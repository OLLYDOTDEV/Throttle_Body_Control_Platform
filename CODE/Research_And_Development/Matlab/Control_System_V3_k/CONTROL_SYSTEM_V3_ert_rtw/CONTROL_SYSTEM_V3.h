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
 * Model version                  : 1.5
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Oct 24 14:44:44 2024
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
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "ADS1115_Vread.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* CONTROL_SYSTEM_V3_COMMON_INCLUDES_ */

#include "CONTROL_SYSTEM_V3_types.h"
#include <math.h>
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

/* Block states (default storage) for system '<S38>/NEGATIVE Edge' */
typedef struct {
  int8_T NEGATIVEEdge_SubsysRanBC;     /* '<S38>/NEGATIVE Edge' */
  boolean_T NEGATIVEEdge_MODE;         /* '<S38>/NEGATIVE Edge' */
} DW_NEGATIVEEdge_CONTROL_SYSTE_T;

/* Block states (default storage) for system '<S38>/POSITIVE Edge' */
typedef struct {
  int8_T POSITIVEEdge_SubsysRanBC;     /* '<S38>/POSITIVE Edge' */
  boolean_T POSITIVEEdge_MODE;         /* '<S38>/POSITIVE Edge' */
} DW_POSITIVEEdge_CONTROL_SYSTE_T;

