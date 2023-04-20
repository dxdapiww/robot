#include "motor.h"
/* Global variables */
float set_speed = 0.0f;
float curr_speed = 0.0f;
float error = 0.0f;
float error_sum = 0.0f;
float error_diff = 0.0f;
float last_error = 0.0f;
float pid_output = 0.0f;
float pwm_output = 0.0f;
float adc_value = 0.0f;
float motor_voltage = 0.0f;
float motor_current = 0.0f;

void Motor_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_SetBits(GPIOG, GPIO_Pin_10);//信号线
	GPIO_ResetBits(GPIOG, GPIO_Pin_9);
	GPIO_SetBits(GPIOD, GPIO_Pin_6);
	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
}

void PID_Speed_Control()
{
	while (1) {
    /* Read ADC value */
    // ADC_SoftwareStartConvCmd(ADC1, ENABLE);
    // while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
    // adc_value = ADC_GetConversionValue(ADC1);

    /* Calculate motor speed */
    curr_speed = (adc_value / 4096.0f) * 3.3f / MOTOR_K;

    /* Calculate PID output */
    error = set_speed - curr_speed;
    error_sum += error;
    error_diff = error - last_error;
    pid_output = KP * error + KI * error_sum + KD * error_diff;
    last_error = error;

    /* Calculate PWM output */
    motor_voltage = pid_output;
    motor_current = (motor_voltage - curr_speed * MOTOR_R) / MOTOR_L;
    pwm_output = PWM_DUTY_MAX * motor_current / 3.3f;

    /* Set PWM duty cycle */
    TIM_SetCompare1(TIM3, (uint16_t)pwm_output);

    /* Wait for next PID cycle */
    delay_ms(1000 / PID_FREQ);
  }
}

void Motor_Stop(void)
{
	TIM_SetCompare2(TIM3, 0);
	TIM_SetCompare1(TIM3, 0);
}

void Motor_PWM(u32 left_speed,u32 right_speed)
{
	TIM_SetCompare2(TIM3, left_speed);
	TIM_SetCompare1(TIM3, right_speed);
}

void Turn_Let(void)
{
	GPIO_ResetBits(GPIOG, GPIO_Pin_10);//信号线
	GPIO_SetBits(GPIOG, GPIO_Pin_9);
	GPIO_SetBits(GPIOD, GPIO_Pin_6);
	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
	TIM_SetCounter(TIM2,0);
	while(Encoder_Get()<1700)
	{

	}
}
