

#include <Arduino.h>
#include <driver/ledc.h>

// Define PWM parameters
const int PWM_Channel = 0;
const int PWM_Frequency = 19000;     // 19569Hz is the MAX at 12Bit resolution
const int PWM_Resolution = 12;       // resolution
const int PWM_Dutycycle_Percent = 0; // 0% duty cycle

const int PWM_Clock_Speed = 80 * 1000000; // Corrected the calculation from 10^6 to 1000000
int Bit_Depth = 0;

// Define pins for H bridge control
int H_BRIDGE_ENA = 4;
int H_BRIDGE_Direction = 0;
int H_BRIDGE_PWM = 2;

// Defines pins for feedback

int TB_FB = 35;

void setup()
{

    // Initialize Serial communication
    Serial.begin(115200);
    while (!Serial)
        // Pin modes
        pinMode(H_BRIDGE_ENA, OUTPUT);
    pinMode(H_BRIDGE_Direction, OUTPUT);
    pinMode(H_BRIDGE_PWM, OUTPUT);

    digitalWrite(H_BRIDGE_ENA, LOW);
    digitalWrite(H_BRIDGE_Direction, LOW);

    // Configure LEDC PWM
    ledcSetup(PWM_Channel, PWM_Frequency, PWM_Resolution);
    ledcAttachPin(H_BRIDGE_PWM, PWM_Channel);
    ledcWrite(PWM_Channel, 0); // Ensure output is off

    delay(1000); // Startup delay
}

void loop()
{
    Serial.println("Value")
    ledcWrite(PWM_Channel, 0); // output is off

    delay(10000);
    ledcWrite(PWM_Channel, 100); // output is off

    delay(10000);
}