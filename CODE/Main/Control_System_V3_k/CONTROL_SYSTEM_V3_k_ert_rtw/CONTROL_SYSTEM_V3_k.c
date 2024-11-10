/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: CONTROL_SYSTEM_V3_k.c
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
#include "rtwtypes.h"
#include "CONTROL_SYSTEM_V3_k_types.h"
#include "CONTROL_SYSTEM_V3_k_private.h"
#include "zero_crossing_types.h"
#include <math.h>

/* Block signals (default storage) */
B_CONTROL_SYSTEM_V3_k_T CONTROL_SYSTEM_V3_k_B;

/* Continuous states */
X_CONTROL_SYSTEM_V3_k_T CONTROL_SYSTEM_V3_k_X;

/* Disabled State Vector */
XDis_CONTROL_SYSTEM_V3_k_T CONTROL_SYSTEM_V3_k_XDis;

/* Block states (default storage) */
DW_CONTROL_SYSTEM_V3_k_T CONTROL_SYSTEM_V3_k_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_CONTROL_SYSTEM_V3_k_T CONTROL_SYSTEM_V3_k_PrevZCX;

/* Real-time model */
static RT_MODEL_CONTROL_SYSTEM_V3_k_T CONTROL_SYSTEM_V3_k_M_;
RT_MODEL_CONTROL_SYSTEM_V3_k_T *const CONTROL_SYSTEM_V3_k_M =
  &CONTROL_SYSTEM_V3_k_M_;

/* Forward declaration for local functions */
static void CONTROL_SYST_SystemCore_release(codertarget_arduinobase_inter_T *obj);

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  CONTROL_SYSTEM_V3_k_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S20>/NEGATIVE Edge'
 *    '<S28>/NEGATIVE Edge'
 */
void CONTROL_SYSTE_NEGATIVEEdge_Init(boolean_T *rty_OUT,
  P_NEGATIVEEdge_CONTROL_SYSTEM_T *localP)
{
  /* SystemInitialize for Outport: '<S22>/OUT' */
  *rty_OUT = localP->OUT_Y0;
}

/*
 * Disable for enable system:
 *    '<S20>/NEGATIVE Edge'
 *    '<S28>/NEGATIVE Edge'
 */
