/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_CONTROL_SYSTEM.c
 *
 * Code generated for Simulink model 'ESP32_CONTROL_SYSTEM'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Aug 19 16:13:12 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ESP32_CONTROL_SYSTEM.h"
#include "ESP32_CONTROL_SYSTEM_types.h"
#include <math.h>
#include "ESP32_CONTROL_SYSTEM_private.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_B;

/* Continuous states */
X_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_X;

/* Disabled State Vector */
XDis_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_XDis;

/* Block states (default storage) */
DW_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_DW;

/* Real-time model */
static RT_MODEL_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_M_;
RT_MODEL_ESP32_CONTROL_SYSTEM_T *const ESP32_CONTROL_SYSTEM_M =
  &ESP32_CONTROL_SYSTEM_M_;

/* Forward declaration for local functions */
static void ESP32_CONTRO_SystemCore_release(codertarget_arduinobase_inter_T *obj);

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
  ESP32_CONTROL_SYSTEM_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ESP32_CONTROL_SYSTEM_step();
  ESP32_CONTROL_SYSTEM_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ESP32_CONTROL_SYSTEM_step();
  ESP32_CONTROL_SYSTEM_derivatives();

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

static void ESP32_CONTRO_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  /* Start for MATLABSystem: '<S12>/PWM' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }

  /* End of Start for MATLABSystem: '<S12>/PWM' */
}

