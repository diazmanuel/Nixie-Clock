
#ifndef NIXIEREQUIRED_H_
#define NIXIEREQUIRED_H_

#include "..\src\sc_types.h"
#include "Nixie.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
	- nixie_setTimer and
	- nixie_unsetTimer
are defined.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- nixieIface_increase
	- nixieIface_show
	- nixieIface_increaseLed
	- nixieIface_init
	- nixieIface_showLed
	- nixieIface_ledPower
	- nixieIface_send
	- nixieIface_nixiePower
	- nixieIface_buzzer
	- nixieIface_swapAlarm
	- nixieIface_swapLedFlag
	- nixieIface_alarmFlag
	- nixieIface_resetVar
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void nixieIface_increase(const Nixie* handle, const int32_t Type, const int32_t Unit);
extern void nixieIface_show(const Nixie* handle, const int32_t State);
extern void nixieIface_increaseLed(const Nixie* handle);
extern void nixieIface_init(const Nixie* handle);
extern void nixieIface_showLed(const Nixie* handle, const int32_t State);
extern void nixieIface_ledPower(const Nixie* handle, const int32_t State);
extern void nixieIface_send(const Nixie* handle, const int32_t State);
extern void nixieIface_nixiePower(const Nixie* handle, const int32_t State);
extern void nixieIface_buzzer(const Nixie* handle, const int32_t State);
extern void nixieIface_swapAlarm(const Nixie* handle);
extern void nixieIface_swapLedFlag(const Nixie* handle);
extern void nixieIface_alarmFlag(const Nixie* handle);
extern void nixieIface_resetVar(const Nixie* handle);



/*!
 * This is a timed state machine that requires timer services
 */ 

/*! This function has to set up timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milliseconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset 
*/
extern void nixie_setTimer(Nixie* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);

/*! This function has to unset timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event that is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
extern void nixie_unsetTimer(Nixie* handle, const sc_eventid evid);



#ifdef __cplusplus
}
#endif 

#endif /* NIXIEREQUIRED_H_ */
