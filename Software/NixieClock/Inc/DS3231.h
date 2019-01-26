/*
 * DS3231.h
 *
 *  Created on: 18 ene. 2019
 *      Author: Manuel
 */

#ifndef DS3231_H_
#define DS3231_H_

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_def.h"



#define DS3231_ADDRESS 0xD0
#define SECONDS_ADDRESS 0x00
#define MINUTES_ADDRESS 0x01
#define HOURS_ADDRESS 0x02
#define DAY_ADDRESS 0x03
#define DATE_ADDRESS 0x04
#define MONTH_ADDRESS 0x05
#define YEAR_ADDRESS 0x06
#define ALARM1_SECONDS_ADDRESS 0x07
#define ALARM1_MINUTES_ADDRESS 0x08
#define ALARM1_HOURS_ADDRESS 0x09
#define ALARM1_DATE_ADDRESS 0x0A
#define ALARM2_MINUTES_ADDRESS 0x0B
#define ALARM2_HOURS_ADDRESS 0x0C
#define ALARM2_DATE_ADDRESS 0x0D
#define CONFIG1_ADDRESS 0x0E
#define CONFIG2_ADDRESS 0x0F
#define OFFSET_ADDRESS 0x10
#define TEMP_MSB_ADDRESS 0x11
#define TEMP_LSB_ADDRESS 0x12

#define D_TIME 0
#define D_DATE 1
#define D_ALARM 2
#define D_TEMP 3
#define D_ALARM_STATE 4
#define D_SECONDS 0
#define D_MINUTES 1
#define D_HOURS 2
#define D_DAY 0
#define D_MONTH 1
#define D_YEAR 2

#define ON 1
#define OFF 0

#define CURRENT 0
#define CONFIG 1

#define A1M1 0x00
#define A1M2 0x00
#define A1M3 0x00
#define A1M4 0x80

struct DS3231{
	uint8_t DS3231[19];
	uint8_t TIME[2][6];
	uint8_t DATE[2][6];
	uint8_t ALARM[2][6];
	uint8_t TEMP[6];
	uint8_t A1IE;
};

void getRTC(I2C_HandleTypeDef *hi2c);
void setConfigRTC(I2C_HandleTypeDef *hi2c);
void stopAlarm(I2C_HandleTypeDef *hi2c);
void resetVarRTC();
void setRTC(I2C_HandleTypeDef *hi2c,uint8_t TYPE);
void loadRTC();
void increase(uint8_t type,uint8_t unit);
uint8_t enableAlarm(I2C_HandleTypeDef *hi2c);
uint8_t * Display(uint8_t State);

#endif /* DS3231_H_ */
