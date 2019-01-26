
#include "Nixie.h"
#include "..\src\sc_types.h"
#include "NixieRequired.h"

/*! \file Implementation of the state machine 'nixie'
*/

/* prototypes of all internal functions */
static sc_boolean check_t__choice_0_tr0_tr0(const Nixie* handle);
static sc_boolean check_t__choice_0_tr2_tr2(const Nixie* handle);
static void effect_t__choice_0_tr0(Nixie* handle);
static void effect_t__choice_0_tr2(Nixie* handle);
static void effect_t__choice_0_tr1(Nixie* handle);
static void enact_t_START(Nixie* handle);
static void enact_t_START_Configuration_Config(Nixie* handle);
static void enact_t_MODE1(Nixie* handle);
static void enact_t_MODE1_Awake_Date(Nixie* handle);
static void enact_t_MODE1_Awake_Temperature(Nixie* handle);
static void enact_t_MODE2(Nixie* handle);
static void enact_t_MODE2_Sleep_Wake_Up(Nixie* handle);
static void enact_t_MODE2_Sleep_Sleep(Nixie* handle);
static void enact_t_MODE2_Sleep_Date(Nixie* handle);
static void enact_t_MODE2_Sleep_Temperature(Nixie* handle);
static void enact_t_MODE3(Nixie* handle);
static void enact_t_Alarm(Nixie* handle);
static void enact_t_Alarm_Alarm_Alarm_ON_(Nixie* handle);
static void enact_t_Alarm_Alarm_Alarm_OFF_(Nixie* handle);
static void exact_t_START(Nixie* handle);
static void exact_t_MODE1_Awake_Date(Nixie* handle);
static void exact_t_MODE1_Awake_Temperature(Nixie* handle);
static void exact_t_MODE2(Nixie* handle);
static void exact_t_MODE2_Sleep_Wake_Up(Nixie* handle);
static void exact_t_MODE2_Sleep_Date(Nixie* handle);
static void exact_t_MODE2_Sleep_Temperature(Nixie* handle);
static void exact_t_MODE3(Nixie* handle);
static void exact_t_Alarm(Nixie* handle);
static void exact_t_Alarm_Alarm_Alarm_ON_(Nixie* handle);
static void exact_t_Alarm_Alarm_Alarm_OFF_(Nixie* handle);
static void enseq_t_START_default(Nixie* handle);
static void enseq_t_START_Configuration_Config_default(Nixie* handle);
static void enseq_t_START_Configuration_Hour_default(Nixie* handle);
static void enseq_t_START_Configuration_Minutes_default(Nixie* handle);
static void enseq_t_START_Configuration_Year_default(Nixie* handle);
static void enseq_t_START_Configuration_Month_default(Nixie* handle);
static void enseq_t_START_Configuration_Day_default(Nixie* handle);
static void enseq_t_MODE1_default(Nixie* handle);
static void enseq_t_MODE1_Awake_Awake_default(Nixie* handle);
static void enseq_t_MODE1_Awake_Date_default(Nixie* handle);
static void enseq_t_MODE1_Awake_Temperature_default(Nixie* handle);
static void enseq_t_MODE2_default(Nixie* handle);
static void enseq_t_MODE2_Sleep_Wake_Up_default(Nixie* handle);
static void enseq_t_MODE2_Sleep_Sleep_default(Nixie* handle);
static void enseq_t_MODE2_Sleep_Date_default(Nixie* handle);
static void enseq_t_MODE2_Sleep_Temperature_default(Nixie* handle);
static void enseq_t_MODE3_default(Nixie* handle);
static void enseq_t_MODE3_Alarm_AlarmConfig_default(Nixie* handle);
static void enseq_t_MODE3_Alarm_Hour_default(Nixie* handle);
static void enseq_t_MODE3_Alarm_Minute_default(Nixie* handle);
static void enseq_t_Alarm_default(Nixie* handle);
static void enseq_t_Alarm_Alarm_Alarm_ON__default(Nixie* handle);
static void enseq_t_Alarm_Alarm_Alarm_OFF__default(Nixie* handle);
static void enseq_t_default(Nixie* handle);
static void enseq_t_START_Configuration_default(Nixie* handle);
static void enseq_t_MODE1_Awake_default(Nixie* handle);
static void enseq_t_MODE2_Sleep_default(Nixie* handle);
static void enseq_t_MODE3_Alarm_default(Nixie* handle);
static void enseq_t_Alarm_Alarm_default(Nixie* handle);
static void exseq_t_START(Nixie* handle);
static void exseq_t_START_Configuration_Config(Nixie* handle);
static void exseq_t_START_Configuration_Hour(Nixie* handle);
static void exseq_t_START_Configuration_Minutes(Nixie* handle);
static void exseq_t_START_Configuration_Year(Nixie* handle);
static void exseq_t_START_Configuration_Month(Nixie* handle);
static void exseq_t_START_Configuration_Day(Nixie* handle);
static void exseq_t_MODE1(Nixie* handle);
static void exseq_t_MODE1_Awake_Awake(Nixie* handle);
static void exseq_t_MODE1_Awake_Date(Nixie* handle);
static void exseq_t_MODE1_Awake_Temperature(Nixie* handle);
static void exseq_t_MODE2(Nixie* handle);
static void exseq_t_MODE2_Sleep_Wake_Up(Nixie* handle);
static void exseq_t_MODE2_Sleep_Sleep(Nixie* handle);
static void exseq_t_MODE2_Sleep_Date(Nixie* handle);
static void exseq_t_MODE2_Sleep_Temperature(Nixie* handle);
static void exseq_t_MODE3(Nixie* handle);
static void exseq_t_MODE3_Alarm_AlarmConfig(Nixie* handle);
static void exseq_t_MODE3_Alarm_Hour(Nixie* handle);
static void exseq_t_MODE3_Alarm_Minute(Nixie* handle);
static void exseq_t_Alarm(Nixie* handle);
static void exseq_t_Alarm_Alarm_Alarm_ON_(Nixie* handle);
static void exseq_t_Alarm_Alarm_Alarm_OFF_(Nixie* handle);
static void exseq_t(Nixie* handle);
static void exseq_t_START_Configuration(Nixie* handle);
static void exseq_t_MODE1_Awake(Nixie* handle);
static void exseq_t_MODE2_Sleep(Nixie* handle);
static void exseq_t_MODE3_Alarm(Nixie* handle);
static void exseq_t_Alarm_Alarm(Nixie* handle);
static void react_t__choice_0(Nixie* handle);
static void react_nixie_t__entry_Default(Nixie* handle);
static void react_nixie_t_START_Configuration__entry_Default(Nixie* handle);
static void react_nixie_t_MODE1_Awake__entry_Default(Nixie* handle);
static void react_nixie_t_MODE2_Sleep__entry_Default(Nixie* handle);
static void react_nixie_t_MODE3_Alarm__entry_Default(Nixie* handle);
static void react_nixie_t_Alarm_Alarm__entry_Default(Nixie* handle);
static sc_boolean react(Nixie* handle);
static sc_boolean t_START_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_START_Configuration_Config_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_START_Configuration_Hour_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_START_Configuration_Minutes_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_START_Configuration_Year_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_START_Configuration_Month_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_START_Configuration_Day_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE1_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE1_Awake_Awake_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE1_Awake_Date_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE1_Awake_Temperature_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE2_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE2_Sleep_Wake_Up_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE2_Sleep_Sleep_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE2_Sleep_Date_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE2_Sleep_Temperature_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE3_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE3_Alarm_AlarmConfig_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE3_Alarm_Hour_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_MODE3_Alarm_Minute_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_Alarm_react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_Alarm_Alarm_Alarm_ON__react(Nixie* handle, const sc_boolean try_transition);
static sc_boolean t_Alarm_Alarm_Alarm_OFF__react(Nixie* handle, const sc_boolean try_transition);
static void clearInEvents(Nixie* handle);
static void clearOutEvents(Nixie* handle);

