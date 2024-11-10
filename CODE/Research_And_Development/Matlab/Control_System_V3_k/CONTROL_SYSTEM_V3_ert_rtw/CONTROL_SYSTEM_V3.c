/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: CONTROL_SYSTEM_V3.c
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
#include "rtwtypes.h"
#include "CONTROL_SYSTEM_V3_types.h"
#include "CONTROL_SYSTEM_V3_private.h"
#include "zero_crossing_types.h"
#include <math.h>

/* Block signals (default storage) */
B_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_B;

/* Continuous states */
X_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_X;

/* Disabled State Vector */
XDis_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_XDis;

/* Block states (default storage) */
DW_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_PrevZCX;

/* Real-time model */
static RT_MODEL_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_M_;
RT_MODEL_CONTROL_SYSTEM_V3_T *const CONTROL_SYSTEM_V3_M = &CONTROL_SYSTEM_V3_M_;

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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  CONTROL_SYSTEM_V3_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  CONTROL_SYSTEM_V3_step();
  CONTROL_SYSTEM_V3_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  CONTROL_SYSTEM_V3_step();
  CONTROL_SYSTEM_V3_derivatives();

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

/*
 * System initialize for enable system:
 *    '<S35>/NEGATIVE Edge'
 *    '<S43>/NEGATIVE Edge'
 */
void CONTROL_SYSTE_NEGATIVEEdge_Init(boolean_T *rty_OUT,
  P_NEGATIVEEdge_CONTROL_SYSTEM_T *localP)
{
  /* SystemInitialize for Outport: '<S37>/OUT' */
  *rty_OUT = localP->OUT_Y0;
}

/*
 * Disable for enable system:
 *    '<S35>/NEGATIVE Edge'
 *    '<S43>/NEGATIVE Edge'
 */
