/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: CONTROL_SYSTEM_V3.h
 *
 * Code generated for Simulink model 'CONTROL_SYSTEM_V3'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Nov  7 23:08:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef CONTROL_SYSTEM_V3_h_
#define CONTROL_SYSTEM_V3_h_
#ifndef CONTROL_SYSTEM_V3_COMMON_INCLUDES_
#define CONTROL_SYSTEM_V3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ADS1115_Vread.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* CONTROL_SYSTEM_V3_COMMON_INCLUDES_ */

#include "CONTROL_SYSTEM_V3_types.h"
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

/* Block states (default storage) for system '<S35>/NEGATIVE Edge' */
typedef struct {
  boolean_T NEGATIVEEdge_MODE;         /* '<S35>/NEGATIVE Edge' */
} DW_NEGATIVEEdge_CONTROL_SYSTE_T;

/* Block states (default storage) for system '<S35>/POSITIVE Edge' */
typedef struct {
  boolean_T POSITIVEEdge_MODE;         /* '<S35>/POSITIVE Edge' */
} DW_POSITIVEEdge_CONTROL_SYSTE_T;

/* Block signals (default storage) */
typedef struct {
  real_T Divide1;                      /* '<S13>/Divide1' */
  real_T Divide1_f;                    /* '<S5>/Divide1' */
  real_T PulseGenerator;               /* '<S3>/Pulse Generator' */
  real_T PulseGenerator_m;             /* '<S4>/Pulse Generator' */
  real_T TB_minVal;                    /* '<Root>/Throttle Body Callibration' */
  real_T dxe[3];                       /* '<S25>/Subtract1' */
  real_T Switch2;                      /* '<S16>/Switch2' */
  real_T Sum1;                         /* '<S10>/Sum1' */
  real_T FilterCoefficient;            /* '<S91>/Filter Coefficient' */
  real_T Switch2_j;                    /* '<S54>/Switch2' */
  real_T IntegralGain;                 /* '<S85>/Integral Gain' */
  real_T Error;                        /* '<S11>/Error' */
  real_T MultiportSwitch[2];           /* '<S43>/Multiport Switch' */
  real_T ICic;                         /* '<S48>/IC=ic' */
  real_T Switch;                       /* '<S48>/Switch' */
  real_T MultiportSwitch_h[2];         /* '<S35>/Multiport Switch' */
  real_T ICic_e;                       /* '<S40>/IC=ic' */
  real_T Switch_d;                     /* '<S40>/Switch' */
  real_T FP_minVal;                    /* '<Root>/Foot Pedal Calibration' */
  real_T b_varargout_3;
  real_T b_varargout_2;
  boolean_T Memory;                    /* '<S49>/Memory' */
  boolean_T Logic[2];                  /* '<S49>/Logic' */
  boolean_T Memory_e;                  /* '<S51>/Memory' */
  boolean_T Logic_e[2];                /* '<S51>/Logic' */
  boolean_T Memory_o;                  /* '<S52>/Memory' */
  boolean_T Logic_d[2];                /* '<S52>/Logic' */
  boolean_T Memory_m;                  /* '<S50>/Memory' */
  boolean_T Logic_l[2];                /* '<S50>/Logic' */
  boolean_T RelationalOperator1;       /* '<S30>/Relational Operator1' */
  boolean_T Memory_j;                  /* '<S43>/Memory' */
  boolean_T LogicalOperator2_f;        /* '<S32>/Logical Operator2' */
  boolean_T RelationalOperator1_p;     /* '<S46>/Relational Operator1' */
  boolean_T RelationalOperator1_h;     /* '<S45>/Relational Operator1' */
  boolean_T Memory_k;                  /* '<S35>/Memory' */
  boolean_T LogicalOperator2_l;        /* '<S31>/Logical Operator2' */
  boolean_T RelationalOperator1_i;     /* '<S38>/Relational Operator1' */
  boolean_T RelationalOperator1_d;     /* '<S37>/Relational Operator1' */
} B_CONTROL_SYSTEM_V3_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ADS1115_Vread_CONTROL_SYSTEM__T obj; /* '<S2>/MATLAB System' */
  codertarget_arduinobase_blo_c_T obj_f;/* '<S8>/Digital Input3' */
  codertarget_arduinobase_blo_c_T obj_h;/* '<S8>/Digital Input2' */
  codertarget_arduinobase_blo_c_T obj_hd;/* '<S8>/Digital Input1' */
  codertarget_arduinobase_blo_c_T obj_c;/* '<S8>/Digital Input' */
  codertarget_arduinobase_block_T obj_l;/* '<S7>/Digital Output1' */
  codertarget_arduinobase_block_T obj_b;/* '<S7>/Digital Output' */
  codertarget_arduinobase_block_T obj_p;/* '<S4>/Digital Output4' */
  codertarget_arduinobase_block_T obj_m;/* '<S3>/Digital Output3' */
  codertarget_arduinobase_block_T obj_pz;/* '<S3>/Digital Output2' */
  codertarget_arduinobase_block_T obj_f2;/* '<S3>/Digital Output1' */
  codertarget_arduinobase_block_T obj_j;/* '<S3>/Digital Output' */
  codertarget_arduinobase_inter_T obj_e;/* '<S7>/PWM' */
  real_T TB_maxSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T TB_minSet;                    /* '<Root>/Throttle Body Callibration' */
  real_T ICic_PreviousInput;           /* '<S48>/IC=ic' */
  real_T ICic_PreviousInput_h;         /* '<S40>/IC=ic' */
  real_T maxSet;                       /* '<Root>/Foot Pedal Calibration' */
  real_T minSet;                       /* '<Root>/Foot Pedal Calibration' */
  int32_T clockTickCounter;            /* '<S3>/Pulse Generator' */
  int32_T clockTickCounter_n;          /* '<S4>/Pulse Generator' */
  int8_T IfCondition_ActiveSubsystem;  /* '<Root>/If Condition' */
  boolean_T Memory_PreviousInput;      /* '<S49>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S51>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S52>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S50>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S43>/Memory' */
  boolean_T Memory_PreviousInput_k;    /* '<S35>/Memory' */
  boolean_T ONDelay_MODE;              /* '<S30>/ON Delay' */
  boolean_T OFFDelay_MODE;             /* '<S30>/OFF Delay' */
  DW_POSITIVEEdge_CONTROL_SYSTE_T POSITIVEEdge_j;/* '<S43>/POSITIVE Edge' */
  DW_NEGATIVEEdge_CONTROL_SYSTE_T NEGATIVEEdge_d;/* '<S43>/NEGATIVE Edge' */
  DW_POSITIVEEdge_CONTROL_SYSTE_T POSITIVEEdge;/* '<S35>/POSITIVE Edge' */
  DW_NEGATIVEEdge_CONTROL_SYSTE_T NEGATIVEEdge;/* '<S35>/NEGATIVE Edge' */
} DW_CONTROL_SYSTEM_V3_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S25>/Integrator' */
  real_T Integrator_CSTATE_b;          /* '<S88>/Integrator' */
  real_T Filter_CSTATE;                /* '<S83>/Filter' */
} X_CONTROL_SYSTEM_V3_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S25>/Integrator' */
  real_T Integrator_CSTATE_b;          /* '<S88>/Integrator' */
  real_T Filter_CSTATE;                /* '<S83>/Filter' */
} XDot_CONTROL_SYSTEM_V3_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S25>/Integrator' */
  boolean_T Integrator_CSTATE_b;       /* '<S88>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S83>/Filter' */
} XDis_CONTROL_SYSTEM_V3_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S44>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_f;/* '<S36>/Triggered Subsystem' */
} PrevZCX_CONTROL_SYSTEM_V3_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S35>/NEGATIVE Edge' */
struct P_NEGATIVEEdge_CONTROL_SYSTEM_T_ {
  boolean_T OUT_Y0;                    /* Computed Parameter: OUT_Y0
                                        * Referenced by: '<S37>/OUT'
                                        */
};

