/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#include "DISPLAY.h"
#include "../../../../ECUAL/LED/LED.h"
#include "../../SERVICES/Config.h"

/*
 * Function: DISPLAY_Init
 * ----------------------------
 *	Display Intialization Module
 *
 *		@return void
 */
void DISPLAY_Init(tLED_x LED_x)
{
	switch(LED_x)
	{
		case LED_USER:
			LED_Init(LED_USER_PORT,LED_USER_PORT_PIN);			
			break;
	}
}

/*
 * Function: DISPLAY_ON
 * ----------------------------
 *	Display turn on
 *	@param tLED_x: LED_USER
 *
 *		@return void
 */
void DISPLAY_ON(tLED_x LED_x)
{
	switch(LED_x)
	{
		case LED_USER:
				LED_SetState(LED_USER_PORT,LED_USER_PORT_PIN,LED_STATE_ON);
			break;
	}
}

/*
 * Function: DISPLAY_OFF
 * ----------------------------
 *	Display turn off
 *	@param tLED_x: LED_USER
 *
 *		@return void
 */
void DISPLAY_OFF(tLED_x LED_x)
{
		switch(LED_x)
	{
		case LED_USER:
				LED_SetState(LED_USER_PORT,LED_USER_PORT_PIN,LED_STATE_OFF);
			break;
	}
}