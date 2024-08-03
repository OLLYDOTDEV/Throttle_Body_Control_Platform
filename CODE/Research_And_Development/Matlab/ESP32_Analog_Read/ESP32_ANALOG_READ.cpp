#include "ESP32_ANALOG_READ.h"
#include "arduino.h"


// PIN int8 [1,1] Non tunable
int pin_G;

void setupFunctionESP32_ANALOG_READ(int8_T  PIN,int size_vector__1){
   pin_G = PIN;
   pinMode(pin_G, INPUT);
    
}

// V int16 [1,1]


void stepFunctionESP32_ANALOG_READ(double * V,int size_vector_1){
  
   *V = analogRead(pin_G) * (3.3 / 4095.0);
}