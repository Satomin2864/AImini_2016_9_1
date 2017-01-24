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
// duty 下は310？
#define duty 380
#define Buffer_size 1000
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
    int16_t kyori[Buffer_size];
    int16_t ax, ay, az, gx, gy, gz;
    int16_t distance1, distance2, sub_distance;
    int16_t rori[Buffer_size];
    int16 cou = 0;
    int16 SetValue = 0;  
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
    ADC_SAR_Seq_Start();
    PWM_motor_WriteCompare1(duty);
    // main
	while(count != Buffer_size)
    //while(true)
    {
        
        
		if(isr_flag == 1)
		{
            // MPU6050の処理
            // データゲット
		    MPU6050_getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
			
            // データの格納 
			buf_a[0][count] = ax;
			buf_a[1][count] = ay;
			buf_a[2][count] = az;
			
			buf_g[0][count] = gx;
			buf_g[1][count] = gy;
			buf_g[2][count] = gz;
			
            // 差分データの確保
			/*
            if(count>0)
			{
				difference_a[0][count] = buf_a[0][count] - buf_a[0][count-1];
				difference_a[1][count] = buf_a[1][count] - buf_a[1][count-1];
				difference_a[2][count] = buf_a[2][count] - buf_a[2][count-1];
				difference_g[0][count] = buf_g[0][count] - buf_g[0][count-1];
				difference_g[1][count] = buf_g[1][count] - buf_g[1][count-1];
				difference_g[2][count] = buf_g[2][count] - buf_g[2][count-1];
			}
			*/
			
			// 出力
			//sprintf(rd,"%d,%d,%d,%d, %d ,%d \n",ax, ay, az, gx, gy, gz);			
			//UART_1_PutString(rd);
            
            
            // 距離センサ
           
            //sub_distance = ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_RETURN_STATUS);
            
            ADC_SAR_Seq_StartConvert();
			//kyori[count] = ADC_SAR_Seq_GetResult16();
            distance2 = distance1;
            distance1 = ADC_SAR_Seq_GetResult16();
            sub_distance = distance2 - distance1;
            kyori[count] = sub_distance;
            //sprintf(rd,"%d\n",sub_distance);			
			//UART_1_PutString(rd);
            
            
            // ロータリーエンコーダー
            
            cou = QuadDec_1_GetCounter();
            if(count == 10)  QuadDec_1_SetCounter(SetValue);
            //sprintf(rd,"A = %d B = %d  count = %d\n",in_A_Read(), in_B_Read(),cou);
            //UART_1_PutString(rd);
            
            
            
            
            // flag
			count++;
			isr_flag = 0;
		}
	}
    PWM_motor_WriteCompare1(0);
    // a
    while(1)
    {
         if(SW_Read() == 0) 
        {
            int i;
            int j;
            
        for(i = 0; i < Buffer_size; i++){
            sprintf(rd,"%d \t %d \t %d \n", buf_a[0][i], buf_a[1][i], buf_a[2][i]);			
		    UART_1_PutString(rd);
        }
        UART_1_PutString("\n");
        break;
        }
    }
    
    UART_1_PutString("\n");
    // g
    while(1)
    {
         if(SW_Read() == 0) 
        {
            int i;
            int j;    
            for(i = 0; i < Buffer_size; i++){
                sprintf(rd,"%d \t %d \t %d \n", buf_g[0][i], buf_g[1][i], buf_g[2][i]);			
    		    UART_1_PutString(rd);
            }
            UART_1_PutString("\n");
            break;
        }
    }
     UART_1_PutString("\n");
     // kyori
     while(1)
     {
         if(SW_Read() == 0) 
        {
            int i;
            int j;
            for(i = 0; i < Buffer_size; i++){
                sprintf(rd,"%d\n", kyori[i]);			
    		    UART_1_PutString(rd);
            }    
            break;
        }
    }
    
    // rori
     while(1)
     {
         if(SW_Read() == 0) 
        {
            int i;
            int j;
            for(i = 0; i < Buffer_size; i++){
                sprintf(rd,"%d\n", kyori[i]);			
    		    UART_1_PutString(rd);
            }    
            break;
        }
    }
    
}

/* [] END OF FILE */
