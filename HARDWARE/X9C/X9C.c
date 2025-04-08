#include "X9C.h"

/*��ʼ��X9C�ܽ�*/
void X9C_Config(void)
{
	
  GPIO_InitTypeDef GPIO_Initure;
    
  __HAL_RCC_GPIOC_CLK_ENABLE();   //ʹ��GPIOBʱ��
    
  GPIO_Initure.Pin=CS_GPIO_PIN|INC_GPIO_PIN|UD_GPIO_PIN;
  GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //�������
  GPIO_Initure.Pull=GPIO_PULLUP;          //����
  GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
  HAL_GPIO_Init(GPIOC,&GPIO_Initure);

  HAL_GPIO_WritePin(GPIOC, CS_GPIO_PIN|INC_GPIO_PIN|UD_GPIO_PIN, GPIO_PIN_RESET);  
}

//��ʱus�ӳ��� 
void Delay(unsigned int t) 
{ 
	unsigned int i; 
	for(i=0;i<t;i++) ;
} 

//************************************************************************
// ���ֵ�λ�����ϵ�һ��
// ���ֵ�λ��100����ͷ���൱��99��
//************************************************************************
void X9C_Inc_N_Step(uint16_t N)
{
   unsigned char i=0; 
          
        
        UD(1);              	// U/D ����   �������INC���أ�ִ��UP����  
        delay_us(1);        	// ��ʱ��Լ2us
		CS(0);              	// CS  ����
	
        for(i = N; i>0; i--)
        {
            INC(0);         	// ��ΪGPIO��ʼ��ʱ��INC�Ѿ������ˡ�INC ����;  // ����һ������
            delay_us(1);    	// ��ʱ2us����
            INC(1);         	// ����INC //����ģʽ
			delay_us(100);  	// ��ʱ��Լ500us, Rw�ȴ�����ȶ�
        }
        CS(1);              	// ���CS���� //store

}
//************************************************************************
// ���ֵ�λ�����µ�һ��
// ���ֵ�λ��100����ͷ���൱��99��
//************************************************************************
void X9C_Dec_N_Step(uint16_t N)
{
   unsigned char i=0; 
	
    UD(0);               		//CLRB_X9C103_UD;   // U/D ��0��  �������INC���أ�ִ��Down����  
    delay_us(1);            	// ��ʱ��Լ2us
    CS(0);  
 
   for(i=N;i>0;i--) 
   {  
		INC(1);               	// ����INC    ��ΪINC��������Ч
		delay_us(1);          	// ��ʱ2us����
		INC(0);               	// INC ����;  // ����һ������
		delay_us(100);        	// ��ʱ��Լ500us, Rw�ȴ�����ȶ�
   }
     INC(0);					//����ģʽ
     CS(1);                 	//���CS���� // store 
}

void X9C_Init(void)				//��ʼ�����м�λ��
{
	X9C_Config();
	X9C_Inc_N_Step(100);
	X9C_Dec_N_Step(49); 
} 
