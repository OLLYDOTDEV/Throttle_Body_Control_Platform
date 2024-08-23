/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: CONTROL_SYSTEM_V2.h
 *
 * Code generated for Simulink model 'CONTROL_SYSTEM_V2'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Aug 23 16:14:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef CONTROL_SYSTEM_V2_h_
#define CONTROL_SYSTEM_V2_h_
#ifndef CONTROL_SYSTEM_V2_COMMON_INCLUDES_
#define CONTROL_SYSTEM_V2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "ADS1115_Vread.h"
#endif                                 /* CONTROL_SYSTEM_V2_COMMON_INCLUDES_ */

#include "CONTROL_SYSTEM_V2_types.h"
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
  real_T Add2;                         /* '<S9>/Add2' */
  real_T Add3;                         /* '<S9>/Add3' */
  real_T Divide1;                      /* '<S9>/Divide1' */
  real_T Sum;                          /* '<S9>/Sum' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Add2_c;                       /* '<S1>/Add2' */
  real_T Add3_e;                       /* '<S1>/Add3' */
  real_T Divide1_b;                    /* '<S1>/Divide1' */
  real_T Sum_c;                        /* '<S1>/Sum' */
  real_T EnablePin;                    /* '<S2>/Enable Pin' */
  real_T DirectionPin;                 /* '<S2>/Direction Pin' */
  real_T Switch;                       /* '<S7>/Switch' */
  real_T TB_maxVal;                    /* '<Root>/Throttle Body Callibration' */
  real_T TB_minVal;                    /* '<Root>/Throttle Body Callibration' */
  real_T FP_maxVal;                    /* '<Root>/Pedal Calibration' */
  real_T FP_minVal;                    /* '<Root>/Pedal Calibration' */
  real_T MATLABSystem_o1;              /* '<Root>/MATLAB System' */
  real_T MATLABSystem_o2;              /* '<Root>/MATLAB System' */
  real_T MATLABSystem_o3;              /* '<Root>/MATLAB System' */
  real_T MATLABSystem_o4;              /* '<Root>/MATLAB System' */
  real_T Sum1;                         /* '<S4>/Sum1' */
  real_T FilterCoefficient;            /* '<S49>/Filter Coefficient' */
  real_T Switch2;                      /* '<S12>/Switch2' */
  real_T IntegralGain;                 /* '<S43>/Integral Gain' */
  real_T In1;                          /* '<S3>/In1' */
  boolean_T Memory;                    /* '<S65>/Memory' */
  boolean_T Logic[2];                  /* '<S65>/Logic' */
  boolean_T Memory_h;                  /* '<S63>/Memory' */
  boolean_T Logic_k[2];                /* '<S63>/Logic' */
  boolean_T Memory_n;                  /* '<S64>/Memory' */
  boolean_T Logic_n[2];                /* '<S64>/Logic' */
  boolean_T DigitalInput2;             /* '<S6>/Digital Input2' */
  boolean_T DigitalInput1;             /* '<S6>/Digital Input1' */
  boolean_T DigitalInput;              /* '<S6>/Digital Input' */
} B_CONTROL_SYSTEM_V2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ADS1115_Vread_CONTROL_SYSTEM__T obj; /* '<Root>/MATLAB System' */
  codertarget_arduinobase_blo_i_T obj_d;/* '<S6>/Digital Input2' */
  codertarget_arduinobase_blo_i_T obj_m;/* '<S6>/Digital Input1' */
  codertarget_arduinobase_blo_i_T obj_do;/* '<S6>/Digital Input' */
  codertarget_arduinobase_block_T obj_j;/* '<S2>/Digital Output1' */
  codertarget_arduinobase_block_T obj_a;/* '<S2>/Digital Output' */
  codertarget_arduinobase_inter_T obj_n;/* '<S2>/PWM' */
  real_T TB_maxSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T TB_minSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T Previous_Val;                 /* '<S7>/MATLAB Function' */
  real_T maxSet;                       /* '<Root>/Pedal Calibration' */
  real_T minSet;                       /* '<Root>/Pedal Calibration' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T DelayInput1_DSTATE;        /* '<S66>/Delay Input1' */
  int8_T If_ActiveSubsystem;           /* '<Root>/If' */
  int8_T PIDControl_SubsysRanBC;       /* '<Root>/PID Control' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
  boolean_T Memory_PreviousInput;      /* '<S65>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S63>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S64>/Memory' */
  boolean_T Previous_Val_not_empty;    /* '<S7>/MATLAB Function' */
} DW_CONTROL_SYSTEM_V2_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S46>/Integrator' */
  real_T Filter_CSTATE;                /* '<S41>/Filter' */
} X_CONTROL_SYSTEM_V2_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S46>/Integrator' */
  real_T Filter_CSTATE;                /* '<S41>/Filter' */
} XDot_CONTROL_SYSTEM_V2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S46>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S41>/Filter' */
} XDis_CONTROL_SYSTEM_V2_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_CONTROL_SYSTEM_V2_T_ {
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
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S39>/Derivative Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S43>/Integral Gain'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S41>/Filter'
                               */
  real_T PIDController1_InitialConditi_a;
                              /* Mask Parameter: PIDController1_InitialConditi_a
                               * Referenced by: '<S46>/Integrator'
                               */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S49>/Filter Coefficient'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S51>/Proportional Gain'
                                        */
  boolean_T SRFlipFlop2_initial_condition;
                                /* Mask Parameter: SRFlipFlop2_initial_condition
                                 * Referenced by: '<S65>/Memory'
                                 */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S63>/Memory'
                                  */
  boolean_T SRFlipFlop1_initial_condition;
                                /* Mask Parameter: SRFlipFlop1_initial_condition
                                 * Referenced by: '<S64>/Memory'
                                 */
  boolean_T DetectIncrease1_vinit;     /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S66>/Delay Input1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S3>/Out1'
                                        */
  real_T PIDOutput_Y0;                 /* Computed Parameter: PIDOutput_Y0
                                        * Referenced by: '<S4>/PID Output'
                                        */
  real_T Constant_Value;               /* Expression: 0.01
                                        * Referenced by: '<S4>/Constant'
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
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0.02
                                        * Referenced by: '<S7>/Constant2'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S65>/Logic'
                                        */
  boolean_T Logic_table_p[16];         /* Computed Parameter: Logic_table_p
                                        * Referenced by: '<S63>/Logic'
                                        */
  boolean_T Logic_table_k[16];         /* Computed Parameter: Logic_table_k
                                        * Referenced by: '<S64>/Logic'
                                        */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_CONTROL_SYSTEM_V2_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_CONTROL_SYSTEM_V2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_CONTROL_SYSTEM_V2_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
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
extern P_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_P;

/* Block signals (default storage) */
extern B_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_B;

/* Continuous states (default storage) */
extern X_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_X;

/* Disabled states (default storage) */
extern XDis_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_XDis;

/* Block states (default storage) */
extern DW_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_DW;

/* Model entry point functions */
extern void CONTROL_SYSTEM_V2_initialize(void);
extern void CONTROL_SYSTEM_V2_step(void);
extern void CONTROL_SYSTEM_V2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CONTROL_SYSTEM_V2_T *const CONTROL_SYSTEM_V2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
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
 * '<Root>' : 'CONTROL_SYSTEM_V2'
 * '<S1>'   : 'CONTROL_SYSTEM_V2/FP_Input Range Conversion'
 * '<S2>'   : 'CONTROL_SYSTEM_V2/H-Bridge Setting'
 * '<S3>'   : 'CONTROL_SYSTEM_V2/If Action Subsystem'
 * '<S4>'   : 'CONTROL_SYSTEM_V2/PID Control'
 * '<S5>'   : 'CONTROL_SYSTEM_V2/Pedal Calibration'
 * '<S6>'   : 'CONTROL_SYSTEM_V2/Subsystem'
 * '<S7>'   : 'CONTROL_SYSTEM_V2/Subsystem1'
 * '<S8>'   : 'CONTROL_SYSTEM_V2/Subsystem2'
 * '<S9>'   : 'CONTROL_SYSTEM_V2/TB_Feedbakc Range Conversion'
 * '<S10>'  : 'CONTROL_SYSTEM_V2/Throttle Body Callibration'
 * '<S11>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1'
 * '<S12>'  : 'CONTROL_SYSTEM_V2/PID Control/Saturation Dynamic'
 * '<S13>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Anti-windup'
 * '<S14>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/D Gain'
 * '<S15>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/External Derivative'
 * '<S16>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Filter'
 * '<S17>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Filter ICs'
 * '<S18>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/I Gain'
 * '<S19>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Ideal P Gain'
 * '<S20>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Ideal P Gain Fdbk'
 * '<S21>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Integrator'
 * '<S22>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Integrator ICs'
 * '<S23>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/N Copy'
 * '<S24>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/N Gain'
 * '<S25>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/P Copy'
 * '<S26>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Parallel P Gain'
 * '<S27>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Reset Signal'
 * '<S28>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Saturation'
 * '<S29>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Saturation Fdbk'
 * '<S30>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Sum'
 * '<S31>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Sum Fdbk'
 * '<S32>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Tracking Mode'
 * '<S33>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Tracking Mode Sum'
 * '<S34>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Tsamp - Integral'
 * '<S35>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Tsamp - Ngain'
 * '<S36>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/postSat Signal'
 * '<S37>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/preSat Signal'
 * '<S38>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Anti-windup/Passthrough'
 * '<S39>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/D Gain/Internal Parameters'
 * '<S40>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/External Derivative/Error'
 * '<S41>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Filter/Cont. Filter'
 * '<S42>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S43>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/I Gain/Internal Parameters'
 * '<S44>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Ideal P Gain/Passthrough'
 * '<S45>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S46>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Integrator/Continuous'
 * '<S47>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Integrator ICs/Internal IC'
 * '<S48>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/N Copy/Disabled'
 * '<S49>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/N Gain/Internal Parameters'
 * '<S50>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/P Copy/Disabled'
 * '<S51>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S52>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Reset Signal/Disabled'
 * '<S53>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Saturation/Passthrough'
 * '<S54>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Saturation Fdbk/Disabled'
 * '<S55>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Sum/Sum_PID'
 * '<S56>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Sum Fdbk/Disabled'
 * '<S57>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Tracking Mode/Disabled'
 * '<S58>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S59>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S60>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S61>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/postSat Signal/Forward_Path'
 * '<S62>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller1/preSat Signal/Forward_Path'
 * '<S63>'  : 'CONTROL_SYSTEM_V2/Subsystem/S-R Flip-Flop'
 * '<S64>'  : 'CONTROL_SYSTEM_V2/Subsystem/S-R Flip-Flop1'
 * '<S65>'  : 'CONTROL_SYSTEM_V2/Subsystem/S-R Flip-Flop2'
 * '<S66>'  : 'CONTROL_SYSTEM_V2/Subsystem1/Detect Increase1'
 * '<S67>'  : 'CONTROL_SYSTEM_V2/Subsystem1/MATLAB Function'
 */
#endif                                 /* CONTROL_SYSTEM_V2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