/* Model step function */
void ESP32_CONTROL_SYSTEM_step(void)
{
  real_T rtb_Sum1[3];
  real_T Integrator1;
  real_T Integrator1_0;
  real_T Integrator1_1;
  real_T rtb_Product;
  int32_T i;
  uint8_T tmp;
  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&ESP32_CONTROL_SYSTEM_M->solverInfo,
                          ((ESP32_CONTROL_SYSTEM_M->Timing.clockTick0+1)*
      ESP32_CONTROL_SYSTEM_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    ESP32_CONTROL_SYSTEM_M->Timing.t[0] = rtsiGetT
      (&ESP32_CONTROL_SYSTEM_M->solverInfo);
  }

  /* Integrator: '<S6>/Integrator1' */
  ESP32_CONTROL_SYSTEM_B.Integrator1[0] =
    ESP32_CONTROL_SYSTEM_X.Integrator1_CSTATE[0];
  ESP32_CONTROL_SYSTEM_B.Integrator1[1] =
    ESP32_CONTROL_SYSTEM_X.Integrator1_CSTATE[1];
  ESP32_CONTROL_SYSTEM_B.Integrator1[2] =
    ESP32_CONTROL_SYSTEM_X.Integrator1_CSTATE[2];
  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
  }

  /* MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  if (ESP32_CONTROL_SYSTEM_DW.obj.SampleTime !=
      ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenera_c) {
    ESP32_CONTROL_SYSTEM_DW.obj.SampleTime =
      ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenera_c;
  }

  /* MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  /*         %% Define output properties */
  ESP32_CONTROL_SYSTEM_B.ESP23_ANALOG_READ_DDAppGenerate = 0.0;
  stepFunctionESP32_ANALOG_READ(35,
    &ESP32_CONTROL_SYSTEM_B.ESP23_ANALOG_READ_DDAppGenerate, 1.0);
  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    /* Sum: '<S7>/Add' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     */
    ESP32_CONTROL_SYSTEM_B.Add = ESP32_CONTROL_SYSTEM_P.Constant_Value -
      ESP32_CONTROL_SYSTEM_P.Constant1_Value;

    /* MATLAB Function: '<Root>/Throttle Body Callibration1' */
    if (ESP32_CONTROL_SYSTEM_B.ESP23_ANALOG_READ_DDAppGenerate >
        ESP32_CONTROL_SYSTEM_DW.TB_maxSet) {
      ESP32_CONTROL_SYSTEM_DW.TB_maxSet =
        ESP32_CONTROL_SYSTEM_B.ESP23_ANALOG_READ_DDAppGenerate;
    }

    if (ESP32_CONTROL_SYSTEM_B.ESP23_ANALOG_READ_DDAppGenerate <
        ESP32_CONTROL_SYSTEM_DW.TB_minSet) {
      ESP32_CONTROL_SYSTEM_DW.TB_minSet =
        ESP32_CONTROL_SYSTEM_B.ESP23_ANALOG_READ_DDAppGenerate;
    }

    ESP32_CONTROL_SYSTEM_B.TB_maxVal = ESP32_CONTROL_SYSTEM_DW.TB_maxSet;
    ESP32_CONTROL_SYSTEM_B.TB_minVal = ESP32_CONTROL_SYSTEM_DW.TB_minSet;

    /* End of MATLAB Function: '<Root>/Throttle Body Callibration1' */

    /* Sum: '<S7>/Add1' */
    ESP32_CONTROL_SYSTEM_B.Add1 = ESP32_CONTROL_SYSTEM_B.TB_maxVal -
      ESP32_CONTROL_SYSTEM_B.TB_minVal;

    /* Product: '<S7>/Divide' */
    ESP32_CONTROL_SYSTEM_B.Divide = ESP32_CONTROL_SYSTEM_B.Add /
      ESP32_CONTROL_SYSTEM_B.Add1;
  }

  /* Product: '<S7>/Product' */
  ESP32_CONTROL_SYSTEM_B.Product =
    ESP32_CONTROL_SYSTEM_B.ESP23_ANALOG_READ_DDAppGenerate *
    ESP32_CONTROL_SYSTEM_B.Divide;

  /* Sum: '<S6>/Sum2' */
  rtb_Product = ESP32_CONTROL_SYSTEM_B.Product -
    ESP32_CONTROL_SYSTEM_B.Integrator1[0];

  /* Gain: '<S6>/Gain' */
  Integrator1 = ESP32_CONTROL_SYSTEM_B.Integrator1[1];
  Integrator1_0 = ESP32_CONTROL_SYSTEM_B.Integrator1[0];
  Integrator1_1 = ESP32_CONTROL_SYSTEM_B.Integrator1[2];

  /* Sum: '<S6>/Sum1' incorporates:
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum1[i] = ((ESP32_CONTROL_SYSTEM_P.Gain_Gain[i + 3] * Integrator1 +
                    ESP32_CONTROL_SYSTEM_P.Gain_Gain[i] * Integrator1_0) +
                   ESP32_CONTROL_SYSTEM_P.Gain_Gain[i + 6] * Integrator1_1) +
      ESP32_CONTROL_SYSTEM_P.Gain2_Gain[i] * rtb_Product;
  }

  /* End of Sum: '<S6>/Sum1' */
  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    /* Fcn: '<S4>/Fcn' incorporates:
     *  Constant: '<S4>/Constant2'
     */
    ESP32_CONTROL_SYSTEM_B.Fcn = 1.0 / (ESP32_CONTROL_SYSTEM_P.roa /
      ESP32_CONTROL_SYSTEM_P.J_aet);
  }

  /* Fcn: '<S2>/Fcn1' incorporates:
   *  Clock: '<S2>/Clock'
   *  Fcn: '<S2>/Fcn2'
   *  Fcn: '<S2>/Fcn3'
   */
  Integrator1 = 2.0 * ESP32_CONTROL_SYSTEM_M->Timing.t[0];
  rtb_Product = sin(Integrator1);

  /* Fcn: '<S2>/Fcn1' */
  ESP32_CONTROL_SYSTEM_B.Fcn1 = (10.0 * rtb_Product + 10.0) + 7.0;

  /* Fcn: '<S2>/Fcn2' */
  ESP32_CONTROL_SYSTEM_B.Fcn2 = cos(Integrator1) * 20.0;

  /* Fcn: '<S2>/Fcn3' */
  ESP32_CONTROL_SYSTEM_B.Fcn3 = -40.0 * rtb_Product;

  /* Gain: '<S1>/Gain1' */
  ESP32_CONTROL_SYSTEM_B.Gain1[0] = ESP32_CONTROL_SYSTEM_P.Gain1_Gain *
    ESP32_CONTROL_SYSTEM_B.Fcn1;
  ESP32_CONTROL_SYSTEM_B.Gain1[1] = ESP32_CONTROL_SYSTEM_P.Gain1_Gain *
    ESP32_CONTROL_SYSTEM_B.Fcn2;
  ESP32_CONTROL_SYSTEM_B.Gain1[2] = ESP32_CONTROL_SYSTEM_P.Gain1_Gain *
    ESP32_CONTROL_SYSTEM_B.Fcn3;

  /* Sum: '<S4>/Sum3' */
  ESP32_CONTROL_SYSTEM_B.Sum3 = ESP32_CONTROL_SYSTEM_B.Gain1[0] -
    ESP32_CONTROL_SYSTEM_B.Integrator1[0];

  /* Gain: '<S4>/Gain' */
  ESP32_CONTROL_SYSTEM_B.Gain = ESP32_CONTROL_SYSTEM_P.Gain_Gain_d *
    ESP32_CONTROL_SYSTEM_B.Sum3;

  /* Product: '<S4>/Product' incorporates:
   *  Gain: '<S4>/Gain1'
   *  Sum: '<S4>/Sum1'
   *  Sum: '<S4>/Sum2'
   *  Sum: '<S4>/Sum4'
   */
  ESP32_CONTROL_SYSTEM_B.Product_f = (((2.0 * ESP32_CONTROL_SYSTEM_P.omga_c *
    (ESP32_CONTROL_SYSTEM_B.Gain1[1] - ESP32_CONTROL_SYSTEM_B.Integrator1[1]) +
    ESP32_CONTROL_SYSTEM_B.Gain) + ESP32_CONTROL_SYSTEM_B.Gain1[2]) -
    ESP32_CONTROL_SYSTEM_B.Integrator1[2]) * ESP32_CONTROL_SYSTEM_B.Fcn;

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Product: '<S6>/Product'
   */
  ESP32_CONTROL_SYSTEM_B.Sum[0] = ESP32_CONTROL_SYSTEM_P.Constant_Value_p +
    rtb_Sum1[0];
  ESP32_CONTROL_SYSTEM_B.Sum[1] = ESP32_CONTROL_SYSTEM_P.roa /
    ESP32_CONTROL_SYSTEM_P.J_aet * ESP32_CONTROL_SYSTEM_B.Product_f + rtb_Sum1[1];
  ESP32_CONTROL_SYSTEM_B.Sum[2] = ESP32_CONTROL_SYSTEM_P.Constant1_Value_g +
    rtb_Sum1[2];
  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    /* SignalConversion generated from: '<S2>/Mux' */
    ESP32_CONTROL_SYSTEM_B.TmpSignalConversionAtTAQSigLogg[0] =
      ESP32_CONTROL_SYSTEM_B.Fcn1;
    ESP32_CONTROL_SYSTEM_B.TmpSignalConversionAtTAQSigLogg[1] =
      ESP32_CONTROL_SYSTEM_B.Fcn2;
    ESP32_CONTROL_SYSTEM_B.TmpSignalConversionAtTAQSigLogg[2] =
      ESP32_CONTROL_SYSTEM_B.Fcn3;
  }

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<S5>/Constant'
   *  Gain: '<S5>/Gain1'
   */
  ESP32_CONTROL_SYSTEM_B.Sum_j = ESP32_CONTROL_SYSTEM_P.Gain1_Gain_f *
    ESP32_CONTROL_SYSTEM_B.Product_f + ESP32_CONTROL_SYSTEM_P.Constant_Value_h;
  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    /* MATLAB Function: '<S5>/Throttle Body Callibration1' */
    if (ESP32_CONTROL_SYSTEM_B.Sum_j > ESP32_CONTROL_SYSTEM_DW.TB_maxSet_j) {
      ESP32_CONTROL_SYSTEM_DW.TB_maxSet_j = ESP32_CONTROL_SYSTEM_B.Sum_j;
    }

    if (ESP32_CONTROL_SYSTEM_B.Sum_j < ESP32_CONTROL_SYSTEM_DW.TB_minSet_n) {
      ESP32_CONTROL_SYSTEM_DW.TB_minSet_n = ESP32_CONTROL_SYSTEM_B.Sum_j;
    }

    /* Sum: '<S11>/Add1' incorporates:
     *  MATLAB Function: '<S5>/Throttle Body Callibration1'
     */
    ESP32_CONTROL_SYSTEM_B.Add1_c = ESP32_CONTROL_SYSTEM_DW.TB_maxSet_j -
      ESP32_CONTROL_SYSTEM_DW.TB_minSet_n;

    /* Sum: '<S11>/Add' incorporates:
     *  Constant: '<S11>/Desire Max Value'
     *  Constant: '<S11>/Desire Min Value'
     */
    ESP32_CONTROL_SYSTEM_B.Add_f = ESP32_CONTROL_SYSTEM_P.Desire_Max -
      ESP32_CONTROL_SYSTEM_P.Desire_Min;

    /* Product: '<S11>/Divide' */
    ESP32_CONTROL_SYSTEM_B.Divide_p = ESP32_CONTROL_SYSTEM_B.Add_f /
      ESP32_CONTROL_SYSTEM_B.Add1_c;
  }

  /* Product: '<S11>/Product' */
  ESP32_CONTROL_SYSTEM_B.Product_j = ESP32_CONTROL_SYSTEM_B.Sum_j *
    ESP32_CONTROL_SYSTEM_B.Divide_p;

  /* Start for MATLABSystem: '<S12>/PWM' */
  if (ESP32_CONTROL_SYSTEM_B.Product_j <= 255.0) {
    rtb_Product = ESP32_CONTROL_SYSTEM_B.Product_j;
  } else {
    rtb_Product = 255.0;
  }

  /* MATLABSystem: '<S12>/PWM' */
  ESP32_CONTROL_SYSTEM_DW.obj_oq.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (2U);

  /* Start for MATLABSystem: '<S12>/PWM' */
  if (!(rtb_Product >= 0.0)) {
    rtb_Product = 0.0;
  }

  /* MATLABSystem: '<S12>/PWM' */
  MW_PWM_SetDutyCycle(ESP32_CONTROL_SYSTEM_DW.obj_oq.PWMDriverObj.MW_PWM_HANDLE,
                      -(rtb_Product * 255.0 / 255.0));
  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
  }

  /* Gain: '<S10>/Gain' */
  ESP32_CONTROL_SYSTEM_B.Gain_j = ESP32_CONTROL_SYSTEM_P.Gain_Gain_a *
    ESP32_CONTROL_SYSTEM_B.Sum3;
  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    /* Constant: '<S5>/Constant3' */
    ESP32_CONTROL_SYSTEM_B.Constant3 = ESP32_CONTROL_SYSTEM_P.Constant3_Value;

    /* MATLABSystem: '<S12>/Digital Output1' */
    rtb_Product = rt_roundd_snf(ESP32_CONTROL_SYSTEM_B.Constant3);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        tmp = (uint8_T)rtb_Product;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(0, tmp);

    /* End of MATLABSystem: '<S12>/Digital Output1' */
    /* Constant: '<S12>/Enable Pin' */
    ESP32_CONTROL_SYSTEM_B.EnablePin = ESP32_CONTROL_SYSTEM_P.EN_Pin;

    /* MATLABSystem: '<S12>/Digital Output' */
    rtb_Product = rt_roundd_snf(ESP32_CONTROL_SYSTEM_B.EnablePin);
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        tmp = (uint8_T)rtb_Product;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(4, tmp);

    /* End of MATLABSystem: '<S12>/Digital Output' */
    /* MATLABSystem: '<S3>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
    if (ESP32_CONTROL_SYSTEM_DW.obj_a.SampleTime !=
        ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenerate) {
      ESP32_CONTROL_SYSTEM_DW.obj_a.SampleTime =
        ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenerate;
    }

    /* MATLABSystem: '<S3>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
    /*         %% Define output properties */
    ESP32_CONTROL_SYSTEM_B.ESP23_ANALOG_READ_DDAppGenera_g = 0.0;
    stepFunctionESP32_ANALOG_READ(34,
      &ESP32_CONTROL_SYSTEM_B.ESP23_ANALOG_READ_DDAppGenera_g, 1.0);
  }

  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {/* Sample time: [0.05s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((ESP32_CONTROL_SYSTEM_M->Timing.clockTick1) * 0.05);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    rt_ertODEUpdateContinuousStates(&ESP32_CONTROL_SYSTEM_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++ESP32_CONTROL_SYSTEM_M->Timing.clockTick0;
    ESP32_CONTROL_SYSTEM_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ESP32_CONTROL_SYSTEM_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.05s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.05, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      ESP32_CONTROL_SYSTEM_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ESP32_CONTROL_SYSTEM_derivatives(void)
{
  XDot_ESP32_CONTROL_SYSTEM_T *_rtXdot;
  _rtXdot = ((XDot_ESP32_CONTROL_SYSTEM_T *) ESP32_CONTROL_SYSTEM_M->derivs);

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ESP32_CONTROL_SYSTEM_B.Sum[0];
  _rtXdot->Integrator1_CSTATE[1] = ESP32_CONTROL_SYSTEM_B.Sum[1];
  _rtXdot->Integrator1_CSTATE[2] = ESP32_CONTROL_SYSTEM_B.Sum[2];
}

/* Model initialize function */
void ESP32_CONTROL_SYSTEM_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo,
                          &ESP32_CONTROL_SYSTEM_M->Timing.simTimeStep);
    rtsiSetTPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo, &rtmGetTPtr
                (ESP32_CONTROL_SYSTEM_M));
    rtsiSetStepSizePtr(&ESP32_CONTROL_SYSTEM_M->solverInfo,
                       &ESP32_CONTROL_SYSTEM_M->Timing.stepSize0);
    rtsiSetdXPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo,
                 &ESP32_CONTROL_SYSTEM_M->derivs);
    rtsiSetContStatesPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo, (real_T **)
                         &ESP32_CONTROL_SYSTEM_M->contStates);
    rtsiSetNumContStatesPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo,
      &ESP32_CONTROL_SYSTEM_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo,
      &ESP32_CONTROL_SYSTEM_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo,
      &ESP32_CONTROL_SYSTEM_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo,
      &ESP32_CONTROL_SYSTEM_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo, (boolean_T**)
      &ESP32_CONTROL_SYSTEM_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo,
                          (&rtmGetErrorStatus(ESP32_CONTROL_SYSTEM_M)));
    rtsiSetRTModelPtr(&ESP32_CONTROL_SYSTEM_M->solverInfo,
                      ESP32_CONTROL_SYSTEM_M);
  }

  rtsiSetSimTimeStep(&ESP32_CONTROL_SYSTEM_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&ESP32_CONTROL_SYSTEM_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&ESP32_CONTROL_SYSTEM_M->solverInfo, false);
  ESP32_CONTROL_SYSTEM_M->intgData.y = ESP32_CONTROL_SYSTEM_M->odeY;
  ESP32_CONTROL_SYSTEM_M->intgData.f[0] = ESP32_CONTROL_SYSTEM_M->odeF[0];
  ESP32_CONTROL_SYSTEM_M->intgData.f[1] = ESP32_CONTROL_SYSTEM_M->odeF[1];
  ESP32_CONTROL_SYSTEM_M->intgData.f[2] = ESP32_CONTROL_SYSTEM_M->odeF[2];
  ESP32_CONTROL_SYSTEM_M->contStates = ((X_ESP32_CONTROL_SYSTEM_T *)
    &ESP32_CONTROL_SYSTEM_X);
  ESP32_CONTROL_SYSTEM_M->contStateDisabled = ((XDis_ESP32_CONTROL_SYSTEM_T *)
    &ESP32_CONTROL_SYSTEM_XDis);
  ESP32_CONTROL_SYSTEM_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ESP32_CONTROL_SYSTEM_M->solverInfo, (void *)
                    &ESP32_CONTROL_SYSTEM_M->intgData);
  rtsiSetSolverName(&ESP32_CONTROL_SYSTEM_M->solverInfo,"ode3");
  rtmSetTPtr(ESP32_CONTROL_SYSTEM_M, &ESP32_CONTROL_SYSTEM_M->Timing.tArray[0]);
  rtmSetTFinal(ESP32_CONTROL_SYSTEM_M, -1);
  ESP32_CONTROL_SYSTEM_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  ESP32_CONTROL_SYSTEM_M->Sizes.checksums[0] = (847587789U);
  ESP32_CONTROL_SYSTEM_M->Sizes.checksums[1] = (3053662484U);
  ESP32_CONTROL_SYSTEM_M->Sizes.checksums[2] = (2920405325U);
  ESP32_CONTROL_SYSTEM_M->Sizes.checksums[3] = (2388070784U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    ESP32_CONTROL_SYSTEM_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ESP32_CONTROL_SYSTEM_M->extModeInfo,
      &ESP32_CONTROL_SYSTEM_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ESP32_CONTROL_SYSTEM_M->extModeInfo,
                        ESP32_CONTROL_SYSTEM_M->Sizes.checksums);
    rteiSetTPtr(ESP32_CONTROL_SYSTEM_M->extModeInfo, rtmGetTPtr
                (ESP32_CONTROL_SYSTEM_M));
  }

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  ESP32_CONTROL_SYSTEM_X.Integrator1_CSTATE[0] =
    ESP32_CONTROL_SYSTEM_P.Integrator1_IC[0];
  ESP32_CONTROL_SYSTEM_X.Integrator1_CSTATE[1] =
    ESP32_CONTROL_SYSTEM_P.Integrator1_IC[1];
  ESP32_CONTROL_SYSTEM_X.Integrator1_CSTATE[2] =
    ESP32_CONTROL_SYSTEM_P.Integrator1_IC[2];

  /* SystemInitialize for MATLAB Function: '<Root>/Throttle Body Callibration1' */
  ESP32_CONTROL_SYSTEM_DW.TB_minSet = 5.0;

  /* SystemInitialize for MATLAB Function: '<S5>/Throttle Body Callibration1' */
  ESP32_CONTROL_SYSTEM_DW.TB_minSet_n = 5.0;

  /* Start for MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  /*  Constructor */
  ESP32_CONTROL_SYSTEM_DW.obj.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj.SampleTime =
    ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenera_c;
  ESP32_CONTROL_SYSTEM_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionESP32_ANALOG_READ(35, 1.0);
  ESP32_CONTROL_SYSTEM_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S12>/PWM' */
  ESP32_CONTROL_SYSTEM_DW.obj_oq.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj_oq.isInitialized = 1;
  ESP32_CONTROL_SYSTEM_DW.obj_oq.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2U,
    19000.0, 255.0);
  ESP32_CONTROL_SYSTEM_DW.obj_oq.isSetupComplete = true;

  /* Start for MATLABSystem: '<S12>/Digital Output1' */
  ESP32_CONTROL_SYSTEM_DW.obj_o.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj_o.isInitialized = 1;
  digitalIOSetup(0, 1);
  ESP32_CONTROL_SYSTEM_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S12>/Digital Output' */
  ESP32_CONTROL_SYSTEM_DW.obj_h.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj_h.isInitialized = 1;
  digitalIOSetup(4, 1);
  ESP32_CONTROL_SYSTEM_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  /*  Constructor */
  ESP32_CONTROL_SYSTEM_DW.obj_a.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj_a.SampleTime =
    ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenerate;
  ESP32_CONTROL_SYSTEM_DW.obj_a.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionESP32_ANALOG_READ(34, 1.0);
  ESP32_CONTROL_SYSTEM_DW.obj_a.isSetupComplete = true;
}

/* Model terminate function */
void ESP32_CONTROL_SYSTEM_terminate(void)
{
  /* Terminate for MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  /* Terminate for MATLABSystem: '<S12>/PWM' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj_oq.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj_oq.matlabCodegenIsDeleted = true;
    ESP32_CONTRO_SystemCore_release(&ESP32_CONTROL_SYSTEM_DW.obj_oq);
  }

  /* End of Terminate for MATLABSystem: '<S12>/PWM' */
  /* Terminate for MATLABSystem: '<S12>/Digital Output1' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj_o.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S12>/Digital Output1' */
  /* Terminate for MATLABSystem: '<S12>/Digital Output' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj_h.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S12>/Digital Output' */
  /* Terminate for MATLABSystem: '<S3>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj_a.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
