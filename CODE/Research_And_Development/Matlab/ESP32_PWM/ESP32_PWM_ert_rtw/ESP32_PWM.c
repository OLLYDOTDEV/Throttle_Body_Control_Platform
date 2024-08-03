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
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug  3 12:55:08 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ESP32_PWM.h"

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
}

/* Model initialize function */
void ESP32_PWM_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  ESP32_PWM_DW.obj.matlabCodegenIsDeleted = false;
  ESP32_PWM_DW.obj.SampleTime = ESP32_PWM_P.MATLABSystem_SampleTime;
  ESP32_PWM_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  /*     validateattributes(varargin{1},{'int16'},{'2d','size',[1,1]},'','Duty_Cycle_Percent'); */
  setupFunctionLEDC_INTERFACE(0, 1.0, 19555, 1.0, 12, 1.0, 0, 1.0, 0LL, 1.0);
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