void CONTROL_SY_NEGATIVEEdge_Disable(DW_NEGATIVEEdge_CONTROL_SYSTE_T *localDW)
{
  localDW->NEGATIVEEdge_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S35>/NEGATIVE Edge'
 *    '<S43>/NEGATIVE Edge'
 */
void CONTROL_SYSTEM_V3_NEGATIVEEdge(RT_MODEL_CONTROL_SYSTEM_V3_T * const
  CONTROL_SYSTEM_V3_M, real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, boolean_T *rty_OUT, DW_NEGATIVEEdge_CONTROL_SYSTE_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S35>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M) && rtsiIsModeUpdateTimeStep
      (&CONTROL_SYSTEM_V3_M->solverInfo)) {
    if (rtu_Enable > 0.0) {
      localDW->NEGATIVEEdge_MODE = true;
    } else if (localDW->NEGATIVEEdge_MODE) {
      CONTROL_SY_NEGATIVEEdge_Disable(localDW);
    }
  }

  if (localDW->NEGATIVEEdge_MODE) {
    /* RelationalOperator: '<S37>/Relational Operator1' */
    *rty_OUT = ((int32_T)rtu_INprevious > (int32_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S35>/NEGATIVE Edge' */
}

/*
 * System initialize for enable system:
 *    '<S35>/POSITIVE Edge'
 *    '<S43>/POSITIVE Edge'
 */
void CONTROL_SYSTE_POSITIVEEdge_Init(boolean_T *rty_OUT,
  P_POSITIVEEdge_CONTROL_SYSTEM_T *localP)
{
  /* SystemInitialize for Outport: '<S38>/OUT' */
  *rty_OUT = localP->OUT_Y0;
}

/*
 * Disable for enable system:
 *    '<S35>/POSITIVE Edge'
 *    '<S43>/POSITIVE Edge'
 */
void CONTROL_SY_POSITIVEEdge_Disable(DW_POSITIVEEdge_CONTROL_SYSTE_T *localDW)
{
  localDW->POSITIVEEdge_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S35>/POSITIVE Edge'
 *    '<S43>/POSITIVE Edge'
 */
void CONTROL_SYSTEM_V3_POSITIVEEdge(RT_MODEL_CONTROL_SYSTEM_V3_T * const
  CONTROL_SYSTEM_V3_M, real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, boolean_T *rty_OUT, DW_POSITIVEEdge_CONTROL_SYSTE_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S35>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S38>/Enable'
   */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M) && rtsiIsModeUpdateTimeStep
      (&CONTROL_SYSTEM_V3_M->solverInfo)) {
    if (rtu_Enable > 0.0) {
      localDW->POSITIVEEdge_MODE = true;
    } else if (localDW->POSITIVEEdge_MODE) {
      CONTROL_SY_POSITIVEEdge_Disable(localDW);
    }
  }

  if (localDW->POSITIVEEdge_MODE) {
    /* RelationalOperator: '<S38>/Relational Operator1' */
    *rty_OUT = ((int32_T)rtu_INprevious < (int32_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S35>/POSITIVE Edge' */
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
  /* Start for MATLABSystem: '<S7>/PWM' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }

  /* End of Start for MATLABSystem: '<S7>/PWM' */
}

/* Model step function */
void CONTROL_SYSTEM_V3_step(void)
{
  real_T Integrator_CSTATE;
  real_T Integrator_CSTATE_0;
  real_T rtb_Error;
  real_T rtb_FP_maxVal;
  real_T rtb_Sum;
  int32_T rowIdx;
  int8_T rowIdx_tmp_4;
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T tmp;
  boolean_T LogicalOperator1;
  boolean_T c_value;
  boolean_T c_value_0;
  boolean_T c_value_1;
  boolean_T rowIdx_tmp;
  boolean_T rowIdx_tmp_0;
  boolean_T rowIdx_tmp_1;
  boolean_T rowIdx_tmp_2;
  boolean_T rowIdx_tmp_3;
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&CONTROL_SYSTEM_V3_M->solverInfo,
                          ((CONTROL_SYSTEM_V3_M->Timing.clockTick0+1)*
      CONTROL_SYSTEM_V3_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(CONTROL_SYSTEM_V3_M)) {
    CONTROL_SYSTEM_V3_M->Timing.t[0] = rtsiGetT(&CONTROL_SYSTEM_V3_M->solverInfo);
  }

  /* MATLABSystem: '<S8>/Digital Input' */
  if (CONTROL_SYSTEM_V3_DW.obj_c.SampleTime !=
      CONTROL_SYSTEM_V3_P.DigitalInput_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj_c.SampleTime =
      CONTROL_SYSTEM_V3_P.DigitalInput_SampleTime;
  }

  LogicalOperator1 = readDigitalPin(36);

  /* MATLABSystem: '<S8>/Digital Input3' */
  if (CONTROL_SYSTEM_V3_DW.obj_f.SampleTime !=
      CONTROL_SYSTEM_V3_P.DigitalInput3_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj_f.SampleTime =
      CONTROL_SYSTEM_V3_P.DigitalInput3_SampleTime;
  }

  c_value = readDigitalPin(35);

  /* MATLABSystem: '<S8>/Digital Input1' */
  if (CONTROL_SYSTEM_V3_DW.obj_hd.SampleTime !=
      CONTROL_SYSTEM_V3_P.DigitalInput1_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj_hd.SampleTime =
      CONTROL_SYSTEM_V3_P.DigitalInput1_SampleTime;
  }

  c_value_0 = readDigitalPin(39);

  /* MATLABSystem: '<S8>/Digital Input2' */
  if (CONTROL_SYSTEM_V3_DW.obj_h.SampleTime !=
      CONTROL_SYSTEM_V3_P.DigitalInput2_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj_h.SampleTime =
      CONTROL_SYSTEM_V3_P.DigitalInput2_SampleTime;
  }

  c_value_1 = readDigitalPin(34);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Memory: '<S49>/Memory' */
    CONTROL_SYSTEM_V3_B.Memory = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput;
  }

  /* Logic: '<S8>/Logical Operator16' incorporates:
   *  Logic: '<S8>/Logical Operator38'
   *  Logic: '<S8>/Logical Operator46'
   *  MATLABSystem: '<S8>/Digital Input3'
   * */
  rowIdx_tmp = !c_value;

  /* Logic: '<S8>/Logical Operator17' incorporates:
   *  Logic: '<S8>/Logical Operator33'
   *  MATLABSystem: '<S8>/Digital Input2'
   * */
  rowIdx_tmp_0 = !c_value_1;

  /* Logic: '<S8>/Logical Operator22' incorporates:
   *  Logic: '<S8>/Logical Operator41'
   *  MATLABSystem: '<S8>/Digital Input1'
   * */
  rowIdx_tmp_2 = !c_value_0;

  /* Logic: '<S8>/Logical Operator21' incorporates:
   *  Logic: '<S8>/Logical Operator17'
   *  Logic: '<S8>/Logical Operator22'
   *  Logic: '<S8>/Logical Operator29'
   */
  rowIdx_tmp_3 = (rowIdx_tmp_2 && rowIdx_tmp_0);

  /* Logic: '<S8>/Logical Operator23' incorporates:
   *  Logic: '<S8>/Logical Operator31'
   *  MATLABSystem: '<S8>/Digital Input1'
   *  MATLABSystem: '<S8>/Digital Input2'
   * */
  rowIdx_tmp_4 = (int8_T)((int8_T)c_value_0 ^ (int8_T)c_value_1);

  /* CombinatorialLogic: '<S49>/Logic' incorporates:
   *  Logic: '<S8>/Logical Operator16'
   *  Logic: '<S8>/Logical Operator18'
   *  Logic: '<S8>/Logical Operator19'
   *  Logic: '<S8>/Logical Operator20'
   *  Logic: '<S8>/Logical Operator21'
   *  Logic: '<S8>/Logical Operator23'
   *  MATLABSystem: '<S8>/Digital Input'
   *  MATLABSystem: '<S8>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(LogicalOperator1 && (rowIdx_tmp &&
    rowIdx_tmp_3)) << 1) + (uint32_T)(int8_T)(rowIdx_tmp_4 ^ (int8_T)c_value)) <<
                      1) + CONTROL_SYSTEM_V3_B.Memory);
  CONTROL_SYSTEM_V3_B.Logic[0U] = CONTROL_SYSTEM_V3_P.Logic_table[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V3_B.Logic[1U] = CONTROL_SYSTEM_V3_P.Logic_table[(uint32_T)
    rowIdx + 8U];

  /* MATLABSystem: '<S3>/Digital Output' */
  writeDigitalPin(27, (uint8_T)CONTROL_SYSTEM_V3_B.Logic[0]);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Memory: '<S51>/Memory' */
    CONTROL_SYSTEM_V3_B.Memory_e = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_o;

    /* Memory: '<S52>/Memory' */
    CONTROL_SYSTEM_V3_B.Memory_o = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_c;
  }

  /* Logic: '<S8>/Logical Operator32' incorporates:
   *  Logic: '<S8>/Logical Operator24'
   *  Logic: '<S8>/Logical Operator40'
   *  MATLABSystem: '<S8>/Digital Input'
   * */
  rowIdx_tmp_1 = !LogicalOperator1;

  /* CombinatorialLogic: '<S51>/Logic' incorporates:
   *  Logic: '<S8>/Logical Operator32'
   *  Logic: '<S8>/Logical Operator34'
   *  Logic: '<S8>/Logical Operator35'
   *  Logic: '<S8>/Logical Operator36'
   *  Logic: '<S8>/Logical Operator37'
   *  Logic: '<S8>/Logical Operator39'
   *  MATLABSystem: '<S8>/Digital Input'
   *  MATLABSystem: '<S8>/Digital Input1'
   *  MATLABSystem: '<S8>/Digital Input2'
   *  MATLABSystem: '<S8>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_0 && (rowIdx_tmp_1 && (rowIdx_tmp &&
    rowIdx_tmp_0))) << 1) + (uint32_T)(int8_T)((int8_T)((int8_T)c_value ^
    (int8_T)c_value_1) ^ (int8_T)LogicalOperator1)) << 1) +
                     CONTROL_SYSTEM_V3_B.Memory_e);
  CONTROL_SYSTEM_V3_B.Logic_e[0U] = CONTROL_SYSTEM_V3_P.Logic_table_p[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V3_B.Logic_e[1U] = CONTROL_SYSTEM_V3_P.Logic_table_p[(uint32_T)
    rowIdx + 8U];

  /* CombinatorialLogic: '<S52>/Logic' incorporates:
   *  Logic: '<S8>/Logical Operator42'
   *  Logic: '<S8>/Logical Operator43'
   *  Logic: '<S8>/Logical Operator44'
   *  Logic: '<S8>/Logical Operator45'
   *  Logic: '<S8>/Logical Operator47'
   *  MATLABSystem: '<S8>/Digital Input'
   *  MATLABSystem: '<S8>/Digital Input1'
   *  MATLABSystem: '<S8>/Digital Input2'
   *  MATLABSystem: '<S8>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_1 && (rowIdx_tmp_1 && (rowIdx_tmp &&
    rowIdx_tmp_2))) << 1) + (uint32_T)(int8_T)((int8_T)((int8_T)c_value ^
    (int8_T)c_value_0) ^ (int8_T)LogicalOperator1)) << 1) +
                     CONTROL_SYSTEM_V3_B.Memory_o);
  CONTROL_SYSTEM_V3_B.Logic_d[0U] = CONTROL_SYSTEM_V3_P.Logic_table_b[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V3_B.Logic_d[1U] = CONTROL_SYSTEM_V3_P.Logic_table_b[(uint32_T)
    rowIdx + 8U];

  /* MATLABSystem: '<S2>/MATLAB System' */
  if (CONTROL_SYSTEM_V3_DW.obj.SampleTime !=
      CONTROL_SYSTEM_V3_P.MATLABSystem_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj.SampleTime =
      CONTROL_SYSTEM_V3_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  rtb_Sum = 0.0;
  CONTROL_SYSTEM_V3_B.b_varargout_2 = 0.0;
  CONTROL_SYSTEM_V3_B.b_varargout_3 = 0.0;
  rtb_Error = 0.0;
  stepFunctionADS1115_Vread(&rtb_Sum, 1.0, &CONTROL_SYSTEM_V3_B.b_varargout_2,
    1.0, &CONTROL_SYSTEM_V3_B.b_varargout_3, 1.0, &rtb_Error, 1.0);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* MATLAB Function: '<Root>/Foot Pedal Calibration' incorporates:
     *  MATLABSystem: '<S2>/MATLAB System'
     * */
    if (CONTROL_SYSTEM_V3_B.b_varargout_3 > CONTROL_SYSTEM_V3_DW.maxSet) {
      CONTROL_SYSTEM_V3_DW.maxSet = CONTROL_SYSTEM_V3_B.b_varargout_3;
    }

    if (CONTROL_SYSTEM_V3_B.b_varargout_3 < CONTROL_SYSTEM_V3_DW.minSet) {
      CONTROL_SYSTEM_V3_DW.minSet = CONTROL_SYSTEM_V3_B.b_varargout_3;
    }

    rtb_FP_maxVal = CONTROL_SYSTEM_V3_DW.maxSet;
    CONTROL_SYSTEM_V3_B.FP_minVal = CONTROL_SYSTEM_V3_DW.minSet;

    /* MATLAB Function: '<Root>/Throttle Body Callibration' incorporates:
     *  MATLABSystem: '<S2>/MATLAB System'
     * */
    if (CONTROL_SYSTEM_V3_B.b_varargout_2 > CONTROL_SYSTEM_V3_DW.TB_maxSet) {
      CONTROL_SYSTEM_V3_DW.TB_maxSet = CONTROL_SYSTEM_V3_B.b_varargout_2;
    }

    if (CONTROL_SYSTEM_V3_B.b_varargout_2 < CONTROL_SYSTEM_V3_DW.TB_minSet) {
      CONTROL_SYSTEM_V3_DW.TB_minSet = CONTROL_SYSTEM_V3_B.b_varargout_2;
    }

    CONTROL_SYSTEM_V3_B.TB_minVal = CONTROL_SYSTEM_V3_DW.TB_minSet;

    /* Product: '<S13>/Divide1' incorporates:
     *  MATLAB Function: '<Root>/Foot Pedal Calibration'
     *  MATLAB Function: '<Root>/Throttle Body Callibration'
     *  Sum: '<S13>/Add2'
     *  Sum: '<S13>/Add3'
     */
    CONTROL_SYSTEM_V3_B.Divide1 = (CONTROL_SYSTEM_V3_DW.maxSet -
      CONTROL_SYSTEM_V3_B.FP_minVal) / (CONTROL_SYSTEM_V3_DW.TB_maxSet -
      CONTROL_SYSTEM_V3_B.TB_minVal);
  }

  /* Sum: '<S13>/Sum' incorporates:
   *  MATLABSystem: '<S2>/MATLAB System'
   *  Product: '<S13>/Product1'
   *  Sum: '<S13>/Subtract'
   * */
  rtb_Sum = (CONTROL_SYSTEM_V3_B.b_varargout_2 - CONTROL_SYSTEM_V3_B.TB_minVal) *
    CONTROL_SYSTEM_V3_B.Divide1 + CONTROL_SYSTEM_V3_B.FP_minVal;

  /* Sum: '<Root>/Sum2' incorporates:
   *  MATLABSystem: '<S2>/MATLAB System'
   * */
  rtb_Error = CONTROL_SYSTEM_V3_B.b_varargout_3 - rtb_Sum;

  /* If: '<Root>/If Condition' */
  rtPrevAction = CONTROL_SYSTEM_V3_DW.IfCondition_ActiveSubsystem;
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
    if (CONTROL_SYSTEM_V3_B.Logic[0]) {
      rtAction = 0;
    } else if (CONTROL_SYSTEM_V3_B.Logic_e[0]) {
      rtAction = 1;
    } else if (CONTROL_SYSTEM_V3_B.Logic_d[0]) {
      rtAction = 2;
    }

    CONTROL_SYSTEM_V3_DW.IfCondition_ActiveSubsystem = rtAction;
  } else {
    rtAction = CONTROL_SYSTEM_V3_DW.IfCondition_ActiveSubsystem;
  }

  if (rtPrevAction != rtAction) {
    if (CONTROL_SYSTEM_V3_M->Timing.t[0] == rtmGetTStart(CONTROL_SYSTEM_V3_M)) {
      (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE_b), 1,
                    2*sizeof(boolean_T));
      (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE), 1,
                    3*sizeof(boolean_T));
    }

    switch (rtPrevAction) {
     case 0:
      break;

     case 1:
      (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE_b), 1,
                    2*sizeof(boolean_T));
      break;

     case 2:
      (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE), 1,
                    3*sizeof(boolean_T));
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/Propotional' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* SignalConversion generated from: '<S11>/Error' */
    CONTROL_SYSTEM_V3_B.Error = rtb_Error;

    /* End of Outputs for SubSystem: '<Root>/Propotional' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<Root>/PID Control' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Enable for If: '<Root>/If Condition' */
      (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE_b), 0,
                    2*sizeof(boolean_T));

      /* End of Enable for SubSystem: '<Root>/PID Control' */
    }

    /* Outputs for IfAction SubSystem: '<Root>/PID Control' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Sum: '<S10>/Sum1' incorporates:
       *  Constant: '<S10>/Constant'
       */
      CONTROL_SYSTEM_V3_B.Sum1 = CONTROL_SYSTEM_V3_P.Constant_Value +
        rtb_FP_maxVal;
    }

    /* Gain: '<S91>/Filter Coefficient' incorporates:
     *  Gain: '<S81>/Derivative Gain'
     *  Integrator: '<S83>/Filter'
     *  Sum: '<S83>/SumD'
     */
    CONTROL_SYSTEM_V3_B.FilterCoefficient = (CONTROL_SYSTEM_V3_P.Kd * rtb_Error
      - CONTROL_SYSTEM_V3_X.Filter_CSTATE) * CONTROL_SYSTEM_V3_P.Kn;

    /* Sum: '<S97>/Sum' incorporates:
     *  Gain: '<S93>/Proportional Gain'
     *  Integrator: '<S88>/Integrator'
     */
    CONTROL_SYSTEM_V3_B.Switch2_j = (CONTROL_SYSTEM_V3_P.Kp * rtb_Error +
      CONTROL_SYSTEM_V3_X.Integrator_CSTATE_b) +
      CONTROL_SYSTEM_V3_B.FilterCoefficient;

    /* Switch: '<S54>/Switch2' incorporates:
     *  RelationalOperator: '<S54>/LowerRelop1'
     *  RelationalOperator: '<S54>/UpperRelop'
     *  Switch: '<S54>/Switch'
     */
    if (CONTROL_SYSTEM_V3_B.Switch2_j > CONTROL_SYSTEM_V3_B.Sum1) {
      /* Sum: '<S97>/Sum' incorporates:
       *  Switch: '<S54>/Switch2'
       */
      CONTROL_SYSTEM_V3_B.Switch2_j = CONTROL_SYSTEM_V3_B.Sum1;
    } else if (CONTROL_SYSTEM_V3_B.Switch2_j < CONTROL_SYSTEM_V3_B.FP_minVal) {
      /* Sum: '<S97>/Sum' incorporates:
       *  Switch: '<S54>/Switch'
       *  Switch: '<S54>/Switch2'
       */
      CONTROL_SYSTEM_V3_B.Switch2_j = CONTROL_SYSTEM_V3_B.FP_minVal;
    }

    /* End of Switch: '<S54>/Switch2' */

    /* Gain: '<S85>/Integral Gain' */
    CONTROL_SYSTEM_V3_B.IntegralGain = CONTROL_SYSTEM_V3_P.Ki * rtb_Error;

    /* End of Outputs for SubSystem: '<Root>/PID Control' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<Root>/ADRC Control' incorporates:
       *  ActionPort: '<S1>/Action Port'
       */
      /* Enable for If: '<Root>/If Condition' */
      (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE), 0,
                    3*sizeof(boolean_T));

      /* End of Enable for SubSystem: '<Root>/ADRC Control' */
    }

    /* Outputs for IfAction SubSystem: '<Root>/ADRC Control' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Gain: '<S23>/Gain1' incorporates:
     *  Gain: '<S23>/Gain'
     *  Gain: '<S23>/Gain2'
     *  Integrator: '<S25>/Integrator'
     *  MATLABSystem: '<S2>/MATLAB System'
     *  Sum: '<S23>/Sum'
     *  Sum: '<S23>/Sum1'
     *  Sum: '<S23>/Sum2'
     * */
    CONTROL_SYSTEM_V3_B.Switch2 = (((CONTROL_SYSTEM_V3_B.b_varargout_3 -
      CONTROL_SYSTEM_V3_X.Integrator_CSTATE[0]) * CONTROL_SYSTEM_V3_P.Gain_Gain
      - CONTROL_SYSTEM_V3_P.Gain2_Gain * CONTROL_SYSTEM_V3_X.Integrator_CSTATE[1])
      - CONTROL_SYSTEM_V3_X.Integrator_CSTATE[2]) *
      CONTROL_SYSTEM_V3_P.Gain1_Gain;

    /* Sum: '<S25>/Subtract' incorporates:
     *  Constant: '<S24>/Constant2'
     *  Constant: '<S24>/Constant3'
     *  Integrator: '<S25>/Integrator'
     *  Product: '<S25>/Product2'
     *  Product: '<S25>/Product3'
     */
    rtb_Sum = (rtb_Sum - ((CONTROL_SYSTEM_V3_P.Constant2_Value[0] *
      CONTROL_SYSTEM_V3_X.Integrator_CSTATE[0] +
      CONTROL_SYSTEM_V3_P.Constant2_Value[1] *
      CONTROL_SYSTEM_V3_X.Integrator_CSTATE[1]) +
                          CONTROL_SYSTEM_V3_P.Constant2_Value[2] *
                          CONTROL_SYSTEM_V3_X.Integrator_CSTATE[2])) -
      CONTROL_SYSTEM_V3_P.Constant3_Value * CONTROL_SYSTEM_V3_B.Switch2;

    /* Integrator: '<S25>/Integrator' incorporates:
     *  Constant: '<S24>/Constant'
     *  Product: '<S25>/Product1'
     */
    rtb_Error = CONTROL_SYSTEM_V3_X.Integrator_CSTATE[1];
    Integrator_CSTATE = CONTROL_SYSTEM_V3_X.Integrator_CSTATE[0];
    Integrator_CSTATE_0 = CONTROL_SYSTEM_V3_X.Integrator_CSTATE[2];
    for (rowIdx = 0; rowIdx < 3; rowIdx++) {
      /* Sum: '<S25>/Subtract1' incorporates:
       *  Constant: '<S24>/Constant'
       *  Constant: '<S24>/Constant1'
       *  Constant: '<S24>/Constant8'
       *  Integrator: '<S25>/Integrator'
       *  Product: '<S25>/Product'
       *  Product: '<S25>/Product1'
       *  Product: '<S25>/Product5'
       */
      CONTROL_SYSTEM_V3_B.dxe[rowIdx] =
        ((CONTROL_SYSTEM_V3_P.Constant_Value_i[rowIdx + 3] * rtb_Error +
          CONTROL_SYSTEM_V3_P.Constant_Value_i[rowIdx] * Integrator_CSTATE) +
         CONTROL_SYSTEM_V3_P.Constant_Value_i[rowIdx + 6] * Integrator_CSTATE_0)
        + (CONTROL_SYSTEM_V3_P.Constant8_Value[rowIdx] * rtb_Sum +
           CONTROL_SYSTEM_V3_P.Constant1_Value[rowIdx] *
           CONTROL_SYSTEM_V3_B.Switch2);
    }

    /* Sum: '<S1>/Sum1' incorporates:
     *  Constant: '<S1>/Constant'
     *  MATLABSystem: '<S2>/MATLAB System'
     *  Product: '<S1>/Divide'
     * */
    rtb_Sum = CONTROL_SYSTEM_V3_B.b_varargout_3 /
      CONTROL_SYSTEM_V3_P.Constant_Value_ih + CONTROL_SYSTEM_V3_B.b_varargout_3;

    /* Switch: '<S16>/Switch2' incorporates:
     *  RelationalOperator: '<S16>/LowerRelop1'
     *  RelationalOperator: '<S16>/UpperRelop'
     *  Switch: '<S16>/Switch'
     */
    if (CONTROL_SYSTEM_V3_B.Switch2 > rtb_Sum) {
      /* Gain: '<S23>/Gain1' incorporates:
       *  Switch: '<S16>/Switch2'
       */
      CONTROL_SYSTEM_V3_B.Switch2 = rtb_Sum;
    } else if (CONTROL_SYSTEM_V3_B.Switch2 < CONTROL_SYSTEM_V3_B.FP_minVal) {
      /* Gain: '<S23>/Gain1' incorporates:
       *  Switch: '<S16>/Switch'
       *  Switch: '<S16>/Switch2'
       */
      CONTROL_SYSTEM_V3_B.Switch2 = CONTROL_SYSTEM_V3_B.FP_minVal;
    }

    /* End of Switch: '<S16>/Switch2' */
    /* End of Outputs for SubSystem: '<Root>/ADRC Control' */
    break;
  }

  /* End of If: '<Root>/If Condition' */

  /* MATLABSystem: '<S3>/Digital Output2' */
  writeDigitalPin(25, (uint8_T)CONTROL_SYSTEM_V3_B.Logic_d[0]);

  /* MATLABSystem: '<S3>/Digital Output1' */
  writeDigitalPin(26, (uint8_T)CONTROL_SYSTEM_V3_B.Logic_e[0]);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Memory: '<S50>/Memory' */
    CONTROL_SYSTEM_V3_B.Memory_m = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_m;
  }

  /* CombinatorialLogic: '<S50>/Logic' incorporates:
   *  Logic: '<S8>/Logical Operator26'
   *  Logic: '<S8>/Logical Operator27'
   *  Logic: '<S8>/Logical Operator28'
   *  MATLABSystem: '<S8>/Digital Input'
   *  MATLABSystem: '<S8>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value && (rowIdx_tmp_1 && rowIdx_tmp_3)) <<
                        1) + (uint32_T)(int8_T)(rowIdx_tmp_4 ^ (int8_T)
    LogicalOperator1)) << 1) + CONTROL_SYSTEM_V3_B.Memory_m);
  CONTROL_SYSTEM_V3_B.Logic_l[0U] = CONTROL_SYSTEM_V3_P.Logic_table_bm[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V3_B.Logic_l[1U] = CONTROL_SYSTEM_V3_P.Logic_table_bm[(uint32_T)
    rowIdx + 8U];

  /* Clock: '<S30>/Clock' */
  rtb_Sum = CONTROL_SYSTEM_V3_M->Timing.t[0];
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* RelationalOperator: '<S30>/Relational Operator1' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S30>/Constant2'
     */
    CONTROL_SYSTEM_V3_B.RelationalOperator1 =
      (CONTROL_SYSTEM_V3_P.OnDelay_DelayType ==
       CONTROL_SYSTEM_V3_P.Constant_Value_p);

    /* Outputs for Enabled SubSystem: '<S30>/ON Delay' incorporates:
     *  EnablePort: '<S32>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      if (CONTROL_SYSTEM_V3_B.RelationalOperator1) {
        CONTROL_SYSTEM_V3_DW.ONDelay_MODE = true;
      } else if (CONTROL_SYSTEM_V3_DW.ONDelay_MODE) {
        /* Disable for Enabled SubSystem: '<S43>/POSITIVE Edge' */
        if (CONTROL_SYSTEM_V3_DW.POSITIVEEdge_j.POSITIVEEdge_MODE) {
          CONTROL_SY_POSITIVEEdge_Disable(&CONTROL_SYSTEM_V3_DW.POSITIVEEdge_j);
        }

        /* End of Disable for SubSystem: '<S43>/POSITIVE Edge' */

        /* Disable for Enabled SubSystem: '<S43>/NEGATIVE Edge' */
        if (CONTROL_SYSTEM_V3_DW.NEGATIVEEdge_d.NEGATIVEEdge_MODE) {
          CONTROL_SY_NEGATIVEEdge_Disable(&CONTROL_SYSTEM_V3_DW.NEGATIVEEdge_d);
        }

        /* End of Disable for SubSystem: '<S43>/NEGATIVE Edge' */
        CONTROL_SYSTEM_V3_DW.ONDelay_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S30>/ON Delay' */
  }

  /* Outputs for Enabled SubSystem: '<S30>/ON Delay' incorporates:
   *  EnablePort: '<S32>/Enable'
   */
  if (CONTROL_SYSTEM_V3_DW.ONDelay_MODE) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* MultiPortSwitch: '<S43>/Multiport Switch' incorporates:
       *  Constant: '<S43>/Constant1'
       */
      switch ((int32_T)CONTROL_SYSTEM_V3_P.EdgeDetector_model_j) {
       case 1:
        /* MultiPortSwitch: '<S43>/Multiport Switch' incorporates:
         *  Constant: '<S43>/pos. edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch[0] =
          CONTROL_SYSTEM_V3_P.posedge_Value_p[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch[1] =
          CONTROL_SYSTEM_V3_P.posedge_Value_p[1];
        break;

       case 2:
        /* MultiPortSwitch: '<S43>/Multiport Switch' incorporates:
         *  Constant: '<S43>/neg. edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch[0] =
          CONTROL_SYSTEM_V3_P.negedge_Value_h[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch[1] =
          CONTROL_SYSTEM_V3_P.negedge_Value_h[1];
        break;

       default:
        /* MultiPortSwitch: '<S43>/Multiport Switch' incorporates:
         *  Constant: '<S43>/either edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch[0] =
          CONTROL_SYSTEM_V3_P.eitheredge_Value_b[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch[1] =
          CONTROL_SYSTEM_V3_P.eitheredge_Value_b[1];
        break;
      }

      /* End of MultiPortSwitch: '<S43>/Multiport Switch' */

      /* Memory: '<S43>/Memory' */
      CONTROL_SYSTEM_V3_B.Memory_j = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_p;
    }

    /* Outputs for Enabled SubSystem: '<S43>/POSITIVE Edge' */
    CONTROL_SYSTEM_V3_POSITIVEEdge(CONTROL_SYSTEM_V3_M,
      CONTROL_SYSTEM_V3_B.MultiportSwitch[0], CONTROL_SYSTEM_V3_B.Logic_l[0],
      CONTROL_SYSTEM_V3_B.Memory_j, &CONTROL_SYSTEM_V3_B.RelationalOperator1_p,
      &CONTROL_SYSTEM_V3_DW.POSITIVEEdge_j);

    /* End of Outputs for SubSystem: '<S43>/POSITIVE Edge' */

    /* Outputs for Enabled SubSystem: '<S43>/NEGATIVE Edge' */
    CONTROL_SYSTEM_V3_NEGATIVEEdge(CONTROL_SYSTEM_V3_M,
      CONTROL_SYSTEM_V3_B.MultiportSwitch[1], CONTROL_SYSTEM_V3_B.Logic_l[0],
      CONTROL_SYSTEM_V3_B.Memory_j, &CONTROL_SYSTEM_V3_B.RelationalOperator1_h,
      &CONTROL_SYSTEM_V3_DW.NEGATIVEEdge_d);

    /* End of Outputs for SubSystem: '<S43>/NEGATIVE Edge' */

    /* Logic: '<S43>/Logical Operator1' */
    LogicalOperator1 = (CONTROL_SYSTEM_V3_B.RelationalOperator1_p ||
                        CONTROL_SYSTEM_V3_B.RelationalOperator1_h);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Memory: '<S48>/IC=ic' */
      CONTROL_SYSTEM_V3_B.ICic = CONTROL_SYSTEM_V3_DW.ICic_PreviousInput;
    }

    /* Switch: '<S48>/Switch' */
    if (LogicalOperator1) {
      /* Switch: '<S48>/Switch' */
      CONTROL_SYSTEM_V3_B.Switch = rtb_Sum;
    } else {
      /* Switch: '<S48>/Switch' */
      CONTROL_SYSTEM_V3_B.Switch = CONTROL_SYSTEM_V3_B.ICic;
    }

    /* End of Switch: '<S48>/Switch' */

    /* Logic: '<S32>/Logical Operator2' incorporates:
     *  Constant: '<S30>/Constant1'
     *  RelationalOperator: '<S32>/Relational Operator'
     *  Sum: '<S32>/Sum'
     */
    CONTROL_SYSTEM_V3_B.LogicalOperator2_f = ((rtb_Sum >=
      CONTROL_SYSTEM_V3_B.Switch + CONTROL_SYSTEM_V3_P.OnDelay_delay) &&
      CONTROL_SYSTEM_V3_B.Logic_l[0]);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Outputs for Triggered SubSystem: '<S44>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S47>/Trigger'
       */
      if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
        CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE = LogicalOperator1;
      }

      /* End of Outputs for SubSystem: '<S44>/Triggered Subsystem' */
    }
  }

  /* End of Outputs for SubSystem: '<S30>/ON Delay' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Outputs for Enabled SubSystem: '<S30>/OFF Delay' incorporates:
     *  EnablePort: '<S31>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      /* Logic: '<S30>/Logical Operator2' */
      if (!CONTROL_SYSTEM_V3_B.RelationalOperator1) {
        CONTROL_SYSTEM_V3_DW.OFFDelay_MODE = true;
      } else if (CONTROL_SYSTEM_V3_DW.OFFDelay_MODE) {
        /* Disable for Enabled SubSystem: '<S35>/POSITIVE Edge' */
        if (CONTROL_SYSTEM_V3_DW.POSITIVEEdge.POSITIVEEdge_MODE) {
          CONTROL_SY_POSITIVEEdge_Disable(&CONTROL_SYSTEM_V3_DW.POSITIVEEdge);
        }

        /* End of Disable for SubSystem: '<S35>/POSITIVE Edge' */

        /* Disable for Enabled SubSystem: '<S35>/NEGATIVE Edge' */
        if (CONTROL_SYSTEM_V3_DW.NEGATIVEEdge.NEGATIVEEdge_MODE) {
          CONTROL_SY_NEGATIVEEdge_Disable(&CONTROL_SYSTEM_V3_DW.NEGATIVEEdge);
        }

        /* End of Disable for SubSystem: '<S35>/NEGATIVE Edge' */
        CONTROL_SYSTEM_V3_DW.OFFDelay_MODE = false;
      }

      /* End of Logic: '<S30>/Logical Operator2' */
    }

    /* End of Outputs for SubSystem: '<S30>/OFF Delay' */
  }

  /* Outputs for Enabled SubSystem: '<S30>/OFF Delay' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  if (CONTROL_SYSTEM_V3_DW.OFFDelay_MODE) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* MultiPortSwitch: '<S35>/Multiport Switch' incorporates:
       *  Constant: '<S35>/Constant1'
       */
      switch ((int32_T)CONTROL_SYSTEM_V3_P.EdgeDetector_model) {
       case 1:
        /* MultiPortSwitch: '<S35>/Multiport Switch' incorporates:
         *  Constant: '<S35>/pos. edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch_h[0] =
          CONTROL_SYSTEM_V3_P.posedge_Value[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch_h[1] =
          CONTROL_SYSTEM_V3_P.posedge_Value[1];
        break;

       case 2:
        /* MultiPortSwitch: '<S35>/Multiport Switch' incorporates:
         *  Constant: '<S35>/neg. edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch_h[0] =
          CONTROL_SYSTEM_V3_P.negedge_Value[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch_h[1] =
          CONTROL_SYSTEM_V3_P.negedge_Value[1];
        break;

       default:
        /* MultiPortSwitch: '<S35>/Multiport Switch' incorporates:
         *  Constant: '<S35>/either edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch_h[0] =
          CONTROL_SYSTEM_V3_P.eitheredge_Value[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch_h[1] =
          CONTROL_SYSTEM_V3_P.eitheredge_Value[1];
        break;
      }

      /* End of MultiPortSwitch: '<S35>/Multiport Switch' */

      /* Memory: '<S35>/Memory' */
      CONTROL_SYSTEM_V3_B.Memory_k = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_k;
    }

    /* Outputs for Enabled SubSystem: '<S35>/POSITIVE Edge' */
    CONTROL_SYSTEM_V3_POSITIVEEdge(CONTROL_SYSTEM_V3_M,
      CONTROL_SYSTEM_V3_B.MultiportSwitch_h[0], CONTROL_SYSTEM_V3_B.Logic_l[0],
      CONTROL_SYSTEM_V3_B.Memory_k, &CONTROL_SYSTEM_V3_B.RelationalOperator1_i,
      &CONTROL_SYSTEM_V3_DW.POSITIVEEdge);

    /* End of Outputs for SubSystem: '<S35>/POSITIVE Edge' */

    /* Outputs for Enabled SubSystem: '<S35>/NEGATIVE Edge' */
    CONTROL_SYSTEM_V3_NEGATIVEEdge(CONTROL_SYSTEM_V3_M,
      CONTROL_SYSTEM_V3_B.MultiportSwitch_h[1], CONTROL_SYSTEM_V3_B.Logic_l[0],
      CONTROL_SYSTEM_V3_B.Memory_k, &CONTROL_SYSTEM_V3_B.RelationalOperator1_d,
      &CONTROL_SYSTEM_V3_DW.NEGATIVEEdge);

    /* End of Outputs for SubSystem: '<S35>/NEGATIVE Edge' */

    /* Logic: '<S35>/Logical Operator1' */
    LogicalOperator1 = (CONTROL_SYSTEM_V3_B.RelationalOperator1_i ||
                        CONTROL_SYSTEM_V3_B.RelationalOperator1_d);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Memory: '<S40>/IC=ic' */
      CONTROL_SYSTEM_V3_B.ICic_e = CONTROL_SYSTEM_V3_DW.ICic_PreviousInput_h;
    }

    /* Switch: '<S40>/Switch' */
    if (LogicalOperator1) {
      /* Switch: '<S40>/Switch' */
      CONTROL_SYSTEM_V3_B.Switch_d = rtb_Sum;
    } else {
      /* Switch: '<S40>/Switch' */
      CONTROL_SYSTEM_V3_B.Switch_d = CONTROL_SYSTEM_V3_B.ICic_e;
    }

    /* End of Switch: '<S40>/Switch' */

    /* Logic: '<S31>/Logical Operator2' incorporates:
     *  Constant: '<S30>/Constant1'
     *  Logic: '<S31>/Logical Operator'
     *  Logic: '<S31>/Logical Operator1'
     *  RelationalOperator: '<S31>/Relational Operator'
     *  Sum: '<S31>/Sum'
     */
    CONTROL_SYSTEM_V3_B.LogicalOperator2_l = ((!(rtb_Sum >=
      CONTROL_SYSTEM_V3_B.Switch_d + CONTROL_SYSTEM_V3_P.OnDelay_delay)) ||
      CONTROL_SYSTEM_V3_B.Logic_l[0]);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Outputs for Triggered SubSystem: '<S36>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S39>/Trigger'
       */
      if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
        CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE_f =
          LogicalOperator1;
      }

      /* End of Outputs for SubSystem: '<S36>/Triggered Subsystem' */
    }
  }

  /* End of Outputs for SubSystem: '<S30>/OFF Delay' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Product: '<S5>/Divide1' incorporates:
     *  Constant: '<S5>/Desire Max Value'
     *  Constant: '<S5>/Desire Min Value'
     *  Sum: '<S5>/Add2'
     *  Sum: '<S5>/Add3'
     */
    CONTROL_SYSTEM_V3_B.Divide1_f = (CONTROL_SYSTEM_V3_P.Desire_Max -
      CONTROL_SYSTEM_V3_P.Desire_Min) / (rtb_FP_maxVal -
      CONTROL_SYSTEM_V3_B.FP_minVal);
  }

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/Constant'
   *  Logic: '<S30>/Logical Operator1'
   *  Switch: '<S7>/Switch1'
   */
  if (CONTROL_SYSTEM_V3_B.LogicalOperator2_f ||
      CONTROL_SYSTEM_V3_B.LogicalOperator2_l) {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_P.Constant_Value_e;
  } else if (CONTROL_SYSTEM_V3_B.Logic_l[0]) {
    /* Switch: '<S7>/Switch1' incorporates:
     *  Gain: '<S7>/Gain'
     */
    rtb_FP_maxVal = (real_T)(CONTROL_SYSTEM_V3_B.Logic_l[0] ? (int32_T)
      CONTROL_SYSTEM_V3_P.Gain_Gain_k : 0) * 0.5;
  } else {
    /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
     *  Gain: '<S9>/Multiply'
     *  Gain: '<S9>/Multiply1'
     *  Gain: '<S9>/Multiply2'
     *  Sum: '<S9>/Add'
     *  Switch: '<S7>/Switch1'
     */
    switch ((uint8_T)(((((uint32_T)(CONTROL_SYSTEM_V3_B.Logic_e[0] ? (int32_T)
      CONTROL_SYSTEM_V3_P.Multiply1_Gain : 0) << 1) + (uint32_T)
                        (CONTROL_SYSTEM_V3_B.Logic[0] ? (int32_T)
                         CONTROL_SYSTEM_V3_P.Multiply_Gain : 0)) + ((uint32_T)
               (CONTROL_SYSTEM_V3_B.Logic_d[0] ? (int32_T)
                CONTROL_SYSTEM_V3_P.Multiply2_Gain : 0) << 1)) >> 1) >> 6) {
     case 1:
      rtb_FP_maxVal = CONTROL_SYSTEM_V3_B.Error;
      break;

     case 2:
      rtb_FP_maxVal = CONTROL_SYSTEM_V3_B.Switch2_j;
      break;

     default:
      rtb_FP_maxVal = CONTROL_SYSTEM_V3_B.Switch2;
      break;
    }

    /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

    /* Switch: '<S7>/Switch1' incorporates:
     *  Constant: '<S5>/Desire Min Value'
     *  Product: '<S5>/Product1'
     *  Sum: '<S5>/Subtract'
     *  Sum: '<S5>/Sum'
     */
    rtb_FP_maxVal = (rtb_FP_maxVal - CONTROL_SYSTEM_V3_B.FP_minVal) *
      CONTROL_SYSTEM_V3_B.Divide1_f + CONTROL_SYSTEM_V3_P.Desire_Min;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Start for MATLABSystem: '<S7>/PWM' */
  if (!(rtb_FP_maxVal <= 255.0)) {
    rtb_FP_maxVal = 255.0;
  }

  /* MATLABSystem: '<S7>/PWM' */
  CONTROL_SYSTEM_V3_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);

  /* Start for MATLABSystem: '<S7>/PWM' */
  if (!(rtb_FP_maxVal >= 0.0)) {
    rtb_FP_maxVal = 0.0;
  }

  /* MATLABSystem: '<S7>/PWM' */
  MW_PWM_SetDutyCycle(CONTROL_SYSTEM_V3_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                      -(rtb_FP_maxVal * 255.0 / 255.0));
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* DiscretePulseGenerator: '<S3>/Pulse Generator' */
    CONTROL_SYSTEM_V3_B.PulseGenerator = (CONTROL_SYSTEM_V3_DW.clockTickCounter <
      CONTROL_SYSTEM_V3_P.PulseGenerator_Duty) &&
      (CONTROL_SYSTEM_V3_DW.clockTickCounter >= 0) ?
      CONTROL_SYSTEM_V3_P.PulseGenerator_Amp : 0.0;

    /* DiscretePulseGenerator: '<S3>/Pulse Generator' */
    if (CONTROL_SYSTEM_V3_DW.clockTickCounter >=
        CONTROL_SYSTEM_V3_P.PulseGenerator_Period - 1.0) {
      CONTROL_SYSTEM_V3_DW.clockTickCounter = 0;
    } else {
      CONTROL_SYSTEM_V3_DW.clockTickCounter++;
    }
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (CONTROL_SYSTEM_V3_B.Logic_l[0]) {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_B.PulseGenerator;
  } else {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_P.Constant_Value_d;
  }

  /* MATLABSystem: '<S3>/Digital Output3' incorporates:
   *  Switch: '<S3>/Switch'
   */
  rtb_FP_maxVal = rt_roundd_snf(rtb_FP_maxVal);
  if (rtb_FP_maxVal < 256.0) {
    if (rtb_FP_maxVal >= 0.0) {
      tmp = (uint8_T)rtb_FP_maxVal;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(33, tmp);

  /* End of MATLABSystem: '<S3>/Digital Output3' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
    CONTROL_SYSTEM_V3_B.PulseGenerator_m =
      (CONTROL_SYSTEM_V3_DW.clockTickCounter_n <
       CONTROL_SYSTEM_V3_P.PulseGenerator_Duty_e) &&
      (CONTROL_SYSTEM_V3_DW.clockTickCounter_n >= 0) ?
      CONTROL_SYSTEM_V3_P.PulseGenerator_Amp_n : 0.0;

    /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
    if (CONTROL_SYSTEM_V3_DW.clockTickCounter_n >=
        CONTROL_SYSTEM_V3_P.PulseGenerator_Period_d - 1.0) {
      CONTROL_SYSTEM_V3_DW.clockTickCounter_n = 0;
    } else {
      CONTROL_SYSTEM_V3_DW.clockTickCounter_n++;
    }
  }

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  MATLABSystem: '<S2>/MATLAB System'
   * */
  if (CONTROL_SYSTEM_V3_B.b_varargout_2 > CONTROL_SYSTEM_V3_P.Switch_Threshold)
  {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_P.Constant_Value_a;
  } else {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_P.Constant1_Value_o;
  }

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  MATLABSystem: '<S2>/MATLAB System'
   * */
  if (CONTROL_SYSTEM_V3_B.b_varargout_3 > CONTROL_SYSTEM_V3_P.Switch2_Threshold)
  {
    CONTROL_SYSTEM_V3_B.b_varargout_2 = CONTROL_SYSTEM_V3_P.Constant2_Value_j;
  } else {
    CONTROL_SYSTEM_V3_B.b_varargout_2 = CONTROL_SYSTEM_V3_P.Constant3_Value_f;
  }

  /* Switch: '<S4>/Switch3' incorporates:
   *  Constant: '<S4>/Constant4'
   *  Logic: '<S4>/OR'
   *  Switch: '<S4>/Switch'
   *  Switch: '<S4>/Switch2'
   */
  if ((!(rtb_FP_maxVal != 0.0)) || (!(CONTROL_SYSTEM_V3_B.b_varargout_2 != 0.0)))
  {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_B.PulseGenerator_m;
  } else {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_P.Constant4_Value;
  }

  /* MATLABSystem: '<S4>/Digital Output4' incorporates:
   *  Switch: '<S4>/Switch3'
   */
  rtb_FP_maxVal = rt_roundd_snf(rtb_FP_maxVal);
  if (rtb_FP_maxVal < 256.0) {
    if (rtb_FP_maxVal >= 0.0) {
      tmp = (uint8_T)rtb_FP_maxVal;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(32, tmp);

  /* End of MATLABSystem: '<S4>/Digital Output4' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* MATLABSystem: '<S7>/Digital Output' incorporates:
     *  Constant: '<S7>/Enable Pin'
     */
    rtb_FP_maxVal = rt_roundd_snf(CONTROL_SYSTEM_V3_P.EN_Pin);
    if (rtb_FP_maxVal < 256.0) {
      if (rtb_FP_maxVal >= 0.0) {
        tmp = (uint8_T)rtb_FP_maxVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(0, tmp);

    /* End of MATLABSystem: '<S7>/Digital Output' */

    /* MATLABSystem: '<S7>/Digital Output1' incorporates:
     *  Constant: '<S7>/Direction Pin'
     */
    rtb_FP_maxVal = rt_roundd_snf(CONTROL_SYSTEM_V3_P.Direction_Pin);
    if (rtb_FP_maxVal < 256.0) {
      if (rtb_FP_maxVal >= 0.0) {
        tmp = (uint8_T)rtb_FP_maxVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(16, tmp);

    /* End of MATLABSystem: '<S7>/Digital Output1' */
  }

  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Update for Memory: '<S49>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput = CONTROL_SYSTEM_V3_B.Logic[0];

      /* Update for Memory: '<S51>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_o = CONTROL_SYSTEM_V3_B.Logic_e
        [0];

      /* Update for Memory: '<S52>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_c = CONTROL_SYSTEM_V3_B.Logic_d
        [0];

      /* Update for Memory: '<S50>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_m = CONTROL_SYSTEM_V3_B.Logic_l
        [0];
    }

    /* Update for Enabled SubSystem: '<S30>/ON Delay' incorporates:
     *  EnablePort: '<S32>/Enable'
     */
    if (CONTROL_SYSTEM_V3_DW.ONDelay_MODE && rtmIsMajorTimeStep
        (CONTROL_SYSTEM_V3_M)) {
      /* Update for Memory: '<S43>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_p = CONTROL_SYSTEM_V3_B.Logic_l
        [0];

      /* Update for Memory: '<S48>/IC=ic' */
      CONTROL_SYSTEM_V3_DW.ICic_PreviousInput = CONTROL_SYSTEM_V3_B.Switch;
    }

    /* End of Update for SubSystem: '<S30>/ON Delay' */

    /* Update for Enabled SubSystem: '<S30>/OFF Delay' incorporates:
     *  EnablePort: '<S31>/Enable'
     */
    if (CONTROL_SYSTEM_V3_DW.OFFDelay_MODE && rtmIsMajorTimeStep
        (CONTROL_SYSTEM_V3_M)) {
      /* Update for Memory: '<S35>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_k = CONTROL_SYSTEM_V3_B.Logic_l
        [0];

      /* Update for Memory: '<S40>/IC=ic' */
      CONTROL_SYSTEM_V3_DW.ICic_PreviousInput_h = CONTROL_SYSTEM_V3_B.Switch_d;
    }

    /* End of Update for SubSystem: '<S30>/OFF Delay' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    rt_ertODEUpdateContinuousStates(&CONTROL_SYSTEM_V3_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++CONTROL_SYSTEM_V3_M->Timing.clockTick0;
    CONTROL_SYSTEM_V3_M->Timing.t[0] = rtsiGetSolverStopTime
      (&CONTROL_SYSTEM_V3_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      CONTROL_SYSTEM_V3_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void CONTROL_SYSTEM_V3_derivatives(void)
{
  XDot_CONTROL_SYSTEM_V3_T *_rtXdot;
  _rtXdot = ((XDot_CONTROL_SYSTEM_V3_T *) CONTROL_SYSTEM_V3_M->derivs);

  /* Derivatives for If: '<Root>/If Condition' */
  {
    real_T *dx;
    int_T i1;
    dx = &(((XDot_CONTROL_SYSTEM_V3_T *) CONTROL_SYSTEM_V3_M->derivs)
           ->Integrator_CSTATE_b);
    for (i1=0; i1 < 2; i1++) {
      dx[i1] = 0.0;
    }
  }

  {
    real_T *dx;
    int_T i1;
    dx = &(((XDot_CONTROL_SYSTEM_V3_T *) CONTROL_SYSTEM_V3_M->derivs)
           ->Integrator_CSTATE[0]);
    for (i1=0; i1 < 3; i1++) {
      dx[i1] = 0.0;
    }
  }

  switch (CONTROL_SYSTEM_V3_DW.IfCondition_ActiveSubsystem) {
   case 0:
    break;

   case 1:
    /* Derivatives for IfAction SubSystem: '<Root>/PID Control' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Derivatives for Integrator: '<S88>/Integrator' */
    _rtXdot->Integrator_CSTATE_b = CONTROL_SYSTEM_V3_B.IntegralGain;

    /* Derivatives for Integrator: '<S83>/Filter' */
    _rtXdot->Filter_CSTATE = CONTROL_SYSTEM_V3_B.FilterCoefficient;

    /* End of Derivatives for SubSystem: '<Root>/PID Control' */
    break;

   case 2:
    /* Derivatives for IfAction SubSystem: '<Root>/ADRC Control' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Derivatives for Integrator: '<S25>/Integrator' */
    _rtXdot->Integrator_CSTATE[0] = CONTROL_SYSTEM_V3_B.dxe[0];
    _rtXdot->Integrator_CSTATE[1] = CONTROL_SYSTEM_V3_B.dxe[1];
    _rtXdot->Integrator_CSTATE[2] = CONTROL_SYSTEM_V3_B.dxe[2];

    /* End of Derivatives for SubSystem: '<Root>/ADRC Control' */
    break;
  }

  /* End of Derivatives for If: '<Root>/If Condition' */
}

/* Model initialize function */
void CONTROL_SYSTEM_V3_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CONTROL_SYSTEM_V3_M->solverInfo,
                          &CONTROL_SYSTEM_V3_M->Timing.simTimeStep);
    rtsiSetTPtr(&CONTROL_SYSTEM_V3_M->solverInfo, &rtmGetTPtr
                (CONTROL_SYSTEM_V3_M));
    rtsiSetStepSizePtr(&CONTROL_SYSTEM_V3_M->solverInfo,
                       &CONTROL_SYSTEM_V3_M->Timing.stepSize0);
    rtsiSetdXPtr(&CONTROL_SYSTEM_V3_M->solverInfo, &CONTROL_SYSTEM_V3_M->derivs);
    rtsiSetContStatesPtr(&CONTROL_SYSTEM_V3_M->solverInfo, (real_T **)
                         &CONTROL_SYSTEM_V3_M->contStates);
    rtsiSetNumContStatesPtr(&CONTROL_SYSTEM_V3_M->solverInfo,
      &CONTROL_SYSTEM_V3_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&CONTROL_SYSTEM_V3_M->solverInfo,
      &CONTROL_SYSTEM_V3_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&CONTROL_SYSTEM_V3_M->solverInfo,
      &CONTROL_SYSTEM_V3_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&CONTROL_SYSTEM_V3_M->solverInfo,
      &CONTROL_SYSTEM_V3_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&CONTROL_SYSTEM_V3_M->solverInfo, (boolean_T**)
      &CONTROL_SYSTEM_V3_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&CONTROL_SYSTEM_V3_M->solverInfo, (&rtmGetErrorStatus
      (CONTROL_SYSTEM_V3_M)));
    rtsiSetRTModelPtr(&CONTROL_SYSTEM_V3_M->solverInfo, CONTROL_SYSTEM_V3_M);
  }

  rtsiSetSimTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&CONTROL_SYSTEM_V3_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&CONTROL_SYSTEM_V3_M->solverInfo, false);
  CONTROL_SYSTEM_V3_M->intgData.y = CONTROL_SYSTEM_V3_M->odeY;
  CONTROL_SYSTEM_V3_M->intgData.f[0] = CONTROL_SYSTEM_V3_M->odeF[0];
  CONTROL_SYSTEM_V3_M->intgData.f[1] = CONTROL_SYSTEM_V3_M->odeF[1];
  CONTROL_SYSTEM_V3_M->intgData.f[2] = CONTROL_SYSTEM_V3_M->odeF[2];
  CONTROL_SYSTEM_V3_M->contStates = ((X_CONTROL_SYSTEM_V3_T *)
    &CONTROL_SYSTEM_V3_X);
  CONTROL_SYSTEM_V3_M->contStateDisabled = ((XDis_CONTROL_SYSTEM_V3_T *)
    &CONTROL_SYSTEM_V3_XDis);
  CONTROL_SYSTEM_V3_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&CONTROL_SYSTEM_V3_M->solverInfo, (void *)
                    &CONTROL_SYSTEM_V3_M->intgData);
  rtsiSetSolverName(&CONTROL_SYSTEM_V3_M->solverInfo,"ode3");
  rtmSetTPtr(CONTROL_SYSTEM_V3_M, &CONTROL_SYSTEM_V3_M->Timing.tArray[0]);
  CONTROL_SYSTEM_V3_M->Timing.stepSize0 = 0.01;

  /* Start for If: '<Root>/If Condition' */
  (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE_b), 1,
                2*sizeof(boolean_T));
  (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE), 1,
                3*sizeof(boolean_T));
  CONTROL_SYSTEM_V3_DW.IfCondition_ActiveSubsystem = -1;
  CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE_f = POS_ZCSIG;
  CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for Memory: '<S49>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput =
    CONTROL_SYSTEM_V3_P.SRFlipFlop3_initial_condition;

  /* InitializeConditions for Memory: '<S51>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_o =
    CONTROL_SYSTEM_V3_P.SRFlipFlop5_initial_condition;

  /* InitializeConditions for Memory: '<S52>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_c =
    CONTROL_SYSTEM_V3_P.SRFlipFlop6_initial_condition;

  /* InitializeConditions for Memory: '<S50>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_m =
    CONTROL_SYSTEM_V3_P.SRFlipFlop4_initial_condition;

  /* SystemInitialize for MATLAB Function: '<Root>/Foot Pedal Calibration' */
  CONTROL_SYSTEM_V3_DW.maxSet = -1.0;
  CONTROL_SYSTEM_V3_DW.minSet = 5.0;

  /* SystemInitialize for MATLAB Function: '<Root>/Throttle Body Callibration' */
  CONTROL_SYSTEM_V3_DW.TB_maxSet = -1.0;
  CONTROL_SYSTEM_V3_DW.TB_minSet = 5.0;

  /* SystemInitialize for IfAction SubSystem: '<Root>/Propotional' */
  /* SystemInitialize for SignalConversion generated from: '<S11>/Error' incorporates:
   *  Outport: '<S11>/Propotional'
   */
  CONTROL_SYSTEM_V3_B.Error = CONTROL_SYSTEM_V3_P.Propotional_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Propotional' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/PID Control' */
  /* InitializeConditions for Integrator: '<S88>/Integrator' */
  CONTROL_SYSTEM_V3_X.Integrator_CSTATE_b =
    CONTROL_SYSTEM_V3_P.PIDController1_InitialConditi_g;

  /* InitializeConditions for Integrator: '<S83>/Filter' */
  CONTROL_SYSTEM_V3_X.Filter_CSTATE =
    CONTROL_SYSTEM_V3_P.PIDController1_InitialCondition;

  /* SystemInitialize for Sum: '<S97>/Sum' incorporates:
   *  Outport: '<S10>/PID Output'
   *  Switch: '<S54>/Switch2'
   */
  CONTROL_SYSTEM_V3_B.Switch2_j = CONTROL_SYSTEM_V3_P.PIDOutput_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/PID Control' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ADRC Control' */
  /* InitializeConditions for Integrator: '<S25>/Integrator' */
  CONTROL_SYSTEM_V3_X.Integrator_CSTATE[0] = CONTROL_SYSTEM_V3_P.Observer_x0;
  CONTROL_SYSTEM_V3_X.Integrator_CSTATE[1] = CONTROL_SYSTEM_V3_P.Observer_x0;
  CONTROL_SYSTEM_V3_X.Integrator_CSTATE[2] = CONTROL_SYSTEM_V3_P.Observer_x0;

  /* SystemInitialize for Gain: '<S23>/Gain1' incorporates:
   *  Outport: '<S1>/ADRC Output'
   *  Switch: '<S16>/Switch2'
   */
  CONTROL_SYSTEM_V3_B.Switch2 = CONTROL_SYSTEM_V3_P.ADRCOutput_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/ADRC Control' */

  /* SystemInitialize for Enabled SubSystem: '<S30>/ON Delay' */
  /* InitializeConditions for Memory: '<S43>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_p = CONTROL_SYSTEM_V3_P.OnDelay_ic;

  /* InitializeConditions for Memory: '<S48>/IC=ic' */
  CONTROL_SYSTEM_V3_DW.ICic_PreviousInput =
    CONTROL_SYSTEM_V3_P.SampleandHold_ic_g;

  /* SystemInitialize for Enabled SubSystem: '<S43>/POSITIVE Edge' */
  CONTROL_SYSTE_POSITIVEEdge_Init(&CONTROL_SYSTEM_V3_B.RelationalOperator1_p,
    &CONTROL_SYSTEM_V3_P.POSITIVEEdge_j);

  /* End of SystemInitialize for SubSystem: '<S43>/POSITIVE Edge' */

  /* SystemInitialize for Enabled SubSystem: '<S43>/NEGATIVE Edge' */
  CONTROL_SYSTE_NEGATIVEEdge_Init(&CONTROL_SYSTEM_V3_B.RelationalOperator1_h,
    &CONTROL_SYSTEM_V3_P.NEGATIVEEdge_d);

  /* End of SystemInitialize for SubSystem: '<S43>/NEGATIVE Edge' */

  /* SystemInitialize for Logic: '<S32>/Logical Operator2' incorporates:
   *  Outport: '<S32>/OUT'
   */
  CONTROL_SYSTEM_V3_B.LogicalOperator2_f = CONTROL_SYSTEM_V3_P.OUT_Y0_a;

  /* End of SystemInitialize for SubSystem: '<S30>/ON Delay' */

  /* SystemInitialize for Enabled SubSystem: '<S30>/OFF Delay' */
  /* InitializeConditions for Memory: '<S35>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_k = CONTROL_SYSTEM_V3_P.OnDelay_ic;

  /* InitializeConditions for Memory: '<S40>/IC=ic' */
  CONTROL_SYSTEM_V3_DW.ICic_PreviousInput_h =
    CONTROL_SYSTEM_V3_P.SampleandHold_ic;

  /* SystemInitialize for Enabled SubSystem: '<S35>/POSITIVE Edge' */
  CONTROL_SYSTE_POSITIVEEdge_Init(&CONTROL_SYSTEM_V3_B.RelationalOperator1_i,
    &CONTROL_SYSTEM_V3_P.POSITIVEEdge);

  /* End of SystemInitialize for SubSystem: '<S35>/POSITIVE Edge' */

  /* SystemInitialize for Enabled SubSystem: '<S35>/NEGATIVE Edge' */
  CONTROL_SYSTE_NEGATIVEEdge_Init(&CONTROL_SYSTEM_V3_B.RelationalOperator1_d,
    &CONTROL_SYSTEM_V3_P.NEGATIVEEdge);

  /* End of SystemInitialize for SubSystem: '<S35>/NEGATIVE Edge' */

  /* SystemInitialize for Logic: '<S31>/Logical Operator2' incorporates:
   *  Outport: '<S31>/OUT'
   */
  CONTROL_SYSTEM_V3_B.LogicalOperator2_l = CONTROL_SYSTEM_V3_P.OUT_Y0;

  /* End of SystemInitialize for SubSystem: '<S30>/OFF Delay' */

  /* Start for MATLABSystem: '<S8>/Digital Input' */
  CONTROL_SYSTEM_V3_DW.obj_c.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_c.SampleTime =
    CONTROL_SYSTEM_V3_P.DigitalInput_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj_c.isInitialized = 1;
  digitalIOSetup(36, 0);
  CONTROL_SYSTEM_V3_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Digital Input3' */
  CONTROL_SYSTEM_V3_DW.obj_f.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_f.SampleTime =
    CONTROL_SYSTEM_V3_P.DigitalInput3_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj_f.isInitialized = 1;
  digitalIOSetup(35, 0);
  CONTROL_SYSTEM_V3_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Digital Input1' */
  CONTROL_SYSTEM_V3_DW.obj_hd.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_hd.SampleTime =
    CONTROL_SYSTEM_V3_P.DigitalInput1_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj_hd.isInitialized = 1;
  digitalIOSetup(39, 0);
  CONTROL_SYSTEM_V3_DW.obj_hd.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Digital Input2' */
  CONTROL_SYSTEM_V3_DW.obj_h.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_h.SampleTime =
    CONTROL_SYSTEM_V3_P.DigitalInput2_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj_h.isInitialized = 1;
  digitalIOSetup(34, 0);
  CONTROL_SYSTEM_V3_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output' */
  CONTROL_SYSTEM_V3_DW.obj_j.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_j.isInitialized = 1;
  digitalIOSetup(27, 1);
  CONTROL_SYSTEM_V3_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/MATLAB System' */
  /*  Constructor */
  CONTROL_SYSTEM_V3_DW.obj.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj.SampleTime =
    CONTROL_SYSTEM_V3_P.MATLABSystem_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionADS1115_Vread(16, 1.0);
  CONTROL_SYSTEM_V3_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output2' */
  CONTROL_SYSTEM_V3_DW.obj_pz.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_pz.isInitialized = 1;
  digitalIOSetup(25, 1);
  CONTROL_SYSTEM_V3_DW.obj_pz.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output1' */
  CONTROL_SYSTEM_V3_DW.obj_f2.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_f2.isInitialized = 1;
  digitalIOSetup(26, 1);
  CONTROL_SYSTEM_V3_DW.obj_f2.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/PWM' */
  CONTROL_SYSTEM_V3_DW.obj_e.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_e.isInitialized = 1;
  CONTROL_SYSTEM_V3_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4U,
    19000.0, 255.0);
  CONTROL_SYSTEM_V3_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output3' */
  CONTROL_SYSTEM_V3_DW.obj_m.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_m.isInitialized = 1;
  digitalIOSetup(33, 1);
  CONTROL_SYSTEM_V3_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output4' */
  CONTROL_SYSTEM_V3_DW.obj_p.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_p.isInitialized = 1;
  digitalIOSetup(32, 1);
  CONTROL_SYSTEM_V3_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Digital Output' */
  CONTROL_SYSTEM_V3_DW.obj_b.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_b.isInitialized = 1;
  digitalIOSetup(0, 1);
  CONTROL_SYSTEM_V3_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Digital Output1' */
  CONTROL_SYSTEM_V3_DW.obj_l.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_l.isInitialized = 1;
  digitalIOSetup(16, 1);
  CONTROL_SYSTEM_V3_DW.obj_l.isSetupComplete = true;
}