/* Block signals (default storage) */
typedef struct {
  real_T Signal1;                      /* '<S13>/fromWS_Signal 1' */
  real_T FootPedalSignal;              /* '<S1>/Switch3' */
  real_T Add2;                         /* '<S16>/Add2' */
  real_T Add3;                         /* '<S16>/Add3' */
  real_T Divide1;                      /* '<S16>/Divide1' */
  real_T Sum;                          /* '<S16>/Sum' */
  real_T Error;                        /* '<S1>/Sum1' */
  real_T Add2_o;                       /* '<S6>/Add2' */
  real_T Add3_g;                       /* '<S6>/Add3' */
  real_T Divide1_i;                    /* '<S6>/Divide1' */
  real_T Sum_h;                        /* '<S6>/Sum' */
  real_T PulseGenerator;               /* '<S4>/Pulse Generator' */
  real_T PercentageError;              /* '<S15>/Gain' */
  real_T FootPedalSignal_l;            /* '<S1>/Switch4' */
  real_T PulseGenerator_p;             /* '<S5>/Pulse Generator' */
  real_T EnablePin;                    /* '<S8>/Enable Pin' */
  real_T DirectionPin;                 /* '<S8>/Direction Pin' */
  real_T TB_maxVal;                    /* '<S1>/Throttle Body Callibration1' */
  real_T TB_minVal;                    /* '<S1>/Throttle Body Callibration1' */
  real_T dxe[3];                       /* '<S28>/Subtract1' */
  real_T Switch2;                      /* '<S19>/Switch2' */
  real_T Integrator;                   /* '<S91>/Integrator' */
  real_T Filter;                       /* '<S86>/Filter' */
  real_T FilterCoefficient;            /* '<S94>/Filter Coefficient' */
  real_T Sum_m;                        /* '<S100>/Sum' */
  real_T Sum1;                         /* '<S11>/Sum1' */
  real_T Switch2_e;                    /* '<S57>/Switch2' */
  real_T IntegralGain;                 /* '<S88>/Integral Gain' */
  real_T Error_j;                      /* '<S12>/Error' */
  real_T MultiportSwitch[2];           /* '<S46>/Multiport Switch' */
  real_T ICic;                         /* '<S51>/IC=ic' */
  real_T Switch;                       /* '<S51>/Switch' */
  real_T MultiportSwitch_l[2];         /* '<S38>/Multiport Switch' */
  real_T ICic_i;                       /* '<S43>/IC=ic' */
  real_T Switch_i;                     /* '<S43>/Switch' */
  real_T FP_maxVal;                    /* '<S1>/Foot Pedal Calibration1' */
  real_T FP_minVal;                    /* '<S1>/Foot Pedal Calibration1' */
  real_T MATLABSystem_o1;              /* '<S3>/MATLAB System' */
  real_T MATLABSystem_o2;              /* '<S3>/MATLAB System' */
  real_T MATLABSystem_o3;              /* '<S3>/MATLAB System' */
  real_T MATLABSystem_o4;              /* '<S3>/MATLAB System' */
  boolean_T Memory;                    /* '<S52>/Memory' */
  boolean_T Logic[2];                  /* '<S52>/Logic' */
  boolean_T Memory_h;                  /* '<S54>/Memory' */
  boolean_T Logic_e[2];                /* '<S54>/Logic' */
  boolean_T Memory_k;                  /* '<S55>/Memory' */
  boolean_T Logic_f[2];                /* '<S55>/Logic' */
  boolean_T Memory_n;                  /* '<S53>/Memory' */
  boolean_T Logic_d[2];                /* '<S53>/Logic' */
  boolean_T RelationalOperator1;       /* '<S33>/Relational Operator1' */
  boolean_T Memory_i;                  /* '<S46>/Memory' */
  boolean_T LogicalOperator2_g;        /* '<S35>/Logical Operator2' */
  boolean_T RelationalOperator1_i;     /* '<S49>/Relational Operator1' */
  boolean_T RelationalOperator1_g;     /* '<S48>/Relational Operator1' */
  boolean_T Memory_no;                 /* '<S38>/Memory' */
  boolean_T LogicalOperator2_c;        /* '<S34>/Logical Operator2' */
  boolean_T RelationalOperator1_e;     /* '<S41>/Relational Operator1' */
  boolean_T RelationalOperator1_f;     /* '<S40>/Relational Operator1' */
} B_CONTROL_SYSTEM_V3_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ADS1115_Vread_CONTROL_SYSTEM__T obj; /* '<S3>/MATLAB System' */
  codertarget_arduinobase_blo_c_T obj_n;/* '<S9>/Digital Input3' */
  codertarget_arduinobase_blo_c_T obj_l;/* '<S9>/Digital Input2' */
  codertarget_arduinobase_blo_c_T obj_m;/* '<S9>/Digital Input1' */
  codertarget_arduinobase_blo_c_T obj_c;/* '<S9>/Digital Input' */
  codertarget_arduinobase_block_T obj_my;/* '<S8>/Digital Output1' */
  codertarget_arduinobase_block_T obj_d;/* '<S8>/Digital Output' */
  codertarget_arduinobase_block_T obj_n5;/* '<S5>/Digital Output4' */
  codertarget_arduinobase_block_T obj_i;/* '<S4>/Digital Output3' */
  codertarget_arduinobase_block_T obj_j;/* '<S4>/Digital Output2' */
  codertarget_arduinobase_block_T obj_e;/* '<S4>/Digital Output1' */
  codertarget_arduinobase_block_T obj_dn;/* '<S4>/Digital Output' */
  codertarget_arduinobase_inter_T obj_g;/* '<S8>/PWM' */
  real_T Integrator_DSTATE;            /* '<S91>/Integrator' */
  real_T Filter_DSTATE;                /* '<S86>/Filter' */
  real_T TB_maxSet;                    /* '<S1>/Throttle Body Callibration1' */
  real_T TB_minSet;                    /* '<S1>/Throttle Body Callibration1' */
  real_T ICic_PreviousInput;           /* '<S51>/IC=ic' */
  real_T ICic_PreviousInput_b;         /* '<S43>/IC=ic' */
  real_T maxSet;                       /* '<S1>/Foot Pedal Calibration1' */
  real_T minSet;                       /* '<S1>/Foot Pedal Calibration1' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              /* '<S13>/fromWS_Signal 1' */

  struct {
    void *LoggedData[2];
  } FootPedalSignalVSThrottleBodyPo;
                       /* '<S1>/Foot Pedal Signal VS Throttle Body Position1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S14>/From Workspace' */

  int32_T clockTickCounter;            /* '<S4>/Pulse Generator' */
  int32_T clockTickCounter_k;          /* '<S5>/Pulse Generator' */
  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              /* '<S13>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S14>/From Workspace' */

  int8_T IfCondition1_ActiveSubsystem; /* '<S1>/If Condition1' */
  int8_T ADRCControl1_SubsysRanBC;     /* '<S1>/ADRC Control1' */
  int8_T PIDControl1_SubsysRanBC;      /* '<S1>/PID Control1' */
  int8_T Propotional1_SubsysRanBC;     /* '<S1>/Propotional1' */
  int8_T ONDelay_SubsysRanBC;          /* '<S33>/ON Delay' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S47>/Triggered Subsystem' */
  int8_T OFFDelay_SubsysRanBC;         /* '<S33>/OFF Delay' */
  int8_T TriggeredSubsystem_SubsysRanB_j;/* '<S39>/Triggered Subsystem' */
  boolean_T Memory_PreviousInput;      /* '<S52>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S54>/Memory' */
  boolean_T Memory_PreviousInput_h;    /* '<S55>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S53>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S46>/Memory' */
  boolean_T Memory_PreviousInput_dj;   /* '<S38>/Memory' */
  boolean_T ONDelay_MODE;              /* '<S33>/ON Delay' */
  boolean_T OFFDelay_MODE;             /* '<S33>/OFF Delay' */
  DW_POSITIVEEdge_CONTROL_SYSTE_T POSITIVEEdge_b;/* '<S46>/POSITIVE Edge' */
  DW_NEGATIVEEdge_CONTROL_SYSTE_T NEGATIVEEdge_m;/* '<S46>/NEGATIVE Edge' */
  DW_POSITIVEEdge_CONTROL_SYSTE_T POSITIVEEdge;/* '<S38>/POSITIVE Edge' */
  DW_NEGATIVEEdge_CONTROL_SYSTE_T NEGATIVEEdge;/* '<S38>/NEGATIVE Edge' */
} DW_CONTROL_SYSTEM_V3_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S28>/Integrator' */
} X_CONTROL_SYSTEM_V3_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S28>/Integrator' */
} XDot_CONTROL_SYSTEM_V3_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S28>/Integrator' */
} XDis_CONTROL_SYSTEM_V3_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S47>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_i;/* '<S39>/Triggered Subsystem' */
} PrevZCX_CONTROL_SYSTEM_V3_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S38>/NEGATIVE Edge' */
struct P_NEGATIVEEdge_CONTROL_SYSTEM_T_ {
  boolean_T OUT_Y0;                    /* Computed Parameter: OUT_Y0
                                        * Referenced by: '<S40>/OUT'
                                        */
};

