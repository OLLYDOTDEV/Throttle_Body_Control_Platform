#ifndef ESP32_CONTROL_SYSTEM_cap_host_h__
#define ESP32_CONTROL_SYSTEM_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap_simtarget.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
ESP32_CONTROL_SYSTEM_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void ESP32_CONTROL_SYSTEM_host_InitializeDataMapInfo (
ESP32_CONTROL_SYSTEM_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
