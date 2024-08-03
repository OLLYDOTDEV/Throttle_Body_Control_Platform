/* Copyright 2023 The MathWorks, Inc. */
#ifndef EXAMPLE_H
#define EXAMPLE_H
#if !( defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER))
#ifdef __cplusplus
#include "rtwtypes.h"
extern "C" {
    #endif
    void stepFunctionADS1115_Vread(int16_T * V0,int size_vector_1,int16_T * V1,int size_vector_2,int16_T * V2,int size_vector_3,int16_T * V3,int size_vector_4);
    void setupFunctionADS1115_Vread(int16_T  SetGain,int size_vector__1);
    #ifdef __cplusplus
}
#endif
#else
#define loop(void) (0)
#define setup(void) (0)
#endif
#endif