/* Parameters for system: '<S35>/POSITIVE Edge' */
struct P_POSITIVEEdge_CONTROL_SYSTEM_T_ {
  boolean_T OUT_Y0;                    /* Computed Parameter: OUT_Y0
                                        * Referenced by: '<S38>/OUT'
                                        */
};

/* Parameters (default storage) */
struct P_CONTROL_SYSTEM_V3_T_ {
  real_T Desire_Max;                   /* Variable: Desire_Max
                                        * Referenced by: '<S5>/Desire Max Value'
                                        */
  real_T Desire_Min;                   /* Variable: Desire_Min
                                        * Referenced by: '<S5>/Desire Min Value'
                                        */
  real_T Direction_Pin;                /* Variable: Direction_Pin
                                        * Referenced by: '<S7>/Direction Pin'
                                        */
  real_T EN_Pin;                       /* Variable: EN_Pin
                                        * Referenced by: '<S7>/Enable Pin'
                                        */
  real_T Kd;                           /* Variable: Kd
                                        * Referenced by: '<S81>/Derivative Gain'
                                        */
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<S85>/Integral Gain'
                                        */
  real_T Kn;                           /* Variable: Kn
                                        * Referenced by: '<S91>/Filter Coefficient'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S93>/Proportional Gain'
                                        */
  real_T OnDelay_DelayType;            /* Mask Parameter: OnDelay_DelayType
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S83>/Filter'
                               */
  real_T PIDController1_InitialConditi_g;
                              /* Mask Parameter: PIDController1_InitialConditi_g
                               * Referenced by: '<S88>/Integrator'
                               */
  real_T OnDelay_delay;                /* Mask Parameter: OnDelay_delay
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T SampleandHold_ic;             /* Mask Parameter: SampleandHold_ic
                                        * Referenced by: '<S40>/IC=ic'
                                        */
  real_T SampleandHold_ic_g;           /* Mask Parameter: SampleandHold_ic_g
                                        * Referenced by: '<S48>/IC=ic'
                                        */
  real_T EdgeDetector_model;           /* Mask Parameter: EdgeDetector_model
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T EdgeDetector_model_j;         /* Mask Parameter: EdgeDetector_model_j
                                        * Referenced by: '<S43>/Constant1'
                                        */
  real_T Observer_x0;                  /* Mask Parameter: Observer_x0
                                        * Referenced by: '<S25>/Integrator'
                                        */
  boolean_T OnDelay_ic;                /* Mask Parameter: OnDelay_ic
                                        * Referenced by:
                                        *   '<S35>/Memory'
                                        *   '<S43>/Memory'
                                        */
  boolean_T SRFlipFlop3_initial_condition;
                                /* Mask Parameter: SRFlipFlop3_initial_condition
                                 * Referenced by: '<S49>/Memory'
                                 */
  boolean_T SRFlipFlop5_initial_condition;
                                /* Mask Parameter: SRFlipFlop5_initial_condition
                                 * Referenced by: '<S51>/Memory'
                                 */
  boolean_T SRFlipFlop6_initial_condition;
                                /* Mask Parameter: SRFlipFlop6_initial_condition
                                 * Referenced by: '<S52>/Memory'
                                 */
  boolean_T SRFlipFlop4_initial_condition;
                                /* Mask Parameter: SRFlipFlop4_initial_condition
                                 * Referenced by: '<S50>/Memory'
                                 */
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S2>/MATLAB System'
                                        */
  real_T Out1_Y0;                      /* Expression: -1e6
                                        * Referenced by: '<S39>/Out1'
                                        */
  real_T posedge_Value[2];             /* Expression: [1 0]
                                        * Referenced by: '<S35>/pos. edge'
                                        */
  real_T negedge_Value[2];             /* Expression: [0 1]
                                        * Referenced by: '<S35>/neg. edge'
                                        */
  real_T eitheredge_Value[2];          /* Expression: [1 1]
                                        * Referenced by: '<S35>/either edge'
                                        */
  real_T Out1_Y0_j;                    /* Expression: -1e6
                                        * Referenced by: '<S47>/Out1'
                                        */
  real_T posedge_Value_p[2];           /* Expression: [1 0]
                                        * Referenced by: '<S43>/pos. edge'
                                        */
  real_T negedge_Value_h[2];           /* Expression: [0 1]
                                        * Referenced by: '<S43>/neg. edge'
                                        */
  real_T eitheredge_Value_b[2];        /* Expression: [1 1]
                                        * Referenced by: '<S43>/either edge'
                                        */
  real_T Propotional_Y0;               /* Computed Parameter: Propotional_Y0
                                        * Referenced by: '<S11>/Propotional'
                                        */
  real_T PIDOutput_Y0;                 /* Computed Parameter: PIDOutput_Y0
                                        * Referenced by: '<S10>/PID Output'
                                        */
  real_T Constant_Value;               /* Expression: 0.01
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T ADRCOutput_Y0;                /* Computed Parameter: ADRCOutput_Y0
                                        * Referenced by: '<S1>/ADRC Output'
                                        */
  real_T Constant_Value_i[9];          /* Expression: a
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: wc^2
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2*wc
                                        * Referenced by: '<S23>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/b0
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real_T Constant1_Value[3];           /* Expression: b
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: d
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T Constant2_Value[3];           /* Expression: c
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T Constant8_Value[3];           /* Expression: l
                                        * Referenced by: '<S24>/Constant8'
                                        */
  real_T Constant_Value_ih;            /* Expression: 2
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S8>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S8>/Digital Input1'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S8>/Digital Input2'
                                        */
  real_T DigitalInput3_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S8>/Digital Input3'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S3>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S3>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Constant2_Value_j;            /* Expression: 1
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Constant3_Value_f;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch2'
                                        */
  real_T PulseGenerator_Amp_n;         /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_d; /* Computed Parameter: PulseGenerator_Period_d
                                   * Referenced by: '<S4>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_e;     /* Computed Parameter: PulseGenerator_Duty_e
                                     * Referenced by: '<S4>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_h;  /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant4'
                                        */
  boolean_T OUT_Y0;                    /* Computed Parameter: OUT_Y0
                                        * Referenced by: '<S31>/OUT'
                                        */
  boolean_T OUT_Y0_a;                  /* Computed Parameter: OUT_Y0_a
                                        * Referenced by: '<S32>/OUT'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S49>/Logic'
                                        */
  boolean_T Logic_table_p[16];         /* Computed Parameter: Logic_table_p
                                        * Referenced by: '<S51>/Logic'
                                        */
  boolean_T Logic_table_b[16];         /* Computed Parameter: Logic_table_b
                                        * Referenced by: '<S52>/Logic'
                                        */
  boolean_T Logic_table_bm[16];        /* Computed Parameter: Logic_table_bm
                                        * Referenced by: '<S50>/Logic'
                                        */
  uint8_T Gain_Gain_k;                 /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S7>/Gain'
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
  P_POSITIVEEdge_CONTROL_SYSTEM_T POSITIVEEdge_j;/* '<S43>/POSITIVE Edge' */
  P_NEGATIVEEdge_CONTROL_SYSTEM_T NEGATIVEEdge_d;/* '<S43>/NEGATIVE Edge' */
  P_POSITIVEEdge_CONTROL_SYSTEM_T POSITIVEEdge;/* '<S35>/POSITIVE Edge' */
  P_NEGATIVEEdge_CONTROL_SYSTEM_T NEGATIVEEdge;/* '<S35>/NEGATIVE Edge' */
};

