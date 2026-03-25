#ifndef __PID_Para_H_
#define __PID_Para_H_

#include "zf_common_headfile.h"




#define large_t (0.02*1)
#define small_t (0.02*0.5)

/*********PID*********/

extern struct PID pid_motor_straight;
extern struct PID pid_motor_turn;

extern struct PID pid_loop_speed_start;	
extern struct PID pid_loop_speed_run;					

extern struct PID pid_motor_ringR;
extern struct PID pid_loop_angle;
extern struct PID pid_loop_gyro;

extern float limit_gyro;

extern float angle_start;
extern struct PID pid_loop_angle_start;				//角度环
extern struct PID pid_loop_angle_ring;				//角度环

//循迹
extern struct PID pid_motor_run;
extern struct PID pid_loop_speed;

//差比和差
extern float A_;
extern float B_;
extern float C_;
extern float D_;
extern float K_;
extern float F_;

extern float A_dianci,B_dianci,C_dianci,all_dianci;
extern float k;


//目标速度
extern int16 speed_target;
extern int16 speed_straight,speed_turn,speed_ringR;
//电磁误差
extern float err_dianci;

extern int8 element;

//环岛
extern int32 distance_ringR;
extern int16 ring_flag_ing,ringR_flag_task,ringR_flag_execute;
extern float gyro_adv_out;
extern float limit_gyro_t;


//环内切1
extern int16 distance_ringR_1;
extern int16 gyro_ring_in;
extern int16 gyro_ring_middle;
extern int16 gyro_ring_out;

//环循迹2
extern int16 distance_ringR_trace;
extern int16 gyro_ring_in_trace;
extern int16 gyto_ring_out_trace;
















extern int8 turn_flag;

extern float ring_L_L;
extern float ring_L_M;

extern float ring_R_M;
extern float ring_R_R;



//循迹
void dianci_xunji(void);				//*总循迹流程*
void ringR_task(void);					//环岛状态机
void ringR_execute(void);				//环岛执行机

void ringL_task(void);
void ringL_execute(void);

void ringR_task_trace(void);					//环岛状态机
void ringR_execute_trace(void);				//环岛执行机

void ringL_task_trace(void);
void ringL_execute_trace(void);



#endif