#include "ESP32_ANALOG_READ.h"
#include "arduino.h"


// PIN int8 [1,1] Non tunable

void setupFunctionESP32_ANALOG_READ(int8_T  PIN,int size_vector__1){

   pinMode(PIN, INPUT);
    
}

// V int16 [1,1]


void stepFunctionESP32_ANALOG_READ(int8_T  PIN,double * V,int size_vector_1){
  
   *V = analogRead(PIN) * (3.3 / 4095.0);
}

