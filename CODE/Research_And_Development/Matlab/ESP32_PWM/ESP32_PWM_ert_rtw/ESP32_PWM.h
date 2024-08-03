/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ESP32_PWM.h
 *
 * Code generated for Simulink model 'ESP32_PWM'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug  3 12:55:08 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ESP32_PWM_h_
#define ESP32_PWM_h_
#ifndef ESP32_PWM_COMMON_INCLUDES_
#define ESP32_PWM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "LEDC_INTERFACE.h"
#endif                                 /* ESP32_PWM_COMMON_INCLUDES_ */

#include "ESP32_PWM_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  LEDC_INTERFACE_ESP32_PWM_T obj;      /* '<Root>/MATLAB System' */
} DW_ESP32_PWM_T;

/* Parameters (default storage) */
struct P_ESP32_PWM_T_ {
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ESP32_PWM_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_ESP32_PWM_T ESP32_PWM_P;

/* Block states (default storage) */
extern DW_ESP32_PWM_T ESP32_PWM_DW;

/* Model entry point functions */
extern void ESP32_PWM_initialize(void);
extern void ESP32_PWM_step(void);
extern void ESP32_PWM_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ESP32_PWM_T *const ESP32_PWM_M;
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
 * '<Root>' : 'ESP32_PWM'
 */
#endif                                 /* ESP32_PWM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
