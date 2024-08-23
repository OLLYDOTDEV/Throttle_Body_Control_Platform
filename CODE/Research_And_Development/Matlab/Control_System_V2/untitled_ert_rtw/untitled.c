/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: untitled.c
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
#include "untitled_types.h"
#include "untitled_private.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Continuous states */
X_untitled_T untitled_X;

/* Disabled State Vector */
XDis_untitled_T untitled_XDis;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_SystemCore_release(codertarget_arduinobase_inter_T *obj);

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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  untitled_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  untitled_step();
  untitled_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  untitled_step();
  untitled_derivatives();

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

static void untitled_SystemCore_release(codertarget_arduinobase_inter_T *obj)
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
void untitled_step(void)
{
  real_T y;
  int32_T rowIdx;
  uint8_T tmp;
  boolean_T c_value;
  boolean_T c_value_0;
  boolean_T c_value_1;
  boolean_T rowIdx_tmp;
  boolean_T rowIdx_tmp_0;
  boolean_T rowIdx_tmp_1;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&untitled_M->solverInfo,
                          ((untitled_M->Timing.clockTick0+1)*
      untitled_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(untitled_M)) {
    untitled_M->Timing.t[0] = rtsiGetT(&untitled_M->solverInfo);
  }

  /* MATLABSystem: '<S6>/Digital Input' */
  if (untitled_DW.obj_do.SampleTime != untitled_P.DigitalInput_SampleTime) {
    untitled_DW.obj_do.SampleTime = untitled_P.DigitalInput_SampleTime;
  }

  c_value = readDigitalPin(39);

  /* MATLABSystem: '<S6>/Digital Input2' */
  if (untitled_DW.obj_d.SampleTime != untitled_P.DigitalInput2_SampleTime) {
    untitled_DW.obj_d.SampleTime = untitled_P.DigitalInput2_SampleTime;
  }

  c_value_0 = readDigitalPin(36);

  /* MATLABSystem: '<S6>/Digital Input1' */
  if (untitled_DW.obj_m.SampleTime != untitled_P.DigitalInput1_SampleTime) {
    untitled_DW.obj_m.SampleTime = untitled_P.DigitalInput1_SampleTime;
  }

  c_value_1 = readDigitalPin(34);
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Memory: '<S9>/Memory' */
    untitled_B.Memory = untitled_DW.Memory_PreviousInput;
  }

  /* Logic: '<S6>/Logical Operator6' incorporates:
   *  Logic: '<S6>/Logical Operator14'
   *  MATLABSystem: '<S6>/Digital Input1'
   * */
  rowIdx_tmp = !c_value_1;

  /* Logic: '<S6>/Logical Operator7' incorporates:
   *  Logic: '<S6>/Logical Operator11'
   *  MATLABSystem: '<S6>/Digital Input2'
   * */
  rowIdx_tmp_1 = !c_value_0;

  /* CombinatorialLogic: '<S9>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator4'
   *  Logic: '<S6>/Logical Operator5'
   *  Logic: '<S6>/Logical Operator6'
   *  Logic: '<S6>/Logical Operator7'
   *  MATLABSystem: '<S6>/Digital Input'
   *  MATLABSystem: '<S6>/Digital Input1'
   *  MATLABSystem: '<S6>/Digital Input2'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value && (rowIdx_tmp_1 && rowIdx_tmp)) << 1)
                       + (uint32_T)(int8_T)((int8_T)c_value_1 ^ (int8_T)
    c_value_0)) << 1) + untitled_B.Memory);
  untitled_B.Logic[0U] = untitled_P.Logic_table[(uint32_T)rowIdx];
  untitled_B.Logic[1U] = untitled_P.Logic_table[(uint32_T)rowIdx + 8U];
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Memory: '<S11>/Memory' */
    untitled_B.Memory_a = untitled_DW.Memory_PreviousInput_c;
  }

  /* Logic: '<S6>/Logical Operator13' incorporates:
   *  Logic: '<S6>/Logical Operator10'
   *  MATLABSystem: '<S6>/Digital Input'
   * */
  rowIdx_tmp_0 = !c_value;

  /* CombinatorialLogic: '<S11>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator12'
   *  Logic: '<S6>/Logical Operator13'
   *  Logic: '<S6>/Logical Operator15'
   *  Logic: '<S6>/Logical Operator3'
   *  MATLABSystem: '<S6>/Digital Input'
   *  MATLABSystem: '<S6>/Digital Input1'
   *  MATLABSystem: '<S6>/Digital Input2'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_0 && (rowIdx_tmp && rowIdx_tmp_0)) <<
                        1) + (uint32_T)(int8_T)((int8_T)c_value ^ (int8_T)
    c_value_1)) << 1) + untitled_B.Memory_a);
  untitled_B.Logic_o[0U] = untitled_P.Logic_table_m[(uint32_T)rowIdx];
  untitled_B.Logic_o[1U] = untitled_P.Logic_table_m[(uint32_T)rowIdx + 8U];
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Memory: '<S10>/Memory' */
    untitled_B.Memory_n = untitled_DW.Memory_PreviousInput_e;
  }

  /* CombinatorialLogic: '<S10>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator2'
   *  Logic: '<S6>/Logical Operator8'
   *  Logic: '<S6>/Logical Operator9'
   *  MATLABSystem: '<S6>/Digital Input'
   *  MATLABSystem: '<S6>/Digital Input1'
   *  MATLABSystem: '<S6>/Digital Input2'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_1 && (rowIdx_tmp_0 && rowIdx_tmp_1)) <<
                        1) + (uint32_T)(int8_T)((int8_T)c_value ^ (int8_T)
    c_value_0)) << 1) + untitled_B.Memory_n);
  untitled_B.Logic_n[0U] = untitled_P.Logic_table_k[(uint32_T)rowIdx];
  untitled_B.Logic_n[1U] = untitled_P.Logic_table_k[(uint32_T)rowIdx + 8U];
  if (rtmIsMajorTimeStep(untitled_M)) {
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  if (untitled_DW.obj.SampleTime != untitled_P.MATLABSystem_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.MATLABSystem_SampleTime;
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  /*         %% Define output properties */
  untitled_B.MATLABSystem_o1 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  untitled_B.MATLABSystem_o2 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  untitled_B.MATLABSystem_o3 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  untitled_B.MATLABSystem_o4 = 0.0;
  stepFunctionADS1115_Vread(&untitled_B.MATLABSystem_o1, 1.0,
    &untitled_B.MATLABSystem_o2, 1.0, &untitled_B.MATLABSystem_o3, 1.0,
    &untitled_B.MATLABSystem_o4, 1.0);
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* MATLAB Function: '<Root>/Throttle Body Callibration' */
    if (untitled_B.MATLABSystem_o2 > untitled_DW.TB_maxSet) {
      untitled_DW.TB_maxSet = untitled_B.MATLABSystem_o2;
    }

    if (untitled_B.MATLABSystem_o2 < untitled_DW.TB_minSet) {
      untitled_DW.TB_minSet = untitled_B.MATLABSystem_o2;
    }

    untitled_B.TB_maxVal = untitled_DW.TB_maxSet;
    untitled_B.TB_minVal = untitled_DW.TB_minSet;

    /* End of MATLAB Function: '<Root>/Throttle Body Callibration' */

    /* Sum: '<S7>/Add' */
    untitled_B.Add = untitled_B.TB_maxVal - untitled_B.TB_minVal;

    /* MATLAB Function: '<Root>/Pedal Calibration' */
    if (untitled_B.MATLABSystem_o3 > untitled_DW.maxSet) {
      untitled_DW.maxSet = untitled_B.MATLABSystem_o3;
    }

    if (untitled_B.MATLABSystem_o3 < untitled_DW.minSet) {
      untitled_DW.minSet = untitled_B.MATLABSystem_o3;
    }

    untitled_B.FP_maxVal = untitled_DW.maxSet;
    untitled_B.FP_minVal = untitled_DW.minSet;

    /* End of MATLAB Function: '<Root>/Pedal Calibration' */

    /* Sum: '<S7>/Add1' */
    untitled_B.Add1 = untitled_B.FP_maxVal - untitled_B.FP_minVal;

    /* Product: '<S7>/Divide' */
    untitled_B.Divide = untitled_B.Add / untitled_B.Add1;
  }

  /* Product: '<S7>/Product' */
  untitled_B.Product = untitled_B.MATLABSystem_o2 * untitled_B.Divide;

  /* Sum: '<Root>/Sum2' */
  untitled_B.Sum2 = untitled_B.MATLABSystem_o3 - untitled_B.Product;

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/Ki'
   *  Gain: '<S4>/Kp'
   *  Integrator: '<S4>/Integrator'
   */
  untitled_B.Saturation = untitled_P.Kp * untitled_B.Sum2 + untitled_P.Ki *
    untitled_X.Integrator_CSTATE;

  /* Saturate: '<S4>/Saturation' */
  if (untitled_B.Saturation > untitled_P.Saturation_UpperSat) {
    /* Sum: '<S4>/Sum' incorporates:
     *  Saturate: '<S4>/Saturation'
     */
    untitled_B.Saturation = untitled_P.Saturation_UpperSat;
  } else if (untitled_B.Saturation < untitled_P.Saturation_LowerSat) {
    /* Sum: '<S4>/Sum' incorporates:
     *  Saturate: '<S4>/Saturation'
     */
    untitled_B.Saturation = untitled_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/If Action Subsystem' */
  /* SignalConversion generated from: '<S3>/In1' */
  untitled_B.In1 = untitled_B.Sum2;

  /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Sum: '<S1>/Add' incorporates:
     *  Constant: '<S1>/Desire Max Value'
     *  Constant: '<S1>/Desire Min Value'
     */
    untitled_B.Add_e = untitled_P.Desire_Max - untitled_P.Desire_Min;

    /* Sum: '<S1>/Add1' */
    untitled_B.Add1_m = untitled_B.FP_maxVal - untitled_B.FP_minVal;

    /* Product: '<S1>/Divide' */
    untitled_B.Divide_o = untitled_B.Add_e / untitled_B.Add1_m;
  }

  /* Switch: '<Root>/Switch1' */
  if (untitled_B.Logic[0]) {
    y = untitled_B.Saturation;
  } else {
    y = untitled_B.In1;
  }

  /* Product: '<S1>/Product' incorporates:
   *  Switch: '<Root>/Switch1'
   */
  untitled_B.Product_i = y * untitled_B.Divide_o;

  /* Start for MATLABSystem: '<S2>/PWM' */
  if (untitled_B.Product_i <= 255.0) {
    y = untitled_B.Product_i;
  } else {
    y = 255.0;
  }

  /* MATLABSystem: '<S2>/PWM' */
  untitled_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);

  /* Start for MATLABSystem: '<S2>/PWM' */
  if (!(y >= 0.0)) {
    y = 0.0;
  }

  /* MATLABSystem: '<S2>/PWM' */
  MW_PWM_SetDutyCycle(untitled_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE, -(y * 255.0 /
    255.0));
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Constant: '<S2>/Enable Pin' */
    untitled_B.EnablePin = untitled_P.EN_Pin;

    /* MATLABSystem: '<S2>/Digital Output' */
    y = rt_roundd_snf(untitled_B.EnablePin);
    if (y < 256.0) {
      if (y >= 0.0) {
        tmp = (uint8_T)y;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(0, tmp);

    /* End of MATLABSystem: '<S2>/Digital Output' */
    /* Constant: '<S2>/Direction Pin' */
    untitled_B.DirectionPin = untitled_P.Direction_Pin;

    /* MATLABSystem: '<S2>/Digital Output1' */
    y = rt_roundd_snf(untitled_B.DirectionPin);
    if (y < 256.0) {
      if (y >= 0.0) {
        tmp = (uint8_T)y;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(16, tmp);

    /* End of MATLABSystem: '<S2>/Digital Output1' */
  }

  if (rtmIsMajorTimeStep(untitled_M)) {
    if (rtmIsMajorTimeStep(untitled_M)) {
      /* Update for Memory: '<S9>/Memory' */
      untitled_DW.Memory_PreviousInput = untitled_B.Logic[0];

      /* Update for Memory: '<S11>/Memory' */
      untitled_DW.Memory_PreviousInput_c = untitled_B.Logic_o[0];

      /* Update for Memory: '<S10>/Memory' */
      untitled_DW.Memory_PreviousInput_e = untitled_B.Logic_n[0];
    }

    if (rtmIsMajorTimeStep(untitled_M)) {/* Sample time: [0.05s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((untitled_M->Timing.clockTick1) * 0.05);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(untitled_M)) {
    rt_ertODEUpdateContinuousStates(&untitled_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++untitled_M->Timing.clockTick0;
    untitled_M->Timing.t[0] = rtsiGetSolverStopTime(&untitled_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.05s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.05, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      untitled_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void untitled_derivatives(void)
{
  XDot_untitled_T *_rtXdot;
  _rtXdot = ((XDot_untitled_T *) untitled_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = untitled_B.Sum2;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetdXPtr(&untitled_M->solverInfo, &untitled_M->derivs);
    rtsiSetContStatesPtr(&untitled_M->solverInfo, (real_T **)
                         &untitled_M->contStates);
    rtsiSetNumContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&untitled_M->solverInfo,
      &untitled_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&untitled_M->solverInfo,
      &untitled_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&untitled_M->solverInfo, (boolean_T**)
      &untitled_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&untitled_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&untitled_M->solverInfo, false);
  untitled_M->intgData.y = untitled_M->odeY;
  untitled_M->intgData.f[0] = untitled_M->odeF[0];
  untitled_M->intgData.f[1] = untitled_M->odeF[1];
  untitled_M->intgData.f[2] = untitled_M->odeF[2];
  untitled_M->contStates = ((X_untitled_T *) &untitled_X);
  untitled_M->contStateDisabled = ((XDis_untitled_T *) &untitled_XDis);
  untitled_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&untitled_M->solverInfo, (void *)&untitled_M->intgData);
  rtsiSetSolverName(&untitled_M->solverInfo,"ode3");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (2114646361U);
  untitled_M->Sizes.checksums[1] = (2661845472U);
  untitled_M->Sizes.checksums[2] = (3378178223U);
  untitled_M->Sizes.checksums[3] = (2016993694U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* InitializeConditions for Memory: '<S9>/Memory' */
  untitled_DW.Memory_PreviousInput = untitled_P.SRFlipFlop_initial_condition;

  /* InitializeConditions for Memory: '<S11>/Memory' */
  untitled_DW.Memory_PreviousInput_c = untitled_P.SRFlipFlop2_initial_condition;

  /* InitializeConditions for Memory: '<S10>/Memory' */
  untitled_DW.Memory_PreviousInput_e = untitled_P.SRFlipFlop1_initial_condition;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  untitled_X.Integrator_CSTATE = untitled_P.Integrator_IC;

  /* SystemInitialize for MATLAB Function: '<Root>/Throttle Body Callibration' */
  untitled_DW.TB_minSet = 5.0;

  /* SystemInitialize for MATLAB Function: '<Root>/Pedal Calibration' */
  untitled_DW.maxSet = -1.0;
  untitled_DW.minSet = 5.0;

  /* Start for MATLABSystem: '<S6>/Digital Input' */
  untitled_DW.obj_do.matlabCodegenIsDeleted = false;
  untitled_DW.obj_do.SampleTime = untitled_P.DigitalInput_SampleTime;
  untitled_DW.obj_do.isInitialized = 1;
  digitalIOSetup(39, 0);
  untitled_DW.obj_do.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Digital Input2' */
  untitled_DW.obj_d.matlabCodegenIsDeleted = false;
  untitled_DW.obj_d.SampleTime = untitled_P.DigitalInput2_SampleTime;
  untitled_DW.obj_d.isInitialized = 1;
  digitalIOSetup(36, 0);
  untitled_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Digital Input1' */
  untitled_DW.obj_m.matlabCodegenIsDeleted = false;
  untitled_DW.obj_m.SampleTime = untitled_P.DigitalInput1_SampleTime;
  untitled_DW.obj_m.isInitialized = 1;
  digitalIOSetup(34, 0);
  untitled_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.MATLABSystem_SampleTime;
  untitled_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionADS1115_Vread(16, 1.0);
  untitled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM' */
  untitled_DW.obj_n.matlabCodegenIsDeleted = false;
  untitled_DW.obj_n.isInitialized = 1;
  untitled_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4U, 19000.0, 255.0);
  untitled_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  untitled_DW.obj_a.matlabCodegenIsDeleted = false;
  untitled_DW.obj_a.isInitialized = 1;
  digitalIOSetup(0, 1);
  untitled_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output1' */
  untitled_DW.obj_j.matlabCodegenIsDeleted = false;
  untitled_DW.obj_j.isInitialized = 1;
  digitalIOSetup(16, 1);
  untitled_DW.obj_j.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/Digital Input' */
  if (!untitled_DW.obj_do.matlabCodegenIsDeleted) {
    untitled_DW.obj_do.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Input' */

  /* Terminate for MATLABSystem: '<S6>/Digital Input2' */
  if (!untitled_DW.obj_d.matlabCodegenIsDeleted) {
    untitled_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Input2' */

  /* Terminate for MATLABSystem: '<S6>/Digital Input1' */
  if (!untitled_DW.obj_m.matlabCodegenIsDeleted) {
    untitled_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Input1' */
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */

  /* Terminate for MATLABSystem: '<S2>/PWM' */
  if (!untitled_DW.obj_n.matlabCodegenIsDeleted) {
    untitled_DW.obj_n.matlabCodegenIsDeleted = true;
    untitled_SystemCore_release(&untitled_DW.obj_n);
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!untitled_DW.obj_a.matlabCodegenIsDeleted) {
    untitled_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output1' */
  if (!untitled_DW.obj_j.matlabCodegenIsDeleted) {
    untitled_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
