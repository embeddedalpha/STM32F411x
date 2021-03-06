/*
 * I2C.h
 *
 *  Created on: 08-Jul-2021
 *      Author: Kunal
 */

#ifndef I2C_I2C_H_
#define I2C_I2C_H_

#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "stdbool.h"

#define Fast_Mode	1
#define Normal_Mode	0
#define read 0
#define write 1

uint16_t reg1, reg2;

typedef struct I2C_Config
{
	I2C_TypeDef *I2C;
	bool mode;

}I2C_Config;


int I2C_Master_Init(I2C_Config I2C);

void I2C_Master_Start(I2C_Config I2C);

void I2C_Master_Send_Address(I2C_Config I2C, char address);

void I2C_Master_Send_Data(I2C_Config I2C, char data);

char I2C_Master_Receive_Data(I2C_Config I2C);

void I2C_Master_Stop(I2C_Config I2C);

void I2C_Master_Send_NACK(I2C_Config I2C);

void I2C_Send_Buffer(I2C_Config I2C, uint8_t address, uint8_t *buffer, int length);

void I2C_Receive_Buffer(I2C_Config I2C, uint8_t address, uint8_t *buffer, int length);

#endif /* I2C_I2C_H_ */
