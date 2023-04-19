#include "timer.h"
#include "led.h"
#include "usart.h"
#include "tracker.h"
u8 SensorB[8] = {0};
u8 SensorA[8] = {0};
s8 weight[8] = {-20,-15,-10,-5,5,10,15,20};
void Lane_Counter_Fwd_Init(void)//前循迹GPIO初始化
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB |
							   RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOE,
						   ENABLE);
	// XJ1 0
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// XJ1 1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// XJ1 2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// XJ1 3
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// XJ1 4
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	// XJ1 5
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	// XJ1 6
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	// XJ1 7
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void Lane_Coutner_Back_Init(void)//后循迹GPIO初始化
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG, ENABLE);

	// XJ2 0
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOF, &GPIO_InitStructure);

	// XJ2 1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;

	// XJ2 2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	// XJ2 3
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOG, &GPIO_InitStructure);

	// XJ2 4
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOG, &GPIO_InitStructure);

	// XJ2 5
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	// XJ2 6
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOF, &GPIO_InitStructure);

	// XJ2 7
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
}


void Lane_Counter_Fwd_Read(void) // 前循迹
{
	SensorA[0] = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
	SensorA[1] = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5);
	SensorA[2] = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6);
	SensorA[3] = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7);
	SensorA[4] = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4);
	SensorA[5] = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);
	SensorA[6] = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0);
	SensorA[7] = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1);
}

void Lane_Counter_Back_Read(void)//后循迹
{
	SensorB[0] = GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_13);
	SensorB[1] = GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_14);
	SensorB[2] = GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_15);
	SensorB[3] = GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_0);
	SensorB[4] = GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_1);
	SensorB[5] = GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_7);
	SensorB[6] = GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_11);
	SensorB[7] = GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_12);
}
void Lane_Keep_Fwd(void)
{
	while(1)
	{
		s32 error = SensorA[0]*weight[0]+SensorA[1]*weight[1]+SensorA[2]*weight[2]+SensorA[3]*weight[3]+
					SensorA[4]*weight[4]+SensorA[5]*weight[5]+SensorA[6]*weight[6]+SensorA[7]*weight[7];
		if(!error) break;
		if(error<0)
		{

		}
		else if(error>0)
		{
			
		}
	}
	//stop
}