const int32_t NIXIE_NIXIEIFACE_B_TIME = 4;
const int32_t NIXIE_NIXIEIFACE_B_DATE = 5;
const int32_t NIXIE_NIXIEIFACE_B_ALARM = 6;
const int32_t NIXIE_NIXIEIFACE_TIME = 0;
const int32_t NIXIE_NIXIEIFACE_DATE = 1;
const int32_t NIXIE_NIXIEIFACE_ALARM = 2;
const int32_t NIXIE_NIXIEIFACE_TEMP = 3;
const int32_t NIXIE_NIXIEIFACE_ALARMSTATE = 4;
const int32_t NIXIE_NIXIEIFACE_COUNTMAX = 3;
const int32_t NIXIE_NIXIEIFACE_HOUR = 0;
const int32_t NIXIE_NIXIEIFACE_MINUTE = 1;
const int32_t NIXIE_NIXIEIFACE_SECONDS = 2;
const int32_t NIXIE_NIXIEIFACE_YEAR = 0;
const int32_t NIXIE_NIXIEIFACE_MONTH = 1;
const int32_t NIXIE_NIXIEIFACE_DAY = 2;
const int32_t NIXIE_NIXIEIFACE_ON = 1;
const int32_t NIXIE_NIXIEIFACE_OFF = 0;

