#include "pid.h"

static float kp, ki, kd; // PID控制器的参数
static float error, integral, derivative, last_error; // PID控制器的变量

void pid_init(float p, float i, float d)
{
    kp = p;
    ki = i;
    kd = d;

    // 初始化PID变量
    error = 0;
    integral = 0;
    derivative = 0;
    last_error = 0;
}

float pid_calculate(float setpoint, float input)
{
    float output=0.0f;
    // 计算误差
    error = setpoint - input;

    // 计算积分项
    integral += error;

    // 计算微分项
    derivative = error - last_error;

    // 计算控制输出
    output = kp * error + ki * integral + kd * derivative;

    // 更新上一次的误差
    last_error = error;

    return output;
}
