/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_CONTROL_SYSTEM_V2.h
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

#ifndef ESP32_CONTROL_SYSTEM_V2_h_
#define ESP32_CONTROL_SYSTEM_V2_h_
#ifndef ESP32_CONTROL_SYSTEM_V2_COMMON_INCLUDES_
#define ESP32_CONTROL_SYSTEM_V2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "ADS1115_Vread.h"
#endif                            /* ESP32_CONTROL_SYSTEM_V2_COMMON_INCLUDES_ */

#include "ESP32_CONTROL_SYSTEM_V2_types.h"
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
  real_T Add;                          /* '<S7>/Add' */
  real_T Add1;                         /* '<S7>/Add1' */
  real_T Product;                      /* '<S7>/Product' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Add_e;                        /* '<S1>/Add' */
  real_T Add1_m;                       /* '<S1>/Add1' */
  real_T Product_i;                    /* '<S1>/Product' */
  real_T EnablePin;                    /* '<S2>/Enable Pin' */
  real_T DirectionPin;                 /* '<S2>/Direction Pin' */
  real_T TB_maxVal;                    /* '<Root>/Throttle Body Callibration' */
  real_T TB_minVal;                    /* '<Root>/Throttle Body Callibration' */
  real_T FP_maxVal;                    /* '<Root>/Pedal Calibration' */
  real_T FP_minVal;                    /* '<Root>/Pedal Calibration' */
  real_T MATLABSystem_o1;              /* '<Root>/MATLAB System' */
  real_T MATLABSystem_o2;              /* '<Root>/MATLAB System' */
  real_T MATLABSystem_o3;              /* '<Root>/MATLAB System' */
  real_T Saturation;                   /* '<S4>/Saturation' */
  real_T In1;                          /* '<S3>/In1' */
  boolean_T Logic[2];                  /* '<S11>/Logic' */
  boolean_T Logic_b[2];                /* '<S9>/Logic' */
  boolean_T Logic_l[2];                /* '<S10>/Logic' */
} B_ESP32_CONTROL_SYSTEM_V2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ADS1115_Vread_ESP32_CONTROL_S_T obj; /* '<Root>/MATLAB System' */
  codertarget_arduinobase_blo_o_T obj_b;/* '<S6>/Digital Input2' */
  codertarget_arduinobase_blo_o_T obj_c;/* '<S6>/Digital Input1' */
  codertarget_arduinobase_blo_o_T obj_e;/* '<S6>/Digital Input' */
  codertarget_arduinobase_block_T obj_cy;/* '<S2>/Digital Output1' */
  codertarget_arduinobase_block_T obj_m;/* '<S2>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l;/* '<S2>/PWM' */
  real_T TB_maxSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T TB_minSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T maxSet;                       /* '<Root>/Pedal Calibration' */
  real_T minSet;                       /* '<Root>/Pedal Calibration' */
  int8_T PIDControl_SubsysRanBC;       /* '<Root>/PID Control' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
  boolean_T Memory_PreviousInput;      /* '<S11>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S9>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S10>/Memory' */
} DW_ESP32_CONTROL_SYSTEM_V2_T;

/* Parameters (default storage) */
struct P_ESP32_CONTROL_SYSTEM_V2_T_ {
  real_T Desire_Max;                   /* Variable: Desire_Max
                                        * Referenced by: '<S1>/Desire Max Value'
                                        */
  real_T Desire_Min;                   /* Variable: Desire_Min
                                        * Referenced by: '<S1>/Desire Min Value'
                                        */
  real_T Direction_Pin;                /* Variable: Direction_Pin
                                        * Referenced by: '<S2>/Direction Pin'
                                        */
  real_T EN_Pin;                       /* Variable: EN_Pin
                                        * Referenced by: '<S2>/Enable Pin'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S4>/Kp'
                                        */
  boolean_T SRFlipFlop2_initial_condition;
                                /* Mask Parameter: SRFlipFlop2_initial_condition
                                 * Referenced by: '<S11>/Memory'
                                 */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S9>/Memory'
                                  */
  boolean_T SRFlipFlop1_initial_condition;
                                /* Mask Parameter: SRFlipFlop1_initial_condition
                                 * Referenced by: '<S10>/Memory'
                                 */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S3>/Out1'
                                        */
  real_T PIDOutput_Y0;                 /* Computed Parameter: PIDOutput_Y0
                                        * Referenced by: '<S4>/PID Output'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 3
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<S6>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<S6>/Digital Input1'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<S6>/Digital Input2'
                                        */
  real_T Constant_Value;               /* Expression: 100
                                        * Referenced by: '<S2>/Constant'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S11>/Logic'
                                        */
  boolean_T Logic_table_d[16];         /* Computed Parameter: Logic_table_d
                                        * Referenced by: '<S9>/Logic'
                                        */
  boolean_T Logic_table_d2[16];        /* Computed Parameter: Logic_table_d2
                                        * Referenced by: '<S10>/Logic'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ESP32_CONTROL_SYSTEM__T {
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
extern P_ESP32_CONTROL_SYSTEM_V2_T ESP32_CONTROL_SYSTEM_V2_P;

/* Block signals (default storage) */
extern B_ESP32_CONTROL_SYSTEM_V2_T ESP32_CONTROL_SYSTEM_V2_B;

/* Block states (default storage) */
extern DW_ESP32_CONTROL_SYSTEM_V2_T ESP32_CONTROL_SYSTEM_V2_DW;

/* Model entry point functions */
extern void ESP32_CONTROL_SYSTEM_V2_initialize(void);
extern void ESP32_CONTROL_SYSTEM_V2_step(void);
extern void ESP32_CONTROL_SYSTEM_V2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ESP32_CONTROL_SYSTEM_T *const ESP32_CONTROL_SYSTEM_V2_M;
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
 * '<Root>' : 'ESP32_CONTROL_SYSTEM_V2'
 * '<S1>'   : 'ESP32_CONTROL_SYSTEM_V2/FP_Input Range Conversion'
 * '<S2>'   : 'ESP32_CONTROL_SYSTEM_V2/H-Bridge Setting'
 * '<S3>'   : 'ESP32_CONTROL_SYSTEM_V2/If Action Subsystem'
 * '<S4>'   : 'ESP32_CONTROL_SYSTEM_V2/PID Control'
 * '<S5>'   : 'ESP32_CONTROL_SYSTEM_V2/Pedal Calibration'
 * '<S6>'   : 'ESP32_CONTROL_SYSTEM_V2/Subsystem'
 * '<S7>'   : 'ESP32_CONTROL_SYSTEM_V2/TB_Feedbakc Range Conversion'
 * '<S8>'   : 'ESP32_CONTROL_SYSTEM_V2/Throttle Body Callibration'
 * '<S9>'   : 'ESP32_CONTROL_SYSTEM_V2/Subsystem/S-R Flip-Flop'
 * '<S10>'  : 'ESP32_CONTROL_SYSTEM_V2/Subsystem/S-R Flip-Flop1'
 * '<S11>'  : 'ESP32_CONTROL_SYSTEM_V2/Subsystem/S-R Flip-Flop2'
 */
#endif                                 /* ESP32_CONTROL_SYSTEM_V2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
