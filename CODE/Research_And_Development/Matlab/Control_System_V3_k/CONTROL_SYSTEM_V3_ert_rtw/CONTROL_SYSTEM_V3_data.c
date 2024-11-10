/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: CONTROL_SYSTEM_V3_data.c
 *
 * Code generated for Simulink model 'CONTROL_SYSTEM_V3'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Nov  7 23:08:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CONTROL_SYSTEM_V3.h"

/* Block parameters (default storage) */
P_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_P = {
  /* Variable: Desire_Max
   * Referenced by: '<S5>/Desire Max Value'
   */
  255.0,

  /* Variable: Desire_Min
   * Referenced by: '<S5>/Desire Min Value'
   */
  0.0,

  /* Variable: Direction_Pin
   * Referenced by: '<S7>/Direction Pin'
   */
  1.0,

  /* Variable: EN_Pin
   * Referenced by: '<S7>/Enable Pin'
   */
  0.0,

  /* Variable: Kd
   * Referenced by: '<S81>/Derivative Gain'
   */
  2.0,

  /* Variable: Ki
   * Referenced by: '<S85>/Integral Gain'
   */
  4.0,

  /* Variable: Kn
   * Referenced by: '<S91>/Filter Coefficient'
   */
  0.1,

  /* Variable: Kp
   * Referenced by: '<S93>/Proportional Gain'
   */
  1.4,

  /* Mask Parameter: OnDelay_DelayType
   * Referenced by: '<S30>/Constant2'
   */
  1.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S83>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_g
   * Referenced by: '<S88>/Integrator'
   */
  0.0,

  /* Mask Parameter: OnDelay_delay
   * Referenced by: '<S30>/Constant1'
   */
  1.0,

  /* Mask Parameter: SampleandHold_ic
   * Referenced by: '<S40>/IC=ic'
   */
  -1.0E+99,

  /* Mask Parameter: SampleandHold_ic_g
   * Referenced by: '<S48>/IC=ic'
   */
  -1.0E+99,

  /* Mask Parameter: EdgeDetector_model
   * Referenced by: '<S35>/Constant1'
   */
  2.0,

  /* Mask Parameter: EdgeDetector_model_j
   * Referenced by: '<S43>/Constant1'
   */
  1.0,

  /* Mask Parameter: Observer_x0
   * Referenced by: '<S25>/Integrator'
   */
  0.0,

  /* Mask Parameter: OnDelay_ic
   * Referenced by:
   *   '<S35>/Memory'
   *   '<S43>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop3_initial_condition
   * Referenced by: '<S49>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop5_initial_condition
   * Referenced by: '<S51>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop6_initial_condition
   * Referenced by: '<S52>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop4_initial_condition
   * Referenced by: '<S50>/Memory'
   */
  false,

  /* Expression: -1
   * Referenced by: '<S2>/MATLAB System'
   */
  -1.0,

  /* Expression: -1e6
   * Referenced by: '<S39>/Out1'
   */
  -1.0E+6,

  /* Expression: [1 0]
   * Referenced by: '<S35>/pos. edge'
   */
  { 1.0, 0.0 },

  /* Expression: [0 1]
   * Referenced by: '<S35>/neg. edge'
   */
  { 0.0, 1.0 },

  /* Expression: [1 1]
   * Referenced by: '<S35>/either edge'
   */
  { 1.0, 1.0 },

  /* Expression: -1e6
   * Referenced by: '<S47>/Out1'
   */
  -1.0E+6,

  /* Expression: [1 0]
   * Referenced by: '<S43>/pos. edge'
   */
  { 1.0, 0.0 },

  /* Expression: [0 1]
   * Referenced by: '<S43>/neg. edge'
   */
  { 0.0, 1.0 },

  /* Expression: [1 1]
   * Referenced by: '<S43>/either edge'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: Propotional_Y0
   * Referenced by: '<S11>/Propotional'
   */
  0.0,

  /* Computed Parameter: PIDOutput_Y0
   * Referenced by: '<S10>/PID Output'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S10>/Constant'
   */
  0.01,

  /* Computed Parameter: ADRCOutput_Y0
   * Referenced by: '<S1>/ADRC Output'
   */
  0.0,

  /* Expression: a
   * Referenced by: '<S24>/Constant'
   */
  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /* Expression: wc^2
   * Referenced by: '<S23>/Gain'
   */
  25.0,

  /* Expression: 2*wc
   * Referenced by: '<S23>/Gain2'
   */
  10.0,

  /* Expression: 1/b0
   * Referenced by: '<S23>/Gain1'
   */
  0.001,

  /* Expression: b
   * Referenced by: '<S24>/Constant1'
   */
  { 0.0, 1000.0, 0.0 },

  /* Expression: d
   * Referenced by: '<S24>/Constant3'
   */
  0.0,

  /* Expression: c
   * Referenced by: '<S24>/Constant2'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: l
   * Referenced by: '<S24>/Constant8'
   */
  { 120.0, 4800.0, 64000.0 },

  /* Expression: 2
   * Referenced by: '<S1>/Constant'
   */
  2.0,

  /* Expression: -1
   * Referenced by: '<S8>/Digital Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S8>/Digital Input1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S8>/Digital Input2'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S8>/Digital Input3'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S30>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S3>/Pulse Generator'
   */
  50.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S3>/Pulse Generator'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S3>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_d
   * Referenced by: '<S4>/Pulse Generator'
   */
  10.0,

  /* Computed Parameter: PulseGenerator_Duty_e
   * Referenced by: '<S4>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S4>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant4'
   */
  0.0,

  /* Computed Parameter: OUT_Y0
   * Referenced by: '<S31>/OUT'
   */
  false,

  /* Computed Parameter: OUT_Y0_a
   * Referenced by: '<S32>/OUT'
   */
  false,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S49>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_p
   * Referenced by: '<S51>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_b
   * Referenced by: '<S52>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_bm
   * Referenced by: '<S50>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S7>/Gain'
   */
  200U,

  /* Computed Parameter: Multiply2_Gain
   * Referenced by: '<S9>/Multiply2'
   */
  192U,

  /* Computed Parameter: Multiply1_Gain
   * Referenced by: '<S9>/Multiply1'
   */
  128U,

  /* Computed Parameter: Multiply_Gain
   * Referenced by: '<S9>/Multiply'
   */
  128U,

  /* Start of '<S43>/POSITIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S46>/OUT'
     */
    false
  }
  ,

  /* End of '<S43>/POSITIVE Edge' */

  /* Start of '<S43>/NEGATIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S45>/OUT'
     */
    false
  }
  ,

  /* End of '<S43>/NEGATIVE Edge' */

  /* Start of '<S35>/POSITIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S38>/OUT'
     */
    false
  }
  ,

  /* End of '<S35>/POSITIVE Edge' */

  /* Start of '<S35>/NEGATIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S37>/OUT'
     */
    false
  }
  /* End of '<S35>/NEGATIVE Edge' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
