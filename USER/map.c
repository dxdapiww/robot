#include "map.h" //存放地图

void Init_All(void) // 初始化所有内容
{
	delay_init();
	Lane_Counter_Fwd_Init();
	Lane_Counter_Bwd_Init();
	Cross_Detect_Init();
	OLED_Init();
	Encoder_Init();
	// NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	// uart_init(115200);
	Motor_Init();
	TIM3_PWM_Init(400, 18); // 10khz
}

void Map1(void)
{
	Motor_Start();
	Go_Stright_Fwd(2);
	Turn_Left();
	Go_Stright_Fwd(2);
	Turn_Right();
	Go_Stright_Fwd(2);
	//	Turn_Left();
	//	Go_Stright_Fwd(6);
	//	Turn_Left();
	Motor_Stop();
}

void Map2(void)
{
	Motor_Start();
	Go_Stright_Fwd(4);
	Turn_Right();
	Go_Stright_Fwd(2);
	Turn_Right();
	Go_Stright_Fwd(2);
	//

	Motor_Stop();
	delay_ms(200);
	Motor_Start();
	Go_Stright_Bwd(4);
	//
	Turn_Left();
	Go_Stright_Fwd(2);
	Turn_Right();
	Go_Stright_Fwd(2);
	//
	Motor_Stop();
	delay_ms(200);
	Motor_Start();
	Go_Stright_Bwd(4);
	//
	Turn_Left();
	Go_Stright_Fwd(2);
	Turn_Right();
	Go_Stright_Fwd(7);
	//
	Turn_Right();
	Go_Stright_Fwd(6);
	Turn_Left();
	delay_ms(50);
	Motor_Stop();
}

void Map3(void)
{
	Motor_Start();
	Go_Stright_Fwd(8);
	Motor_Stop();
}

void Map4(void)
{
	int path[][2] = {{0, 0}, {4, 0}, {4, 2}, {6, 2}, {6, 0}, {2, 0}, {2, 2}, {4, 2}, {4, 9}, {10, 9}, {10, 3}, {4, 3}, {4, 0}};
	int i = 0;
	Motor_Start();
	for (i = 0; i < sizeof(path) / sizeof(path[0]) - 1; i++)
	{
		int dx = path[i + 1][0] - path[i][0];
		int dy = path[i + 1][1] - path[i][1];
		if (dx > 0)
		{
			Go_Stright_Fwd(dx);
		}
		else if (dx < 0)
		{
			Go_Stright_Bwd(-dx);
		}
		if (dy > 0)
		{
			Turn_Left();
			Go_Stright_Fwd(dy);
			Turn_Right();
		}
		else if (dy < 0)
		{
			Turn_Right();
			Go_Stright_Fwd(-dy);
			Turn_Left();
		}
	}
	Motor_Stop();
}

