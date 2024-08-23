/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_CONTROL_SYSTEM_V2.c
 *
 * Code generated for Simulink model 'ESP32_CONTROL_SYSTEM_V2'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Aug 21 16:28:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ESP32_CONTROL_SYSTEM_V2.h"
#include "ESP32_CONTROL_SYSTEM_V2_types.h"
#include "ESP32_CONTROL_SYSTEM_V2_private.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals (default storage) */
B_ESP32_CONTROL_SYSTEM_V2_T ESP32_CONTROL_SYSTEM_V2_B;

/* Block states (default storage) */
DW_ESP32_CONTROL_SYSTEM_V2_T ESP32_CONTROL_SYSTEM_V2_DW;

/* Real-time model */
static RT_MODEL_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_V2_M_;
RT_MODEL_ESP32_CONTROL_SYSTEM_T *const ESP32_CONTROL_SYSTEM_V2_M =
  &ESP32_CONTROL_SYSTEM_V2_M_;

/* Forward declaration for local functions */
static void ESP32_CONTRO_SystemCore_release(codertarget_arduinobase_inter_T *obj);
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

static void ESP32_CONTRO_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  /* Start for MATLABSystem: '<S2>/PWM' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4U);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }

  /* End of Start for MATLABSystem: '<S2>/PWM' */
}

