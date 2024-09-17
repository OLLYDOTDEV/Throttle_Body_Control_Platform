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
 * Model version                  : 1.19
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Sep 12 15:27:52 2024
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ADS1115_Vread.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* CONTROL_SYSTEM_V2_COMMON_INCLUDES_ */

#include "CONTROL_SYSTEM_V2_types.h"
#include <string.h>
#include <stddef.h>
#include "zero_crossing_types.h"

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

/* Block states (default storage) for system '<S20>/NEGATIVE Edge' */
typedef struct {
  boolean_T NEGATIVEEdge_MODE;         /* '<S20>/NEGATIVE Edge' */
} DW_NEGATIVEEdge_CONTROL_SYSTE_T;

/* Block states (default storage) for system '<S20>/POSITIVE Edge' */
typedef struct {
  boolean_T POSITIVEEdge_MODE;         /* '<S20>/POSITIVE Edge' */
} DW_POSITIVEEdge_CONTROL_SYSTE_T;

/* Block signals (default storage) */
typedef struct {
  real_T Divide1;                      /* '<S12>/Divide1' */
  real_T Divide1_p;                    /* '<S4>/Divide1' */
  real_T PulseGenerator;               /* '<S2>/Pulse Generator' */
  real_T PulseGenerator_f;             /* '<S3>/Pulse Generator' */
  real_T TB_minVal;                    /* '<Root>/Throttle Body Callibration' */
  real_T Sum1;                         /* '<S10>/Sum1' */
  real_T FilterCoefficient;            /* '<S76>/Filter Coefficient' */
  real_T Switch2;                      /* '<S39>/Switch2' */
  real_T IntegralGain;                 /* '<S70>/Integral Gain' */
  real_T In1;                          /* '<S8>/In1' */
  real_T MultiportSwitch[2];           /* '<S28>/Multiport Switch' */
  real_T ICic;                         /* '<S33>/IC=ic' */
  real_T Switch;                       /* '<S33>/Switch' */
  real_T MultiportSwitch_k[2];         /* '<S20>/Multiport Switch' */
  real_T ICic_h;                       /* '<S25>/IC=ic' */
  real_T Switch_i;                     /* '<S25>/Switch' */
  real_T FP_minVal;                    /* '<Root>/Foot Pedal Calibration' */
  boolean_T Memory;                    /* '<S34>/Memory' */
  boolean_T Logic[2];                  /* '<S34>/Logic' */
  boolean_T Memory_h;                  /* '<S36>/Memory' */
  boolean_T Logic_h[2];                /* '<S36>/Logic' */
  boolean_T Memory_c;                  /* '<S37>/Memory' */
  boolean_T Logic_d[2];                /* '<S37>/Logic' */
  boolean_T Memory_hc;                 /* '<S35>/Memory' */
  boolean_T Logic_k[2];                /* '<S35>/Logic' */
  boolean_T RelationalOperator1;       /* '<S15>/Relational Operator1' */
  boolean_T Memory_i;                  /* '<S28>/Memory' */
  boolean_T LogicalOperator2_h;        /* '<S17>/Logical Operator2' */
  boolean_T RelationalOperator1_j;     /* '<S31>/Relational Operator1' */
  boolean_T RelationalOperator1_m;     /* '<S30>/Relational Operator1' */
  boolean_T Memory_n;                  /* '<S20>/Memory' */
  boolean_T LogicalOperator2_m;        /* '<S16>/Logical Operator2' */
  boolean_T RelationalOperator1_f;     /* '<S23>/Relational Operator1' */
  boolean_T RelationalOperator1_h;     /* '<S22>/Relational Operator1' */
} B_CONTROL_SYSTEM_V2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ADS1115_Vread_CONTROL_SYSTEM__T obj; /* '<S1>/MATLAB System' */
  codertarget_arduinobase_blo_i_T obj_m;/* '<S7>/Digital Input3' */
  codertarget_arduinobase_blo_i_T obj_d;/* '<S7>/Digital Input2' */
  codertarget_arduinobase_blo_i_T obj_e;/* '<S7>/Digital Input1' */
  codertarget_arduinobase_blo_i_T obj_dc;/* '<S7>/Digital Input' */
  codertarget_arduinobase_block_T obj_c;/* '<S6>/Digital Output1' */
  codertarget_arduinobase_block_T obj_n;/* '<S6>/Digital Output' */
  codertarget_arduinobase_block_T obj_g;/* '<S3>/Digital Output4' */
  codertarget_arduinobase_block_T obj_k;/* '<S2>/Digital Output3' */
  codertarget_arduinobase_block_T obj_cu;/* '<S2>/Digital Output2' */
  codertarget_arduinobase_block_T obj_i;/* '<S2>/Digital Output1' */
  codertarget_arduinobase_block_T obj_b;/* '<S2>/Digital Output' */
  codertarget_arduinobase_inter_T obj_mm;/* '<S6>/PWM' */
  real_T TB_maxSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T TB_minSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T ICic_PreviousInput;           /* '<S33>/IC=ic' */
  real_T ICic_PreviousInput_i;         /* '<S25>/IC=ic' */
  real_T maxSet;                       /* '<Root>/Foot Pedal Calibration' */
  real_T minSet;                       /* '<Root>/Foot Pedal Calibration' */
  int32_T clockTickCounter;            /* '<S2>/Pulse Generator' */
  int32_T clockTickCounter_j;          /* '<S3>/Pulse Generator' */
  int8_T IfCondition_ActiveSubsystem;  /* '<Root>/If Condition' */
  boolean_T Memory_PreviousInput;      /* '<S34>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S36>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S37>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S35>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S28>/Memory' */
  boolean_T Memory_PreviousInput_ds;   /* '<S20>/Memory' */
  boolean_T ONDelay_MODE;              /* '<S15>/ON Delay' */
  boolean_T OFFDelay_MODE;             /* '<S15>/OFF Delay' */
  DW_POSITIVEEdge_CONTROL_SYSTE_T POSITIVEEdge_n;/* '<S28>/POSITIVE Edge' */
  DW_NEGATIVEEdge_CONTROL_SYSTE_T NEGATIVEEdge_c;/* '<S28>/NEGATIVE Edge' */
  DW_POSITIVEEdge_CONTROL_SYSTE_T POSITIVEEdge;/* '<S20>/POSITIVE Edge' */
  DW_NEGATIVEEdge_CONTROL_SYSTE_T NEGATIVEEdge;/* '<S20>/NEGATIVE Edge' */
} DW_CONTROL_SYSTEM_V2_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S73>/Integrator' */
  real_T Filter_CSTATE;                /* '<S68>/Filter' */
} X_CONTROL_SYSTEM_V2_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S73>/Integrator' */
  real_T Filter_CSTATE;                /* '<S68>/Filter' */
} XDot_CONTROL_SYSTEM_V2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S73>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S68>/Filter' */
} XDis_CONTROL_SYSTEM_V2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S29>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_i;/* '<S21>/Triggered Subsystem' */
} PrevZCX_CONTROL_SYSTEM_V2_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters for system: '<S20>/NEGATIVE Edge' */
struct P_NEGATIVEEdge_CONTROL_SYSTEM_T_ {
  boolean_T OUT_Y0;                    /* Computed Parameter: OUT_Y0
                                        * Referenced by: '<S22>/OUT'
                                        */
};

