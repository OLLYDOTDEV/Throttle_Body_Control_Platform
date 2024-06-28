#include <avr/io.h>

int E1 = 10;
int M1 = 11;
int M2 = 12;

int TB_FB1 = A0;
int TB_FB2 = A1;
int PEDDEL_FB2 = A2;

void setup() {
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);

  pinMode(TB_FB1, INPUT);
  pinMode(TB_FB2, INPUT);
  pinMode(PEDDEL_FB2, INPUT);

  Serial.begin(9600);

  // Set up Timer 1 for phase-correct PWM with OCRA top
  // Set COM1A1 and COM1B1 to enable non-inverting PWM on pins 10 and 11
  // Set WGM13, WGM12, and WGM10 for phase-correct PWM with OCRA top
  // Set CS11 for prescaler of 8
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
  TCCR1B = _BV(WGM13) | _BV(CS11);
  // Set OCR1A as the top value for Timer 1 to control PWM frequency
  // Adjust this value to set the desired PWM frequency
  //
  //
  //
  //  1 kHz: OCR1A = 15624
  //  2 kHz: OCR1A = 7812
  //  5 kHz: OCR1A = 3124
  //  10 kHz: OCR1A = 1562
  //  20 kHz: OCR1A = 781
    OCR1A = (16000000 / (2 * 8 * input_Frequence)) - 1

//  OCR1A = 200; 
}

void loop() {
  int peddel_fb2_value = analogRead(PEDDEL_FB2); // Read analog input from PEDDEL_FB2
  int pwm_value = map(peddel_fb2_value, 0, 1023, 0, 255); // Scale input to PWM range

  Serial.print("Pedal Value: ");
  Serial.println(peddel_fb2_value);

  Serial.print("PWM Value: ");
  Serial.println(pwm_value);

  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(E1, pwm_value);

  float tb_fb1_value_scaled = analogRead(TB_FB1) / (5.0 * 1024.0); // Read and scale analog input from TB_FB1
  Serial.print("TB_FB1: ");
  Serial.println(tb_fb1_value_scaled);

  float tb_fb2_value_scaled = analogRead(TB_FB2) / (5.0 * 1024.0); // Read and scale analog input from TB_FB2
  Serial.print("TB_FB2: ");
  Serial.println(tb_fb2_value_scaled);

 // delay(1000); // Adjust delay as needed
}
