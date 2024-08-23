/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'CONTROL_SYSTEM_V2'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Aug 23 16:14:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "CONTROL_SYSTEM_V2.h"
#include "CONTROL_SYSTEM_V2_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "ext_mode.h"
#include "MW_ArduinoHWInit.h"
#include "mw_freertos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
extmodeErrorCode_T errorCode;
SemaphoreHandle_t stopSem;
SemaphoreHandle_t baserateTaskSem;
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(CONTROL_SYSTEM_V2_M) == (NULL)) &&
    !rtmGetStopRequested(CONTROL_SYSTEM_V2_M);
  while (runModel) {
    mw_osSemaphoreWaitEver(&baserateTaskSem);

    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    CONTROL_SYSTEM_V2_step();

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(CONTROL_SYSTEM_V2_M) == (NULL)) &&
                      !rtmGetStopRequested(CONTROL_SYSTEM_V2_M));
    runModel = !stopRequested && !extmodeSimulationComplete() &&
      !extmodeStopRequested();
  }

  runModel = 0;
  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(CONTROL_SYSTEM_V2_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Terminate model */
  CONTROL_SYSTEM_V2_terminate();
  extmodeReset();
  mw_osSemaphoreRelease(&stopSem);
  return NULL;
}

int app_main(int argc, char **argv)
{
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(CONTROL_SYSTEM_V2_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(argc, (const char_T **)argv);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  /* Initialize model */
  CONTROL_SYSTEM_V2_initialize();

  /* External Mode initialization */
  errorCode = extmodeInit(CONTROL_SYSTEM_V2_M->extModeInfo, &rtmGetTFinal
    (CONTROL_SYSTEM_V2_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(CONTROL_SYSTEM_V2_M, true);
    }
  }

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.05, 0);

  /* Wait for stop semaphore */
  mw_osSemaphoreWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSemaphoreDelete(&timerTaskSem[i]), 0,
                   "mw_osSemaphoreDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