/* Parameters for system: '<S20>/POSITIVE Edge' */
struct P_POSITIVEEdge_CONTROL_SYSTEM_T_ {
  boolean_T OUT_Y0;                    /* Computed Parameter: OUT_Y0
                                        * Referenced by: '<S23>/OUT'
                                        */
};

/* Parameters (default storage) */
struct P_CONTROL_SYSTEM_V2_T_ {
  real_T Desire_Max;                   /* Variable: Desire_Max
                                        * Referenced by: '<S4>/Desire Max Value'
                                        */
  real_T Desire_Min;                   /* Variable: Desire_Min
                                        * Referenced by: '<S4>/Desire Min Value'
                                        */
  real_T Direction_Pin;                /* Variable: Direction_Pin
                                        * Referenced by: '<S6>/Direction Pin'
                                        */
  real_T EN_Pin;                       /* Variable: EN_Pin
                                        * Referenced by: '<S6>/Enable Pin'
                                        */
  real_T Kd;                           /* Variable: Kd
                                        * Referenced by: '<S66>/Derivative Gain'
                                        */
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<S70>/Integral Gain'
                                        */
  real_T Kn;                           /* Variable: Kn
                                        * Referenced by: '<S76>/Filter Coefficient'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S78>/Proportional Gain'
                                        */
  real_T OnDelay_DelayType;            /* Mask Parameter: OnDelay_DelayType
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S68>/Filter'
                               */
  real_T PIDController2_InitialConditi_a;
                              /* Mask Parameter: PIDController2_InitialConditi_a
                               * Referenced by: '<S73>/Integrator'
                               */
  real_T OnDelay_delay;                /* Mask Parameter: OnDelay_delay
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T SampleandHold_ic;             /* Mask Parameter: SampleandHold_ic
                                        * Referenced by: '<S25>/IC=ic'
                                        */
  real_T SampleandHold_ic_k;           /* Mask Parameter: SampleandHold_ic_k
                                        * Referenced by: '<S33>/IC=ic'
                                        */
  real_T EdgeDetector_model;           /* Mask Parameter: EdgeDetector_model
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T EdgeDetector_model_g;         /* Mask Parameter: EdgeDetector_model_g
                                        * Referenced by: '<S28>/Constant1'
                                        */
  boolean_T OnDelay_ic;                /* Mask Parameter: OnDelay_ic
                                        * Referenced by:
                                        *   '<S20>/Memory'
                                        *   '<S28>/Memory'
                                        */
  boolean_T SRFlipFlop3_initial_condition;
                                /* Mask Parameter: SRFlipFlop3_initial_condition
                                 * Referenced by: '<S34>/Memory'
                                 */
  boolean_T SRFlipFlop5_initial_condition;
                                /* Mask Parameter: SRFlipFlop5_initial_condition
                                 * Referenced by: '<S36>/Memory'
                                 */
  boolean_T SRFlipFlop6_initial_condition;
                                /* Mask Parameter: SRFlipFlop6_initial_condition
                                 * Referenced by: '<S37>/Memory'
                                 */
  boolean_T SRFlipFlop4_initial_condition;
                                /* Mask Parameter: SRFlipFlop4_initial_condition
                                 * Referenced by: '<S35>/Memory'
                                 */
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S1>/MATLAB System'
                                        */
  real_T Out1_Y0;                      /* Expression: -1e6
                                        * Referenced by: '<S24>/Out1'
                                        */
  real_T posedge_Value[2];             /* Expression: [1 0]
                                        * Referenced by: '<S20>/pos. edge'
                                        */
  real_T negedge_Value[2];             /* Expression: [0 1]
                                        * Referenced by: '<S20>/neg. edge'
                                        */
  real_T eitheredge_Value[2];          /* Expression: [1 1]
                                        * Referenced by: '<S20>/either edge'
                                        */
  real_T Out1_Y0_l;                    /* Expression: -1e6
                                        * Referenced by: '<S32>/Out1'
                                        */
  real_T posedge_Value_d[2];           /* Expression: [1 0]
                                        * Referenced by: '<S28>/pos. edge'
                                        */
  real_T negedge_Value_f[2];           /* Expression: [0 1]
                                        * Referenced by: '<S28>/neg. edge'
                                        */
  real_T eitheredge_Value_b[2];        /* Expression: [1 1]
                                        * Referenced by: '<S28>/either edge'
                                        */
  real_T Out1_Y0_i;                    /* Computed Parameter: Out1_Y0_i
                                        * Referenced by: '<S8>/Out1'
                                        */
  real_T PIDOutput_Y0;                 /* Computed Parameter: PIDOutput_Y0
                                        * Referenced by: '<S10>/PID Output'
                                        */
  real_T Constant_Value;               /* Expression: 0.01
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S7>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S7>/Digital Input1'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S7>/Digital Input2'
                                        */
  real_T DigitalInput3_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S7>/Digital Input3'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant_Value_jl;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S2>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S2>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S3>/Switch2'
                                        */
  real_T PulseGenerator_Amp_b;         /* Expression: 1
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_l; /* Computed Parameter: PulseGenerator_Period_l
                                   * Referenced by: '<S3>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_e;     /* Computed Parameter: PulseGenerator_Duty_e
                                     * Referenced by: '<S3>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_k;  /* Expression: 0
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant4'
                                        */
  boolean_T OUT_Y0;                    /* Computed Parameter: OUT_Y0
                                        * Referenced by: '<S16>/OUT'
                                        */
  boolean_T OUT_Y0_k;                  /* Computed Parameter: OUT_Y0_k
                                        * Referenced by: '<S17>/OUT'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S34>/Logic'
                                        */
  boolean_T Logic_table_k[16];         /* Computed Parameter: Logic_table_k
                                        * Referenced by: '<S36>/Logic'
                                        */
  boolean_T Logic_table_p[16];         /* Computed Parameter: Logic_table_p
                                        * Referenced by: '<S37>/Logic'
                                        */
  boolean_T Logic_table_g[16];         /* Computed Parameter: Logic_table_g
                                        * Referenced by: '<S35>/Logic'
                                        */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S6>/Gain'
                                        */
  uint8_T Multiply2_Gain;              /* Computed Parameter: Multiply2_Gain
                                        * Referenced by: '<S9>/Multiply2'
                                        */
  uint8_T Multiply1_Gain;              /* Computed Parameter: Multiply1_Gain
                                        * Referenced by: '<S9>/Multiply1'
                                        */
  uint8_T Multiply_Gain;               /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S9>/Multiply'
                                        */
  P_POSITIVEEdge_CONTROL_SYSTEM_T POSITIVEEdge_n;/* '<S28>/POSITIVE Edge' */
  P_NEGATIVEEdge_CONTROL_SYSTEM_T NEGATIVEEdge_c;/* '<S28>/NEGATIVE Edge' */
  P_POSITIVEEdge_CONTROL_SYSTEM_T POSITIVEEdge;/* '<S20>/POSITIVE Edge' */
  P_NEGATIVEEdge_CONTROL_SYSTEM_T NEGATIVEEdge;/* '<S20>/NEGATIVE Edge' */
};

