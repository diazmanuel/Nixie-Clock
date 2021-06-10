/*
 * nixieDisplay.c
 *
 *  Created on: 24 ene. 2019
 *      Author: Manuel
 */
#include "nixieDisplay.h"


extern I2C_HandleTypeDef hi2c2;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;


static Nixie Clock;

static uint8_t LedFlag=1;
static uint8_t LedPower=1;
static uint8_t BuzzerFlag=0;
static uint8_t Led[5];
static uint8_t LedIndex=0;
static uint8_t DisplayIndex=0;
static uint8_t NixiePower=1;

struct state_timer {
void *sm_handle;
sc_eventid ev_id;
raise_event_cb_t cb;
uint32_t timeout;
uint32_t expires;
bool periodic;
};

static struct state_timer timers[MAX_NUM_TIMERS] = {0};
void resetVarNixie(){
	LedFlag=1;
	LedPower=1;
	BuzzerFlag=0;
	LedIndex=0;
	DisplayIndex=0;
	NixiePower=1;
	Led[N_TIME]=BLACK;
	Led[N_DATE]=GREEN;
	Led[N_TEMP]=BLUE;
	Led[N_ALARM]=RED;
	Led[N_ALARM_STATE]=RED;
}
void nixieLed(){
	static uint8_t aux=0;
	if(LedFlag && LedPower){
		if(((Led[LedIndex]>>0)&0x03)>aux){
			HAL_GPIO_WritePin(LedRed_GPIO_Port,LedRed_Pin,GPIO_PIN_SET);
		}else{
			HAL_GPIO_WritePin(LedRed_GPIO_Port,LedRed_Pin,GPIO_PIN_RESET);
		}
		if(((Led[LedIndex]>>2)&0x03)>aux){
			HAL_GPIO_WritePin(LedGreen_GPIO_Port,LedGreen_Pin,GPIO_PIN_SET);
		}else{
			HAL_GPIO_WritePin(LedGreen_GPIO_Port,LedGreen_Pin,GPIO_PIN_RESET);
		}
		if(((Led[LedIndex]>>4)&0x03)>aux){
			HAL_GPIO_WritePin(LedBlue_GPIO_Port,LedBlue_Pin,GPIO_PIN_SET);
		}else{
			HAL_GPIO_WritePin(LedBlue_GPIO_Port,LedBlue_Pin,GPIO_PIN_RESET);
		}
		aux++;
		aux%=3;
	}else{
		HAL_GPIO_WritePin(LedBlue_GPIO_Port,LedBlue_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LedGreen_GPIO_Port,LedGreen_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LedRed_GPIO_Port,LedRed_Pin,GPIO_PIN_RESET);
	}
}
void segment(uint8_t digit){
	uint8_t *display;
	display=Display(DisplayIndex);
	HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Nixie_5_GPIO_Port,Nixie_5_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Nixie_6_GPIO_Port,Nixie_6_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Nixie_8_GPIO_Port,Nixie_8_Pin,GPIO_PIN_RESET);
	switch(display[digit]){
					case 0:
						HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_5_GPIO_Port,Nixie_5_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_6_GPIO_Port,Nixie_6_Pin,GPIO_PIN_SET);
						break;
					case 1:
						HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
						break;
					case 2:
						HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_5_GPIO_Port,Nixie_5_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_SET);
						break;
					case 3:
						HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_SET);
						break;
					case 4:
						HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_6_GPIO_Port,Nixie_6_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_SET);
						break;
					case 5:
						HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_6_GPIO_Port,Nixie_6_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_SET);
						break;
					case 6:
						HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_5_GPIO_Port,Nixie_5_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_6_GPIO_Port,Nixie_6_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_SET);
						break;
					case 7:
						HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
						break;
					case 8:
						HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_5_GPIO_Port,Nixie_5_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_6_GPIO_Port,Nixie_6_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_SET);
						break;
					case 9:
						HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_6_GPIO_Port,Nixie_6_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_SET);
						break;
			}

	if(DisplayIndex==N_TEMP){
		HAL_GPIO_WritePin(NixieCrl_P_GPIO_Port,NixieCrl_P_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(NixieCrl_5_GPIO_Port,NixieCrl_5_Pin,GPIO_PIN_RESET);
		if(digit==2){
			HAL_GPIO_WritePin(Nixie_8_GPIO_Port,Nixie_8_Pin,GPIO_PIN_SET);
		}
		if((digit==4) && (display[digit]==1)){
			HAL_GPIO_WritePin(Nixie_8_GPIO_Port,Nixie_8_Pin,GPIO_PIN_SET);
		}else{
			HAL_GPIO_WritePin(NixieCrl_4_GPIO_Port,NixieCrl_4_Pin,GPIO_PIN_RESET);
		}
	}else{
		HAL_GPIO_WritePin(NixieCrl_P_GPIO_Port,NixieCrl_P_Pin,GPIO_PIN_SET);
		if ((digit==2) || (digit==4)){
			HAL_GPIO_WritePin(Nixie_8_GPIO_Port,Nixie_8_Pin,GPIO_PIN_SET);
		}
	}
}
void segmentDisplay(){

	static uint8_t digit=0;
	HAL_GPIO_WritePin(NixieCrl_0_GPIO_Port,NixieCrl_0_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_1_GPIO_Port,NixieCrl_1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_2_GPIO_Port,NixieCrl_2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_3_GPIO_Port,NixieCrl_3_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_4_GPIO_Port,NixieCrl_4_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_5_GPIO_Port,NixieCrl_5_Pin,GPIO_PIN_RESET);
	if(NixiePower){


		switch(digit){
				case 0:
					HAL_GPIO_WritePin(NixieCrl_0_GPIO_Port,NixieCrl_0_Pin,GPIO_PIN_SET);
					break;
				case 1:
					HAL_GPIO_WritePin(NixieCrl_1_GPIO_Port,NixieCrl_1_Pin,GPIO_PIN_SET);
					break;
				case 2:
					HAL_GPIO_WritePin(NixieCrl_2_GPIO_Port,NixieCrl_2_Pin,GPIO_PIN_SET);
					break;
				case 3:
					HAL_GPIO_WritePin(NixieCrl_3_GPIO_Port,NixieCrl_3_Pin,GPIO_PIN_SET);
					break;
				case 4:
					HAL_GPIO_WritePin(NixieCrl_4_GPIO_Port,NixieCrl_4_Pin,GPIO_PIN_SET);
					break;
				case 5:
					HAL_GPIO_WritePin(NixieCrl_5_GPIO_Port,NixieCrl_5_Pin,GPIO_PIN_SET);
					break;
				}
		segment(digit);
		digit++;
		digit%=6;
	}
}
void nixieDisplay(){
	uint8_t *display;
	static uint8_t digit=0;
	HAL_GPIO_WritePin(NixieCrl_0_GPIO_Port,NixieCrl_0_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_1_GPIO_Port,NixieCrl_1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_2_GPIO_Port,NixieCrl_2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_3_GPIO_Port,NixieCrl_3_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_4_GPIO_Port,NixieCrl_4_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NixieCrl_5_GPIO_Port,NixieCrl_5_Pin,GPIO_PIN_RESET);
	if(NixiePower){
		display=Display(DisplayIndex);
		HAL_GPIO_WritePin(Nixie_0_GPIO_Port,Nixie_0_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_5_GPIO_Port,Nixie_5_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_6_GPIO_Port,Nixie_6_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_8_GPIO_Port,Nixie_8_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_9_GPIO_Port,Nixie_9_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_DP_GPIO_Port,Nixie_DP_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie_LP_GPIO_Port,Nixie_LP_Pin,GPIO_PIN_RESET);
		switch(display[digit]){
				case 0:
					HAL_GPIO_WritePin(Nixie_0_GPIO_Port,Nixie_0_Pin,GPIO_PIN_SET);
					break;
				case 1:
					HAL_GPIO_WritePin(Nixie_1_GPIO_Port,Nixie_1_Pin,GPIO_PIN_SET);
					break;
				case 2:
					HAL_GPIO_WritePin(Nixie_2_GPIO_Port,Nixie_2_Pin,GPIO_PIN_SET);
					break;
				case 3:
					HAL_GPIO_WritePin(Nixie_3_GPIO_Port,Nixie_3_Pin,GPIO_PIN_SET);
					break;
				case 4:
					HAL_GPIO_WritePin(Nixie_4_GPIO_Port,Nixie_4_Pin,GPIO_PIN_SET);
					break;
				case 5:
					HAL_GPIO_WritePin(Nixie_5_GPIO_Port,Nixie_5_Pin,GPIO_PIN_SET);
					break;
				case 6:
					HAL_GPIO_WritePin(Nixie_6_GPIO_Port,Nixie_6_Pin,GPIO_PIN_SET);
					break;
				case 7:
					HAL_GPIO_WritePin(Nixie_7_GPIO_Port,Nixie_7_Pin,GPIO_PIN_SET);
					break;
				case 8:
					HAL_GPIO_WritePin(Nixie_8_GPIO_Port,Nixie_8_Pin,GPIO_PIN_SET);
					break;
				case 9:
					HAL_GPIO_WritePin(Nixie_9_GPIO_Port,Nixie_9_Pin,GPIO_PIN_SET);
					break;
		}
		switch(digit){
				case 0:
					HAL_GPIO_WritePin(NixieCrl_0_GPIO_Port,NixieCrl_0_Pin,GPIO_PIN_SET);
					break;
				case 1:
					HAL_GPIO_WritePin(NixieCrl_1_GPIO_Port,NixieCrl_1_Pin,GPIO_PIN_SET);
					break;
				case 2:
					HAL_GPIO_WritePin(NixieCrl_2_GPIO_Port,NixieCrl_2_Pin,GPIO_PIN_SET);
					break;
				case 3:
					HAL_GPIO_WritePin(NixieCrl_3_GPIO_Port,NixieCrl_3_Pin,GPIO_PIN_SET);
					break;
				case 4:
					HAL_GPIO_WritePin(NixieCrl_4_GPIO_Port,NixieCrl_4_Pin,GPIO_PIN_SET);
					break;
				case 5:
					HAL_GPIO_WritePin(NixieCrl_5_GPIO_Port,NixieCrl_5_Pin,GPIO_PIN_SET);
					break;
				}


		if(DisplayIndex==N_TEMP){
			HAL_GPIO_WritePin(NixieCrl_P_GPIO_Port,NixieCrl_P_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(NixieCrl_5_GPIO_Port,NixieCrl_5_Pin,GPIO_PIN_RESET);
			if(digit==1){
				HAL_GPIO_WritePin(Nixie_LP_GPIO_Port,Nixie_LP_Pin,GPIO_PIN_SET);
			}
			if((digit==4) && (display[digit]==1)){
				HAL_GPIO_WritePin(Nixie_LP_GPIO_Port,Nixie_LP_Pin,GPIO_PIN_SET);
			}
		}else{
			HAL_GPIO_WritePin(NixieCrl_P_GPIO_Port,NixieCrl_P_Pin,GPIO_PIN_SET);

		}
		digit++;
		digit%=6;
	}
}

void nixieIface_increase(const Nixie* handle, const int32_t Type, const int32_t Unit){
	increase(Type,Unit);
}
void nixieIface_show(const Nixie* handle, const int32_t State){
	DisplayIndex=State;
}
void nixieIface_increaseLed(const Nixie* handle){
	Led[N_TIME]++;
	Led[N_TIME]%=0x40;
}
void nixieIface_init(const Nixie* handle){
	  HAL_TIM_Base_Start_IT(&htim2);
	  HAL_TIM_Base_Start_IT(&htim3);
	  HAL_TIM_Base_Start_IT(&htim4);
	  setConfigRTC(&hi2c2);
	  resetVarRTC();
	  resetVarNixie();
}
void nixieIface_showLed(const Nixie* handle, const int32_t State){
	LedIndex=State;
}
void nixieIface_ledPower(const Nixie* handle, const int32_t State){
	LedPower=State;
}
void nixieIface_send(const Nixie* handle, const int32_t State){
	setRTC(&hi2c2,State);
}
void nixieIface_nixiePower(const Nixie* handle, const int32_t State){
	NixiePower=State;
}
void nixieIface_buzzer(const Nixie* handle, const int32_t State){
	BuzzerFlag=State;
}
void nixieIface_swapAlarm(const Nixie* handle){
	uint8_t aux=0;
	aux=enableAlarm(&hi2c2);
	Led[N_ALARM_STATE]=aux? GREEN: RED;
}
void nixieIface_swapLedFlag(const Nixie* handle){
	LedFlag=~LedFlag;
}
void nixieIface_alarmFlag(const Nixie* handle){
	stopAlarm(&hi2c2);
}
void nixieIface_resetVar(const Nixie* handle){
	resetVarRTC();
}
void nixie_setTimer(Nixie* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	stateTimer_start(handle, evid, (raise_event_cb_t) nixie_raiseTimeEvent, time_ms, periodic);
}
void nixie_unsetTimer(Nixie* handle, const sc_eventid evid){
	stateTimer_stop(evid);
}
void nixieInit(){
	  nixie_init(&Clock);
	  nixie_enter(&Clock);
	  nixie_runCycle(&Clock);
}

void nixieEvent(uint8_t event){
	switch (event){
	case E_B1 :
		nixieIface_raise_b_1(&Clock);
		break;
	case E_B2 :
		nixieIface_raise_b_2(&Clock);
		break;
	case E_B3 :
		nixieIface_raise_b_3(&Clock);
		break;
	case E_ALARM :
		nixieIface_raise_e_ALARM(&Clock);
		break;
	case E_SENSOR :
		nixieIface_raise_s_SENSOR(&Clock);
		break;
	}
	nixie_runCycle(&Clock);
}



uint8_t stateTimer_start(void *sm_handle, sc_eventid ev_id, raise_event_cb_t cb,
                          uint32_t timeout, bool periodic)
{
    if ((sm_handle == NULL) || (ev_id == NULL) || (cb == NULL)) {
        return ERROR;
    }

    for (uint8_t i = 0; i < NELEMENTS(timers); i++) {
        if (timers[i].ev_id == ev_id) {
            return ERROR;  // existing event
        }
        if (timers[i].ev_id == NULL) {
            timers[i].sm_handle = sm_handle;
            timers[i].ev_id = ev_id;
            timers[i].cb = cb;
            timers[i].timeout = timeout;
            timers[i].expires = timeout;
            timers[i].periodic = periodic;
            return SUCCESS;
        }
    }

    return ERROR;  // no free timer
}

void stateTimer_update(void)
{
    for (uint8_t i = 0; i < NELEMENTS(timers); i++) {
        if (timers[i].ev_id != NULL) {
            if (timers[i].expires != 0) {
                timers[i].expires--;
            }
            else {
                timers[i].cb(timers[i].sm_handle, timers[i].ev_id);

                if (timers[i].periodic) {
                    timers[i].expires = timers[i].timeout;
                }
                else {
                    timers[i].ev_id = NULL;
                }
            }
        }
    }
}

uint8_t stateTimer_stop(sc_eventid ev_id)
{
    for (uint8_t i = 0; i < NELEMENTS(timers); i++) {
        if (timers[i].ev_id == ev_id) {
            timers[i].ev_id = NULL;
            return SUCCESS;
        }
    }

    return ERROR; // no timer associated to that event
}
void nixieTickUpdate(){
	  stateTimer_update();
	  nixie_runCycle(&Clock);
}


uint8_t nixieBuzzer(uint8_t Period, uint8_t Activity){
	static uint8_t aux=0;
	if (Activity>Period){
		return ERROR;
	}else{
		if((BuzzerFlag) && (aux<Activity)){
			HAL_GPIO_TogglePin(Buzzer_GPIO_Port,Buzzer_Pin);
		}else{
			HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_RESET);
		}
		aux++;
		aux%=Period;
	return SUCCESS;
	}
}


