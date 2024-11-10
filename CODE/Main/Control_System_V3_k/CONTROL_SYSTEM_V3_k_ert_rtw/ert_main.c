/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'CONTROL_SYSTEM_V3_k'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct 15 11:47:05 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "CONTROL_SYSTEM_V3_k.h"
#include "CONTROL_SYSTEM_V3_k_private.h"
#include "rtwtypes.h"
#include "limits.h"
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
SemaphoreHandle_t stopSem;
SemaphoreHandle_t baserateTaskSem;
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(CONTROL_SYSTEM_V3_k_M) == (NULL)) &&
    !rtmGetStopRequested(CONTROL_SYSTEM_V3_k_M);
  while (runModel) {
    mw_osSemaphoreWaitEver(&baserateTaskSem);
    CONTROL_SYSTEM_V3_k_step();

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(CONTROL_SYSTEM_V3_k_M) == (NULL)) &&
                      !rtmGetStopRequested(CONTROL_SYSTEM_V3_k_M));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(CONTROL_SYSTEM_V3_k_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Terminate model */
  CONTROL_SYSTEM_V3_k_terminate();
  mw_osSemaphoreRelease(&stopSem);
  return NULL;
}

int app_main(int argc, char **argv)
{
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(CONTROL_SYSTEM_V3_k_M, 0);

  /* Initialize model */
  CONTROL_SYSTEM_V3_k_initialize();

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.01, 0);

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
