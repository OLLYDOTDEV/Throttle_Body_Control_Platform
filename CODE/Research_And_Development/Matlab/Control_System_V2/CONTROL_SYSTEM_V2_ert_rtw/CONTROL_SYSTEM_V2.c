/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: CONTROL_SYSTEM_V2.c
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
#include "CONTROL_SYSTEM_V2_types.h"
#include "CONTROL_SYSTEM_V2_private.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals (default storage) */
B_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_B;

/* Continuous states */
X_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_X;

/* Disabled State Vector */
XDis_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_XDis;

/* Block states (default storage) */
DW_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_DW;

/* Real-time model */
static RT_MODEL_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_M_;
RT_MODEL_CONTROL_SYSTEM_V2_T *const CONTROL_SYSTEM_V2_M = &CONTROL_SYSTEM_V2_M_;

/* Forward declaration for local functions */
static void CONTROL_SYST_SystemCore_release(codertarget_arduinobase_inter_T *obj);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  CONTROL_SYSTEM_V2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  CONTROL_SYSTEM_V2_step();
  CONTROL_SYSTEM_V2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  CONTROL_SYSTEM_V2_step();
  CONTROL_SYSTEM_V2_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void CONTROL_SYST_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  /* Start for MATLABSystem: '<S2>/PWM' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }

  /* End of Start for MATLABSystem: '<S2>/PWM' */
}