/* Parameters for system: '<S38>/POSITIVE Edge' */
struct P_POSITIVEEdge_CONTROL_SYSTEM_T_ {
  boolean_T OUT_Y0;                    /* Computed Parameter: OUT_Y0
                                        * Referenced by: '<S41>/OUT'
                                        */
};

/* Parameters (default storage) */
struct P_CONTROL_SYSTEM_V3_T_ {
  real_T Desire_Max;                   /* Variable: Desire_Max
                                        * Referenced by: '<S6>/Desire Max Value'
                                        */
  real_T Desire_Min;                   /* Variable: Desire_Min
                                        * Referenced by: '<S6>/Desire Min Value'
                                        */
  real_T Direction_Pin;                /* Variable: Direction_Pin
                                        * Referenced by: '<S8>/Direction Pin'
                                        */
  real_T EN_Pin;                       /* Variable: EN_Pin
                                        * Referenced by: '<S8>/Enable Pin'
                                        */
  real_T Kd;                           /* Variable: Kd
                                        * Referenced by: '<S84>/Derivative Gain'
                                        */
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<S88>/Integral Gain'
                                        */
  real_T Kn;                           /* Variable: Kn
                                        * Referenced by: '<S94>/Filter Coefficient'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S96>/Proportional Gain'
                                        */
  real_T OnDelay_DelayType;            /* Mask Parameter: OnDelay_DelayType
                                        * Referenced by: '<S33>/Constant2'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S86>/Filter'
                               */
  real_T PIDController1_InitialConditi_o;
                              /* Mask Parameter: PIDController1_InitialConditi_o
                               * Referenced by: '<S91>/Integrator'
                               */
  real_T OnDelay_delay;                /* Mask Parameter: OnDelay_delay
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T SampleandHold_ic;             /* Mask Parameter: SampleandHold_ic
                                        * Referenced by: '<S43>/IC=ic'
                                        */
  real_T SampleandHold_ic_k;           /* Mask Parameter: SampleandHold_ic_k
                                        * Referenced by: '<S51>/IC=ic'
                                        */
  real_T EdgeDetector_model;           /* Mask Parameter: EdgeDetector_model
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T EdgeDetector_model_a;         /* Mask Parameter: EdgeDetector_model_a
                                        * Referenced by: '<S46>/Constant1'
                                        */
  real_T Observer_x0;                  /* Mask Parameter: Observer_x0
                                        * Referenced by: '<S28>/Integrator'
                                        */
  boolean_T OnDelay_ic;                /* Mask Parameter: OnDelay_ic
                                        * Referenced by:
                                        *   '<S38>/Memory'
                                        *   '<S46>/Memory'
                                        */
  boolean_T SRFlipFlop3_initial_condition;
                                /* Mask Parameter: SRFlipFlop3_initial_condition
                                 * Referenced by: '<S52>/Memory'
                                 */
  boolean_T SRFlipFlop5_initial_condition;
                                /* Mask Parameter: SRFlipFlop5_initial_condition
                                 * Referenced by: '<S54>/Memory'
                                 */
  boolean_T SRFlipFlop6_initial_condition;
                                /* Mask Parameter: SRFlipFlop6_initial_condition
                                 * Referenced by: '<S55>/Memory'
                                 */
  boolean_T SRFlipFlop4_initial_condition;
                                /* Mask Parameter: SRFlipFlop4_initial_condition
                                 * Referenced by: '<S53>/Memory'
                                 */
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S3>/MATLAB System'
                                        */
  real_T Out1_Y0;                      /* Expression: -1e6
                                        * Referenced by: '<S42>/Out1'
                                        */
  real_T posedge_Value[2];             /* Expression: [1 0]
                                        * Referenced by: '<S38>/pos. edge'
                                        */
  real_T negedge_Value[2];             /* Expression: [0 1]
                                        * Referenced by: '<S38>/neg. edge'
                                        */
  real_T eitheredge_Value[2];          /* Expression: [1 1]
                                        * Referenced by: '<S38>/either edge'
                                        */
  real_T Out1_Y0_i;                    /* Expression: -1e6
                                        * Referenced by: '<S50>/Out1'
                                        */
  real_T posedge_Value_j[2];           /* Expression: [1 0]
                                        * Referenced by: '<S46>/pos. edge'
                                        */
  real_T negedge_Value_i[2];           /* Expression: [0 1]
                                        * Referenced by: '<S46>/neg. edge'
                                        */
  real_T eitheredge_Value_c[2];        /* Expression: [1 1]
                                        * Referenced by: '<S46>/either edge'
                                        */
  real_T Propotional_Y0;               /* Computed Parameter: Propotional_Y0
                                        * Referenced by: '<S12>/Propotional'
                                        */
  real_T PIDOutput_Y0;                 /* Computed Parameter: PIDOutput_Y0
                                        * Referenced by: '<S11>/PID Output'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S91>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S86>/Filter'
                                        */
  real_T Constant_Value;               /* Expression: 0.01
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T ADRCOutput_Y0;                /* Computed Parameter: ADRCOutput_Y0
                                        * Referenced by: '<S2>/ADRC Output'
                                        */
  real_T Constant_Value_k[9];          /* Expression: a
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: wc^2
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2*wc
                                        * Referenced by: '<S26>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/b0
                                        * Referenced by: '<S26>/Gain1'
                                        */
  real_T Constant1_Value[3];           /* Expression: b
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: d
                                        * Referenced by: '<S27>/Constant3'
                                        */
  real_T Constant2_Value[3];           /* Expression: c
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T Constant8_Value[3];           /* Expression: l
                                        * Referenced by: '<S27>/Constant8'
                                        */
  real_T Constant_Value_g;             /* Expression: 2
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S9>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S9>/Digital Input1'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S9>/Digital Input2'
                                        */
  real_T DigitalInput3_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S9>/Digital Input3'
                                        */
  real_T Constant3_Value_b;            /* Expression: 100
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0.1
                                        * Referenced by: '<S1>/Switch3'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S4>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S4>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 100
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Constant2_Value_g;            /* Expression: 1
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant3_Value_b5;           /* Expression: 0
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S5>/Switch2'
                                        */
  real_T PulseGenerator_Amp_i;         /* Expression: 1
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_m; /* Computed Parameter: PulseGenerator_Period_m
                                   * Referenced by: '<S5>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_p;     /* Computed Parameter: PulseGenerator_Duty_p
                                     * Referenced by: '<S5>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_n;  /* Expression: 0
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant4'
                                        */
  boolean_T OUT_Y0;                    /* Computed Parameter: OUT_Y0
                                        * Referenced by: '<S34>/OUT'
                                        */
  boolean_T OUT_Y0_o;                  /* Computed Parameter: OUT_Y0_o
                                        * Referenced by: '<S35>/OUT'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S52>/Logic'
                                        */
  boolean_T Logic_table_i[16];         /* Computed Parameter: Logic_table_i
                                        * Referenced by: '<S54>/Logic'
                                        */
  boolean_T Logic_table_j[16];         /* Computed Parameter: Logic_table_j
                                        * Referenced by: '<S55>/Logic'
                                        */
  boolean_T Logic_table_d[16];         /* Computed Parameter: Logic_table_d
                                        * Referenced by: '<S53>/Logic'
                                        */
  uint8_T Gain_Gain_f;                 /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S8>/Gain'
                                        */
  uint8_T Multiply1_Gain;              /* Computed Parameter: Multiply1_Gain
                                        * Referenced by: '<S10>/Multiply1'
                                        */
  uint8_T Multiply2_Gain;              /* Computed Parameter: Multiply2_Gain
                                        * Referenced by: '<S10>/Multiply2'
                                        */
  uint8_T Multiply_Gain;               /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S10>/Multiply'
                                        */
  P_POSITIVEEdge_CONTROL_SYSTEM_T POSITIVEEdge_b;/* '<S46>/POSITIVE Edge' */
  P_NEGATIVEEdge_CONTROL_SYSTEM_T NEGATIVEEdge_m;/* '<S46>/NEGATIVE Edge' */
  P_POSITIVEEdge_CONTROL_SYSTEM_T POSITIVEEdge;/* '<S38>/POSITIVE Edge' */
  P_NEGATIVEEdge_CONTROL_SYSTEM_T NEGATIVEEdge;/* '<S38>/NEGATIVE Edge' */
};

