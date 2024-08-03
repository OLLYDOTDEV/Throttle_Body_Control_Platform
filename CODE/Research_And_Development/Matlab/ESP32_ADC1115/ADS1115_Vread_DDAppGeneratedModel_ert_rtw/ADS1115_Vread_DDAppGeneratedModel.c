/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ADS1115_Vread_DDAppGeneratedModel.c
 *
 * Code generated for Simulink model 'ADS1115_Vread_DDAppGeneratedModel'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug  3 13:17:21 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADS1115_Vread_DDAppGeneratedModel.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_ADS1115_Vread_DDAppGenerat_T ADS1115_Vread_DDAppGenerated_DW;

/* Real-time model */
static RT_MODEL_ADS1115_Vread_DDAppG_T ADS1115_Vread_DDAppGenerated_M_;
RT_MODEL_ADS1115_Vread_DDAppG_T *const ADS1115_Vread_DDAppGenerated_M =
  &ADS1115_Vread_DDAppGenerated_M_;

/* Model step function */
void ADS1115_Vread_DDAppGeneratedModel_step(void)
{
  real_T b_varargout_1;
  real_T b_varargout_2;
  real_T b_varargout_3;
  real_T b_varargout_4;

  /* MATLABSystem: '<Root>/ADS1115_Vread_DDAppGeneratedBlock' */
  if (ADS1115_Vread_DDAppGenerated_DW.obj.SampleTime !=
      ADS1115_Vread_DDAppGeneratedM_P.ADS1115_Vread_DDAppGeneratedBlo) {
    ADS1115_Vread_DDAppGenerated_DW.obj.SampleTime =
      ADS1115_Vread_DDAppGeneratedM_P.ADS1115_Vread_DDAppGeneratedBlo;
  }

  /*         %% Define output properties */
  b_varargout_1 = 0.0;
  b_varargout_2 = 0.0;
  b_varargout_3 = 0.0;
  b_varargout_4 = 0.0;
  stepFunctionADS1115_Vread(&b_varargout_1, 1.0, &b_varargout_2, 1.0,
    &b_varargout_3, 1.0, &b_varargout_4, 1.0);

  /* End of MATLABSystem: '<Root>/ADS1115_Vread_DDAppGeneratedBlock' */
}

/* Model initialize function */
void ADS1115_Vread_DDAppGeneratedModel_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/ADS1115_Vread_DDAppGeneratedBlock' */
  /*  Constructor */
  ADS1115_Vread_DDAppGenerated_DW.obj.matlabCodegenIsDeleted = false;
  ADS1115_Vread_DDAppGenerated_DW.obj.SampleTime =
    ADS1115_Vread_DDAppGeneratedM_P.ADS1115_Vread_DDAppGeneratedBlo;
  ADS1115_Vread_DDAppGenerated_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionADS1115_Vread(0, 1.0);
  ADS1115_Vread_DDAppGenerated_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void ADS1115_Vread_DDAppGeneratedModel_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/ADS1115_Vread_DDAppGeneratedBlock' */
  if (!ADS1115_Vread_DDAppGenerated_DW.obj.matlabCodegenIsDeleted) {
    ADS1115_Vread_DDAppGenerated_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/ADS1115_Vread_DDAppGeneratedBlock' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
