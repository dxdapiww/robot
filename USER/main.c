#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "tracker.h"
#include "motor.h"
#include "pid.h"
#include "Encoder.h"
#include "OLED.h"
/************************************************
 ALIENTEK精英STM32开发板实验9
 PWM输出实验
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/
u32 speed = 3600;

int main(void)
{
	//u16 led0pwmval = 0;
	//u8 dir = 1;
	delay_init();									// 延时函数初始化
	Lane_Counter_Fwd_Init();
	Lane_Coutner_Back_Init();
	OLED_Init();
	Encoder_Init();
	Motor_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);								// 串口初始化为115200
	//LED_Init();										// LED端口初始化
	TIM3_PWM_Init(7199, 0);							// 不分频。PWM频率=72000000/900=80Khz
	while (1)
	{
		Motor_PWM(3600,3600);
		// i=Encoder_Get();
		// OLED_ShowSignedNum(2,2,i,5);
		//Go_Stright_Fwd(4);
		// TIM_SetCompare2(TIM3, speed);
		// TIM_SetCompare1(TIM3, speed);
		// printf("1\n");
	}
}