/* Model step function */
void CONTROL_SYSTEM_V2_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_RelationalOperator;
  real_T rtb_Switch;
  int32_T rowIdx;
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T tmp;
  boolean_T rowIdx_tmp;
  boolean_T rowIdx_tmp_0;
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&CONTROL_SYSTEM_V2_M->solverInfo,
                          ((CONTROL_SYSTEM_V2_M->Timing.clockTick0+1)*
      CONTROL_SYSTEM_V2_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(CONTROL_SYSTEM_V2_M)) {
    CONTROL_SYSTEM_V2_M->Timing.t[0] = rtsiGetT(&CONTROL_SYSTEM_V2_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V2_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V2_DW.PIDControl_SubsysRanBC);

  /* MATLABSystem: '<S6>/Digital Input2' */
  if (CONTROL_SYSTEM_V2_DW.obj_d.SampleTime !=
      CONTROL_SYSTEM_V2_P.DigitalInput2_SampleTime) {
    CONTROL_SYSTEM_V2_DW.obj_d.SampleTime =
      CONTROL_SYSTEM_V2_P.DigitalInput2_SampleTime;
  }

  /* MATLABSystem: '<S6>/Digital Input2' */
  CONTROL_SYSTEM_V2_B.DigitalInput2 = readDigitalPin(36);

  /* MATLABSystem: '<S6>/Digital Input1' */
  if (CONTROL_SYSTEM_V2_DW.obj_m.SampleTime !=
      CONTROL_SYSTEM_V2_P.DigitalInput1_SampleTime) {
    CONTROL_SYSTEM_V2_DW.obj_m.SampleTime =
      CONTROL_SYSTEM_V2_P.DigitalInput1_SampleTime;
  }

  /* MATLABSystem: '<S6>/Digital Input1' */
  CONTROL_SYSTEM_V2_B.DigitalInput1 = readDigitalPin(34);

  /* MATLABSystem: '<S6>/Digital Input' */
  if (CONTROL_SYSTEM_V2_DW.obj_do.SampleTime !=
      CONTROL_SYSTEM_V2_P.DigitalInput_SampleTime) {
    CONTROL_SYSTEM_V2_DW.obj_do.SampleTime =
      CONTROL_SYSTEM_V2_P.DigitalInput_SampleTime;
  }

  /* MATLABSystem: '<S6>/Digital Input' */
  CONTROL_SYSTEM_V2_B.DigitalInput = readDigitalPin(35);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
    /* Memory: '<S65>/Memory' */
    CONTROL_SYSTEM_V2_B.Memory = CONTROL_SYSTEM_V2_DW.Memory_PreviousInput;
  }

  /* Logic: '<S6>/Logical Operator14' incorporates:
   *  Logic: '<S6>/Logical Operator6'
   */
  rowIdx_tmp = !CONTROL_SYSTEM_V2_B.DigitalInput1;

  /* Logic: '<S6>/Logical Operator13' incorporates:
   *  Logic: '<S6>/Logical Operator10'
   */
  rowIdx_tmp_0 = !CONTROL_SYSTEM_V2_B.DigitalInput;

  /* CombinatorialLogic: '<S65>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator12'
   *  Logic: '<S6>/Logical Operator13'
   *  Logic: '<S6>/Logical Operator14'
   *  Logic: '<S6>/Logical Operator15'
   *  Logic: '<S6>/Logical Operator3'
   */
  rowIdx = (int32_T)(((((uint32_T)(CONTROL_SYSTEM_V2_B.DigitalInput2 &&
    (rowIdx_tmp && rowIdx_tmp_0)) << 1) + (uint32_T)(int8_T)((int8_T)
    CONTROL_SYSTEM_V2_B.DigitalInput ^ (int8_T)CONTROL_SYSTEM_V2_B.DigitalInput1))
                      << 1) + CONTROL_SYSTEM_V2_B.Memory);
  CONTROL_SYSTEM_V2_B.Logic[0U] = CONTROL_SYSTEM_V2_P.Logic_table[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V2_B.Logic[1U] = CONTROL_SYSTEM_V2_P.Logic_table[(uint32_T)
    rowIdx + 8U];
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  if (CONTROL_SYSTEM_V2_DW.obj.SampleTime !=
      CONTROL_SYSTEM_V2_P.MATLABSystem_SampleTime) {
    CONTROL_SYSTEM_V2_DW.obj.SampleTime =
      CONTROL_SYSTEM_V2_P.MATLABSystem_SampleTime;
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  /*         %% Define output properties */
  CONTROL_SYSTEM_V2_B.MATLABSystem_o1 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  CONTROL_SYSTEM_V2_B.MATLABSystem_o2 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  CONTROL_SYSTEM_V2_B.MATLABSystem_o3 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  CONTROL_SYSTEM_V2_B.MATLABSystem_o4 = 0.0;
  stepFunctionADS1115_Vread(&CONTROL_SYSTEM_V2_B.MATLABSystem_o1, 1.0,
    &CONTROL_SYSTEM_V2_B.MATLABSystem_o2, 1.0,
    &CONTROL_SYSTEM_V2_B.MATLABSystem_o3, 1.0,
    &CONTROL_SYSTEM_V2_B.MATLABSystem_o4, 1.0);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
    /* MATLAB Function: '<Root>/Pedal Calibration' */
    if (CONTROL_SYSTEM_V2_B.MATLABSystem_o3 > CONTROL_SYSTEM_V2_DW.maxSet) {
      CONTROL_SYSTEM_V2_DW.maxSet = CONTROL_SYSTEM_V2_B.MATLABSystem_o3;
    }

    if (CONTROL_SYSTEM_V2_B.MATLABSystem_o3 < CONTROL_SYSTEM_V2_DW.minSet) {
      CONTROL_SYSTEM_V2_DW.minSet = CONTROL_SYSTEM_V2_B.MATLABSystem_o3;
    }

    CONTROL_SYSTEM_V2_B.FP_maxVal = CONTROL_SYSTEM_V2_DW.maxSet;
    CONTROL_SYSTEM_V2_B.FP_minVal = CONTROL_SYSTEM_V2_DW.minSet;

    /* End of MATLAB Function: '<Root>/Pedal Calibration' */

    /* Memory: '<S63>/Memory' */
    CONTROL_SYSTEM_V2_B.Memory_h = CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_p;

    /* Memory: '<S64>/Memory' */
    CONTROL_SYSTEM_V2_B.Memory_n = CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_e;
  }

  /* CombinatorialLogic: '<S63>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator4'
   *  Logic: '<S6>/Logical Operator5'
   *  Logic: '<S6>/Logical Operator7'
   */
  rowIdx = (int32_T)(((((uint32_T)(CONTROL_SYSTEM_V2_B.DigitalInput &&
    ((!CONTROL_SYSTEM_V2_B.DigitalInput2) && rowIdx_tmp)) << 1) + (uint32_T)
                       (int8_T)((int8_T)CONTROL_SYSTEM_V2_B.DigitalInput1 ^
    (int8_T)CONTROL_SYSTEM_V2_B.DigitalInput2)) << 1) +
                     CONTROL_SYSTEM_V2_B.Memory_h);
  CONTROL_SYSTEM_V2_B.Logic_k[0U] = CONTROL_SYSTEM_V2_P.Logic_table_p[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V2_B.Logic_k[1U] = CONTROL_SYSTEM_V2_P.Logic_table_p[(uint32_T)
    rowIdx + 8U];

  /* CombinatorialLogic: '<S64>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator11'
   *  Logic: '<S6>/Logical Operator2'
   *  Logic: '<S6>/Logical Operator8'
   *  Logic: '<S6>/Logical Operator9'
   */
  rowIdx = (int32_T)(((((uint32_T)(CONTROL_SYSTEM_V2_B.DigitalInput1 &&
    (rowIdx_tmp_0 && (!CONTROL_SYSTEM_V2_B.DigitalInput2))) << 1) + (uint32_T)
                       (int8_T)((int8_T)CONTROL_SYSTEM_V2_B.DigitalInput ^
    (int8_T)CONTROL_SYSTEM_V2_B.DigitalInput2)) << 1) +
                     CONTROL_SYSTEM_V2_B.Memory_n);
  CONTROL_SYSTEM_V2_B.Logic_n[0U] = CONTROL_SYSTEM_V2_P.Logic_table_k[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V2_B.Logic_n[1U] = CONTROL_SYSTEM_V2_P.Logic_table_k[(uint32_T)
    rowIdx + 8U];
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
    /* Sum: '<S9>/Add2' */
    CONTROL_SYSTEM_V2_B.Add2 = CONTROL_SYSTEM_V2_B.FP_maxVal -
      CONTROL_SYSTEM_V2_B.FP_minVal;

    /* MATLAB Function: '<Root>/Throttle Body Callibration' */
    if (CONTROL_SYSTEM_V2_B.MATLABSystem_o2 > CONTROL_SYSTEM_V2_DW.TB_maxSet) {
      CONTROL_SYSTEM_V2_DW.TB_maxSet = CONTROL_SYSTEM_V2_B.MATLABSystem_o2;
    }

    if (CONTROL_SYSTEM_V2_B.MATLABSystem_o2 < CONTROL_SYSTEM_V2_DW.TB_minSet) {
      CONTROL_SYSTEM_V2_DW.TB_minSet = CONTROL_SYSTEM_V2_B.MATLABSystem_o2;
    }

    CONTROL_SYSTEM_V2_B.TB_maxVal = CONTROL_SYSTEM_V2_DW.TB_maxSet;
    CONTROL_SYSTEM_V2_B.TB_minVal = CONTROL_SYSTEM_V2_DW.TB_minSet;

    /* End of MATLAB Function: '<Root>/Throttle Body Callibration' */

    /* Sum: '<S9>/Add3' */
    CONTROL_SYSTEM_V2_B.Add3 = CONTROL_SYSTEM_V2_B.TB_maxVal -
      CONTROL_SYSTEM_V2_B.TB_minVal;

    /* Product: '<S9>/Divide1' */
    CONTROL_SYSTEM_V2_B.Divide1 = CONTROL_SYSTEM_V2_B.Add2 /
      CONTROL_SYSTEM_V2_B.Add3;
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Product: '<S9>/Product1'
   *  Sum: '<S9>/Subtract'
   */
  CONTROL_SYSTEM_V2_B.Sum = (CONTROL_SYSTEM_V2_B.MATLABSystem_o2 -
    CONTROL_SYSTEM_V2_B.TB_minVal) * CONTROL_SYSTEM_V2_B.Divide1 +
    CONTROL_SYSTEM_V2_B.FP_minVal;

  /* Sum: '<Root>/Sum2' */
  CONTROL_SYSTEM_V2_B.Sum2 = CONTROL_SYSTEM_V2_B.MATLABSystem_o3 -
    CONTROL_SYSTEM_V2_B.Sum;

  /* If: '<Root>/If' */
  rtPrevAction = CONTROL_SYSTEM_V2_DW.If_ActiveSubsystem;
  if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V2_M->solverInfo)) {
    if (CONTROL_SYSTEM_V2_B.Logic[0]) {
      rtAction = 0;
    } else if (CONTROL_SYSTEM_V2_B.Logic_k[0]) {
      rtAction = 1;
    } else if (CONTROL_SYSTEM_V2_B.Logic_n[0]) {
      rtAction = 2;
    } else {
      rtAction = 3;
    }

    CONTROL_SYSTEM_V2_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = CONTROL_SYSTEM_V2_DW.If_ActiveSubsystem;
  }

  if (rtPrevAction != rtAction) {
    if (CONTROL_SYSTEM_V2_M->Timing.t[0] == rtmGetTStart(CONTROL_SYSTEM_V2_M)) {
      (void) memset(&(CONTROL_SYSTEM_V2_XDis.Integrator_CSTATE), 1,
                    2*sizeof(boolean_T));
    }

    if (rtPrevAction == 1) {
      (void) memset(&(CONTROL_SYSTEM_V2_XDis.Integrator_CSTATE), 1,
                    2*sizeof(boolean_T));
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* SignalConversion generated from: '<S3>/In1' */
    CONTROL_SYSTEM_V2_B.In1 = CONTROL_SYSTEM_V2_B.Sum2;
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V2_M->solverInfo)) {
      srUpdateBC(CONTROL_SYSTEM_V2_DW.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<Root>/PID Control' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* Enable for If: '<Root>/If' */
      (void) memset(&(CONTROL_SYSTEM_V2_XDis.Integrator_CSTATE), 0,
                    2*sizeof(boolean_T));

      /* End of Enable for SubSystem: '<Root>/PID Control' */
    }

    /* Outputs for IfAction SubSystem: '<Root>/PID Control' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
      /* Sum: '<S4>/Sum1' incorporates:
       *  Constant: '<S4>/Constant'
       */
      CONTROL_SYSTEM_V2_B.Sum1 = CONTROL_SYSTEM_V2_P.Constant_Value +
        CONTROL_SYSTEM_V2_B.FP_maxVal;
    }

    /* Gain: '<S49>/Filter Coefficient' incorporates:
     *  Gain: '<S39>/Derivative Gain'
     *  Integrator: '<S41>/Filter'
     *  Sum: '<S41>/SumD'
     */
    CONTROL_SYSTEM_V2_B.FilterCoefficient =
      (CONTROL_SYSTEM_V2_P.PIDController1_D * CONTROL_SYSTEM_V2_B.Sum2 -
       CONTROL_SYSTEM_V2_X.Filter_CSTATE) * CONTROL_SYSTEM_V2_P.PIDController1_N;

    /* Sum: '<S55>/Sum' incorporates:
     *  Gain: '<S51>/Proportional Gain'
     *  Integrator: '<S46>/Integrator'
     */
    CONTROL_SYSTEM_V2_B.Switch2 = (CONTROL_SYSTEM_V2_P.PIDController1_P *
      CONTROL_SYSTEM_V2_B.Sum2 + CONTROL_SYSTEM_V2_X.Integrator_CSTATE) +
      CONTROL_SYSTEM_V2_B.FilterCoefficient;

    /* Switch: '<S12>/Switch2' incorporates:
     *  RelationalOperator: '<S12>/LowerRelop1'
     *  RelationalOperator: '<S12>/UpperRelop'
     *  Switch: '<S12>/Switch'
     */
    if (CONTROL_SYSTEM_V2_B.Switch2 > CONTROL_SYSTEM_V2_B.Sum1) {
      /* Sum: '<S55>/Sum' incorporates:
       *  Switch: '<S12>/Switch2'
       */
      CONTROL_SYSTEM_V2_B.Switch2 = CONTROL_SYSTEM_V2_B.Sum1;
    } else if (CONTROL_SYSTEM_V2_B.Switch2 < CONTROL_SYSTEM_V2_B.FP_minVal) {
      /* Sum: '<S55>/Sum' incorporates:
       *  Switch: '<S12>/Switch'
       *  Switch: '<S12>/Switch2'
       */
      CONTROL_SYSTEM_V2_B.Switch2 = CONTROL_SYSTEM_V2_B.FP_minVal;
    }

    /* End of Switch: '<S12>/Switch2' */

    /* Gain: '<S43>/Integral Gain' */
    CONTROL_SYSTEM_V2_B.IntegralGain = CONTROL_SYSTEM_V2_P.PIDController1_I *
      CONTROL_SYSTEM_V2_B.Sum2;
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V2_M->solverInfo)) {
      srUpdateBC(CONTROL_SYSTEM_V2_DW.PIDControl_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<Root>/PID Control' */
    break;

   case 2:
    break;
  }

  /* End of If: '<Root>/If' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
    /* Sum: '<S1>/Add2' incorporates:
     *  Constant: '<S1>/Desire Max Value'
     *  Constant: '<S1>/Desire Min Value'
     */
    CONTROL_SYSTEM_V2_B.Add2_c = CONTROL_SYSTEM_V2_P.Desire_Max -
      CONTROL_SYSTEM_V2_P.Desire_Min;

    /* Sum: '<S1>/Add3' */
    CONTROL_SYSTEM_V2_B.Add3_e = CONTROL_SYSTEM_V2_B.FP_maxVal -
      CONTROL_SYSTEM_V2_B.FP_minVal;

    /* Product: '<S1>/Divide1' */
    CONTROL_SYSTEM_V2_B.Divide1_b = CONTROL_SYSTEM_V2_B.Add2_c /
      CONTROL_SYSTEM_V2_B.Add3_e;
  }

  /* Switch: '<Root>/Switch1' */
  if (CONTROL_SYSTEM_V2_B.Logic_k[0]) {
    rtb_Switch = CONTROL_SYSTEM_V2_B.Switch2;
  } else {
    rtb_Switch = CONTROL_SYSTEM_V2_B.In1;
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Desire Min Value'
   *  Product: '<S1>/Product1'
   *  Sum: '<S1>/Subtract'
   *  Switch: '<Root>/Switch1'
   */
  CONTROL_SYSTEM_V2_B.Sum_c = (rtb_Switch - CONTROL_SYSTEM_V2_B.FP_minVal) *
    CONTROL_SYSTEM_V2_B.Divide1_b + CONTROL_SYSTEM_V2_P.Desire_Min;

  /* Switch: '<S2>/Switch' incorporates:
   *  Gain: '<S2>/Gain'
   */
  if (CONTROL_SYSTEM_V2_B.DigitalInput2) {
    rtb_Switch = (real_T)(CONTROL_SYSTEM_V2_B.DigitalInput2 ? (int32_T)
                          CONTROL_SYSTEM_V2_P.Gain_Gain : 0) * 0.5;
  } else {
    rtb_Switch = CONTROL_SYSTEM_V2_B.Sum_c;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Start for MATLABSystem: '<S2>/PWM' */
  if (!(rtb_Switch <= 255.0)) {
    rtb_Switch = 255.0;
  }

  /* MATLABSystem: '<S2>/PWM' */
  CONTROL_SYSTEM_V2_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);

  /* Start for MATLABSystem: '<S2>/PWM' */
  if (!(rtb_Switch >= 0.0)) {
    rtb_Switch = 0.0;
  }

  /* MATLABSystem: '<S2>/PWM' */
  MW_PWM_SetDutyCycle(CONTROL_SYSTEM_V2_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                      -(rtb_Switch * 255.0 / 255.0));
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
    /* Constant: '<S2>/Enable Pin' */
    CONTROL_SYSTEM_V2_B.EnablePin = CONTROL_SYSTEM_V2_P.EN_Pin;

    /* MATLABSystem: '<S2>/Digital Output' */
    rtb_Switch = rt_roundd_snf(CONTROL_SYSTEM_V2_B.EnablePin);
    if (rtb_Switch < 256.0) {
      if (rtb_Switch >= 0.0) {
        tmp = (uint8_T)rtb_Switch;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(0, tmp);

    /* End of MATLABSystem: '<S2>/Digital Output' */
    /* Constant: '<S2>/Direction Pin' */
    CONTROL_SYSTEM_V2_B.DirectionPin = CONTROL_SYSTEM_V2_P.Direction_Pin;

    /* MATLABSystem: '<S2>/Digital Output1' */
    rtb_Switch = rt_roundd_snf(CONTROL_SYSTEM_V2_B.DirectionPin);
    if (rtb_Switch < 256.0) {
      if (rtb_Switch >= 0.0) {
        tmp = (uint8_T)rtb_Switch;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(16, tmp);

    /* End of MATLABSystem: '<S2>/Digital Output1' */
    /* MATLAB Function: '<S7>/MATLAB Function' */
    if (!CONTROL_SYSTEM_V2_DW.Previous_Val_not_empty) {
      CONTROL_SYSTEM_V2_DW.Previous_Val = 0.0;
      CONTROL_SYSTEM_V2_DW.Previous_Val_not_empty = true;
    } else {
      CONTROL_SYSTEM_V2_DW.Previous_Val = 0.0;
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function' */

    /* RelationalOperator: '<S7>/Relational Operator' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    rtb_RelationalOperator = (CONTROL_SYSTEM_V2_P.Constant2_Value >= 0.0);

    /* Switch: '<S7>/Switch' incorporates:
     *  RelationalOperator: '<S66>/FixPt Relational Operator'
     *  UnitDelay: '<S66>/Delay Input1'
     *
     * Block description for '<S66>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_RelationalOperator > (int32_T)
        CONTROL_SYSTEM_V2_DW.DelayInput1_DSTATE) {
      /* Switch: '<S7>/Switch' incorporates:
       *  Constant: '<S7>/Constant'
       */
      CONTROL_SYSTEM_V2_B.Switch = CONTROL_SYSTEM_V2_P.Constant_Value_l;
    } else {
      /* Switch: '<S7>/Switch' incorporates:
       *  Constant: '<S7>/Constant1'
       */
      CONTROL_SYSTEM_V2_B.Switch = CONTROL_SYSTEM_V2_P.Constant1_Value;
    }

    /* End of Switch: '<S7>/Switch' */
  }

  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
      /* Update for Memory: '<S65>/Memory' */
      CONTROL_SYSTEM_V2_DW.Memory_PreviousInput = CONTROL_SYSTEM_V2_B.Logic[0];

      /* Update for Memory: '<S63>/Memory' */
      CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_p = CONTROL_SYSTEM_V2_B.Logic_k
        [0];

      /* Update for Memory: '<S64>/Memory' */
      CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_e = CONTROL_SYSTEM_V2_B.Logic_n
        [0];

      /* Update for UnitDelay: '<S66>/Delay Input1'
       *
       * Block description for '<S66>/Delay Input1':
       *
       *  Store in Global RAM
       */
      CONTROL_SYSTEM_V2_DW.DelayInput1_DSTATE = rtb_RelationalOperator;
    }

    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {/* Sample time: [0.05s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((CONTROL_SYSTEM_V2_M->Timing.clockTick1) * 0.05);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V2_M)) {
    rt_ertODEUpdateContinuousStates(&CONTROL_SYSTEM_V2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++CONTROL_SYSTEM_V2_M->Timing.clockTick0;
    CONTROL_SYSTEM_V2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&CONTROL_SYSTEM_V2_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.05s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.05, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      CONTROL_SYSTEM_V2_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void CONTROL_SYSTEM_V2_derivatives(void)
{
  XDot_CONTROL_SYSTEM_V2_T *_rtXdot;
  _rtXdot = ((XDot_CONTROL_SYSTEM_V2_T *) CONTROL_SYSTEM_V2_M->derivs);

  /* Derivatives for If: '<Root>/If' */
  {
    real_T *dx;
    int_T i1;
    dx = &(((XDot_CONTROL_SYSTEM_V2_T *) CONTROL_SYSTEM_V2_M->derivs)
           ->Integrator_CSTATE);
    for (i1=0; i1 < 2; i1++) {
      dx[i1] = 0.0;
    }
  }

  if (CONTROL_SYSTEM_V2_DW.If_ActiveSubsystem == 1) {
    /* Derivatives for IfAction SubSystem: '<Root>/PID Control' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Derivatives for Integrator: '<S46>/Integrator' */
    _rtXdot->Integrator_CSTATE = CONTROL_SYSTEM_V2_B.IntegralGain;

    /* Derivatives for Integrator: '<S41>/Filter' */
    _rtXdot->Filter_CSTATE = CONTROL_SYSTEM_V2_B.FilterCoefficient;

    /* End of Derivatives for SubSystem: '<Root>/PID Control' */
  }

  /* End of Derivatives for If: '<Root>/If' */
}

/* Model initialize function */
void CONTROL_SYSTEM_V2_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CONTROL_SYSTEM_V2_M->solverInfo,
                          &CONTROL_SYSTEM_V2_M->Timing.simTimeStep);
    rtsiSetTPtr(&CONTROL_SYSTEM_V2_M->solverInfo, &rtmGetTPtr
                (CONTROL_SYSTEM_V2_M));
    rtsiSetStepSizePtr(&CONTROL_SYSTEM_V2_M->solverInfo,
                       &CONTROL_SYSTEM_V2_M->Timing.stepSize0);
    rtsiSetdXPtr(&CONTROL_SYSTEM_V2_M->solverInfo, &CONTROL_SYSTEM_V2_M->derivs);
    rtsiSetContStatesPtr(&CONTROL_SYSTEM_V2_M->solverInfo, (real_T **)
                         &CONTROL_SYSTEM_V2_M->contStates);
    rtsiSetNumContStatesPtr(&CONTROL_SYSTEM_V2_M->solverInfo,
      &CONTROL_SYSTEM_V2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&CONTROL_SYSTEM_V2_M->solverInfo,
      &CONTROL_SYSTEM_V2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&CONTROL_SYSTEM_V2_M->solverInfo,
      &CONTROL_SYSTEM_V2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&CONTROL_SYSTEM_V2_M->solverInfo,
      &CONTROL_SYSTEM_V2_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&CONTROL_SYSTEM_V2_M->solverInfo, (boolean_T**)
      &CONTROL_SYSTEM_V2_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&CONTROL_SYSTEM_V2_M->solverInfo, (&rtmGetErrorStatus
      (CONTROL_SYSTEM_V2_M)));
    rtsiSetRTModelPtr(&CONTROL_SYSTEM_V2_M->solverInfo, CONTROL_SYSTEM_V2_M);
  }

  rtsiSetSimTimeStep(&CONTROL_SYSTEM_V2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&CONTROL_SYSTEM_V2_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&CONTROL_SYSTEM_V2_M->solverInfo, false);
  CONTROL_SYSTEM_V2_M->intgData.y = CONTROL_SYSTEM_V2_M->odeY;
  CONTROL_SYSTEM_V2_M->intgData.f[0] = CONTROL_SYSTEM_V2_M->odeF[0];
  CONTROL_SYSTEM_V2_M->intgData.f[1] = CONTROL_SYSTEM_V2_M->odeF[1];
  CONTROL_SYSTEM_V2_M->intgData.f[2] = CONTROL_SYSTEM_V2_M->odeF[2];
  CONTROL_SYSTEM_V2_M->contStates = ((X_CONTROL_SYSTEM_V2_T *)
    &CONTROL_SYSTEM_V2_X);
  CONTROL_SYSTEM_V2_M->contStateDisabled = ((XDis_CONTROL_SYSTEM_V2_T *)
    &CONTROL_SYSTEM_V2_XDis);
  CONTROL_SYSTEM_V2_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&CONTROL_SYSTEM_V2_M->solverInfo, (void *)
                    &CONTROL_SYSTEM_V2_M->intgData);
  rtsiSetSolverName(&CONTROL_SYSTEM_V2_M->solverInfo,"ode3");
  rtmSetTPtr(CONTROL_SYSTEM_V2_M, &CONTROL_SYSTEM_V2_M->Timing.tArray[0]);
  rtmSetTFinal(CONTROL_SYSTEM_V2_M, -1);
  CONTROL_SYSTEM_V2_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  CONTROL_SYSTEM_V2_M->Sizes.checksums[0] = (329306841U);
  CONTROL_SYSTEM_V2_M->Sizes.checksums[1] = (3969144793U);
  CONTROL_SYSTEM_V2_M->Sizes.checksums[2] = (1761222855U);
  CONTROL_SYSTEM_V2_M->Sizes.checksums[3] = (2374127689U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[17];
    CONTROL_SYSTEM_V2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &CONTROL_SYSTEM_V2_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)&CONTROL_SYSTEM_V2_DW.PIDControl_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&CONTROL_SYSTEM_V2_DW.PIDControl_SubsysRanBC;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(CONTROL_SYSTEM_V2_M->extModeInfo,
      &CONTROL_SYSTEM_V2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(CONTROL_SYSTEM_V2_M->extModeInfo,
                        CONTROL_SYSTEM_V2_M->Sizes.checksums);
    rteiSetTPtr(CONTROL_SYSTEM_V2_M->extModeInfo, rtmGetTPtr(CONTROL_SYSTEM_V2_M));
  }

  /* Start for If: '<Root>/If' */
  (void) memset(&(CONTROL_SYSTEM_V2_XDis.Integrator_CSTATE), 1,
                2*sizeof(boolean_T));
  CONTROL_SYSTEM_V2_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for Memory: '<S65>/Memory' */
  CONTROL_SYSTEM_V2_DW.Memory_PreviousInput =
    CONTROL_SYSTEM_V2_P.SRFlipFlop2_initial_condition;

  /* InitializeConditions for Memory: '<S63>/Memory' */
  CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_p =
    CONTROL_SYSTEM_V2_P.SRFlipFlop_initial_condition;

  /* InitializeConditions for Memory: '<S64>/Memory' */
  CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_e =
    CONTROL_SYSTEM_V2_P.SRFlipFlop1_initial_condition;

  /* InitializeConditions for UnitDelay: '<S66>/Delay Input1'
   *
   * Block description for '<S66>/Delay Input1':
   *
   *  Store in Global RAM
   */
  CONTROL_SYSTEM_V2_DW.DelayInput1_DSTATE =
    CONTROL_SYSTEM_V2_P.DetectIncrease1_vinit;

  /* SystemInitialize for MATLAB Function: '<Root>/Pedal Calibration' */
  CONTROL_SYSTEM_V2_DW.maxSet = -1.0;
  CONTROL_SYSTEM_V2_DW.minSet = 5.0;

  /* SystemInitialize for MATLAB Function: '<Root>/Throttle Body Callibration' */
  CONTROL_SYSTEM_V2_DW.TB_minSet = 5.0;

  /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S3>/In1' incorporates:
   *  Outport: '<S3>/Out1'
   */
  CONTROL_SYSTEM_V2_B.In1 = CONTROL_SYSTEM_V2_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/PID Control' */
  /* InitializeConditions for Integrator: '<S46>/Integrator' */
  CONTROL_SYSTEM_V2_X.Integrator_CSTATE =
    CONTROL_SYSTEM_V2_P.PIDController1_InitialConditi_a;

  /* InitializeConditions for Integrator: '<S41>/Filter' */
  CONTROL_SYSTEM_V2_X.Filter_CSTATE =
    CONTROL_SYSTEM_V2_P.PIDController1_InitialCondition;

  /* SystemInitialize for Sum: '<S55>/Sum' incorporates:
   *  Outport: '<S4>/PID Output'
   *  Switch: '<S12>/Switch2'
   */
  CONTROL_SYSTEM_V2_B.Switch2 = CONTROL_SYSTEM_V2_P.PIDOutput_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/PID Control' */

  /* Start for MATLABSystem: '<S6>/Digital Input2' */
  CONTROL_SYSTEM_V2_DW.obj_d.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V2_DW.obj_d.SampleTime =
    CONTROL_SYSTEM_V2_P.DigitalInput2_SampleTime;
  CONTROL_SYSTEM_V2_DW.obj_d.isInitialized = 1;
  digitalIOSetup(36, 0);
  CONTROL_SYSTEM_V2_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Digital Input1' */
  CONTROL_SYSTEM_V2_DW.obj_m.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V2_DW.obj_m.SampleTime =
    CONTROL_SYSTEM_V2_P.DigitalInput1_SampleTime;
  CONTROL_SYSTEM_V2_DW.obj_m.isInitialized = 1;
  digitalIOSetup(34, 0);
  CONTROL_SYSTEM_V2_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Digital Input' */
  CONTROL_SYSTEM_V2_DW.obj_do.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V2_DW.obj_do.SampleTime =
    CONTROL_SYSTEM_V2_P.DigitalInput_SampleTime;
  CONTROL_SYSTEM_V2_DW.obj_do.isInitialized = 1;
  digitalIOSetup(35, 0);
  CONTROL_SYSTEM_V2_DW.obj_do.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  CONTROL_SYSTEM_V2_DW.obj.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V2_DW.obj.SampleTime =
    CONTROL_SYSTEM_V2_P.MATLABSystem_SampleTime;
  CONTROL_SYSTEM_V2_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionADS1115_Vread(16, 1.0);
  CONTROL_SYSTEM_V2_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM' */
  CONTROL_SYSTEM_V2_DW.obj_n.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V2_DW.obj_n.isInitialized = 1;
  CONTROL_SYSTEM_V2_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4U,
    19000.0, 255.0);
  CONTROL_SYSTEM_V2_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  CONTROL_SYSTEM_V2_DW.obj_a.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V2_DW.obj_a.isInitialized = 1;
  digitalIOSetup(0, 1);
  CONTROL_SYSTEM_V2_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output1' */
  CONTROL_SYSTEM_V2_DW.obj_j.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V2_DW.obj_j.isInitialized = 1;
  digitalIOSetup(16, 1);
  CONTROL_SYSTEM_V2_DW.obj_j.isSetupComplete = true;
}

/* Model terminate function */
void CONTROL_SYSTEM_V2_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/Digital Input2' */
  if (!CONTROL_SYSTEM_V2_DW.obj_d.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V2_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Input2' */

  /* Terminate for MATLABSystem: '<S6>/Digital Input1' */
  if (!CONTROL_SYSTEM_V2_DW.obj_m.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V2_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Input1' */

  /* Terminate for MATLABSystem: '<S6>/Digital Input' */
  if (!CONTROL_SYSTEM_V2_DW.obj_do.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V2_DW.obj_do.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Input' */
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!CONTROL_SYSTEM_V2_DW.obj.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */
  /* Terminate for MATLABSystem: '<S2>/PWM' */
  if (!CONTROL_SYSTEM_V2_DW.obj_n.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V2_DW.obj_n.matlabCodegenIsDeleted = true;
    CONTROL_SYST_SystemCore_release(&CONTROL_SYSTEM_V2_DW.obj_n);
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!CONTROL_SYSTEM_V2_DW.obj_a.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V2_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output1' */
  if (!CONTROL_SYSTEM_V2_DW.obj_j.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V2_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
