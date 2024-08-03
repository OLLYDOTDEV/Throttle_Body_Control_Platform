/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_ANALOG_READ_DDAppGeneratedModel.h
 *
 * Code generated for Simulink model 'ESP32_ANALOG_READ_DDAppGeneratedModel'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug  3 17:35:33 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ESP32_ANALOG_READ_DDAppGeneratedModel_h_
#define ESP32_ANALOG_READ_DDAppGeneratedModel_h_
#ifndef ESP32_ANALOG_READ_DDAppGeneratedModel_COMMON_INCLUDES_
#define ESP32_ANALOG_READ_DDAppGeneratedModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ESP32_ANALOG_READ.h"
#endif              /* ESP32_ANALOG_READ_DDAppGeneratedModel_COMMON_INCLUDES_ */

#include "ESP32_ANALOG_READ_DDAppGeneratedModel_types.h"
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

#define ESP32_ANALOG_READ_DDAppGeneratedModel_M (ESP32_ANALOG_READ_DDAppGener_M)

/* Block signals (default storage) */
typedef struct {
  real_T ESP23_ANALOG_READ_DDAppGenerate;
                            /* '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
} B_ESP32_ANALOG_READ_DDAppGene_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ESP32_ANALOG_READ_ESP32_ANALO_T obj;
                            /* '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock' */
} DW_ESP32_ANALOG_READ_DDAppGen_T;

/* Parameters (default storage) */
struct P_ESP32_ANALOG_READ_DDAppGene_T_ {
  real_T ESP23_ANALOG_READ_DDAppGenerate;/* Expression: -1
                                          * Referenced by: '<Root>/ESP23_ANALOG_READ_DDAppGeneratedBlock'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_ESP32_ANALOG_READ_DDA_T {
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
extern P_ESP32_ANALOG_READ_DDAppGene_T ESP32_ANALOG_READ_DDAppGenera_P;

/* Block signals (default storage) */
extern B_ESP32_ANALOG_READ_DDAppGene_T ESP32_ANALOG_READ_DDAppGenera_B;

/* Block states (default storage) */
extern DW_ESP32_ANALOG_READ_DDAppGen_T ESP32_ANALOG_READ_DDAppGener_DW;

/* Model entry point functions */
extern void ESP32_ANALOG_READ_DDAppGeneratedModel_initialize(void);
extern void ESP32_ANALOG_READ_DDAppGeneratedModel_step(void);
extern void ESP32_ANALOG_READ_DDAppGeneratedModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ESP32_ANALOG_READ_DD_T *const ESP32_ANALOG_READ_DDAppGener_M;
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
 * '<Root>' : 'ESP32_ANALOG_READ_DDAppGeneratedModel'
 */
#endif                            /* ESP32_ANALOG_READ_DDAppGeneratedModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
