#include "E:\Banana444\Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_ADC1115\ADS1115_Vread.h"
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

  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

    





  // Untested
  // Set the gain based on the SetGain parameter
/**
  switch (SetGain) {
    case 0:
      ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 0.1875mV (default)
      break;
    case 1:
      ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 0.125mV
      break;
    case 2:
      ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 0.0625mV
      break;
    case 4:
      ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.03125mV
      break;
    case 8:
      ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.015625mV
      break;
    case 16:
      ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.0078125mV
      break;
    default:
      ads.setGain(GAIN_TWOTHIRDS);  // Default gain
      break;
  }
  **/
}


// V0 double [1,1]
// V1 double [1,1]
// V2 double [1,1]
// V3 double [1,1]


void stepFunctionADS1115_Vread(double * V0,int size_vector_1,double * V1,int size_vector_2,double * V2,int size_vector_3,double * V3,int size_vector_4){

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