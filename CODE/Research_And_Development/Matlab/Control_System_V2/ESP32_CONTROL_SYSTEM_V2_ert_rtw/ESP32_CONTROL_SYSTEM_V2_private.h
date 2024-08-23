/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_CONTROL_SYSTEM_V2_private.h
 *
 * Code generated for Simulink model 'ESP32_CONTROL_SYSTEM_V2'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Aug 21 16:28:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ESP32_CONTROL_SYSTEM_V2_private_h_
#define ESP32_CONTROL_SYSTEM_V2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "ESP32_CONTROL_SYSTEM_V2_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);

#endif                                 /* ESP32_CONTROL_SYSTEM_V2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
