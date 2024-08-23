/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: untitled.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Aug 21 16:58:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef untitled_h_
#define untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "ADS1115_Vread.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"
#include <string.h>
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

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
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

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Add;                          /* '<S7>/Add' */
  real_T Add1;                         /* '<S7>/Add1' */
  real_T Divide;                       /* '<S7>/Divide' */
  real_T Product;                      /* '<S7>/Product' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Saturation;                   /* '<S4>/Saturation' */
  real_T Add_e;                        /* '<S1>/Add' */
  real_T Add1_m;                       /* '<S1>/Add1' */
  real_T Divide_o;                     /* '<S1>/Divide' */
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
  real_T MATLABSystem_o4;              /* '<Root>/MATLAB System' */
  real_T In1;                          /* '<S3>/In1' */
  boolean_T Memory;                    /* '<S9>/Memory' */
  boolean_T Logic[2];                  /* '<S9>/Logic' */
  boolean_T Memory_a;                  /* '<S11>/Memory' */
  boolean_T Logic_o[2];                /* '<S11>/Logic' */
  boolean_T Memory_n;                  /* '<S10>/Memory' */
  boolean_T Logic_n[2];                /* '<S10>/Logic' */
} B_untitled_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ADS1115_Vread_untitled_T obj;        /* '<Root>/MATLAB System' */
  codertarget_arduinobase_blo_b_T obj_d;/* '<S6>/Digital Input2' */
  codertarget_arduinobase_blo_b_T obj_m;/* '<S6>/Digital Input1' */
  codertarget_arduinobase_blo_b_T obj_do;/* '<S6>/Digital Input' */
  codertarget_arduinobase_block_T obj_j;/* '<S2>/Digital Output1' */
  codertarget_arduinobase_block_T obj_a;/* '<S2>/Digital Output' */
  codertarget_arduinobase_inter_T obj_n;/* '<S2>/PWM' */
  real_T TB_maxSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T TB_minSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T maxSet;                       /* '<Root>/Pedal Calibration' */
  real_T minSet;                       /* '<Root>/Pedal Calibration' */
  boolean_T Memory_PreviousInput;      /* '<S9>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S11>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S10>/Memory' */
} DW_untitled_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
} X_untitled_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
} XDot_untitled_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
} XDis_untitled_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_untitled_T_ {
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
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<S4>/Ki'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S4>/Kp'
                                        */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S9>/Memory'
                                  */
  boolean_T SRFlipFlop2_initial_condition;
                                /* Mask Parameter: SRFlipFlop2_initial_condition
                                 * Referenced by: '<S11>/Memory'
                                 */
  boolean_T SRFlipFlop1_initial_condition;
                                /* Mask Parameter: SRFlipFlop1_initial_condition
                                 * Referenced by: '<S10>/Memory'
                                 */
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S6>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S6>/Digital Input1'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S6>/Digital Input2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 3
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S9>/Logic'
                                        */
  boolean_T Logic_table_m[16];         /* Computed Parameter: Logic_table_m
                                        * Referenced by: '<S11>/Logic'
                                        */
  boolean_T Logic_table_k[16];         /* Computed Parameter: Logic_table_k
                                        * Referenced by: '<S10>/Logic'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_untitled_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_untitled_T *contStateDisabled;
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
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_untitled_T untitled_P;

/* Block signals (default storage) */
extern B_untitled_T untitled_B;

/* Continuous states (default storage) */
extern X_untitled_T untitled_X;

/* Disabled states (default storage) */
extern XDis_untitled_T untitled_XDis;

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;
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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/FP_Input Range Conversion'
 * '<S2>'   : 'untitled/H-Bridge Setting'
 * '<S3>'   : 'untitled/If Action Subsystem'
 * '<S4>'   : 'untitled/PID Control'
 * '<S5>'   : 'untitled/Pedal Calibration'
 * '<S6>'   : 'untitled/Subsystem'
 * '<S7>'   : 'untitled/TB_Feedbakc Range Conversion'
 * '<S8>'   : 'untitled/Throttle Body Callibration'
 * '<S9>'   : 'untitled/Subsystem/S-R Flip-Flop'
 * '<S10>'  : 'untitled/Subsystem/S-R Flip-Flop1'
 * '<S11>'  : 'untitled/Subsystem/S-R Flip-Flop2'
 */
#endif                                 /* untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
