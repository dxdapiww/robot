#include "timer.h"
#include "led.h"
#include "usart.h"
#include "stm32f10x.h"
#include "Encoder.h"
#include "delay.h"

#define PID_FREQ 1000
#define PWM_FREQ 20000
#define PWM_DUTY_MAX 1000

#define MOTOR_R 1.0f
#define MOTOR_L 0.01f
#define MOTOR_K 0.01f

#define KP 25.0f
#define KI 0.1f
#define KD 0.2f

void Motor_Init(void);
void Motor_Stop(void);
void Motor_PWM(u32 left_speed,u32 right_speed);
void Turn_Left(void);