#include "pid.h"

static float kp, ki, kd; // PID�������Ĳ���
static float error, integral, derivative, last_error; // PID�������ı���

void pid_init(float p, float i, float d)
{
    kp = p;
    ki = i;
    kd = d;

    // ��ʼ��PID����
    error = 0;
    integral = 0;
    derivative = 0;
    last_error = 0;
}

float pid_calculate(float setpoint, float input)
{
    float output=0.0f;
    // �������
    error = setpoint - input;

    // ���������
    integral += error;

    // ����΢����
    derivative = error - last_error;

    // ����������
    output = kp * error + ki * integral + kd * derivative;

    // ������һ�ε����
    last_error = error;

    return output;
}
