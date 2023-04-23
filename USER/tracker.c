#include "tracker.h"
#include <math.h>
u8 SensorB[8] = {0};
u8 SensorA[8] = {0};
u8 SensorC[4] = {0};
sc8 weight[8] = {-18, -12, -8, -4, 4, 8, 12, 18};
u32 speed = Normal;
u32 speed_L, speed_R;
void Lane_Counter_Fwd_Init(void) // 前循迹GPIO初始化
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

void Lane_Counter_Bwd_Init(void) // 后循迹GPIO初始化
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

void Cross_Detect_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	// XJ3 0
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	// XJ3 1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	// XJ3 2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	// XJ3 3
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
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

void Lane_Counter_Bwd_Read(void) // 后循迹
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

void Cross_Detect_Read(void)
{
	SensorC[0] = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12);
	SensorC[1] = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
	SensorC[2] = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14);
	SensorC[3] = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);
}

void Lane_Keep_Fwd(void)
{
	s32 error;
	Lane_Counter_Fwd_Read();
	error = SensorA[0] * weight[0] + SensorA[1] * weight[1] + SensorA[2] * weight[2] + SensorA[3] * weight[3] +
			SensorA[4] * weight[4] + SensorA[5] * weight[5] + SensorA[6] * weight[6] + SensorA[7] * weight[7];

	speed_L = speed + KP * error;
	speed_R = speed - KP * error;
	Motor_PWM(speed_L, speed_R);
	// stop
}

void Lane_Keep_Bwd(void)
{
	s32 error;
	Lane_Counter_Bwd_Read();
	error = SensorB[0] * weight[0] + SensorB[1] * weight[1] + SensorB[2] * weight[2] + SensorB[3] * weight[3] +
			SensorB[4] * weight[4] + SensorB[5] * weight[5] + SensorB[6] * weight[6] + SensorB[7] * weight[7];

	speed_L = speed  - KP * error;
	speed_R = speed  + KP * error;
	Motor_PWM(speed_L, speed_R);
	// stop
}

// void Go_Stright_Bwd(u8 num)
// {
//   // 初始化电机
//   Motor1_Bwd();
//   Motor2_Bwd();
//   speed = Normal;

//   // 确保所有传感器都被读取并更新
//   Lane_Counter_Bwd_Read();

//   // 延时等待车辆开始向后移动
//   delay_ms(100);

//   // 确保车辆已经向后移动了一定距离
//   while (Encoder_Get() < 100);

//   while (num)
//   {
//     // 读取传感器
//     u8 led_num = SensorB[0] + SensorB[1] + SensorB[2] + SensorB[3] + SensorB[4] + SensorB[5] + SensorB[6] + SensorB[7];

//     if (led_num <= 2)
//     {
//       // 如果车辆偏离轨道，停止并等待修正
//       TIM_SetCounter(TIM2, 0);
//       while (Read_Sensors_Bwd() <= 2);
//     }
//     else
//     {
//       // 按照轨道行驶
//       Lane_Keep_Bwd();
//       if (Encoder_Get() >= 700)
//       {
//         // 如果车辆已经行驶到目标位置，减速并等待修正
//         speed = Slow;
//         Lane_Keep_Bwd();
//         while (Read_Sensors_Bwd() <= 2);
//         speed = Normal;

//         // 重置编码器计数器
//         TIM_SetCounter(TIM2, 0);

//         // 进入下一个循环
//         num--;
//       }
//     }
//   }

  // 停止电机
//   Motor1_Fwd();
//   Motor2_Fwd();
// }

void Go_Stright_Fwd(u8 num)
{
	Motor1_Fwd();
	Motor2_Fwd();
	while (num)
	{
		u8 led_num = 0;
		while (1)
		{
			Lane_Counter_Fwd_Read();
			led_num = SensorA[0] + SensorA[1] + SensorA[2] + SensorA[3] + SensorA[4] + SensorA[5] + SensorA[6] + SensorA[7];
			if (led_num > 4)
			{
				Lane_Keep_Fwd();
			}
			if (led_num <= 2)
			{
				TIM_SetCounter(TIM2, 0);
				break;
			}
		}
		TIM_SetCounter(TIM2, 0);
		while (1)
		{
			if (num == 1)
			{
				speed = Slow;
				Lane_Keep_Fwd();
				if (Encoder_Get() <= -450) // 3/4 speed 700
				{
					speed = Normal;
					break;
				}
			}
			else
			{
				Lane_Keep_Fwd();
				if (Encoder_Get() <= -450)
				{
					TIM_SetCounter(TIM2, 0);
					break;
				}
			}
		}
		num--;
	}
}

void Go_Stright_Bwd(u8 num)
{
	Motor1_Bwd();
	Motor2_Bwd();
	while (num)
	{
		u8 led_num = 0;
		while (1)
		{
			Lane_Counter_Bwd_Read();
			led_num = SensorB[0] + SensorB[1] + SensorB[2] + SensorB[3] + SensorB[4] + SensorB[5] + SensorB[6] + SensorB[7];
			if (led_num > 4)
			{
				Lane_Keep_Bwd();
			}
			if (led_num <= 2)
			{
				TIM_SetCounter(TIM2, 0);
				break;
			}
		}
		TIM_SetCounter(TIM2, 0);
		while (1)
		{
			if (num == 1)
			{
				speed = Slow;
				Lane_Keep_Fwd();
				if (Encoder_Get() >= 500) // 3/4 speed 700
				{
					speed = Normal;
					break;
				}
			}
			else
			{
				Lane_Keep_Bwd();
				if (Encoder_Get() >= 500)
				{
					TIM_SetCounter(TIM2, 0);
					break;
				}
			}
		}
		num--;
	}
	Motor1_Fwd();
	Motor2_Fwd();
}

void Turn_Left(void) // 左转
{
	//	Motor_Stop();
	//	delay_ms(100);
	//	Motor_Start();
	TIM_SetCounter(TIM2, 0);
	speed = Slow;
	while (1)
	{
		Motor1_Fwd();
		Motor2_Bwd();
		if (Encoder_Get() == 1550)
		{
			Motor1_Fwd();
			Motor2_Fwd();
			speed = Normal;
			break;
		}
	}
}

void Turn_Right(void) // 右转
{
	//	Motor_Stop();
	//	delay_ms(100);
	//	Motor_Start();
	TIM_SetCounter(TIM2, 0);
	speed = Slow;
	while (1)
	{
		Motor1_Bwd();
		Motor2_Fwd();
		if (Encoder_Get() == -1800)
		{
			Motor1_Fwd();
			Motor2_Fwd();
			speed = Normal;
			break;
		}
	}
}
