/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ADS1115_Vread_DDAppGeneratedModel.h
 *
 * Code generated for Simulink model 'ADS1115_Vread_DDAppGeneratedModel'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug  3 13:17:21 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ADS1115_Vread_DDAppGeneratedModel_h_
#define ADS1115_Vread_DDAppGeneratedModel_h_
#ifndef ADS1115_Vread_DDAppGeneratedModel_COMMON_INCLUDES_
#define ADS1115_Vread_DDAppGeneratedModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ADS1115_Vread.h"
#endif                  /* ADS1115_Vread_DDAppGeneratedModel_COMMON_INCLUDES_ */

#include "ADS1115_Vread_DDAppGeneratedModel_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define ADS1115_Vread_DDAppGeneratedModel_M (ADS1115_Vread_DDAppGenerated_M)

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ADS1115_Vread_ADS1115_Vread_D_T obj;
                                /* '<Root>/ADS1115_Vread_DDAppGeneratedBlock' */
} DW_ADS1115_Vread_DDAppGenerat_T;

/* Parameters (default storage) */
struct P_ADS1115_Vread_DDAppGenerate_T_ {
  real_T ADS1115_Vread_DDAppGeneratedBlo;/* Expression: -1
                                          * Referenced by: '<Root>/ADS1115_Vread_DDAppGeneratedBlock'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_ADS1115_Vread_DDAppGe_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_ADS1115_Vread_DDAppGenerate_T ADS1115_Vread_DDAppGeneratedM_P;

/* Block states (default storage) */
extern DW_ADS1115_Vread_DDAppGenerat_T ADS1115_Vread_DDAppGenerated_DW;

/* Model entry point functions */
extern void ADS1115_Vread_DDAppGeneratedModel_initialize(void);
extern void ADS1115_Vread_DDAppGeneratedModel_step(void);
extern void ADS1115_Vread_DDAppGeneratedModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ADS1115_Vread_DDAppG_T *const ADS1115_Vread_DDAppGenerated_M;
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
 * '<Root>' : 'ADS1115_Vread_DDAppGeneratedModel'
 */
#endif                                /* ADS1115_Vread_DDAppGeneratedModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
