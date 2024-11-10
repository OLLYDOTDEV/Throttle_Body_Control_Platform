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
#include "rtwtypes.h"
#include "CONTROL_SYSTEM_V3_types.h"
#include "CONTROL_SYSTEM_V3_private.h"
#include <math.h>
#include "zero_crossing_types.h"

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
  int_T nXc = 3;
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
 *    '<S38>/NEGATIVE Edge'
 *    '<S46>/NEGATIVE Edge'
 */
void CONTROL_SYSTE_NEGATIVEEdge_Init(boolean_T *rty_OUT,
  P_NEGATIVEEdge_CONTROL_SYSTEM_T *localP)
{
  /* SystemInitialize for Outport: '<S40>/OUT' */
  *rty_OUT = localP->OUT_Y0;
}

/*
 * Disable for enable system:
 *    '<S38>/NEGATIVE Edge'
 *    '<S46>/NEGATIVE Edge'
 */
void CONTROL_SY_NEGATIVEEdge_Disable(DW_NEGATIVEEdge_CONTROL_SYSTE_T *localDW)
{
  localDW->NEGATIVEEdge_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S38>/NEGATIVE Edge'
 *    '<S46>/NEGATIVE Edge'
 */
void CONTROL_SYSTEM_V3_NEGATIVEEdge(RT_MODEL_CONTROL_SYSTEM_V3_T * const
  CONTROL_SYSTEM_V3_M, real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, boolean_T *rty_OUT, DW_NEGATIVEEdge_CONTROL_SYSTE_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S38>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S40>/Enable'
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
    /* RelationalOperator: '<S40>/Relational Operator1' */
    *rty_OUT = ((int32_T)rtu_INprevious > (int32_T)rtu_IN);
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      srUpdateBC(localDW->NEGATIVEEdge_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S38>/NEGATIVE Edge' */
}

/*
 * System initialize for enable system:
 *    '<S38>/POSITIVE Edge'
 *    '<S46>/POSITIVE Edge'
 */
void CONTROL_SYSTE_POSITIVEEdge_Init(boolean_T *rty_OUT,
  P_POSITIVEEdge_CONTROL_SYSTEM_T *localP)
{
  /* SystemInitialize for Outport: '<S41>/OUT' */
  *rty_OUT = localP->OUT_Y0;
}

/*
 * Disable for enable system:
 *    '<S38>/POSITIVE Edge'
 *    '<S46>/POSITIVE Edge'
 */
void CONTROL_SY_POSITIVEEdge_Disable(DW_POSITIVEEdge_CONTROL_SYSTE_T *localDW)
{
  localDW->POSITIVEEdge_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S38>/POSITIVE Edge'
 *    '<S46>/POSITIVE Edge'
 */
void CONTROL_SYSTEM_V3_POSITIVEEdge(RT_MODEL_CONTROL_SYSTEM_V3_T * const
  CONTROL_SYSTEM_V3_M, real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, boolean_T *rty_OUT, DW_POSITIVEEdge_CONTROL_SYSTE_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S38>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S41>/Enable'
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
    /* RelationalOperator: '<S41>/Relational Operator1' */
    *rty_OUT = ((int32_T)rtu_INprevious < (int32_T)rtu_IN);
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      srUpdateBC(localDW->POSITIVEEdge_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S38>/POSITIVE Edge' */
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
  /* Start for MATLABSystem: '<S8>/PWM' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }

  /* End of Start for MATLABSystem: '<S8>/PWM' */
}

/* Model step function */
void CONTROL_SYSTEM_V3_step(void)
{
  real_T Integrator_CSTATE;
  real_T Integrator_CSTATE_0;
  real_T Integrator_CSTATE_1;
  real_T rtb_Sum1;
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

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V3_DW.TriggeredSubsystem_SubsysRanB_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V3_DW.NEGATIVEEdge.NEGATIVEEdge_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V3_DW.POSITIVEEdge.POSITIVEEdge_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V3_DW.OFFDelay_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V3_DW.TriggeredSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V3_DW.ONDelay_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V3_DW.Propotional1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V3_DW.PIDControl1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CONTROL_SYSTEM_V3_DW.ADRCControl1_SubsysRanBC);

  /* MATLABSystem: '<S9>/Digital Input' */
  if (CONTROL_SYSTEM_V3_DW.obj_c.SampleTime !=
      CONTROL_SYSTEM_V3_P.DigitalInput_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj_c.SampleTime =
      CONTROL_SYSTEM_V3_P.DigitalInput_SampleTime;
  }

  LogicalOperator1 = readDigitalPin(36);

  /* MATLABSystem: '<S9>/Digital Input3' */
  if (CONTROL_SYSTEM_V3_DW.obj_n.SampleTime !=
      CONTROL_SYSTEM_V3_P.DigitalInput3_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj_n.SampleTime =
      CONTROL_SYSTEM_V3_P.DigitalInput3_SampleTime;
  }

  c_value = readDigitalPin(35);

  /* MATLABSystem: '<S9>/Digital Input1' */
  if (CONTROL_SYSTEM_V3_DW.obj_m.SampleTime !=
      CONTROL_SYSTEM_V3_P.DigitalInput1_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj_m.SampleTime =
      CONTROL_SYSTEM_V3_P.DigitalInput1_SampleTime;
  }

  c_value_0 = readDigitalPin(39);

  /* MATLABSystem: '<S9>/Digital Input2' */
  if (CONTROL_SYSTEM_V3_DW.obj_l.SampleTime !=
      CONTROL_SYSTEM_V3_P.DigitalInput2_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj_l.SampleTime =
      CONTROL_SYSTEM_V3_P.DigitalInput2_SampleTime;
  }

  c_value_1 = readDigitalPin(34);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Memory: '<S52>/Memory' */
    CONTROL_SYSTEM_V3_B.Memory = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput;
  }

  /* Logic: '<S9>/Logical Operator16' incorporates:
   *  Logic: '<S9>/Logical Operator38'
   *  Logic: '<S9>/Logical Operator46'
   *  MATLABSystem: '<S9>/Digital Input3'
   * */
  rowIdx_tmp = !c_value;

  /* Logic: '<S9>/Logical Operator17' incorporates:
   *  Logic: '<S9>/Logical Operator33'
   *  MATLABSystem: '<S9>/Digital Input2'
   * */
  rowIdx_tmp_0 = !c_value_1;

  /* Logic: '<S9>/Logical Operator22' incorporates:
   *  Logic: '<S9>/Logical Operator41'
   *  MATLABSystem: '<S9>/Digital Input1'
   * */
  rowIdx_tmp_2 = !c_value_0;

  /* Logic: '<S9>/Logical Operator21' incorporates:
   *  Logic: '<S9>/Logical Operator17'
   *  Logic: '<S9>/Logical Operator22'
   *  Logic: '<S9>/Logical Operator29'
   */
  rowIdx_tmp_3 = (rowIdx_tmp_2 && rowIdx_tmp_0);

  /* Logic: '<S9>/Logical Operator23' incorporates:
   *  Logic: '<S9>/Logical Operator31'
   *  MATLABSystem: '<S9>/Digital Input1'
   *  MATLABSystem: '<S9>/Digital Input2'
   * */
  rowIdx_tmp_4 = (int8_T)((int8_T)c_value_0 ^ (int8_T)c_value_1);

  /* CombinatorialLogic: '<S52>/Logic' incorporates:
   *  Logic: '<S9>/Logical Operator16'
   *  Logic: '<S9>/Logical Operator18'
   *  Logic: '<S9>/Logical Operator19'
   *  Logic: '<S9>/Logical Operator20'
   *  Logic: '<S9>/Logical Operator21'
   *  Logic: '<S9>/Logical Operator23'
   *  MATLABSystem: '<S9>/Digital Input'
   *  MATLABSystem: '<S9>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(LogicalOperator1 && (rowIdx_tmp &&
    rowIdx_tmp_3)) << 1) + (uint32_T)(int8_T)(rowIdx_tmp_4 ^ (int8_T)c_value)) <<
                      1) + CONTROL_SYSTEM_V3_B.Memory);
  CONTROL_SYSTEM_V3_B.Logic[0U] = CONTROL_SYSTEM_V3_P.Logic_table[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V3_B.Logic[1U] = CONTROL_SYSTEM_V3_P.Logic_table[(uint32_T)
    rowIdx + 8U];

  /* MATLABSystem: '<S4>/Digital Output' */
  writeDigitalPin(27, (uint8_T)CONTROL_SYSTEM_V3_B.Logic[0]);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Memory: '<S54>/Memory' */
    CONTROL_SYSTEM_V3_B.Memory_h = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_b;

    /* Memory: '<S55>/Memory' */
    CONTROL_SYSTEM_V3_B.Memory_k = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_h;
  }

  /* Logic: '<S9>/Logical Operator32' incorporates:
   *  Logic: '<S9>/Logical Operator24'
   *  Logic: '<S9>/Logical Operator40'
   *  MATLABSystem: '<S9>/Digital Input'
   * */
  rowIdx_tmp_1 = !LogicalOperator1;

  /* CombinatorialLogic: '<S54>/Logic' incorporates:
   *  Logic: '<S9>/Logical Operator32'
   *  Logic: '<S9>/Logical Operator34'
   *  Logic: '<S9>/Logical Operator35'
   *  Logic: '<S9>/Logical Operator36'
   *  Logic: '<S9>/Logical Operator37'
   *  Logic: '<S9>/Logical Operator39'
   *  MATLABSystem: '<S9>/Digital Input'
   *  MATLABSystem: '<S9>/Digital Input1'
   *  MATLABSystem: '<S9>/Digital Input2'
   *  MATLABSystem: '<S9>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_0 && (rowIdx_tmp_1 && (rowIdx_tmp &&
    rowIdx_tmp_0))) << 1) + (uint32_T)(int8_T)((int8_T)((int8_T)c_value ^
    (int8_T)c_value_1) ^ (int8_T)LogicalOperator1)) << 1) +
                     CONTROL_SYSTEM_V3_B.Memory_h);
  CONTROL_SYSTEM_V3_B.Logic_e[0U] = CONTROL_SYSTEM_V3_P.Logic_table_i[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V3_B.Logic_e[1U] = CONTROL_SYSTEM_V3_P.Logic_table_i[(uint32_T)
    rowIdx + 8U];

  /* CombinatorialLogic: '<S55>/Logic' incorporates:
   *  Logic: '<S9>/Logical Operator42'
   *  Logic: '<S9>/Logical Operator43'
   *  Logic: '<S9>/Logical Operator44'
   *  Logic: '<S9>/Logical Operator45'
   *  Logic: '<S9>/Logical Operator47'
   *  MATLABSystem: '<S9>/Digital Input'
   *  MATLABSystem: '<S9>/Digital Input1'
   *  MATLABSystem: '<S9>/Digital Input2'
   *  MATLABSystem: '<S9>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_1 && (rowIdx_tmp_1 && (rowIdx_tmp &&
    rowIdx_tmp_2))) << 1) + (uint32_T)(int8_T)((int8_T)((int8_T)c_value ^
    (int8_T)c_value_0) ^ (int8_T)LogicalOperator1)) << 1) +
                     CONTROL_SYSTEM_V3_B.Memory_k);
  CONTROL_SYSTEM_V3_B.Logic_f[0U] = CONTROL_SYSTEM_V3_P.Logic_table_j[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V3_B.Logic_f[1U] = CONTROL_SYSTEM_V3_P.Logic_table_j[(uint32_T)
    rowIdx + 8U];

  /* MATLABSystem: '<S3>/MATLAB System' */
  if (CONTROL_SYSTEM_V3_DW.obj.SampleTime !=
      CONTROL_SYSTEM_V3_P.MATLABSystem_SampleTime) {
    CONTROL_SYSTEM_V3_DW.obj.SampleTime =
      CONTROL_SYSTEM_V3_P.MATLABSystem_SampleTime;
  }

  /* MATLABSystem: '<S3>/MATLAB System' */
  /*         %% Define output properties */
  CONTROL_SYSTEM_V3_B.MATLABSystem_o1 = 0.0;

  /* MATLABSystem: '<S3>/MATLAB System' */
  CONTROL_SYSTEM_V3_B.MATLABSystem_o2 = 0.0;

  /* MATLABSystem: '<S3>/MATLAB System' */
  CONTROL_SYSTEM_V3_B.MATLABSystem_o3 = 0.0;

  /* MATLABSystem: '<S3>/MATLAB System' */
  CONTROL_SYSTEM_V3_B.MATLABSystem_o4 = 0.0;
  stepFunctionADS1115_Vread(&CONTROL_SYSTEM_V3_B.MATLABSystem_o1, 1.0,
    &CONTROL_SYSTEM_V3_B.MATLABSystem_o2, 1.0,
    &CONTROL_SYSTEM_V3_B.MATLABSystem_o3, 1.0,
    &CONTROL_SYSTEM_V3_B.MATLABSystem_o4, 1.0);

  /* FromWorkspace: '<S13>/fromWS_Signal 1' */
  {
    real_T t = CONTROL_SYSTEM_V3_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      CONTROL_SYSTEM_V3_DW.fromWS_Signal1_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      CONTROL_SYSTEM_V3_DW.fromWS_Signal1_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      CONTROL_SYSTEM_V3_B.Signal1 = 0.0;
    } else if (t == pTimeValues[10]) {
      CONTROL_SYSTEM_V3_B.Signal1 = pDataValues[10];
    } else if (t > pTimeValues[10]) {
      CONTROL_SYSTEM_V3_B.Signal1 = 0.0;
    } else {
      int_T currTimeIndex = CONTROL_SYSTEM_V3_DW.fromWS_Signal1_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      CONTROL_SYSTEM_V3_B.Signal1 = pDataValues[currTimeIndex];
      CONTROL_SYSTEM_V3_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* Switch: '<S1>/Switch3' */
  if (CONTROL_SYSTEM_V3_B.MATLABSystem_o3 >
      CONTROL_SYSTEM_V3_P.Switch3_Threshold) {
    /* Switch: '<S1>/Switch3' incorporates:
     *  Constant: '<S1>/Constant3'
     */
    CONTROL_SYSTEM_V3_B.FootPedalSignal = CONTROL_SYSTEM_V3_P.Constant3_Value_b;
  } else {
    /* Switch: '<S1>/Switch3' */
    CONTROL_SYSTEM_V3_B.FootPedalSignal = CONTROL_SYSTEM_V3_B.Signal1;
  }

  /* End of Switch: '<S1>/Switch3' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* MATLAB Function: '<S1>/Foot Pedal Calibration1' */
    if (CONTROL_SYSTEM_V3_B.FootPedalSignal > CONTROL_SYSTEM_V3_DW.maxSet) {
      CONTROL_SYSTEM_V3_DW.maxSet = CONTROL_SYSTEM_V3_B.FootPedalSignal;
    }

    if (CONTROL_SYSTEM_V3_B.FootPedalSignal < CONTROL_SYSTEM_V3_DW.minSet) {
      CONTROL_SYSTEM_V3_DW.minSet = CONTROL_SYSTEM_V3_B.FootPedalSignal;
    }

    CONTROL_SYSTEM_V3_B.FP_maxVal = CONTROL_SYSTEM_V3_DW.maxSet;
    CONTROL_SYSTEM_V3_B.FP_minVal = CONTROL_SYSTEM_V3_DW.minSet;

    /* End of MATLAB Function: '<S1>/Foot Pedal Calibration1' */

    /* Sum: '<S16>/Add2' */
    CONTROL_SYSTEM_V3_B.Add2 = CONTROL_SYSTEM_V3_B.FP_maxVal -
      CONTROL_SYSTEM_V3_B.FP_minVal;

    /* MATLAB Function: '<S1>/Throttle Body Callibration1' */
    if (CONTROL_SYSTEM_V3_B.MATLABSystem_o2 > CONTROL_SYSTEM_V3_DW.TB_maxSet) {
      CONTROL_SYSTEM_V3_DW.TB_maxSet = CONTROL_SYSTEM_V3_B.MATLABSystem_o2;
    }

    if (CONTROL_SYSTEM_V3_B.MATLABSystem_o2 < CONTROL_SYSTEM_V3_DW.TB_minSet) {
      CONTROL_SYSTEM_V3_DW.TB_minSet = CONTROL_SYSTEM_V3_B.MATLABSystem_o2;
    }

    CONTROL_SYSTEM_V3_B.TB_maxVal = CONTROL_SYSTEM_V3_DW.TB_maxSet;
    CONTROL_SYSTEM_V3_B.TB_minVal = CONTROL_SYSTEM_V3_DW.TB_minSet;

    /* End of MATLAB Function: '<S1>/Throttle Body Callibration1' */

    /* Sum: '<S16>/Add3' */
    CONTROL_SYSTEM_V3_B.Add3 = CONTROL_SYSTEM_V3_B.TB_maxVal -
      CONTROL_SYSTEM_V3_B.TB_minVal;

    /* Product: '<S16>/Divide1' */
    CONTROL_SYSTEM_V3_B.Divide1 = CONTROL_SYSTEM_V3_B.Add2 /
      CONTROL_SYSTEM_V3_B.Add3;
  }

  /* Sum: '<S16>/Sum' incorporates:
   *  Product: '<S16>/Product1'
   *  Sum: '<S16>/Subtract'
   */
  CONTROL_SYSTEM_V3_B.Sum = (CONTROL_SYSTEM_V3_B.MATLABSystem_o2 -
    CONTROL_SYSTEM_V3_B.TB_minVal) * CONTROL_SYSTEM_V3_B.Divide1 +
    CONTROL_SYSTEM_V3_B.FP_minVal;

  /* Sum: '<S1>/Sum1' */
  CONTROL_SYSTEM_V3_B.Error = CONTROL_SYSTEM_V3_B.FootPedalSignal -
    CONTROL_SYSTEM_V3_B.Sum;

  /* If: '<S1>/If Condition1' */
  rtPrevAction = CONTROL_SYSTEM_V3_DW.IfCondition1_ActiveSubsystem;
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
    if (CONTROL_SYSTEM_V3_B.Logic[0]) {
      rtAction = 0;
    } else if (CONTROL_SYSTEM_V3_B.Logic_e[0]) {
      rtAction = 1;
    } else if (CONTROL_SYSTEM_V3_B.Logic_f[0]) {
      rtAction = 2;
    }

    CONTROL_SYSTEM_V3_DW.IfCondition1_ActiveSubsystem = rtAction;
  } else {
    rtAction = CONTROL_SYSTEM_V3_DW.IfCondition1_ActiveSubsystem;
  }

  if (rtPrevAction != rtAction) {
    if (CONTROL_SYSTEM_V3_M->Timing.t[0] == rtmGetTStart(CONTROL_SYSTEM_V3_M)) {
      (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE), 1,
                    3*sizeof(boolean_T));
    }

    if (rtPrevAction == 2) {
      (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE), 1,
                    3*sizeof(boolean_T));
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Propotional1' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/Error' */
    CONTROL_SYSTEM_V3_B.Error_j = CONTROL_SYSTEM_V3_B.Error;
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      srUpdateBC(CONTROL_SYSTEM_V3_DW.Propotional1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S1>/Propotional1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/PID Control1' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* DiscreteIntegrator: '<S91>/Integrator' */
      CONTROL_SYSTEM_V3_B.Integrator = CONTROL_SYSTEM_V3_DW.Integrator_DSTATE;

      /* DiscreteIntegrator: '<S86>/Filter' */
      CONTROL_SYSTEM_V3_B.Filter = CONTROL_SYSTEM_V3_DW.Filter_DSTATE;
    }

    /* Gain: '<S94>/Filter Coefficient' incorporates:
     *  Gain: '<S84>/Derivative Gain'
     *  Sum: '<S86>/SumD'
     */
    CONTROL_SYSTEM_V3_B.FilterCoefficient = (CONTROL_SYSTEM_V3_P.Kd *
      CONTROL_SYSTEM_V3_B.Error - CONTROL_SYSTEM_V3_B.Filter) *
      CONTROL_SYSTEM_V3_P.Kn;

    /* Sum: '<S100>/Sum' incorporates:
     *  Gain: '<S96>/Proportional Gain'
     */
    CONTROL_SYSTEM_V3_B.Sum_m = (CONTROL_SYSTEM_V3_P.Kp *
      CONTROL_SYSTEM_V3_B.Error + CONTROL_SYSTEM_V3_B.Integrator) +
      CONTROL_SYSTEM_V3_B.FilterCoefficient;
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Sum: '<S11>/Sum1' incorporates:
       *  Constant: '<S11>/Constant'
       */
      CONTROL_SYSTEM_V3_B.Sum1 = CONTROL_SYSTEM_V3_P.Constant_Value +
        CONTROL_SYSTEM_V3_B.FP_maxVal;
    }

    /* Switch: '<S57>/Switch2' incorporates:
     *  RelationalOperator: '<S57>/LowerRelop1'
     *  RelationalOperator: '<S57>/UpperRelop'
     *  Switch: '<S57>/Switch'
     */
    if (CONTROL_SYSTEM_V3_B.Sum_m > CONTROL_SYSTEM_V3_B.Sum1) {
      /* Switch: '<S57>/Switch2' */
      CONTROL_SYSTEM_V3_B.Switch2_e = CONTROL_SYSTEM_V3_B.Sum1;
    } else if (CONTROL_SYSTEM_V3_B.Sum_m < CONTROL_SYSTEM_V3_B.FP_minVal) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Switch: '<S57>/Switch2'
       */
      CONTROL_SYSTEM_V3_B.Switch2_e = CONTROL_SYSTEM_V3_B.FP_minVal;
    } else {
      /* Switch: '<S57>/Switch2' incorporates:
       *  Switch: '<S57>/Switch'
       */
      CONTROL_SYSTEM_V3_B.Switch2_e = CONTROL_SYSTEM_V3_B.Sum_m;
    }

    /* End of Switch: '<S57>/Switch2' */

    /* Gain: '<S88>/Integral Gain' */
    CONTROL_SYSTEM_V3_B.IntegralGain = CONTROL_SYSTEM_V3_P.Ki *
      CONTROL_SYSTEM_V3_B.Error;
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      srUpdateBC(CONTROL_SYSTEM_V3_DW.PIDControl1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S1>/PID Control1' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S1>/ADRC Control1' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* Enable for If: '<S1>/If Condition1' */
      (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE), 0,
                    3*sizeof(boolean_T));

      /* End of Enable for SubSystem: '<S1>/ADRC Control1' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/ADRC Control1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Gain: '<S26>/Gain1' incorporates:
     *  Gain: '<S26>/Gain'
     *  Gain: '<S26>/Gain2'
     *  Integrator: '<S28>/Integrator'
     *  Sum: '<S26>/Sum'
     *  Sum: '<S26>/Sum1'
     *  Sum: '<S26>/Sum2'
     */
    CONTROL_SYSTEM_V3_B.Switch2 = (((0.0 -
      CONTROL_SYSTEM_V3_X.Integrator_CSTATE[0]) * CONTROL_SYSTEM_V3_P.Gain_Gain
      - CONTROL_SYSTEM_V3_P.Gain2_Gain * CONTROL_SYSTEM_V3_X.Integrator_CSTATE[1])
      - CONTROL_SYSTEM_V3_X.Integrator_CSTATE[2]) *
      CONTROL_SYSTEM_V3_P.Gain1_Gain;

    /* Sum: '<S28>/Subtract' incorporates:
     *  Constant: '<S27>/Constant2'
     *  Constant: '<S27>/Constant3'
     *  Integrator: '<S28>/Integrator'
     *  Product: '<S28>/Product2'
     *  Product: '<S28>/Product3'
     */
    rtb_Sum1 = (CONTROL_SYSTEM_V3_B.Sum - ((CONTROL_SYSTEM_V3_P.Constant2_Value
      [0] * CONTROL_SYSTEM_V3_X.Integrator_CSTATE[0] +
      CONTROL_SYSTEM_V3_P.Constant2_Value[1] *
      CONTROL_SYSTEM_V3_X.Integrator_CSTATE[1]) +
      CONTROL_SYSTEM_V3_P.Constant2_Value[2] *
      CONTROL_SYSTEM_V3_X.Integrator_CSTATE[2])) -
      CONTROL_SYSTEM_V3_P.Constant3_Value * CONTROL_SYSTEM_V3_B.Switch2;

    /* Integrator: '<S28>/Integrator' incorporates:
     *  Constant: '<S27>/Constant'
     *  Product: '<S28>/Product1'
     */
    Integrator_CSTATE = CONTROL_SYSTEM_V3_X.Integrator_CSTATE[1];
    Integrator_CSTATE_0 = CONTROL_SYSTEM_V3_X.Integrator_CSTATE[0];
    Integrator_CSTATE_1 = CONTROL_SYSTEM_V3_X.Integrator_CSTATE[2];
    for (rowIdx = 0; rowIdx < 3; rowIdx++) {
      /* Sum: '<S28>/Subtract1' incorporates:
       *  Constant: '<S27>/Constant'
       *  Constant: '<S27>/Constant1'
       *  Constant: '<S27>/Constant8'
       *  Integrator: '<S28>/Integrator'
       *  Product: '<S28>/Product'
       *  Product: '<S28>/Product1'
       *  Product: '<S28>/Product5'
       */
      CONTROL_SYSTEM_V3_B.dxe[rowIdx] =
        ((CONTROL_SYSTEM_V3_P.Constant_Value_k[rowIdx + 3] * Integrator_CSTATE +
          CONTROL_SYSTEM_V3_P.Constant_Value_k[rowIdx] * Integrator_CSTATE_0) +
         CONTROL_SYSTEM_V3_P.Constant_Value_k[rowIdx + 6] * Integrator_CSTATE_1)
        + (CONTROL_SYSTEM_V3_P.Constant8_Value[rowIdx] * rtb_Sum1 +
           CONTROL_SYSTEM_V3_P.Constant1_Value[rowIdx] *
           CONTROL_SYSTEM_V3_B.Switch2);
    }

    /* Sum: '<S2>/Sum1' incorporates:
     *  Constant: '<S2>/Constant'
     *  Product: '<S2>/Divide'
     */
    rtb_Sum1 = 0.0 / CONTROL_SYSTEM_V3_P.Constant_Value_g;

    /* Switch: '<S19>/Switch2' incorporates:
     *  RelationalOperator: '<S19>/LowerRelop1'
     *  RelationalOperator: '<S19>/UpperRelop'
     *  Switch: '<S19>/Switch'
     */
    if (CONTROL_SYSTEM_V3_B.Switch2 > rtb_Sum1) {
      /* Gain: '<S26>/Gain1' incorporates:
       *  Switch: '<S19>/Switch2'
       */
      CONTROL_SYSTEM_V3_B.Switch2 = rtb_Sum1;
    } else if (CONTROL_SYSTEM_V3_B.Switch2 < CONTROL_SYSTEM_V3_B.FP_minVal) {
      /* Gain: '<S26>/Gain1' incorporates:
       *  Switch: '<S19>/Switch'
       *  Switch: '<S19>/Switch2'
       */
      CONTROL_SYSTEM_V3_B.Switch2 = CONTROL_SYSTEM_V3_B.FP_minVal;
    }

    /* End of Switch: '<S19>/Switch2' */
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      srUpdateBC(CONTROL_SYSTEM_V3_DW.ADRCControl1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S1>/ADRC Control1' */
    break;
  }

  /* End of If: '<S1>/If Condition1' */

  /* MATLABSystem: '<S4>/Digital Output2' */
  writeDigitalPin(25, (uint8_T)CONTROL_SYSTEM_V3_B.Logic_f[0]);

  /* MATLABSystem: '<S4>/Digital Output1' */
  writeDigitalPin(26, (uint8_T)CONTROL_SYSTEM_V3_B.Logic_e[0]);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Memory: '<S53>/Memory' */
    CONTROL_SYSTEM_V3_B.Memory_n = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_d;
  }

  /* CombinatorialLogic: '<S53>/Logic' incorporates:
   *  Logic: '<S9>/Logical Operator26'
   *  Logic: '<S9>/Logical Operator27'
   *  Logic: '<S9>/Logical Operator28'
   *  MATLABSystem: '<S9>/Digital Input'
   *  MATLABSystem: '<S9>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value && (rowIdx_tmp_1 && rowIdx_tmp_3)) <<
                        1) + (uint32_T)(int8_T)(rowIdx_tmp_4 ^ (int8_T)
    LogicalOperator1)) << 1) + CONTROL_SYSTEM_V3_B.Memory_n);
  CONTROL_SYSTEM_V3_B.Logic_d[0U] = CONTROL_SYSTEM_V3_P.Logic_table_d[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V3_B.Logic_d[1U] = CONTROL_SYSTEM_V3_P.Logic_table_d[(uint32_T)
    rowIdx + 8U];

  /* Clock: '<S33>/Clock' */
  rtb_Sum1 = CONTROL_SYSTEM_V3_M->Timing.t[0];
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* RelationalOperator: '<S33>/Relational Operator1' incorporates:
     *  Constant: '<S33>/Constant'
     *  Constant: '<S33>/Constant2'
     */
    CONTROL_SYSTEM_V3_B.RelationalOperator1 =
      (CONTROL_SYSTEM_V3_P.OnDelay_DelayType ==
       CONTROL_SYSTEM_V3_P.Constant_Value_b);

    /* Outputs for Enabled SubSystem: '<S33>/ON Delay' incorporates:
     *  EnablePort: '<S35>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      if (CONTROL_SYSTEM_V3_B.RelationalOperator1) {
        CONTROL_SYSTEM_V3_DW.ONDelay_MODE = true;
      } else if (CONTROL_SYSTEM_V3_DW.ONDelay_MODE) {
        /* Disable for Enabled SubSystem: '<S46>/POSITIVE Edge' */
        if (CONTROL_SYSTEM_V3_DW.POSITIVEEdge_b.POSITIVEEdge_MODE) {
          CONTROL_SY_POSITIVEEdge_Disable(&CONTROL_SYSTEM_V3_DW.POSITIVEEdge_b);
        }

        /* End of Disable for SubSystem: '<S46>/POSITIVE Edge' */

        /* Disable for Enabled SubSystem: '<S46>/NEGATIVE Edge' */
        if (CONTROL_SYSTEM_V3_DW.NEGATIVEEdge_m.NEGATIVEEdge_MODE) {
          CONTROL_SY_NEGATIVEEdge_Disable(&CONTROL_SYSTEM_V3_DW.NEGATIVEEdge_m);
        }

        /* End of Disable for SubSystem: '<S46>/NEGATIVE Edge' */
        CONTROL_SYSTEM_V3_DW.ONDelay_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S33>/ON Delay' */
  }

  /* Outputs for Enabled SubSystem: '<S33>/ON Delay' incorporates:
   *  EnablePort: '<S35>/Enable'
   */
  if (CONTROL_SYSTEM_V3_DW.ONDelay_MODE) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
       *  Constant: '<S46>/Constant1'
       */
      switch ((int32_T)CONTROL_SYSTEM_V3_P.EdgeDetector_model_a) {
       case 1:
        /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
         *  Constant: '<S46>/pos. edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch[0] =
          CONTROL_SYSTEM_V3_P.posedge_Value_j[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch[1] =
          CONTROL_SYSTEM_V3_P.posedge_Value_j[1];
        break;

       case 2:
        /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
         *  Constant: '<S46>/neg. edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch[0] =
          CONTROL_SYSTEM_V3_P.negedge_Value_i[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch[1] =
          CONTROL_SYSTEM_V3_P.negedge_Value_i[1];
        break;

       default:
        /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
         *  Constant: '<S46>/either edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch[0] =
          CONTROL_SYSTEM_V3_P.eitheredge_Value_c[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch[1] =
          CONTROL_SYSTEM_V3_P.eitheredge_Value_c[1];
        break;
      }

      /* End of MultiPortSwitch: '<S46>/Multiport Switch' */

      /* Memory: '<S46>/Memory' */
      CONTROL_SYSTEM_V3_B.Memory_i = CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_n;
    }

    /* Outputs for Enabled SubSystem: '<S46>/POSITIVE Edge' */
    CONTROL_SYSTEM_V3_POSITIVEEdge(CONTROL_SYSTEM_V3_M,
      CONTROL_SYSTEM_V3_B.MultiportSwitch[0], CONTROL_SYSTEM_V3_B.Logic_d[0],
      CONTROL_SYSTEM_V3_B.Memory_i, &CONTROL_SYSTEM_V3_B.RelationalOperator1_i,
      &CONTROL_SYSTEM_V3_DW.POSITIVEEdge_b);

    /* End of Outputs for SubSystem: '<S46>/POSITIVE Edge' */

    /* Outputs for Enabled SubSystem: '<S46>/NEGATIVE Edge' */
    CONTROL_SYSTEM_V3_NEGATIVEEdge(CONTROL_SYSTEM_V3_M,
      CONTROL_SYSTEM_V3_B.MultiportSwitch[1], CONTROL_SYSTEM_V3_B.Logic_d[0],
      CONTROL_SYSTEM_V3_B.Memory_i, &CONTROL_SYSTEM_V3_B.RelationalOperator1_g,
      &CONTROL_SYSTEM_V3_DW.NEGATIVEEdge_m);

    /* End of Outputs for SubSystem: '<S46>/NEGATIVE Edge' */

    /* Logic: '<S46>/Logical Operator1' */
    LogicalOperator1 = (CONTROL_SYSTEM_V3_B.RelationalOperator1_i ||
                        CONTROL_SYSTEM_V3_B.RelationalOperator1_g);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Memory: '<S51>/IC=ic' */
      CONTROL_SYSTEM_V3_B.ICic = CONTROL_SYSTEM_V3_DW.ICic_PreviousInput;
    }

    /* Switch: '<S51>/Switch' */
    if (LogicalOperator1) {
      /* Switch: '<S51>/Switch' */
      CONTROL_SYSTEM_V3_B.Switch = rtb_Sum1;
    } else {
      /* Switch: '<S51>/Switch' */
      CONTROL_SYSTEM_V3_B.Switch = CONTROL_SYSTEM_V3_B.ICic;
    }

    /* End of Switch: '<S51>/Switch' */

    /* Logic: '<S35>/Logical Operator2' incorporates:
     *  Constant: '<S33>/Constant1'
     *  RelationalOperator: '<S35>/Relational Operator'
     *  Sum: '<S35>/Sum'
     */
    CONTROL_SYSTEM_V3_B.LogicalOperator2_g = ((rtb_Sum1 >=
      CONTROL_SYSTEM_V3_B.Switch + CONTROL_SYSTEM_V3_P.OnDelay_delay) &&
      CONTROL_SYSTEM_V3_B.Logic_d[0]);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Outputs for Triggered SubSystem: '<S47>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S50>/Trigger'
       */
      if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
        if (LogicalOperator1 &&
            (CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE != POS_ZCSIG))
        {
          CONTROL_SYSTEM_V3_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE = LogicalOperator1;
      }

      /* End of Outputs for SubSystem: '<S47>/Triggered Subsystem' */
    }

    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      srUpdateBC(CONTROL_SYSTEM_V3_DW.ONDelay_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S33>/ON Delay' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Outputs for Enabled SubSystem: '<S33>/OFF Delay' incorporates:
     *  EnablePort: '<S34>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      /* Logic: '<S33>/Logical Operator2' */
      if (!CONTROL_SYSTEM_V3_B.RelationalOperator1) {
        CONTROL_SYSTEM_V3_DW.OFFDelay_MODE = true;
      } else if (CONTROL_SYSTEM_V3_DW.OFFDelay_MODE) {
        /* Disable for Enabled SubSystem: '<S38>/POSITIVE Edge' */
        if (CONTROL_SYSTEM_V3_DW.POSITIVEEdge.POSITIVEEdge_MODE) {
          CONTROL_SY_POSITIVEEdge_Disable(&CONTROL_SYSTEM_V3_DW.POSITIVEEdge);
        }

        /* End of Disable for SubSystem: '<S38>/POSITIVE Edge' */

        /* Disable for Enabled SubSystem: '<S38>/NEGATIVE Edge' */
        if (CONTROL_SYSTEM_V3_DW.NEGATIVEEdge.NEGATIVEEdge_MODE) {
          CONTROL_SY_NEGATIVEEdge_Disable(&CONTROL_SYSTEM_V3_DW.NEGATIVEEdge);
        }

        /* End of Disable for SubSystem: '<S38>/NEGATIVE Edge' */
        CONTROL_SYSTEM_V3_DW.OFFDelay_MODE = false;
      }

      /* End of Logic: '<S33>/Logical Operator2' */
    }

    /* End of Outputs for SubSystem: '<S33>/OFF Delay' */
  }

  /* Outputs for Enabled SubSystem: '<S33>/OFF Delay' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  if (CONTROL_SYSTEM_V3_DW.OFFDelay_MODE) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* MultiPortSwitch: '<S38>/Multiport Switch' incorporates:
       *  Constant: '<S38>/Constant1'
       */
      switch ((int32_T)CONTROL_SYSTEM_V3_P.EdgeDetector_model) {
       case 1:
        /* MultiPortSwitch: '<S38>/Multiport Switch' incorporates:
         *  Constant: '<S38>/pos. edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch_l[0] =
          CONTROL_SYSTEM_V3_P.posedge_Value[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch_l[1] =
          CONTROL_SYSTEM_V3_P.posedge_Value[1];
        break;

       case 2:
        /* MultiPortSwitch: '<S38>/Multiport Switch' incorporates:
         *  Constant: '<S38>/neg. edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch_l[0] =
          CONTROL_SYSTEM_V3_P.negedge_Value[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch_l[1] =
          CONTROL_SYSTEM_V3_P.negedge_Value[1];
        break;

       default:
        /* MultiPortSwitch: '<S38>/Multiport Switch' incorporates:
         *  Constant: '<S38>/either edge'
         */
        CONTROL_SYSTEM_V3_B.MultiportSwitch_l[0] =
          CONTROL_SYSTEM_V3_P.eitheredge_Value[0];
        CONTROL_SYSTEM_V3_B.MultiportSwitch_l[1] =
          CONTROL_SYSTEM_V3_P.eitheredge_Value[1];
        break;
      }

      /* End of MultiPortSwitch: '<S38>/Multiport Switch' */

      /* Memory: '<S38>/Memory' */
      CONTROL_SYSTEM_V3_B.Memory_no =
        CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_dj;
    }

    /* Outputs for Enabled SubSystem: '<S38>/POSITIVE Edge' */
    CONTROL_SYSTEM_V3_POSITIVEEdge(CONTROL_SYSTEM_V3_M,
      CONTROL_SYSTEM_V3_B.MultiportSwitch_l[0], CONTROL_SYSTEM_V3_B.Logic_d[0],
      CONTROL_SYSTEM_V3_B.Memory_no, &CONTROL_SYSTEM_V3_B.RelationalOperator1_e,
      &CONTROL_SYSTEM_V3_DW.POSITIVEEdge);

    /* End of Outputs for SubSystem: '<S38>/POSITIVE Edge' */

    /* Outputs for Enabled SubSystem: '<S38>/NEGATIVE Edge' */
    CONTROL_SYSTEM_V3_NEGATIVEEdge(CONTROL_SYSTEM_V3_M,
      CONTROL_SYSTEM_V3_B.MultiportSwitch_l[1], CONTROL_SYSTEM_V3_B.Logic_d[0],
      CONTROL_SYSTEM_V3_B.Memory_no, &CONTROL_SYSTEM_V3_B.RelationalOperator1_f,
      &CONTROL_SYSTEM_V3_DW.NEGATIVEEdge);

    /* End of Outputs for SubSystem: '<S38>/NEGATIVE Edge' */

    /* Logic: '<S38>/Logical Operator1' */
    LogicalOperator1 = (CONTROL_SYSTEM_V3_B.RelationalOperator1_e ||
                        CONTROL_SYSTEM_V3_B.RelationalOperator1_f);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Memory: '<S43>/IC=ic' */
      CONTROL_SYSTEM_V3_B.ICic_i = CONTROL_SYSTEM_V3_DW.ICic_PreviousInput_b;
    }

    /* Switch: '<S43>/Switch' */
    if (LogicalOperator1) {
      /* Switch: '<S43>/Switch' */
      CONTROL_SYSTEM_V3_B.Switch_i = rtb_Sum1;
    } else {
      /* Switch: '<S43>/Switch' */
      CONTROL_SYSTEM_V3_B.Switch_i = CONTROL_SYSTEM_V3_B.ICic_i;
    }

    /* End of Switch: '<S43>/Switch' */

    /* Logic: '<S34>/Logical Operator2' incorporates:
     *  Constant: '<S33>/Constant1'
     *  Logic: '<S34>/Logical Operator'
     *  Logic: '<S34>/Logical Operator1'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  Sum: '<S34>/Sum'
     */
    CONTROL_SYSTEM_V3_B.LogicalOperator2_c = ((!(rtb_Sum1 >=
      CONTROL_SYSTEM_V3_B.Switch_i + CONTROL_SYSTEM_V3_P.OnDelay_delay)) ||
      CONTROL_SYSTEM_V3_B.Logic_d[0]);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Outputs for Triggered SubSystem: '<S39>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S42>/Trigger'
       */
      if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
        if (LogicalOperator1 &&
            (CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE_i !=
             POS_ZCSIG)) {
          CONTROL_SYSTEM_V3_DW.TriggeredSubsystem_SubsysRanB_j = 4;
        }

        CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE_i =
          LogicalOperator1;
      }

      /* End of Outputs for SubSystem: '<S39>/Triggered Subsystem' */
    }

    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_M->solverInfo)) {
      srUpdateBC(CONTROL_SYSTEM_V3_DW.OFFDelay_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S33>/OFF Delay' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Sum: '<S6>/Add2' incorporates:
     *  Constant: '<S6>/Desire Max Value'
     *  Constant: '<S6>/Desire Min Value'
     */
    CONTROL_SYSTEM_V3_B.Add2_o = CONTROL_SYSTEM_V3_P.Desire_Max -
      CONTROL_SYSTEM_V3_P.Desire_Min;

    /* Sum: '<S6>/Add3' */
    CONTROL_SYSTEM_V3_B.Add3_g = CONTROL_SYSTEM_V3_B.FP_maxVal -
      CONTROL_SYSTEM_V3_B.FP_minVal;

    /* Product: '<S6>/Divide1' */
    CONTROL_SYSTEM_V3_B.Divide1_i = CONTROL_SYSTEM_V3_B.Add2_o /
      CONTROL_SYSTEM_V3_B.Add3_g;
  }

  /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
   *  Gain: '<S10>/Multiply'
   *  Gain: '<S10>/Multiply1'
   *  Gain: '<S10>/Multiply2'
   *  Sum: '<S10>/Add'
   */
  switch ((uint8_T)(((((uint32_T)(CONTROL_SYSTEM_V3_B.Logic_e[0] ? (int32_T)
    CONTROL_SYSTEM_V3_P.Multiply1_Gain : 0) << 1) + (uint32_T)
                      (CONTROL_SYSTEM_V3_B.Logic[0] ? (int32_T)
                       CONTROL_SYSTEM_V3_P.Multiply_Gain : 0)) + ((uint32_T)
             (CONTROL_SYSTEM_V3_B.Logic_f[0] ? (int32_T)
              CONTROL_SYSTEM_V3_P.Multiply2_Gain : 0) << 1)) >> 1) >> 6) {
   case 1:
    /* Switch: '<S5>/Switch' */
    rtb_Sum1 = CONTROL_SYSTEM_V3_B.Error_j;
    break;

   case 2:
    /* Switch: '<S5>/Switch' */
    rtb_Sum1 = CONTROL_SYSTEM_V3_B.Switch2_e;
    break;

   default:
    /* Switch: '<S5>/Switch' */
    rtb_Sum1 = CONTROL_SYSTEM_V3_B.Switch2;
    break;
  }

  /* End of MultiPortSwitch: '<S10>/Multiport Switch' */

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Desire Min Value'
   *  Product: '<S6>/Product1'
   *  Sum: '<S6>/Subtract'
   */
  CONTROL_SYSTEM_V3_B.Sum_h = (rtb_Sum1 - CONTROL_SYSTEM_V3_B.FP_minVal) *
    CONTROL_SYSTEM_V3_B.Divide1_i + CONTROL_SYSTEM_V3_P.Desire_Min;

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S8>/Constant'
   *  Logic: '<S33>/Logical Operator1'
   *  Switch: '<S8>/Switch1'
   */
  if (CONTROL_SYSTEM_V3_B.LogicalOperator2_g ||
      CONTROL_SYSTEM_V3_B.LogicalOperator2_c) {
    rtb_Sum1 = CONTROL_SYSTEM_V3_P.Constant_Value_p;
  } else if (CONTROL_SYSTEM_V3_B.Logic_d[0]) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Gain: '<S8>/Gain'
     */
    rtb_Sum1 = (real_T)(CONTROL_SYSTEM_V3_B.Logic_d[0] ? (int32_T)
                        CONTROL_SYSTEM_V3_P.Gain_Gain_f : 0) * 0.5;
  } else {
    /* Switch: '<S8>/Switch1' */
    rtb_Sum1 = CONTROL_SYSTEM_V3_B.Sum_h;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Start for MATLABSystem: '<S8>/PWM' */
  if (!(rtb_Sum1 <= 255.0)) {
    rtb_Sum1 = 255.0;
  }

  /* MATLABSystem: '<S8>/PWM' */
  CONTROL_SYSTEM_V3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);

  /* Start for MATLABSystem: '<S8>/PWM' */
  if (!(rtb_Sum1 >= 0.0)) {
    rtb_Sum1 = 0.0;
  }

  /* MATLABSystem: '<S8>/PWM' */
  MW_PWM_SetDutyCycle(CONTROL_SYSTEM_V3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                      -(rtb_Sum1 * 255.0 / 255.0));
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
    CONTROL_SYSTEM_V3_B.PulseGenerator = (CONTROL_SYSTEM_V3_DW.clockTickCounter <
      CONTROL_SYSTEM_V3_P.PulseGenerator_Duty) &&
      (CONTROL_SYSTEM_V3_DW.clockTickCounter >= 0) ?
      CONTROL_SYSTEM_V3_P.PulseGenerator_Amp : 0.0;

    /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
    if (CONTROL_SYSTEM_V3_DW.clockTickCounter >=
        CONTROL_SYSTEM_V3_P.PulseGenerator_Period - 1.0) {
      CONTROL_SYSTEM_V3_DW.clockTickCounter = 0;
    } else {
      CONTROL_SYSTEM_V3_DW.clockTickCounter++;
    }
  }

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (CONTROL_SYSTEM_V3_B.Logic_d[0]) {
    rtb_Sum1 = CONTROL_SYSTEM_V3_B.PulseGenerator;
  } else {
    rtb_Sum1 = CONTROL_SYSTEM_V3_P.Constant_Value_o;
  }

  /* MATLABSystem: '<S4>/Digital Output3' incorporates:
   *  Switch: '<S4>/Switch'
   */
  rtb_Sum1 = rt_roundd_snf(rtb_Sum1);
  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      tmp = (uint8_T)rtb_Sum1;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(33, tmp);

  /* End of MATLABSystem: '<S4>/Digital Output3' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Abs: '<S15>/Abs'
   *  Product: '<S15>/Divide'
   */
  rtb_Sum1 = fabs(CONTROL_SYSTEM_V3_B.Error / CONTROL_SYSTEM_V3_B.Sum);

  /* Gain: '<S15>/Gain' */
  CONTROL_SYSTEM_V3_B.PercentageError = CONTROL_SYSTEM_V3_P.Gain_Gain_i *
    rtb_Sum1;
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
  }

  /* FromWorkspace: '<S14>/From Workspace' */
  {
    real_T t = CONTROL_SYSTEM_V3_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      CONTROL_SYSTEM_V3_DW.FromWorkspace_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      CONTROL_SYSTEM_V3_DW.FromWorkspace_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      rtb_Sum1 = 0.0;
    } else if (t == pTimeValues[4]) {
      rtb_Sum1 = pDataValues[4];
    } else if (t > pTimeValues[4]) {
      rtb_Sum1 = 0.0;
    } else {
      int_T currTimeIndex = CONTROL_SYSTEM_V3_DW.FromWorkspace_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      rtb_Sum1 = pDataValues[currTimeIndex];
      CONTROL_SYSTEM_V3_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* Switch: '<S1>/Switch4' */
  if (rtb_Sum1 != 0.0) {
    /* Switch: '<S1>/Switch4' */
    CONTROL_SYSTEM_V3_B.FootPedalSignal_l = CONTROL_SYSTEM_V3_B.Sum;
  } else {
    /* Switch: '<S1>/Switch4' */
    CONTROL_SYSTEM_V3_B.FootPedalSignal_l = 0.0;
  }

  /* End of Switch: '<S1>/Switch4' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
    CONTROL_SYSTEM_V3_B.PulseGenerator_p =
      (CONTROL_SYSTEM_V3_DW.clockTickCounter_k <
       CONTROL_SYSTEM_V3_P.PulseGenerator_Duty_p) &&
      (CONTROL_SYSTEM_V3_DW.clockTickCounter_k >= 0) ?
      CONTROL_SYSTEM_V3_P.PulseGenerator_Amp_i : 0.0;

    /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
    if (CONTROL_SYSTEM_V3_DW.clockTickCounter_k >=
        CONTROL_SYSTEM_V3_P.PulseGenerator_Period_m - 1.0) {
      CONTROL_SYSTEM_V3_DW.clockTickCounter_k = 0;
    } else {
      CONTROL_SYSTEM_V3_DW.clockTickCounter_k++;
    }
  }

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   */
  if (CONTROL_SYSTEM_V3_B.MATLABSystem_o2 > CONTROL_SYSTEM_V3_P.Switch_Threshold)
  {
    rtb_Sum1 = CONTROL_SYSTEM_V3_P.Constant_Value_e;
  } else {
    rtb_Sum1 = CONTROL_SYSTEM_V3_P.Constant1_Value_c;
  }

  /* Switch: '<S5>/Switch2' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant3'
   */
  if (CONTROL_SYSTEM_V3_B.MATLABSystem_o3 >
      CONTROL_SYSTEM_V3_P.Switch2_Threshold) {
    Integrator_CSTATE = CONTROL_SYSTEM_V3_P.Constant2_Value_g;
  } else {
    Integrator_CSTATE = CONTROL_SYSTEM_V3_P.Constant3_Value_b5;
  }

  /* Switch: '<S5>/Switch3' incorporates:
   *  Constant: '<S5>/Constant4'
   *  Logic: '<S5>/OR'
   *  Switch: '<S5>/Switch'
   *  Switch: '<S5>/Switch2'
   */
  if ((!(rtb_Sum1 != 0.0)) || (!(Integrator_CSTATE != 0.0))) {
    rtb_Sum1 = CONTROL_SYSTEM_V3_B.PulseGenerator_p;
  } else {
    rtb_Sum1 = CONTROL_SYSTEM_V3_P.Constant4_Value;
  }

  /* MATLABSystem: '<S5>/Digital Output4' incorporates:
   *  Switch: '<S5>/Switch3'
   */
  rtb_Sum1 = rt_roundd_snf(rtb_Sum1);
  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      tmp = (uint8_T)rtb_Sum1;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(32, tmp);

  /* End of MATLABSystem: '<S5>/Digital Output4' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    /* Constant: '<S8>/Enable Pin' */
    CONTROL_SYSTEM_V3_B.EnablePin = CONTROL_SYSTEM_V3_P.EN_Pin;

    /* MATLABSystem: '<S8>/Digital Output' */
    rtb_Sum1 = rt_roundd_snf(CONTROL_SYSTEM_V3_B.EnablePin);
    if (rtb_Sum1 < 256.0) {
      if (rtb_Sum1 >= 0.0) {
        tmp = (uint8_T)rtb_Sum1;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(0, tmp);

    /* End of MATLABSystem: '<S8>/Digital Output' */
    /* Constant: '<S8>/Direction Pin' */
    CONTROL_SYSTEM_V3_B.DirectionPin = CONTROL_SYSTEM_V3_P.Direction_Pin;

    /* MATLABSystem: '<S8>/Digital Output1' */
    rtb_Sum1 = rt_roundd_snf(CONTROL_SYSTEM_V3_B.DirectionPin);
    if (rtb_Sum1 < 256.0) {
      if (rtb_Sum1 >= 0.0) {
        tmp = (uint8_T)rtb_Sum1;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(16, tmp);

    /* End of MATLABSystem: '<S8>/Digital Output1' */
  }

  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
      /* Update for Memory: '<S52>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput = CONTROL_SYSTEM_V3_B.Logic[0];

      /* Update for Memory: '<S54>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_b = CONTROL_SYSTEM_V3_B.Logic_e
        [0];

      /* Update for Memory: '<S55>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_h = CONTROL_SYSTEM_V3_B.Logic_f
        [0];

      /* Update for Memory: '<S53>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_d = CONTROL_SYSTEM_V3_B.Logic_d
        [0];
    }

    /* Update for If: '<S1>/If Condition1' */
    if (CONTROL_SYSTEM_V3_DW.IfCondition1_ActiveSubsystem == 1) {
      /* Update for IfAction SubSystem: '<S1>/PID Control1' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {
        /* Update for DiscreteIntegrator: '<S91>/Integrator' */
        CONTROL_SYSTEM_V3_DW.Integrator_DSTATE +=
          CONTROL_SYSTEM_V3_P.Integrator_gainval *
          CONTROL_SYSTEM_V3_B.IntegralGain;

        /* Update for DiscreteIntegrator: '<S86>/Filter' */
        CONTROL_SYSTEM_V3_DW.Filter_DSTATE += CONTROL_SYSTEM_V3_P.Filter_gainval
          * CONTROL_SYSTEM_V3_B.FilterCoefficient;
      }

      /* End of Update for SubSystem: '<S1>/PID Control1' */
    }

    /* End of Update for If: '<S1>/If Condition1' */

    /* Update for Enabled SubSystem: '<S33>/ON Delay' incorporates:
     *  EnablePort: '<S35>/Enable'
     */
    if (CONTROL_SYSTEM_V3_DW.ONDelay_MODE && rtmIsMajorTimeStep
        (CONTROL_SYSTEM_V3_M)) {
      /* Update for Memory: '<S46>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_n = CONTROL_SYSTEM_V3_B.Logic_d
        [0];

      /* Update for Memory: '<S51>/IC=ic' */
      CONTROL_SYSTEM_V3_DW.ICic_PreviousInput = CONTROL_SYSTEM_V3_B.Switch;
    }

    /* End of Update for SubSystem: '<S33>/ON Delay' */

    /* Update for Enabled SubSystem: '<S33>/OFF Delay' incorporates:
     *  EnablePort: '<S34>/Enable'
     */
    if (CONTROL_SYSTEM_V3_DW.OFFDelay_MODE && rtmIsMajorTimeStep
        (CONTROL_SYSTEM_V3_M)) {
      /* Update for Memory: '<S38>/Memory' */
      CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_dj =
        CONTROL_SYSTEM_V3_B.Logic_d[0];

      /* Update for Memory: '<S43>/IC=ic' */
      CONTROL_SYSTEM_V3_DW.ICic_PreviousInput_b = CONTROL_SYSTEM_V3_B.Switch_i;
    }

    /* End of Update for SubSystem: '<S33>/OFF Delay' */
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((CONTROL_SYSTEM_V3_M->Timing.clockTick1) * 0.01);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
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

  /* Derivatives for If: '<S1>/If Condition1' */
  {
    real_T *dx;
    int_T i1;
    dx = &(((XDot_CONTROL_SYSTEM_V3_T *) CONTROL_SYSTEM_V3_M->derivs)
           ->Integrator_CSTATE[0]);
    for (i1=0; i1 < 3; i1++) {
      dx[i1] = 0.0;
    }
  }

  if (CONTROL_SYSTEM_V3_DW.IfCondition1_ActiveSubsystem == 2) {
    /* Derivatives for IfAction SubSystem: '<S1>/ADRC Control1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Derivatives for Integrator: '<S28>/Integrator' */
    _rtXdot->Integrator_CSTATE[0] = CONTROL_SYSTEM_V3_B.dxe[0];
    _rtXdot->Integrator_CSTATE[1] = CONTROL_SYSTEM_V3_B.dxe[1];
    _rtXdot->Integrator_CSTATE[2] = CONTROL_SYSTEM_V3_B.dxe[2];

    /* End of Derivatives for SubSystem: '<S1>/ADRC Control1' */
  }

  /* End of Derivatives for If: '<S1>/If Condition1' */
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
  rtmSetTFinal(CONTROL_SYSTEM_V3_M, -1);
  CONTROL_SYSTEM_V3_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  CONTROL_SYSTEM_V3_M->Sizes.checksums[0] = (2919133234U);
  CONTROL_SYSTEM_V3_M->Sizes.checksums[1] = (3045350839U);
  CONTROL_SYSTEM_V3_M->Sizes.checksums[2] = (63489670U);
  CONTROL_SYSTEM_V3_M->Sizes.checksums[3] = (3936668173U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[37];
    CONTROL_SYSTEM_V3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.ADRCControl1_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.ADRCControl1_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = (sysRanDType *)
      &CONTROL_SYSTEM_V3_DW.TriggeredSubsystem_SubsysRanB_j;
    systemRan[13] = (sysRanDType *)
      &CONTROL_SYSTEM_V3_DW.NEGATIVEEdge.NEGATIVEEdge_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &CONTROL_SYSTEM_V3_DW.POSITIVEEdge.POSITIVEEdge_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.OFFDelay_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.OFFDelay_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.OFFDelay_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.OFFDelay_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &CONTROL_SYSTEM_V3_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &CONTROL_SYSTEM_V3_DW.NEGATIVEEdge_m.NEGATIVEEdge_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &CONTROL_SYSTEM_V3_DW.POSITIVEEdge_b.POSITIVEEdge_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.ONDelay_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.ONDelay_SubsysRanBC;
    systemRan[24] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.ONDelay_SubsysRanBC;
    systemRan[25] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.ONDelay_SubsysRanBC;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.PIDControl1_SubsysRanBC;
    systemRan[34] = (sysRanDType *)&CONTROL_SYSTEM_V3_DW.PIDControl1_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &CONTROL_SYSTEM_V3_DW.Propotional1_SubsysRanBC;
    systemRan[36] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(CONTROL_SYSTEM_V3_M->extModeInfo,
      &CONTROL_SYSTEM_V3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(CONTROL_SYSTEM_V3_M->extModeInfo,
                        CONTROL_SYSTEM_V3_M->Sizes.checksums);
    rteiSetTPtr(CONTROL_SYSTEM_V3_M->extModeInfo, rtmGetTPtr(CONTROL_SYSTEM_V3_M));
  }

  /* Start for FromWorkspace: '<S13>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 3.0, 3.0, 5.0, 5.0, 7.0, 7.0, 9.0,
      9.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 50.0, 50.0, 25.0, 25.0,
      100.0, 100.0, 0.0, 0.0 } ;

    CONTROL_SYSTEM_V3_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
    CONTROL_SYSTEM_V3_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
    CONTROL_SYSTEM_V3_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }

  /* Start for If: '<S1>/If Condition1' */
  (void) memset(&(CONTROL_SYSTEM_V3_XDis.Integrator_CSTATE), 1,
                3*sizeof(boolean_T));
  CONTROL_SYSTEM_V3_DW.IfCondition1_ActiveSubsystem = -1;

  /* Start for FromWorkspace: '<S14>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 2.0, 2.0, 10.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 1.0, 1.0, 0.0 } ;

    CONTROL_SYSTEM_V3_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    CONTROL_SYSTEM_V3_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    CONTROL_SYSTEM_V3_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE_i = POS_ZCSIG;
  CONTROL_SYSTEM_V3_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for Memory: '<S52>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput =
    CONTROL_SYSTEM_V3_P.SRFlipFlop3_initial_condition;

  /* InitializeConditions for Memory: '<S54>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_b =
    CONTROL_SYSTEM_V3_P.SRFlipFlop5_initial_condition;

  /* InitializeConditions for Memory: '<S55>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_h =
    CONTROL_SYSTEM_V3_P.SRFlipFlop6_initial_condition;

  /* InitializeConditions for Memory: '<S53>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_d =
    CONTROL_SYSTEM_V3_P.SRFlipFlop4_initial_condition;

  /* SystemInitialize for MATLAB Function: '<S1>/Foot Pedal Calibration1' */
  CONTROL_SYSTEM_V3_DW.maxSet = -1.0;
  CONTROL_SYSTEM_V3_DW.minSet = 5.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Throttle Body Callibration1' */
  CONTROL_SYSTEM_V3_DW.TB_maxSet = -1.0;
  CONTROL_SYSTEM_V3_DW.TB_minSet = 5.0;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Propotional1' */
  /* SystemInitialize for SignalConversion generated from: '<S12>/Error' incorporates:
   *  Outport: '<S12>/Propotional'
   */
  CONTROL_SYSTEM_V3_B.Error_j = CONTROL_SYSTEM_V3_P.Propotional_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Propotional1' */
  /* InitializeConditions for DiscreteIntegrator: '<S91>/Integrator' */
  CONTROL_SYSTEM_V3_DW.Integrator_DSTATE =
    CONTROL_SYSTEM_V3_P.PIDController1_InitialConditi_o;

  /* InitializeConditions for DiscreteIntegrator: '<S86>/Filter' */
  CONTROL_SYSTEM_V3_DW.Filter_DSTATE =
    CONTROL_SYSTEM_V3_P.PIDController1_InitialCondition;

  /* SystemInitialize for Switch: '<S57>/Switch2' incorporates:
   *  Outport: '<S11>/PID Output'
   */
  CONTROL_SYSTEM_V3_B.Switch2_e = CONTROL_SYSTEM_V3_P.PIDOutput_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/PID Control1' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/ADRC Control1' */
  /* InitializeConditions for Integrator: '<S28>/Integrator' */
  CONTROL_SYSTEM_V3_X.Integrator_CSTATE[0] = CONTROL_SYSTEM_V3_P.Observer_x0;
  CONTROL_SYSTEM_V3_X.Integrator_CSTATE[1] = CONTROL_SYSTEM_V3_P.Observer_x0;
  CONTROL_SYSTEM_V3_X.Integrator_CSTATE[2] = CONTROL_SYSTEM_V3_P.Observer_x0;

  /* SystemInitialize for Gain: '<S26>/Gain1' incorporates:
   *  Outport: '<S2>/ADRC Output'
   *  Switch: '<S19>/Switch2'
   */
  CONTROL_SYSTEM_V3_B.Switch2 = CONTROL_SYSTEM_V3_P.ADRCOutput_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/ADRC Control1' */

  /* SystemInitialize for Enabled SubSystem: '<S33>/ON Delay' */
  /* InitializeConditions for Memory: '<S46>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_n = CONTROL_SYSTEM_V3_P.OnDelay_ic;

  /* InitializeConditions for Memory: '<S51>/IC=ic' */
  CONTROL_SYSTEM_V3_DW.ICic_PreviousInput =
    CONTROL_SYSTEM_V3_P.SampleandHold_ic_k;

  /* SystemInitialize for Enabled SubSystem: '<S46>/POSITIVE Edge' */
  CONTROL_SYSTE_POSITIVEEdge_Init(&CONTROL_SYSTEM_V3_B.RelationalOperator1_i,
    &CONTROL_SYSTEM_V3_P.POSITIVEEdge_b);

  /* End of SystemInitialize for SubSystem: '<S46>/POSITIVE Edge' */

  /* SystemInitialize for Enabled SubSystem: '<S46>/NEGATIVE Edge' */
  CONTROL_SYSTE_NEGATIVEEdge_Init(&CONTROL_SYSTEM_V3_B.RelationalOperator1_g,
    &CONTROL_SYSTEM_V3_P.NEGATIVEEdge_m);

  /* End of SystemInitialize for SubSystem: '<S46>/NEGATIVE Edge' */

  /* SystemInitialize for Logic: '<S35>/Logical Operator2' incorporates:
   *  Outport: '<S35>/OUT'
   */
  CONTROL_SYSTEM_V3_B.LogicalOperator2_g = CONTROL_SYSTEM_V3_P.OUT_Y0_o;

  /* End of SystemInitialize for SubSystem: '<S33>/ON Delay' */

  /* SystemInitialize for Enabled SubSystem: '<S33>/OFF Delay' */
  /* InitializeConditions for Memory: '<S38>/Memory' */
  CONTROL_SYSTEM_V3_DW.Memory_PreviousInput_dj = CONTROL_SYSTEM_V3_P.OnDelay_ic;

  /* InitializeConditions for Memory: '<S43>/IC=ic' */
  CONTROL_SYSTEM_V3_DW.ICic_PreviousInput_b =
    CONTROL_SYSTEM_V3_P.SampleandHold_ic;

  /* SystemInitialize for Enabled SubSystem: '<S38>/POSITIVE Edge' */
  CONTROL_SYSTE_POSITIVEEdge_Init(&CONTROL_SYSTEM_V3_B.RelationalOperator1_e,
    &CONTROL_SYSTEM_V3_P.POSITIVEEdge);

  /* End of SystemInitialize for SubSystem: '<S38>/POSITIVE Edge' */

  /* SystemInitialize for Enabled SubSystem: '<S38>/NEGATIVE Edge' */
  CONTROL_SYSTE_NEGATIVEEdge_Init(&CONTROL_SYSTEM_V3_B.RelationalOperator1_f,
    &CONTROL_SYSTEM_V3_P.NEGATIVEEdge);

  /* End of SystemInitialize for SubSystem: '<S38>/NEGATIVE Edge' */

  /* SystemInitialize for Logic: '<S34>/Logical Operator2' incorporates:
   *  Outport: '<S34>/OUT'
   */
  CONTROL_SYSTEM_V3_B.LogicalOperator2_c = CONTROL_SYSTEM_V3_P.OUT_Y0;

  /* End of SystemInitialize for SubSystem: '<S33>/OFF Delay' */

  /* Start for MATLABSystem: '<S9>/Digital Input' */
  CONTROL_SYSTEM_V3_DW.obj_c.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_c.SampleTime =
    CONTROL_SYSTEM_V3_P.DigitalInput_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj_c.isInitialized = 1;
  digitalIOSetup(36, 0);
  CONTROL_SYSTEM_V3_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/Digital Input3' */
  CONTROL_SYSTEM_V3_DW.obj_n.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_n.SampleTime =
    CONTROL_SYSTEM_V3_P.DigitalInput3_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj_n.isInitialized = 1;
  digitalIOSetup(35, 0);
  CONTROL_SYSTEM_V3_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/Digital Input1' */
  CONTROL_SYSTEM_V3_DW.obj_m.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_m.SampleTime =
    CONTROL_SYSTEM_V3_P.DigitalInput1_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj_m.isInitialized = 1;
  digitalIOSetup(39, 0);
  CONTROL_SYSTEM_V3_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/Digital Input2' */
  CONTROL_SYSTEM_V3_DW.obj_l.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_l.SampleTime =
    CONTROL_SYSTEM_V3_P.DigitalInput2_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj_l.isInitialized = 1;
  digitalIOSetup(34, 0);
  CONTROL_SYSTEM_V3_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  CONTROL_SYSTEM_V3_DW.obj_dn.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_dn.isInitialized = 1;
  digitalIOSetup(27, 1);
  CONTROL_SYSTEM_V3_DW.obj_dn.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/MATLAB System' */
  /*  Constructor */
  CONTROL_SYSTEM_V3_DW.obj.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj.SampleTime =
    CONTROL_SYSTEM_V3_P.MATLABSystem_SampleTime;
  CONTROL_SYSTEM_V3_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionADS1115_Vread(16, 1.0);
  CONTROL_SYSTEM_V3_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output2' */
  CONTROL_SYSTEM_V3_DW.obj_j.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_j.isInitialized = 1;
  digitalIOSetup(25, 1);
  CONTROL_SYSTEM_V3_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  CONTROL_SYSTEM_V3_DW.obj_e.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_e.isInitialized = 1;
  digitalIOSetup(26, 1);
  CONTROL_SYSTEM_V3_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/PWM' */
  CONTROL_SYSTEM_V3_DW.obj_g.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_g.isInitialized = 1;
  CONTROL_SYSTEM_V3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4U,
    19000.0, 255.0);
  CONTROL_SYSTEM_V3_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output3' */
  CONTROL_SYSTEM_V3_DW.obj_i.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_i.isInitialized = 1;
  digitalIOSetup(33, 1);
  CONTROL_SYSTEM_V3_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output4' */
  CONTROL_SYSTEM_V3_DW.obj_n5.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_n5.isInitialized = 1;
  digitalIOSetup(32, 1);
  CONTROL_SYSTEM_V3_DW.obj_n5.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Digital Output' */
  CONTROL_SYSTEM_V3_DW.obj_d.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_d.isInitialized = 1;
  digitalIOSetup(0, 1);
  CONTROL_SYSTEM_V3_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Digital Output1' */
  CONTROL_SYSTEM_V3_DW.obj_my.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_DW.obj_my.isInitialized = 1;
  digitalIOSetup(16, 1);
  CONTROL_SYSTEM_V3_DW.obj_my.isSetupComplete = true;
}

/* Model terminate function */
void CONTROL_SYSTEM_V3_terminate(void)
{
  /* Terminate for MATLABSystem: '<S9>/Digital Input' */
  if (!CONTROL_SYSTEM_V3_DW.obj_c.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Input' */

  /* Terminate for MATLABSystem: '<S9>/Digital Input3' */
  if (!CONTROL_SYSTEM_V3_DW.obj_n.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Input3' */

  /* Terminate for MATLABSystem: '<S9>/Digital Input1' */
  if (!CONTROL_SYSTEM_V3_DW.obj_m.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Input1' */

  /* Terminate for MATLABSystem: '<S9>/Digital Input2' */
  if (!CONTROL_SYSTEM_V3_DW.obj_l.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Input2' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!CONTROL_SYSTEM_V3_DW.obj_dn.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_dn.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S3>/MATLAB System' */
  if (!CONTROL_SYSTEM_V3_DW.obj.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/MATLAB System' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output2' */
  if (!CONTROL_SYSTEM_V3_DW.obj_j.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!CONTROL_SYSTEM_V3_DW.obj_e.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S8>/PWM' */
  if (!CONTROL_SYSTEM_V3_DW.obj_g.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_g.matlabCodegenIsDeleted = true;
    CONTROL_SYST_SystemCore_release(&CONTROL_SYSTEM_V3_DW.obj_g);
  }

  /* End of Terminate for MATLABSystem: '<S8>/PWM' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output3' */
  if (!CONTROL_SYSTEM_V3_DW.obj_i.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output3' */
  /* Terminate for MATLABSystem: '<S5>/Digital Output4' */
  if (!CONTROL_SYSTEM_V3_DW.obj_n5.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_n5.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output4' */
  /* Terminate for MATLABSystem: '<S8>/Digital Output' */
  if (!CONTROL_SYSTEM_V3_DW.obj_d.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Output' */
  /* Terminate for MATLABSystem: '<S8>/Digital Output1' */
  if (!CONTROL_SYSTEM_V3_DW.obj_my.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_DW.obj_my.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
