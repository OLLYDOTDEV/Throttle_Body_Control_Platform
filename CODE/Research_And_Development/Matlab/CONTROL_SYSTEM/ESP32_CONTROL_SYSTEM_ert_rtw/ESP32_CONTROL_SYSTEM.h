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
 * Model version                  : 1.22
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Aug 27 22:03:23 2024
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ESP32_ANALOG_READ.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                               /* ESP32_CONTROL_SYSTEM_COMMON_INCLUDES_ */

#include "ESP32_CONTROL_SYSTEM_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Divide;                       /* '<S8>/Divide' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Saturation;                   /* '<S5>/Saturation' */
  real_T In1;                          /* '<S4>/In1' */
  boolean_T Logic[2];                  /* '<S13>/Logic' */
  boolean_T Logic_b[2];                /* '<S11>/Logic' */
  boolean_T Logic_l[2];                /* '<S12>/Logic' */
} B_ESP32_CONTROL_SYSTEM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ESP32_ANALOG_READ_ESP32_CONTR_T obj;
                              /* '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  ESP32_ANALOG_READ_ESP32_CONTR_T obj_h;
                             /* '<S2>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  codertarget_arduinobase_block_T obj_c;/* '<S3>/Digital Output1' */
  codertarget_arduinobase_block_T obj_m;/* '<S3>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l;/* '<S3>/PWM' */
  real_T TB_maxSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T TB_minSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T maxSet;                       /* '<Root>/Pedal Calibration' */
  real_T minSet;                       /* '<Root>/Pedal Calibration' */
  real_T TimeStampA;                   /* '<S5>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S5>/Derivative' */
  real_T TimeStampB;                   /* '<S5>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S5>/Derivative' */
  int8_T If_ActiveSubsystem;           /* '<Root>/If' */
  boolean_T Memory_PreviousInput;      /* '<S13>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S11>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S12>/Memory' */
} DW_ESP32_CONTROL_SYSTEM_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S5>/Integrator' */
} X_ESP32_CONTROL_SYSTEM_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S5>/Integrator' */
} XDot_ESP32_CONTROL_SYSTEM_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S5>/Integrator' */
} XDis_ESP32_CONTROL_SYSTEM_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_ESP32_CONTROL_SYSTEM_T_ {
  real_T Desire_Max;                   /* Variable: Desire_Max
                                        * Referenced by: '<S1>/Desire Max Value'
                                        */
  real_T Desire_Min;                   /* Variable: Desire_Min
                                        * Referenced by: '<S1>/Desire Min Value'
                                        */
  real_T Direction_Pin;                /* Variable: Direction_Pin
                                        * Referenced by: '<S3>/Direction Pin'
                                        */
  real_T EN_Pin;                       /* Variable: EN_Pin
                                        * Referenced by: '<S3>/Enable Pin'
                                        */
  real_T Kd;                           /* Variable: Kd
                                        * Referenced by: '<S5>/Kd'
                                        */
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<S5>/Ki'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S5>/Kp'
                                        */
  boolean_T SRFlipFlop2_initial_condition;
                                /* Mask Parameter: SRFlipFlop2_initial_condition
                                 * Referenced by: '<S13>/Memory'
                                 */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S11>/Memory'
                                  */
  boolean_T SRFlipFlop1_initial_condition;
                                /* Mask Parameter: SRFlipFlop1_initial_condition
                                 * Referenced by: '<S12>/Memory'
                                 */
  real_T ESP23_ANALOG_READ_DDAppGenerate;/* Expression: -1
                                          * Referenced by: '<S2>/ESP23_ANALOG_READ_DDAppGeneratedBlock1'
                                          */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
  real_T PIDOutput_Y0;                 /* Computed Parameter: PIDOutput_Y0
                                        * Referenced by: '<S5>/PID Output'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 3
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T ESP23_ANALOG_READ_DDAppGenera_p;/* Expression: -1
                                          * Referenced by: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock'
                                          */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S13>/Logic'
                                        */
  boolean_T Logic_table_d[16];         /* Computed Parameter: Logic_table_d
                                        * Referenced by: '<S11>/Logic'
                                        */
  boolean_T Logic_table_d2[16];        /* Computed Parameter: Logic_table_d2
                                        * Referenced by: '<S12>/Logic'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ESP32_CONTROL_SYSTEM_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_ESP32_CONTROL_SYSTEM_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_ESP32_CONTROL_SYSTEM_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_P;

/* Block signals (default storage) */
extern B_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_B;

/* Continuous states (default storage) */
extern X_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_X;

/* Disabled states (default storage) */
extern XDis_ESP32_CONTROL_SYSTEM_T ESP32_CONTROL_SYSTEM_XDis;

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
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display10' : Unused code path elimination
 * Block '<Root>/Display11' : Unused code path elimination
 * Block '<Root>/Display12' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Display4' : Unused code path elimination
 * Block '<Root>/Display5' : Unused code path elimination
 * Block '<Root>/Display6' : Unused code path elimination
 * Block '<Root>/Display7' : Unused code path elimination
 * Block '<Root>/Display8' : Unused code path elimination
 * Block '<Root>/Display9' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S1>/Display4' : Unused code path elimination
 * Block '<S3>/Display3' : Unused code path elimination
 * Block '<S3>/Display4' : Unused code path elimination
 * Block '<S7>/Display' : Unused code path elimination
 * Block '<S7>/Display1' : Unused code path elimination
 * Block '<S7>/Display2' : Unused code path elimination
 * Block '<S8>/Display2' : Unused code path elimination
 * Block '<S8>/Display4' : Unused code path elimination
 */

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
 * '<S2>'   : 'ESP32_CONTROL_SYSTEM/Foot Pedal'
 * '<S3>'   : 'ESP32_CONTROL_SYSTEM/H-Bridge Setting'
 * '<S4>'   : 'ESP32_CONTROL_SYSTEM/If Action Subsystem'
 * '<S5>'   : 'ESP32_CONTROL_SYSTEM/PID Control'
 * '<S6>'   : 'ESP32_CONTROL_SYSTEM/Pedal Calibration'
 * '<S7>'   : 'ESP32_CONTROL_SYSTEM/Subsystem'
 * '<S8>'   : 'ESP32_CONTROL_SYSTEM/TB_Feedbakc Range Conversion'
 * '<S9>'   : 'ESP32_CONTROL_SYSTEM/Throttle Body '
 * '<S10>'  : 'ESP32_CONTROL_SYSTEM/Throttle Body Callibration'
 * '<S11>'  : 'ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop'
 * '<S12>'  : 'ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop1'
 * '<S13>'  : 'ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop2'
 */
#endif                                 /* ESP32_CONTROL_SYSTEM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
