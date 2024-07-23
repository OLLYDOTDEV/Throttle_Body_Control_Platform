/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: RPI_ADS1115.h
 *
 * Code generated for Simulink model 'RPI_ADS1115'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Jul 23 13:58:16 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RPI_ADS1115_h_
#define RPI_ADS1115_h_
#ifndef RPI_ADS1115_COMMON_INCLUDES_
#define RPI_ADS1115_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#endif                                 /* RPI_ADS1115_COMMON_INCLUDES_ */

#include "RPI_ADS1115_types.h"
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
  codertarget_raspi_internal_AD_T obj; /* '<Root>/ADS1x15' */
} DW_RPI_ADS1115_T;

/* Real-time Model Data Structure */
struct tag_RTM_RPI_ADS1115_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_RPI_ADS1115_T RPI_ADS1115_DW;

/* Model entry point functions */
extern void RPI_ADS1115_initialize(void);
extern void RPI_ADS1115_step(void);
extern void RPI_ADS1115_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RPI_ADS1115_T *const RPI_ADS1115_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
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
 * '<Root>' : 'RPI_ADS1115'
 */
#endif                                 /* RPI_ADS1115_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
