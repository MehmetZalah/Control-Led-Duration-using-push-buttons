/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#include "TIME.h"

/*
 * Function: TIME_Wait_Seconds
 * ----------------------------
 *	Wait function in Seconds
 *	@param uint8_t: time in seconds
 *
 *		@return void
 */
void TIME_Wait_Seconds(uint8_t time)
{	
	SYSTICK_Wait(time*1000);
}