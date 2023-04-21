#include "timer.h"
#include "led.h"
#include "usart.h"
#include "stm32f10x.h"
#include "motor.h"
#include "OLED.h"
#include "Encoder.h"
#include "motor.h"

void Lane_Counter_Fwd_Init(void); //??????
void Lane_Counter_Back_Init(void);
void Lane_Keep_Fwd(void);
void Lane_Counter_Fwd_Read(void);
void Go_Stright_Fwd(u8 num);
void Cross_Detect_Init(void);
void Cross_Detect_read(void);

