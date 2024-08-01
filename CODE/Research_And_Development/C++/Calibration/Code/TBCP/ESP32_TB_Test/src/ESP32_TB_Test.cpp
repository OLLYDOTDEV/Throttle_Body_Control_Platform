

#include <Arduino.h>
#include <driver/ledc.h>
#include <PID_v1.h>

// Define PWM parameters
const int PWM_Channel = 0;
const int PWM_Frequency = 10000; // 19569Hz is the MAX at 12Bit resolution
const int PWM_Resolution = 12;   // resolution

const int PWM_Clock_Speed = 80 * 1000000; // Corrected the calculation from 10^6 to 1000000
int Bit_Depth = 0;

// Define pins for H bridge control
int H_BRIDGE_ENA = 4;
int H_BRIDGE_Direction = 0;
int H_BRIDGE_PWM = 2;

// Defines pins for feedback

int FP_FB = 34;                   // Foot pedal feedback pin
int TB_FB = 35;                   // Throttle body feedback pin
const float OffsetVoltage = 0.50; // Manaul offset voltage to counter error in reads

// PID

// Define Variables we'll be connecting to
double Setpoint, PID_Input, PID_Output;
float Pos_Error;


double consKp = 2.1, consKi = 1.25, consKd = 0.005;
// https://tlk-energy.de/blog-en/practical-pid-tuning-guide

PID myPID(&PID_Input, &PID_Output, &Setpoint, consKp, consKi, consKd, DIRECT);

// Send_Serial_Data(FP_POS_Percent,TB_FB,DC,PID,Pos_Error)
// Function to send data to serial Studio
template <typename... Args>
void Send_Serial_Data(Args... args)
{
    // Send frame start delimiter

    Serial.print("/*");

    // Convert each argument to string and send it over serial
    int Temp[] = {0, (Serial.print(args), Serial.print(","), 0)...};

    // Send frame end delimiter
    Serial.println("*/");
}

void TB_PWM_Control(float Percent)
{
    ledcWrite(PWM_Channel, map(Percent, 0, 100, 0, Bit_Depth)); // output is off
}

struct FP_Calibration_Value
{
    float min;
    float max;
};
struct TB_Calibration_Value
{
    float min;
    float max;
};

FP_Calibration_Value FP_FB_Test()
{
    Serial.println("starting FP_Test()");
    const int sampleCount = 500;  // Number of samples for the rolling average
    const float minThreshold = 1; // Voltage threshold for min value
    const float maxThreshold = 4; //  Voltage threshold for max value
    const int sampleInterval = 5; // Interval between samples in milliseconds

    FP_Calibration_Value calibValues;

    float minValue = 0.00;
    float maxValue = 0.00;
    bool validMin = false;
    bool validMax = false;

    while (!validMin)
    {

        for (int i = 0; i < sampleCount; i++)
        {
            minValue += analogRead(FP_FB) * 1.51512 * (3.3 / 4095.0) + OffsetVoltage;
            delay(sampleInterval);
        }
        minValue /= sampleCount;

        if (minValue < minThreshold)
        {
            validMin = true;
        }
        else
        {
            minValue = 0;
            Serial.println("Min value over expected value. Retaking measurement...");
        }
        Serial.print("Min value: ");
        Serial.println(minValue);
    }

    Serial.println("Please depress the Foot Pedal completely & Hold.");

    delay(5000); // Wait for user to depress the pedal

    while (!validMax)
    {

        for (int i = 0; i < sampleCount; i++)
        {
            maxValue += analogRead(FP_FB) * 1.51512 * (3.3 / 4095.0) + OffsetVoltage;
            delay(sampleInterval);
        }
        maxValue /= sampleCount;

        if (maxValue > maxThreshold)
        {
            validMax = true;
        }
        else
        {
            maxValue = 0;
            Serial.println("Max value under expected value. Retaking measurement...");
        }
        Serial.print("Max value: ");
        Serial.println(maxValue);
    }
    calibValues.max = maxValue;
    calibValues.min = minValue;

    return calibValues;
}

TB_Calibration_Value TB_FB_Test()
{
    Serial.println("starting TB_TB_Test()");
    TB_PWM_Control(0); // TB Closed

    const int sampleCount = 500;  // Number of samples for the rolling average
    const float minThreshold = 1; // Voltage threshold for min value
    const float maxThreshold = 4; //  Voltage threshold for max value
    const int sampleInterval = 5; // Interval between samples in milliseconds

    TB_Calibration_Value calibValues;

    float minValue = 0.00;
    float maxValue = 0.00;
    bool validMin = false;
    bool validMax = false;

    while (!validMin)
    {

        for (int i = 0; i < sampleCount; i++)
        {
            minValue += analogRead(TB_FB) * 1.51512 * (3.3 / 4095.0) + OffsetVoltage;
            delay(sampleInterval);
        }
        minValue /= sampleCount;

        if (minValue < minThreshold)
        {
            validMin = true;
        }
        else
        {
            minValue = 0;
            Serial.println("Min value over expected value. Retaking measurement...");
        }
        Serial.print("Min value: ");
        Serial.println(minValue);
    }

    TB_PWM_Control(100); // TB Opened
    delay(1000);         // Wait TB to fully open

    while (!validMax)
    {

        for (int i = 0; i < sampleCount; i++)
        {
            maxValue += analogRead(TB_FB) * 1.51512 * (3.3 / 4095.0) + OffsetVoltage;
            delay(sampleInterval);
        }
        maxValue /= sampleCount;

        if (maxValue > maxThreshold)
        {
            validMax = true;
        }
        else
        {
            maxValue = 0;
            Serial.println("Max value under expected value. Retaking measurement...");
        }
        Serial.print("Max value: ");
        Serial.println(maxValue);
    }
    TB_PWM_Control(0); // TB Closed

    calibValues.max = maxValue;
    calibValues.min = minValue;

    return calibValues;
}

