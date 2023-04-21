#include "map.h" //存放地图

void Init_All(void)//初始化所有内容
{
	delay_init();
	Lane_Counter_Fwd_Init();
	Lane_Counter_Back_Init();
	Cross_Detect_Init();
	OLED_Init();
	Encoder_Init();
	TIM3_PWM_Init(99, 72);//10khz
	Motor_Init();
}

void Map1(void)
{
	Motor_Start();
	Go_Stright_Fwd(5);
	Turn_Left();
	Go_Stright_Fwd(5);
	Turn_Left();
	Go_Stright_Fwd(5);
	Turn_Left();
	Go_Stright_Fwd(5);
	Turn_Left();
	Motor_Stop();
}