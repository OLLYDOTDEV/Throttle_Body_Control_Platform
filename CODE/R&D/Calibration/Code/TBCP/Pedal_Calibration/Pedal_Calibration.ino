const int Pedal_Pin = A2;

float Pedal_Read;
float max_value = 0;
float min_value = 1;  // Set to 1 initially to ensure any value read will be less than it

void setup() {
  Serial.begin(9600);
  delay(10000);
}

void loop() {
  Pedal_Read = analogRead(Pedal_Pin);
  Pedal_Read = (Pedal_Read / 1024.0) * 5.0;

  // Update maximum and minimum values
  if (Pedal_Read > max_value) {
    max_value = Pedal_Read;
  }
  if (Pedal_Read < min_value) {
    min_value = Pedal_Read;
  }

  /*
  Serial.print("Current_Value:");
  Serial.print(Pedal_Read);
  Serial.print(",");
  Serial.print("Max_Value:");
  Serial.print(max_value);
  Serial.print(",");
  Serial.print("Min_Value:");
  Serial.println(min_value);
*/

  Serial.print("/*");  // Frame start sequence  [/*]
  Serial.print("millis()");
  Serial.print(",");
  Serial.print(Pedal_Read);
  Serial.print(",");
  Serial.print(max_value);
  Serial.print(",");
  Serial.print(min_value);
  Serial.print("*/");  // Frame finish sequence [*/]
  Serial.println();

  delay(200);
}
