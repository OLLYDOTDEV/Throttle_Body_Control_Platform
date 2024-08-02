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
 * C/C++ source code generated on : Sat Aug  3 09:21:59 2024
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
#include "ADS1115_Single_Ended_Read_V2_private.h"

/* Block signals (default storage) */
B_ADS1115_Single_Ended_Read_V_T ADS1115_Single_Ended_Read_V2_B;

/* Block states (default storage) */
DW_ADS1115_Single_Ended_Read__T ADS1115_Single_Ended_Read_V2_DW;

/* Real-time model */
static RT_MODEL_ADS1115_Single_Ended_T ADS1115_Single_Ended_Read_V2_M_;
RT_MODEL_ADS1115_Single_Ended_T *const ADS1115_Single_Ended_Read_V2_M =
  &ADS1115_Single_Ended_Read_V2_M_;

/* Model step function */
void ADS1115_Single_Ended_Read_V2_step(void)
{
  /* MATLABSystem: '<Root>/MATLAB System' */
  if (ADS1115_Single_Ended_Read_V2_DW.obj.SampleTime !=
      ADS1115_Single_Ended_Read_V2_P.MATLABSystem_SampleTime) {
    ADS1115_Single_Ended_Read_V2_DW.obj.SampleTime =
      ADS1115_Single_Ended_Read_V2_P.MATLABSystem_SampleTime;
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  /*         %% Define output properties */
  ADS1115_Single_Ended_Read_V2_B.MATLABSystem_o1 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  ADS1115_Single_Ended_Read_V2_B.MATLABSystem_o2 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  ADS1115_Single_Ended_Read_V2_B.MATLABSystem_o3 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  ADS1115_Single_Ended_Read_V2_B.MATLABSystem_o4 = 0.0;
  stepFunctionADS1115_Vread(&ADS1115_Single_Ended_Read_V2_B.MATLABSystem_o1, 1.0,
    &ADS1115_Single_Ended_Read_V2_B.MATLABSystem_o2, 1.0,
    &ADS1115_Single_Ended_Read_V2_B.MATLABSystem_o3, 1.0,
    &ADS1115_Single_Ended_Read_V2_B.MATLABSystem_o4, 1.0);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ADS1115_Single_Ended_Read_V2_M->Timing.taskTime0 =
    ((time_T)(++ADS1115_Single_Ended_Read_V2_M->Timing.clockTick0)) *
    ADS1115_Single_Ended_Read_V2_M->Timing.stepSize0;
}

/* Model initialize function */
void ADS1115_Single_Ended_Read_V2_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ADS1115_Single_Ended_Read_V2_M, -1);
  ADS1115_Single_Ended_Read_V2_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  ADS1115_Single_Ended_Read_V2_M->Sizes.checksums[0] = (858471331U);
  ADS1115_Single_Ended_Read_V2_M->Sizes.checksums[1] = (1178335604U);
  ADS1115_Single_Ended_Read_V2_M->Sizes.checksums[2] = (2582662298U);
  ADS1115_Single_Ended_Read_V2_M->Sizes.checksums[3] = (3532511828U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ADS1115_Single_Ended_Read_V2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ADS1115_Single_Ended_Read_V2_M->extModeInfo,
      &ADS1115_Single_Ended_Read_V2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ADS1115_Single_Ended_Read_V2_M->extModeInfo,
                        ADS1115_Single_Ended_Read_V2_M->Sizes.checksums);
    rteiSetTPtr(ADS1115_Single_Ended_Read_V2_M->extModeInfo, rtmGetTPtr
                (ADS1115_Single_Ended_Read_V2_M));
  }

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
