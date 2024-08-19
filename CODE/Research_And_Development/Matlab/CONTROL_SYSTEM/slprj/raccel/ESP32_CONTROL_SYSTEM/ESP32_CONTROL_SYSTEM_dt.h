#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , { "esrqlk55ff" , 17 , 24 } ,
{ "l3esrsu2eh" , 18 , 16 } , { "blgorz4e4p" , 19 , 24 } , { "pntbhiegs1" , 20
, 12 } , { "uint64_T" , 21 , 8 } , { "int64_T" , 22 , 8 } , { "uint_T" , 23 ,
32 } , { "char_T" , 24 , 8 } , { "uchar_T" , 25 , 8 } , { "time_T" , 26 , 8 }
} ; static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof (
real32_T ) , sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) ,
sizeof ( uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof (
boolean_T ) , sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T )
, sizeof ( action_T ) , 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof
( int64_T ) , sizeof ( uint64_T ) , sizeof ( esrqlk55ff ) , sizeof (
l3esrsu2eh ) , sizeof ( blgorz4e4p ) , sizeof ( pntbhiegs1 ) , sizeof (
uint64_T ) , sizeof ( int64_T ) , sizeof ( uint_T ) , sizeof ( char_T ) ,
sizeof ( uchar_T ) , sizeof ( time_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"physical_connection" , "int64_T" , "uint64_T" , "esrqlk55ff" , "l3esrsu2eh"
, "blgorz4e4p" , "pntbhiegs1" , "uint64_T" , "int64_T" , "uint_T" , "char_T"
, "uchar_T" , "time_T" } ; static DataTypeTransition rtBTransitions [ ] = { {
( char_T * ) ( & rtB . bycanyiwbu ) , 0 , 0 , 17 } , { ( char_T * ) ( & rtB .
mjkefw0glp [ 0 ] ) , 8 , 0 , 12 } , { ( char_T * ) ( & rtDW . p3r0gb03ym ) ,
17 , 0 , 2 } , { ( char_T * ) ( & rtDW . ijzqlftzv5 ) , 19 , 0 , 1 } , { (
char_T * ) ( & rtDW . nib2ue5ne1 ) , 18 , 0 , 2 } , { ( char_T * ) ( & rtDW .
im1fctk0q1 ) , 20 , 0 , 1 } , { ( char_T * ) ( & rtDW . h4u5gxaeco ) , 0 , 0
, 4 } , { ( char_T * ) ( & rtDW . h2ejymjsjy . AQHandles ) , 11 , 0 , 1 } , {
( char_T * ) ( & rtDW . lqijnndszp ) , 6 , 0 , 2 } , { ( char_T * ) ( & rtDW
. neukdt43no ) , 2 , 0 , 2 } , { ( char_T * ) ( & rtDW . iqkzlayyoz ) , 8 , 0
, 15 } } ; static DataTypeTransitionTable rtBTransTable = { 11U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . Desire_Max ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtP .
SRFlipFlop2_initial_condition ) , 8 , 0 , 3 } , { ( char_T * ) ( & rtP .
ESP23_ANALOG_READ_DDAppGeneratedBlock1_SampleTime ) , 0 , 0 , 11 } , { (
char_T * ) ( & rtP . Logic_table [ 0 ] ) , 8 , 0 , 48 } } ; static
DataTypeTransitionTable rtPTransTable = { 4U , rtPTransitions } ;
