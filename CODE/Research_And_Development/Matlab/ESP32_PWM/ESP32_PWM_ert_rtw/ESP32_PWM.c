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
 * Model version                  : 1.5
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug  3 16:10:09 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ESP32_PWM.h"
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
   *  Constant: '<Root>/Constant'
   */
  if (ESP32_PWM_DW.obj.SampleTime != ESP32_PWM_P.MATLABSystem_SampleTime) {
    ESP32_PWM_DW.obj.SampleTime = ESP32_PWM_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  stepFunctionLEDC_INTERFACE(ESP32_PWM_P.Constant_Value, 1.0);

  /* End of MATLABSystem: '<Root>/MATLAB System' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ESP32_PWM_M->Timing.taskTime0 =
    ((time_T)(++ESP32_PWM_M->Timing.clockTick0)) * ESP32_PWM_M->Timing.stepSize0;
}

/* Model initialize function */
void ESP32_PWM_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ESP32_PWM_M, -1);
  ESP32_PWM_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  ESP32_PWM_M->Sizes.checksums[0] = (911647856U);
  ESP32_PWM_M->Sizes.checksums[1] = (1780423543U);
  ESP32_PWM_M->Sizes.checksums[2] = (3593002410U);
  ESP32_PWM_M->Sizes.checksums[3] = (1884289693U);

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
