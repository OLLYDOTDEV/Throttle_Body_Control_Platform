/* Copyright 2023 The MathWorks, Inc. */
#ifndef EXAMPLE_H
#define EXAMPLE_H
#if !( defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER))
#ifdef __cplusplus
#include "rtwtypes.h"
extern "C" {
    #endif
    void stepFunctionLEDC_INTERFACE(int16_T Duty_Cycle_Percent,int size_vector_a);
    void setupFunctionLEDC_INTERFACE(int16_T  PWM_CHANNEL,int size_vector__1,int16_T  PWM_FREQUENCY,int size_vector__2,int16_T  PWM_RESOLUTION,int size_vector__3,int16_T  PWM_PIN,int size_vector__4,int_T  PWM_Clock_Speed,int size_5);
    #ifdef __cplusplus
}
#endif
#else
#define loop(void) (0)
#define setup(void) (0)
#endif
#endif