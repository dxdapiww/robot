#ifndef __MOTOR_H
#define __MOTOR_H

#include "timer.h"
#include "led.h"
#include "usart.h"
#include "stm32f10x.h"
#include "Encoder.h"
#include "delay.h"

#define PID_FREQ 1000
#define PWM_FREQ 20000
#define PWM_DUTY_MAX 1000

#define MOTOR_R 1.5f
#define MOTOR_L 0.01f
#define MOTOR_K 0.01f

#define KP 6.0f  //0.75f 3/4
#define KI 0.1f
#define KD 0.2f

#define Normal 40 // 100-value = 占空比
#define Max 1
#define Slow 120
void Motor_Init(void);
void Motor_Stop(void);
void Motor_PWM(u32 left_speed, u32 right_speed);

void Motor_Start(void);
void Motor1_Fwd(void);
void Motor1_Bwd(void);
void Motor2_Fwd(void);
void Motor2_Bwd(void);

#endif
