#include "main.h"
u32 i = 0;
int main(void)
{
	Init_All();
	// NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	// uart_init(115200);								
	//	while (1)
	//	{
	//		i=Encoder_Get();
	//		OLED_ShowSignedNum(2,2,i,5);
	//	}
	Map1();
}
