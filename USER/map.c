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
