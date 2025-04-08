#ifndef __X9C_H
#define __X9C_H

#include "main.h"
#include "delay.h"
// CS
#define CS_GPIO_PORT 	GPIOC				 /* GPIO端口 */
#define CS_GPIO_PIN 	GPIO_PIN_0			 /* 连接到SCL时钟线的GPIO */

// INC
#define INC_GPIO_PORT 	GPIOC				  /* GPIO端口 */
#define INC_GPIO_PIN 	GPIO_PIN_1			  /* 连接到SCL时钟线的GPIO */

// UD
#define UD_GPIO_PORT 	GPIOC				 /* GPIO端口 */
#define UD_GPIO_PIN 	GPIO_PIN_2			 /* 连接到SCL时钟线的GPIO */

/* 有关电位器的宏定义  使用标准的固件库控制IO*/
#define CS(a)                                    						\
	if (a)                                       						\
		HAL_GPIO_WritePin(CS_GPIO_PORT, CS_GPIO_PIN, GPIO_PIN_SET); 	\
	else                                         						\
		HAL_GPIO_WritePin(CS_GPIO_PORT, CS_GPIO_PIN, GPIO_PIN_RESET)

#define INC(a)                                     						\
	if (a)                                         						\
		HAL_GPIO_WritePin(INC_GPIO_PORT, INC_GPIO_PIN, GPIO_PIN_SET); 	\
	else                                           						\
		HAL_GPIO_WritePin(INC_GPIO_PORT, INC_GPIO_PIN, GPIO_PIN_RESET)

#define UD(a)                                    						\
	if (a)                                       						\
		HAL_GPIO_WritePin(UD_GPIO_PORT, UD_GPIO_PIN, GPIO_PIN_SET); 	\
	else                                         						\
		HAL_GPIO_WritePin(UD_GPIO_PORT, UD_GPIO_PIN, GPIO_PIN_RESET)

void X9C_Inc_N_Step(uint16_t N);
void X9C_Dec_N_Step(uint16_t N);
void Delay(unsigned int t);
void X9C_Init(void); // 初始化至中间位置
void X9C_Config(void);

#endif