/* Real-time Model Data Structure */
struct tag_RTM_CONTROL_SYSTEM_V3_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_CONTROL_SYSTEM_V3_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_CONTROL_SYSTEM_V3_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
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
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Constant' : Unused code path elimination
 * Block '<S39>/Relational Operator' : Unused code path elimination
 * Block '<S39>/Sum' : Unused code path elimination
 * Block '<S47>/Constant' : Unused code path elimination
 * Block '<S47>/Relational Operator' : Unused code path elimination
 * Block '<S47>/Sum' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/From Workspace' : Unused code path elimination
 * Block '<S14>/fromWS_Signal 1' : Unused code path elimination
 * Block '<S33>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S43>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S46>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S51>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'CONTROL_SYSTEM_V3/Subsystem5'
 * '<S2>'   : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1'
 * '<S3>'   : 'CONTROL_SYSTEM_V3/Subsystem5/Analog Signal1'
 * '<S4>'   : 'CONTROL_SYSTEM_V3/Subsystem5/Button Control LED1'
 * '<S5>'   : 'CONTROL_SYSTEM_V3/Subsystem5/Error Indication1'
 * '<S6>'   : 'CONTROL_SYSTEM_V3/Subsystem5/FP_Input Range Conversion1'
 * '<S7>'   : 'CONTROL_SYSTEM_V3/Subsystem5/Foot Pedal Calibration1'
 * '<S8>'   : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1'
 * '<S9>'   : 'CONTROL_SYSTEM_V3/Subsystem5/Latching1'
 * '<S10>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Operation Selector1'
 * '<S11>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1'
 * '<S12>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Propotional1'
 * '<S13>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Signal Editor2'
 * '<S14>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Signal Editor3'
 * '<S15>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Subsystem3'
 * '<S16>'  : 'CONTROL_SYSTEM_V3/Subsystem5/TB_Feedbakc Range Conversion1'
 * '<S17>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Throttle Body Callibration1'
 * '<S18>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control'
 * '<S19>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Saturation Dynamic'
 * '<S20>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC'
 * '<S21>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/error feedback'
 * '<S22>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/extended state observer'
 * '<S23>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/input saturation'
 * '<S24>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/rZOH'
 * '<S25>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/yZOH'
 * '<S26>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/error feedback/seccond order'
 * '<S27>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/extended state observer/continuous time'
 * '<S28>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/extended state observer/continuous time/Observer'
 * '<S29>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/input saturation/passthrough'
 * '<S30>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/rZOH/passthrough'
 * '<S31>'  : 'CONTROL_SYSTEM_V3/Subsystem5/ADRC Control1/Active Disturbance Rejection Control/ADRC/yZOH/passthrough'
 * '<S32>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay'
 * '<S33>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model'
 * '<S34>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/OFF Delay'
 * '<S35>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/ON Delay'
 * '<S36>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/OFF Delay/Edge Detector'
 * '<S37>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/OFF Delay/Sample and Hold'
 * '<S38>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/OFF Delay/Edge Detector/Model'
 * '<S39>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/OFF Delay/Edge Detector/Model/Internal dirac generator'
 * '<S40>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/OFF Delay/Edge Detector/Model/NEGATIVE Edge'
 * '<S41>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/OFF Delay/Edge Detector/Model/POSITIVE Edge'
 * '<S42>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/OFF Delay/Edge Detector/Model/Internal dirac generator/Triggered Subsystem'
 * '<S43>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/OFF Delay/Sample and Hold/Model'
 * '<S44>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/ON Delay/Edge Detector'
 * '<S45>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/ON Delay/Sample and Hold'
 * '<S46>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/ON Delay/Edge Detector/Model'
 * '<S47>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/ON Delay/Edge Detector/Model/Internal dirac generator'
 * '<S48>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/ON Delay/Edge Detector/Model/NEGATIVE Edge'
 * '<S49>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/ON Delay/Edge Detector/Model/POSITIVE Edge'
 * '<S50>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/ON Delay/Edge Detector/Model/Internal dirac generator/Triggered Subsystem'
 * '<S51>'  : 'CONTROL_SYSTEM_V3/Subsystem5/H-Bridge Setting1/On Delay/Model/ON Delay/Sample and Hold/Model'
 * '<S52>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Latching1/S-R Flip-Flop3'
 * '<S53>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Latching1/S-R Flip-Flop4'
 * '<S54>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Latching1/S-R Flip-Flop5'
 * '<S55>'  : 'CONTROL_SYSTEM_V3/Subsystem5/Latching1/S-R Flip-Flop6'
 * '<S56>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1'
 * '<S57>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/Saturation Dynamic'
 * '<S58>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Anti-windup'
 * '<S59>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/D Gain'
 * '<S60>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/External Derivative'
 * '<S61>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Filter'
 * '<S62>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Filter ICs'
 * '<S63>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/I Gain'
 * '<S64>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Ideal P Gain'
 * '<S65>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Ideal P Gain Fdbk'
 * '<S66>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Integrator'
 * '<S67>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Integrator ICs'
 * '<S68>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/N Copy'
 * '<S69>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/N Gain'
 * '<S70>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/P Copy'
 * '<S71>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Parallel P Gain'
 * '<S72>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Reset Signal'
 * '<S73>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Saturation'
 * '<S74>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Saturation Fdbk'
 * '<S75>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Sum'
 * '<S76>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Sum Fdbk'
 * '<S77>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Tracking Mode'
 * '<S78>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Tracking Mode Sum'
 * '<S79>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Tsamp - Integral'
 * '<S80>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Tsamp - Ngain'
 * '<S81>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/postSat Signal'
 * '<S82>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/preSat Signal'
 * '<S83>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Anti-windup/Passthrough'
 * '<S84>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/D Gain/Internal Parameters'
 * '<S85>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/External Derivative/Error'
 * '<S86>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S87>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S88>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/I Gain/Internal Parameters'
 * '<S89>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Ideal P Gain/Passthrough'
 * '<S90>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S91>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Integrator/Discrete'
 * '<S92>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Integrator ICs/Internal IC'
 * '<S93>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/N Copy/Disabled'
 * '<S94>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/N Gain/Internal Parameters'
 * '<S95>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/P Copy/Disabled'
 * '<S96>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S97>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Reset Signal/Disabled'
 * '<S98>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Saturation/Passthrough'
 * '<S99>'  : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Saturation Fdbk/Disabled'
 * '<S100>' : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Sum/Sum_PID'
 * '<S101>' : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Sum Fdbk/Disabled'
 * '<S102>' : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Tracking Mode/Disabled'
 * '<S103>' : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S105>' : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S106>' : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/postSat Signal/Forward_Path'
 * '<S107>' : 'CONTROL_SYSTEM_V3/Subsystem5/PID Control1/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* CONTROL_SYSTEM_V3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
