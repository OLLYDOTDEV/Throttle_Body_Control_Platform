/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_CONTROL_SYSTEM_data.c
 *
 * Code generated for Simulink model 'ESP32_CONTROL_SYSTEM'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Aug  9 12:23:33 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ESP32_CONTROL_SYSTEM.h"

/* Block parameters (default storage) */
P_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_P = {
  /* Variable: Desire_Max
   * Referenced by: '<S1>/Desire Max Value'
   */
  100.0,

  /* Variable: Desire_Min
   * Referenced by: '<S1>/Desire Min Value'
   */
  0.0,

  /* Variable: EN_Pin
   * Referenced by: '<S2>/Enable Pin'
   */
  1.0,

  /* Variable: Kp
   * Referenced by: '<S3>/Kp'
   */
  7.0,

  /* Expression: -1
   * Referenced by: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock1'
   */
  -1.0,

  /* Expression: 3.2
   * Referenced by: '<S3>/Saturation'
   */
  3.2,

  /* Expression: 0
   * Referenced by: '<S3>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
