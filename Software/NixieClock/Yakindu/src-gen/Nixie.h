
#ifndef NIXIE_H_
#define NIXIE_H_

#include "..\src\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'nixie'.
*/

/*! Define number of states in the state enum */

#define NIXIE_STATE_COUNT 23

/*! Define dimension of the state configuration vector for orthogonal states. */
#define NIXIE_MAX_ORTHOGONAL_STATES 1

/*! Define maximum number of time events that can be active at once */
#define NIXIE_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_NIXIE_T_START 0
#define SCVI_NIXIE_T_START_CONFIGURATION_CONFIG 0
#define SCVI_NIXIE_T_START_CONFIGURATION_HOUR 0
#define SCVI_NIXIE_T_START_CONFIGURATION_MINUTES 0
#define SCVI_NIXIE_T_START_CONFIGURATION_YEAR 0
#define SCVI_NIXIE_T_START_CONFIGURATION_MONTH 0
#define SCVI_NIXIE_T_START_CONFIGURATION_DAY 0
#define SCVI_NIXIE_T_MODE1 0
#define SCVI_NIXIE_T_MODE1_AWAKE_AWAKE 0
#define SCVI_NIXIE_T_MODE1_AWAKE_DATE 0
#define SCVI_NIXIE_T_MODE1_AWAKE_TEMPERATURE 0
#define SCVI_NIXIE_T_MODE2 0
#define SCVI_NIXIE_T_MODE2_SLEEP_WAKE_UP 0
#define SCVI_NIXIE_T_MODE2_SLEEP_SLEEP 0
#define SCVI_NIXIE_T_MODE2_SLEEP_DATE 0
#define SCVI_NIXIE_T_MODE2_SLEEP_TEMPERATURE 0
#define SCVI_NIXIE_T_MODE3 0
#define SCVI_NIXIE_T_MODE3_ALARM_ALARMCONFIG 0
#define SCVI_NIXIE_T_MODE3_ALARM_HOUR 0
#define SCVI_NIXIE_T_MODE3_ALARM_MINUTE 0
#define SCVI_NIXIE_T_ALARM 0
#define SCVI_NIXIE_T_ALARM_ALARM_ALARM_ON_ 0
#define SCVI_NIXIE_T_ALARM_ALARM_ALARM_OFF_ 0

/*! Enumeration of all states */ 
typedef enum
{
	Nixie_last_state,
	Nixie_t_START,
	Nixie_t_START_Configuration_Config,
	Nixie_t_START_Configuration_Hour,
	Nixie_t_START_Configuration_Minutes,
	Nixie_t_START_Configuration_Year,
	Nixie_t_START_Configuration_Month,
	Nixie_t_START_Configuration_Day,
	Nixie_t_MODE1,
	Nixie_t_MODE1_Awake_Awake,
	Nixie_t_MODE1_Awake_Date,
	Nixie_t_MODE1_Awake_Temperature,
	Nixie_t_MODE2,
	Nixie_t_MODE2_Sleep_Wake_Up,
	Nixie_t_MODE2_Sleep_Sleep,
	Nixie_t_MODE2_Sleep_Date,
	Nixie_t_MODE2_Sleep_Temperature,
	Nixie_t_MODE3,
	Nixie_t_MODE3_Alarm_AlarmConfig,
	Nixie_t_MODE3_Alarm_Hour,
	Nixie_t_MODE3_Alarm_Minute,
	Nixie_t_Alarm,
	Nixie_t_Alarm_Alarm_Alarm_ON_,
	Nixie_t_Alarm_Alarm_Alarm_OFF_
} NixieStates;

/*! Type definition of the data structure for the NixieIface interface scope. */
typedef struct
{
	sc_boolean S_SENSOR_raised;
	sc_boolean B_1_raised;
	sc_boolean B_2_raised;
	sc_boolean B_3_raised;
	sc_boolean E_ALARM_raised;
} NixieIface;


/* Declaration of constants for scope NixieIface. */
extern const int32_t NIXIE_NIXIEIFACE_B_TIME;
extern const int32_t NIXIE_NIXIEIFACE_B_DATE;
extern const int32_t NIXIE_NIXIEIFACE_B_ALARM;
extern const int32_t NIXIE_NIXIEIFACE_TIME;
extern const int32_t NIXIE_NIXIEIFACE_DATE;
extern const int32_t NIXIE_NIXIEIFACE_ALARM;
extern const int32_t NIXIE_NIXIEIFACE_TEMP;
extern const int32_t NIXIE_NIXIEIFACE_ALARMSTATE;
extern const int32_t NIXIE_NIXIEIFACE_COUNTMAX;
extern const int32_t NIXIE_NIXIEIFACE_HOUR;
extern const int32_t NIXIE_NIXIEIFACE_MINUTE;
extern const int32_t NIXIE_NIXIEIFACE_SECONDS;
extern const int32_t NIXIE_NIXIEIFACE_YEAR;
extern const int32_t NIXIE_NIXIEIFACE_MONTH;
extern const int32_t NIXIE_NIXIEIFACE_DAY;
extern const int32_t NIXIE_NIXIEIFACE_ON;
extern const int32_t NIXIE_NIXIEIFACE_OFF;


