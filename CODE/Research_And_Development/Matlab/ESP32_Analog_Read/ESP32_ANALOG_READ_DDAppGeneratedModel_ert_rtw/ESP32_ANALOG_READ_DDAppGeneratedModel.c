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
 * Model version                  : 1.7
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Aug  6 15:07:06 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ESP32_ANALOG_READ_DDAppGeneratedModel.h"
#include "ESP32_ANALOG_READ_DDAppGeneratedModel_private.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals (default storage) */
B_ESP32_ANALOG_READ_DDAppGene_T ESP32_ANALOG_READ_DDAppGenera_B;

/* Block states (default storage) */
DW_ESP32_ANALOG_READ_DDAppGen_T ESP32_ANALOG_READ_DDAppGener_DW;

/* Real-time model */
static RT_MODEL_ESP32_ANALOG_READ_DD_T ESP32_ANALOG_READ_DDAppGener_M_;
RT_MODEL_ESP32_ANALOG_READ_DD_T *const ESP32_ANALOG_READ_DDAppGener_M =
  &ESP32_ANALOG_READ_DDAppGener_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void ESP32_ANALOG_READ_DDAppGeneratedModel_step(void)
{
  real_T y;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  if (ESP32_ANALOG_READ_DDAppGener_DW.obj_p.SampleTime !=
      ESP32_ANALOG_READ_DDAppGenera_P.ESP23_ANALOG_READ_DDAppGenerate) {
    ESP32_ANALOG_READ_DDAppGener_DW.obj_p.SampleTime =
      ESP32_ANALOG_READ_DDAppGenera_P.ESP23_ANALOG_READ_DDAppGenerate;
  }

  /* MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  /*         %% Define output properties */
  ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenera_o = 0.0;
  stepFunctionESP32_ANALOG_READ(35,
    &ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenera_o, 1.0);

  /* MATLAB Function: '<Root>/Pedal Calibration1' */
  if (ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenera_o >
      ESP32_ANALOG_READ_DDAppGener_DW.TB_maxSet) {
    ESP32_ANALOG_READ_DDAppGener_DW.TB_maxSet =
      ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenera_o;
  }

  if (ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenera_o <
      ESP32_ANALOG_READ_DDAppGener_DW.TB_minSet) {
    ESP32_ANALOG_READ_DDAppGener_DW.TB_minSet =
      ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenera_o;
  }

  ESP32_ANALOG_READ_DDAppGenera_B.TB_maxVal =
    ESP32_ANALOG_READ_DDAppGener_DW.TB_maxSet;
  ESP32_ANALOG_READ_DDAppGenera_B.TB_minVal =
    ESP32_ANALOG_READ_DDAppGener_DW.TB_minSet;

  /* End of MATLAB Function: '<Root>/Pedal Calibration1' */
  /* Sum: '<S6>/Add' */
  ESP32_ANALOG_READ_DDAppGenera_B.Add =
    ESP32_ANALOG_READ_DDAppGenera_B.TB_maxVal -
    ESP32_ANALOG_READ_DDAppGenera_B.TB_minVal;

  /* MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  if (ESP32_ANALOG_READ_DDAppGener_DW.obj.SampleTime !=
      ESP32_ANALOG_READ_DDAppGenera_P.ESP23_ANALOG_READ_DDAppGenera_p) {
    ESP32_ANALOG_READ_DDAppGener_DW.obj.SampleTime =
      ESP32_ANALOG_READ_DDAppGenera_P.ESP23_ANALOG_READ_DDAppGenera_p;
  }

  /* MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  /*         %% Define output properties */
  ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenerate = 0.0;
  stepFunctionESP32_ANALOG_READ(34,
    &ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenerate, 1.0);

  /* MATLAB Function: '<Root>/Pedal Calibration' */
  if (ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenerate >
      ESP32_ANALOG_READ_DDAppGener_DW.maxSet) {
    ESP32_ANALOG_READ_DDAppGener_DW.maxSet =
      ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenerate;
  }

  if (ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenerate <
      ESP32_ANALOG_READ_DDAppGener_DW.minSet) {
    ESP32_ANALOG_READ_DDAppGener_DW.minSet =
      ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenerate;
  }

  ESP32_ANALOG_READ_DDAppGenera_B.FP_maxVal =
    ESP32_ANALOG_READ_DDAppGener_DW.maxSet;
  ESP32_ANALOG_READ_DDAppGenera_B.FP_minVal =
    ESP32_ANALOG_READ_DDAppGener_DW.minSet;

  /* End of MATLAB Function: '<Root>/Pedal Calibration' */

  /* Sum: '<S6>/Add1' incorporates:
   *  Sum: '<S1>/Add1'
   */
  ESP32_ANALOG_READ_DDAppGenera_B.Add1 =
    ESP32_ANALOG_READ_DDAppGenera_B.FP_maxVal -
    ESP32_ANALOG_READ_DDAppGenera_B.FP_minVal;

  /* Product: '<S6>/Product' incorporates:
   *  Product: '<S6>/Divide'
   */
  ESP32_ANALOG_READ_DDAppGenera_B.Product = ESP32_ANALOG_READ_DDAppGenera_B.Add /
    ESP32_ANALOG_READ_DDAppGenera_B.Add1 *
    ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenera_o;

  /* Gain: '<S3>/Kp' incorporates:
   *  Sum: '<S3>/Sum2'
   */
  ESP32_ANALOG_READ_DDAppGenera_B.Saturation =
    (ESP32_ANALOG_READ_DDAppGenera_B.ESP23_ANALOG_READ_DDAppGenerate -
     ESP32_ANALOG_READ_DDAppGenera_B.Product) *
    ESP32_ANALOG_READ_DDAppGenera_P.Kp;

  /* Saturate: '<S3>/Saturation' */
  if (ESP32_ANALOG_READ_DDAppGenera_B.Saturation >
      ESP32_ANALOG_READ_DDAppGenera_P.Saturation_UpperSat) {
    /* Gain: '<S3>/Kp' incorporates:
     *  Saturate: '<S3>/Saturation'
     */
    ESP32_ANALOG_READ_DDAppGenera_B.Saturation =
      ESP32_ANALOG_READ_DDAppGenera_P.Saturation_UpperSat;
  } else if (ESP32_ANALOG_READ_DDAppGenera_B.Saturation <
             ESP32_ANALOG_READ_DDAppGenera_P.Saturation_LowerSat) {
    /* Gain: '<S3>/Kp' incorporates:
     *  Saturate: '<S3>/Saturation'
     */
    ESP32_ANALOG_READ_DDAppGenera_B.Saturation =
      ESP32_ANALOG_READ_DDAppGenera_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S3>/Saturation' */
  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Desire Max Value'
   *  Constant: '<S1>/Desire Min Value'
   */
  ESP32_ANALOG_READ_DDAppGenera_B.Add_e =
    ESP32_ANALOG_READ_DDAppGenera_P.Desire_Max -
    ESP32_ANALOG_READ_DDAppGenera_P.Desire_Min;

  /* Sum: '<S1>/Add1' */
  ESP32_ANALOG_READ_DDAppGenera_B.Add1_m = ESP32_ANALOG_READ_DDAppGenera_B.Add1;

  /* Product: '<S1>/Product' incorporates:
   *  Product: '<S1>/Divide'
   */
  ESP32_ANALOG_READ_DDAppGenera_B.Product_i =
    ESP32_ANALOG_READ_DDAppGenera_B.Add_e /
    ESP32_ANALOG_READ_DDAppGenera_B.Add1_m *
    ESP32_ANALOG_READ_DDAppGenera_B.Saturation;

  /* MATLABSystem: '<S2>/PWM' */
  ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(2U);

  /* Start for MATLABSystem: '<S2>/PWM' */
  if (ESP32_ANALOG_READ_DDAppGenera_B.Product_i <= 255.0) {
    y = ESP32_ANALOG_READ_DDAppGenera_B.Product_i;
  } else {
    y = 255.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  /* MATLABSystem: '<S2>/PWM' */
  MW_PWM_SetDutyCycle
    (ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.PWMDriverObj.MW_PWM_HANDLE, y);

  /* Constant: '<S2>/Enable Pin' */
  ESP32_ANALOG_READ_DDAppGenera_B.EnablePin =
    ESP32_ANALOG_READ_DDAppGenera_P.EN_Pin;

  /* MATLABSystem: '<S2>/Digital Output' */
  y = rt_roundd_snf(ESP32_ANALOG_READ_DDAppGenera_B.EnablePin);
  if (y < 256.0) {
    if (y >= 0.0) {
      tmp = (uint8_T)y;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(4, tmp);

  /* End of MATLABSystem: '<S2>/Digital Output' */
  /* Constant: '<S2>/Direction_Pin' */
  ESP32_ANALOG_READ_DDAppGenera_B.Direction_Pin =
    ESP32_ANALOG_READ_DDAppGenera_P.Direction_Pin;

  /* MATLABSystem: '<S2>/Digital Output1' */
  y = rt_roundd_snf(ESP32_ANALOG_READ_DDAppGenera_B.Direction_Pin);
  if (y < 256.0) {
    if (y >= 0.0) {
      tmp = (uint8_T)y;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(0, tmp);

  /* End of MATLABSystem: '<S2>/Digital Output1' */

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
  ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums[0] = (1674940698U);
  ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums[1] = (1145581760U);
  ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums[2] = (4207951762U);
  ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums[3] = (256666952U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    ESP32_ANALOG_READ_DDAppGener_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ESP32_ANALOG_READ_DDAppGener_M->extModeInfo,
      &ESP32_ANALOG_READ_DDAppGener_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ESP32_ANALOG_READ_DDAppGener_M->extModeInfo,
                        ESP32_ANALOG_READ_DDAppGener_M->Sizes.checksums);
    rteiSetTPtr(ESP32_ANALOG_READ_DDAppGener_M->extModeInfo, rtmGetTPtr
                (ESP32_ANALOG_READ_DDAppGener_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/Pedal Calibration1' */
  ESP32_ANALOG_READ_DDAppGener_DW.TB_minSet = 5.0;

  /* SystemInitialize for MATLAB Function: '<Root>/Pedal Calibration' */
  ESP32_ANALOG_READ_DDAppGener_DW.minSet = 5.0;

  /* Start for MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  /*  Constructor */
  ESP32_ANALOG_READ_DDAppGener_DW.obj_p.matlabCodegenIsDeleted = false;
  ESP32_ANALOG_READ_DDAppGener_DW.obj_p.SampleTime =
    ESP32_ANALOG_READ_DDAppGenera_P.ESP23_ANALOG_READ_DDAppGenerate;
  ESP32_ANALOG_READ_DDAppGener_DW.obj_p.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionESP32_ANALOG_READ(35, 1.0);
  ESP32_ANALOG_READ_DDAppGener_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  /*  Constructor */
  ESP32_ANALOG_READ_DDAppGener_DW.obj.matlabCodegenIsDeleted = false;
  ESP32_ANALOG_READ_DDAppGener_DW.obj.SampleTime =
    ESP32_ANALOG_READ_DDAppGenera_P.ESP23_ANALOG_READ_DDAppGenera_p;
  ESP32_ANALOG_READ_DDAppGener_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionESP32_ANALOG_READ(34, 1.0);
  ESP32_ANALOG_READ_DDAppGener_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM' */
  ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.matlabCodegenIsDeleted = false;
  ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.isInitialized = 1;
  ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_Open(2U, 0.0, 0.0);
  ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  ESP32_ANALOG_READ_DDAppGener_DW.obj_m.matlabCodegenIsDeleted = false;
  ESP32_ANALOG_READ_DDAppGener_DW.obj_m.isInitialized = 1;
  digitalIOSetup(4, 1);
  ESP32_ANALOG_READ_DDAppGener_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output1' */
  ESP32_ANALOG_READ_DDAppGener_DW.obj_c.matlabCodegenIsDeleted = false;
  ESP32_ANALOG_READ_DDAppGener_DW.obj_c.isInitialized = 1;
  digitalIOSetup(0, 1);
  ESP32_ANALOG_READ_DDAppGener_DW.obj_c.isSetupComplete = true;
}

/* Model terminate function */
void ESP32_ANALOG_READ_DDAppGeneratedModel_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  if (!ESP32_ANALOG_READ_DDAppGener_DW.obj_p.matlabCodegenIsDeleted) {
    ESP32_ANALOG_READ_DDAppGener_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  /* Terminate for MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  if (!ESP32_ANALOG_READ_DDAppGener_DW.obj.matlabCodegenIsDeleted) {
    ESP32_ANALOG_READ_DDAppGener_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  /* Terminate for MATLABSystem: '<S2>/PWM' */
  if (!ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.matlabCodegenIsDeleted) {
    ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.matlabCodegenIsDeleted = true;
    if ((ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.isInitialized == 1) &&
        ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.isSetupComplete) {
      ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(2U);
      MW_PWM_SetDutyCycle
        (ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(2U);
      MW_PWM_Close
        (ESP32_ANALOG_READ_DDAppGener_DW.obj_mw.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!ESP32_ANALOG_READ_DDAppGener_DW.obj_m.matlabCodegenIsDeleted) {
    ESP32_ANALOG_READ_DDAppGener_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output1' */
  if (!ESP32_ANALOG_READ_DDAppGener_DW.obj_c.matlabCodegenIsDeleted) {
    ESP32_ANALOG_READ_DDAppGener_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
