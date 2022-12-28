/*
 * labyrinthe.c
 *
 *  Created on: 30 nov. 2022
 *      Author: flavi
 */


#include "stm32f1xx_hal.h"
#include "WS2812S.h"
#include "WS2812B.h"
#include "config.h"
#include "macro_types.h"
#include "stm32f1_gpio.h"
#include "labyrinthe.h"


#define COLOR_RED	0x00FF00
#define T1H		1
#define T1L		1
#define T0H		0
#define T0L		1
#define RES     200
void murs_init();

void murs_init(){

	//short red;
	uint8_t i;
	LED_MATRIX_init();
	//uint32_t pixels[64];
	uint32_t matrice[64]={0,1,3,1,0,0,0,0,
						  0,1,0,1,0,0,0,0,
						  0,1,0,1,0,0,0,0,
						  0,1,0,1,1,1,1,1,
						  0,1,0,0,0,0,0,1,
						  0,1,1,1,1,1,0,1,
						  0,0,0,0,0,1,0,1,
						  0,0,0,0,0,1,2,1};


	for(i=0;i<64;i++){
		//LED_MATRIX_send_pixel(1);
		if(matrice[i]==1){
			//WS2812S_send_pixel(red[i], LED_MATRIX_PIN_DATA, (uint32_t *)&LED_MATRIX_PORT_DATA->BSRR);
			//LED_MATRIX_display(i, 64);
			matrice[i]=0x00FF00;
		}
		else if(matrice[i]==2){
			matrice[i]=0xFF0000;
		}
		else if(matrice[i]==3){
			matrice[i]=0x0000FF;
		}
		else{
			matrice[i]=0x000000;
		}
	}
	LED_MATRIX_display(matrice, 64);
}

