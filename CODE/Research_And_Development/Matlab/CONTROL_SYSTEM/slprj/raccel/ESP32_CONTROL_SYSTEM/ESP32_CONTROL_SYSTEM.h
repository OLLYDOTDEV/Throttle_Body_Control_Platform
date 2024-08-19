#ifndef ESP32_CONTROL_SYSTEM_h_
#define ESP32_CONTROL_SYSTEM_h_
#ifndef ESP32_CONTROL_SYSTEM_COMMON_INCLUDES_
#define ESP32_CONTROL_SYSTEM_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#include "ESP32_ANALOG_READ.h"
#include "MW_arduino_digitalio.h"
#include "LEDC_INTERFACE.h"
#include "MW_PWM.h"
#endif
#include "ESP32_CONTROL_SYSTEM_types.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME ESP32_CONTROL_SYSTEM
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (26) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T bycanyiwbu ; real_T bju3kpli0i ; real_T kup3k4djp2 ;
real_T beag5zqefx ; real_T lrpa3i4esi ; real_T oyjj50ava1 ; real_T b11m1qjdau
; real_T pa54dctzk4 ; real_T na1hcq14yz ; real_T awwjveugww ; real_T
mn5225snhj ; real_T kvlnakxcle ; real_T lkwjxdp1nd ; real_T hhrdlpy0f1 ;
real_T bau2xxwqfo ; real_T nzuc3bbrlw ; real_T natjvn3ndc ; boolean_T
mjkefw0glp [ 2 ] ; boolean_T jjk0zpl2ip [ 2 ] ; boolean_T e1fsn4x2kx [ 2 ] ;
boolean_T px4kkvrnqh ; boolean_T jfg5plt3zq ; boolean_T d0huozsipw ;
boolean_T jce0j0kvq0 ; boolean_T bujahb4nz0 ; boolean_T eu2i5x3hxj ; } B ;
typedef struct { esrqlk55ff p3r0gb03ym ; esrqlk55ff e04iubfqaj ; blgorz4e4p
ijzqlftzv5 ; l3esrsu2eh nib2ue5ne1 ; l3esrsu2eh paw5p34xdz ; pntbhiegs1
im1fctk0q1 ; real_T h4u5gxaeco ; real_T cugyfmtf3n ; real_T ael0xmoqfk ;
real_T nnqdqjkzh0 ; struct { void * AQHandles ; } h2ejymjsjy ; int32_T
lqijnndszp ; int32_T dzx1zvljdx ; int8_T neukdt43no ; int8_T opdzx13d4w ;
boolean_T iqkzlayyoz ; boolean_T jbtnexulne ; boolean_T fgencks1rr ;
boolean_T bdwoarctdr ; boolean_T i5zvnxp2r1 ; boolean_T b4hsj1czxa ;
boolean_T jqo0zm3h2d ; boolean_T pgzxjuy5rd ; boolean_T ppkepdgicr ;
boolean_T dlfzvyk43d ; boolean_T bprpcacnxj ; boolean_T ogh3golwcm ;
boolean_T i0zqzmk04w ; boolean_T mie5grxc3r ; boolean_T nu1d13x2he ; } DW ;
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
real_T Desire_Max ; real_T Desire_Min ; real_T EN_Pin ; real_T Kp ; boolean_T
SRFlipFlop2_initial_condition ; boolean_T SRFlipFlop_initial_condition ;
boolean_T SRFlipFlop1_initial_condition ; real_T
ESP23_ANALOG_READ_DDAppGeneratedBlock1_SampleTime ; real_T
MATLABSystem_SampleTime ; real_T Out1_Y0 ; real_T PIDOutput_Y0 ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T
ESP23_ANALOG_READ_DDAppGeneratedBlock_SampleTime ; real_T Constant3_Value ;
real_T Constant_Value ; real_T Constant2_Value ; real_T
Constant3_Value_lhquxpnirq ; boolean_T Logic_table [ 16 ] ; boolean_T
Logic_table_d2use2ry5x [ 16 ] ; boolean_T Logic_table_d2xeq0qaza [ 16 ] ; } ;
extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW
rtDW ; extern P rtP ; extern mxArray * mr_ESP32_CONTROL_SYSTEM_GetDWork ( ) ;
extern void mr_ESP32_CONTROL_SYSTEM_SetDWork ( const mxArray * ssDW ) ;
extern mxArray * mr_ESP32_CONTROL_SYSTEM_GetSimStateDisallowedBlocks ( ) ;
extern const rtwCAPI_ModelMappingStaticInfo *
ESP32_CONTROL_SYSTEM_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS
; extern DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
