/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: CONTROL_SYSTEM_V2_data.c
 *
 * Code generated for Simulink model 'CONTROL_SYSTEM_V2'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Aug 23 16:14:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CONTROL_SYSTEM_V2.h"

/* Block parameters (default storage) */
P_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_P = {
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

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S39>/Derivative Gain'
   */
  0.1,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S43>/Integral Gain'
   */
  2.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S41>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_a
   * Referenced by: '<S46>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S49>/Filter Coefficient'
   */
  1.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S51>/Proportional Gain'
   */
  3.0,

  /* Mask Parameter: SRFlipFlop2_initial_condition
   * Referenced by: '<S65>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop_initial_condition
   * Referenced by: '<S63>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop1_initial_condition
   * Referenced by: '<S64>/Memory'
   */
  false,

  /* Mask Parameter: DetectIncrease1_vinit
   * Referenced by: '<S66>/Delay Input1'
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

  /* Expression: 0.01
   * Referenced by: '<S4>/Constant'
   */
  0.01,

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
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant1'
   */
  1.0,

  /* Expression: 0.02
   * Referenced by: '<S7>/Constant2'
   */
  0.02,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S65>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_p
   * Referenced by: '<S63>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_k
   * Referenced by: '<S64>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S2>/Gain'
   */
  200U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
