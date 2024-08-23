/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_CONTROL_SYSTEM_V2_data.c
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

#include "ESP32_CONTROL_SYSTEM_V2.h"

/* Block parameters (default storage) */
P_ESP32_CONTROL_SYSTEM_V2_T ESP32_CONTROL_SYSTEM_V2_P = {
  /* Variable: Desire_Max
   * Referenced by: '<S1>/Desire Max Value'
   */
  255.0,

  /* Variable: Desire_Min
   * Referenced by: '<S1>/Desire Min Value'
   */
  0.0,

  /* Variable: Direction_Pin
   * Referenced by: '<S2>/Direction Pin'
   */
  1.0,

  /* Variable: EN_Pin
   * Referenced by: '<S2>/Enable Pin'
   */
  0.0,

  /* Variable: Kp
   * Referenced by: '<S4>/Kp'
   */
  4.0,

  /* Mask Parameter: SRFlipFlop2_initial_condition
   * Referenced by: '<S11>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition
   * Referenced by: '<S9>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop1_initial_condition
   * Referenced by: '<S10>/Memory'
   */
  false,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S3>/Out1'
   */
  0.0,

  /* Computed Parameter: PIDOutput_Y0
   * Referenced by: '<S4>/PID Output'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S4>/Saturation'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S4>/Saturation'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/MATLAB System'
   */
  -1.0,

  /* Expression: 0.1
   * Referenced by: '<S6>/Digital Input'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S6>/Digital Input1'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S6>/Digital Input2'
   */
  0.1,

  /* Expression: 100
   * Referenced by: '<S2>/Constant'
   */
  100.0,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S11>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_d
   * Referenced by: '<S9>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_d2
   * Referenced by: '<S10>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
