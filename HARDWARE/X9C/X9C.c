#include "X9C.h"

/*初始化X9C管脚*/
void X9C_Config(void)
{
	
  GPIO_InitTypeDef GPIO_Initure;
    
  __HAL_RCC_GPIOC_CLK_ENABLE();   //使能GPIOB时钟
    
  GPIO_Initure.Pin=CS_GPIO_PIN|INC_GPIO_PIN|UD_GPIO_PIN;
  GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
  GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
  GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //快速
  HAL_GPIO_Init(GPIOC,&GPIO_Initure);

  HAL_GPIO_WritePin(GPIOC, CS_GPIO_PIN|INC_GPIO_PIN|UD_GPIO_PIN, GPIO_PIN_RESET);  
}

//延时us子程序 
void Delay(unsigned int t) 
{ 
	unsigned int i; 
	for(i=0;i<t;i++) ;
} 

//************************************************************************
// 数字电位器向上调一步
// 数字电位器100个抽头，相当于99步
//************************************************************************
void X9C_Inc_N_Step(uint16_t N)
{
   unsigned char i=0; 
          
        
        UD(1);              	// U/D 拉高   则下面的INC下沿，执行UP操作  
        delay_us(1);        	// 延时大约2us
		CS(0);              	// CS  拉低
	
        for(i = N; i>0; i--)
        {
            INC(0);         	// 因为GPIO初始化时，INC已经拉高了。INC 拉低;  // 产生一个下沿
            delay_us(1);    	// 延时2us左右
            INC(1);         	// 拉高INC //保存模式
			delay_us(100);  	// 延时大约500us, Rw等待输出稳定
        }
        CS(1);              	// 完毕CS拉高 //store

}
//************************************************************************
// 数字电位器向下调一步
// 数字电位器100个抽头，相当于99步
//************************************************************************
void X9C_Dec_N_Step(uint16_t N)
{
   unsigned char i=0; 
	
    UD(0);               		//CLRB_X9C103_UD;   // U/D 清0，  则下面的INC下沿，执行Down操作  
    delay_us(1);            	// 延时大约2us
    CS(0);  
 
   for(i=N;i>0;i--) 
   {  
		INC(1);               	// 拉高INC    因为INC的下沿有效
		delay_us(1);          	// 延时2us左右
		INC(0);               	// INC 拉低;  // 产生一个下沿
		delay_us(100);        	// 延时大约500us, Rw等待输出稳定
   }
     INC(0);					//保存模式
     CS(1);                 	//完毕CS拉高 // store 
}

void X9C_Init(void)				//初始化至中间位置
{
	X9C_Config();
	X9C_Inc_N_Step(100);
	X9C_Dec_N_Step(49); 
} 
