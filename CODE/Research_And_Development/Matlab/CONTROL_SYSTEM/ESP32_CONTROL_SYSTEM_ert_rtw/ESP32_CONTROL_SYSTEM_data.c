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
 * Model version                  : 1.20
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Aug 19 16:13:12 2024
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
   * Referenced by: '<S11>/Desire Max Value'
   */
  255.0,

  /* Variable: Desire_Min
   * Referenced by: '<S11>/Desire Min Value'
   */
  0.0,

  /* Variable: EN_Pin
   * Referenced by: '<S12>/Enable Pin'
   */
  1.0,

  /* Variable: J_aet
   * Referenced by:
   *   '<S4>/Constant2'
   *   '<S6>/Constant2'
   */
  0.0035,

  /* Variable: omga_c
   * Referenced by: '<S4>/Gain1'
   */
  2.0,

  /* Variable: roa
   * Referenced by:
   *   '<S4>/Constant2'
   *   '<S6>/Constant2'
   */
  0.24,

  /* Expression: -1
   * Referenced by: '<S3>/ESP23_ANALOG_READ_DDAppGeneratedBlock1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock'
   */
  -1.0,

  /* Expression: [12*pi/180 0 0]'
   * Referenced by: '<S6>/Integrator1'
   */
  { 0.20943951023931953, 0.0, 0.0 },

  /* Expression: [0 1 0;0 0 1;0 0 0]
   * Referenced by: '<S6>/Gain'
   */
  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant1'
   */
  0.0,

  /* Expression: [Beta1 Beta2 Beta3]'
   * Referenced by: '<S6>/Gain2'
   */
  { 150.0, 7500.0, 125000.0 },

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant1'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S1>/Gain1'
   */
  0.017453292519943295,

  /* Expression: (omga_c)^2
   * Referenced by: '<S4>/Gain'
   */
  4.0,

  /* Expression: 0.7
   * Referenced by: '<S5>/Gain1'
   */
  0.7,

  /* Expression: 0.3
   * Referenced by: '<S5>/Constant'
   */
  0.3,

  /* Expression: 180/pi
   * Referenced by: '<S10>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S5>/Constant3'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