/* Real-time Model Data Structure */
struct tag_RTM_CONTROL_SYSTEM_V3_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_CONTROL_SYSTEM_V3_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_CONTROL_SYSTEM_V3_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[5];
  real_T odeF[3][5];
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
extern P_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_P;

/* Block signals (default storage) */
extern B_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_B;

/* Continuous states (default storage) */
extern X_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_X;

/* Disabled states (default storage) */
extern XDis_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_XDis;

/* Block states (default storage) */
extern DW_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_CONTROL_SYSTEM_V3_T CONTROL_SYSTEM_V3_PrevZCX;

/* Model entry point functions */
extern void CONTROL_SYSTEM_V3_initialize(void);
extern void CONTROL_SYSTEM_V3_step(void);
extern void CONTROL_SYSTEM_V3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CONTROL_SYSTEM_V3_T *const CONTROL_SYSTEM_V3_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Error Reading' : Unused code path elimination
 * Block '<S5>/Display1' : Unused code path elimination
 * Block '<S5>/Display3' : Unused code path elimination
 * Block '<Root>/Foot Pedal Maximum Reading' : Unused code path elimination
 * Block '<Root>/Foot Pedal Minimum Reading' : Unused code path elimination
 * Block '<Root>/Foot Pedal Reading' : Unused code path elimination
 * Block '<Root>/Foot Pedal Signal VS Throttle Body Position' : Unused code path elimination
 * Block '<S7>/Display3' : Unused code path elimination
 * Block '<S7>/Display4' : Unused code path elimination
 * Block '<S36>/Constant' : Unused code path elimination
 * Block '<S36>/Relational Operator' : Unused code path elimination
 * Block '<S36>/Sum' : Unused code path elimination
 * Block '<S44>/Constant' : Unused code path elimination
 * Block '<S44>/Relational Operator' : Unused code path elimination
 * Block '<S44>/Sum' : Unused code path elimination
 * Block '<Root>/NaN' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/PID Output Reading' : Unused code path elimination
 * Block '<Root>/Percentage Error' : Unused code path elimination
 * Block '<S12>/Abs' : Unused code path elimination
 * Block '<S12>/Divide' : Unused code path elimination
 * Block '<S12>/Gain' : Unused code path elimination
 * Block '<Root>/TB Maximum Reading' : Unused code path elimination
 * Block '<Root>/TB Minimum Reading' : Unused code path elimination
 * Block '<Root>/TB New Range Reading' : Unused code path elimination
 * Block '<S13>/Display1' : Unused code path elimination
 * Block '<S13>/Display3' : Unused code path elimination
 * Block '<Root>/Throttle Body Feeback Reading' : Unused code path elimination
 * Block '<Root>/Throttle Body Feeback Reading (Unused)' : Unused code path elimination
 * Block '<S30>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S35>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S40>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S43>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S48>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'CONTROL_SYSTEM_V3'
 * '<S1>'   : 'CONTROL_SYSTEM_V3/ADRC Control'
 * '<S2>'   : 'CONTROL_SYSTEM_V3/Analog Signal'
 * '<S3>'   : 'CONTROL_SYSTEM_V3/Button Control LED'
 * '<S4>'   : 'CONTROL_SYSTEM_V3/Error Indication'
 * '<S5>'   : 'CONTROL_SYSTEM_V3/FP_Input Range Conversion'
 * '<S6>'   : 'CONTROL_SYSTEM_V3/Foot Pedal Calibration'
 * '<S7>'   : 'CONTROL_SYSTEM_V3/H-Bridge Setting'
 * '<S8>'   : 'CONTROL_SYSTEM_V3/Latching'
 * '<S9>'   : 'CONTROL_SYSTEM_V3/Operation Selector'
 * '<S10>'  : 'CONTROL_SYSTEM_V3/PID Control'
 * '<S11>'  : 'CONTROL_SYSTEM_V3/Propotional'
 * '<S12>'  : 'CONTROL_SYSTEM_V3/Subsystem'
 * '<S13>'  : 'CONTROL_SYSTEM_V3/TB_Feedbakc Range Conversion'
 * '<S14>'  : 'CONTROL_SYSTEM_V3/Throttle Body Callibration'
 * '<S15>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control'
 * '<S16>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Saturation Dynamic'
 * '<S17>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC'
 * '<S18>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/error feedback'
 * '<S19>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/extended state observer'
 * '<S20>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/input saturation'
 * '<S21>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/rZOH'
 * '<S22>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/yZOH'
 * '<S23>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/error feedback/seccond order'
 * '<S24>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/extended state observer/continuous time'
 * '<S25>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/extended state observer/continuous time/Observer'
 * '<S26>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/input saturation/passthrough'
 * '<S27>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/rZOH/passthrough'
 * '<S28>'  : 'CONTROL_SYSTEM_V3/ADRC Control/Active Disturbance Rejection Control/ADRC/yZOH/passthrough'
 * '<S29>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay'
 * '<S30>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model'
 * '<S31>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/OFF Delay'
 * '<S32>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/ON Delay'
 * '<S33>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector'
 * '<S34>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/OFF Delay/Sample and Hold'
 * '<S35>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model'
 * '<S36>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model/Internal dirac generator'
 * '<S37>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model/NEGATIVE Edge'
 * '<S38>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model/POSITIVE Edge'
 * '<S39>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/OFF Delay/Edge Detector/Model/Internal dirac generator/Triggered Subsystem'
 * '<S40>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/OFF Delay/Sample and Hold/Model'
 * '<S41>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector'
 * '<S42>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/ON Delay/Sample and Hold'
 * '<S43>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model'
 * '<S44>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model/Internal dirac generator'
 * '<S45>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model/NEGATIVE Edge'
 * '<S46>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model/POSITIVE Edge'
 * '<S47>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/ON Delay/Edge Detector/Model/Internal dirac generator/Triggered Subsystem'
 * '<S48>'  : 'CONTROL_SYSTEM_V3/H-Bridge Setting/On Delay/Model/ON Delay/Sample and Hold/Model'
 * '<S49>'  : 'CONTROL_SYSTEM_V3/Latching/S-R Flip-Flop3'
 * '<S50>'  : 'CONTROL_SYSTEM_V3/Latching/S-R Flip-Flop4'
 * '<S51>'  : 'CONTROL_SYSTEM_V3/Latching/S-R Flip-Flop5'
 * '<S52>'  : 'CONTROL_SYSTEM_V3/Latching/S-R Flip-Flop6'
 * '<S53>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1'
 * '<S54>'  : 'CONTROL_SYSTEM_V3/PID Control/Saturation Dynamic'
 * '<S55>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Anti-windup'
 * '<S56>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/D Gain'
 * '<S57>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/External Derivative'
 * '<S58>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Filter'
 * '<S59>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Filter ICs'
 * '<S60>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/I Gain'
 * '<S61>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Ideal P Gain'
 * '<S62>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Ideal P Gain Fdbk'
 * '<S63>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Integrator'
 * '<S64>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Integrator ICs'
 * '<S65>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/N Copy'
 * '<S66>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/N Gain'
 * '<S67>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/P Copy'
 * '<S68>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Parallel P Gain'
 * '<S69>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Reset Signal'
 * '<S70>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Saturation'
 * '<S71>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Saturation Fdbk'
 * '<S72>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Sum'
 * '<S73>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Sum Fdbk'
 * '<S74>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Tracking Mode'
 * '<S75>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Tracking Mode Sum'
 * '<S76>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Tsamp - Integral'
 * '<S77>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Tsamp - Ngain'
 * '<S78>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/postSat Signal'
 * '<S79>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/preSat Signal'
 * '<S80>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Anti-windup/Passthrough'
 * '<S81>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/D Gain/Internal Parameters'
 * '<S82>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/External Derivative/Error'
 * '<S83>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Filter/Cont. Filter'
 * '<S84>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S85>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/I Gain/Internal Parameters'
 * '<S86>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Ideal P Gain/Passthrough'
 * '<S87>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S88>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Integrator/Continuous'
 * '<S89>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Integrator ICs/Internal IC'
 * '<S90>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/N Copy/Disabled'
 * '<S91>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/N Gain/Internal Parameters'
 * '<S92>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/P Copy/Disabled'
 * '<S93>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S94>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Reset Signal/Disabled'
 * '<S95>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Saturation/Passthrough'
 * '<S96>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Saturation Fdbk/Disabled'
 * '<S97>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Sum/Sum_PID'
 * '<S98>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Sum Fdbk/Disabled'
 * '<S99>'  : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Tracking Mode/Disabled'
 * '<S100>' : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S102>' : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S103>' : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/postSat Signal/Forward_Path'
 * '<S104>' : 'CONTROL_SYSTEM_V3/PID Control/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* CONTROL_SYSTEM_V3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
