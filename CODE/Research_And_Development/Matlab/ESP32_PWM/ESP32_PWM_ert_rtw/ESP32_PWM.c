/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_PWM.c
 *
 * Code generated for Simulink model 'ESP32_PWM'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Aug  9 11:08:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ESP32_PWM.h"
#include <math.h>
#include "ESP32_PWM_private.h"

/* Block states (default storage) */
DW_ESP32_PWM_T ESP32_PWM_DW;

/* Real-time model */
static RT_MODEL_ESP32_PWM_T ESP32_PWM_M_;
RT_MODEL_ESP32_PWM_T *const ESP32_PWM_M = &ESP32_PWM_M_;

/* Model step function */
void ESP32_PWM_step(void)
{
  /* MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Abs: '<Root>/Abs'
   *  Sin: '<Root>/Sine Wave'
   */
  if (ESP32_PWM_DW.obj.SampleTime != ESP32_PWM_P.MATLABSystem_SampleTime) {
    ESP32_PWM_DW.obj.SampleTime = ESP32_PWM_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  stepFunctionLEDC_INTERFACE(fabs(sin(ESP32_PWM_P.SineWave_Freq *
    ESP32_PWM_M->Timing.t[0] + ESP32_PWM_P.SineWave_Phase) *
    ESP32_PWM_P.SineWave_Amp + ESP32_PWM_P.SineWave_Bias), 1.0);

  /* End of MATLABSystem: '<Root>/MATLAB System' */
  {                                    /* Sample time: [0.005s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((ESP32_PWM_M->Timing.clockTick1) * 0.005);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ESP32_PWM_M->Timing.t[0] =
    ((time_T)(++ESP32_PWM_M->Timing.clockTick0)) * ESP32_PWM_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ESP32_PWM_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void ESP32_PWM_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ESP32_PWM_M->solverInfo,
                          &ESP32_PWM_M->Timing.simTimeStep);
    rtsiSetTPtr(&ESP32_PWM_M->solverInfo, &rtmGetTPtr(ESP32_PWM_M));
    rtsiSetStepSizePtr(&ESP32_PWM_M->solverInfo, &ESP32_PWM_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ESP32_PWM_M->solverInfo, (&rtmGetErrorStatus
      (ESP32_PWM_M)));
    rtsiSetRTModelPtr(&ESP32_PWM_M->solverInfo, ESP32_PWM_M);
  }

  rtsiSetSimTimeStep(&ESP32_PWM_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&ESP32_PWM_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&ESP32_PWM_M->solverInfo, false);
  rtsiSetSolverName(&ESP32_PWM_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(ESP32_PWM_M, &ESP32_PWM_M->Timing.tArray[0]);
  rtmSetTFinal(ESP32_PWM_M, -1);
  ESP32_PWM_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  ESP32_PWM_M->Sizes.checksums[0] = (3817861101U);
  ESP32_PWM_M->Sizes.checksums[1] = (365683989U);
  ESP32_PWM_M->Sizes.checksums[2] = (799797628U);
  ESP32_PWM_M->Sizes.checksums[3] = (2095968539U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ESP32_PWM_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ESP32_PWM_M->extModeInfo,
      &ESP32_PWM_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ESP32_PWM_M->extModeInfo, ESP32_PWM_M->Sizes.checksums);
    rteiSetTPtr(ESP32_PWM_M->extModeInfo, rtmGetTPtr(ESP32_PWM_M));
  }

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  ESP32_PWM_DW.obj.matlabCodegenIsDeleted = false;
  ESP32_PWM_DW.obj.SampleTime = ESP32_PWM_P.MATLABSystem_SampleTime;
  ESP32_PWM_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  /*     validateattributes(varargin{1},{'int16'},{'2d','size',[1,1]},'','Duty_Cycle_Percent'); */
  setupFunctionLEDC_INTERFACE(0, 1.0, 19555, 1.0, 12, 1.0, 14, 1.0, 80000000LL,
    1.0);
  ESP32_PWM_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void ESP32_PWM_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!ESP32_PWM_DW.obj.matlabCodegenIsDeleted) {
    ESP32_PWM_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