/* Real-time Model Data Structure */
struct tag_RTM_CONTROL_SYSTEM_V2_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_CONTROL_SYSTEM_V2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_CONTROL_SYSTEM_V2_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][2];
  ODE1_IntgData intgData;

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
extern P_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_P;

/* Block signals (default storage) */
extern B_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_B;

/* Continuous states (default storage) */
extern X_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_X;

/* Disabled states (default storage) */
extern XDis_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_XDis;

/* Block states (default storage) */
extern DW_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_CONTROL_SYSTEM_V2_T CONTROL_SYSTEM_V2_PrevZCX;

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
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Error Reading' : Unused code path elimination
 * Block '<S4>/Display1' : Unused code path elimination
 * Block '<S4>/Display3' : Unused code path elimination
 * Block '<Root>/Foot Pedal Maximum Reading' : Unused code path elimination
 * Block '<Root>/Foot Pedal Minimum Reading' : Unused code path elimination
 * Block '<Root>/Foot Pedal Reading' : Unused code path elimination
 * Block '<Root>/Foot Pedal Signal VS Throttle Body Position' : Unused code path elimination
 * Block '<S6>/Display3' : Unused code path elimination
 * Block '<S6>/Display4' : Unused code path elimination
 * Block '<S21>/Constant' : Unused code path elimination
 * Block '<S21>/Relational Operator' : Unused code path elimination
 * Block '<S21>/Sum' : Unused code path elimination
 * Block '<S29>/Constant' : Unused code path elimination
 * Block '<S29>/Relational Operator' : Unused code path elimination
 * Block '<S29>/Sum' : Unused code path elimination
 * Block '<S7>/Display' : Unused code path elimination
 * Block '<S7>/Display1' : Unused code path elimination
 * Block '<S7>/Display2' : Unused code path elimination
 * Block '<S7>/Display3' : Unused code path elimination
 * Block '<Root>/NaN' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/PID Output Reading' : Unused code path elimination
 * Block '<S11>/Abs' : Unused code path elimination
 * Block '<S11>/Divide' : Unused code path elimination
 * Block '<S11>/Gain' : Unused code path elimination
 * Block '<Root>/TB Maximum Reading' : Unused code path elimination
 * Block '<Root>/TB Minimum Reading' : Unused code path elimination
 * Block '<Root>/TB New Range Reading' : Unused code path elimination
 * Block '<S12>/Display1' : Unused code path elimination
 * Block '<S12>/Display3' : Unused code path elimination
 * Block '<Root>/Throttle Body Feeback Reading' : Unused code path elimination
 * Block '<Root>/Throttle Body Feeback Reading (Unused)' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<S15>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S33>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'CONTROL_SYSTEM_V2/Analog Signal'
 * '<S2>'   : 'CONTROL_SYSTEM_V2/Button Control'
 * '<S3>'   : 'CONTROL_SYSTEM_V2/Error Indication'
 * '<S4>'   : 'CONTROL_SYSTEM_V2/FP_Input Range Conversion'
 * '<S5>'   : 'CONTROL_SYSTEM_V2/Foot Pedal Calibration'
 * '<S6>'   : 'CONTROL_SYSTEM_V2/H-Bridge Setting'
 * '<S7>'   : 'CONTROL_SYSTEM_V2/Latching'
 * '<S8>'   : 'CONTROL_SYSTEM_V2/No Control'
 * '<S9>'   : 'CONTROL_SYSTEM_V2/Operation Selector'
 * '<S10>'  : 'CONTROL_SYSTEM_V2/PID Control'
 * '<S11>'  : 'CONTROL_SYSTEM_V2/Subsystem'
 * '<S12>'  : 'CONTROL_SYSTEM_V2/TB_Feedbakc Range Conversion'
 * '<S13>'  : 'CONTROL_SYSTEM_V2/Throttle Body Callibration'
 * '<S14>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay'
 * '<S15>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model'
 * '<S16>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/OFF Delay'
 * '<S17>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/ON Delay'
 * '<S18>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector'
 * '<S19>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/OFF Delay/Sample and Hold'
 * '<S20>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model'
 * '<S21>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model/Internal dirac generator'
 * '<S22>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model/NEGATIVE Edge'
 * '<S23>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model/POSITIVE Edge'
 * '<S24>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model/Internal dirac generator/Triggered Subsystem'
 * '<S25>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/OFF Delay/Sample and Hold/Model'
 * '<S26>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector'
 * '<S27>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/ON Delay/Sample and Hold'
 * '<S28>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model'
 * '<S29>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model/Internal dirac generator'
 * '<S30>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model/NEGATIVE Edge'
 * '<S31>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model/POSITIVE Edge'
 * '<S32>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model/Internal dirac generator/Triggered Subsystem'
 * '<S33>'  : 'CONTROL_SYSTEM_V2/H-Bridge Setting/On Delay/Model/ON Delay/Sample and Hold/Model'
 * '<S34>'  : 'CONTROL_SYSTEM_V2/Latching/S-R Flip-Flop3'
 * '<S35>'  : 'CONTROL_SYSTEM_V2/Latching/S-R Flip-Flop4'
 * '<S36>'  : 'CONTROL_SYSTEM_V2/Latching/S-R Flip-Flop5'
 * '<S37>'  : 'CONTROL_SYSTEM_V2/Latching/S-R Flip-Flop6'
 * '<S38>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2'
 * '<S39>'  : 'CONTROL_SYSTEM_V2/PID Control/Saturation Dynamic'
 * '<S40>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Anti-windup'
 * '<S41>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/D Gain'
 * '<S42>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/External Derivative'
 * '<S43>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Filter'
 * '<S44>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Filter ICs'
 * '<S45>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/I Gain'
 * '<S46>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Ideal P Gain'
 * '<S47>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Ideal P Gain Fdbk'
 * '<S48>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Integrator'
 * '<S49>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Integrator ICs'
 * '<S50>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/N Copy'
 * '<S51>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/N Gain'
 * '<S52>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/P Copy'
 * '<S53>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Parallel P Gain'
 * '<S54>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Reset Signal'
 * '<S55>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Saturation'
 * '<S56>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Saturation Fdbk'
 * '<S57>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Sum'
 * '<S58>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Sum Fdbk'
 * '<S59>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Tracking Mode'
 * '<S60>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Tracking Mode Sum'
 * '<S61>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Tsamp - Integral'
 * '<S62>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Tsamp - Ngain'
 * '<S63>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/postSat Signal'
 * '<S64>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/preSat Signal'
 * '<S65>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Anti-windup/Passthrough'
 * '<S66>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/D Gain/Internal Parameters'
 * '<S67>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/External Derivative/Error'
 * '<S68>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Filter/Cont. Filter'
 * '<S69>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S70>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/I Gain/Internal Parameters'
 * '<S71>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Ideal P Gain/Passthrough'
 * '<S72>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S73>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Integrator/Continuous'
 * '<S74>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Integrator ICs/Internal IC'
 * '<S75>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/N Copy/Disabled'
 * '<S76>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/N Gain/Internal Parameters'
 * '<S77>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/P Copy/Disabled'
 * '<S78>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S79>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Reset Signal/Disabled'
 * '<S80>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Saturation/Passthrough'
 * '<S81>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Saturation Fdbk/Disabled'
 * '<S82>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Sum/Sum_PID'
 * '<S83>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Sum Fdbk/Disabled'
 * '<S84>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Tracking Mode/Disabled'
 * '<S85>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S86>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S87>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S88>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/postSat Signal/Forward_Path'
 * '<S89>'  : 'CONTROL_SYSTEM_V2/PID Control/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* CONTROL_SYSTEM_V2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
