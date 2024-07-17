// Example code on how send data to Serial Studio by sending formated JSON packet

#include <Arduino.h>
#include <Serial_Studio_Send_Frame.h>

char* Formated_JSON = Format_Raw_JSON(RAW_JSON); 

void setup()
{
  // Initialize serial port
  Serial.begin(115200);
  // while(!Serial);
delay(2000);



}

void loop()
{


Send_Serial_JSON(Formated_JSON,"1","2","3");
delay(1000);
Send_Serial_JSON(Formated_JSON,"2","3","1");
delay(1000);
Send_Serial_JSON(Formated_JSON,"3","2","1");

}
