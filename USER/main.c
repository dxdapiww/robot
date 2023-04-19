#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "tracker.h"
#include "motor.h"
/************************************************
 ALIENTEK��ӢSTM32������ʵ��9
 PWM���ʵ��
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{
	u16 led0pwmval = 0;
	//u8 dir = 1;
	delay_init();									// ��ʱ������ʼ��
	Lane_Counter_Fwd_Init();
	Lane_Coutner_Back_Init();
	Motor_Init();
	TIM4_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // ����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);								// ���ڳ�ʼ��Ϊ115200
	//LED_Init();										// LED�˿ڳ�ʼ��
	TIM3_PWM_Init(7199, 0);							// ����Ƶ��PWMƵ��=72000000/900=80Khz

	while (1)
	{
		TIM_SetCompare2(TIM3, 3600);
		TIM_SetCompare1(TIM3, 3600);
		printf("1\n");
	}
}