/*! Type definition of the data structure for the NixieInternal interface scope. */
typedef struct
{
	int32_t count;
	int32_t MODE;
} NixieInternal;



/*! Type definition of the data structure for the NixieTimeEvents interface scope. */
typedef struct
{
	sc_boolean nixie_t_MODE1_Awake_Date_tev0_raised;
	sc_boolean nixie_t_MODE1_Awake_Temperature_tev0_raised;
	sc_boolean nixie_t_MODE2_Sleep_Wake_Up_tev0_raised;
	sc_boolean nixie_t_MODE2_Sleep_Date_tev0_raised;
	sc_boolean nixie_t_MODE2_Sleep_Temperature_tev0_raised;
	sc_boolean nixie_t_Alarm_Alarm_Alarm_ON__tev0_raised;
	sc_boolean nixie_t_Alarm_Alarm_Alarm_OFF__tev0_raised;
} NixieTimeEvents;




/*! 
 * Type definition of the data structure for the Nixie state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	NixieStates stateConfVector[NIXIE_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	NixieIface iface;
	NixieInternal internal;
	NixieTimeEvents timeEvents;
} Nixie;



/*! Initializes the Nixie state machine data structures. Must be called before first usage.*/
extern void nixie_init(Nixie* handle);

/*! Activates the state machine */
extern void nixie_enter(Nixie* handle);

/*! Deactivates the state machine */
extern void nixie_exit(Nixie* handle);

/*! Performs a 'run to completion' step. */
extern void nixie_runCycle(Nixie* handle);

/*! Raises a time event. */
extern void nixie_raiseTimeEvent(Nixie* handle, sc_eventid evid);

/*! Gets the value of the variable 'B_Time' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_b_Time(const Nixie* handle);
/*! Gets the value of the variable 'B_Date' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_b_Date(const Nixie* handle);
/*! Gets the value of the variable 'B_Alarm' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_b_Alarm(const Nixie* handle);
/*! Gets the value of the variable 'Time' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_time(const Nixie* handle);
/*! Gets the value of the variable 'Date' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_date(const Nixie* handle);
/*! Gets the value of the variable 'Alarm' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_alarm(const Nixie* handle);
/*! Gets the value of the variable 'Temp' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_temp(const Nixie* handle);
/*! Gets the value of the variable 'AlarmState' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_alarmState(const Nixie* handle);
/*! Gets the value of the variable 'COUNTMAX' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_cOUNTMAX(const Nixie* handle);
/*! Gets the value of the variable 'Hour' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_hour(const Nixie* handle);
/*! Gets the value of the variable 'Minute' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_minute(const Nixie* handle);
/*! Gets the value of the variable 'Seconds' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_seconds(const Nixie* handle);
/*! Gets the value of the variable 'Year' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_year(const Nixie* handle);
/*! Gets the value of the variable 'Month' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_month(const Nixie* handle);
/*! Gets the value of the variable 'Day' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_day(const Nixie* handle);
/*! Gets the value of the variable 'On' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_on(const Nixie* handle);
/*! Gets the value of the variable 'Off' that is defined in the default interface scope. */ 
extern int32_t nixieIface_get_off(const Nixie* handle);
/*! Raises the in event 'S_SENSOR' that is defined in the default interface scope. */ 
extern void nixieIface_raise_s_SENSOR(Nixie* handle);

/*! Raises the in event 'B_1' that is defined in the default interface scope. */ 
extern void nixieIface_raise_b_1(Nixie* handle);

/*! Raises the in event 'B_2' that is defined in the default interface scope. */ 
extern void nixieIface_raise_b_2(Nixie* handle);

/*! Raises the in event 'B_3' that is defined in the default interface scope. */ 
extern void nixieIface_raise_b_3(Nixie* handle);

/*! Raises the in event 'E_ALARM' that is defined in the default interface scope. */ 
extern void nixieIface_raise_e_ALARM(Nixie* handle);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean nixie_isActive(const Nixie* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean nixie_isFinal(const Nixie* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean nixie_isStateActive(const Nixie* handle, NixieStates state);


#ifdef __cplusplus
}
#endif 

#endif /* NIXIE_H_ */
