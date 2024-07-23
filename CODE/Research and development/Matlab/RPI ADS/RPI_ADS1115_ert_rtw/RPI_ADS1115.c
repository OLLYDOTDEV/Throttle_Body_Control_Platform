/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: RPI_ADS1115.c
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

#include "RPI_ADS1115.h"
#include "RPI_ADS1115_types.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "RPI_ADS1115_private.h"
#include <math.h>

/* Block states (default storage) */
DW_RPI_ADS1115_T RPI_ADS1115_DW;

/* Real-time model */
static RT_MODEL_RPI_ADS1115_T RPI_ADS1115_M_;
RT_MODEL_RPI_ADS1115_T *const RPI_ADS1115_M = &RPI_ADS1115_M_;

/* Forward declaration for local functions */
static codertarget_raspi_internal_AD_T *RPI_ADS1115_ADS1x15_ADS1x15
  (codertarget_raspi_internal_AD_T *obj);
static void RPI_ADS1115_SystemCore_setup(codertarget_raspi_internal_AD_T *obj);
static codertarget_raspi_internal_AD_T *RPI_ADS1115_ADS1x15_ADS1x15
  (codertarget_raspi_internal_AD_T *obj)
{
  codertarget_raspi_internal_AD_T *b_obj;

  /* Start for MATLABSystem: '<Root>/ADS1x15' */
  b_obj = obj;
  obj->isInitialized = 0;
  obj->i2cObj.isInitialized = 0;
  obj->i2cObj.Hw = &obj->i2cObj._pobj0;
  obj->i2cObj.MW_I2C_HANDLE = MW_I2C_Open(1, MW_I2C_MASTER);
  obj->i2cObj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObj.MW_I2C_HANDLE, obj->i2cObj.BusSpeed);
  obj->i2cObj.matlabCodegenIsDeleted = false;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void RPI_ADS1115_SystemCore_setup(codertarget_raspi_internal_AD_T *obj)
{
  real_T x;
  uint16_T tmp;
  uint8_T y[8];
  uint8_T SwappedDataBytes_0[3];
  uint8_T b_SwappedDataBytes[3];
  uint8_T SwappedDataBytes[2];
  uint8_T xtmp;

  /* Start for MATLABSystem: '<Root>/ADS1x15' */
  obj->isInitialized = 1;
  x = 16515.0;

  /* Start for MATLABSystem: '<Root>/ADS1x15' */
  memcpy((void *)&y[0], (void *)&x, (size_t)8 * sizeof(uint8_T));
  xtmp = y[0];

  /* Start for MATLABSystem: '<Root>/ADS1x15' */
  y[0] = y[7];
  y[7] = xtmp;
  xtmp = y[1];

  /* Start for MATLABSystem: '<Root>/ADS1x15' */
  y[1] = y[6];
  y[6] = xtmp;
  xtmp = y[2];

  /* Start for MATLABSystem: '<Root>/ADS1x15' */
  y[2] = y[5];
  y[5] = xtmp;
  xtmp = y[3];

  /* Start for MATLABSystem: '<Root>/ADS1x15' */
  y[3] = y[4];
  y[4] = xtmp;
  memcpy((void *)&x, (void *)&y[0], (size_t)1 * sizeof(real_T));
  x = rt_roundd_snf(x);
  if (x < 65536.0) {
    if (x >= 0.0) {
      tmp = (uint16_T)x;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  memcpy((void *)&SwappedDataBytes[0], (void *)&tmp, (size_t)2 * sizeof(uint8_T));
  b_SwappedDataBytes[0] = 1U;
  b_SwappedDataBytes[1] = SwappedDataBytes[0];
  b_SwappedDataBytes[2] = SwappedDataBytes[1];

  /* Start for MATLABSystem: '<Root>/ADS1x15' */
  memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0], (size_t)
         3 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 72U, &SwappedDataBytes_0[0], 3U,
                     false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void RPI_ADS1115_step(void)
{
  int16_T b_data;
  uint8_T b_x[2];
  uint8_T output_raw[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* MATLABSystem: '<Root>/ADS1x15' */
  status = 0U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(RPI_ADS1115_DW.obj.i2cObj.MW_I2C_HANDLE, 72U,
    &SwappedDataBytes, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(RPI_ADS1115_DW.obj.i2cObj.MW_I2C_HANDLE, 72U, &output_raw
                      [0], 2U, false, true);
    memcpy((void *)&b_data, (void *)&output_raw[0], (size_t)1 * sizeof(int16_T));
  } else {
    b_data = 0;
  }

  memcpy((void *)&output_raw[0], (void *)&b_data, (size_t)2 * sizeof(uint8_T));
  b_x[0] = output_raw[1];
  b_x[1] = output_raw[0];
  memcpy((void *)&b_data, (void *)&b_x[0], (size_t)1 * sizeof(int16_T));

  /* End of MATLABSystem: '<Root>/ADS1x15' */
}

/* Model initialize function */
void RPI_ADS1115_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/ADS1x15' */
  RPI_ADS1115_DW.obj.i2cObj.matlabCodegenIsDeleted = true;
  RPI_ADS1115_DW.obj.matlabCodegenIsDeleted = true;
  RPI_ADS1115_ADS1x15_ADS1x15(&RPI_ADS1115_DW.obj);
  RPI_ADS1115_SystemCore_setup(&RPI_ADS1115_DW.obj);
}

/* Model terminate function */
void RPI_ADS1115_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/ADS1x15' */
  if (!RPI_ADS1115_DW.obj.matlabCodegenIsDeleted) {
    RPI_ADS1115_DW.obj.matlabCodegenIsDeleted = true;
    if ((RPI_ADS1115_DW.obj.isInitialized == 1) &&
        RPI_ADS1115_DW.obj.isSetupComplete) {
      MW_I2C_Close(RPI_ADS1115_DW.obj.i2cObj.MW_I2C_HANDLE);
    }
  }

  if (!RPI_ADS1115_DW.obj.i2cObj.matlabCodegenIsDeleted) {
    RPI_ADS1115_DW.obj.i2cObj.matlabCodegenIsDeleted = true;
    MW_I2C_Close(RPI_ADS1115_DW.obj.i2cObj.MW_I2C_HANDLE);
    if (RPI_ADS1115_DW.obj.i2cObj.isInitialized == 1) {
      RPI_ADS1115_DW.obj.i2cObj.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ADS1x15' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
