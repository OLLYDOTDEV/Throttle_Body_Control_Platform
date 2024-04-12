#include <Arduino.h>
#include <Serial_Studio_Send_Frame.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(112500);
}

void loop() {

  
delay(500);
Send_Serial_Data(1,2,3);
delay(500);
Send_Serial_Data(2,3,1);
delay(500);
Send_Serial_Data(3,2,1);
}


