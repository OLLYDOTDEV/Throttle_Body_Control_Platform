#include "LEDC_INTERFACE.h"
#include <arduino.h>
#include <driver/ledc.h>



// PWM_CHANNEL int16 [1,1] Non tunable
// PWM_FREQUENCY int16 [1,1] Non tunable
// PWM_RESOLUTION int16 [1,1] Non tunable
// PWM_PIN int16 [1,1] Non tunable
// PWM_Clock_Speed int64 [1,1] Non tunable

int Bit_Depth = 0;
int PWM_CHANNEL_G = 0;

void setupFunctionLEDC_INTERFACE(int16_T  PWM_CHANNEL,int size_vector__1,int16_T  PWM_FREQUENCY,int size_vector__2,int16_T  PWM_RESOLUTION,int size_vector__3,int16_T  PWM_PIN,int size_vector__4,int_T  PWM_Clock_Speed,int size_5){

    // Configure LEDC PWM
    ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
   ledcAttachPin(PWM_PIN, PWM_CHANNEL);
    ledcWrite(PWM_CHANNEL, 0); // Ensure output is off
    Bit_Depth = pow(2, PWM_RESOLUTION) - 1; // Used later to map duty cycle to 0 to 100% for PWM Signal
    PWM_CHANNEL_G = PWM_CHANNEL;
   // pinMode(14,OUTPUT);
}


// Duty_Cycle_Percent int16 [1,1]

void stepFunctionLEDC_INTERFACE(int16_T Duty_Cycle_Percent,int size_vector_a){
 
  ledcWrite(PWM_CHANNEL_G, map(Duty_Cycle_Percent, 0, 100, 0, Bit_Depth)); // output is off



}