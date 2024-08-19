#include "ESP32_CONTROL_SYSTEM_capi_host.h"
static ESP32_CONTROL_SYSTEM_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        ESP32_CONTROL_SYSTEM_host_InitializeDataMapInfo(&(root), "ESP32_CONTROL_SYSTEM");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction(){return(getRootMappingInfo());}
