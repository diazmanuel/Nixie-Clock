/*
 * DS3231.c
 *
 *  Created on: 18 ene. 2019
 *      Author: Manuel
 */


#include "DS3231.h"

struct DS3231 RTC_DATA;

void getRTC(I2C_HandleTypeDef *hi2c){
	HAL_I2C_Mem_Read_DMA(&(*hi2c),DS3231_ADDRESS,0,I2C_MEMADD_SIZE_8BIT,RTC_DATA.DS3231,19);
}
uint8_t * Display(uint8_t State){
	switch(State){
		case D_TIME:
			return RTC_DATA.TIME[CURRENT];
			break;
		case D_DATE:
			return RTC_DATA.DATE[CURRENT];
			break;
		case D_ALARM:
			return RTC_DATA.ALARM[CURRENT];
			break;
		case D_TEMP:
			return RTC_DATA.TEMP;
			break;
		default:
			return RTC_DATA.TIME[CURRENT];
			break;
	}
}
void setConfigRTC(I2C_HandleTypeDef *hi2c){
	uint8_t data[2];
	data[0]=CONFIG1_ADDRESS;
	data[1]=0x04;
	HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
	data[0]=CONFIG2_ADDRESS;
	data[1]=0x00;
	HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);

}
void stopAlarm(I2C_HandleTypeDef *hi2c){
	uint8_t data[2];
	data[0]=CONFIG2_ADDRESS;
	data[1]=0x00;
	HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
}
uint8_t enableAlarm(I2C_HandleTypeDef *hi2c){
	uint8_t STATE=(~RTC_DATA.A1IE);
	uint8_t data[2];
	data[0]=CONFIG1_ADDRESS;
	data[1]=(RTC_DATA.A1IE)? 0x04 : 0x05;
	HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
	return STATE;
}

