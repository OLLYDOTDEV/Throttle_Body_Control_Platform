/*
This script can be used for the testing of generateing a PWM signal for the H Bridge.
It uses the seiral port with the format [freq,dutycycle%] eg >     1000,100 



By Oliver Bell
*/







int ENA = 14;
int IN1 = 27;
int IN2 = 26;

int frequency = 500; // Frequency in Hz
int dutyCycle = 50;  // Duty cycle in percentage
const int pwm_channel = 1;
const int resolution = 10; // resolution

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  // Initialize PWM
  ledcSetup(pwm_channel, frequency, resolution);
  ledcAttachPin(ENA, pwm_channel);

  // Initialize Serial Communication
  Serial.begin(9600);
  while (!Serial); // Wait for Serial Monitor to open
  Serial.println("PWM initialized");
}

void loop() {
  // Check for serial input
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int commaIndex = input.indexOf(',');
    if (commaIndex != -1) {
      // Parse frequency and duty cycle from serial input
      frequency = input.substring(0, commaIndex).toInt();
      dutyCycle = input.substring(commaIndex + 1).toInt();

      // Validate duty cycle range
   //   dutyCycle = constrain(dutyCycle, 0, 100);
      
      // Set PWM frequency and duty cycle
      ledcSetup(pwm_channel, frequency, resolution);
     ledcWrite(pwm_channel, map(dutyCycle, 0, 100, 0, 4096)); // Map duty cycle to 10-bit range

    }
  }

  // Read analog values from A34 and A35 and scale to 3 volts
  float sensorValueA34 = (analogRead(34) * 3.3) / 4096;
  float sensorValueA35 = (analogRead(35) * 3.3) / 4096;

  // Print debug information
  Serial.print("Frequency:");
  Serial.print(frequency);
  Serial.print(" Hz,Duty_Cycle:");
  Serial.print(dutyCycle);
  Serial.print("%, A34:");
  Serial.print(sensorValueA34);
  Serial.print(",A35:");
  Serial.println(sensorValueA35);

  delay(500); // Adjust delay as needed
}
