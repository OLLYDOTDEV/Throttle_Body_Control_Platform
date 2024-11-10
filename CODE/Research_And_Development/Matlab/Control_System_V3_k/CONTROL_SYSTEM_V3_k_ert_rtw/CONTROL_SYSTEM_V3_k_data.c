/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: CONTROL_SYSTEM_V3_k_data.c
 *
 * Code generated for Simulink model 'CONTROL_SYSTEM_V3_k'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct 15 11:47:05 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CONTROL_SYSTEM_V3_k.h"

/* Block parameters (default storage) */
P_CONTROL_SYSTEM_V3_k_T CONTROL_SYSTEM_V3_k_P = {
  /* Variable: Desire_Max
   * Referenced by: '<S4>/Desire Max Value'
   */
  255.0,

  /* Variable: Desire_Min
   * Referenced by: '<S4>/Desire Min Value'
   */
  0.0,

  /* Variable: Direction_Pin
   * Referenced by: '<S6>/Direction Pin'
   */
  1.0,

  /* Variable: EN_Pin
   * Referenced by: '<S6>/Enable Pin'
   */
  0.0,

  /* Variable: Kd
   * Referenced by: '<S66>/Derivative Gain'
   */
  2.0,

  /* Variable: Ki
   * Referenced by: '<S70>/Integral Gain'
   */
  4.0,

  /* Variable: Kn
   * Referenced by: '<S76>/Filter Coefficient'
   */
  0.1,

  /* Variable: Kp
   * Referenced by: '<S78>/Proportional Gain'
   */
  1.4,

  /* Mask Parameter: OnDelay_DelayType
   * Referenced by: '<S15>/Constant2'
   */
  1.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S68>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_l
   * Referenced by: '<S73>/Integrator'
   */
  0.0,

  /* Mask Parameter: OnDelay_delay
   * Referenced by: '<S15>/Constant1'
   */
  1.0,

  /* Mask Parameter: SampleandHold_ic
   * Referenced by: '<S25>/IC=ic'
   */
  -1.0E+99,

  /* Mask Parameter: SampleandHold_ic_k
   * Referenced by: '<S33>/IC=ic'
   */
  -1.0E+99,

  /* Mask Parameter: EdgeDetector_model
   * Referenced by: '<S20>/Constant1'
   */
  2.0,

  /* Mask Parameter: EdgeDetector_model_g
   * Referenced by: '<S28>/Constant1'
   */
  1.0,

  /* Mask Parameter: OnDelay_ic
   * Referenced by:
   *   '<S20>/Memory'
   *   '<S28>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop3_initial_condition
   * Referenced by: '<S34>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop5_initial_condition
   * Referenced by: '<S36>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop6_initial_condition
   * Referenced by: '<S37>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop4_initial_condition
   * Referenced by: '<S35>/Memory'
   */
  false,

  /* Expression: -1
   * Referenced by: '<S1>/MATLAB System'
   */
  -1.0,

  /* Expression: -1e6
   * Referenced by: '<S24>/Out1'
   */
  -1.0E+6,

  /* Expression: [1 0]
   * Referenced by: '<S20>/pos. edge'
   */
  { 1.0, 0.0 },

  /* Expression: [0 1]
   * Referenced by: '<S20>/neg. edge'
   */
  { 0.0, 1.0 },

  /* Expression: [1 1]
   * Referenced by: '<S20>/either edge'
   */
  { 1.0, 1.0 },

  /* Expression: -1e6
   * Referenced by: '<S32>/Out1'
   */
  -1.0E+6,

  /* Expression: [1 0]
   * Referenced by: '<S28>/pos. edge'
   */
  { 1.0, 0.0 },

  /* Expression: [0 1]
   * Referenced by: '<S28>/neg. edge'
   */
  { 0.0, 1.0 },

  /* Expression: [1 1]
   * Referenced by: '<S28>/either edge'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: Propotional_Y0
   * Referenced by: '<S10>/Propotional'
   */
  0.0,

  /* Computed Parameter: PIDOutput_Y0
   * Referenced by: '<S9>/PID Output'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S9>/Constant'
   */
  0.01,

  /* Expression: -1
   * Referenced by: '<S7>/Digital Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S7>/Digital Input1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S7>/Digital Input2'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S7>/Digital Input3'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S15>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S2>/Pulse Generator'
   */
  50.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S2>/Pulse Generator'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S2>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Switch2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_l
   * Referenced by: '<S3>/Pulse Generator'
   */
  10.0,

  /* Computed Parameter: PulseGenerator_Duty_e
   * Referenced by: '<S3>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S3>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant4'
   */
  0.0,

  /* Computed Parameter: OUT_Y0
   * Referenced by: '<S16>/OUT'
   */
  false,

  /* Computed Parameter: OUT_Y0_k
   * Referenced by: '<S17>/OUT'
   */
  false,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S34>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_k
   * Referenced by: '<S36>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_p
   * Referenced by: '<S37>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_g
   * Referenced by: '<S35>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S6>/Gain'
   */
  200U,

  /* Computed Parameter: Multiply2_Gain
   * Referenced by: '<S8>/Multiply2'
   */
  192U,

  /* Computed Parameter: Multiply1_Gain
   * Referenced by: '<S8>/Multiply1'
   */
  128U,

  /* Computed Parameter: Multiply_Gain
   * Referenced by: '<S8>/Multiply'
   */
  128U,

  /* Start of '<S28>/POSITIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S31>/OUT'
     */
    false
  }
  ,

  /* End of '<S28>/POSITIVE Edge' */

  /* Start of '<S28>/NEGATIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S30>/OUT'
     */
    false
  }
  ,

  /* End of '<S28>/NEGATIVE Edge' */

  /* Start of '<S20>/POSITIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S23>/OUT'
     */
    false
  }
  ,

  /* End of '<S20>/POSITIVE Edge' */

  /* Start of '<S20>/NEGATIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S22>/OUT'
     */
    false
  }
  /* End of '<S20>/NEGATIVE Edge' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
