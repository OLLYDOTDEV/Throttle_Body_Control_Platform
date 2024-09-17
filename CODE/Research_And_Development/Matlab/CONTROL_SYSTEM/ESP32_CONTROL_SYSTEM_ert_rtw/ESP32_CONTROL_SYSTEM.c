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
 * Model version                  : 1.22
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Aug 27 22:03:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ESP32_CONTROL_SYSTEM.h"
#include "ESP32_CONTROL_SYSTEM_types.h"
#include "ESP32_CONTROL_SYSTEM_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>

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
  int_T nXc = 1;
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
  /* Start for MATLABSystem: '<S3>/PWM' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }

  /* End of Start for MATLABSystem: '<S3>/PWM' */
}

/* Model step function */
void ESP32_CONTROL_SYSTEM_step(void)
{
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

  {
    real_T lastTime;
    real_T rtb_FP_maxVal;
    real_T rtb_FP_minVal;
    real_T rtb_Sum;
    real_T *lastU;
    int32_T rowIdx;
    int8_T rtAction;
    int8_T rtPrevAction;
    uint8_T tmp;
    if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
      /* CombinatorialLogic: '<S13>/Logic' incorporates:
       *  Constant: '<S7>/Constant'
       *  Constant: '<S7>/Constant2'
       *  Constant: '<S7>/Constant3'
       *  Logic: '<S7>/Logical Operator12'
       *  Logic: '<S7>/Logical Operator13'
       *  Logic: '<S7>/Logical Operator14'
       *  Logic: '<S7>/Logical Operator15'
       *  Logic: '<S7>/Logical Operator3'
       *  Memory: '<S13>/Memory'
       */
      rowIdx = (int32_T)(((((uint32_T)((ESP32_CONTROL_SYSTEM_P.Constant3_Value
        != 0.0) && ((!(ESP32_CONTROL_SYSTEM_P.Constant2_Value != 0.0)) &&
                    (!(ESP32_CONTROL_SYSTEM_P.Constant_Value != 0.0)))) << 1) +
                           (uint32_T)(int8_T)((int8_T)
        (ESP32_CONTROL_SYSTEM_P.Constant_Value != 0.0) ^ (int8_T)
        (ESP32_CONTROL_SYSTEM_P.Constant2_Value != 0.0))) << 1) +
                         ESP32_CONTROL_SYSTEM_DW.Memory_PreviousInput);
      ESP32_CONTROL_SYSTEM_B.Logic[0U] = ESP32_CONTROL_SYSTEM_P.Logic_table
        [(uint32_T)rowIdx];
      ESP32_CONTROL_SYSTEM_B.Logic[1U] = ESP32_CONTROL_SYSTEM_P.Logic_table
        [(uint32_T)rowIdx + 8U];

      /* CombinatorialLogic: '<S11>/Logic' incorporates:
       *  Constant: '<S7>/Constant'
       *  Constant: '<S7>/Constant2'
       *  Constant: '<S7>/Constant3'
       *  Logic: '<S7>/Logical Operator1'
       *  Logic: '<S7>/Logical Operator4'
       *  Logic: '<S7>/Logical Operator5'
       *  Logic: '<S7>/Logical Operator6'
       *  Logic: '<S7>/Logical Operator7'
       *  Memory: '<S11>/Memory'
       */
      rowIdx = (int32_T)(((((uint32_T)((ESP32_CONTROL_SYSTEM_P.Constant_Value !=
        0.0) && ((!(ESP32_CONTROL_SYSTEM_P.Constant3_Value != 0.0)) &&
                 (!(ESP32_CONTROL_SYSTEM_P.Constant2_Value != 0.0)))) << 1) +
                           (uint32_T)(int8_T)((int8_T)
        (ESP32_CONTROL_SYSTEM_P.Constant2_Value != 0.0) ^ (int8_T)
        (ESP32_CONTROL_SYSTEM_P.Constant3_Value != 0.0))) << 1) +
                         ESP32_CONTROL_SYSTEM_DW.Memory_PreviousInput_f);
      ESP32_CONTROL_SYSTEM_B.Logic_b[0U] = ESP32_CONTROL_SYSTEM_P.Logic_table_d
        [(uint32_T)rowIdx];
      ESP32_CONTROL_SYSTEM_B.Logic_b[1U] = ESP32_CONTROL_SYSTEM_P.Logic_table_d
        [(uint32_T)rowIdx + 8U];

      /* CombinatorialLogic: '<S12>/Logic' incorporates:
       *  Constant: '<S7>/Constant'
       *  Constant: '<S7>/Constant2'
       *  Constant: '<S7>/Constant3'
       *  Logic: '<S7>/Logical Operator10'
       *  Logic: '<S7>/Logical Operator11'
       *  Logic: '<S7>/Logical Operator2'
       *  Logic: '<S7>/Logical Operator8'
       *  Logic: '<S7>/Logical Operator9'
       *  Memory: '<S12>/Memory'
       */
      rowIdx = (int32_T)(((((uint32_T)((ESP32_CONTROL_SYSTEM_P.Constant2_Value
        != 0.0) && ((!(ESP32_CONTROL_SYSTEM_P.Constant_Value != 0.0)) &&
                    (!(ESP32_CONTROL_SYSTEM_P.Constant3_Value != 0.0)))) << 1) +
                           (uint32_T)(int8_T)((int8_T)
        (ESP32_CONTROL_SYSTEM_P.Constant_Value != 0.0) ^ (int8_T)
        (ESP32_CONTROL_SYSTEM_P.Constant3_Value != 0.0))) << 1) +
                         ESP32_CONTROL_SYSTEM_DW.Memory_PreviousInput_n);
      ESP32_CONTROL_SYSTEM_B.Logic_l[0U] =
        ESP32_CONTROL_SYSTEM_P.Logic_table_d2[(uint32_T)rowIdx];
      ESP32_CONTROL_SYSTEM_B.Logic_l[1U] =
        ESP32_CONTROL_SYSTEM_P.Logic_table_d2[(uint32_T)rowIdx + 8U];
    }

    /* MATLABSystem: '<S2>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
    if (ESP32_CONTROL_SYSTEM_DW.obj_h.SampleTime !=
        ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenerate) {
      ESP32_CONTROL_SYSTEM_DW.obj_h.SampleTime =
        ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenerate;
    }

    /*         %% Define output properties */
    rtb_Sum = 0.0;
    stepFunctionESP32_ANALOG_READ(34, &rtb_Sum, 1.0);

    /* MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
    if (ESP32_CONTROL_SYSTEM_DW.obj.SampleTime !=
        ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenera_p) {
      ESP32_CONTROL_SYSTEM_DW.obj.SampleTime =
        ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenera_p;
    }

    /*         %% Define output properties */
    lastTime = 0.0;
    stepFunctionESP32_ANALOG_READ(35, &lastTime, 1.0);
    if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
      /* MATLAB Function: '<Root>/Throttle Body Callibration' incorporates:
       *  MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock'
       */
      if (lastTime > ESP32_CONTROL_SYSTEM_DW.TB_maxSet) {
        ESP32_CONTROL_SYSTEM_DW.TB_maxSet = lastTime;
      }

      if (lastTime < ESP32_CONTROL_SYSTEM_DW.TB_minSet) {
        ESP32_CONTROL_SYSTEM_DW.TB_minSet = lastTime;
      }

      /* MATLAB Function: '<Root>/Pedal Calibration' incorporates:
       *  MATLABSystem: '<S2>/ESP23_ANALOG_READ_DDAppGeneratedBlock1'
       */
      if (rtb_Sum > ESP32_CONTROL_SYSTEM_DW.maxSet) {
        ESP32_CONTROL_SYSTEM_DW.maxSet = rtb_Sum;
      }

      if (rtb_Sum < ESP32_CONTROL_SYSTEM_DW.minSet) {
        ESP32_CONTROL_SYSTEM_DW.minSet = rtb_Sum;
      }

      rtb_FP_maxVal = ESP32_CONTROL_SYSTEM_DW.maxSet;
      rtb_FP_minVal = ESP32_CONTROL_SYSTEM_DW.minSet;

      /* Product: '<S8>/Divide' incorporates:
       *  MATLAB Function: '<Root>/Pedal Calibration'
       *  MATLAB Function: '<Root>/Throttle Body Callibration'
       *  Sum: '<S8>/Add'
       *  Sum: '<S8>/Add1'
       */
      ESP32_CONTROL_SYSTEM_B.Divide = (ESP32_CONTROL_SYSTEM_DW.TB_maxSet -
        ESP32_CONTROL_SYSTEM_DW.TB_minSet) / (ESP32_CONTROL_SYSTEM_DW.maxSet -
        ESP32_CONTROL_SYSTEM_DW.minSet);
    }

    /* Sum: '<Root>/Sum2' incorporates:
     *  MATLABSystem: '<S2>/ESP23_ANALOG_READ_DDAppGeneratedBlock1'
     *  MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock'
     *  Product: '<S8>/Product'
     */
    ESP32_CONTROL_SYSTEM_B.Sum2 = rtb_Sum - lastTime *
      ESP32_CONTROL_SYSTEM_B.Divide;

    /* If: '<Root>/If' */
    rtPrevAction = ESP32_CONTROL_SYSTEM_DW.If_ActiveSubsystem;
    if (rtsiIsModeUpdateTimeStep(&ESP32_CONTROL_SYSTEM_M->solverInfo)) {
      if (ESP32_CONTROL_SYSTEM_B.Logic[0]) {
        rtAction = 0;
      } else if (ESP32_CONTROL_SYSTEM_B.Logic_b[0]) {
        rtAction = 1;
      } else if (ESP32_CONTROL_SYSTEM_B.Logic_l[0]) {
        rtAction = 2;
      } else {
        rtAction = 3;
      }

      ESP32_CONTROL_SYSTEM_DW.If_ActiveSubsystem = rtAction;
    } else {
      rtAction = ESP32_CONTROL_SYSTEM_DW.If_ActiveSubsystem;
    }

    if (rtPrevAction != rtAction) {
      if (ESP32_CONTROL_SYSTEM_M->Timing.t[0] == rtmGetTStart
          (ESP32_CONTROL_SYSTEM_M)) {
        (void) memset(&(ESP32_CONTROL_SYSTEM_XDis.Integrator_CSTATE), 1,
                      1*sizeof(boolean_T));
      }

      if (rtPrevAction == 1) {
        (void) memset(&(ESP32_CONTROL_SYSTEM_XDis.Integrator_CSTATE), 1,
                      1*sizeof(boolean_T));
      }
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* SignalConversion generated from: '<S4>/In1' */
      ESP32_CONTROL_SYSTEM_B.In1 = ESP32_CONTROL_SYSTEM_B.Sum2;

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
      break;

     case 1:
      if (rtAction != rtPrevAction) {
        /* Enable for IfAction SubSystem: '<Root>/PID Control' incorporates:
         *  ActionPort: '<S5>/Action Port'
         */
        /* Enable for If: '<Root>/If' */
        (void) memset(&(ESP32_CONTROL_SYSTEM_XDis.Integrator_CSTATE), 0,
                      1*sizeof(boolean_T));

        /* End of Enable for SubSystem: '<Root>/PID Control' */
      }

      /* Outputs for IfAction SubSystem: '<Root>/PID Control' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* Derivative: '<S5>/Derivative' */
      rtb_Sum = ESP32_CONTROL_SYSTEM_M->Timing.t[0];
      if ((ESP32_CONTROL_SYSTEM_DW.TimeStampA >= rtb_Sum) &&
          (ESP32_CONTROL_SYSTEM_DW.TimeStampB >= rtb_Sum)) {
        rtb_Sum = 0.0;
      } else {
        lastTime = ESP32_CONTROL_SYSTEM_DW.TimeStampA;
        lastU = &ESP32_CONTROL_SYSTEM_DW.LastUAtTimeA;
        if (ESP32_CONTROL_SYSTEM_DW.TimeStampA <
            ESP32_CONTROL_SYSTEM_DW.TimeStampB) {
          if (ESP32_CONTROL_SYSTEM_DW.TimeStampB < rtb_Sum) {
            lastTime = ESP32_CONTROL_SYSTEM_DW.TimeStampB;
            lastU = &ESP32_CONTROL_SYSTEM_DW.LastUAtTimeB;
          }
        } else if (ESP32_CONTROL_SYSTEM_DW.TimeStampA >= rtb_Sum) {
          lastTime = ESP32_CONTROL_SYSTEM_DW.TimeStampB;
          lastU = &ESP32_CONTROL_SYSTEM_DW.LastUAtTimeB;
        }

        rtb_Sum = (ESP32_CONTROL_SYSTEM_B.Sum2 - *lastU) / (rtb_Sum - lastTime);
      }

      /* End of Derivative: '<S5>/Derivative' */

      /* Sum: '<S5>/Sum' incorporates:
       *  Gain: '<S5>/Kd'
       *  Gain: '<S5>/Ki'
       *  Gain: '<S5>/Kp'
       *  Integrator: '<S5>/Integrator'
       */
      ESP32_CONTROL_SYSTEM_B.Saturation = (ESP32_CONTROL_SYSTEM_P.Kp *
        ESP32_CONTROL_SYSTEM_B.Sum2 + ESP32_CONTROL_SYSTEM_P.Ki *
        ESP32_CONTROL_SYSTEM_X.Integrator_CSTATE) + ESP32_CONTROL_SYSTEM_P.Kd *
        rtb_Sum;

      /* Saturate: '<S5>/Saturation' */
      if (ESP32_CONTROL_SYSTEM_B.Saturation >
          ESP32_CONTROL_SYSTEM_P.Saturation_UpperSat) {
        /* Sum: '<S5>/Sum' incorporates:
         *  Saturate: '<S5>/Saturation'
         */
        ESP32_CONTROL_SYSTEM_B.Saturation =
          ESP32_CONTROL_SYSTEM_P.Saturation_UpperSat;
      } else if (ESP32_CONTROL_SYSTEM_B.Saturation <
                 ESP32_CONTROL_SYSTEM_P.Saturation_LowerSat) {
        /* Sum: '<S5>/Sum' incorporates:
         *  Saturate: '<S5>/Saturation'
         */
        ESP32_CONTROL_SYSTEM_B.Saturation =
          ESP32_CONTROL_SYSTEM_P.Saturation_LowerSat;
      }

      /* End of Saturate: '<S5>/Saturation' */
      /* End of Outputs for SubSystem: '<Root>/PID Control' */
      break;

     case 2:
      break;
    }

    /* End of If: '<Root>/If' */
    if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
      /* Switch: '<Root>/Switch1' */
      if (ESP32_CONTROL_SYSTEM_B.Logic_b[0]) {
        rtb_Sum = ESP32_CONTROL_SYSTEM_B.Saturation;
      } else {
        rtb_Sum = ESP32_CONTROL_SYSTEM_B.In1;
      }

      /* Product: '<S1>/Product' incorporates:
       *  Constant: '<S1>/Desire Max Value'
       *  Constant: '<S1>/Desire Min Value'
       *  Product: '<S1>/Divide'
       *  Sum: '<S1>/Add'
       *  Sum: '<S1>/Add1'
       *  Switch: '<Root>/Switch1'
       */
      rtb_FP_maxVal = (ESP32_CONTROL_SYSTEM_P.Desire_Max -
                       ESP32_CONTROL_SYSTEM_P.Desire_Min) / (rtb_FP_maxVal -
        rtb_FP_minVal) * rtb_Sum;

      /* Start for MATLABSystem: '<S3>/PWM' */
      if (!(rtb_FP_maxVal <= 255.0)) {
        rtb_FP_maxVal = 255.0;
      }

      /* MATLABSystem: '<S3>/PWM' */
      ESP32_CONTROL_SYSTEM_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(2U);

      /* Start for MATLABSystem: '<S3>/PWM' */
      if (!(rtb_FP_maxVal >= 0.0)) {
        rtb_FP_maxVal = 0.0;
      }

      /* MATLABSystem: '<S3>/PWM' */
      MW_PWM_SetDutyCycle
        (ESP32_CONTROL_SYSTEM_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
         -(rtb_FP_maxVal * 255.0 / 255.0));

      /* MATLABSystem: '<S3>/Digital Output' incorporates:
       *  Constant: '<S3>/Enable Pin'
       */
      rtb_Sum = rt_roundd_snf(ESP32_CONTROL_SYSTEM_P.EN_Pin);
      if (rtb_Sum < 256.0) {
        if (rtb_Sum >= 0.0) {
          tmp = (uint8_T)rtb_Sum;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      writeDigitalPin(4, tmp);

      /* End of MATLABSystem: '<S3>/Digital Output' */

      /* MATLABSystem: '<S3>/Digital Output1' incorporates:
       *  Constant: '<S3>/Direction Pin'
       */
      rtb_Sum = rt_roundd_snf(ESP32_CONTROL_SYSTEM_P.Direction_Pin);
      if (rtb_Sum < 256.0) {
        if (rtb_Sum >= 0.0) {
          tmp = (uint8_T)rtb_Sum;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      writeDigitalPin(0, tmp);

      /* End of MATLABSystem: '<S3>/Digital Output1' */
    }
  }

  if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
    real_T *lastU;
    if (rtmIsMajorTimeStep(ESP32_CONTROL_SYSTEM_M)) {
      /* Update for Memory: '<S13>/Memory' */
      ESP32_CONTROL_SYSTEM_DW.Memory_PreviousInput =
        ESP32_CONTROL_SYSTEM_B.Logic[0];

      /* Update for Memory: '<S11>/Memory' */
      ESP32_CONTROL_SYSTEM_DW.Memory_PreviousInput_f =
        ESP32_CONTROL_SYSTEM_B.Logic_b[0];

      /* Update for Memory: '<S12>/Memory' */
      ESP32_CONTROL_SYSTEM_DW.Memory_PreviousInput_n =
        ESP32_CONTROL_SYSTEM_B.Logic_l[0];
    }

    /* Update for If: '<Root>/If' */
    if (ESP32_CONTROL_SYSTEM_DW.If_ActiveSubsystem == 1) {
      /* Update for IfAction SubSystem: '<Root>/PID Control' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* Update for Derivative: '<S5>/Derivative' */
      if (ESP32_CONTROL_SYSTEM_DW.TimeStampA == (rtInf)) {
        ESP32_CONTROL_SYSTEM_DW.TimeStampA = ESP32_CONTROL_SYSTEM_M->Timing.t[0];
        lastU = &ESP32_CONTROL_SYSTEM_DW.LastUAtTimeA;
      } else if (ESP32_CONTROL_SYSTEM_DW.TimeStampB == (rtInf)) {
        ESP32_CONTROL_SYSTEM_DW.TimeStampB = ESP32_CONTROL_SYSTEM_M->Timing.t[0];
        lastU = &ESP32_CONTROL_SYSTEM_DW.LastUAtTimeB;
      } else if (ESP32_CONTROL_SYSTEM_DW.TimeStampA <
                 ESP32_CONTROL_SYSTEM_DW.TimeStampB) {
        ESP32_CONTROL_SYSTEM_DW.TimeStampA = ESP32_CONTROL_SYSTEM_M->Timing.t[0];
        lastU = &ESP32_CONTROL_SYSTEM_DW.LastUAtTimeA;
      } else {
        ESP32_CONTROL_SYSTEM_DW.TimeStampB = ESP32_CONTROL_SYSTEM_M->Timing.t[0];
        lastU = &ESP32_CONTROL_SYSTEM_DW.LastUAtTimeB;
      }

      *lastU = ESP32_CONTROL_SYSTEM_B.Sum2;

      /* End of Update for Derivative: '<S5>/Derivative' */
      /* End of Update for SubSystem: '<Root>/PID Control' */
    }

    /* End of Update for If: '<Root>/If' */
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

  /* Derivatives for If: '<Root>/If' */
  ((XDot_ESP32_CONTROL_SYSTEM_T *) ESP32_CONTROL_SYSTEM_M->derivs)
    ->Integrator_CSTATE = 0.0;
  if (ESP32_CONTROL_SYSTEM_DW.If_ActiveSubsystem == 1) {
    /* Derivatives for IfAction SubSystem: '<Root>/PID Control' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Derivatives for Integrator: '<S5>/Integrator' */
    _rtXdot->Integrator_CSTATE = ESP32_CONTROL_SYSTEM_B.Sum2;

    /* End of Derivatives for SubSystem: '<Root>/PID Control' */
  }

  /* End of Derivatives for If: '<Root>/If' */
}

/* Model initialize function */
void ESP32_CONTROL_SYSTEM_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

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
  ESP32_CONTROL_SYSTEM_M->Timing.stepSize0 = 0.05;

  /* Start for If: '<Root>/If' */
  (void) memset(&(ESP32_CONTROL_SYSTEM_XDis.Integrator_CSTATE), 1,
                1*sizeof(boolean_T));
  ESP32_CONTROL_SYSTEM_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for Memory: '<S13>/Memory' */
  ESP32_CONTROL_SYSTEM_DW.Memory_PreviousInput =
    ESP32_CONTROL_SYSTEM_P.SRFlipFlop2_initial_condition;

  /* InitializeConditions for Memory: '<S11>/Memory' */
  ESP32_CONTROL_SYSTEM_DW.Memory_PreviousInput_f =
    ESP32_CONTROL_SYSTEM_P.SRFlipFlop_initial_condition;

  /* InitializeConditions for Memory: '<S12>/Memory' */
  ESP32_CONTROL_SYSTEM_DW.Memory_PreviousInput_n =
    ESP32_CONTROL_SYSTEM_P.SRFlipFlop1_initial_condition;

  /* SystemInitialize for MATLAB Function: '<Root>/Throttle Body Callibration' */
  ESP32_CONTROL_SYSTEM_DW.TB_minSet = 5.0;

  /* SystemInitialize for MATLAB Function: '<Root>/Pedal Calibration' */
  ESP32_CONTROL_SYSTEM_DW.maxSet = -1.0;
  ESP32_CONTROL_SYSTEM_DW.minSet = 5.0;

  /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S4>/In1' incorporates:
   *  Outport: '<S4>/Out1'
   */
  ESP32_CONTROL_SYSTEM_B.In1 = ESP32_CONTROL_SYSTEM_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/PID Control' */
  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  ESP32_CONTROL_SYSTEM_DW.TimeStampA = (rtInf);
  ESP32_CONTROL_SYSTEM_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  ESP32_CONTROL_SYSTEM_X.Integrator_CSTATE =
    ESP32_CONTROL_SYSTEM_P.Integrator_IC;

  /* SystemInitialize for Sum: '<S5>/Sum' incorporates:
   *  Outport: '<S5>/PID Output'
   *  Saturate: '<S5>/Saturation'
   */
  ESP32_CONTROL_SYSTEM_B.Saturation = ESP32_CONTROL_SYSTEM_P.PIDOutput_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/PID Control' */

  /* Start for MATLABSystem: '<S2>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  /*  Constructor */
  ESP32_CONTROL_SYSTEM_DW.obj_h.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj_h.SampleTime =
    ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenerate;
  ESP32_CONTROL_SYSTEM_DW.obj_h.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionESP32_ANALOG_READ(34, 1.0);
  ESP32_CONTROL_SYSTEM_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  /*  Constructor */
  ESP32_CONTROL_SYSTEM_DW.obj.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj.SampleTime =
    ESP32_CONTROL_SYSTEM_P.ESP23_ANALOG_READ_DDAppGenera_p;
  ESP32_CONTROL_SYSTEM_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionESP32_ANALOG_READ(35, 1.0);
  ESP32_CONTROL_SYSTEM_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM' */
  ESP32_CONTROL_SYSTEM_DW.obj_l.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj_l.isInitialized = 1;
  ESP32_CONTROL_SYSTEM_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2U,
    19000.0, 255.0);
  ESP32_CONTROL_SYSTEM_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output' */
  ESP32_CONTROL_SYSTEM_DW.obj_m.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj_m.isInitialized = 1;
  digitalIOSetup(4, 1);
  ESP32_CONTROL_SYSTEM_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output1' */
  ESP32_CONTROL_SYSTEM_DW.obj_c.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_DW.obj_c.isInitialized = 1;
  digitalIOSetup(0, 1);
  ESP32_CONTROL_SYSTEM_DW.obj_c.isSetupComplete = true;
}

/* Model terminate function */
void ESP32_CONTROL_SYSTEM_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj_h.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */

  /* Terminate for MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */

  /* Terminate for MATLABSystem: '<S3>/PWM' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj_l.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj_l.matlabCodegenIsDeleted = true;
    ESP32_CONTRO_SystemCore_release(&ESP32_CONTROL_SYSTEM_DW.obj_l);
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj_m.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output1' */
  if (!ESP32_CONTROL_SYSTEM_DW.obj_c.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