void nixie_init(Nixie* handle)
{
	sc_integer i;
	
	for (i = 0; i < NIXIE_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Nixie_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;
	
	clearInEvents(handle);
	clearOutEvents(handle);
	
	/* Default init sequence for statechart nixie */
	handle->internal.count = 0;
	handle->internal.MODE = 0;
}

void nixie_enter(Nixie* handle)
{
	/* Default enter sequence for statechart nixie */
	enseq_t_default(handle);
}

void nixie_runCycle(Nixie* handle)
{
	clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < NIXIE_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Nixie_t_START_Configuration_Config:
		{
			t_START_Configuration_Config_react(handle, bool_true);
			break;
		}
		case Nixie_t_START_Configuration_Hour:
		{
			t_START_Configuration_Hour_react(handle, bool_true);
			break;
		}
		case Nixie_t_START_Configuration_Minutes:
		{
			t_START_Configuration_Minutes_react(handle, bool_true);
			break;
		}
		case Nixie_t_START_Configuration_Year:
		{
			t_START_Configuration_Year_react(handle, bool_true);
			break;
		}
		case Nixie_t_START_Configuration_Month:
		{
			t_START_Configuration_Month_react(handle, bool_true);
			break;
		}
		case Nixie_t_START_Configuration_Day:
		{
			t_START_Configuration_Day_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE1_Awake_Awake:
		{
			t_MODE1_Awake_Awake_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE1_Awake_Date:
		{
			t_MODE1_Awake_Date_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE1_Awake_Temperature:
		{
			t_MODE1_Awake_Temperature_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE2_Sleep_Wake_Up:
		{
			t_MODE2_Sleep_Wake_Up_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE2_Sleep_Sleep:
		{
			t_MODE2_Sleep_Sleep_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE2_Sleep_Date:
		{
			t_MODE2_Sleep_Date_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE2_Sleep_Temperature:
		{
			t_MODE2_Sleep_Temperature_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE3_Alarm_AlarmConfig:
		{
			t_MODE3_Alarm_AlarmConfig_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE3_Alarm_Hour:
		{
			t_MODE3_Alarm_Hour_react(handle, bool_true);
			break;
		}
		case Nixie_t_MODE3_Alarm_Minute:
		{
			t_MODE3_Alarm_Minute_react(handle, bool_true);
			break;
		}
		case Nixie_t_Alarm_Alarm_Alarm_ON_:
		{
			t_Alarm_Alarm_Alarm_ON__react(handle, bool_true);
			break;
		}
		case Nixie_t_Alarm_Alarm_Alarm_OFF_:
		{
			t_Alarm_Alarm_Alarm_OFF__react(handle, bool_true);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void nixie_exit(Nixie* handle)
{
	/* Default exit sequence for statechart nixie */
	exseq_t(handle);
}

sc_boolean nixie_isActive(const Nixie* handle)
{
	sc_boolean result = bool_false;
	sc_integer i;
	
	for(i = 0; i < NIXIE_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Nixie_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean nixie_isFinal(const Nixie* handle)
{
   return bool_false;
}

void nixie_raiseTimeEvent(Nixie* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + (unsigned)sizeof(NixieTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean nixie_isStateActive(const Nixie* handle, NixieStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Nixie_t_START :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_START] >= Nixie_t_START
				&& handle->stateConfVector[SCVI_NIXIE_T_START] <= Nixie_t_START_Configuration_Day);
			break;
		case Nixie_t_START_Configuration_Config :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_START_CONFIGURATION_CONFIG] == Nixie_t_START_Configuration_Config
			);
			break;
		case Nixie_t_START_Configuration_Hour :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_START_CONFIGURATION_HOUR] == Nixie_t_START_Configuration_Hour
			);
			break;
		case Nixie_t_START_Configuration_Minutes :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_START_CONFIGURATION_MINUTES] == Nixie_t_START_Configuration_Minutes
			);
			break;
		case Nixie_t_START_Configuration_Year :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_START_CONFIGURATION_YEAR] == Nixie_t_START_Configuration_Year
			);
			break;
		case Nixie_t_START_Configuration_Month :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_START_CONFIGURATION_MONTH] == Nixie_t_START_Configuration_Month
			);
			break;
		case Nixie_t_START_Configuration_Day :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_START_CONFIGURATION_DAY] == Nixie_t_START_Configuration_Day
			);
			break;
		case Nixie_t_MODE1 :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE1] >= Nixie_t_MODE1
				&& handle->stateConfVector[SCVI_NIXIE_T_MODE1] <= Nixie_t_MODE1_Awake_Temperature);
			break;
		case Nixie_t_MODE1_Awake_Awake :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE1_AWAKE_AWAKE] == Nixie_t_MODE1_Awake_Awake
			);
			break;
		case Nixie_t_MODE1_Awake_Date :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE1_AWAKE_DATE] == Nixie_t_MODE1_Awake_Date
			);
			break;
		case Nixie_t_MODE1_Awake_Temperature :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE1_AWAKE_TEMPERATURE] == Nixie_t_MODE1_Awake_Temperature
			);
			break;
		case Nixie_t_MODE2 :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE2] >= Nixie_t_MODE2
				&& handle->stateConfVector[SCVI_NIXIE_T_MODE2] <= Nixie_t_MODE2_Sleep_Temperature);
			break;
		case Nixie_t_MODE2_Sleep_Wake_Up :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE2_SLEEP_WAKE_UP] == Nixie_t_MODE2_Sleep_Wake_Up
			);
			break;
		case Nixie_t_MODE2_Sleep_Sleep :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE2_SLEEP_SLEEP] == Nixie_t_MODE2_Sleep_Sleep
			);
			break;
		case Nixie_t_MODE2_Sleep_Date :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE2_SLEEP_DATE] == Nixie_t_MODE2_Sleep_Date
			);
			break;
		case Nixie_t_MODE2_Sleep_Temperature :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE2_SLEEP_TEMPERATURE] == Nixie_t_MODE2_Sleep_Temperature
			);
			break;
		case Nixie_t_MODE3 :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE3] >= Nixie_t_MODE3
				&& handle->stateConfVector[SCVI_NIXIE_T_MODE3] <= Nixie_t_MODE3_Alarm_Minute);
			break;
		case Nixie_t_MODE3_Alarm_AlarmConfig :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE3_ALARM_ALARMCONFIG] == Nixie_t_MODE3_Alarm_AlarmConfig
			);
			break;
		case Nixie_t_MODE3_Alarm_Hour :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE3_ALARM_HOUR] == Nixie_t_MODE3_Alarm_Hour
			);
			break;
		case Nixie_t_MODE3_Alarm_Minute :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_MODE3_ALARM_MINUTE] == Nixie_t_MODE3_Alarm_Minute
			);
			break;
		case Nixie_t_Alarm :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_ALARM] >= Nixie_t_Alarm
				&& handle->stateConfVector[SCVI_NIXIE_T_ALARM] <= Nixie_t_Alarm_Alarm_Alarm_OFF_);
			break;
		case Nixie_t_Alarm_Alarm_Alarm_ON_ :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_ALARM_ALARM_ALARM_ON_] == Nixie_t_Alarm_Alarm_Alarm_ON_
			);
			break;
		case Nixie_t_Alarm_Alarm_Alarm_OFF_ :
			result = (sc_boolean) (handle->stateConfVector[SCVI_NIXIE_T_ALARM_ALARM_ALARM_OFF_] == Nixie_t_Alarm_Alarm_Alarm_OFF_
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clearInEvents(Nixie* handle)
{
	handle->iface.S_SENSOR_raised = bool_false;
	handle->iface.B_1_raised = bool_false;
	handle->iface.B_2_raised = bool_false;
	handle->iface.B_3_raised = bool_false;
	handle->iface.E_ALARM_raised = bool_false;
	handle->timeEvents.nixie_t_MODE1_Awake_Date_tev0_raised = bool_false;
	handle->timeEvents.nixie_t_MODE1_Awake_Temperature_tev0_raised = bool_false;
	handle->timeEvents.nixie_t_MODE2_Sleep_Wake_Up_tev0_raised = bool_false;
	handle->timeEvents.nixie_t_MODE2_Sleep_Date_tev0_raised = bool_false;
	handle->timeEvents.nixie_t_MODE2_Sleep_Temperature_tev0_raised = bool_false;
	handle->timeEvents.nixie_t_Alarm_Alarm_Alarm_ON__tev0_raised = bool_false;
	handle->timeEvents.nixie_t_Alarm_Alarm_Alarm_OFF__tev0_raised = bool_false;
}

static void clearOutEvents(Nixie* handle)
{
}

void nixieIface_raise_s_SENSOR(Nixie* handle)
{
	handle->iface.S_SENSOR_raised = bool_true;
}
void nixieIface_raise_b_1(Nixie* handle)
{
	handle->iface.B_1_raised = bool_true;
}
void nixieIface_raise_b_2(Nixie* handle)
{
	handle->iface.B_2_raised = bool_true;
}
void nixieIface_raise_b_3(Nixie* handle)
{
	handle->iface.B_3_raised = bool_true;
}
void nixieIface_raise_e_ALARM(Nixie* handle)
{
	handle->iface.E_ALARM_raised = bool_true;
}


int32_t nixieIface_get_b_Time(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_B_TIME;
}
int32_t nixieIface_get_b_Date(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_B_DATE;
}
int32_t nixieIface_get_b_Alarm(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_B_ALARM;
}
int32_t nixieIface_get_time(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_TIME;
}
int32_t nixieIface_get_date(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_DATE;
}
int32_t nixieIface_get_alarm(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_ALARM;
}
int32_t nixieIface_get_temp(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_TEMP;
}
int32_t nixieIface_get_alarmState(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_ALARMSTATE;
}
int32_t nixieIface_get_cOUNTMAX(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_COUNTMAX;
}
int32_t nixieIface_get_hour(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_HOUR;
}
int32_t nixieIface_get_minute(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_MINUTE;
}
int32_t nixieIface_get_seconds(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_SECONDS;
}
int32_t nixieIface_get_year(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_YEAR;
}
int32_t nixieIface_get_month(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_MONTH;
}
int32_t nixieIface_get_day(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_DAY;
}
int32_t nixieIface_get_on(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_ON;
}
int32_t nixieIface_get_off(const Nixie* handle)
{
	return NIXIE_NIXIEIFACE_OFF;
}

/* implementations of all internal functions */

static sc_boolean check_t__choice_0_tr0_tr0(const Nixie* handle)
{
	return (handle->internal.MODE) == (2);
}

static sc_boolean check_t__choice_0_tr2_tr2(const Nixie* handle)
{
	return (handle->internal.MODE) == (3);
}

static void effect_t__choice_0_tr0(Nixie* handle)
{
	enseq_t_MODE2_default(handle);
}

static void effect_t__choice_0_tr2(Nixie* handle)
{
	enseq_t_MODE3_default(handle);
}

static void effect_t__choice_0_tr1(Nixie* handle)
{
	enseq_t_MODE1_default(handle);
}

/* Entry action for state 'START'. */
static void enact_t_START(Nixie* handle)
{
	/* Entry action for state 'START'. */
	nixieIface_init(handle);
}

/* Entry action for state 'Config'. */
static void enact_t_START_Configuration_Config(Nixie* handle)
{
	/* Entry action for state 'Config'. */
	nixieIface_show(handle, NIXIE_NIXIEIFACE_TIME);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_TIME);
}

/* Entry action for state 'MODE1'. */
static void enact_t_MODE1(Nixie* handle)
{
	/* Entry action for state 'MODE1'. */
	nixieIface_show(handle, NIXIE_NIXIEIFACE_TIME);
	handle->internal.MODE = 1;
	nixieIface_nixiePower(handle, NIXIE_NIXIEIFACE_ON);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_TIME);
}

/* Entry action for state 'Date'. */
static void enact_t_MODE1_Awake_Date(Nixie* handle)
{
	/* Entry action for state 'Date'. */
	nixie_setTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE1_Awake_Date_tev0_raised) , (10 * 1000), bool_false);
	nixieIface_show(handle, NIXIE_NIXIEIFACE_DATE);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_DATE);
}

/* Entry action for state 'Temperature'. */
static void enact_t_MODE1_Awake_Temperature(Nixie* handle)
{
	/* Entry action for state 'Temperature'. */
	nixie_setTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE1_Awake_Temperature_tev0_raised) , (10 * 1000), bool_false);
	nixieIface_show(handle, NIXIE_NIXIEIFACE_TEMP);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_TEMP);
}

/* Entry action for state 'MODE2'. */
static void enact_t_MODE2(Nixie* handle)
{
	/* Entry action for state 'MODE2'. */
	handle->internal.MODE = 2;
}

/* Entry action for state 'Wake Up'. */
static void enact_t_MODE2_Sleep_Wake_Up(Nixie* handle)
{
	/* Entry action for state 'Wake Up'. */
	nixie_setTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE2_Sleep_Wake_Up_tev0_raised) , (60 * 1000), bool_false);
	nixieIface_show(handle, NIXIE_NIXIEIFACE_TIME);
	nixieIface_ledPower(handle, NIXIE_NIXIEIFACE_ON);
	nixieIface_nixiePower(handle, NIXIE_NIXIEIFACE_ON);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_TIME);
}

