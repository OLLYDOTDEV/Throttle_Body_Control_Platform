#include <avr/io.h>

int E1 = 10;  // PWM pin
int M1 = 11;  // Motor driver pin
int M2 nn= 12;  // Motor driver pin


int E2 = 5;  // PWM pin
int M3 = 4;  // Motor driver pin
int M4 = 3;  // Motor driver pin

int TB_FB1 = A0;  // Differential input pin 1
int TB_FB2 = A1;  // Differential input pin 2

int input_Frequency = 1;  // Default frequency
int dutyCycle = 50;       // Default duty cycle (percentage)

void setup() {

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);

  pinMode(TB_FB1, INPUT);
  pinMode(TB_FB2, INPUT);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);

  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);

  Serial.begin(9600);

  // Set up Timer 1 for phase-correct PWM with OCRA top
  // Set COM1A1 and COM1B1 to enable non-inverting PWM on pins 10 and 11
  // Set WGM13, WGM12, and WGM10 for phase-correct PWM with OCRA top
  // Set CS11 for prescaler of 8
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
  TCCR1B = _BV(WGM13) | _BV(CS11);

  Serial.println("Enter frequency (Hz) and duty cycle (%) separated by comma (e.g., 1000,50):");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int commaIndex = input.indexOf(',');
    if (commaIndex != -1) {
      input_Frequency = input.substring(0, commaIndex).toInt();
      dutyCycle = input.substring(commaIndex + 1).toInt();
      setPWMFrequency(input_Frequency);
      Serial.println("Frequency set to " + String(input_Frequency) + " Hz");
      Serial.println("Duty cycle set to " + String(dutyCycle) + "%");
    }
  }

  int tb_fb1_value = analogRead(TB_FB1);
  int tb_fb2_value = analogRead(TB_FB2);
  Serial.print("input_Frequency:");
  Serial.print(input_Frequency);
  Serial.print(", ");
  Serial.print("dutyCycle:");
  Serial.print(dutyCycle);
  Serial.print(", ");
  Serial.print("TB_FB1_Value:");
  Serial.print(tb_fb1_value);
  Serial.print(", ");
  Serial.print("TB_FB2_Value:");
  Serial.println(tb_fb2_value);


  analogWrite(E1, map(dutyCycle, 0, 100, 0, 255));



  //delay(500);  // Adjust delay as needed
}

void setPWMFrequency(int frequency) {
  OCR1A = (16000000 / (2 * 8 * frequency)) - 1;
}
