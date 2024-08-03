/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ADS1115_Single_Ended_Read_V2.c
 *
 * Code generated for Simulink model 'ADS1115_Single_Ended_Read_V2'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug  3 13:21:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Traceability
 *    2. Debugging
 *    3. Execution efficiency
 * Validation result: Not run
 */

#include "ADS1115_Single_Ended_Read_V2.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_ADS1115_Single_Ended_Read__T ADS1115_Single_Ended_Read_V2_DW;

/* Real-time model */
static RT_MODEL_ADS1115_Single_Ended_T ADS1115_Single_Ended_Read_V2_M_;
RT_MODEL_ADS1115_Single_Ended_T *const ADS1115_Single_Ended_Read_V2_M =
  &ADS1115_Single_Ended_Read_V2_M_;

/* Model step function */
void ADS1115_Single_Ended_Read_V2_step(void)
{
  real_T b_varargout_1;
  real_T b_varargout_2;
  real_T b_varargout_3;
  real_T b_varargout_4;

  /* MATLABSystem: '<Root>/MATLAB System' */
  if (ADS1115_Single_Ended_Read_V2_DW.obj.SampleTime !=
      ADS1115_Single_Ended_Read_V2_P.MATLABSystem_SampleTime) {
    ADS1115_Single_Ended_Read_V2_DW.obj.SampleTime =
      ADS1115_Single_Ended_Read_V2_P.MATLABSystem_SampleTime;
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
void ADS1115_Single_Ended_Read_V2_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  ADS1115_Single_Ended_Read_V2_DW.obj.matlabCodegenIsDeleted = false;
  ADS1115_Single_Ended_Read_V2_DW.obj.SampleTime =
    ADS1115_Single_Ended_Read_V2_P.MATLABSystem_SampleTime;
  ADS1115_Single_Ended_Read_V2_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionADS1115_Vread(1, 1.0);
  ADS1115_Single_Ended_Read_V2_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void ADS1115_Single_Ended_Read_V2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!ADS1115_Single_Ended_Read_V2_DW.obj.matlabCodegenIsDeleted) {
    ADS1115_Single_Ended_Read_V2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
