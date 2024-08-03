/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_ANALOG_READ_DDAppGeneratedModel.c
 *
 * Code generated for Simulink model 'ESP32_ANALOG_READ_DDAppGeneratedModel'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug  3 17:35:33 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ESP32_ANALOG_READ_DDAppGeneratedModel.h"
#include "ESP32_ANALOG_READ_DDAppGeneratedModel_private.h"

/* Block signals (default storage) */
B_ESP32_ANALOG_READ_DDAppGene_T ESP32_ANALOG_READ_DDAppGenera_B;

/* Block states (default storage) */
DW_ESP32_ANALOG_READ_DDAppGen_T ESP32_ANALOG_READ_DDAppGener_DW;

/* Real-time model */
static RT_MODEL_ESP32_ANALOG_READ_DD_T ESP32_ANALOG_READ_DDAppGener_M_;
RT_MODEL_ESP32_ANALOG_READ_DD_T *const ESP32_ANALOG_READ_DDAppGener_M =
  &ESP32_ANALOG_READ_DDAppGener_M_;

/* Model step function */
void ESP32_ANALOG_READ_DDAppGeneratedModel_step(void)
{
  /* MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  if (ESP32_ANALOG_READ_DDAppGener_DW.obj.SampleTime !=
      ESP32_ANALOG_READ_DDAppGenera_P.ESP23_ANALOG_READ_DDAppGenerate) {
    ESP32_ANALOG_READ_DDAppGener_DW.obj.SampleTime =
      ESP32_ANALOG_READ_DDAppGenera_P.ESP23_ANALOG_READ_DDAppGenerate;
  }

  /* MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  /*         %% Define output properties */
  ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenerate = 0.0;
  stepFunctionESP32_ANALOG_READ
    (&ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenerate, 1.0);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ESP32_ANALOG_READ_DDAppGener_M->Timing.taskTime0 =
    ((time_T)(++ESP32_ANALOG_READ_DDAppGener_M->Timing.clockTick0)) *
    ESP32_ANALOG_READ_DDAppGener_M->Timing.stepSize0;
}

/* Model initialize function */
void ESP32_ANALOG_READ_DDAppGeneratedModel_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ESP32_ANALOG_READ_DDAppGener_M, -1);
  ESP32_ANALOG_READ_DDAppGener_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums[0] = (585774591U);
  ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums[1] = (2239361659U);
  ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums[2] = (1703826514U);
  ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums[3] = (2249072454U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ESP32_ANALOG_READ_DDAppGener_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ESP32_ANALOG_READ_DDAppGener_M->extModeInfo,
      &ESP32_ANALOG_READ_DDAppGener_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ESP32_ANALOG_READ_DDAppGener_M->extModeInfo,
                        ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums);
    rteiSetTPtr(ESP32_ANALOG_READ_DDAppGener_M->extModeInfo, rtmGetTPtr
                (ESP32_ANALOG_READ_DDAppGener_M));
  }

  /* Start for MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  /*  Constructor */
  ESP32_ANALOG_READ_DDAppGener_DW.obj.matlabCodegenIsDeleted = false;
  ESP32_ANALOG_READ_DDAppGener_DW.obj.SampleTime =
    ESP32_ANALOG_READ_DDAppGenera_P.ESP23_ANALOG_READ_DDAppGenerate;
  ESP32_ANALOG_READ_DDAppGener_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionESP32_ANALOG_READ(36, 1.0);
  ESP32_ANALOG_READ_DDAppGener_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void ESP32_ANALOG_READ_DDAppGeneratedModel_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  if (!ESP32_ANALOG_READ_DDAppGener_DW.obj.matlabCodegenIsDeleted) {
    ESP32_ANALOG_READ_DDAppGener_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
