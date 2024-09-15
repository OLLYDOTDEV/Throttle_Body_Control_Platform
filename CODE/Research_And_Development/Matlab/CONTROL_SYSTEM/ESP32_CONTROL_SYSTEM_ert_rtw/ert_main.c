/*
 * Community and Technical College License -- for use in teaching and
 * meeting course requirements at community and technical colleges only.
 * Not for government, commercial, university, or other organizational
 * use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'ESP32_CONTROL_SYSTEM'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Aug 27 22:03:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "ESP32_CONTROL_SYSTEM.h"
#include "ESP32_CONTROL_SYSTEM_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
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
  runModel = (rtmGetErrorStatus(ESP32_CONTROL_SYSTEM_M) == (NULL)) &&
    !rtmGetStopRequested(ESP32_CONTROL_SYSTEM_M);
  while (runModel) {
    mw_osSemaphoreWaitEver(&baserateTaskSem);
    ESP32_CONTROL_SYSTEM_step();

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(ESP32_CONTROL_SYSTEM_M) == (NULL)) &&
                      !rtmGetStopRequested(ESP32_CONTROL_SYSTEM_M));
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
  rtmSetErrorStatus(ESP32_CONTROL_SYSTEM_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Terminate model */
  ESP32_CONTROL_SYSTEM_terminate();
  mw_osSemaphoreRelease(&stopSem);
  return NULL;
}

int app_main(int argc, char **argv)
{
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(ESP32_CONTROL_SYSTEM_M, 0);

  /* Initialize model */
  ESP32_CONTROL_SYSTEM_initialize();

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