void increase(uint8_t type,uint8_t unit){
	switch(type){
	case D_TIME:
		switch(unit){
		case D_SECONDS:
			if((RTC_DATA.TIME[CONFIG][1]==5) && (RTC_DATA.TIME[CONFIG][0]==9)){
				RTC_DATA.TIME[CONFIG][0]=0;
				RTC_DATA.TIME[CONFIG][1]=0;
			}else{
				if(RTC_DATA.TIME[CONFIG][0]!=9){
					RTC_DATA.TIME[CONFIG][0]++;
				}else{
					RTC_DATA.TIME[CONFIG][0]=0;
					RTC_DATA.TIME[CONFIG][1]++;
				}
			}
		break;
		case D_MINUTES:
			if((RTC_DATA.TIME[CONFIG][3]==5) && (RTC_DATA.TIME[CONFIG][2]==9)){
				RTC_DATA.TIME[CONFIG][2]=0;
				RTC_DATA.TIME[CONFIG][3]=0;
			}else{
				if(RTC_DATA.TIME[CONFIG][2]!=9){
					RTC_DATA.TIME[CONFIG][2]++;
				}else{
					RTC_DATA.TIME[CONFIG][2]=0;
					RTC_DATA.TIME[CONFIG][3]++;
				}
			}
			break;
		case D_HOURS:
			if((RTC_DATA.TIME[CONFIG][5]==2) && (RTC_DATA.TIME[CONFIG][4]==3)){
				RTC_DATA.TIME[CONFIG][4]=0;
				RTC_DATA.TIME[CONFIG][5]=0;
			}else{
				if(RTC_DATA.TIME[CONFIG][4]!=9){
					RTC_DATA.TIME[CONFIG][4]++;
				}else{
					RTC_DATA.TIME[CONFIG][4]=0;
					RTC_DATA.TIME[CONFIG][5]++;
				}
			}
			break;
			}
		break;
	case D_DATE:
		switch(unit){
		case D_DAY:
			if((RTC_DATA.DATE[CONFIG][5]==3) && (RTC_DATA.TIME[CONFIG][4]==1)){
				RTC_DATA.DATE[CONFIG][4]=1;
				RTC_DATA.DATE[CONFIG][5]=0;
			}else{
				if(RTC_DATA.DATE[CONFIG][4]!=9){
					RTC_DATA.DATE[CONFIG][4]++;
				}else{
					RTC_DATA.DATE[CONFIG][4]=0;
					RTC_DATA.DATE[CONFIG][5]++;
				}
			}
		break;
		case D_MONTH:
			if((RTC_DATA.DATE[CONFIG][3]==1) && (RTC_DATA.TIME[CONFIG][2]==2)){
				RTC_DATA.DATE[CONFIG][2]=1;
				RTC_DATA.DATE[CONFIG][3]=0;
			}else{
				if(RTC_DATA.DATE[CONFIG][2]!=9){
					RTC_DATA.DATE[CONFIG][2]++;
				}else{
					RTC_DATA.DATE[CONFIG][2]=0;
					RTC_DATA.DATE[CONFIG][3]++;
				}
			}
			break;
		case D_YEAR:
			if(RTC_DATA.DATE[CONFIG][0]==9 && RTC_DATA.DATE[CONFIG][1]==9){
				RTC_DATA.DATE[CONFIG][0]=0;
				RTC_DATA.DATE[CONFIG][1]=0;
			}else{
				if(RTC_DATA.DATE[CONFIG][0]!=9){
					RTC_DATA.DATE[CONFIG][0]++;
				}else{
					RTC_DATA.DATE[CONFIG][0]=0;
					RTC_DATA.DATE[CONFIG][1]++;
				}
			}
			break;
			}
		break;
	case D_ALARM:
		switch(unit){
		case D_SECONDS:
			if((RTC_DATA.ALARM[CONFIG][1]==5) && (RTC_DATA.ALARM[CONFIG][0]==9)){
				RTC_DATA.ALARM[CONFIG][0]=0;
				RTC_DATA.ALARM[CONFIG][1]=0;
			}else{
				if(RTC_DATA.ALARM[CONFIG][0]!=9){
					RTC_DATA.ALARM[CONFIG][0]++;
				}else{
					RTC_DATA.ALARM[CONFIG][0]=0;
					RTC_DATA.ALARM[CONFIG][1]++;
				}
			}
		break;
		case D_MINUTES:
			if((RTC_DATA.ALARM[CONFIG][3]==5) && (RTC_DATA.ALARM[CONFIG][2]==9)){
				RTC_DATA.ALARM[CONFIG][2]=0;
				RTC_DATA.ALARM[CONFIG][3]=0;
			}else{
				if(RTC_DATA.ALARM[CONFIG][2]!=9){
					RTC_DATA.ALARM[CONFIG][2]++;
				}else{
					RTC_DATA.ALARM[CONFIG][2]=0;
					RTC_DATA.ALARM[CONFIG][3]++;
				}
			}
			break;
		case D_HOURS:
			if((RTC_DATA.ALARM[CONFIG][5]==2) && (RTC_DATA.ALARM[CONFIG][4]==3)){
				RTC_DATA.ALARM[CONFIG][4]=0;
				RTC_DATA.ALARM[CONFIG][5]=0;
			}else{
				if(RTC_DATA.ALARM[CONFIG][4]!=9){
					RTC_DATA.ALARM[CONFIG][4]++;
				}else{
					RTC_DATA.ALARM[CONFIG][4]=0;
					RTC_DATA.ALARM[CONFIG][5]++;
				}
			}
			break;
			}
		break;
	}
}