/* Entry action for state 'Sleep'. */
static void enact_t_MODE2_Sleep_Sleep(Nixie* handle)
{
	/* Entry action for state 'Sleep'. */
	nixieIface_ledPower(handle, NIXIE_NIXIEIFACE_OFF);
	nixieIface_nixiePower(handle, NIXIE_NIXIEIFACE_OFF);
}

/* Entry action for state 'Date'. */
static void enact_t_MODE2_Sleep_Date(Nixie* handle)
{
	/* Entry action for state 'Date'. */
	nixie_setTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE2_Sleep_Date_tev0_raised) , (10 * 1000), bool_false);
	nixieIface_show(handle, NIXIE_NIXIEIFACE_DATE);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_DATE);
}

/* Entry action for state 'Temperature'. */
static void enact_t_MODE2_Sleep_Temperature(Nixie* handle)
{
	/* Entry action for state 'Temperature'. */
	nixie_setTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE2_Sleep_Temperature_tev0_raised) , (10 * 1000), bool_false);
	nixieIface_show(handle, NIXIE_NIXIEIFACE_TEMP);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_TEMP);
}

/* Entry action for state 'MODE3'. */
static void enact_t_MODE3(Nixie* handle)
{
	/* Entry action for state 'MODE3'. */
	handle->internal.MODE = 3;
	nixieIface_show(handle, NIXIE_NIXIEIFACE_ALARM);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_ALARMSTATE);
	nixieIface_nixiePower(handle, NIXIE_NIXIEIFACE_ON);
}

/* Entry action for state 'Alarm'. */
static void enact_t_Alarm(Nixie* handle)
{
	/* Entry action for state 'Alarm'. */
	nixieIface_show(handle, NIXIE_NIXIEIFACE_TIME);
	nixieIface_alarmFlag(handle);
	nixieIface_nixiePower(handle, NIXIE_NIXIEIFACE_ON);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_ALARM);
}

/* Entry action for state 'Alarm[ON]'. */
static void enact_t_Alarm_Alarm_Alarm_ON_(Nixie* handle)
{
	/* Entry action for state 'Alarm[ON]'. */
	nixie_setTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_Alarm_Alarm_Alarm_ON__tev0_raised) , (300 * 1000), bool_false);
	nixieIface_buzzer(handle, NIXIE_NIXIEIFACE_ON);
}

/* Entry action for state 'Alarm[OFF]'. */
static void enact_t_Alarm_Alarm_Alarm_OFF_(Nixie* handle)
{
	/* Entry action for state 'Alarm[OFF]'. */
	nixie_setTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_Alarm_Alarm_Alarm_OFF__tev0_raised) , (600 * 1000), bool_false);
	nixieIface_buzzer(handle, NIXIE_NIXIEIFACE_OFF);
	handle->internal.count++;
}

/* Exit action for state 'START'. */
static void exact_t_START(Nixie* handle)
{
	/* Exit action for state 'START'. */
	nixieIface_resetVar(handle);
}

/* Exit action for state 'Date'. */
static void exact_t_MODE1_Awake_Date(Nixie* handle)
{
	/* Exit action for state 'Date'. */
	nixie_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE1_Awake_Date_tev0_raised) );		
}

/* Exit action for state 'Temperature'. */
static void exact_t_MODE1_Awake_Temperature(Nixie* handle)
{
	/* Exit action for state 'Temperature'. */
	nixie_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE1_Awake_Temperature_tev0_raised) );		
	nixieIface_show(handle, NIXIE_NIXIEIFACE_TIME);
	nixieIface_showLed(handle, NIXIE_NIXIEIFACE_TIME);
}

/* Exit action for state 'MODE2'. */
static void exact_t_MODE2(Nixie* handle)
{
	/* Exit action for state 'MODE2'. */
	nixieIface_ledPower(handle, NIXIE_NIXIEIFACE_ON);
}

/* Exit action for state 'Wake Up'. */
static void exact_t_MODE2_Sleep_Wake_Up(Nixie* handle)
{
	/* Exit action for state 'Wake Up'. */
	nixie_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE2_Sleep_Wake_Up_tev0_raised) );		
}

/* Exit action for state 'Date'. */
static void exact_t_MODE2_Sleep_Date(Nixie* handle)
{
	/* Exit action for state 'Date'. */
	nixie_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE2_Sleep_Date_tev0_raised) );		
}

/* Exit action for state 'Temperature'. */
static void exact_t_MODE2_Sleep_Temperature(Nixie* handle)
{
	/* Exit action for state 'Temperature'. */
	nixie_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_MODE2_Sleep_Temperature_tev0_raised) );		
}

/* Exit action for state 'MODE3'. */
static void exact_t_MODE3(Nixie* handle)
{
	/* Exit action for state 'MODE3'. */
	nixieIface_resetVar(handle);
}

/* Exit action for state 'Alarm'. */
static void exact_t_Alarm(Nixie* handle)
{
	/* Exit action for state 'Alarm'. */
	handle->internal.count = 0;
	nixieIface_buzzer(handle, NIXIE_NIXIEIFACE_OFF);
}

/* Exit action for state 'Alarm[ON]'. */
static void exact_t_Alarm_Alarm_Alarm_ON_(Nixie* handle)
{
	/* Exit action for state 'Alarm[ON]'. */
	nixie_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_Alarm_Alarm_Alarm_ON__tev0_raised) );		
}

/* Exit action for state 'Alarm[OFF]'. */
static void exact_t_Alarm_Alarm_Alarm_OFF_(Nixie* handle)
{
	/* Exit action for state 'Alarm[OFF]'. */
	nixie_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.nixie_t_Alarm_Alarm_Alarm_OFF__tev0_raised) );		
}

/* 'default' enter sequence for state START */
static void enseq_t_START_default(Nixie* handle)
{
	/* 'default' enter sequence for state START */
	enact_t_START(handle);
	enseq_t_START_Configuration_default(handle);
}

