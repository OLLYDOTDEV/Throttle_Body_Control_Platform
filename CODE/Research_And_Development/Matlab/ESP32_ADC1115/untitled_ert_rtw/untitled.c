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
 * C/C++ source code generated on : Sat Aug  3 12:58:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  real_T b_varargout_1;
  real_T b_varargout_2;
  real_T b_varargout_3;
  real_T b_varargout_4;

  /* MATLABSystem: '<Root>/MATLAB System' */
  if (untitled_DW.obj.SampleTime != untitled_P.MATLABSystem_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  b_varargout_1 = 0.0;
  b_varargout_2 = 0.0;
  b_varargout_3 = 0.0;
  b_varargout_4 = 0.0;
  stepFunctionADS1115_Vread(&b_varargout_1, 1.0, &b_varargout_2, 1.0,
    &b_varargout_3, 1.0, &b_varargout_4, 1.0);

  /* End of MATLABSystem: '<Root>/MATLAB System' */
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.MATLABSystem_SampleTime;
  untitled_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionADS1115_Vread(1, 1.0);
  untitled_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */