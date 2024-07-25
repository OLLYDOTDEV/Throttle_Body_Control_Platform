/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: RPI_ADS1115_types.h
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

#ifndef RPI_ADS1115_types_h_
#define RPI_ADS1115_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<Root>/ADS1x15' */
#include "MW_SVD.h"
#ifndef struct_tag_vB8gURpcbTUBlHcczw228B
#define struct_tag_vB8gURpcbTUBlHcczw228B

struct tag_vB8gURpcbTUBlHcczw228B
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_vB8gURpcbTUBlHcczw228B */

#ifndef typedef_f_codertarget_raspi_internal__T
#define typedef_f_codertarget_raspi_internal__T

typedef struct tag_vB8gURpcbTUBlHcczw228B f_codertarget_raspi_internal__T;

#endif                             /* typedef_f_codertarget_raspi_internal__T */

#ifndef struct_tag_lyyZOnh3K94CJKrpbCvwwG
#define struct_tag_lyyZOnh3K94CJKrpbCvwwG

struct tag_lyyZOnh3K94CJKrpbCvwwG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  f_codertarget_raspi_internal__T *Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
  f_codertarget_raspi_internal__T _pobj0;
};

#endif                                 /* struct_tag_lyyZOnh3K94CJKrpbCvwwG */

#ifndef typedef_f_codertarget_raspi_interna_k_T
#define typedef_f_codertarget_raspi_interna_k_T

typedef struct tag_lyyZOnh3K94CJKrpbCvwwG f_codertarget_raspi_interna_k_T;

#endif                             /* typedef_f_codertarget_raspi_interna_k_T */

#ifndef struct_tag_yw48k0dG0pvYRlcgksoFVE
#define struct_tag_yw48k0dG0pvYRlcgksoFVE

struct tag_yw48k0dG0pvYRlcgksoFVE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_codertarget_raspi_interna_k_T i2cObj;
};

#endif                                 /* struct_tag_yw48k0dG0pvYRlcgksoFVE */

#ifndef typedef_codertarget_raspi_internal_AD_T
#define typedef_codertarget_raspi_internal_AD_T

typedef struct tag_yw48k0dG0pvYRlcgksoFVE codertarget_raspi_internal_AD_T;

#endif                             /* typedef_codertarget_raspi_internal_AD_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_RPI_ADS1115_T RT_MODEL_RPI_ADS1115_T;

#endif                                 /* RPI_ADS1115_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
