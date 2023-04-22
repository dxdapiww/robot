#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
#define PID_FREQ 1000


void TIM4_Init(void);
void TIM3_Int_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
#endif
