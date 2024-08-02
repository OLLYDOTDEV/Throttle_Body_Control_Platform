/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ADS1115_Single_Ended_Read_V2.h
 *
 * Code generated for Simulink model 'ADS1115_Single_Ended_Read_V2'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug  3 09:21:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Traceability
 *    2. Debugging
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef ADS1115_Single_Ended_Read_V2_h_
#define ADS1115_Single_Ended_Read_V2_h_
#ifndef ADS1115_Single_Ended_Read_V2_COMMON_INCLUDES_
#define ADS1115_Single_Ended_Read_V2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "ADS1115_Vread.h"
#endif                       /* ADS1115_Single_Ended_Read_V2_COMMON_INCLUDES_ */

#include "ADS1115_Single_Ended_Read_V2_types.h"
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
  real_T MATLABSystem_o1;              /* '<Root>/MATLAB System' */
  real_T MATLABSystem_o2;              /* '<Root>/MATLAB System' */
  real_T MATLABSystem_o3;              /* '<Root>/MATLAB System' */
  real_T MATLABSystem_o4;              /* '<Root>/MATLAB System' */
} B_ADS1115_Single_Ended_Read_V_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ADS1115_Vread_ADS1115_Single__T obj; /* '<Root>/MATLAB System' */
} DW_ADS1115_Single_Ended_Read__T;

/* Parameters (default storage) */
struct P_ADS1115_Single_Ended_Read_V_T_ {
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ADS1115_Single_Ended__T {
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
extern P_ADS1115_Single_Ended_Read_V_T ADS1115_Single_Ended_Read_V2_P;

/* Block signals (default storage) */
extern B_ADS1115_Single_Ended_Read_V_T ADS1115_Single_Ended_Read_V2_B;

/* Block states (default storage) */
extern DW_ADS1115_Single_Ended_Read__T ADS1115_Single_Ended_Read_V2_DW;

/* Model entry point functions */
extern void ADS1115_Single_Ended_Read_V2_initialize(void);
extern void ADS1115_Single_Ended_Read_V2_step(void);
extern void ADS1115_Single_Ended_Read_V2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ADS1115_Single_Ended_T *const ADS1115_Single_Ended_Read_V2_M;
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
 * '<Root>' : 'ADS1115_Single_Ended_Read_V2'
 */
#endif                                 /* ADS1115_Single_Ended_Read_V2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
