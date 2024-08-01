/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ADS1115_Single_Ended_Read.h
 *
 * Code generated for Simulink model 'ADS1115_Single_Ended_Read'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Aug  1 13:40:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Traceability
 *    2. Debugging
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef ADS1115_Single_Ended_Read_h_
#define ADS1115_Single_Ended_Read_h_
#ifndef ADS1115_Single_Ended_Read_COMMON_INCLUDES_
#define ADS1115_Single_Ended_Read_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                          /* ADS1115_Single_Ended_Read_COMMON_INCLUDES_ */

#include "ADS1115_Single_Ended_Read_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  int16_T SFunctionBuilder_o1;         /* '<Root>/S-Function Builder' */
  int16_T SFunctionBuilder_o2;         /* '<Root>/S-Function Builder' */
  int16_T SFunctionBuilder_o3;         /* '<Root>/S-Function Builder' */
  int16_T SFunctionBuilder_o4;         /* '<Root>/S-Function Builder' */
} B_ADS1115_Single_Ended_Read_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
} DW_ADS1115_Single_Ended_Read_T;

/* Real-time Model Data Structure */
struct tag_RTM_ADS1115_Single_Ended__T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_ADS1115_Single_Ended_Read_T ADS1115_Single_Ended_Read_B;

/* Block states (default storage) */
extern DW_ADS1115_Single_Ended_Read_T ADS1115_Single_Ended_Read_DW;

/* Model entry point functions */
extern void ADS1115_Single_Ended_Read_initialize(void);
extern void ADS1115_Single_Ended_Read_step(void);
extern void ADS1115_Single_Ended_Read_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ADS1115_Single_Ended_T *const ADS1115_Single_Ended_Read_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Display4' : Unused code path elimination
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
 * '<Root>' : 'ADS1115_Single_Ended_Read'
 */
#endif                                 /* ADS1115_Single_Ended_Read_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
