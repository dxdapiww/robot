#ifndef __TRACKER_H
#define __TRACKER_H

#include "stm32f10x.h"
#include "motor.h"

void Lane_Counter_Fwd_Init(void);
void Lane_Counter_Bwd_Init(void);
void Lane_Keep_Fwd(void);
void Lane_Counter_Fwd_Read(void);
void Go_Stright_Fwd(u8 num);
void Cross_Detect_Init(void);
void Cross_Detect_read(void);
void Go_Stright_Bwd(u8 num);
void Lane_Keep_Bwd(void);

#endif