void resetVarRTC(){
	for(uint8_t i=0;i==5;i++){
		RTC_DATA.TIME[1][i]=0;
		RTC_DATA.ALARM[1][i]=0;
	}
	RTC_DATA.DATE[CONFIG][0]=0;
	RTC_DATA.DATE[CONFIG][1]=0;
	RTC_DATA.DATE[CONFIG][2]=1;
	RTC_DATA.DATE[CONFIG][3]=0;
	RTC_DATA.DATE[CONFIG][4]=1;
	RTC_DATA.DATE[CONFIG][5]=0;
}
void setRTC(I2C_HandleTypeDef *hi2c,uint8_t TYPE){
	uint8_t data[2];
	switch(TYPE){
	case D_TIME:
		data[0]=SECONDS_ADDRESS;
		data[1]=((RTC_DATA.TIME[CONFIG][1]<<4)|RTC_DATA.TIME[CONFIG][0]);
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		data[0]=MINUTES_ADDRESS;
		data[1]=((RTC_DATA.TIME[CONFIG][3]<<4)|RTC_DATA.TIME[CONFIG][2]);
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		data[0]=HOURS_ADDRESS;
		data[1]=((RTC_DATA.TIME[CONFIG][5]<<4)|RTC_DATA.TIME[CONFIG][4]);
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		break;
	case D_DATE:
		data[0]=YEAR_ADDRESS;
		data[1]=((RTC_DATA.DATE[CONFIG][1]<<4)|RTC_DATA.DATE[CONFIG][0]);
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		data[0]=MONTH_ADDRESS;
		data[1]=((RTC_DATA.DATE[CONFIG][3]<<4)|RTC_DATA.DATE[CONFIG][2]);
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		data[0]=DATE_ADDRESS;
		data[1]=((RTC_DATA.DATE[CONFIG][5]<<4)|RTC_DATA.DATE[CONFIG][4]);
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		break;
	case D_ALARM:
		data[0]=ALARM1_SECONDS_ADDRESS;
		data[1]=((RTC_DATA.ALARM[CONFIG][1]<<4)|RTC_DATA.ALARM[CONFIG][0])|(A1M1);
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		data[0]=ALARM1_MINUTES_ADDRESS;
		data[1]=((RTC_DATA.ALARM[CONFIG][3]<<4)|RTC_DATA.ALARM[CONFIG][2])|(A1M2);
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		data[0]=ALARM1_HOURS_ADDRESS;
		data[1]=((RTC_DATA.ALARM[CONFIG][5]<<4)|RTC_DATA.ALARM[CONFIG][4])|(A1M3);
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		data[0]=ALARM1_DATE_ADDRESS;
		data[1]=A1M4;
		HAL_I2C_Master_Transmit(&(*hi2c),DS3231_ADDRESS,data,2,100);
		break;
	}

}
void loadRTC(){
RTC_DATA.TIME[CURRENT][0]=RTC_DATA.DS3231[0]&0x0f;
RTC_DATA.TIME[CURRENT][1]=(RTC_DATA.DS3231[0]&0xf0)>>4;
RTC_DATA.TIME[CURRENT][2]=RTC_DATA.DS3231[1]&0x0f;
RTC_DATA.TIME[CURRENT][3]=(RTC_DATA.DS3231[1]&0xf0)>>4;
RTC_DATA.TIME[CURRENT][4]=RTC_DATA.DS3231[2]&0x0f;
RTC_DATA.TIME[CURRENT][5]=(RTC_DATA.DS3231[2]&0x30)>>4;

RTC_DATA.DATE[CURRENT][0]=RTC_DATA.DS3231[6]&0x0f;
RTC_DATA.DATE[CURRENT][1]=(RTC_DATA.DS3231[6])>>4;
RTC_DATA.DATE[CURRENT][2]=RTC_DATA.DS3231[5]&0x0f;
RTC_DATA.DATE[CURRENT][3]=(RTC_DATA.DS3231[5]&0x10)>>4;
RTC_DATA.DATE[CURRENT][4]=RTC_DATA.DS3231[4]&0x0f;
RTC_DATA.DATE[CURRENT][5]=(RTC_DATA.DS3231[4]&0x30)>>4;


RTC_DATA.ALARM[CURRENT][0]=RTC_DATA.DS3231[7]&0x0f;
RTC_DATA.ALARM[CURRENT][1]=(RTC_DATA.DS3231[7]&0xf0)>>4;
RTC_DATA.ALARM[CURRENT][2]=RTC_DATA.DS3231[8]&0x0f;
RTC_DATA.ALARM[CURRENT][3]=(RTC_DATA.DS3231[8]&0xf0)>>4;
RTC_DATA.ALARM[CURRENT][4]=RTC_DATA.DS3231[9]&0x0f;
RTC_DATA.ALARM[CURRENT][5]=(RTC_DATA.DS3231[9]&0x30)>>4;

switch(RTC_DATA.DS3231[18]>>6){
	case 0:
		RTC_DATA.TEMP[0]=0;
		RTC_DATA.TEMP[1]=0;
	break;
	case 1:
		RTC_DATA.TEMP[0]=5;
		RTC_DATA.TEMP[1]=2;
	break;
	case 2:
		RTC_DATA.TEMP[0]=0;
		RTC_DATA.TEMP[1]=5;
	break;
	case 3:
		RTC_DATA.TEMP[0]=5;
		RTC_DATA.TEMP[1]=7;
	break;
	default:
		RTC_DATA.TEMP[0]=0;
		RTC_DATA.TEMP[1]=0;
	break;
}
RTC_DATA.TEMP[2]=((RTC_DATA.DS3231[17]&0x7f)%10);
RTC_DATA.TEMP[3]=((RTC_DATA.DS3231[17]&0x7f)/10);
RTC_DATA.TEMP[4]=(RTC_DATA.DS3231[17]>>7);
RTC_DATA.A1IE=(RTC_DATA.DS3231[14] & 0x01);
}

