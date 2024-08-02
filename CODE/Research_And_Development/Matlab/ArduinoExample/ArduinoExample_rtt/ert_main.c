/*
 * File: ert_main.c
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
#include "Arduino.h"
#include <ext_work.h>                  /* External mode header files */
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>
#define STEP_SIZE                      (unsigned long) (200000)

int_T main(void)
{
  unsigned long oldtime = 0L;
  unsigned long actualtime;
  init();

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  ArduinoExample_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(ArduinoExample_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = FALSE;
    rtExtModeWaitForStartPkt(ArduinoExample_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(ArduinoExample_M, TRUE);
    }
  }

  rtERTExtModeStartMsg();

#ifdef _RTT_USE_SERIAL1_

  Serial_begin(1, 9600);

#endif

#ifdef _RTT_USE_SERIAL2_

  Serial_begin(2, 9600);

#endif

#ifdef _RTT_USE_SERIAL3_

  Serial_begin(3, 9600);

#endif

  /* The main step loop */
  while ((rtmGetErrorStatus(ArduinoExample_M) == (NULL)) && !rtmGetStopRequested
         (ArduinoExample_M)) {
    actualtime = micros();
    if ((unsigned long) (actualtime - oldtime) >= STEP_SIZE) {
      oldtime = actualtime;

      /* External mode */
      {
        boolean_T rtmStopReq = FALSE;
        rtExtModeOneStep(ArduinoExample_M->extModeInfo, 1, &rtmStopReq);
        if (rtmStopReq) {
          rtmSetStopRequested(ArduinoExample_M, TRUE);
        }
      }

      ArduinoExample_output();

      /* Get model outputs here */

      /* External mode */
      rtExtModeUploadCheckTrigger(1);

      {                                /* Sample time: [0.2s, 0.0s] */
        rtExtModeUpload(0, ArduinoExample_M->Timing.taskTime0);
      }

      ArduinoExample_update();
      rtExtModeCheckEndTrigger();
    }
  }

  rtExtModeShutdown(1);
  delay(1000);
  ArduinoExample_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