/* Model step function */
void ESP32_CONTROL_SYSTEM_V2_step(void)
{
  real_T b_varargout_4;
  int32_T rowIdx;
  uint8_T tmp;
  boolean_T c_value;
  boolean_T c_value_0;
  boolean_T c_value_1;
  boolean_T rowIdx_tmp;
  boolean_T rowIdx_tmp_0;
  boolean_T rowIdx_tmp_1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(ESP32_CONTROL_SYSTEM_V2_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ESP32_CONTROL_SYSTEM_V2_DW.PIDControl_SubsysRanBC);

  /* MATLABSystem: '<S6>/Digital Input' */
  if (ESP32_CONTROL_SYSTEM_V2_DW.obj_e.SampleTime !=
      ESP32_CONTROL_SYSTEM_V2_P.DigitalInput_SampleTime) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj_e.SampleTime =
      ESP32_CONTROL_SYSTEM_V2_P.DigitalInput_SampleTime;
  }

  c_value = readDigitalPin(36);

  /* MATLABSystem: '<S6>/Digital Input2' */
  if (ESP32_CONTROL_SYSTEM_V2_DW.obj_b.SampleTime !=
      ESP32_CONTROL_SYSTEM_V2_P.DigitalInput2_SampleTime) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj_b.SampleTime =
      ESP32_CONTROL_SYSTEM_V2_P.DigitalInput2_SampleTime;
  }

  c_value_0 = readDigitalPin(34);

  /* MATLABSystem: '<S6>/Digital Input1' */
  if (ESP32_CONTROL_SYSTEM_V2_DW.obj_c.SampleTime !=
      ESP32_CONTROL_SYSTEM_V2_P.DigitalInput1_SampleTime) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj_c.SampleTime =
      ESP32_CONTROL_SYSTEM_V2_P.DigitalInput1_SampleTime;
  }

  c_value_1 = readDigitalPin(39);

  /* Logic: '<S6>/Logical Operator14' incorporates:
   *  Logic: '<S6>/Logical Operator6'
   *  MATLABSystem: '<S6>/Digital Input2'
   * */
  rowIdx_tmp = !c_value_0;

  /* Logic: '<S6>/Logical Operator13' incorporates:
   *  Logic: '<S6>/Logical Operator10'
   *  MATLABSystem: '<S6>/Digital Input1'
   * */
  rowIdx_tmp_0 = !c_value_1;

  /* CombinatorialLogic: '<S11>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator12'
   *  Logic: '<S6>/Logical Operator13'
   *  Logic: '<S6>/Logical Operator14'
   *  Logic: '<S6>/Logical Operator15'
   *  Logic: '<S6>/Logical Operator3'
   *  MATLABSystem: '<S6>/Digital Input'
   *  MATLABSystem: '<S6>/Digital Input1'
   *  MATLABSystem: '<S6>/Digital Input2'
   *  Memory: '<S11>/Memory'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value && (rowIdx_tmp && rowIdx_tmp_0)) << 1)
                       + (uint32_T)(int8_T)((int8_T)c_value_1 ^ (int8_T)
    c_value_0)) << 1) + ESP32_CONTROL_SYSTEM_V2_DW.Memory_PreviousInput);
  ESP32_CONTROL_SYSTEM_V2_B.Logic[0U] = ESP32_CONTROL_SYSTEM_V2_P.Logic_table
    [(uint32_T)rowIdx];
  ESP32_CONTROL_SYSTEM_V2_B.Logic[1U] = ESP32_CONTROL_SYSTEM_V2_P.Logic_table
    [(uint32_T)rowIdx + 8U];

  /* Logic: '<S6>/Logical Operator7' incorporates:
   *  Logic: '<S6>/Logical Operator11'
   *  MATLABSystem: '<S6>/Digital Input'
   * */
  rowIdx_tmp_1 = !c_value;

  /* CombinatorialLogic: '<S9>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator4'
   *  Logic: '<S6>/Logical Operator5'
   *  Logic: '<S6>/Logical Operator7'
   *  MATLABSystem: '<S6>/Digital Input'
   *  MATLABSystem: '<S6>/Digital Input1'
   *  MATLABSystem: '<S6>/Digital Input2'
   *  Memory: '<S9>/Memory'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_1 && (rowIdx_tmp_1 && rowIdx_tmp)) <<
                        1) + (uint32_T)(int8_T)((int8_T)c_value_0 ^ (int8_T)
    c_value)) << 1) + ESP32_CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_f);
  ESP32_CONTROL_SYSTEM_V2_B.Logic_b[0U] =
    ESP32_CONTROL_SYSTEM_V2_P.Logic_table_d[(uint32_T)rowIdx];
  ESP32_CONTROL_SYSTEM_V2_B.Logic_b[1U] =
    ESP32_CONTROL_SYSTEM_V2_P.Logic_table_d[(uint32_T)rowIdx + 8U];

  /* CombinatorialLogic: '<S10>/Logic' incorporates:
   *  Logic: '<S6>/Logical Operator2'
   *  Logic: '<S6>/Logical Operator8'
   *  Logic: '<S6>/Logical Operator9'
   *  MATLABSystem: '<S6>/Digital Input'
   *  MATLABSystem: '<S6>/Digital Input1'
   *  MATLABSystem: '<S6>/Digital Input2'
   *  Memory: '<S10>/Memory'
   * */
  rowIdx = (int32_T)(((((uint32_T)(c_value_0 && (rowIdx_tmp_0 && rowIdx_tmp_1)) <<
                        1) + (uint32_T)(int8_T)((int8_T)c_value_1 ^ (int8_T)
    c_value)) << 1) + ESP32_CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_n);
  ESP32_CONTROL_SYSTEM_V2_B.Logic_l[0U] =
    ESP32_CONTROL_SYSTEM_V2_P.Logic_table_d2[(uint32_T)rowIdx];
  ESP32_CONTROL_SYSTEM_V2_B.Logic_l[1U] =
    ESP32_CONTROL_SYSTEM_V2_P.Logic_table_d2[(uint32_T)rowIdx + 8U];

  /* MATLABSystem: '<Root>/MATLAB System' */
  if (ESP32_CONTROL_SYSTEM_V2_DW.obj.SampleTime !=
      ESP32_CONTROL_SYSTEM_V2_P.MATLABSystem_SampleTime) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj.SampleTime =
      ESP32_CONTROL_SYSTEM_V2_P.MATLABSystem_SampleTime;
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  /*         %% Define output properties */
  ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o1 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o2 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o3 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  b_varargout_4 = 0.0;

  /* MATLABSystem: '<Root>/MATLAB System' */
  stepFunctionADS1115_Vread(&ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o1, 1.0,
    &ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o2, 1.0,
    &ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o3, 1.0, &b_varargout_4, 1.0);

  /* MATLAB Function: '<Root>/Throttle Body Callibration' */
  if (ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o2 >
      ESP32_CONTROL_SYSTEM_V2_DW.TB_maxSet) {
    ESP32_CONTROL_SYSTEM_V2_DW.TB_maxSet =
      ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o2;
  }

  if (ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o2 <
      ESP32_CONTROL_SYSTEM_V2_DW.TB_minSet) {
    ESP32_CONTROL_SYSTEM_V2_DW.TB_minSet =
      ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o2;
  }

  ESP32_CONTROL_SYSTEM_V2_B.TB_maxVal = ESP32_CONTROL_SYSTEM_V2_DW.TB_maxSet;
  ESP32_CONTROL_SYSTEM_V2_B.TB_minVal = ESP32_CONTROL_SYSTEM_V2_DW.TB_minSet;

  /* End of MATLAB Function: '<Root>/Throttle Body Callibration' */

  /* Sum: '<S7>/Add' */
  ESP32_CONTROL_SYSTEM_V2_B.Add = ESP32_CONTROL_SYSTEM_V2_B.TB_maxVal -
    ESP32_CONTROL_SYSTEM_V2_B.TB_minVal;

  /* MATLAB Function: '<Root>/Pedal Calibration' */
  if (ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o3 >
      ESP32_CONTROL_SYSTEM_V2_DW.maxSet) {
    ESP32_CONTROL_SYSTEM_V2_DW.maxSet =
      ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o3;
  }

  if (ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o3 <
      ESP32_CONTROL_SYSTEM_V2_DW.minSet) {
    ESP32_CONTROL_SYSTEM_V2_DW.minSet =
      ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o3;
  }

  ESP32_CONTROL_SYSTEM_V2_B.FP_maxVal = ESP32_CONTROL_SYSTEM_V2_DW.maxSet;
  ESP32_CONTROL_SYSTEM_V2_B.FP_minVal = ESP32_CONTROL_SYSTEM_V2_DW.minSet;

  /* End of MATLAB Function: '<Root>/Pedal Calibration' */

  /* Sum: '<S7>/Add1' incorporates:
   *  Sum: '<S1>/Add1'
   */
  ESP32_CONTROL_SYSTEM_V2_B.Add1 = ESP32_CONTROL_SYSTEM_V2_B.FP_maxVal -
    ESP32_CONTROL_SYSTEM_V2_B.FP_minVal;

  /* Product: '<S7>/Product' incorporates:
   *  Product: '<S7>/Divide'
   */
  ESP32_CONTROL_SYSTEM_V2_B.Product = ESP32_CONTROL_SYSTEM_V2_B.Add /
    ESP32_CONTROL_SYSTEM_V2_B.Add1 * ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o2;

  /* Sum: '<Root>/Sum2' */
  ESP32_CONTROL_SYSTEM_V2_B.Sum2 = ESP32_CONTROL_SYSTEM_V2_B.MATLABSystem_o3 -
    ESP32_CONTROL_SYSTEM_V2_B.Product;

  /* If: '<Root>/If' */
  if (ESP32_CONTROL_SYSTEM_V2_B.Logic[0]) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* SignalConversion generated from: '<S3>/In1' */
    ESP32_CONTROL_SYSTEM_V2_B.In1 = ESP32_CONTROL_SYSTEM_V2_B.Sum2;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(ESP32_CONTROL_SYSTEM_V2_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem' */
  } else if (ESP32_CONTROL_SYSTEM_V2_B.Logic_b[0]) {
    /* Outputs for IfAction SubSystem: '<Root>/PID Control' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Gain: '<S4>/Kp' */
    ESP32_CONTROL_SYSTEM_V2_B.Saturation = ESP32_CONTROL_SYSTEM_V2_P.Kp *
      ESP32_CONTROL_SYSTEM_V2_B.Sum2;

    /* Saturate: '<S4>/Saturation' */
    if (ESP32_CONTROL_SYSTEM_V2_B.Saturation >
        ESP32_CONTROL_SYSTEM_V2_P.Saturation_UpperSat) {
      /* Gain: '<S4>/Kp' incorporates:
       *  Saturate: '<S4>/Saturation'
       */
      ESP32_CONTROL_SYSTEM_V2_B.Saturation =
        ESP32_CONTROL_SYSTEM_V2_P.Saturation_UpperSat;
    } else if (ESP32_CONTROL_SYSTEM_V2_B.Saturation <
               ESP32_CONTROL_SYSTEM_V2_P.Saturation_LowerSat) {
      /* Gain: '<S4>/Kp' incorporates:
       *  Saturate: '<S4>/Saturation'
       */
      ESP32_CONTROL_SYSTEM_V2_B.Saturation =
        ESP32_CONTROL_SYSTEM_V2_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S4>/Saturation' */
    /* End of Outputs for SubSystem: '<Root>/PID Control' */

    /* Update for IfAction SubSystem: '<Root>/PID Control' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(ESP32_CONTROL_SYSTEM_V2_DW.PIDControl_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/PID Control' */
  }

  /* End of If: '<Root>/If' */
  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Desire Max Value'
   *  Constant: '<S1>/Desire Min Value'
   */
  ESP32_CONTROL_SYSTEM_V2_B.Add_e = ESP32_CONTROL_SYSTEM_V2_P.Desire_Max -
    ESP32_CONTROL_SYSTEM_V2_P.Desire_Min;

  /* Sum: '<S1>/Add1' */
  ESP32_CONTROL_SYSTEM_V2_B.Add1_m = ESP32_CONTROL_SYSTEM_V2_B.Add1;

  /* Switch: '<Root>/Switch1' */
  if (ESP32_CONTROL_SYSTEM_V2_B.Logic_b[0]) {
    b_varargout_4 = ESP32_CONTROL_SYSTEM_V2_B.Saturation;
  } else {
    b_varargout_4 = ESP32_CONTROL_SYSTEM_V2_B.In1;
  }

  /* Product: '<S1>/Product' incorporates:
   *  Product: '<S1>/Divide'
   *  Switch: '<Root>/Switch1'
   */
  ESP32_CONTROL_SYSTEM_V2_B.Product_i = ESP32_CONTROL_SYSTEM_V2_B.Add_e /
    ESP32_CONTROL_SYSTEM_V2_B.Add1_m * b_varargout_4;

  /* Start for MATLABSystem: '<S2>/PWM' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (ESP32_CONTROL_SYSTEM_V2_P.Constant_Value <= 255.0) {
    b_varargout_4 = ESP32_CONTROL_SYSTEM_V2_P.Constant_Value;
  } else {
    b_varargout_4 = 255.0;
  }

  /* MATLABSystem: '<S2>/PWM' */
  ESP32_CONTROL_SYSTEM_V2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (4U);

  /* Start for MATLABSystem: '<S2>/PWM' */
  if (!(b_varargout_4 >= 0.0)) {
    b_varargout_4 = 0.0;
  }

  /* MATLABSystem: '<S2>/PWM' */
  MW_PWM_SetDutyCycle
    (ESP32_CONTROL_SYSTEM_V2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
     -(b_varargout_4 * 255.0 / 255.0));

  /* Constant: '<S2>/Enable Pin' */
  ESP32_CONTROL_SYSTEM_V2_B.EnablePin = ESP32_CONTROL_SYSTEM_V2_P.EN_Pin;

  /* MATLABSystem: '<S2>/Digital Output' */
  b_varargout_4 = rt_roundd_snf(ESP32_CONTROL_SYSTEM_V2_B.EnablePin);
  if (b_varargout_4 < 256.0) {
    if (b_varargout_4 >= 0.0) {
      tmp = (uint8_T)b_varargout_4;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(0, tmp);

  /* End of MATLABSystem: '<S2>/Digital Output' */
  /* Constant: '<S2>/Direction Pin' */
  ESP32_CONTROL_SYSTEM_V2_B.DirectionPin =
    ESP32_CONTROL_SYSTEM_V2_P.Direction_Pin;

  /* MATLABSystem: '<S2>/Digital Output1' */
  b_varargout_4 = rt_roundd_snf(ESP32_CONTROL_SYSTEM_V2_B.DirectionPin);
  if (b_varargout_4 < 256.0) {
    if (b_varargout_4 >= 0.0) {
      tmp = (uint8_T)b_varargout_4;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(16, tmp);

  /* End of MATLABSystem: '<S2>/Digital Output1' */
  /* Update for Memory: '<S11>/Memory' */
  ESP32_CONTROL_SYSTEM_V2_DW.Memory_PreviousInput =
    ESP32_CONTROL_SYSTEM_V2_B.Logic[0];

  /* Update for Memory: '<S9>/Memory' */
  ESP32_CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_f =
    ESP32_CONTROL_SYSTEM_V2_B.Logic_b[0];

  /* Update for Memory: '<S10>/Memory' */
  ESP32_CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_n =
    ESP32_CONTROL_SYSTEM_V2_B.Logic_l[0];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ESP32_CONTROL_SYSTEM_V2_M->Timing.taskTime0 =
    ((time_T)(++ESP32_CONTROL_SYSTEM_V2_M->Timing.clockTick0)) *
    ESP32_CONTROL_SYSTEM_V2_M->Timing.stepSize0;
}

/* Model initialize function */
void ESP32_CONTROL_SYSTEM_V2_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ESP32_CONTROL_SYSTEM_V2_M, -1);
  ESP32_CONTROL_SYSTEM_V2_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  ESP32_CONTROL_SYSTEM_V2_M->Sizes.checksums[0] = (226494377U);
  ESP32_CONTROL_SYSTEM_V2_M->Sizes.checksums[1] = (1773985087U);
  ESP32_CONTROL_SYSTEM_V2_M->Sizes.checksums[2] = (3504204921U);
  ESP32_CONTROL_SYSTEM_V2_M->Sizes.checksums[3] = (592993769U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    ESP32_CONTROL_SYSTEM_V2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &ESP32_CONTROL_SYSTEM_V2_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &ESP32_CONTROL_SYSTEM_V2_DW.PIDControl_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ESP32_CONTROL_SYSTEM_V2_M->extModeInfo,
      &ESP32_CONTROL_SYSTEM_V2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ESP32_CONTROL_SYSTEM_V2_M->extModeInfo,
                        ESP32_CONTROL_SYSTEM_V2_M->Sizes.checksums);
    rteiSetTPtr(ESP32_CONTROL_SYSTEM_V2_M->extModeInfo, rtmGetTPtr
                (ESP32_CONTROL_SYSTEM_V2_M));
  }

  /* InitializeConditions for Memory: '<S11>/Memory' */
  ESP32_CONTROL_SYSTEM_V2_DW.Memory_PreviousInput =
    ESP32_CONTROL_SYSTEM_V2_P.SRFlipFlop2_initial_condition;

  /* InitializeConditions for Memory: '<S9>/Memory' */
  ESP32_CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_f =
    ESP32_CONTROL_SYSTEM_V2_P.SRFlipFlop_initial_condition;

  /* InitializeConditions for Memory: '<S10>/Memory' */
  ESP32_CONTROL_SYSTEM_V2_DW.Memory_PreviousInput_n =
    ESP32_CONTROL_SYSTEM_V2_P.SRFlipFlop1_initial_condition;

  /* SystemInitialize for MATLAB Function: '<Root>/Throttle Body Callibration' */
  ESP32_CONTROL_SYSTEM_V2_DW.TB_minSet = 5.0;

  /* SystemInitialize for MATLAB Function: '<Root>/Pedal Calibration' */
  ESP32_CONTROL_SYSTEM_V2_DW.maxSet = -1.0;
  ESP32_CONTROL_SYSTEM_V2_DW.minSet = 5.0;

  /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S3>/In1' incorporates:
   *  Outport: '<S3>/Out1'
   */
  ESP32_CONTROL_SYSTEM_V2_B.In1 = ESP32_CONTROL_SYSTEM_V2_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/PID Control' */
  /* SystemInitialize for Gain: '<S4>/Kp' incorporates:
   *  Outport: '<S4>/PID Output'
   *  Saturate: '<S4>/Saturation'
   */
  ESP32_CONTROL_SYSTEM_V2_B.Saturation = ESP32_CONTROL_SYSTEM_V2_P.PIDOutput_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/PID Control' */

  /* Start for MATLABSystem: '<S6>/Digital Input' */
  ESP32_CONTROL_SYSTEM_V2_DW.obj_e.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_e.SampleTime =
    ESP32_CONTROL_SYSTEM_V2_P.DigitalInput_SampleTime;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_e.isInitialized = 1;
  digitalIOSetup(36, 0);
  ESP32_CONTROL_SYSTEM_V2_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Digital Input2' */
  ESP32_CONTROL_SYSTEM_V2_DW.obj_b.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_b.SampleTime =
    ESP32_CONTROL_SYSTEM_V2_P.DigitalInput2_SampleTime;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_b.isInitialized = 1;
  digitalIOSetup(34, 0);
  ESP32_CONTROL_SYSTEM_V2_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Digital Input1' */
  ESP32_CONTROL_SYSTEM_V2_DW.obj_c.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_c.SampleTime =
    ESP32_CONTROL_SYSTEM_V2_P.DigitalInput1_SampleTime;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_c.isInitialized = 1;
  digitalIOSetup(39, 0);
  ESP32_CONTROL_SYSTEM_V2_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  ESP32_CONTROL_SYSTEM_V2_DW.obj.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_V2_DW.obj.SampleTime =
    ESP32_CONTROL_SYSTEM_V2_P.MATLABSystem_SampleTime;
  ESP32_CONTROL_SYSTEM_V2_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionADS1115_Vread(0, 1.0);
  ESP32_CONTROL_SYSTEM_V2_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM' */
  ESP32_CONTROL_SYSTEM_V2_DW.obj_l.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_l.isInitialized = 1;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4U,
    19000.0, 255.0);
  ESP32_CONTROL_SYSTEM_V2_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  ESP32_CONTROL_SYSTEM_V2_DW.obj_m.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_m.isInitialized = 1;
  digitalIOSetup(0, 1);
  ESP32_CONTROL_SYSTEM_V2_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output1' */
  ESP32_CONTROL_SYSTEM_V2_DW.obj_cy.matlabCodegenIsDeleted = false;
  ESP32_CONTROL_SYSTEM_V2_DW.obj_cy.isInitialized = 1;
  digitalIOSetup(16, 1);
  ESP32_CONTROL_SYSTEM_V2_DW.obj_cy.isSetupComplete = true;
}

/* Model terminate function */
void ESP32_CONTROL_SYSTEM_V2_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/Digital Input' */
  if (!ESP32_CONTROL_SYSTEM_V2_DW.obj_e.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Input' */

  /* Terminate for MATLABSystem: '<S6>/Digital Input2' */
  if (!ESP32_CONTROL_SYSTEM_V2_DW.obj_b.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Input2' */

  /* Terminate for MATLABSystem: '<S6>/Digital Input1' */
  if (!ESP32_CONTROL_SYSTEM_V2_DW.obj_c.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Input1' */
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!ESP32_CONTROL_SYSTEM_V2_DW.obj.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */
  /* Terminate for MATLABSystem: '<S2>/PWM' */
  if (!ESP32_CONTROL_SYSTEM_V2_DW.obj_l.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj_l.matlabCodegenIsDeleted = true;
    ESP32_CONTRO_SystemCore_release(&ESP32_CONTROL_SYSTEM_V2_DW.obj_l);
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!ESP32_CONTROL_SYSTEM_V2_DW.obj_m.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output1' */
  if (!ESP32_CONTROL_SYSTEM_V2_DW.obj_cy.matlabCodegenIsDeleted) {
    ESP32_CONTROL_SYSTEM_V2_DW.obj_cy.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
