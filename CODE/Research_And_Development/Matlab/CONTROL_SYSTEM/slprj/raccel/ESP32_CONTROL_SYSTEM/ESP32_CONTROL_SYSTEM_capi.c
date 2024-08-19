#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ESP32_CONTROL_SYSTEM_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 21
#endif
#ifndef SS_INT64
#define SS_INT64 22
#endif
#else
#include "builtin_typeid_types.h"
#include "ESP32_CONTROL_SYSTEM.h"
#include "ESP32_CONTROL_SYSTEM_capi.h"
#include "ESP32_CONTROL_SYSTEM_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 6 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/If Action Subsystem" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 1 , 7 , TARGET_STRING ( "ESP32_CONTROL_SYSTEM/PID Control" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 8 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Pedal Calibration" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 3 , 8 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Pedal Calibration" ) , TARGET_STRING ( "" ) , 1 , 0 , 0
, 0 , 0 } , { 4 , 9 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Throttle Body Callibration" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 5 , 9 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Throttle Body Callibration" ) , TARGET_STRING ( "" ) ,
1 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING ( "ESP32_CONTROL_SYSTEM/Abs" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Constant3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 8 , 0 , TARGET_STRING ( "ESP32_CONTROL_SYSTEM/Sum2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/FP_Input Range Conversion/Product" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/FP_Input Range Conversion/Add" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/FP_Input Range Conversion/Add1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 12 , 1 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Foot Pedal Signal/ESP23_ANALOG_READ_DDAppGeneratedBlock1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/H-Bridge Setting/Enable Pin" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 14 , 6 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/If Action Subsystem/In1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 15 , 7 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/PID Control/Saturation" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/Logical Operator1" ) , TARGET_STRING ( "" ) ,
0 , 1 , 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/Logical Operator12" ) , TARGET_STRING ( "" )
, 0 , 1 , 0 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/Logical Operator2" ) , TARGET_STRING ( "" ) ,
0 , 1 , 0 , 0 , 1 } , { 19 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/Logical Operator3" ) , TARGET_STRING ( "" ) ,
0 , 1 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/Logical Operator4" ) , TARGET_STRING ( "" ) ,
0 , 1 , 0 , 0 , 1 } , { 21 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/Logical Operator8" ) , TARGET_STRING ( "" ) ,
0 , 1 , 0 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/TB_Feedbakc Range Conversion/Add" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/TB_Feedbakc Range Conversion/Add1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 10 , TARGET_STRING (
 "ESP32_CONTROL_SYSTEM/Throttle Body Feedback/ESP23_ANALOG_READ_DDAppGeneratedBlock"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop/Logic" ) , TARGET_STRING ( "" )
, 0 , 1 , 1 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop1/Logic" ) , TARGET_STRING ( ""
) , 0 , 1 , 1 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop2/Logic" ) , TARGET_STRING ( ""
) , 0 , 1 , 1 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 }
} ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 28 ,
TARGET_STRING ( "ESP32_CONTROL_SYSTEM/Constant3" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 29 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Foot Pedal Signal/ESP23_ANALOG_READ_DDAppGeneratedBlock1"
) , TARGET_STRING ( "SampleTime" ) , 0 , 0 , 0 } , { 30 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/H-Bridge Setting/MATLAB System" ) , TARGET_STRING (
"SampleTime" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/If Action Subsystem/Out1" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/PID Control/PID Output" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 33 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/PID Control/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 34 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/PID Control/Saturation" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop" ) , TARGET_STRING (
"initial_condition" ) , 1 , 0 , 0 } , { 36 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop1" ) , TARGET_STRING (
"initial_condition" ) , 1 , 0 , 0 } , { 37 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop2" ) , TARGET_STRING (
"initial_condition" ) , 1 , 0 , 0 } , { 38 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/Constant" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 39 , TARGET_STRING ( "ESP32_CONTROL_SYSTEM/Subsystem/Constant2" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/Constant3" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 41 , TARGET_STRING (
 "ESP32_CONTROL_SYSTEM/Throttle Body Feedback/ESP23_ANALOG_READ_DDAppGeneratedBlock"
) , TARGET_STRING ( "SampleTime" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop/Logic" ) , TARGET_STRING (
"TruthTable" ) , 1 , 2 , 0 } , { 43 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop1/Logic" ) , TARGET_STRING (
"TruthTable" ) , 1 , 2 , 0 } , { 44 , TARGET_STRING (
"ESP32_CONTROL_SYSTEM/Subsystem/S-R Flip-Flop2/Logic" ) , TARGET_STRING (
"TruthTable" ) , 1 , 2 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ;
static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 45 , TARGET_STRING (
"Desire_Max" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING ( "Desire_Min" ) , 0 , 0
, 0 } , { 47 , TARGET_STRING ( "EN_Pin" ) , 0 , 0 , 0 } , { 48 ,
TARGET_STRING ( "Kp" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . nzuc3bbrlw , & rtB . bau2xxwqfo ,
& rtB . lkwjxdp1nd , & rtB . hhrdlpy0f1 , & rtB . mn5225snhj , & rtB .
kvlnakxcle , & rtB . kup3k4djp2 , & rtB . b11m1qjdau , & rtB . beag5zqefx , &
rtB . oyjj50ava1 , & rtB . na1hcq14yz , & rtB . lrpa3i4esi , & rtB .
natjvn3ndc , & rtB . pa54dctzk4 , & rtB . nzuc3bbrlw , & rtB . bau2xxwqfo , &
rtB . px4kkvrnqh , & rtB . jfg5plt3zq , & rtB . d0huozsipw , & rtB .
jce0j0kvq0 , & rtB . bujahb4nz0 , & rtB . eu2i5x3hxj , & rtB . bycanyiwbu , &
rtB . bju3kpli0i , & rtB . awwjveugww , & rtB . jjk0zpl2ip [ 0 ] , & rtB .
e1fsn4x2kx [ 0 ] , & rtB . mjkefw0glp [ 0 ] , & rtP . Constant3_Value , & rtP
. ESP23_ANALOG_READ_DDAppGeneratedBlock1_SampleTime , & rtP .
MATLABSystem_SampleTime , & rtP . Out1_Y0 , & rtP . PIDOutput_Y0 , & rtP .
Saturation_UpperSat , & rtP . Saturation_LowerSat , & rtP .
SRFlipFlop_initial_condition , & rtP . SRFlipFlop1_initial_condition , & rtP
. SRFlipFlop2_initial_condition , & rtP . Constant_Value , & rtP .
Constant2_Value , & rtP . Constant3_Value_lhquxpnirq , & rtP .
ESP23_ANALOG_READ_DDAppGeneratedBlock_SampleTime , & rtP .
Logic_table_d2use2ry5x [ 0 ] , & rtP . Logic_table_d2xeq0qaza [ 0 ] , & rtP .
Logic_table [ 0 ] , & rtP . Desire_Max , & rtP . Desire_Min , & rtP . EN_Pin
, & rtP . Kp , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , ( uint8_T )
SS_BOOLEAN , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 1 , 1 , 2 , 1 , 8 , 2 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.05 , 0.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , (
boolean_T ) 0 } , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ]
= { { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( NULL ) , (
NULL ) , 1 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 28 , rtRootInputs , 0 , rtRootOutputs , 0 } , {
rtBlockParameters , 17 , rtModelParameters , 4 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 2465906952U , 2396748390U , 3124760881U ,
1359990380U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * ESP32_CONTROL_SYSTEM_GetCAPIStaticMap
( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void ESP32_CONTROL_SYSTEM_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion
( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void ESP32_CONTROL_SYSTEM_host_InitializeDataMapInfo (
ESP32_CONTROL_SYSTEM_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