void CONTROL_SY_NEGATIVEEdge_Disable(DW_NEGATIVEEdge_CONTROL_SYSTE_T *localDW)
{
  localDW->NEGATIVEEdge_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S20>/NEGATIVE Edge'
 *    '<S28>/NEGATIVE Edge'
 */
void CONTROL_SYSTEM_V3__NEGATIVEEdge(RT_MODEL_CONTROL_SYSTEM_V3_k_T * const
  CONTROL_SYSTEM_V3_k_M, real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, boolean_T *rty_OUT, DW_NEGATIVEEdge_CONTROL_SYSTE_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S20>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M) && rtsiIsModeUpdateTimeStep
      (&CONTROL_SYSTEM_V3_k_M->solverInfo)) {
    if (rtu_Enable > 0.0) {
      localDW->NEGATIVEEdge_MODE = true;
    } else if (localDW->NEGATIVEEdge_MODE) {
      CONTROL_SY_NEGATIVEEdge_Disable(localDW);
    }
  }

  if (localDW->NEGATIVEEdge_MODE) {
    /* RelationalOperator: '<S22>/Relational Operator1' */
    *rty_OUT = ((int32_T)rtu_INprevious > (int32_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S20>/NEGATIVE Edge' */
}

/*
 * System initialize for enable system:
 *    '<S20>/POSITIVE Edge'
 *    '<S28>/POSITIVE Edge'
 */
void CONTROL_SYSTE_POSITIVEEdge_Init(boolean_T *rty_OUT,
  P_POSITIVEEdge_CONTROL_SYSTEM_T *localP)
{
  /* SystemInitialize for Outport: '<S23>/OUT' */
  *rty_OUT = localP->OUT_Y0;
}

/*
 * Disable for enable system:
 *    '<S20>/POSITIVE Edge'
 *    '<S28>/POSITIVE Edge'
 */
void CONTROL_SY_POSITIVEEdge_Disable(DW_POSITIVEEdge_CONTROL_SYSTE_T *localDW)
{
  localDW->POSITIVEEdge_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S20>/POSITIVE Edge'
 *    '<S28>/POSITIVE Edge'
 */
void CONTROL_SYSTEM_V3__POSITIVEEdge(RT_MODEL_CONTROL_SYSTEM_V3_k_T * const
  CONTROL_SYSTEM_V3_k_M, real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, boolean_T *rty_OUT, DW_POSITIVEEdge_CONTROL_SYSTE_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S20>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S23>/Enable'
   */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M) && rtsiIsModeUpdateTimeStep
      (&CONTROL_SYSTEM_V3_k_M->solverInfo)) {
    if (rtu_Enable > 0.0) {
      localDW->POSITIVEEdge_MODE = true;
    } else if (localDW->POSITIVEEdge_MODE) {
      CONTROL_SY_POSITIVEEdge_Disable(localDW);
    }
  }

  if (localDW->POSITIVEEdge_MODE) {
    /* RelationalOperator: '<S23>/Relational Operator1' */
    *rty_OUT = ((int32_T)rtu_INprevious < (int32_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S20>/POSITIVE Edge' */
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
  /* Start for MATLABSystem: '<S6>/PWM' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }

  /* End of Start for MATLABSystem: '<S6>/PWM' */
}

/* Model step function */
void CONTROL_SYSTEM_V3_k_step(void)
{
  real_T b_varargout_2;
  real_T b_varargout_3;
  real_T b_varargout_4;
  real_T rtb_Error;
  real_T rtb_FP_maxVal;
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
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&CONTROL_SYSTEM_V3_k_M->solverInfo,
                          ((CONTROL_SYSTEM_V3_k_M->Timing.clockTick0+1)*
      CONTROL_SYSTEM_V3_k_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    CONTROL_SYSTEM_V3_k_M->Timing.t[0] = rtsiGetT
      (&CONTROL_SYSTEM_V3_k_M->solverInfo);
  }

  /* MATLABSystem: '<S7>/Digital Input' */
  if (CONTROL_SYSTEM_V3_k_DW.obj_dc.SampleTime !=
      CONTROL_SYSTEM_V3_k_P.DigitalInput_SampleTime) {
    CONTROL_SYSTEM_V3_k_DW.obj_dc.SampleTime =
      CONTROL_SYSTEM_V3_k_P.DigitalInput_SampleTime;
  }

  LogicalOperator1 = readDigitalPin(36);

  /* MATLABSystem: '<S7>/Digital Input3' */
  if (CONTROL_SYSTEM_V3_k_DW.obj_m.SampleTime !=
      CONTROL_SYSTEM_V3_k_P.DigitalInput3_SampleTime) {
    CONTROL_SYSTEM_V3_k_DW.obj_m.SampleTime =
      CONTROL_SYSTEM_V3_k_P.DigitalInput3_SampleTime;
  }

  c_value = readDigitalPin(35);

  /* MATLABSystem: '<S7>/Digital Input1' */
  if (CONTROL_SYSTEM_V3_k_DW.obj_e.SampleTime !=
      CONTROL_SYSTEM_V3_k_P.DigitalInput1_SampleTime) {
    CONTROL_SYSTEM_V3_k_DW.obj_e.SampleTime =
      CONTROL_SYSTEM_V3_k_P.DigitalInput1_SampleTime;
  }

  c_value_0 = readDigitalPin(39);

  /* MATLABSystem: '<S7>/Digital Input2' */
  if (CONTROL_SYSTEM_V3_k_DW.obj_d.SampleTime !=
      CONTROL_SYSTEM_V3_k_P.DigitalInput2_SampleTime) {
    CONTROL_SYSTEM_V3_k_DW.obj_d.SampleTime =
      CONTROL_SYSTEM_V3_k_P.DigitalInput2_SampleTime;
  }

  c_value_1 = readDigitalPin(34);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* Memory: '<S34>/Memory' */
    CONTROL_SYSTEM_V3_k_B.Memory = CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput;
  }

  /* Logic: '<S7>/Logical Operator16' incorporates:
   *  Logic: '<S7>/Logical Operator38'
   *  Logic: '<S7>/Logical Operator46'
   *  MATLABSystem: '<S7>/Digital Input3'
   * */
  rowIdx_tmp = !c_value;

  /* Logic: '<S7>/Logical Operator17' incorporates:
   *  Logic: '<S7>/Logical Operator33'
   *  MATLABSystem: '<S7>/Digital Input2'
   * */
  rowIdx_tmp_0 = !c_value_1;

  /* Logic: '<S7>/Logical Operator22' incorporates:
   *  Logic: '<S7>/Logical Operator41'
   *  MATLABSystem: '<S7>/Digital Input1'
   * */
  rowIdx_tmp_2 = !c_value_0;

  /* Logic: '<S7>/Logical Operator21' incorporates:
   *  Logic: '<S7>/Logical Operator17'
   *  Logic: '<S7>/Logical Operator22'
   *  Logic: '<S7>/Logical Operator29'
   */
  rowIdx_tmp_3 = (rowIdx_tmp_2 && rowIdx_tmp_0);

  /* Logic: '<S7>/Logical Operator23' incorporates:
   *  Logic: '<S7>/Logical Operator31'
   *  MATLABSystem: '<S7>/Digital Input1'
   *  MATLABSystem: '<S7>/Digital Input2'
   * */
  rowIdx_tmp_4 = (int8_T)((int8_T)c_value_0 ^ (int8_T)c_value_1);

  /* CombinatorialLogic: '<S34>/Logic' incorporates:
   *  Logic: '<S7>/Logical Operator16'
   *  Logic: '<S7>/Logical Operator18'
   *  Logic: '<S7>/Logical Operator19'
   *  Logic: '<S7>/Logical Operator20'
   *  Logic: '<S7>/Logical Operator21'
   *  Logic: '<S7>/Logical Operator23'
   *  MATLABSystem: '<S7>/Digital Input'
   *  MATLABSystem: '<S7>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(LogicalOperator1 && (rowIdx_tmp &&
    rowIdx_tmp_3)) << 1) + (uint32_T)(int8_T)(rowIdx_tmp_4 ^ (int8_T)c_value)) <<
                      1) + CONTROL_SYSTEM_V3_k_B.Memory);
  CONTROL_SYSTEM_V3_k_B.Logic[0U] = CONTROL_SYSTEM_V3_k_P.Logic_table[(uint32_T)
    rowIdx];
  CONTROL_SYSTEM_V3_k_B.Logic[1U] = CONTROL_SYSTEM_V3_k_P.Logic_table[(uint32_T)
    rowIdx + 8U];

  /* MATLABSystem: '<S2>/Digital Output' */
  writeDigitalPin(27, (uint8_T)CONTROL_SYSTEM_V3_k_B.Logic[0]);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* Memory: '<S36>/Memory' */
    CONTROL_SYSTEM_V3_k_B.Memory_h =
      CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_j;

    /* Memory: '<S37>/Memory' */
    CONTROL_SYSTEM_V3_k_B.Memory_c =
      CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_b;
  }

  /* Logic: '<S7>/Logical Operator32' incorporates:
   *  Logic: '<S7>/Logical Operator24'
   *  Logic: '<S7>/Logical Operator40'
   *  MATLABSystem: '<S7>/Digital Input'
   * */
  rowIdx_tmp_1 = !LogicalOperator1;

  /* CombinatorialLogic: '<S36>/Logic' incorporates:
   *  Logic: '<S7>/Logical Operator32'
   *  Logic: '<S7>/Logical Operator34'
   *  Logic: '<S7>/Logical Operator35'
   *  Logic: '<S7>/Logical Operator36'
   *  Logic: '<S7>/Logical Operator37'
   *  Logic: '<S7>/Logical Operator39'
   *  MATLABSystem: '<S7>/Digital Input'
   *  MATLABSystem: '<S7>/Digital Input1'
   *  MATLABSystem: '<S7>/Digital Input2'
   *  MATLABSystem: '<S7>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_0 && (rowIdx_tmp_1 && (rowIdx_tmp &&
    rowIdx_tmp_0))) << 1) + (uint32_T)(int8_T)((int8_T)((int8_T)c_value ^
    (int8_T)c_value_1) ^ (int8_T)LogicalOperator1)) << 1) +
                     CONTROL_SYSTEM_V3_k_B.Memory_h);
  CONTROL_SYSTEM_V3_k_B.Logic_h[0U] = CONTROL_SYSTEM_V3_k_P.Logic_table_k
    [(uint32_T)rowIdx];
  CONTROL_SYSTEM_V3_k_B.Logic_h[1U] = CONTROL_SYSTEM_V3_k_P.Logic_table_k
    [(uint32_T)rowIdx + 8U];

  /* CombinatorialLogic: '<S37>/Logic' incorporates:
   *  Logic: '<S7>/Logical Operator42'
   *  Logic: '<S7>/Logical Operator43'
   *  Logic: '<S7>/Logical Operator44'
   *  Logic: '<S7>/Logical Operator45'
   *  Logic: '<S7>/Logical Operator47'
   *  MATLABSystem: '<S7>/Digital Input'
   *  MATLABSystem: '<S7>/Digital Input1'
   *  MATLABSystem: '<S7>/Digital Input2'
   *  MATLABSystem: '<S7>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_1 && (rowIdx_tmp_1 && (rowIdx_tmp &&
    rowIdx_tmp_2))) << 1) + (uint32_T)(int8_T)((int8_T)((int8_T)c_value ^
    (int8_T)c_value_0) ^ (int8_T)LogicalOperator1)) << 1) +
                     CONTROL_SYSTEM_V3_k_B.Memory_c);
  CONTROL_SYSTEM_V3_k_B.Logic_d[0U] = CONTROL_SYSTEM_V3_k_P.Logic_table_p
    [(uint32_T)rowIdx];
  CONTROL_SYSTEM_V3_k_B.Logic_d[1U] = CONTROL_SYSTEM_V3_k_P.Logic_table_p
    [(uint32_T)rowIdx + 8U];

  /* MATLABSystem: '<S1>/MATLAB System' */
  if (CONTROL_SYSTEM_V3_k_DW.obj.SampleTime !=
      CONTROL_SYSTEM_V3_k_P.MATLABSystem_SampleTime) {
    CONTROL_SYSTEM_V3_k_DW.obj.SampleTime =
      CONTROL_SYSTEM_V3_k_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  rtb_Error = 0.0;
  b_varargout_2 = 0.0;
  b_varargout_3 = 0.0;
  b_varargout_4 = 0.0;
  stepFunctionADS1115_Vread(&rtb_Error, 1.0, &b_varargout_2, 1.0, &b_varargout_3,
    1.0, &b_varargout_4, 1.0);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* MATLAB Function: '<Root>/Foot Pedal Calibration' incorporates:
     *  MATLABSystem: '<S1>/MATLAB System'
     * */
    if (b_varargout_3 > CONTROL_SYSTEM_V3_k_DW.maxSet) {
      CONTROL_SYSTEM_V3_k_DW.maxSet = b_varargout_3;
    }

    if (b_varargout_3 < CONTROL_SYSTEM_V3_k_DW.minSet) {
      CONTROL_SYSTEM_V3_k_DW.minSet = b_varargout_3;
    }

    rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_DW.maxSet;
    CONTROL_SYSTEM_V3_k_B.FP_minVal = CONTROL_SYSTEM_V3_k_DW.minSet;

    /* MATLAB Function: '<Root>/Throttle Body Callibration' incorporates:
     *  MATLABSystem: '<S1>/MATLAB System'
     * */
    if (b_varargout_2 > CONTROL_SYSTEM_V3_k_DW.TB_maxSet) {
      CONTROL_SYSTEM_V3_k_DW.TB_maxSet = b_varargout_2;
    }

    if (b_varargout_2 < CONTROL_SYSTEM_V3_k_DW.TB_minSet) {
      CONTROL_SYSTEM_V3_k_DW.TB_minSet = b_varargout_2;
    }

    CONTROL_SYSTEM_V3_k_B.TB_minVal = CONTROL_SYSTEM_V3_k_DW.TB_minSet;

    /* Product: '<S12>/Divide1' incorporates:
     *  MATLAB Function: '<Root>/Foot Pedal Calibration'
     *  MATLAB Function: '<Root>/Throttle Body Callibration'
     *  Sum: '<S12>/Add2'
     *  Sum: '<S12>/Add3'
     */
    CONTROL_SYSTEM_V3_k_B.Divide1 = (CONTROL_SYSTEM_V3_k_DW.maxSet -
      CONTROL_SYSTEM_V3_k_B.FP_minVal) / (CONTROL_SYSTEM_V3_k_DW.TB_maxSet -
      CONTROL_SYSTEM_V3_k_B.TB_minVal);
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  MATLABSystem: '<S1>/MATLAB System'
   *  Product: '<S12>/Product1'
   *  Sum: '<S12>/Subtract'
   *  Sum: '<S12>/Sum'
   * */
  rtb_Error = b_varargout_3 - ((b_varargout_2 - CONTROL_SYSTEM_V3_k_B.TB_minVal)
    * CONTROL_SYSTEM_V3_k_B.Divide1 + CONTROL_SYSTEM_V3_k_B.FP_minVal);

  /* If: '<Root>/If Condition' */
  rtPrevAction = CONTROL_SYSTEM_V3_k_DW.IfCondition_ActiveSubsystem;
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_k_M->solverInfo)) {
    if (CONTROL_SYSTEM_V3_k_B.Logic[0]) {
      rtAction = 0;
    } else if (CONTROL_SYSTEM_V3_k_B.Logic_h[0]) {
      rtAction = 1;
    } else if (CONTROL_SYSTEM_V3_k_B.Logic_d[0]) {
      rtAction = 2;
    }

    CONTROL_SYSTEM_V3_k_DW.IfCondition_ActiveSubsystem = rtAction;
  } else {
    rtAction = CONTROL_SYSTEM_V3_k_DW.IfCondition_ActiveSubsystem;
  }

  if (rtPrevAction != rtAction) {
    if (CONTROL_SYSTEM_V3_k_M->Timing.t[0] == rtmGetTStart(CONTROL_SYSTEM_V3_k_M))
    {
      (void) memset(&(CONTROL_SYSTEM_V3_k_XDis.Integrator_CSTATE), 1,
                    2*sizeof(boolean_T));
    }

    if (rtPrevAction == 1) {
      (void) memset(&(CONTROL_SYSTEM_V3_k_XDis.Integrator_CSTATE), 1,
                    2*sizeof(boolean_T));
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/Propotional' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* SignalConversion generated from: '<S10>/Error' */
    CONTROL_SYSTEM_V3_k_B.Error = rtb_Error;

    /* End of Outputs for SubSystem: '<Root>/Propotional' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<Root>/PID Control' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Enable for If: '<Root>/If Condition' */
      (void) memset(&(CONTROL_SYSTEM_V3_k_XDis.Integrator_CSTATE), 0,
                    2*sizeof(boolean_T));

      /* End of Enable for SubSystem: '<Root>/PID Control' */
    }

    /* Outputs for IfAction SubSystem: '<Root>/PID Control' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
      /* Sum: '<S9>/Sum1' incorporates:
       *  Constant: '<S9>/Constant'
       */
      CONTROL_SYSTEM_V3_k_B.Sum1 = CONTROL_SYSTEM_V3_k_P.Constant_Value +
        rtb_FP_maxVal;
    }

    /* Gain: '<S76>/Filter Coefficient' incorporates:
     *  Gain: '<S66>/Derivative Gain'
     *  Integrator: '<S68>/Filter'
     *  Sum: '<S68>/SumD'
     */
    CONTROL_SYSTEM_V3_k_B.FilterCoefficient = (CONTROL_SYSTEM_V3_k_P.Kd *
      rtb_Error - CONTROL_SYSTEM_V3_k_X.Filter_CSTATE) *
      CONTROL_SYSTEM_V3_k_P.Kn;

    /* Sum: '<S82>/Sum' incorporates:
     *  Gain: '<S78>/Proportional Gain'
     *  Integrator: '<S73>/Integrator'
     */
    CONTROL_SYSTEM_V3_k_B.Switch2 = (CONTROL_SYSTEM_V3_k_P.Kp * rtb_Error +
      CONTROL_SYSTEM_V3_k_X.Integrator_CSTATE) +
      CONTROL_SYSTEM_V3_k_B.FilterCoefficient;

    /* Switch: '<S39>/Switch2' incorporates:
     *  RelationalOperator: '<S39>/LowerRelop1'
     *  RelationalOperator: '<S39>/UpperRelop'
     *  Switch: '<S39>/Switch'
     */
    if (CONTROL_SYSTEM_V3_k_B.Switch2 > CONTROL_SYSTEM_V3_k_B.Sum1) {
      /* Sum: '<S82>/Sum' incorporates:
       *  Switch: '<S39>/Switch2'
       */
      CONTROL_SYSTEM_V3_k_B.Switch2 = CONTROL_SYSTEM_V3_k_B.Sum1;
    } else if (CONTROL_SYSTEM_V3_k_B.Switch2 < CONTROL_SYSTEM_V3_k_B.FP_minVal)
    {
      /* Sum: '<S82>/Sum' incorporates:
       *  Switch: '<S39>/Switch'
       *  Switch: '<S39>/Switch2'
       */
      CONTROL_SYSTEM_V3_k_B.Switch2 = CONTROL_SYSTEM_V3_k_B.FP_minVal;
    }

    /* End of Switch: '<S39>/Switch2' */

    /* Gain: '<S70>/Integral Gain' */
    CONTROL_SYSTEM_V3_k_B.IntegralGain = CONTROL_SYSTEM_V3_k_P.Ki * rtb_Error;

    /* End of Outputs for SubSystem: '<Root>/PID Control' */
    break;

   case 2:
    break;
  }

  /* End of If: '<Root>/If Condition' */

  /* MATLABSystem: '<S2>/Digital Output2' */
  writeDigitalPin(25, (uint8_T)CONTROL_SYSTEM_V3_k_B.Logic_d[0]);

  /* MATLABSystem: '<S2>/Digital Output1' */
  writeDigitalPin(26, (uint8_T)CONTROL_SYSTEM_V3_k_B.Logic_h[0]);
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* Memory: '<S35>/Memory' */
    CONTROL_SYSTEM_V3_k_B.Memory_hc =
      CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_d;
  }

  /* CombinatorialLogic: '<S35>/Logic' incorporates:
   *  Logic: '<S7>/Logical Operator26'
   *  Logic: '<S7>/Logical Operator27'
   *  Logic: '<S7>/Logical Operator28'
   *  MATLABSystem: '<S7>/Digital Input'
   *  MATLABSystem: '<S7>/Digital Input3'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value && (rowIdx_tmp_1 && rowIdx_tmp_3)) <<
                        1) + (uint32_T)(int8_T)(rowIdx_tmp_4 ^ (int8_T)
    LogicalOperator1)) << 1) + CONTROL_SYSTEM_V3_k_B.Memory_hc);
  CONTROL_SYSTEM_V3_k_B.Logic_k[0U] = CONTROL_SYSTEM_V3_k_P.Logic_table_g
    [(uint32_T)rowIdx];
  CONTROL_SYSTEM_V3_k_B.Logic_k[1U] = CONTROL_SYSTEM_V3_k_P.Logic_table_g
    [(uint32_T)rowIdx + 8U];

  /* Clock: '<S15>/Clock' */
  rtb_Error = CONTROL_SYSTEM_V3_k_M->Timing.t[0];
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* RelationalOperator: '<S15>/Relational Operator1' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant2'
     */
    CONTROL_SYSTEM_V3_k_B.RelationalOperator1 =
      (CONTROL_SYSTEM_V3_k_P.OnDelay_DelayType ==
       CONTROL_SYSTEM_V3_k_P.Constant_Value_j);

    /* Outputs for Enabled SubSystem: '<S15>/ON Delay' incorporates:
     *  EnablePort: '<S17>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_k_M->solverInfo)) {
      if (CONTROL_SYSTEM_V3_k_B.RelationalOperator1) {
        CONTROL_SYSTEM_V3_k_DW.ONDelay_MODE = true;
      } else if (CONTROL_SYSTEM_V3_k_DW.ONDelay_MODE) {
        /* Disable for Enabled SubSystem: '<S28>/POSITIVE Edge' */
        if (CONTROL_SYSTEM_V3_k_DW.POSITIVEEdge_n.POSITIVEEdge_MODE) {
          CONTROL_SY_POSITIVEEdge_Disable(&CONTROL_SYSTEM_V3_k_DW.POSITIVEEdge_n);
        }

        /* End of Disable for SubSystem: '<S28>/POSITIVE Edge' */

        /* Disable for Enabled SubSystem: '<S28>/NEGATIVE Edge' */
        if (CONTROL_SYSTEM_V3_k_DW.NEGATIVEEdge_c.NEGATIVEEdge_MODE) {
          CONTROL_SY_NEGATIVEEdge_Disable(&CONTROL_SYSTEM_V3_k_DW.NEGATIVEEdge_c);
        }

        /* End of Disable for SubSystem: '<S28>/NEGATIVE Edge' */
        CONTROL_SYSTEM_V3_k_DW.ONDelay_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S15>/ON Delay' */
  }

  /* Outputs for Enabled SubSystem: '<S15>/ON Delay' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (CONTROL_SYSTEM_V3_k_DW.ONDelay_MODE) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
      /* MultiPortSwitch: '<S28>/Multiport Switch' incorporates:
       *  Constant: '<S28>/Constant1'
       */
      switch ((int32_T)CONTROL_SYSTEM_V3_k_P.EdgeDetector_model_g) {
       case 1:
        /* MultiPortSwitch: '<S28>/Multiport Switch' incorporates:
         *  Constant: '<S28>/pos. edge'
         */
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch[0] =
          CONTROL_SYSTEM_V3_k_P.posedge_Value_d[0];
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch[1] =
          CONTROL_SYSTEM_V3_k_P.posedge_Value_d[1];
        break;

       case 2:
        /* MultiPortSwitch: '<S28>/Multiport Switch' incorporates:
         *  Constant: '<S28>/neg. edge'
         */
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch[0] =
          CONTROL_SYSTEM_V3_k_P.negedge_Value_f[0];
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch[1] =
          CONTROL_SYSTEM_V3_k_P.negedge_Value_f[1];
        break;

       default:
        /* MultiPortSwitch: '<S28>/Multiport Switch' incorporates:
         *  Constant: '<S28>/either edge'
         */
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch[0] =
          CONTROL_SYSTEM_V3_k_P.eitheredge_Value_b[0];
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch[1] =
          CONTROL_SYSTEM_V3_k_P.eitheredge_Value_b[1];
        break;
      }

      /* End of MultiPortSwitch: '<S28>/Multiport Switch' */

      /* Memory: '<S28>/Memory' */
      CONTROL_SYSTEM_V3_k_B.Memory_i =
        CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_p;
    }

    /* Outputs for Enabled SubSystem: '<S28>/POSITIVE Edge' */
    CONTROL_SYSTEM_V3__POSITIVEEdge(CONTROL_SYSTEM_V3_k_M,
      CONTROL_SYSTEM_V3_k_B.MultiportSwitch[0], CONTROL_SYSTEM_V3_k_B.Logic_k[0],
      CONTROL_SYSTEM_V3_k_B.Memory_i,
      &CONTROL_SYSTEM_V3_k_B.RelationalOperator1_j,
      &CONTROL_SYSTEM_V3_k_DW.POSITIVEEdge_n);

    /* End of Outputs for SubSystem: '<S28>/POSITIVE Edge' */

    /* Outputs for Enabled SubSystem: '<S28>/NEGATIVE Edge' */
    CONTROL_SYSTEM_V3__NEGATIVEEdge(CONTROL_SYSTEM_V3_k_M,
      CONTROL_SYSTEM_V3_k_B.MultiportSwitch[1], CONTROL_SYSTEM_V3_k_B.Logic_k[0],
      CONTROL_SYSTEM_V3_k_B.Memory_i,
      &CONTROL_SYSTEM_V3_k_B.RelationalOperator1_m,
      &CONTROL_SYSTEM_V3_k_DW.NEGATIVEEdge_c);

    /* End of Outputs for SubSystem: '<S28>/NEGATIVE Edge' */

    /* Logic: '<S28>/Logical Operator1' */
    LogicalOperator1 = (CONTROL_SYSTEM_V3_k_B.RelationalOperator1_j ||
                        CONTROL_SYSTEM_V3_k_B.RelationalOperator1_m);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
      /* Memory: '<S33>/IC=ic' */
      CONTROL_SYSTEM_V3_k_B.ICic = CONTROL_SYSTEM_V3_k_DW.ICic_PreviousInput;
    }

    /* Switch: '<S33>/Switch' */
    if (LogicalOperator1) {
      /* Switch: '<S33>/Switch' */
      CONTROL_SYSTEM_V3_k_B.Switch = rtb_Error;
    } else {
      /* Switch: '<S33>/Switch' */
      CONTROL_SYSTEM_V3_k_B.Switch = CONTROL_SYSTEM_V3_k_B.ICic;
    }

    /* End of Switch: '<S33>/Switch' */

    /* Logic: '<S17>/Logical Operator2' incorporates:
     *  Constant: '<S15>/Constant1'
     *  RelationalOperator: '<S17>/Relational Operator'
     *  Sum: '<S17>/Sum'
     */
    CONTROL_SYSTEM_V3_k_B.LogicalOperator2_h = ((rtb_Error >=
      CONTROL_SYSTEM_V3_k_B.Switch + CONTROL_SYSTEM_V3_k_P.OnDelay_delay) &&
      CONTROL_SYSTEM_V3_k_B.Logic_k[0]);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
      /* Outputs for Triggered SubSystem: '<S29>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S32>/Trigger'
       */
      if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_k_M->solverInfo)) {
        CONTROL_SYSTEM_V3_k_PrevZCX.TriggeredSubsystem_Trig_ZCE =
          LogicalOperator1;
      }

      /* End of Outputs for SubSystem: '<S29>/Triggered Subsystem' */
    }
  }

  /* End of Outputs for SubSystem: '<S15>/ON Delay' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* Outputs for Enabled SubSystem: '<S15>/OFF Delay' incorporates:
     *  EnablePort: '<S16>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_k_M->solverInfo)) {
      /* Logic: '<S15>/Logical Operator2' */
      if (!CONTROL_SYSTEM_V3_k_B.RelationalOperator1) {
        CONTROL_SYSTEM_V3_k_DW.OFFDelay_MODE = true;
      } else if (CONTROL_SYSTEM_V3_k_DW.OFFDelay_MODE) {
        /* Disable for Enabled SubSystem: '<S20>/POSITIVE Edge' */
        if (CONTROL_SYSTEM_V3_k_DW.POSITIVEEdge.POSITIVEEdge_MODE) {
          CONTROL_SY_POSITIVEEdge_Disable(&CONTROL_SYSTEM_V3_k_DW.POSITIVEEdge);
        }

        /* End of Disable for SubSystem: '<S20>/POSITIVE Edge' */

        /* Disable for Enabled SubSystem: '<S20>/NEGATIVE Edge' */
        if (CONTROL_SYSTEM_V3_k_DW.NEGATIVEEdge.NEGATIVEEdge_MODE) {
          CONTROL_SY_NEGATIVEEdge_Disable(&CONTROL_SYSTEM_V3_k_DW.NEGATIVEEdge);
        }

        /* End of Disable for SubSystem: '<S20>/NEGATIVE Edge' */
        CONTROL_SYSTEM_V3_k_DW.OFFDelay_MODE = false;
      }

      /* End of Logic: '<S15>/Logical Operator2' */
    }

    /* End of Outputs for SubSystem: '<S15>/OFF Delay' */
  }

  /* Outputs for Enabled SubSystem: '<S15>/OFF Delay' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (CONTROL_SYSTEM_V3_k_DW.OFFDelay_MODE) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
      /* MultiPortSwitch: '<S20>/Multiport Switch' incorporates:
       *  Constant: '<S20>/Constant1'
       */
      switch ((int32_T)CONTROL_SYSTEM_V3_k_P.EdgeDetector_model) {
       case 1:
        /* MultiPortSwitch: '<S20>/Multiport Switch' incorporates:
         *  Constant: '<S20>/pos. edge'
         */
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch_k[0] =
          CONTROL_SYSTEM_V3_k_P.posedge_Value[0];
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch_k[1] =
          CONTROL_SYSTEM_V3_k_P.posedge_Value[1];
        break;

       case 2:
        /* MultiPortSwitch: '<S20>/Multiport Switch' incorporates:
         *  Constant: '<S20>/neg. edge'
         */
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch_k[0] =
          CONTROL_SYSTEM_V3_k_P.negedge_Value[0];
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch_k[1] =
          CONTROL_SYSTEM_V3_k_P.negedge_Value[1];
        break;

       default:
        /* MultiPortSwitch: '<S20>/Multiport Switch' incorporates:
         *  Constant: '<S20>/either edge'
         */
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch_k[0] =
          CONTROL_SYSTEM_V3_k_P.eitheredge_Value[0];
        CONTROL_SYSTEM_V3_k_B.MultiportSwitch_k[1] =
          CONTROL_SYSTEM_V3_k_P.eitheredge_Value[1];
        break;
      }

      /* End of MultiPortSwitch: '<S20>/Multiport Switch' */

      /* Memory: '<S20>/Memory' */
      CONTROL_SYSTEM_V3_k_B.Memory_n =
        CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_ds;
    }

    /* Outputs for Enabled SubSystem: '<S20>/POSITIVE Edge' */
    CONTROL_SYSTEM_V3__POSITIVEEdge(CONTROL_SYSTEM_V3_k_M,
      CONTROL_SYSTEM_V3_k_B.MultiportSwitch_k[0], CONTROL_SYSTEM_V3_k_B.Logic_k
      [0], CONTROL_SYSTEM_V3_k_B.Memory_n,
      &CONTROL_SYSTEM_V3_k_B.RelationalOperator1_f,
      &CONTROL_SYSTEM_V3_k_DW.POSITIVEEdge);

    /* End of Outputs for SubSystem: '<S20>/POSITIVE Edge' */

    /* Outputs for Enabled SubSystem: '<S20>/NEGATIVE Edge' */
    CONTROL_SYSTEM_V3__NEGATIVEEdge(CONTROL_SYSTEM_V3_k_M,
      CONTROL_SYSTEM_V3_k_B.MultiportSwitch_k[1], CONTROL_SYSTEM_V3_k_B.Logic_k
      [0], CONTROL_SYSTEM_V3_k_B.Memory_n,
      &CONTROL_SYSTEM_V3_k_B.RelationalOperator1_h,
      &CONTROL_SYSTEM_V3_k_DW.NEGATIVEEdge);

    /* End of Outputs for SubSystem: '<S20>/NEGATIVE Edge' */

    /* Logic: '<S20>/Logical Operator1' */
    LogicalOperator1 = (CONTROL_SYSTEM_V3_k_B.RelationalOperator1_f ||
                        CONTROL_SYSTEM_V3_k_B.RelationalOperator1_h);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
      /* Memory: '<S25>/IC=ic' */
      CONTROL_SYSTEM_V3_k_B.ICic_h = CONTROL_SYSTEM_V3_k_DW.ICic_PreviousInput_i;
    }

    /* Switch: '<S25>/Switch' */
    if (LogicalOperator1) {
      /* Switch: '<S25>/Switch' */
      CONTROL_SYSTEM_V3_k_B.Switch_i = rtb_Error;
    } else {
      /* Switch: '<S25>/Switch' */
      CONTROL_SYSTEM_V3_k_B.Switch_i = CONTROL_SYSTEM_V3_k_B.ICic_h;
    }

    /* End of Switch: '<S25>/Switch' */

    /* Logic: '<S16>/Logical Operator2' incorporates:
     *  Constant: '<S15>/Constant1'
     *  Logic: '<S16>/Logical Operator'
     *  Logic: '<S16>/Logical Operator1'
     *  RelationalOperator: '<S16>/Relational Operator'
     *  Sum: '<S16>/Sum'
     */
    CONTROL_SYSTEM_V3_k_B.LogicalOperator2_m = ((!(rtb_Error >=
      CONTROL_SYSTEM_V3_k_B.Switch_i + CONTROL_SYSTEM_V3_k_P.OnDelay_delay)) ||
      CONTROL_SYSTEM_V3_k_B.Logic_k[0]);
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
      /* Outputs for Triggered SubSystem: '<S21>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S24>/Trigger'
       */
      if (rtsiIsModeUpdateTimeStep(&CONTROL_SYSTEM_V3_k_M->solverInfo)) {
        CONTROL_SYSTEM_V3_k_PrevZCX.TriggeredSubsystem_Trig_ZCE_i =
          LogicalOperator1;
      }

      /* End of Outputs for SubSystem: '<S21>/Triggered Subsystem' */
    }
  }

  /* End of Outputs for SubSystem: '<S15>/OFF Delay' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* Product: '<S4>/Divide1' incorporates:
     *  Constant: '<S4>/Desire Max Value'
     *  Constant: '<S4>/Desire Min Value'
     *  Sum: '<S4>/Add2'
     *  Sum: '<S4>/Add3'
     */
    CONTROL_SYSTEM_V3_k_B.Divide1_p = (CONTROL_SYSTEM_V3_k_P.Desire_Max -
      CONTROL_SYSTEM_V3_k_P.Desire_Min) / (rtb_FP_maxVal -
      CONTROL_SYSTEM_V3_k_B.FP_minVal);
  }

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S6>/Constant'
   *  Logic: '<S15>/Logical Operator1'
   *  Switch: '<S6>/Switch1'
   */
  if (CONTROL_SYSTEM_V3_k_B.LogicalOperator2_h ||
      CONTROL_SYSTEM_V3_k_B.LogicalOperator2_m) {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_P.Constant_Value_jl;
  } else if (CONTROL_SYSTEM_V3_k_B.Logic_k[0]) {
    /* Switch: '<S6>/Switch1' incorporates:
     *  Gain: '<S6>/Gain'
     */
    rtb_FP_maxVal = (real_T)(CONTROL_SYSTEM_V3_k_B.Logic_k[0] ? (int32_T)
      CONTROL_SYSTEM_V3_k_P.Gain_Gain : 0) * 0.5;
  } else {
    /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
     *  Gain: '<S8>/Multiply'
     *  Gain: '<S8>/Multiply1'
     *  Gain: '<S8>/Multiply2'
     *  Sum: '<S8>/Add'
     *  Switch: '<S6>/Switch1'
     */
    switch ((uint8_T)(((((uint32_T)(CONTROL_SYSTEM_V3_k_B.Logic_h[0] ? (int32_T)
      CONTROL_SYSTEM_V3_k_P.Multiply1_Gain : 0) << 1) + (uint32_T)
                        (CONTROL_SYSTEM_V3_k_B.Logic[0] ? (int32_T)
                         CONTROL_SYSTEM_V3_k_P.Multiply_Gain : 0)) + ((uint32_T)
               (CONTROL_SYSTEM_V3_k_B.Logic_d[0] ? (int32_T)
                CONTROL_SYSTEM_V3_k_P.Multiply2_Gain : 0) << 1)) >> 1) >> 6) {
     case 1:
      rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_B.Error;
      break;

     case 2:
      rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_B.Switch2;
      break;

     default:
      rtb_FP_maxVal = 0.0;
      break;
    }

    /* End of MultiPortSwitch: '<S8>/Multiport Switch' */

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S4>/Desire Min Value'
     *  Product: '<S4>/Product1'
     *  Sum: '<S4>/Subtract'
     *  Sum: '<S4>/Sum'
     */
    rtb_FP_maxVal = (rtb_FP_maxVal - CONTROL_SYSTEM_V3_k_B.FP_minVal) *
      CONTROL_SYSTEM_V3_k_B.Divide1_p + CONTROL_SYSTEM_V3_k_P.Desire_Min;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Start for MATLABSystem: '<S6>/PWM' */
  if (!(rtb_FP_maxVal <= 255.0)) {
    rtb_FP_maxVal = 255.0;
  }

  /* MATLABSystem: '<S6>/PWM' */
  CONTROL_SYSTEM_V3_k_DW.obj_mm.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);

  /* Start for MATLABSystem: '<S6>/PWM' */
  if (!(rtb_FP_maxVal >= 0.0)) {
    rtb_FP_maxVal = 0.0;
  }

  /* MATLABSystem: '<S6>/PWM' */
  MW_PWM_SetDutyCycle(CONTROL_SYSTEM_V3_k_DW.obj_mm.PWMDriverObj.MW_PWM_HANDLE,
                      -(rtb_FP_maxVal * 255.0 / 255.0));
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
    CONTROL_SYSTEM_V3_k_B.PulseGenerator =
      (CONTROL_SYSTEM_V3_k_DW.clockTickCounter <
       CONTROL_SYSTEM_V3_k_P.PulseGenerator_Duty) &&
      (CONTROL_SYSTEM_V3_k_DW.clockTickCounter >= 0) ?
      CONTROL_SYSTEM_V3_k_P.PulseGenerator_Amp : 0.0;

    /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
    if (CONTROL_SYSTEM_V3_k_DW.clockTickCounter >=
        CONTROL_SYSTEM_V3_k_P.PulseGenerator_Period - 1.0) {
      CONTROL_SYSTEM_V3_k_DW.clockTickCounter = 0;
    } else {
      CONTROL_SYSTEM_V3_k_DW.clockTickCounter++;
    }
  }

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (CONTROL_SYSTEM_V3_k_B.Logic_k[0]) {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_B.PulseGenerator;
  } else {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_P.Constant_Value_i;
  }

  /* MATLABSystem: '<S2>/Digital Output3' incorporates:
   *  Switch: '<S2>/Switch'
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

  /* End of MATLABSystem: '<S2>/Digital Output3' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* DiscretePulseGenerator: '<S3>/Pulse Generator' */
    CONTROL_SYSTEM_V3_k_B.PulseGenerator_f =
      (CONTROL_SYSTEM_V3_k_DW.clockTickCounter_j <
       CONTROL_SYSTEM_V3_k_P.PulseGenerator_Duty_e) &&
      (CONTROL_SYSTEM_V3_k_DW.clockTickCounter_j >= 0) ?
      CONTROL_SYSTEM_V3_k_P.PulseGenerator_Amp_b : 0.0;

    /* DiscretePulseGenerator: '<S3>/Pulse Generator' */
    if (CONTROL_SYSTEM_V3_k_DW.clockTickCounter_j >=
        CONTROL_SYSTEM_V3_k_P.PulseGenerator_Period_l - 1.0) {
      CONTROL_SYSTEM_V3_k_DW.clockTickCounter_j = 0;
    } else {
      CONTROL_SYSTEM_V3_k_DW.clockTickCounter_j++;
    }
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  MATLABSystem: '<S1>/MATLAB System'
   * */
  if (b_varargout_2 > CONTROL_SYSTEM_V3_k_P.Switch_Threshold) {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_P.Constant_Value_d;
  } else {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_P.Constant1_Value;
  }

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  MATLABSystem: '<S1>/MATLAB System'
   * */
  if (b_varargout_3 > CONTROL_SYSTEM_V3_k_P.Switch2_Threshold) {
    b_varargout_2 = CONTROL_SYSTEM_V3_k_P.Constant2_Value;
  } else {
    b_varargout_2 = CONTROL_SYSTEM_V3_k_P.Constant3_Value;
  }

  /* Switch: '<S3>/Switch3' incorporates:
   *  Constant: '<S3>/Constant4'
   *  Logic: '<S3>/OR'
   *  Switch: '<S3>/Switch'
   *  Switch: '<S3>/Switch2'
   */
  if ((!(rtb_FP_maxVal != 0.0)) || (!(b_varargout_2 != 0.0))) {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_B.PulseGenerator_f;
  } else {
    rtb_FP_maxVal = CONTROL_SYSTEM_V3_k_P.Constant4_Value;
  }

  /* MATLABSystem: '<S3>/Digital Output4' incorporates:
   *  Switch: '<S3>/Switch3'
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

  /* End of MATLABSystem: '<S3>/Digital Output4' */
  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    /* MATLABSystem: '<S6>/Digital Output' incorporates:
     *  Constant: '<S6>/Enable Pin'
     */
    rtb_FP_maxVal = rt_roundd_snf(CONTROL_SYSTEM_V3_k_P.EN_Pin);
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

    /* End of MATLABSystem: '<S6>/Digital Output' */

    /* MATLABSystem: '<S6>/Digital Output1' incorporates:
     *  Constant: '<S6>/Direction Pin'
     */
    rtb_FP_maxVal = rt_roundd_snf(CONTROL_SYSTEM_V3_k_P.Direction_Pin);
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

    /* End of MATLABSystem: '<S6>/Digital Output1' */
  }

  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
      /* Update for Memory: '<S34>/Memory' */
      CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput = CONTROL_SYSTEM_V3_k_B.Logic
        [0];

      /* Update for Memory: '<S36>/Memory' */
      CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_j =
        CONTROL_SYSTEM_V3_k_B.Logic_h[0];

      /* Update for Memory: '<S37>/Memory' */
      CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_b =
        CONTROL_SYSTEM_V3_k_B.Logic_d[0];

      /* Update for Memory: '<S35>/Memory' */
      CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_d =
        CONTROL_SYSTEM_V3_k_B.Logic_k[0];
    }

    /* Update for Enabled SubSystem: '<S15>/ON Delay' incorporates:
     *  EnablePort: '<S17>/Enable'
     */
    if (CONTROL_SYSTEM_V3_k_DW.ONDelay_MODE && rtmIsMajorTimeStep
        (CONTROL_SYSTEM_V3_k_M)) {
      /* Update for Memory: '<S28>/Memory' */
      CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_p =
        CONTROL_SYSTEM_V3_k_B.Logic_k[0];

      /* Update for Memory: '<S33>/IC=ic' */
      CONTROL_SYSTEM_V3_k_DW.ICic_PreviousInput = CONTROL_SYSTEM_V3_k_B.Switch;
    }

    /* End of Update for SubSystem: '<S15>/ON Delay' */

    /* Update for Enabled SubSystem: '<S15>/OFF Delay' incorporates:
     *  EnablePort: '<S16>/Enable'
     */
    if (CONTROL_SYSTEM_V3_k_DW.OFFDelay_MODE && rtmIsMajorTimeStep
        (CONTROL_SYSTEM_V3_k_M)) {
      /* Update for Memory: '<S20>/Memory' */
      CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_ds =
        CONTROL_SYSTEM_V3_k_B.Logic_k[0];

      /* Update for Memory: '<S25>/IC=ic' */
      CONTROL_SYSTEM_V3_k_DW.ICic_PreviousInput_i =
        CONTROL_SYSTEM_V3_k_B.Switch_i;
    }

    /* End of Update for SubSystem: '<S15>/OFF Delay' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(CONTROL_SYSTEM_V3_k_M)) {
    rt_ertODEUpdateContinuousStates(&CONTROL_SYSTEM_V3_k_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++CONTROL_SYSTEM_V3_k_M->Timing.clockTick0;
    CONTROL_SYSTEM_V3_k_M->Timing.t[0] = rtsiGetSolverStopTime
      (&CONTROL_SYSTEM_V3_k_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      CONTROL_SYSTEM_V3_k_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void CONTROL_SYSTEM_V3_k_derivatives(void)
{
  XDot_CONTROL_SYSTEM_V3_k_T *_rtXdot;
  _rtXdot = ((XDot_CONTROL_SYSTEM_V3_k_T *) CONTROL_SYSTEM_V3_k_M->derivs);

  /* Derivatives for If: '<Root>/If Condition' */
  {
    real_T *dx;
    int_T i1;
    dx = &(((XDot_CONTROL_SYSTEM_V3_k_T *) CONTROL_SYSTEM_V3_k_M->derivs)
           ->Integrator_CSTATE);
    for (i1=0; i1 < 2; i1++) {
      dx[i1] = 0.0;
    }
  }

  if (CONTROL_SYSTEM_V3_k_DW.IfCondition_ActiveSubsystem == 1) {
    /* Derivatives for IfAction SubSystem: '<Root>/PID Control' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Derivatives for Integrator: '<S73>/Integrator' */
    _rtXdot->Integrator_CSTATE = CONTROL_SYSTEM_V3_k_B.IntegralGain;

    /* Derivatives for Integrator: '<S68>/Filter' */
    _rtXdot->Filter_CSTATE = CONTROL_SYSTEM_V3_k_B.FilterCoefficient;

    /* End of Derivatives for SubSystem: '<Root>/PID Control' */
  }

  /* End of Derivatives for If: '<Root>/If Condition' */
}

