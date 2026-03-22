
#include "zf_common_headfile.h"

//Motor para Control Area//
#define MAX_DUTY            ( 50 )                                               // 最大 MAX_DUTY% 占空比

#define DIR_1               ( IO_P50 ) 
#define PWM_1               ( PWMB_CH4_P34 )
                              
#define DIR_2               ( IO_P52 ) 
#define PWM_2               ( PWMD_CH4_P53 )
                              
#define DIR_3               ( IO_P75 )
#define PWM_3               ( PWMB_CH1_P74 )

int8 duty = 0;
int8 dir = 1;

// #define DIR_4               ( IO_P77 )
// #define PWM_4               ( PWMB_CH3_P76 )

//Motor para Control Area//
void Motor_Init(void)
	{
	
	gpio_init(DIR_1, GPO, GPIO_HIGH, GPO_PUSH_PULL);   // GPIO 初始化为输出 默认上拉输出高
    pwm_init(PWM_1, 17000, 0);                         // PWM 通道初始化频率 17KHz 占空比初始为 0

    gpio_init(DIR_2, GPO, GPIO_HIGH, GPO_PUSH_PULL);   // GPIO 初始化为输出 默认上拉输出高
    pwm_init(PWM_2, 17000, 0);                         // PWM 通道初始化频率 17KHz 占空比初始为 0

    gpio_init(DIR_3, GPO, GPIO_HIGH, GPO_PUSH_PULL);   // GPIO 初始化为输出 默认上拉输出高
    pwm_init(PWM_3, 17000, 0);                         // PWM 通道初始化频率 17KHz 占空比初始为 0

	}
void Motor_Control(void)
{
	        //此处编写需要循环执行的代码
        if(duty >= 0)                                                           // 正转
        {
            gpio_set_level(DIR_1, GPIO_HIGH);                                   // DIR输出高电平
            pwm_set_duty(PWM_1, duty * (PWM_DUTY_MAX / 100));                   // 计算占空比

            gpio_set_level(DIR_2, GPIO_HIGH);                                   // DIR输出高电平
            pwm_set_duty(PWM_2, duty * (PWM_DUTY_MAX / 100));                   // 计算占空比

            // gpio_set_level(DIR_3, GPIO_HIGH);                                   // DIR输出高电平
            // pwm_set_duty(PWM_3, duty * (PWM_DUTY_MAX / 100));                   // 计算占空比

        }
        
        if(dir)                                                                 // 根据方向判断计数方向 本例程仅作参考
        {
            duty ++;                                                            // 正向计数
            if(duty >= MAX_DUTY)                                                // 达到最大值
            dir = 0;                                                            // 变更计数方向
        }
        else
        {
            duty --;                                                            // 反向计数
            if(duty <= -MAX_DUTY)                                               // 达到最小值
            dir = 1;                                                            // 变更计数方向
        }
        system_delay_ms(50);

        // 此处编写需要循环执行的代码

}	
// void N_pressure_Fan_Init(void)
// {
// 	pwn_init(PWM_3);



// }