/* Model terminate function */
void CONTROL_SYSTEM_V3_terminate(void)
{
  /* Terminate for MATLABSystem: '<S8>/Digital Input' */
  if (!CONTROL_SYSTEM_V3_DW.obj_c.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Input' */

  /* Terminate for MATLABSystem: '<S8>/Digital Input3' */
  if (!CONTROL_SYSTEM_V3_DW.obj_f.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Input3' */

  /* Terminate for MATLABSystem: '<S8>/Digital Input1' */
  if (!CONTROL_SYSTEM_V3_DW.obj_hd.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_hd.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Input1' */

  /* Terminate for MATLABSystem: '<S8>/Digital Input2' */
  if (!CONTROL_SYSTEM_V3_DW.obj_h.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Input2' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  if (!CONTROL_SYSTEM_V3_DW.obj_j.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output' */

  /* Terminate for MATLABSystem: '<S2>/MATLAB System' */
  if (!CONTROL_SYSTEM_V3_DW.obj.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/MATLAB System' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output2' */
  if (!CONTROL_SYSTEM_V3_DW.obj_pz.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_pz.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output1' */
  if (!CONTROL_SYSTEM_V3_DW.obj_f2.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_f2.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S7>/PWM' */
  if (!CONTROL_SYSTEM_V3_DW.obj_e.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_e.matlabCodegenIsDeleted = true;
    CONTROL_SYST_SystemCore_release(&CONTROL_SYSTEM_V3_DW.obj_e);
  }

  /* End of Terminate for MATLABSystem: '<S7>/PWM' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output3' */
  if (!CONTROL_SYSTEM_V3_DW.obj_m.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output3' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output4' */
  if (!CONTROL_SYSTEM_V3_DW.obj_p.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output4' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output' */
  if (!CONTROL_SYSTEM_V3_DW.obj_b.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output1' */
  if (!CONTROL_SYSTEM_V3_DW.obj_l.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
