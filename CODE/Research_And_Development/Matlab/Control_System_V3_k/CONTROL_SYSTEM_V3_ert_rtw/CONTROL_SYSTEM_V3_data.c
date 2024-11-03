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
 * Model version                  : 1.5
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Oct 24 14:44:44 2024
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
   * Referenced by: '<S6>/Desire Max Value'
   */
  255.0,

  /* Variable: Desire_Min
   * Referenced by: '<S6>/Desire Min Value'
   */
  0.0,

  /* Variable: Direction_Pin
   * Referenced by: '<S8>/Direction Pin'
   */
  1.0,

  /* Variable: EN_Pin
   * Referenced by: '<S8>/Enable Pin'
   */
  0.0,

  /* Variable: Kd
   * Referenced by: '<S84>/Derivative Gain'
   */
  2.0,

  /* Variable: Ki
   * Referenced by: '<S88>/Integral Gain'
   */
  4.0,

  /* Variable: Kn
   * Referenced by: '<S94>/Filter Coefficient'
   */
  0.1,

  /* Variable: Kp
   * Referenced by: '<S96>/Proportional Gain'
   */
  1.4,

  /* Mask Parameter: OnDelay_DelayType
   * Referenced by: '<S33>/Constant2'
   */
  1.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S86>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_o
   * Referenced by: '<S91>/Integrator'
   */
  0.0,

  /* Mask Parameter: OnDelay_delay
   * Referenced by: '<S33>/Constant1'
   */
  1.0,

  /* Mask Parameter: SampleandHold_ic
   * Referenced by: '<S43>/IC=ic'
   */
  -1.0E+99,

  /* Mask Parameter: SampleandHold_ic_k
   * Referenced by: '<S51>/IC=ic'
   */
  -1.0E+99,

  /* Mask Parameter: EdgeDetector_model
   * Referenced by: '<S38>/Constant1'
   */
  2.0,

  /* Mask Parameter: EdgeDetector_model_a
   * Referenced by: '<S46>/Constant1'
   */
  1.0,

  /* Mask Parameter: Observer_x0
   * Referenced by: '<S28>/Integrator'
   */
  0.0,

  /* Mask Parameter: OnDelay_ic
   * Referenced by:
   *   '<S38>/Memory'
   *   '<S46>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop3_initial_condition
   * Referenced by: '<S52>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop5_initial_condition
   * Referenced by: '<S54>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop6_initial_condition
   * Referenced by: '<S55>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop4_initial_condition
   * Referenced by: '<S53>/Memory'
   */
  false,

  /* Expression: -1
   * Referenced by: '<S3>/MATLAB System'
   */
  -1.0,

  /* Expression: -1e6
   * Referenced by: '<S42>/Out1'
   */
  -1.0E+6,

  /* Expression: [1 0]
   * Referenced by: '<S38>/pos. edge'
   */
  { 1.0, 0.0 },

  /* Expression: [0 1]
   * Referenced by: '<S38>/neg. edge'
   */
  { 0.0, 1.0 },

  /* Expression: [1 1]
   * Referenced by: '<S38>/either edge'
   */
  { 1.0, 1.0 },

  /* Expression: -1e6
   * Referenced by: '<S50>/Out1'
   */
  -1.0E+6,

  /* Expression: [1 0]
   * Referenced by: '<S46>/pos. edge'
   */
  { 1.0, 0.0 },

  /* Expression: [0 1]
   * Referenced by: '<S46>/neg. edge'
   */
  { 0.0, 1.0 },

  /* Expression: [1 1]
   * Referenced by: '<S46>/either edge'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: Propotional_Y0
   * Referenced by: '<S12>/Propotional'
   */
  0.0,

  /* Computed Parameter: PIDOutput_Y0
   * Referenced by: '<S11>/PID Output'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S91>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S86>/Filter'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S11>/Constant'
   */
  0.01,

  /* Computed Parameter: ADRCOutput_Y0
   * Referenced by: '<S2>/ADRC Output'
   */
  0.0,

  /* Expression: a
   * Referenced by: '<S27>/Constant'
   */
  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /* Expression: wc^2
   * Referenced by: '<S26>/Gain'
   */
  100.0,

  /* Expression: 2*wc
   * Referenced by: '<S26>/Gain2'
   */
  20.0,

  /* Expression: 1/b0
   * Referenced by: '<S26>/Gain1'
   */
  0.0005,

  /* Expression: b
   * Referenced by: '<S27>/Constant1'
   */
  { 0.0, 2000.0, 0.0 },

  /* Expression: d
   * Referenced by: '<S27>/Constant3'
   */
  0.0,

  /* Expression: c
   * Referenced by: '<S27>/Constant2'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: l
   * Referenced by: '<S27>/Constant8'
   */
  { 240.0, 19200.0, 512000.0 },

  /* Expression: 2
   * Referenced by: '<S2>/Constant'
   */
  2.0,

  /* Expression: -1
   * Referenced by: '<S9>/Digital Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S9>/Digital Input1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S9>/Digital Input2'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S9>/Digital Input3'
   */
  -1.0,

  /* Expression: 100
   * Referenced by: '<S1>/Constant3'
   */
  100.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Switch3'
   */
  0.1,

  /* Expression: 1
   * Referenced by: '<S33>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S4>/Pulse Generator'
   */
  50.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S4>/Pulse Generator'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S4>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S15>/Gain'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Switch2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_m
   * Referenced by: '<S5>/Pulse Generator'
   */
  10.0,

  /* Computed Parameter: PulseGenerator_Duty_p
   * Referenced by: '<S5>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S5>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant4'
   */
  0.0,

  /* Computed Parameter: OUT_Y0
   * Referenced by: '<S34>/OUT'
   */
  false,

  /* Computed Parameter: OUT_Y0_o
   * Referenced by: '<S35>/OUT'
   */
  false,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S52>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_i
   * Referenced by: '<S54>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_j
   * Referenced by: '<S55>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_d
   * Referenced by: '<S53>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S8>/Gain'
   */
  200U,

  /* Computed Parameter: Multiply1_Gain
   * Referenced by: '<S10>/Multiply1'
   */
  128U,

  /* Computed Parameter: Multiply2_Gain
   * Referenced by: '<S10>/Multiply2'
   */
  192U,

  /* Computed Parameter: Multiply_Gain
   * Referenced by: '<S10>/Multiply'
   */
  128U,

  /* Start of '<S46>/POSITIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S49>/OUT'
     */
    false
  }
  ,

  /* End of '<S46>/POSITIVE Edge' */

  /* Start of '<S46>/NEGATIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S48>/OUT'
     */
    false
  }
  ,

  /* End of '<S46>/NEGATIVE Edge' */

  /* Start of '<S38>/POSITIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S41>/OUT'
     */
    false
  }
  ,

  /* End of '<S38>/POSITIVE Edge' */

  /* Start of '<S38>/NEGATIVE Edge' */
  {
    /* Computed Parameter: OUT_Y0
     * Referenced by: '<S40>/OUT'
     */
    false
  }
  /* End of '<S38>/NEGATIVE Edge' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
