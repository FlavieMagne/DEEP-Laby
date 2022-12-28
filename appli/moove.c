/*
 * moove.c
 *
 *  Created on: 30 nov. 2022
 *      Author: flavi
 */

#include "stm32f1xx_hal.h"
#include "WS2812S.h"
#include "config.h"
#include "macro_types.h"
#include "stm32f1_gpio.h"
#include "labyrinthe.h"
#include "moove.h"


#define COLOR_RED	0x00FF00
#define T1H		1
#define T1L		1
#define T0H		0
#define T0L		1
#define RES     200

void right(void);
void left(void);

void right(void){
	uint8_t j;
	uint8_t i;
	murs_init();
	uint32_t matrice2[64]={0,0,2,0,0,0,0,0,
						   0,0,2,0,0,0,0,0,
						   0,0,2,0,0,0,0,0,
						   0,0,2,0,0,0,0,0,
						   0,0,2,2,2,2,2,0,
						   0,0,0,0,0,0,2,0,
						   0,0,0,0,0,0,2,0,
						   0,0,0,0,0,0,2,0};




			for(i=0;i<64;i++){
						if(matrice2[i]==2){
							matrice2[i]=0xFF0000;
						}
						else{
							matrice2[i]=0x000000;
						}
			//}
			//for(j=1;j<36;j+=8){
				//matrice2[j]=0x0FF000;
				//Delay_us(1000);
			//}

				while(matrice2[i]==2){
					LED_MATRIX_send_pixel(1);
					if(matrice2[i]==2){
						LED_MATRIX_send_pixel(matrice2[i]);
						LED_MATRIX_display(matrice2[i], 64);

				//matrice2[j]=0x0FF000;
				//	LED_MATRIX_display(matrice2[j], 64);
				//	Delay_us(10000);
					}
					}

			LED_MATRIX_display(matrice2, 64);
	}


}

void left(void){

}

void jules(void){
	//LED_MATRIX_init();
	uint8_t i;
	uint32_t matJules[64]={0,0,2,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,3};

	for(i=2; i<64; i+9){
		if (matJules[i]==2){
			matJules[i]= 0xFF0000;
			LED_MATRIX_display(matJules[i], 64);
			Delay_us(1000);
			matJules[i]=0;
		}
	}
}