/* Model initialize function */
void CONTROL_SYSTEM_V3_k_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo,
                          &CONTROL_SYSTEM_V3_k_M->Timing.simTimeStep);
    rtsiSetTPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo, &rtmGetTPtr
                (CONTROL_SYSTEM_V3_k_M));
    rtsiSetStepSizePtr(&CONTROL_SYSTEM_V3_k_M->solverInfo,
                       &CONTROL_SYSTEM_V3_k_M->Timing.stepSize0);
    rtsiSetdXPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo,
                 &CONTROL_SYSTEM_V3_k_M->derivs);
    rtsiSetContStatesPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo, (real_T **)
                         &CONTROL_SYSTEM_V3_k_M->contStates);
    rtsiSetNumContStatesPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo,
      &CONTROL_SYSTEM_V3_k_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo,
      &CONTROL_SYSTEM_V3_k_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo,
      &CONTROL_SYSTEM_V3_k_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo,
      &CONTROL_SYSTEM_V3_k_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo, (boolean_T**)
      &CONTROL_SYSTEM_V3_k_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo,
                          (&rtmGetErrorStatus(CONTROL_SYSTEM_V3_k_M)));
    rtsiSetRTModelPtr(&CONTROL_SYSTEM_V3_k_M->solverInfo, CONTROL_SYSTEM_V3_k_M);
  }

  rtsiSetSimTimeStep(&CONTROL_SYSTEM_V3_k_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&CONTROL_SYSTEM_V3_k_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&CONTROL_SYSTEM_V3_k_M->solverInfo, false);
  CONTROL_SYSTEM_V3_k_M->intgData.f[0] = CONTROL_SYSTEM_V3_k_M->odeF[0];
  CONTROL_SYSTEM_V3_k_M->contStates = ((X_CONTROL_SYSTEM_V3_k_T *)
    &CONTROL_SYSTEM_V3_k_X);
  CONTROL_SYSTEM_V3_k_M->contStateDisabled = ((XDis_CONTROL_SYSTEM_V3_k_T *)
    &CONTROL_SYSTEM_V3_k_XDis);
  CONTROL_SYSTEM_V3_k_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&CONTROL_SYSTEM_V3_k_M->solverInfo, (void *)
                    &CONTROL_SYSTEM_V3_k_M->intgData);
  rtsiSetSolverName(&CONTROL_SYSTEM_V3_k_M->solverInfo,"ode1");
  rtmSetTPtr(CONTROL_SYSTEM_V3_k_M, &CONTROL_SYSTEM_V3_k_M->Timing.tArray[0]);
  CONTROL_SYSTEM_V3_k_M->Timing.stepSize0 = 0.01;

  /* Start for If: '<Root>/If Condition' */
  (void) memset(&(CONTROL_SYSTEM_V3_k_XDis.Integrator_CSTATE), 1,
                2*sizeof(boolean_T));
  CONTROL_SYSTEM_V3_k_DW.IfCondition_ActiveSubsystem = -1;
  CONTROL_SYSTEM_V3_k_PrevZCX.TriggeredSubsystem_Trig_ZCE_i = POS_ZCSIG;
  CONTROL_SYSTEM_V3_k_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for Memory: '<S34>/Memory' */
  CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput =
    CONTROL_SYSTEM_V3_k_P.SRFlipFlop3_initial_condition;

  /* InitializeConditions for Memory: '<S36>/Memory' */
  CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_j =
    CONTROL_SYSTEM_V3_k_P.SRFlipFlop5_initial_condition;

  /* InitializeConditions for Memory: '<S37>/Memory' */
  CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_b =
    CONTROL_SYSTEM_V3_k_P.SRFlipFlop6_initial_condition;

  /* InitializeConditions for Memory: '<S35>/Memory' */
  CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_d =
    CONTROL_SYSTEM_V3_k_P.SRFlipFlop4_initial_condition;

  /* SystemInitialize for MATLAB Function: '<Root>/Foot Pedal Calibration' */
  CONTROL_SYSTEM_V3_k_DW.maxSet = -1.0;
  CONTROL_SYSTEM_V3_k_DW.minSet = 5.0;

  /* SystemInitialize for MATLAB Function: '<Root>/Throttle Body Callibration' */
  CONTROL_SYSTEM_V3_k_DW.TB_maxSet = -1.0;
  CONTROL_SYSTEM_V3_k_DW.TB_minSet = 5.0;

  /* SystemInitialize for IfAction SubSystem: '<Root>/Propotional' */
  /* SystemInitialize for SignalConversion generated from: '<S10>/Error' incorporates:
   *  Outport: '<S10>/Propotional'
   */
  CONTROL_SYSTEM_V3_k_B.Error = CONTROL_SYSTEM_V3_k_P.Propotional_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Propotional' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/PID Control' */
  /* InitializeConditions for Integrator: '<S73>/Integrator' */
  CONTROL_SYSTEM_V3_k_X.Integrator_CSTATE =
    CONTROL_SYSTEM_V3_k_P.PIDController1_InitialConditi_l;

  /* InitializeConditions for Integrator: '<S68>/Filter' */
  CONTROL_SYSTEM_V3_k_X.Filter_CSTATE =
    CONTROL_SYSTEM_V3_k_P.PIDController1_InitialCondition;

  /* SystemInitialize for Sum: '<S82>/Sum' incorporates:
   *  Outport: '<S9>/PID Output'
   *  Switch: '<S39>/Switch2'
   */
  CONTROL_SYSTEM_V3_k_B.Switch2 = CONTROL_SYSTEM_V3_k_P.PIDOutput_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/PID Control' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/ON Delay' */
  /* InitializeConditions for Memory: '<S28>/Memory' */
  CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_p =
    CONTROL_SYSTEM_V3_k_P.OnDelay_ic;

  /* InitializeConditions for Memory: '<S33>/IC=ic' */
  CONTROL_SYSTEM_V3_k_DW.ICic_PreviousInput =
    CONTROL_SYSTEM_V3_k_P.SampleandHold_ic_k;

  /* SystemInitialize for Enabled SubSystem: '<S28>/POSITIVE Edge' */
  CONTROL_SYSTE_POSITIVEEdge_Init(&CONTROL_SYSTEM_V3_k_B.RelationalOperator1_j,
    &CONTROL_SYSTEM_V3_k_P.POSITIVEEdge_n);

  /* End of SystemInitialize for SubSystem: '<S28>/POSITIVE Edge' */

  /* SystemInitialize for Enabled SubSystem: '<S28>/NEGATIVE Edge' */
  CONTROL_SYSTE_NEGATIVEEdge_Init(&CONTROL_SYSTEM_V3_k_B.RelationalOperator1_m,
    &CONTROL_SYSTEM_V3_k_P.NEGATIVEEdge_c);

  /* End of SystemInitialize for SubSystem: '<S28>/NEGATIVE Edge' */

  /* SystemInitialize for Logic: '<S17>/Logical Operator2' incorporates:
   *  Outport: '<S17>/OUT'
   */
  CONTROL_SYSTEM_V3_k_B.LogicalOperator2_h = CONTROL_SYSTEM_V3_k_P.OUT_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S15>/ON Delay' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/OFF Delay' */
  /* InitializeConditions for Memory: '<S20>/Memory' */
  CONTROL_SYSTEM_V3_k_DW.Memory_PreviousInput_ds =
    CONTROL_SYSTEM_V3_k_P.OnDelay_ic;

  /* InitializeConditions for Memory: '<S25>/IC=ic' */
  CONTROL_SYSTEM_V3_k_DW.ICic_PreviousInput_i =
    CONTROL_SYSTEM_V3_k_P.SampleandHold_ic;

  /* SystemInitialize for Enabled SubSystem: '<S20>/POSITIVE Edge' */
  CONTROL_SYSTE_POSITIVEEdge_Init(&CONTROL_SYSTEM_V3_k_B.RelationalOperator1_f,
    &CONTROL_SYSTEM_V3_k_P.POSITIVEEdge);

  /* End of SystemInitialize for SubSystem: '<S20>/POSITIVE Edge' */

  /* SystemInitialize for Enabled SubSystem: '<S20>/NEGATIVE Edge' */
  CONTROL_SYSTE_NEGATIVEEdge_Init(&CONTROL_SYSTEM_V3_k_B.RelationalOperator1_h,
    &CONTROL_SYSTEM_V3_k_P.NEGATIVEEdge);

  /* End of SystemInitialize for SubSystem: '<S20>/NEGATIVE Edge' */

  /* SystemInitialize for Logic: '<S16>/Logical Operator2' incorporates:
   *  Outport: '<S16>/OUT'
   */
  CONTROL_SYSTEM_V3_k_B.LogicalOperator2_m = CONTROL_SYSTEM_V3_k_P.OUT_Y0;

  /* End of SystemInitialize for SubSystem: '<S15>/OFF Delay' */

  /* Start for MATLABSystem: '<S7>/Digital Input' */
  CONTROL_SYSTEM_V3_k_DW.obj_dc.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_dc.SampleTime =
    CONTROL_SYSTEM_V3_k_P.DigitalInput_SampleTime;
  CONTROL_SYSTEM_V3_k_DW.obj_dc.isInitialized = 1;
  digitalIOSetup(36, 0);
  CONTROL_SYSTEM_V3_k_DW.obj_dc.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Digital Input3' */
  CONTROL_SYSTEM_V3_k_DW.obj_m.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_m.SampleTime =
    CONTROL_SYSTEM_V3_k_P.DigitalInput3_SampleTime;
  CONTROL_SYSTEM_V3_k_DW.obj_m.isInitialized = 1;
  digitalIOSetup(35, 0);
  CONTROL_SYSTEM_V3_k_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Digital Input1' */
  CONTROL_SYSTEM_V3_k_DW.obj_e.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_e.SampleTime =
    CONTROL_SYSTEM_V3_k_P.DigitalInput1_SampleTime;
  CONTROL_SYSTEM_V3_k_DW.obj_e.isInitialized = 1;
  digitalIOSetup(39, 0);
  CONTROL_SYSTEM_V3_k_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Digital Input2' */
  CONTROL_SYSTEM_V3_k_DW.obj_d.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_d.SampleTime =
    CONTROL_SYSTEM_V3_k_P.DigitalInput2_SampleTime;
  CONTROL_SYSTEM_V3_k_DW.obj_d.isInitialized = 1;
  digitalIOSetup(34, 0);
  CONTROL_SYSTEM_V3_k_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  CONTROL_SYSTEM_V3_k_DW.obj_b.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_b.isInitialized = 1;
  digitalIOSetup(27, 1);
  CONTROL_SYSTEM_V3_k_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/MATLAB System' */
  /*  Constructor */
  CONTROL_SYSTEM_V3_k_DW.obj.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj.SampleTime =
    CONTROL_SYSTEM_V3_k_P.MATLABSystem_SampleTime;
  CONTROL_SYSTEM_V3_k_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionADS1115_Vread(16, 1.0);
  CONTROL_SYSTEM_V3_k_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output2' */
  CONTROL_SYSTEM_V3_k_DW.obj_cu.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_cu.isInitialized = 1;
  digitalIOSetup(25, 1);
  CONTROL_SYSTEM_V3_k_DW.obj_cu.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output1' */
  CONTROL_SYSTEM_V3_k_DW.obj_i.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_i.isInitialized = 1;
  digitalIOSetup(26, 1);
  CONTROL_SYSTEM_V3_k_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM' */
  CONTROL_SYSTEM_V3_k_DW.obj_mm.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_mm.isInitialized = 1;
  CONTROL_SYSTEM_V3_k_DW.obj_mm.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4U,
    19000.0, 255.0);
  CONTROL_SYSTEM_V3_k_DW.obj_mm.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output3' */
  CONTROL_SYSTEM_V3_k_DW.obj_k.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_k.isInitialized = 1;
  digitalIOSetup(33, 1);
  CONTROL_SYSTEM_V3_k_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output4' */
  CONTROL_SYSTEM_V3_k_DW.obj_g.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_g.isInitialized = 1;
  digitalIOSetup(32, 1);
  CONTROL_SYSTEM_V3_k_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Digital Output' */
  CONTROL_SYSTEM_V3_k_DW.obj_n.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_n.isInitialized = 1;
  digitalIOSetup(0, 1);
  CONTROL_SYSTEM_V3_k_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Digital Output1' */
  CONTROL_SYSTEM_V3_k_DW.obj_c.matlabCodegenIsDeleted = false;
  CONTROL_SYSTEM_V3_k_DW.obj_c.isInitialized = 1;
  digitalIOSetup(16, 1);
  CONTROL_SYSTEM_V3_k_DW.obj_c.isSetupComplete = true;
}

