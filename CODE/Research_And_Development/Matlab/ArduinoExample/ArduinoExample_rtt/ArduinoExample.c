/*
 * File: ArduinoExample.c
 *
 * Code generated for Simulink model 'ArduinoExample'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Sat Oct 26 17:42:20 2013
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ArduinoExample.h"
#include "ArduinoExample_private.h"
#include "ArduinoExample_dt.h"

/* Real-time model */
RT_MODEL_ArduinoExample_T ArduinoExample_M_;
RT_MODEL_ArduinoExample_T *const ArduinoExample_M = &ArduinoExample_M_;

/* Model output function */
void ArduinoExample_output(void)
{
  /* S-Function (sfAFMotor): '<Root>/S-Function Builder' */
  sfAFMotor_Outputs_wrapper(&ArduinoExample_P.Constant_Value,
    &ArduinoExample_P.Constant1_Value );
}

/* Model update function */
void ArduinoExample_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(ArduinoExample_M)!=-1) &&
        !((rtmGetTFinal(ArduinoExample_M)-ArduinoExample_M->Timing.taskTime0) >
          ArduinoExample_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ArduinoExample_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ArduinoExample_M)) {
      rtmSetErrorStatus(ArduinoExample_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ArduinoExample_M->Timing.taskTime0 =
    (++ArduinoExample_M->Timing.clockTick0) * ArduinoExample_M->Timing.stepSize0;
}

/* Model initialize function */
void ArduinoExample_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ArduinoExample_M, 0,
                sizeof(RT_MODEL_ArduinoExample_T));
  rtmSetTFinal(ArduinoExample_M, -1);
  ArduinoExample_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  ArduinoExample_M->Sizes.checksums[0] = (4226897770U);
  ArduinoExample_M->Sizes.checksums[1] = (3787195326U);
  ArduinoExample_M->Sizes.checksums[2] = (3267069643U);
  ArduinoExample_M->Sizes.checksums[3] = (1034154733U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ArduinoExample_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ArduinoExample_M->extModeInfo,
      &ArduinoExample_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ArduinoExample_M->extModeInfo,
                        ArduinoExample_M->Sizes.checksums);
    rteiSetTPtr(ArduinoExample_M->extModeInfo, rtmGetTPtr(ArduinoExample_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ArduinoExample_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void ArduinoExample_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
