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
 ALIENTEK��ӢSTM32������ʵ��9
 PWM���ʵ��
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
u32 speed = 3600;
u32 i =1;
int main(void)
{
	//u16 led0pwmval = 0;
	//u8 dir = 1;
	delay_init();									// ��ʱ������ʼ��
	Lane_Counter_Fwd_Init();
	Lane_Coutner_Back_Init();
	OLED_Init();
	Encoder_Init();
	Motor_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // ����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);								// ���ڳ�ʼ��Ϊ115200
	//LED_Init();										// LED�˿ڳ�ʼ��
	TIM3_PWM_Init(7199, 0);							// ����Ƶ��PWMƵ��=72000000/900=80Khz
	while (1)
	{
		Motor_PWM(3600,3600);
		i=Encoder_Get();
		OLED_ShowSignedNum(2,2,i,5);
		//Go_Stright_Fwd(4);
		// TIM_SetCompare2(TIM3, speed);
		// TIM_SetCompare1(TIM3, speed);
		// printf("1\n");
	}
}
