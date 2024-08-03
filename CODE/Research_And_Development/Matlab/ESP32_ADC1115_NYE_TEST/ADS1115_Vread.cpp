#include "E:\Banana444\Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_ADC1115_NYE_TEST\ADS1115_Vread.h"

#include "arduino.h"
#include "Wire.h"
#include "Adafruit_ADS1X15.h"
Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
// SetGain int16 [1,1] Non tunable

void setupFunctionADS1115_Vread(int16_T  SetGain,int size_vector__1){
  if (!ads.begin()) {
    //Serial.println("Failed to initialize ADS.");
    while (1);
  }

}

// V0 int16 [1,1]
// V1 int16 [1,1]
// V2 int16 [1,1]
// V3 int16 [1,1]


void stepFunctionADS1115_Vread(int16_T * V0,int size_vector_1,int16_T * V1,int size_vector_2,int16_T * V2,int size_vector_3,int16_T * V3,int size_vector_4){
  
  double adc0, adc1, adc2, adc3;
  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);

    *V0 = ads.computeVolts(adc0);
    *V1 = ads.computeVolts(adc1);
    *V2 = ads.computeVolts(adc2); 
    *V3 = ads.computeVolts(adc3);
}