/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: CONTROL_SYSTEM_V3_private.h
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

#ifndef CONTROL_SYSTEM_V3_private_h_
#define CONTROL_SYSTEM_V3_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "CONTROL_SYSTEM_V3.h"
#include "CONTROL_SYSTEM_V3_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Used by FromWorkspace Block: '<S13>/fromWS_Signal 1' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern real_T rt_roundd_snf(real_T u);
extern void CONTROL_SYSTE_NEGATIVEEdge_Init(boolean_T *rty_OUT,
  P_NEGATIVEEdge_CONTROL_SYSTEM_T *localP);
extern void CONTROL_SY_NEGATIVEEdge_Disable(DW_NEGATIVEEdge_CONTROL_SYSTE_T
  *localDW);
extern void CONTROL_SYSTEM_V3_NEGATIVEEdge(RT_MODEL_CONTROL_SYSTEM_V3_T * const
  CONTROL_SYSTEM_V3_M, real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, boolean_T *rty_OUT, DW_NEGATIVEEdge_CONTROL_SYSTE_T *localDW);
extern void CONTROL_SYSTE_POSITIVEEdge_Init(boolean_T *rty_OUT,
  P_POSITIVEEdge_CONTROL_SYSTEM_T *localP);
extern void CONTROL_SY_POSITIVEEdge_Disable(DW_POSITIVEEdge_CONTROL_SYSTE_T
  *localDW);
extern void CONTROL_SYSTEM_V3_POSITIVEEdge(RT_MODEL_CONTROL_SYSTEM_V3_T * const
  CONTROL_SYSTEM_V3_M, real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, boolean_T *rty_OUT, DW_POSITIVEEdge_CONTROL_SYSTE_T *localDW);

/* private model entry point functions */
extern void CONTROL_SYSTEM_V3_derivatives(void);

#endif                                 /* CONTROL_SYSTEM_V3_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
