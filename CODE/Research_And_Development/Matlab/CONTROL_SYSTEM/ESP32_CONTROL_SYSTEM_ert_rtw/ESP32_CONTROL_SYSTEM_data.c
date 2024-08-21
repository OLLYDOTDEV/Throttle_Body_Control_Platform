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
 * C/C++ source code generated on : Tue Aug 20 20:09:56 2024
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
  255.0,

  /* Variable: Desire_Min
   * Referenced by: '<S1>/Desire Min Value'
   */
  0.0,

  /* Variable: Direction_Pin
   * Referenced by: '<S3>/Direction Pin'
   */
  0.0,

  /* Variable: EN_Pin
   * Referenced by: '<S3>/Enable Pin'
   */
  1.0,

  /* Variable: Kd
   * Referenced by: '<S5>/Kd'
   */
  0.1,

  /* Variable: Ki
   * Referenced by: '<S5>/Ki'
   */
  2.0,

  /* Variable: Kp
   * Referenced by: '<S5>/Kp'
   */
  4.0,

  /* Mask Parameter: SRFlipFlop2_initial_condition
   * Referenced by: '<S13>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition
   * Referenced by: '<S11>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop1_initial_condition
   * Referenced by: '<S12>/Memory'
   */
  false,

  /* Expression: -1
   * Referenced by: '<S2>/ESP23_ANALOG_READ_DDAppGeneratedBlock1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S3>/MATLAB System'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S4>/Out1'
   */
  0.0,

  /* Computed Parameter: PIDOutput_Y0
   * Referenced by: '<S5>/PID Output'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S5>/Saturation'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S10>/ESP23_ANALOG_READ_DDAppGeneratedBlock'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S13>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_d
   * Referenced by: '<S11>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_d2
   * Referenced by: '<S12>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
