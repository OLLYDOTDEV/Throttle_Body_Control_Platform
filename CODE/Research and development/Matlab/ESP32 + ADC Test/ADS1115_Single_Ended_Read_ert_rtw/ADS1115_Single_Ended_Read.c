/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ADS1115_Single_Ended_Read.c
 *
 * Code generated for Simulink model 'ADS1115_Single_Ended_Read'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Jul 23 10:03:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADS1115_Single_Ended_Read.h"
#include "ADS1115_Single_Ended_Read_private.h"

/* Block signals (default storage) */
B_ADS1115_Single_Ended_Read_T ADS1115_Single_Ended_Read_B;

/* Block states (default storage) */
DW_ADS1115_Single_Ended_Read_T ADS1115_Single_Ended_Read_DW;

/* Real-time model */
static RT_MODEL_ADS1115_Single_Ended_T ADS1115_Single_Ended_Read_M_;
RT_MODEL_ADS1115_Single_Ended_T *const ADS1115_Single_Ended_Read_M =
  &ADS1115_Single_Ended_Read_M_;

/* Model step function */
void ADS1115_Single_Ended_Read_step(void)
{
  /* S-Function (ADS1115_Interface): '<Root>/S-Function Builder' */
  ADS1115_Interface_Outputs_wrapper
    (&ADS1115_Single_Ended_Read_B.SFunctionBuilder_o1,
     &ADS1115_Single_Ended_Read_B.SFunctionBuilder_o2,
     &ADS1115_Single_Ended_Read_B.SFunctionBuilder_o3,
     &ADS1115_Single_Ended_Read_B.SFunctionBuilder_o4,
     &ADS1115_Single_Ended_Read_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (ADS1115_Interface): '<Root>/S-Function Builder' */

  /* S-Function "ADS1115_Interface_wrapper" Block: <Root>/S-Function Builder */
  ADS1115_Interface_Update_wrapper
    (&ADS1115_Single_Ended_Read_B.SFunctionBuilder_o1,
     &ADS1115_Single_Ended_Read_B.SFunctionBuilder_o2,
     &ADS1115_Single_Ended_Read_B.SFunctionBuilder_o3,
     &ADS1115_Single_Ended_Read_B.SFunctionBuilder_o4,
     &ADS1115_Single_Ended_Read_DW.SFunctionBuilder_DSTATE);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ADS1115_Single_Ended_Read_M->Timing.taskTime0 =
    ((time_T)(++ADS1115_Single_Ended_Read_M->Timing.clockTick0)) *
    ADS1115_Single_Ended_Read_M->Timing.stepSize0;
}

/* Model initialize function */
void ADS1115_Single_Ended_Read_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ADS1115_Single_Ended_Read_M, -1);
  ADS1115_Single_Ended_Read_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  ADS1115_Single_Ended_Read_M->Sizes.checksums[0] = (417461933U);
  ADS1115_Single_Ended_Read_M->Sizes.checksums[1] = (203071941U);
  ADS1115_Single_Ended_Read_M->Sizes.checksums[2] = (1018046117U);
  ADS1115_Single_Ended_Read_M->Sizes.checksums[3] = (1298657026U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ADS1115_Single_Ended_Read_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ADS1115_Single_Ended_Read_M->extModeInfo,
      &ADS1115_Single_Ended_Read_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ADS1115_Single_Ended_Read_M->extModeInfo,
                        ADS1115_Single_Ended_Read_M->Sizes.checksums);
    rteiSetTPtr(ADS1115_Single_Ended_Read_M->extModeInfo, rtmGetTPtr
                (ADS1115_Single_Ended_Read_M));
  }

  /* InitializeConditions for S-Function (ADS1115_Interface): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        ADS1115_Single_Ended_Read_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void ADS1115_Single_Ended_Read_terminate(void)
{
  /* Terminate for S-Function (ADS1115_Interface): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  ADS1115_Interface_Terminate_wrapper
    (&ADS1115_Single_Ended_Read_DW.SFunctionBuilder_DSTATE);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
