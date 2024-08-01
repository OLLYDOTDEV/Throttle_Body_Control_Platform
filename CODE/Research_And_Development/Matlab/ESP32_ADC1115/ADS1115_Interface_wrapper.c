
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#ifndef MATLAB_MEX_FILE
#define ARDUINO 100

#include "libraries/Adafruit_ADS1X15/Adafruit_ADS1X15.cpp"

Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
#define y_1_width 1
#define y_2_width 1
#define y_3_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void ADS1115_Interface_Outputs_wrapper(int16_T *A0,
			int16_T *A2,
			int16_T *A1,
			int16_T *A3,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */


    #ifndef MATLAB_MEX_FILE
    if(xD[0] == 1){
      A0[0] = ads.readADC_SingleEnded(0);
      A1[0] = ads.readADC_SingleEnded(1);
      A2[0] = ads.readADC_SingleEnded(2);
      A3[0] = ads.readADC_SingleEnded(3);
    }
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void ADS1115_Interface_Update_wrapper(int16_T *A0,
			int16_T *A2,
			int16_T *A1,
			int16_T *A3,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] != 1){
    #ifndef MATLAB_MEX_FILE
    ads.begin();
    xD[0] = 1;
#endif
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