/* 'default' enter sequence for state Config */
static void enseq_t_START_Configuration_Config_default(Nixie* handle)
{
	/* 'default' enter sequence for state Config */
	enact_t_START_Configuration_Config(handle);
	handle->stateConfVector[0] = Nixie_t_START_Configuration_Config;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Hour */
static void enseq_t_START_Configuration_Hour_default(Nixie* handle)
{
	/* 'default' enter sequence for state Hour */
	handle->stateConfVector[0] = Nixie_t_START_Configuration_Hour;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Minutes */
static void enseq_t_START_Configuration_Minutes_default(Nixie* handle)
{
	/* 'default' enter sequence for state Minutes */
	handle->stateConfVector[0] = Nixie_t_START_Configuration_Minutes;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Year */
static void enseq_t_START_Configuration_Year_default(Nixie* handle)
{
	/* 'default' enter sequence for state Year */
	handle->stateConfVector[0] = Nixie_t_START_Configuration_Year;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Month */
static void enseq_t_START_Configuration_Month_default(Nixie* handle)
{
	/* 'default' enter sequence for state Month */
	handle->stateConfVector[0] = Nixie_t_START_Configuration_Month;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Day */
static void enseq_t_START_Configuration_Day_default(Nixie* handle)
{
	/* 'default' enter sequence for state Day */
	handle->stateConfVector[0] = Nixie_t_START_Configuration_Day;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state MODE1 */
static void enseq_t_MODE1_default(Nixie* handle)
{
	/* 'default' enter sequence for state MODE1 */
	enact_t_MODE1(handle);
	enseq_t_MODE1_Awake_default(handle);
}

/* 'default' enter sequence for state Awake */
static void enseq_t_MODE1_Awake_Awake_default(Nixie* handle)
{
	/* 'default' enter sequence for state Awake */
	handle->stateConfVector[0] = Nixie_t_MODE1_Awake_Awake;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Date */
static void enseq_t_MODE1_Awake_Date_default(Nixie* handle)
{
	/* 'default' enter sequence for state Date */
	enact_t_MODE1_Awake_Date(handle);
	handle->stateConfVector[0] = Nixie_t_MODE1_Awake_Date;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Temperature */
static void enseq_t_MODE1_Awake_Temperature_default(Nixie* handle)
{
	/* 'default' enter sequence for state Temperature */
	enact_t_MODE1_Awake_Temperature(handle);
	handle->stateConfVector[0] = Nixie_t_MODE1_Awake_Temperature;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state MODE2 */
static void enseq_t_MODE2_default(Nixie* handle)
{
	/* 'default' enter sequence for state MODE2 */
	enact_t_MODE2(handle);
	enseq_t_MODE2_Sleep_default(handle);
}

/* 'default' enter sequence for state Wake Up */
static void enseq_t_MODE2_Sleep_Wake_Up_default(Nixie* handle)
{
	/* 'default' enter sequence for state Wake Up */
	enact_t_MODE2_Sleep_Wake_Up(handle);
	handle->stateConfVector[0] = Nixie_t_MODE2_Sleep_Wake_Up;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Sleep */
static void enseq_t_MODE2_Sleep_Sleep_default(Nixie* handle)
{
	/* 'default' enter sequence for state Sleep */
	enact_t_MODE2_Sleep_Sleep(handle);
	handle->stateConfVector[0] = Nixie_t_MODE2_Sleep_Sleep;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Date */
static void enseq_t_MODE2_Sleep_Date_default(Nixie* handle)
{
	/* 'default' enter sequence for state Date */
	enact_t_MODE2_Sleep_Date(handle);
	handle->stateConfVector[0] = Nixie_t_MODE2_Sleep_Date;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Temperature */
static void enseq_t_MODE2_Sleep_Temperature_default(Nixie* handle)
{
	/* 'default' enter sequence for state Temperature */
	enact_t_MODE2_Sleep_Temperature(handle);
	handle->stateConfVector[0] = Nixie_t_MODE2_Sleep_Temperature;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state MODE3 */
static void enseq_t_MODE3_default(Nixie* handle)
{
	/* 'default' enter sequence for state MODE3 */
	enact_t_MODE3(handle);
	enseq_t_MODE3_Alarm_default(handle);
}

/* 'default' enter sequence for state AlarmConfig */
static void enseq_t_MODE3_Alarm_AlarmConfig_default(Nixie* handle)
{
	/* 'default' enter sequence for state AlarmConfig */
	handle->stateConfVector[0] = Nixie_t_MODE3_Alarm_AlarmConfig;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Hour */
static void enseq_t_MODE3_Alarm_Hour_default(Nixie* handle)
{
	/* 'default' enter sequence for state Hour */
	handle->stateConfVector[0] = Nixie_t_MODE3_Alarm_Hour;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Minute */
static void enseq_t_MODE3_Alarm_Minute_default(Nixie* handle)
{
	/* 'default' enter sequence for state Minute */
	handle->stateConfVector[0] = Nixie_t_MODE3_Alarm_Minute;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Alarm */
static void enseq_t_Alarm_default(Nixie* handle)
{
	/* 'default' enter sequence for state Alarm */
	enact_t_Alarm(handle);
	enseq_t_Alarm_Alarm_default(handle);
}

/* 'default' enter sequence for state Alarm[ON] */
static void enseq_t_Alarm_Alarm_Alarm_ON__default(Nixie* handle)
{
	/* 'default' enter sequence for state Alarm[ON] */
	enact_t_Alarm_Alarm_Alarm_ON_(handle);
	handle->stateConfVector[0] = Nixie_t_Alarm_Alarm_Alarm_ON_;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Alarm[OFF] */
static void enseq_t_Alarm_Alarm_Alarm_OFF__default(Nixie* handle)
{
	/* 'default' enter sequence for state Alarm[OFF] */
	enact_t_Alarm_Alarm_Alarm_OFF_(handle);
	handle->stateConfVector[0] = Nixie_t_Alarm_Alarm_Alarm_OFF_;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region t */
static void enseq_t_default(Nixie* handle)
{
	/* 'default' enter sequence for region t */
	react_nixie_t__entry_Default(handle);
}

/* 'default' enter sequence for region Configuration */
static void enseq_t_START_Configuration_default(Nixie* handle)
{
	/* 'default' enter sequence for region Configuration */
	react_nixie_t_START_Configuration__entry_Default(handle);
}

/* 'default' enter sequence for region Awake */
static void enseq_t_MODE1_Awake_default(Nixie* handle)
{
	/* 'default' enter sequence for region Awake */
	react_nixie_t_MODE1_Awake__entry_Default(handle);
}

/* 'default' enter sequence for region Sleep */
static void enseq_t_MODE2_Sleep_default(Nixie* handle)
{
	/* 'default' enter sequence for region Sleep */
	react_nixie_t_MODE2_Sleep__entry_Default(handle);
}

/* 'default' enter sequence for region Alarm */
static void enseq_t_MODE3_Alarm_default(Nixie* handle)
{
	/* 'default' enter sequence for region Alarm */
	react_nixie_t_MODE3_Alarm__entry_Default(handle);
}

/* 'default' enter sequence for region Alarm */
static void enseq_t_Alarm_Alarm_default(Nixie* handle)
{
	/* 'default' enter sequence for region Alarm */
	react_nixie_t_Alarm_Alarm__entry_Default(handle);
}

/* Default exit sequence for state START */
static void exseq_t_START(Nixie* handle)
{
	/* Default exit sequence for state START */
	exseq_t_START_Configuration(handle);
	exact_t_START(handle);
}

/* Default exit sequence for state Config */
static void exseq_t_START_Configuration_Config(Nixie* handle)
{
	/* Default exit sequence for state Config */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Hour */
static void exseq_t_START_Configuration_Hour(Nixie* handle)
{
	/* Default exit sequence for state Hour */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Minutes */
static void exseq_t_START_Configuration_Minutes(Nixie* handle)
{
	/* Default exit sequence for state Minutes */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Year */
static void exseq_t_START_Configuration_Year(Nixie* handle)
{
	/* Default exit sequence for state Year */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Month */
static void exseq_t_START_Configuration_Month(Nixie* handle)
{
	/* Default exit sequence for state Month */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Day */
static void exseq_t_START_Configuration_Day(Nixie* handle)
{
	/* Default exit sequence for state Day */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state MODE1 */
static void exseq_t_MODE1(Nixie* handle)
{
	/* Default exit sequence for state MODE1 */
	exseq_t_MODE1_Awake(handle);
}

/* Default exit sequence for state Awake */
static void exseq_t_MODE1_Awake_Awake(Nixie* handle)
{
	/* Default exit sequence for state Awake */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Date */
static void exseq_t_MODE1_Awake_Date(Nixie* handle)
{
	/* Default exit sequence for state Date */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
	exact_t_MODE1_Awake_Date(handle);
}

/* Default exit sequence for state Temperature */
static void exseq_t_MODE1_Awake_Temperature(Nixie* handle)
{
	/* Default exit sequence for state Temperature */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
	exact_t_MODE1_Awake_Temperature(handle);
}

/* Default exit sequence for state MODE2 */
static void exseq_t_MODE2(Nixie* handle)
{
	/* Default exit sequence for state MODE2 */
	exseq_t_MODE2_Sleep(handle);
	exact_t_MODE2(handle);
}

/* Default exit sequence for state Wake Up */
static void exseq_t_MODE2_Sleep_Wake_Up(Nixie* handle)
{
	/* Default exit sequence for state Wake Up */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
	exact_t_MODE2_Sleep_Wake_Up(handle);
}

/* Default exit sequence for state Sleep */
static void exseq_t_MODE2_Sleep_Sleep(Nixie* handle)
{
	/* Default exit sequence for state Sleep */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Date */
static void exseq_t_MODE2_Sleep_Date(Nixie* handle)
{
	/* Default exit sequence for state Date */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
	exact_t_MODE2_Sleep_Date(handle);
}

/* Default exit sequence for state Temperature */
static void exseq_t_MODE2_Sleep_Temperature(Nixie* handle)
{
	/* Default exit sequence for state Temperature */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
	exact_t_MODE2_Sleep_Temperature(handle);
}

/* Default exit sequence for state MODE3 */
static void exseq_t_MODE3(Nixie* handle)
{
	/* Default exit sequence for state MODE3 */
	exseq_t_MODE3_Alarm(handle);
	exact_t_MODE3(handle);
}

/* Default exit sequence for state AlarmConfig */
static void exseq_t_MODE3_Alarm_AlarmConfig(Nixie* handle)
{
	/* Default exit sequence for state AlarmConfig */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Hour */
static void exseq_t_MODE3_Alarm_Hour(Nixie* handle)
{
	/* Default exit sequence for state Hour */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Minute */
static void exseq_t_MODE3_Alarm_Minute(Nixie* handle)
{
	/* Default exit sequence for state Minute */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Alarm */
static void exseq_t_Alarm(Nixie* handle)
{
	/* Default exit sequence for state Alarm */
	exseq_t_Alarm_Alarm(handle);
	exact_t_Alarm(handle);
}

/* Default exit sequence for state Alarm[ON] */
static void exseq_t_Alarm_Alarm_Alarm_ON_(Nixie* handle)
{
	/* Default exit sequence for state Alarm[ON] */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
	exact_t_Alarm_Alarm_Alarm_ON_(handle);
}

/* Default exit sequence for state Alarm[OFF] */
static void exseq_t_Alarm_Alarm_Alarm_OFF_(Nixie* handle)
{
	/* Default exit sequence for state Alarm[OFF] */
	handle->stateConfVector[0] = Nixie_last_state;
	handle->stateConfVectorPosition = 0;
	exact_t_Alarm_Alarm_Alarm_OFF_(handle);
}

/* Default exit sequence for region t */
static void exseq_t(Nixie* handle)
{
	/* Default exit sequence for region t */
	/* Handle exit of all possible states (of nixie.t) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Nixie_t_START_Configuration_Config :
		{
			exseq_t_START_Configuration_Config(handle);
			exact_t_START(handle);
			break;
		}
		case Nixie_t_START_Configuration_Hour :
		{
			exseq_t_START_Configuration_Hour(handle);
			exact_t_START(handle);
			break;
		}
		case Nixie_t_START_Configuration_Minutes :
		{
			exseq_t_START_Configuration_Minutes(handle);
			exact_t_START(handle);
			break;
		}
		case Nixie_t_START_Configuration_Year :
		{
			exseq_t_START_Configuration_Year(handle);
			exact_t_START(handle);
			break;
		}
		case Nixie_t_START_Configuration_Month :
		{
			exseq_t_START_Configuration_Month(handle);
			exact_t_START(handle);
			break;
		}
		case Nixie_t_START_Configuration_Day :
		{
			exseq_t_START_Configuration_Day(handle);
			exact_t_START(handle);
			break;
		}
		case Nixie_t_MODE1_Awake_Awake :
		{
			exseq_t_MODE1_Awake_Awake(handle);
			break;
		}
		case Nixie_t_MODE1_Awake_Date :
		{
			exseq_t_MODE1_Awake_Date(handle);
			break;
		}
		case Nixie_t_MODE1_Awake_Temperature :
		{
			exseq_t_MODE1_Awake_Temperature(handle);
			break;
		}
		case Nixie_t_MODE2_Sleep_Wake_Up :
		{
			exseq_t_MODE2_Sleep_Wake_Up(handle);
			exact_t_MODE2(handle);
			break;
		}
		case Nixie_t_MODE2_Sleep_Sleep :
		{
			exseq_t_MODE2_Sleep_Sleep(handle);
			exact_t_MODE2(handle);
			break;
		}
		case Nixie_t_MODE2_Sleep_Date :
		{
			exseq_t_MODE2_Sleep_Date(handle);
			exact_t_MODE2(handle);
			break;
		}
		case Nixie_t_MODE2_Sleep_Temperature :
		{
			exseq_t_MODE2_Sleep_Temperature(handle);
			exact_t_MODE2(handle);
			break;
		}
		case Nixie_t_MODE3_Alarm_AlarmConfig :
		{
			exseq_t_MODE3_Alarm_AlarmConfig(handle);
			exact_t_MODE3(handle);
			break;
		}
		case Nixie_t_MODE3_Alarm_Hour :
		{
			exseq_t_MODE3_Alarm_Hour(handle);
			exact_t_MODE3(handle);
			break;
		}
		case Nixie_t_MODE3_Alarm_Minute :
		{
			exseq_t_MODE3_Alarm_Minute(handle);
			exact_t_MODE3(handle);
			break;
		}
		case Nixie_t_Alarm_Alarm_Alarm_ON_ :
		{
			exseq_t_Alarm_Alarm_Alarm_ON_(handle);
			exact_t_Alarm(handle);
			break;
		}
		case Nixie_t_Alarm_Alarm_Alarm_OFF_ :
		{
			exseq_t_Alarm_Alarm_Alarm_OFF_(handle);
			exact_t_Alarm(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Configuration */
static void exseq_t_START_Configuration(Nixie* handle)
{
	/* Default exit sequence for region Configuration */
	/* Handle exit of all possible states (of nixie.t.START.Configuration) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Nixie_t_START_Configuration_Config :
		{
			exseq_t_START_Configuration_Config(handle);
			break;
		}
		case Nixie_t_START_Configuration_Hour :
		{
			exseq_t_START_Configuration_Hour(handle);
			break;
		}
		case Nixie_t_START_Configuration_Minutes :
		{
			exseq_t_START_Configuration_Minutes(handle);
			break;
		}
		case Nixie_t_START_Configuration_Year :
		{
			exseq_t_START_Configuration_Year(handle);
			break;
		}
		case Nixie_t_START_Configuration_Month :
		{
			exseq_t_START_Configuration_Month(handle);
			break;
		}
		case Nixie_t_START_Configuration_Day :
		{
			exseq_t_START_Configuration_Day(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Awake */
static void exseq_t_MODE1_Awake(Nixie* handle)
{
	/* Default exit sequence for region Awake */
	/* Handle exit of all possible states (of nixie.t.MODE1.Awake) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Nixie_t_MODE1_Awake_Awake :
		{
			exseq_t_MODE1_Awake_Awake(handle);
			break;
		}
		case Nixie_t_MODE1_Awake_Date :
		{
			exseq_t_MODE1_Awake_Date(handle);
			break;
		}
		case Nixie_t_MODE1_Awake_Temperature :
		{
			exseq_t_MODE1_Awake_Temperature(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Sleep */
static void exseq_t_MODE2_Sleep(Nixie* handle)
{
	/* Default exit sequence for region Sleep */
	/* Handle exit of all possible states (of nixie.t.MODE2.Sleep) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Nixie_t_MODE2_Sleep_Wake_Up :
		{
			exseq_t_MODE2_Sleep_Wake_Up(handle);
			break;
		}
		case Nixie_t_MODE2_Sleep_Sleep :
		{
			exseq_t_MODE2_Sleep_Sleep(handle);
			break;
		}
		case Nixie_t_MODE2_Sleep_Date :
		{
			exseq_t_MODE2_Sleep_Date(handle);
			break;
		}
		case Nixie_t_MODE2_Sleep_Temperature :
		{
			exseq_t_MODE2_Sleep_Temperature(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Alarm */
static void exseq_t_MODE3_Alarm(Nixie* handle)
{
	/* Default exit sequence for region Alarm */
	/* Handle exit of all possible states (of nixie.t.MODE3.Alarm) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Nixie_t_MODE3_Alarm_AlarmConfig :
		{
			exseq_t_MODE3_Alarm_AlarmConfig(handle);
			break;
		}
		case Nixie_t_MODE3_Alarm_Hour :
		{
			exseq_t_MODE3_Alarm_Hour(handle);
			break;
		}
		case Nixie_t_MODE3_Alarm_Minute :
		{
			exseq_t_MODE3_Alarm_Minute(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Alarm */
static void exseq_t_Alarm_Alarm(Nixie* handle)
{
	/* Default exit sequence for region Alarm */
	/* Handle exit of all possible states (of nixie.t.Alarm.Alarm) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Nixie_t_Alarm_Alarm_Alarm_ON_ :
		{
			exseq_t_Alarm_Alarm_Alarm_ON_(handle);
			break;
		}
		case Nixie_t_Alarm_Alarm_Alarm_OFF_ :
		{
			exseq_t_Alarm_Alarm_Alarm_OFF_(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state null. */
static void react_t__choice_0(Nixie* handle)
{
	/* The reactions of state null. */
	if (check_t__choice_0_tr0_tr0(handle) == bool_true)
	{ 
		effect_t__choice_0_tr0(handle);
	}  else
	{
		if (check_t__choice_0_tr2_tr2(handle) == bool_true)
		{ 
			effect_t__choice_0_tr2(handle);
		}  else
		{
			effect_t__choice_0_tr1(handle);
		}
	}
}

/* Default react sequence for initial entry  */
static void react_nixie_t__entry_Default(Nixie* handle)
{
	/* Default react sequence for initial entry  */
	enseq_t_START_default(handle);
}

/* Default react sequence for initial entry  */
static void react_nixie_t_START_Configuration__entry_Default(Nixie* handle)
{
	/* Default react sequence for initial entry  */
	enseq_t_START_Configuration_Config_default(handle);
}

/* Default react sequence for initial entry  */
static void react_nixie_t_MODE1_Awake__entry_Default(Nixie* handle)
{
	/* Default react sequence for initial entry  */
	enseq_t_MODE1_Awake_Awake_default(handle);
}

/* Default react sequence for initial entry  */
static void react_nixie_t_MODE2_Sleep__entry_Default(Nixie* handle)
{
	/* Default react sequence for initial entry  */
	enseq_t_MODE2_Sleep_Sleep_default(handle);
}

/* Default react sequence for initial entry  */
static void react_nixie_t_MODE3_Alarm__entry_Default(Nixie* handle)
{
	/* Default react sequence for initial entry  */
	enseq_t_MODE3_Alarm_AlarmConfig_default(handle);
}

/* Default react sequence for initial entry  */
static void react_nixie_t_Alarm_Alarm__entry_Default(Nixie* handle)
{
	/* Default react sequence for initial entry  */
	enseq_t_Alarm_Alarm_Alarm_ON__default(handle);
}

static sc_boolean react(Nixie* handle) {
	/* State machine reactions. */
	return bool_false;
}

static sc_boolean t_START_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state START. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((react(handle)) == (bool_false))
		{ 
			if (handle->iface.B_1_raised == bool_true)
			{ 
				exseq_t_START(handle);
				enseq_t_MODE1_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_START_Configuration_Config_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Config. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_START_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.B_3_raised == bool_true)
			{ 
				exseq_t_START_Configuration_Config(handle);
				nixieIface_show(handle, NIXIE_NIXIEIFACE_B_TIME);
				enseq_t_START_Configuration_Hour_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_START_Configuration_Hour_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Hour. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_START_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.B_3_raised == bool_true)
			{ 
				exseq_t_START_Configuration_Hour(handle);
				enseq_t_START_Configuration_Minutes_default(handle);
			}  else
			{
				if (handle->iface.B_2_raised == bool_true)
				{ 
					exseq_t_START_Configuration_Hour(handle);
					nixieIface_increase(handle, NIXIE_NIXIEIFACE_B_TIME, NIXIE_NIXIEIFACE_HOUR);
					enseq_t_START_Configuration_Hour_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_START_Configuration_Minutes_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Minutes. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_START_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.B_3_raised == bool_true)
			{ 
				exseq_t_START_Configuration_Minutes(handle);
				nixieIface_send(handle, NIXIE_NIXIEIFACE_TIME);
				nixieIface_show(handle, NIXIE_NIXIEIFACE_B_DATE);
				nixieIface_showLed(handle, NIXIE_NIXIEIFACE_B_DATE);
				enseq_t_START_Configuration_Year_default(handle);
			}  else
			{
				if (handle->iface.B_2_raised == bool_true)
				{ 
					exseq_t_START_Configuration_Minutes(handle);
					nixieIface_increase(handle, NIXIE_NIXIEIFACE_B_TIME, NIXIE_NIXIEIFACE_MINUTE);
					enseq_t_START_Configuration_Minutes_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_START_Configuration_Year_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Year. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_START_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.B_3_raised == bool_true)
			{ 
				exseq_t_START_Configuration_Year(handle);
				enseq_t_START_Configuration_Month_default(handle);
			}  else
			{
				if (handle->iface.B_2_raised == bool_true)
				{ 
					exseq_t_START_Configuration_Year(handle);
					nixieIface_increase(handle, NIXIE_NIXIEIFACE_B_DATE, NIXIE_NIXIEIFACE_YEAR);
					enseq_t_START_Configuration_Year_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_START_Configuration_Month_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Month. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_START_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.B_3_raised == bool_true)
			{ 
				exseq_t_START_Configuration_Month(handle);
				enseq_t_START_Configuration_Day_default(handle);
			}  else
			{
				if (handle->iface.B_2_raised == bool_true)
				{ 
					exseq_t_START_Configuration_Month(handle);
					nixieIface_increase(handle, NIXIE_NIXIEIFACE_B_DATE, NIXIE_NIXIEIFACE_MONTH);
					enseq_t_START_Configuration_Month_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_START_Configuration_Day_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Day. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_START_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.B_3_raised == bool_true)
			{ 
				exseq_t_START_Configuration_Day(handle);
				nixieIface_send(handle, NIXIE_NIXIEIFACE_DATE);
				enseq_t_START_Configuration_Config_default(handle);
			}  else
			{
				if (handle->iface.B_2_raised == bool_true)
				{ 
					exseq_t_START_Configuration_Day(handle);
					nixieIface_increase(handle, NIXIE_NIXIEIFACE_B_DATE, NIXIE_NIXIEIFACE_DAY);
					enseq_t_START_Configuration_Day_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE1_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state MODE1. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((react(handle)) == (bool_false))
		{ 
			if (handle->iface.E_ALARM_raised == bool_true)
			{ 
				exseq_t_MODE1(handle);
				enseq_t_Alarm_default(handle);
			}  else
			{
				if (handle->iface.B_1_raised == bool_true)
				{ 
					exseq_t_MODE1(handle);
					enseq_t_MODE2_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE1_Awake_Awake_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Awake. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE1_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.S_SENSOR_raised == bool_true)
			{ 
				exseq_t_MODE1_Awake_Awake(handle);
				enseq_t_MODE1_Awake_Date_default(handle);
			}  else
			{
				if (handle->iface.B_3_raised == bool_true)
				{ 
					exseq_t_MODE1_Awake_Awake(handle);
					nixieIface_swapLedFlag(handle);
					enseq_t_MODE1_Awake_Awake_default(handle);
				}  else
				{
					if (handle->iface.B_2_raised == bool_true)
					{ 
						exseq_t_MODE1_Awake_Awake(handle);
						nixieIface_increaseLed(handle);
						enseq_t_MODE1_Awake_Awake_default(handle);
					}  else
					{
						did_transition = bool_false;
					}
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE1_Awake_Date_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Date. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE1_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->timeEvents.nixie_t_MODE1_Awake_Date_tev0_raised == bool_true)
			{ 
				exseq_t_MODE1_Awake_Date(handle);
				enseq_t_MODE1_Awake_Temperature_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE1_Awake_Temperature_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Temperature. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE1_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->timeEvents.nixie_t_MODE1_Awake_Temperature_tev0_raised == bool_true)
			{ 
				exseq_t_MODE1_Awake_Temperature(handle);
				enseq_t_MODE1_Awake_Awake_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE2_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state MODE2. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((react(handle)) == (bool_false))
		{ 
			if (handle->iface.E_ALARM_raised == bool_true)
			{ 
				exseq_t_MODE2(handle);
				enseq_t_Alarm_default(handle);
			}  else
			{
				if (handle->iface.B_1_raised == bool_true)
				{ 
					exseq_t_MODE2(handle);
					enseq_t_MODE3_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE2_Sleep_Wake_Up_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Wake Up. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE2_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.S_SENSOR_raised == bool_true)
			{ 
				exseq_t_MODE2_Sleep_Wake_Up(handle);
				enseq_t_MODE2_Sleep_Date_default(handle);
			}  else
			{
				if (handle->timeEvents.nixie_t_MODE2_Sleep_Wake_Up_tev0_raised == bool_true)
				{ 
					exseq_t_MODE2_Sleep_Wake_Up(handle);
					enseq_t_MODE2_Sleep_Sleep_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE2_Sleep_Sleep_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Sleep. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE2_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.S_SENSOR_raised == bool_true)
			{ 
				exseq_t_MODE2_Sleep_Sleep(handle);
				enseq_t_MODE2_Sleep_Wake_Up_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE2_Sleep_Date_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Date. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE2_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->timeEvents.nixie_t_MODE2_Sleep_Date_tev0_raised == bool_true)
			{ 
				exseq_t_MODE2_Sleep_Date(handle);
				enseq_t_MODE2_Sleep_Temperature_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE2_Sleep_Temperature_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Temperature. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE2_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->timeEvents.nixie_t_MODE2_Sleep_Temperature_tev0_raised == bool_true)
			{ 
				exseq_t_MODE2_Sleep_Temperature(handle);
				enseq_t_MODE2_Sleep_Wake_Up_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE3_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state MODE3. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((react(handle)) == (bool_false))
		{ 
			if (handle->iface.E_ALARM_raised == bool_true)
			{ 
				exseq_t_MODE3(handle);
				enseq_t_Alarm_default(handle);
			}  else
			{
				if (handle->iface.B_1_raised == bool_true)
				{ 
					exseq_t_MODE3(handle);
					enseq_t_MODE1_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE3_Alarm_AlarmConfig_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state AlarmConfig. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE3_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.B_3_raised == bool_true)
			{ 
				exseq_t_MODE3_Alarm_AlarmConfig(handle);
				enseq_t_MODE3_Alarm_Hour_default(handle);
			}  else
			{
				if (handle->iface.B_2_raised == bool_true)
				{ 
					exseq_t_MODE3_Alarm_AlarmConfig(handle);
					nixieIface_swapAlarm(handle);
					enseq_t_MODE3_Alarm_AlarmConfig_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE3_Alarm_Hour_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Hour. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE3_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.B_3_raised == bool_true)
			{ 
				exseq_t_MODE3_Alarm_Hour(handle);
				enseq_t_MODE3_Alarm_Minute_default(handle);
			}  else
			{
				if (handle->iface.B_2_raised == bool_true)
				{ 
					exseq_t_MODE3_Alarm_Hour(handle);
					nixieIface_increase(handle, NIXIE_NIXIEIFACE_B_ALARM, NIXIE_NIXIEIFACE_HOUR);
					enseq_t_MODE3_Alarm_Hour_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_MODE3_Alarm_Minute_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Minute. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_MODE3_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.B_3_raised == bool_true)
			{ 
				exseq_t_MODE3_Alarm_Minute(handle);
				nixieIface_send(handle, NIXIE_NIXIEIFACE_ALARM);
				enseq_t_MODE3_Alarm_AlarmConfig_default(handle);
			}  else
			{
				if (handle->iface.B_2_raised == bool_true)
				{ 
					exseq_t_MODE3_Alarm_Minute(handle);
					nixieIface_increase(handle, NIXIE_NIXIEIFACE_B_ALARM, NIXIE_NIXIEIFACE_MINUTE);
					enseq_t_MODE3_Alarm_Minute_default(handle);
				}  else
				{
					did_transition = bool_false;
				}
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_Alarm_react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Alarm. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((react(handle)) == (bool_false))
		{ 
			if ((handle->iface.S_SENSOR_raised == bool_true) || (((handle->internal.count) == (NIXIE_NIXIEIFACE_COUNTMAX)) == bool_true))
			{ 
				exseq_t_Alarm(handle);
				react_t__choice_0(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_Alarm_Alarm_Alarm_ON__react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Alarm[ON]. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_Alarm_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->timeEvents.nixie_t_Alarm_Alarm_Alarm_ON__tev0_raised == bool_true)
			{ 
				exseq_t_Alarm_Alarm_Alarm_ON_(handle);
				enseq_t_Alarm_Alarm_Alarm_OFF__default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean t_Alarm_Alarm_Alarm_OFF__react(Nixie* handle, const sc_boolean try_transition) {
	/* The reactions of state Alarm[OFF]. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((t_Alarm_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->timeEvents.nixie_t_Alarm_Alarm_Alarm_OFF__tev0_raised == bool_true)
			{ 
				exseq_t_Alarm_Alarm_Alarm_OFF_(handle);
				enseq_t_Alarm_Alarm_Alarm_ON__default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}


