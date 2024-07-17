


#include <Arduino.h>
#include <driver/ledc.h>

// Define PWM parameters
const int PWM_Channel = 0;
const int PWM_Frequency = 500;       // 500 Hz
const int PWM_Resolution = 12;       // resolution
const int PWM_Dutycycle_Percent = 0; // 0% duty cycle

const int PWM_Clock_Speed = 80 * 1000000; // Corrected the calculation from 10^6 to 1000000
int Bit_Depth = 0;

// Define pins for H bridge control
int H_BRIDGE_ENA = 4;
int H_BRIDGE_Direction = 0;
int H_BRIDGE_PWM = 2;


