/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ADS1115_Single_Ended_Read_private.h
 *
 * Code generated for Simulink model 'ADS1115_Single_Ended_Read'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Jul 23 14:06:56 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ADS1115_Single_Ended_Read_private_h_
#define ADS1115_Single_Ended_Read_private_h_
#include "rtwtypes.h"
#include "ADS1115_Single_Ended_Read_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void ADS1115_Interface_Start_wrapper(real_T *xD);
SFB_EXTERN_C void ADS1115_Interface_Outputs_wrapper(int16_T *A0,
  int16_T *A2,
  int16_T *A1,
  int16_T *A3,
  const real_T *xD);
SFB_EXTERN_C void ADS1115_Interface_Update_wrapper(int16_T *A0,
  int16_T *A2,
  int16_T *A1,
  int16_T *A3,
  real_T *xD);
SFB_EXTERN_C void ADS1115_Interface_Terminate_wrapper(real_T *xD);

#undef SFB_EXTERN_C
#endif                                /* ADS1115_Single_Ended_Read_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
