/*********************************************************************************************************************
 * STC32G144K Opensourec Library 即（STC32G144K 开源库）是一个基于官方 SDK 接口的第三方开源库
 * Copyright (c) 2025 SEEKFREE 逐飞科技
 *
 * 本文件是STC32G144K开源库的一部分
 *
 * STC32G144K 开源库 是免费软件
 * 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
 * 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
 *
 * 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
 * 甚至没有隐含的适销性或适合特定用途的保证
 * 更多细节请参见 GPL
 *
 * 您应该在收到本开源库的同时收到一份 GPL 的副本
 * 如果没有，请参阅<https://www.gnu.org/licenses/>
 *
 * 额外注明：
 * 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
 * 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
 * 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
 * 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
 *
 * 文件名称
 * 公司名称          成都逐飞科技有限公司
 * 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
 * 开发环境          MDK FOR C251
 * 适用平台          STC32G144K
 * 店铺链接          https://seekfree.taobao.com/
 *
 * 修改记录
 * 日期              作者           备注
 * 2025-11-20        大W            first version
 ********************************************************************************************************************/
#include "zf_common_headfile.h"
#include "PD_ENC_SDI.h"
#include "var.h"
#include "Motor.h"
#include "ADC.h"

#define PIT_CH (TIM1_PIT)

// 陀螺仪型号为IMU963RA 因兼容性改为IMU660RB//
void main(void)
{

    clock_init(SYSTEM_CLOCK_96M); // 时钟配置及系统初始化<务必保留>
    debug_init();                 // 调试串口信息初始化
    gpio_init(IO_P52, GPO, 0, GPO_PUSH_PULL);
    // imu660rb_init();
    // // 此处编写用户代码 例如外设初始化代码等
    // tim0_irq_handler = pit_hanlder;
    pit_ms_init(PIT_CH, 100, ENC_handler);
    //	siai_adc_all_sample();
    my_adc_init();
    ENC_Init();
    printf("\r\nInit Success!\r\n");
    // // 此处编写用户代码 例如外设初始化代码等

    // 此处编写用户代码 例如外设初始化代码等

    while (1)
    {

        siai_adc_all_sample();
        adc_normalizing();

        printf("encoder_data_dir_1 counter %d .\r\n", -encoder_data_dir_1); // 输出编码器计数信息
        printf("encoder_data_dir_2 counter %d .\r\n", encoder_data_dir_2);  // 输出编码器计数信息

        printf("Norm: L=%.1f, M=%.1f,R=%.1f\r\n", L, M, R);
        system_delay_ms(500);
        // 此处编写需要循环执行的代码
        // printf("\r\nIMU660RB gyro data:  x=%5d, y=%5d, z=%5d\r\n", imu660rb_gyro_x, imu660rb_gyro_y, imu660rb_gyro_z);
        // printf("\r\nIMU660RB acc data:  x=%5d, y=%5d, z=%5d\r\n", imu660rb_acc_x, imu660rb_acc_y, imu660rb_acc_z);
    }
}
