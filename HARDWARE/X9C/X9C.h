#ifndef __X9C_H
#define __X9C_H

#include "main.h"
#include "delay.h"
// CS
#define CS_GPIO_PORT 	GPIOC				 /* GPIO�˿� */
#define CS_GPIO_PIN 	GPIO_PIN_0			 /* ���ӵ�SCLʱ���ߵ�GPIO */

// INC
#define INC_GPIO_PORT 	GPIOC				  /* GPIO�˿� */
#define INC_GPIO_PIN 	GPIO_PIN_1			  /* ���ӵ�SCLʱ���ߵ�GPIO */

// UD
#define UD_GPIO_PORT 	GPIOC				 /* GPIO�˿� */
#define UD_GPIO_PIN 	GPIO_PIN_2			 /* ���ӵ�SCLʱ���ߵ�GPIO */

/* �йص�λ���ĺ궨��  ʹ�ñ�׼�Ĺ̼������IO*/
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
void X9C_Init(void); // ��ʼ�����м�λ��
void X9C_Config(void);

#endif
