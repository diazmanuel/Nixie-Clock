/*
 * nixieDisplay.h
 *
 *  Created on: 24 ene. 2019
 *      Author: Manuel
 */

#ifndef NIXIEDISPLAY_H_
#define NIXIEDISPLAY_H_

#include "main.h"

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_def.h"
#include "stddef.h"
#include "DS3231.h"
#include "../Yakindu/src-gen/Nixie.h"

typedef void (*raise_event_cb_t)(void *, sc_eventid);
#define MAX_NUM_TIMERS 5

#define SUCCESS 1
#define ERROR 0
#define NELEMENTS(array)  (sizeof (array) / sizeof (array[0]))

#define N_TIME 0
#define N_DATE 1
#define N_ALARM 2
#define N_TEMP 3
#define N_ALARM_STATE 4

#define E_B1 1
#define E_B2 2
#define E_B3 3
#define E_ALARM 4
#define E_SENSOR 5
#define ON 1
#define OFF 0

#define RED 0x04
#define GREEN 0x02
#define BLUE 0x01
#define WHITE 0x07
#define BLACK 0x00

#define DUTY 1 //10%

void resetGpio();
void nixieDisplay();
void nixieTickUpdate();
void nixieInit();
void nixieEvent(uint8_t event);

uint8_t nixieBuzzer(uint8_t Period, uint8_t Activity);
void resetVarNixie();
void nixieLed();
void testni();
uint8_t stateTimer_start(void * sm_handle, sc_eventid ev_id, raise_event_cb_t cb,uint32_t timeout, bool periodic);
void stateTimer_update(void);
uint8_t stateTimer_stop(sc_eventid ev_id);

void nixieIface_increase(const Nixie* handle, const int32_t Type, const int32_t Unit);
void nixieIface_show(const Nixie* handle, const int32_t State);
void nixieIface_increaseLed(const Nixie* handle);
void nixieIface_init(const Nixie* handle);
void nixieIface_showLed(const Nixie* handle, const int32_t State);
void nixieIface_ledPower(const Nixie* handle, const int32_t State);
void nixieIface_send(const Nixie* handle, const int32_t State);
void nixieIface_nixiePower(const Nixie* handle, const int32_t State);
void nixieIface_buzzer(const Nixie* handle, const int32_t State);
void nixieIface_swapAlarm(const Nixie* handle);
void nixieIface_swapLedFlag(const Nixie* handle);
void nixieIface_alarmFlag(const Nixie* handle);
void nixieIface_resetVar(const Nixie* handle);

#endif /* NIXIEDISPLAY_H_ */
