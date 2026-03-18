#ifndef __IMU_H_
#define __IMU_H_

//角度获取
extern float gyro_z[2], next_gyro_z;			//(被测)Z轴角速度
extern float angle_ringR;

extern float null_drift_z;
extern float avl_gyro_z;  //测量-零漂

void tuoluo_init(void);
void gyroscope_get_gyro(void);		//角速度获取
void angle_get(void);							//角度获取
void angle_clear(void);						//角度清零
 
int8 null_drift_calculate(void);	//零漂解算
#endif