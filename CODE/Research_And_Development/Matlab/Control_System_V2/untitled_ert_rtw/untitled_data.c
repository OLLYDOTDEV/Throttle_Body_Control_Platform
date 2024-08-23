/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: untitled_data.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Aug 21 16:58:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"

/* Block parameters (default storage) */
P_untitled_T untitled_P = {
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

  /* Variable: Ki
   * Referenced by: '<S4>/Ki'
   */
  2.0,

  /* Variable: Kp
   * Referenced by: '<S4>/Kp'
   */
  4.0,

  /* Mask Parameter: SRFlipFlop_initial_condition
   * Referenced by: '<S9>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop2_initial_condition
   * Referenced by: '<S11>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop1_initial_condition
   * Referenced by: '<S10>/Memory'
   */
  false,

  /* Expression: -1
   * Referenced by: '<Root>/MATLAB System'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S6>/Digital Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S6>/Digital Input1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S6>/Digital Input2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
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

  /* Computed Parameter: Logic_table
   * Referenced by: '<S9>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_m
   * Referenced by: '<S11>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_k
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