/* Model terminate function */
void CONTROL_SYSTEM_V3_k_terminate(void)
{
  /* Terminate for MATLABSystem: '<S7>/Digital Input' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_dc.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_dc.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Input' */

  /* Terminate for MATLABSystem: '<S7>/Digital Input3' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_m.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Input3' */

  /* Terminate for MATLABSystem: '<S7>/Digital Input1' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_e.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Input1' */

  /* Terminate for MATLABSystem: '<S7>/Digital Input2' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_d.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Input2' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_b.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */

  /* Terminate for MATLABSystem: '<S1>/MATLAB System' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/MATLAB System' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output2' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_cu.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_cu.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output1' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_i.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S6>/PWM' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_mm.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_mm.matlabCodegenIsDeleted = true;
    CONTROL_SYST_SystemCore_release(&CONTROL_SYSTEM_V3_k_DW.obj_mm);
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output3' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_k.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output3' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output4' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_g.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output4' */

  /* Terminate for MATLABSystem: '<S6>/Digital Output' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_n.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Output' */

  /* Terminate for MATLABSystem: '<S6>/Digital Output1' */
  if (!CONTROL_SYSTEM_V3_k_DW.obj_c.matlabCodegenIsDeleted) {
    CONTROL_SYSTEM_V3_k_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
