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
 * Model version                  : 1.12
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Aug  1 13:48:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Traceability
 *    2. Debugging
 *    3. Execution efficiency
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
}

/* Model initialize function */
void ADS1115_Single_Ended_Read_initialize(void)
{
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
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
