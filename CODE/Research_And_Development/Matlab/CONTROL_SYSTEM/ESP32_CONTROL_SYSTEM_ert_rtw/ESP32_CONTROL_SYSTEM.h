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
 * Model version                  : 1.20
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Aug 19 16:13:12 2024
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
#include "ext_mode.h"
#include "ESP32_ANALOG_READ.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                               /* ESP32_CONTROL_SYSTEM_COMMON_INCLUDES_ */

#include "ESP32_CONTROL_SYSTEM_types.h"
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
  real_T Integrator1[3];               /* '<S6>/Integrator1' */
  real_T Add;                          /* '<S7>/Add' */
  real_T Add1;                         /* '<S7>/Add1' */
  real_T Divide;                       /* '<S7>/Divide' */
  real_T Product;                      /* '<S7>/Product' */
  real_T Fcn;                          /* '<S4>/Fcn' */
  real_T Fcn1;                         /* '<S2>/Fcn1' */
  real_T Fcn2;                         /* '<S2>/Fcn2' */
  real_T Fcn3;                         /* '<S2>/Fcn3' */
  real_T Gain1[3];                     /* '<S1>/Gain1' */
  real_T Sum3;                         /* '<S4>/Sum3' */
  real_T Gain;                         /* '<S4>/Gain' */
  real_T Product_f;                    /* '<S4>/Product' */
  real_T Sum[3];                       /* '<S6>/Sum' */
  real_T TmpSignalConversionAtTAQSigLogg[3];
  /* '<S2>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T Sum_j;                        /* '<S5>/Sum' */
  real_T Add1_c;                       /* '<S11>/Add1' */
  real_T Add_f;                        /* '<S11>/Add' */
  real_T Divide_p;                     /* '<S11>/Divide' */
  real_T Product_j;                    /* '<S11>/Product' */
  real_T Gain_j;                       /* '<S10>/Gain' */
  real_T Constant3;                    /* '<S5>/Constant3' */
  real_T EnablePin;                    /* '<S12>/Enable Pin' */
  real_T ESP23_ANALOG_READ_DDAppGenerate;
                              /* '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  real_T TB_maxVal;                   /* '<Root>/Throttle Body Callibration1' */
  real_T TB_minVal;                   /* '<Root>/Throttle Body Callibration1' */
  real_T ESP23_ANALOG_READ_DDAppGenera_g;
                             /* '<S3>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
} B_ESP32_CONTROL_SYSTEM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ESP32_ANALOG_READ_ESP32_CONTR_T obj;
                              /* '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
  ESP32_ANALOG_READ_ESP32_CONTR_T obj_a;
                             /* '<S3>/ESP23_ANALOG_READ_DDAppGeneratedBlock1' */
  codertarget_arduinobase_block_T obj_o;/* '<S12>/Digital Output1' */
  codertarget_arduinobase_block_T obj_h;/* '<S12>/Digital Output' */
  codertarget_arduinobase_inter_T obj_oq;/* '<S12>/PWM' */
  real_T TB_maxSet;                   /* '<Root>/Throttle Body Callibration1' */
  real_T TB_minSet;                   /* '<Root>/Throttle Body Callibration1' */
  real_T TB_maxSet_j;                  /* '<S5>/Throttle Body Callibration1' */
  real_T TB_minSet_n;                  /* '<S5>/Throttle Body Callibration1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S6>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S6>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S2>/Scope3' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_c;                    /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S5>/Scope' */

  struct {
    void *LoggedData;
  } SIneInput_PWORK;                   /* '<S5>/SIne Input' */

  struct {
    void *LoggedData;
  } Trackingerro_PWORK;                /* '<S4>/Tracking erro' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_p;                    /* '<S2>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_h;                    /* '<S2>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_g;                     /* '<S2>/Scope' */
} DW_ESP32_CONTROL_SYSTEM_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S6>/Integrator1' */
} X_ESP32_CONTROL_SYSTEM_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S6>/Integrator1' */
} XDot_ESP32_CONTROL_SYSTEM_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<S6>/Integrator1' */
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
                                        * Referenced by: '<S11>/Desire Max Value'
                                        */
  real_T Desire_Min;                   /* Variable: Desire_Min
                                        * Referenced by: '<S11>/Desire Min Value'
                                        */
  real_T EN_Pin;                       /* Variable: EN_Pin
                                        * Referenced by: '<S12>/Enable Pin'
                                        */
  real_T J_aet;                        /* Variable: J_aet
                                        * Referenced by:
                                        *   '<S4>/Constant2'
                                        *   '<S6>/Constant2'
                                        */
  real_T omga_c;                       /* Variable: omga_c
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T roa;                          /* Variable: roa
                                        * Referenced by:
                                        *   '<S4>/Constant2'
                                        *   '<S6>/Constant2'
                                        */
  real_T ESP23_ANALOG_READ_DDAppGenerate;/* Expression: -1
                                          * Referenced by: '<S3>/ESP23_ANALOG_READ_DDAppGeneratedBlock1'
                                          */
  real_T ESP23_ANALOG_READ_DDAppGenera_c;/* Expression: -1
                                          * Referenced by: '<S9>/ESP23_ANALOG_READ_DDAppGeneratedBlock'
                                          */
  real_T Integrator1_IC[3];            /* Expression: [12*pi/180 0 0]'
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Gain_Gain[9];                 /* Expression: [0 1 0;0 0 1;0 0 0]
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Gain2_Gain[3];                /* Expression: [Beta1 Beta2 Beta3]'
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain_Gain_d;                  /* Expression: (omga_c)^2
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 0.7
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Constant_Value_h;             /* Expression: 0.3
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 180/pi
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ESP32_CONTROL_SYSTEM_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_ESP32_CONTROL_SYSTEM_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_ESP32_CONTROL_SYSTEM_T *contStateDisabled;
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
 * '<S1>'   : 'ESP32_CONTROL_SYSTEM/Degrees to Radians2'
 * '<S2>'   : 'ESP32_CONTROL_SYSTEM/Desired signals_Sinewave1'
 * '<S3>'   : 'ESP32_CONTROL_SYSTEM/Foot Pedal Signal1'
 * '<S4>'   : 'ESP32_CONTROL_SYSTEM/SFBC_Controller1'
 * '<S5>'   : 'ESP32_CONTROL_SYSTEM/Subsystem4'
 * '<S6>'   : 'ESP32_CONTROL_SYSTEM/Subsystem5'
 * '<S7>'   : 'ESP32_CONTROL_SYSTEM/TB_Feedbakc Range Conversion3'
 * '<S8>'   : 'ESP32_CONTROL_SYSTEM/Throttle Body Callibration1'
 * '<S9>'   : 'ESP32_CONTROL_SYSTEM/Throttle Body Feedback1'
 * '<S10>'  : 'ESP32_CONTROL_SYSTEM/SFBC_Controller1/Radians to Degrees4'
 * '<S11>'  : 'ESP32_CONTROL_SYSTEM/Subsystem4/FP_Input Range Conversion1'
 * '<S12>'  : 'ESP32_CONTROL_SYSTEM/Subsystem4/H-Bridge Setting'
 * '<S13>'  : 'ESP32_CONTROL_SYSTEM/Subsystem4/Throttle Body Callibration1'
 */
#endif                                 /* ESP32_CONTROL_SYSTEM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
