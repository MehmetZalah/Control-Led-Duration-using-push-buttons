/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#ifndef __TIME_CONFIG_H__
#define __TIME_CONFIG_H__

#include "../../../../MCAL/SYSTICK/SYSTICK.h"

/*
 * Function: TIME_Wait_Seconds
 * ----------------------------
 *	Wait function in Seconds
 *	@param uint8_t: time in seconds
 *
 *		@return void
 */
void TIME_Wait_Seconds(uint8_t time);

#endif