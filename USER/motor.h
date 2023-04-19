#include "timer.h"
#include "led.h"
#include "usart.h"
#include "stm32f10x.h"

#define PID_FREQ 1000
#define PWM_FREQ 20000
#define PWM_DUTY_MAX 1000

#define MOTOR_R 1.0f
#define MOTOR_L 0.01f
#define MOTOR_K 0.01f

#define KP 0.5f
#define KI 0.1f
#define KD 0.2f

void Motor_Init(void);