float Map_Float(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float FP_Pos(float min, float max, float Voltage) // Returns current % of the foot pedal
{
    float Mapped_Value = Map_Float(Voltage, min, max, 0, 100); // cant use standard map() function as it doesnt support float values
    return constrain(Mapped_Value, 0, 100);
}

float TB_Pos(float min, float max, float Percent) // Returns current % of the Throttle body
{
    float Mapped_Value = Map_Float(Percent, min, max, 0, 100); // cant use standard map() function as it doesnt support float values
    return constrain(Mapped_Value, 0, 100);
}

void TB_Pos_Control(float Target_Pos, float Current_Pos)
{ // Control Function for TB
    Setpoint = Target_Pos;
    PID_Input = Current_Pos;
    Pos_Error = abs(Target_Pos - Current_Pos); // distance away from setpoint
        myPID.SetTunings(consKp, consKi, consKd);
    myPID.Compute();
    PID_Output = constrain(PID_Output, 0, 100);
    TB_PWM_Control(PID_Output);
    Send_Serial_Data(Target_Pos, Current_Pos, PID_Output, Pos_Error);
}

void setup()
{

    // Initialize Serial communication
    Serial.begin(115200);
    while (!Serial)
        // control Pin modes
        pinMode(H_BRIDGE_ENA, OUTPUT);
    pinMode(H_BRIDGE_Direction, OUTPUT);
    pinMode(H_BRIDGE_PWM, OUTPUT);
    // feedback pins modes

    pinMode(TB_FB, INPUT);
    pinMode(FP_FB, INPUT);

    digitalWrite(H_BRIDGE_ENA, LOW);       // ENABLE H BRIDGE OUTPUTS
    digitalWrite(H_BRIDGE_Direction, LOW); // LOW = OPEN  | HIGH = CLOSE

    // Configure LEDC PWM
    ledcSetup(PWM_Channel, PWM_Frequency, PWM_Resolution);
    ledcAttachPin(H_BRIDGE_PWM, PWM_Channel);
    ledcWrite(PWM_Channel, 0); // Ensure output is off

    Bit_Depth = pow(2, PWM_Resolution) - 1; // Used later to map duty cycle to 0 to 100% for PWM Signal

    // turn the PID on
    Setpoint = 0;
    myPID.SetMode(AUTOMATIC);

    delay(500); // Startup delay
}

void loop()
{

    FP_Calibration_Value FP_Test_Values = FP_FB_Test();
    TB_Calibration_Value TB_Test_Values = TB_FB_Test();
    Serial.println("\n\n\n\n\n\n\n\n\n\n\n");
    Serial.println("- FP_Test_Values -");
    Serial.print("Min value: ");
    Serial.println(FP_Test_Values.min);
    Serial.print("Max value: ");
    Serial.println(FP_Test_Values.max);
    Serial.println("");
    Serial.println("- TP_Test_Values -");
    Serial.print("Min value: ");
    Serial.println(TB_Test_Values.min);
    Serial.print("Max value: ");
    Serial.println(TB_Test_Values.max);

    Serial.println("\n");
    Serial.println("Continue with PID control system (Y) ");
    while (true)
    {
        if (Serial.available() > 0)
        {
            char response = Serial.read(); // Read the incoming character
            if (response == 'y' || response == 'Y')
            {
                Serial.println("Starting PID control system ");
                delay(1000);
                break;
            }
        }
    }

    while (true)
    {
        float FP_FB_Voltage = analogRead(FP_FB) * 1.51512 * (3.3 / 4095.0) + OffsetVoltage;
        float FP_POS_Percent = FP_Pos(FP_Test_Values.min, FP_Test_Values.max, FP_FB_Voltage);
        // Serial.print("FP Value (%):");
        // Serial.println(FP_POS_Percent);

        float FB_FB_Voltage = analogRead(TB_FB) * 1.51512 * (3.3 / 4095.0) + OffsetVoltage;
        float TB_POS_Percent = TB_Pos(TB_Test_Values.min, TB_Test_Values.max, FB_FB_Voltage);
        // Serial.print("TB Value (%):");
        // Serial.println(TB_POS_Percent);

        TB_Pos_Control(FP_POS_Percent, TB_POS_Percent);
        // delay(100);
    }
}
