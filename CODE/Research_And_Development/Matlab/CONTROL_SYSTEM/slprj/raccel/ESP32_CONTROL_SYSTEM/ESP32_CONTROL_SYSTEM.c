#include "ESP32_CONTROL_SYSTEM.h"
#include "ESP32_CONTROL_SYSTEM_types.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "rt_logging_mmi.h"
#include "ESP32_CONTROL_SYSTEM_capi.h"
#include "ESP32_CONTROL_SYSTEM_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , &
stopRequested ) ; } rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_engine_exec.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "24.1 (R2024a) 19-Nov-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 } ; const char
* raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_engine_exec.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define jwqif3hij5 (-1)
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; static void kvdhpyjlir ( esrqlk55ff * obj , real_T newTime ) ;
static void kvdhpyjlir1 ( blgorz4e4p * obj , real_T newTime ) ; static void
ndwgjvpext ( pntbhiegs1 * obj ) ; static void kvdhpyjlir ( esrqlk55ff * obj ,
real_T newTime ) { obj -> SampleTime = newTime ; } static void kvdhpyjlir1 (
blgorz4e4p * obj , real_T newTime ) { obj -> SampleTime = newTime ; } static
void ndwgjvpext ( pntbhiegs1 * obj ) { if ( ( obj -> isInitialized == 1 ) &&
obj -> isSetupComplete ) { obj -> PWMDriverObj . MW_PWM_HANDLE =
MW_PWM_GetHandle ( 2U ) ; MW_PWM_SetDutyCycle ( obj -> PWMDriverObj .
MW_PWM_HANDLE , - 0.0 ) ; obj -> PWMDriverObj . MW_PWM_HANDLE =
MW_PWM_GetHandle ( 2U ) ; MW_PWM_Close ( obj -> PWMDriverObj . MW_PWM_HANDLE
) ; } } void MdlInitialize ( void ) { rtDW . iqkzlayyoz = rtP .
SRFlipFlop2_initial_condition ; rtDW . jbtnexulne = rtP .
SRFlipFlop_initial_condition ; rtDW . fgencks1rr = rtP .
SRFlipFlop1_initial_condition ; rtDW . ael0xmoqfk = - 1.0 ; rtDW . ppkepdgicr
= true ; rtDW . nnqdqjkzh0 = 5.0 ; rtDW . dlfzvyk43d = true ; rtDW .
pgzxjuy5rd = false ; rtDW . dzx1zvljdx = jwqif3hij5 ; rtDW . h4u5gxaeco = 0.0
; rtDW . b4hsj1czxa = true ; rtDW . cugyfmtf3n = 5.0 ; rtDW . jqo0zm3h2d =
true ; rtDW . i5zvnxp2r1 = false ; rtDW . lqijnndszp = jwqif3hij5 ; rtB .
nzuc3bbrlw = rtP . Out1_Y0 ; rtB . bau2xxwqfo = rtP . PIDOutput_Y0 ; } void
MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
 "ESP32_CONTROL_SYSTEM/Throttle Body Feedback/ESP23_ANALOG_READ_DDAppGeneratedBlock"
) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 2 ] = { 1 , 1 } ; sigDims . nDims = 2 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. h2ejymjsjy . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"c2e04d10-fe8a-49a0-a5d7-b4b1db8c965f" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . h2ejymjsjy . AQHandles , hDT , & srcInfo ) ; if ( rtDW . h2ejymjsjy .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . h2ejymjsjy . AQHandles ,
"0.05" , 0.05 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
h2ejymjsjy . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . h2ejymjsjy .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . h2ejymjsjy . AQHandles , 1 , 50000 ) ;
sdiAsyncRepoSetSignalExportName ( rtDW . h2ejymjsjy . AQHandles , loggedName
, origSigName , propName ) ; } sdiFreeLabel ( sigName ) ; sdiFreeLabel (
loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel ( propName ) ;
sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; sdiFreeLabel (
subPath ) ; } } if ( ! isStreamoutAlreadyRegistered ) { } } } } rtDW .
e04iubfqaj . isInitialized = 0 ; rtDW . e04iubfqaj . SampleTime = - 1.0 ;
rtDW . e04iubfqaj . matlabCodegenIsDeleted = false ; rtDW . nu1d13x2he = true
; kvdhpyjlir ( & rtDW . e04iubfqaj , rtP .
ESP23_ANALOG_READ_DDAppGeneratedBlock1_SampleTime ) ; rtDW . e04iubfqaj .
isInitialized = 1 ; setupFunctionESP32_ANALOG_READ ( 34 , 1.0 ) ; rtDW .
e04iubfqaj . isSetupComplete = true ; rtDW . p3r0gb03ym . isInitialized = 0 ;
rtDW . p3r0gb03ym . SampleTime = - 1.0 ; rtDW . p3r0gb03ym .
matlabCodegenIsDeleted = false ; rtDW . bdwoarctdr = true ; kvdhpyjlir ( &
rtDW . p3r0gb03ym , rtP . ESP23_ANALOG_READ_DDAppGeneratedBlock_SampleTime )
; rtDW . p3r0gb03ym . isInitialized = 1 ; setupFunctionESP32_ANALOG_READ ( 35
, 1.0 ) ; rtDW . p3r0gb03ym . isSetupComplete = true ; rtDW . im1fctk0q1 .
matlabCodegenIsDeleted = false ; rtDW . bprpcacnxj = true ; rtDW . im1fctk0q1
. isInitialized = 1 ; rtDW . im1fctk0q1 . PWMDriverObj . MW_PWM_HANDLE =
MW_PWM_Open ( 2U , 19000.0 , 255.0 ) ; rtDW . im1fctk0q1 . isSetupComplete =
true ; rtDW . nib2ue5ne1 . matlabCodegenIsDeleted = false ; rtDW . i0zqzmk04w
= true ; rtDW . nib2ue5ne1 . isInitialized = 1 ; digitalIOSetup ( 0 , 1 ) ;
rtDW . nib2ue5ne1 . isSetupComplete = true ; rtDW . paw5p34xdz .
matlabCodegenIsDeleted = false ; rtDW . mie5grxc3r = true ; rtDW . paw5p34xdz
. isInitialized = 1 ; digitalIOSetup ( 4 , 1 ) ; rtDW . paw5p34xdz .
isSetupComplete = true ; rtDW . ijzqlftzv5 . isInitialized = 0 ; rtDW .
ijzqlftzv5 . SampleTime = - 1.0 ; rtDW . ijzqlftzv5 . matlabCodegenIsDeleted
= false ; rtDW . ogh3golwcm = true ; kvdhpyjlir1 ( & rtDW . ijzqlftzv5 , rtP
. MATLABSystem_SampleTime ) ; rtDW . ijzqlftzv5 . isInitialized = 1 ;
setupFunctionLEDC_INTERFACE ( 0 , 1.0 , 0 , 1.0 , 0 , 1.0 , 0 , 1.0 , 0LL ,
1.0 ) ; rtDW . ijzqlftzv5 . isSetupComplete = true ; MdlInitialize ( ) ; }
void MdlOutputs ( int_T tid ) { real_T tmp ; int32_T rowIdx ; uint8_T tmp_p ;
srClearBC ( rtDW . opdzx13d4w ) ; srClearBC ( rtDW . neukdt43no ) ; if ( rtDW
. e04iubfqaj . SampleTime != rtP .
ESP23_ANALOG_READ_DDAppGeneratedBlock1_SampleTime ) { kvdhpyjlir ( & rtDW .
e04iubfqaj , rtP . ESP23_ANALOG_READ_DDAppGeneratedBlock1_SampleTime ) ; }
rtB . natjvn3ndc = 0.0 ; stepFunctionESP32_ANALOG_READ ( 34 , & rtB .
natjvn3ndc , 1.0 ) ; rtDW . dzx1zvljdx = jwqif3hij5 ; if ( rtB . natjvn3ndc >
rtDW . ael0xmoqfk ) { rtDW . ael0xmoqfk = rtB . natjvn3ndc ; } if ( rtB .
natjvn3ndc < rtDW . nnqdqjkzh0 ) { rtDW . nnqdqjkzh0 = rtB . natjvn3ndc ; }
rtB . lkwjxdp1nd = rtDW . ael0xmoqfk ; rtB . hhrdlpy0f1 = rtDW . nnqdqjkzh0 ;
rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) rtB . jfg5plt3zq << 1 ) + rtB .
jce0j0kvq0 ) << 1 ) + rtDW . iqkzlayyoz ) ; rtB . mjkefw0glp [ 0U ] = rtP .
Logic_table [ ( uint32_T ) rowIdx ] ; rtB . mjkefw0glp [ 1U ] = rtP .
Logic_table [ ( uint32_T ) rowIdx + 8U ] ; rowIdx = ( int32_T ) ( ( ( ( (
uint32_T ) rtB . bujahb4nz0 << 1 ) + rtB . px4kkvrnqh ) << 1 ) + rtDW .
jbtnexulne ) ; rtB . jjk0zpl2ip [ 0U ] = rtP . Logic_table_d2use2ry5x [ (
uint32_T ) rowIdx ] ; rtB . jjk0zpl2ip [ 1U ] = rtP . Logic_table_d2use2ry5x
[ ( uint32_T ) rowIdx + 8U ] ; rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) rtB
. eu2i5x3hxj << 1 ) + rtB . d0huozsipw ) << 1 ) + rtDW . fgencks1rr ) ; rtB .
e1fsn4x2kx [ 0U ] = rtP . Logic_table_d2xeq0qaza [ ( uint32_T ) rowIdx ] ;
rtB . e1fsn4x2kx [ 1U ] = rtP . Logic_table_d2xeq0qaza [ ( uint32_T ) rowIdx
+ 8U ] ; if ( rtDW . p3r0gb03ym . SampleTime != rtP .
ESP23_ANALOG_READ_DDAppGeneratedBlock_SampleTime ) { kvdhpyjlir ( & rtDW .
p3r0gb03ym , rtP . ESP23_ANALOG_READ_DDAppGeneratedBlock_SampleTime ) ; } rtB
. awwjveugww = 0.0 ; stepFunctionESP32_ANALOG_READ ( 35 , & rtB . awwjveugww
, 1.0 ) ; rtDW . lqijnndszp = jwqif3hij5 ; if ( rtB . awwjveugww > rtDW .
h4u5gxaeco ) { rtDW . h4u5gxaeco = rtB . awwjveugww ; } if ( rtB . awwjveugww
< rtDW . cugyfmtf3n ) { rtDW . cugyfmtf3n = rtB . awwjveugww ; } rtB .
mn5225snhj = rtDW . h4u5gxaeco ; rtB . kvlnakxcle = rtDW . cugyfmtf3n ; rtB .
bycanyiwbu = rtB . mn5225snhj - rtB . kvlnakxcle ; rtB . bju3kpli0i = rtB .
lkwjxdp1nd - rtB . hhrdlpy0f1 ; rtB . kup3k4djp2 = muDoubleScalarAbs ( rtB .
bycanyiwbu / rtB . bju3kpli0i * rtB . awwjveugww ) ; rtB . beag5zqefx = rtB .
natjvn3ndc - rtB . kup3k4djp2 ; if ( rtB . mjkefw0glp [ 0 ] ) { rtB .
nzuc3bbrlw = rtB . beag5zqefx ; srUpdateBC ( rtDW . opdzx13d4w ) ; } else if
( rtB . jjk0zpl2ip [ 0 ] ) { rtB . bau2xxwqfo = rtP . Kp * rtB . beag5zqefx ;
if ( rtB . bau2xxwqfo > rtP . Saturation_UpperSat ) { rtB . bau2xxwqfo = rtP
. Saturation_UpperSat ; } else if ( rtB . bau2xxwqfo < rtP .
Saturation_LowerSat ) { rtB . bau2xxwqfo = rtP . Saturation_LowerSat ; }
srUpdateBC ( rtDW . neukdt43no ) ; } rtB . lrpa3i4esi = rtB . lkwjxdp1nd -
rtB . hhrdlpy0f1 ; if ( rtB . jjk0zpl2ip [ 0 ] ) { tmp = rtB . bau2xxwqfo ; }
else { tmp = rtB . nzuc3bbrlw ; } rtB . oyjj50ava1 = rtB . na1hcq14yz / rtB .
lrpa3i4esi * tmp ; rtDW . im1fctk0q1 . PWMDriverObj . MW_PWM_HANDLE =
MW_PWM_GetHandle ( 2U ) ; MW_PWM_SetDutyCycle ( rtDW . im1fctk0q1 .
PWMDriverObj . MW_PWM_HANDLE , - ( muDoubleScalarMax ( muDoubleScalarMin (
rtB . oyjj50ava1 , 255.0 ) , 0.0 ) * 255.0 / 255.0 ) ) ; tmp =
muDoubleScalarRound ( rtB . b11m1qjdau ) ; if ( tmp < 256.0 ) { if ( tmp >=
0.0 ) { tmp_p = ( uint8_T ) tmp ; } else { tmp_p = 0U ; } } else if ( tmp >=
256.0 ) { tmp_p = MAX_uint8_T ; } else { tmp_p = 0U ; } writeDigitalPin ( 0 ,
tmp_p ) ; tmp = muDoubleScalarRound ( rtB . pa54dctzk4 ) ; if ( tmp < 256.0 )
{ if ( tmp >= 0.0 ) { tmp_p = ( uint8_T ) tmp ; } else { tmp_p = 0U ; } }
else if ( tmp >= 256.0 ) { tmp_p = MAX_uint8_T ; } else { tmp_p = 0U ; }
writeDigitalPin ( 4 , tmp_p ) ; if ( rtDW . ijzqlftzv5 . SampleTime != rtP .
MATLABSystem_SampleTime ) { kvdhpyjlir1 ( & rtDW . ijzqlftzv5 , rtP .
MATLABSystem_SampleTime ) ; } stepFunctionLEDC_INTERFACE ( 0.0 , 1.0 ) ; { if
( rtDW . h2ejymjsjy . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal
( rtDW . h2ejymjsjy . AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) &
rtB . awwjveugww + 0 ) ; } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID1
( int_T tid ) { rtB . b11m1qjdau = rtP . Constant3_Value ; rtB . pa54dctzk4 =
rtP . EN_Pin ; rtB . na1hcq14yz = rtP . Desire_Max - rtP . Desire_Min ; rtB .
px4kkvrnqh = ( rtP . Constant2_Value != 0.0 ) ^ ( rtP .
Constant3_Value_lhquxpnirq != 0.0 ) ; rtB . jfg5plt3zq = ( ( rtP .
Constant3_Value_lhquxpnirq != 0.0 ) && ( ( ! ( rtP . Constant2_Value != 0.0 )
) && ( ! ( rtP . Constant_Value != 0.0 ) ) ) ) ; rtB . d0huozsipw = ( rtP .
Constant_Value != 0.0 ) ^ ( rtP . Constant3_Value_lhquxpnirq != 0.0 ) ; rtB .
jce0j0kvq0 = ( rtP . Constant_Value != 0.0 ) ^ ( rtP . Constant2_Value != 0.0
) ; rtB . bujahb4nz0 = ( ( rtP . Constant_Value != 0.0 ) && ( ( ! ( rtP .
Constant3_Value_lhquxpnirq != 0.0 ) ) && ( ! ( rtP . Constant2_Value != 0.0 )
) ) ) ; rtB . eu2i5x3hxj = ( ( rtP . Constant2_Value != 0.0 ) && ( ( ! ( rtP
. Constant_Value != 0.0 ) ) && ( ! ( rtP . Constant3_Value_lhquxpnirq != 0.0
) ) ) ) ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { rtDW .
iqkzlayyoz = rtB . mjkefw0glp [ 0 ] ; rtDW . jbtnexulne = rtB . jjk0zpl2ip [
0 ] ; rtDW . fgencks1rr = rtB . e1fsn4x2kx [ 0 ] ; UNUSED_PARAMETER ( tid ) ;
} void MdlUpdateTID1 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlTerminate ( void ) { if ( ! rtDW . e04iubfqaj . matlabCodegenIsDeleted ) {
rtDW . e04iubfqaj . matlabCodegenIsDeleted = true ; } if ( ! rtDW .
p3r0gb03ym . matlabCodegenIsDeleted ) { rtDW . p3r0gb03ym .
matlabCodegenIsDeleted = true ; } if ( ! rtDW . im1fctk0q1 .
matlabCodegenIsDeleted ) { rtDW . im1fctk0q1 . matlabCodegenIsDeleted = true
; ndwgjvpext ( & rtDW . im1fctk0q1 ) ; } if ( ! rtDW . nib2ue5ne1 .
matlabCodegenIsDeleted ) { rtDW . nib2ue5ne1 . matlabCodegenIsDeleted = true
; } if ( ! rtDW . paw5p34xdz . matlabCodegenIsDeleted ) { rtDW . paw5p34xdz .
matlabCodegenIsDeleted = true ; } if ( ! rtDW . ijzqlftzv5 .
matlabCodegenIsDeleted ) { rtDW . ijzqlftzv5 . matlabCodegenIsDeleted = true
; } { if ( rtDW . h2ejymjsjy . AQHandles ) { sdiTerminateStreaming ( & rtDW .
h2ejymjsjy . AQHandles ) ; } } } static void
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( mxArray * destArray , mwIndex i
, int j , const void * srcData , size_t numBytes ) ; static void
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( mxArray * destArray , mwIndex i
, int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ;
static void mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( void * destData
, const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy (
( uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_ESP32_CONTROL_SYSTEM_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) ; static void
mr_ESP32_CONTROL_SYSTEM_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j
, mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_ESP32_CONTROL_SYSTEM_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_ESP32_CONTROL_SYSTEM_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_ESP32_CONTROL_SYSTEM_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_ESP32_CONTROL_SYSTEM_cacheDataToMxArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) ; static void
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_ESP32_CONTROL_SYSTEM_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_ESP32_CONTROL_SYSTEM_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_ESP32_CONTROL_SYSTEM_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_ESP32_CONTROL_SYSTEM_extractBitFieldFromCellArrayWithOffset
( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T
numBits ) { const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_ESP32_CONTROL_SYSTEM_GetDWork ( ) {
static const char_T * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" ,
"NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 ,
ssDWFieldNames ) ; mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( ssDW , 0 , 0
, ( const void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char_T *
rtdwDataFieldNames [ 29 ] = { "rtDW.p3r0gb03ym" , "rtDW.e04iubfqaj" ,
"rtDW.ijzqlftzv5" , "rtDW.nib2ue5ne1" , "rtDW.paw5p34xdz" , "rtDW.im1fctk0q1"
, "rtDW.h4u5gxaeco" , "rtDW.cugyfmtf3n" , "rtDW.ael0xmoqfk" ,
"rtDW.nnqdqjkzh0" , "rtDW.lqijnndszp" , "rtDW.dzx1zvljdx" , "rtDW.neukdt43no"
, "rtDW.opdzx13d4w" , "rtDW.iqkzlayyoz" , "rtDW.jbtnexulne" ,
"rtDW.fgencks1rr" , "rtDW.bdwoarctdr" , "rtDW.i5zvnxp2r1" , "rtDW.b4hsj1czxa"
, "rtDW.jqo0zm3h2d" , "rtDW.pgzxjuy5rd" , "rtDW.ppkepdgicr" ,
"rtDW.dlfzvyk43d" , "rtDW.bprpcacnxj" , "rtDW.ogh3golwcm" , "rtDW.i0zqzmk04w"
, "rtDW.mie5grxc3r" , "rtDW.nu1d13x2he" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 29 , rtdwDataFieldNames ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void
* ) & ( rtDW . p3r0gb03ym ) , sizeof ( rtDW . p3r0gb03ym ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void
* ) & ( rtDW . e04iubfqaj ) , sizeof ( rtDW . e04iubfqaj ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void
* ) & ( rtDW . ijzqlftzv5 ) , sizeof ( rtDW . ijzqlftzv5 ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void
* ) & ( rtDW . nib2ue5ne1 ) , sizeof ( rtDW . nib2ue5ne1 ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void
* ) & ( rtDW . paw5p34xdz ) , sizeof ( rtDW . paw5p34xdz ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void
* ) & ( rtDW . im1fctk0q1 ) , sizeof ( rtDW . im1fctk0q1 ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void
* ) & ( rtDW . h4u5gxaeco ) , sizeof ( rtDW . h4u5gxaeco ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void
* ) & ( rtDW . cugyfmtf3n ) , sizeof ( rtDW . cugyfmtf3n ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void
* ) & ( rtDW . ael0xmoqfk ) , sizeof ( rtDW . ael0xmoqfk ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void
* ) & ( rtDW . nnqdqjkzh0 ) , sizeof ( rtDW . nnqdqjkzh0 ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void
* ) & ( rtDW . lqijnndszp ) , sizeof ( rtDW . lqijnndszp ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void
* ) & ( rtDW . dzx1zvljdx ) , sizeof ( rtDW . dzx1zvljdx ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void
* ) & ( rtDW . neukdt43no ) , sizeof ( rtDW . neukdt43no ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void
* ) & ( rtDW . opdzx13d4w ) , sizeof ( rtDW . opdzx13d4w ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void
* ) & ( rtDW . iqkzlayyoz ) , sizeof ( rtDW . iqkzlayyoz ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void
* ) & ( rtDW . jbtnexulne ) , sizeof ( rtDW . jbtnexulne ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void
* ) & ( rtDW . fgencks1rr ) , sizeof ( rtDW . fgencks1rr ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void
* ) & ( rtDW . bdwoarctdr ) , sizeof ( rtDW . bdwoarctdr ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void
* ) & ( rtDW . i5zvnxp2r1 ) , sizeof ( rtDW . i5zvnxp2r1 ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void
* ) & ( rtDW . b4hsj1czxa ) , sizeof ( rtDW . b4hsj1czxa ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void
* ) & ( rtDW . jqo0zm3h2d ) , sizeof ( rtDW . jqo0zm3h2d ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void
* ) & ( rtDW . pgzxjuy5rd ) , sizeof ( rtDW . pgzxjuy5rd ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void
* ) & ( rtDW . ppkepdgicr ) , sizeof ( rtDW . ppkepdgicr ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void
* ) & ( rtDW . dlfzvyk43d ) , sizeof ( rtDW . dlfzvyk43d ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void
* ) & ( rtDW . bprpcacnxj ) , sizeof ( rtDW . bprpcacnxj ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void
* ) & ( rtDW . ogh3golwcm ) , sizeof ( rtDW . ogh3golwcm ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void
* ) & ( rtDW . i0zqzmk04w ) , sizeof ( rtDW . i0zqzmk04w ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void
* ) & ( rtDW . mie5grxc3r ) , sizeof ( rtDW . mie5grxc3r ) ) ;
mr_ESP32_CONTROL_SYSTEM_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void
* ) & ( rtDW . nu1d13x2he ) , sizeof ( rtDW . nu1d13x2he ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_ESP32_CONTROL_SYSTEM_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW
, 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber
( ssDW , 0 , 1 ) ; mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void *
) & ( rtDW . p3r0gb03ym ) , rtdwData , 0 , 0 , sizeof ( rtDW . p3r0gb03ym ) )
; mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
e04iubfqaj ) , rtdwData , 0 , 1 , sizeof ( rtDW . e04iubfqaj ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ijzqlftzv5 ) , rtdwData , 0 , 2 , sizeof ( rtDW . ijzqlftzv5 ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
nib2ue5ne1 ) , rtdwData , 0 , 3 , sizeof ( rtDW . nib2ue5ne1 ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
paw5p34xdz ) , rtdwData , 0 , 4 , sizeof ( rtDW . paw5p34xdz ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
im1fctk0q1 ) , rtdwData , 0 , 5 , sizeof ( rtDW . im1fctk0q1 ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
h4u5gxaeco ) , rtdwData , 0 , 6 , sizeof ( rtDW . h4u5gxaeco ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cugyfmtf3n ) , rtdwData , 0 , 7 , sizeof ( rtDW . cugyfmtf3n ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ael0xmoqfk ) , rtdwData , 0 , 8 , sizeof ( rtDW . ael0xmoqfk ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
nnqdqjkzh0 ) , rtdwData , 0 , 9 , sizeof ( rtDW . nnqdqjkzh0 ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lqijnndszp ) , rtdwData , 0 , 10 , sizeof ( rtDW . lqijnndszp ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dzx1zvljdx ) , rtdwData , 0 , 11 , sizeof ( rtDW . dzx1zvljdx ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
neukdt43no ) , rtdwData , 0 , 12 , sizeof ( rtDW . neukdt43no ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
opdzx13d4w ) , rtdwData , 0 , 13 , sizeof ( rtDW . opdzx13d4w ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
iqkzlayyoz ) , rtdwData , 0 , 14 , sizeof ( rtDW . iqkzlayyoz ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jbtnexulne ) , rtdwData , 0 , 15 , sizeof ( rtDW . jbtnexulne ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
fgencks1rr ) , rtdwData , 0 , 16 , sizeof ( rtDW . fgencks1rr ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bdwoarctdr ) , rtdwData , 0 , 17 , sizeof ( rtDW . bdwoarctdr ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
i5zvnxp2r1 ) , rtdwData , 0 , 18 , sizeof ( rtDW . i5zvnxp2r1 ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
b4hsj1czxa ) , rtdwData , 0 , 19 , sizeof ( rtDW . b4hsj1czxa ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jqo0zm3h2d ) , rtdwData , 0 , 20 , sizeof ( rtDW . jqo0zm3h2d ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pgzxjuy5rd ) , rtdwData , 0 , 21 , sizeof ( rtDW . pgzxjuy5rd ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ppkepdgicr ) , rtdwData , 0 , 22 , sizeof ( rtDW . ppkepdgicr ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dlfzvyk43d ) , rtdwData , 0 , 23 , sizeof ( rtDW . dlfzvyk43d ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bprpcacnxj ) , rtdwData , 0 , 24 , sizeof ( rtDW . bprpcacnxj ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ogh3golwcm ) , rtdwData , 0 , 25 , sizeof ( rtDW . ogh3golwcm ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
i0zqzmk04w ) , rtdwData , 0 , 26 , sizeof ( rtDW . i0zqzmk04w ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
mie5grxc3r ) , rtdwData , 0 , 27 , sizeof ( rtDW . mie5grxc3r ) ) ;
mr_ESP32_CONTROL_SYSTEM_restoreDataFromMxArray ( ( void * ) & ( rtDW .
nu1d13x2he ) , rtdwData , 0 , 28 , sizeof ( rtDW . nu1d13x2he ) ) ; } }
mxArray * mr_ESP32_CONTROL_SYSTEM_GetSimStateDisallowedBlocks ( ) { mxArray *
data = mxCreateCellMatrix ( 6 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static
const char_T * blockType [ 6 ] = { "MATLABSystem" , "MATLABSystem" ,
"MATLABSystem" , "MATLABSystem" , "MATLABSystem" , "MATLABSystem" , } ;
static const char_T * blockPath [ 6 ] = {
"ESP32_CONTROL_SYSTEM/Foot Pedal Signal/ESP23_ANALOG_READ_DDAppGeneratedBlock1"
, "ESP32_CONTROL_SYSTEM/H-Bridge Setting/Digital Output" ,
"ESP32_CONTROL_SYSTEM/H-Bridge Setting/Digital Output1" ,
"ESP32_CONTROL_SYSTEM/H-Bridge Setting/MATLAB System" ,
"ESP32_CONTROL_SYSTEM/H-Bridge Setting/PWM" ,
 "ESP32_CONTROL_SYSTEM/Throttle Body Feedback/ESP23_ANALOG_READ_DDAppGeneratedBlock"
, } ; static const int reason [ 6 ] = { 6 , 6 , 6 , 6 , 6 , 6 , } ; for (
subs [ 0 ] = 0 ; subs [ 0 ] < 6 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough
( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 1 ) ; ssSetNumBlocks ( rtS , 83 ) ;
ssSetNumBlockIO ( rtS , 26 ) ; ssSetNumBlockParams ( rtS , 66 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.05 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2465906952U ) ; ssSetChecksumVal ( rtS , 1 ,
2396748390U ) ; ssSetChecksumVal ( rtS , 2 , 3124760881U ) ; ssSetChecksumVal
( rtS , 3 , 1359990380U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 0 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
executionInfo -> gblObjects_ . numRootInportBlks = 0 ; executionInfo ->
gblObjects_ . inportDataTypeIdx = NULL ; executionInfo -> gblObjects_ .
inportDims = NULL ; executionInfo -> gblObjects_ . inportComplex = NULL ;
executionInfo -> gblObjects_ . inportInterpoFlag = NULL ; executionInfo ->
gblObjects_ . inportContinuous = NULL ; ( void ) memset ( ( char_T * ) rtS ,
0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo , 0 ,
sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 27 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
ESP32_CONTROL_SYSTEM_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"ESP32_CONTROL_SYSTEM" ) ; ssSetPath ( rtS , "ESP32_CONTROL_SYSTEM" ) ;
ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , INFINITY ) ; ssSetStepSize (
rtS , 0.05 ) ; ssSetFixedStepSize ( rtS , 0.05 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 50000 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo (
rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetNumNonContDerivSigInfos ( rtS , 0 ) ;
ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS , &
slvrInfo ) ; ssSetSolverName ( rtS , "FixedStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
2465906952U ) ; ssSetChecksumVal ( rtS , 1 , 2396748390U ) ; ssSetChecksumVal
( rtS , 2 , 3124760881U ) ; ssSetChecksumVal ( rtS , 3 , 1359990380U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 11 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = ( sysRanDType * ) & rtDW . opdzx13d4w ;
systemRan [ 7 ] = ( sysRanDType * ) & rtDW . neukdt43no ; systemRan [ 8 ] = &
rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ; systemRan [ 10 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_ESP32_CONTROL_SYSTEM_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_ESP32_CONTROL_SYSTEM_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_ESP32_CONTROL_SYSTEM_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } executionInfo -> simulationOptions_ . stateSaveName_ =
rtliGetLogX ( ssGetRTWLogInfo ( rtS ) ) ; executionInfo -> simulationOptions_
. finalStateName_ = rtliGetLogXFinal ( ssGetRTWLogInfo ( rtS ) ) ;
executionInfo -> simulationOptions_ . outputSaveName_ = rtliGetLogY (
ssGetRTWLogInfo ( rtS ) ) ; return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID1 ( tid ) ; }
