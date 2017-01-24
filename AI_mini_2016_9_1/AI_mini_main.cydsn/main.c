/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include "MPU6050/MPU6050.h"
// duty 下410でコース完走可
#define duty 380
#define Buffer_size 600
#define Range_a 2
#define Range_g 0
int isr_flag = 0;
CY_ISR(isr_int){
    isr_flag = 1;
}
int main()
{
    // 変数
    // uint16 pwr=130;
	uint8_t finish = 0;
	uint16_t i = 0,count = 0;
	int16_t buf_a[3][Buffer_size];
	int16_t buf_g[3][Buffer_size];
	int16_t difference_a[3][Buffer_size];
	int16_t difference_g[3][Buffer_size];
	int16_t filter_buf_a[3][Buffer_size];
	int16_t filter_buf_g[3][Buffer_size];
    int16_t ax, ay, az, gx, gy, gz;
    int16_t distance1, distance2, sub_distance;
    int16_t up_gz, down_gz;
    int16 cou = 0;
    int16 SetValue = 0;
    int stop = 0;
    int check_gy = 0, check_down_gz = 0, check_up_gz = 0, check_gx = 0;
	char rd[30];
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    // コンポーネット初期化
    QuadDec_1_Start();
    I2C_Start();
	CyDelay(3000);
    PWM_motor_Start();
	UART_1_Start();
    MPU6050(0x68);
    MPU6050_initialize();
	isr_flag_Start();
    isr_flag_StartEx(isr_int);
	MPU6050_setFullScaleAccelRange(Range_a);
	MPU6050_setFullScaleGyroRange(Range_g);
    MPU6050_getXAccelOffset();
    MPU6050_getYAccelOffset();
    MPU6050_getZAccelOffset();
    MPU6050_getXGyroOffset();
    MPU6050_getYGyroOffset();
    MPU6050_getZGyroOffset();
    //ADC_SAR_Seq_Start();
     ADC_SAR_Seq_Start();
    // main
	//while(count != Buffer_size)
	while(1)
    {
        
        
		if(isr_flag == 1)
		{
            // データゲット
            
            // MPU6050の処理
		    MPU6050_getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

            // 距離センサ
            // 距離センサ
           
            //sub_distance = ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_RETURN_STATUS);
            
            ADC_SAR_Seq_StartConvert();
			//kyori[count] = ADC_SAR_Seq_GetResult16();
            distance2 = distance1;
            distance1 = ADC_SAR_Seq_GetResult16();
            sub_distance = distance2 - distance1;
            
            //sprintf(rd,"%d\n",sub_distance);			
			//UART_1_PutString(rd);
                    
            // ロータリーエンコーダー
            cou = QuadDec_1_GetCounter();
            if(cou == 100)  QuadDec_1_SetCounter(SetValue);
           
            // flag
			isr_flag = 0;
            
            // 速度制御
            // 9/1
            // 安定版 
            /*
            if(gy >= 25000 && check < 10)
            {
                gy = 26000;
                check++;
            }
            else
            {
                check = 0;   
            }
            if(sub_distance > 750 && gy == 26000)
            {
                PWM_motor_WriteCompare1(duty - 300);
            }
            else
            {
                PWM_motor_WriteCompare1(duty);   
            }
            */
            //gx
            if((gx <= -25000 || gx >= 25000) && check_gx < 500)
            {
                gx = 26000;
                check_gx++;
            }
            else check_gx = 0;
           
           
            //gy
            if((gy >=  3000  )&& check_gy < 100000)
            {
                gy = 26000;
                check_gy++;
            }
            else
            {
                check_gy = 0;   
            }
            
            // 完成
            
            
            if(distance1 < 200){
                PWM_motor_WriteCompare1(duty - 180);   
            }
            else if(gz > 20000 || gz <  -15000)
            {
                PWM_motor_WriteCompare1(duty - 100);
            }
            else if(distance1 < 1100 && distance1 > 850)
            {
                PWM_motor_WriteCompare1(duty + 400);   
            }
            else if(sub_distance > 850 && gy == 26000 && stop < 100)
            {
                PWM_motor_WriteCompare1(duty - 120);
                //stop++;
            }
            else
            {
                PWM_motor_WriteCompare1(duty);

            }
            
            
            // mi完成
            /*
            if(sub_distance > 850 && gy == 26000 )
            {
                PWM_motor_WriteCompare1(duty - 150);
                //stop++;
            }
            else if(gy == 26000)
            {
                PWM_motor_WriteCompare1(duty + 140);   
            }
            
            else if(distance1 > 1200)
            {
                PWM_motor_WriteCompare1(duty - 150);
            }
            else if(gx == 26000)
            {
                PWM_motor_WriteCompare1(duty + 100);   
            }
            else if(check_down_gz > 1 && check_up_gz > 1)
            {
                // 120
                PWM_motor_WriteCompare1(duty + 150);
            }
            
            else if(gz > 20000 || gz < -20000)
            {
                PWM_motor_WriteCompare1(duty - 110);   
            }
                    
            else
            {
                PWM_motor_WriteCompare1(duty );

            }
            */
            
            // 8/31
            //元安定版
            /*
            if(distance > 1500){
                PWM_motor_WriteCompare1(duty - 200);
            }
            else if(gz>23000 || gz < -14000)
            {
                PWM_motor_WriteCompare1(duty - 200);   
            }
            else
            {
                PWM_motor_WriteCompare1(duty);     
            }
            */
            
            //　安定版
            /*
            if(distance1 < 1300 && distance1 > 1050)
            {
                PWM_motor_WriteCompare1(duty + 110);
            }
            else if(distance1 >= 1500){
                PWM_motor_WriteCompare1(duty - 150);
            }
            else if(gz>23000 || gz < -14000)
            {
                PWM_motor_WriteCompare1(duty - 200);   
            }
            else
            {
                PWM_motor_WriteCompare1(duty);
            }
            */
            
            //調整中
            /*
             if(distance < 1400 && distance > 1000)
            {
                PWM_motor_WriteCompare1(duty + 100);
            }
            else if(distance >= 1500){
                PWM_motor_WriteCompare1(duty - 230);
            }
            else if(gz>23000 || gz < -14000)
            {
                PWM_motor_WriteCompare1(duty - 200);   
            }
            else
            {
                PWM_motor_WriteCompare1(duty);
            }
            */
		}
	}
}

/* [] END OF FILE */
