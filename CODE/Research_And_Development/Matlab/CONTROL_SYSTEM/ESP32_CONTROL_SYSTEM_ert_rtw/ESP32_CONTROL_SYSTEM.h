/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_CONTROL_SYSTEM.h
 *
 * Code generated for Simulink model 'ESP32_CONTROL_SYSTEM'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Aug  9 12:23:33 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ESP32_CONTROL_SYSTEM_h_
#define ESP32_CONTROL_SYSTEM_h_
#ifndef ESP32_CONTROL_SYSTEM_COMMON_INCLUDES_
#define ESP32_CONTROL_SYSTEM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ESP32_ANALOG_READ.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                               /* ESP32_CONTROL_SYSTEM_COMMON_INCLUDES_ */

#include "ESP32_CONTROL_SYSTEM_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Add;                          /* '<S6>/Add' */
  real_T Add1;                         /* '<S6>/Add1' */
  real_T Product;                      /* '<S6>/Product' */
  real_T Add_e;                        /* '<S1>/Add' */
  real_T Add1_m;                       /* '<S1>/Add1' */
  real_T Product_i;                    /* '<S1>/Product' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T EnablePin;                    /* '<S2>/Enable Pin' */
  real_T TB_maxVal;                    /* '<Root>/Pedal Calibration1' */
  real_T TB_minVal;                    /* '<Root>/Pedal Calibration1' */
  real_T FP_maxVal;                    /* '<Root>/Pedal Calibration' */
  real_T FP_minVal;                    /* '<Root>/Pedal Calibration' */
  real_T ESP23_ANALOG_READ_DDAppGenerate;
                           /* '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  real_T ESP23_ANALOG_READ_DDAppGenera_o;
                            /* '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
} B_ESP32_CONTROL_SYSTEM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ESP32_ANALOG_READ_ESP32_CONTR_T obj;
                           /* '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  ESP32_ANALOG_READ_ESP32_CONTR_T obj_p;
                            /* '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  codertarget_arduinobase_block_T obj_c;/* '<S2>/Digital Output1' */
  codertarget_arduinobase_block_T obj_m;/* '<S2>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l;/* '<S2>/PWM' */
  real_T TB_maxSet;                    /* '<Root>/Pedal Calibration1' */
  real_T TB_minSet;                    /* '<Root>/Pedal Calibration1' */
  real_T maxSet;                       /* '<Root>/Pedal Calibration' */
  real_T minSet;                       /* '<Root>/Pedal Calibration' */
} DW_ESP32_CONTROL_SYSTEM_T;

/* Parameters (default storage) */
struct P_ESP32_CONTROL_SYSTEM_T_ {
  real_T Desire_Max;                   /* Variable: Desire_Max
                                        * Referenced by: '<S1>/Desire Max Value'
                                        */
  real_T Desire_Min;                   /* Variable: Desire_Min
                                        * Referenced by: '<S1>/Desire Min Value'
                                        */
  real_T EN_Pin;                       /* Variable: EN_Pin
                                        * Referenced by: '<S2>/Enable Pin'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S3>/Kp'
                                        */
  real_T ESP23_ANALOG_READ_DDAppGenerate;/* Expression: -1
                                          * Referenced by: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock'
                                          */
  real_T ESP23_ANALOG_READ_DDAppGenera_p;/* Expression: -1
                                          * Referenced by: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock1'
                                          */
  real_T Saturation_UpperSat;          /* Expression: 3.2
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ESP32_CONTROL_SYSTEM_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_P;

/* Block signals (default storage) */
extern B_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_B;

/* Block states (default storage) */
extern DW_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_DW;

/* Model entry point functions */
extern void ESP32_CONTROL_SYSTEM_initialize(void);
extern void ESP32_CONTROL_SYSTEM_step(void);
extern void ESP32_CONTROL_SYSTEM_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ESP32_CONTROL_SYSTEM_T *const ESP32_CONTROL_SYSTEM_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ESP32_CONTROL_SYSTEM'
 * '<S1>'   : 'ESP32_CONTROL_SYSTEM/FP_Input Range Conversion'
 * '<S2>'   : 'ESP32_CONTROL_SYSTEM/H-Bridge Setting'
 * '<S3>'   : 'ESP32_CONTROL_SYSTEM/PID Control'
 * '<S4>'   : 'ESP32_CONTROL_SYSTEM/Pedal Calibration'
 * '<S5>'   : 'ESP32_CONTROL_SYSTEM/Pedal Calibration1'
 * '<S6>'   : 'ESP32_CONTROL_SYSTEM/TB_Feedbakc Range Conversion'
 */
#endif                                 /* ESP32_CONTROL_SYSTEM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
