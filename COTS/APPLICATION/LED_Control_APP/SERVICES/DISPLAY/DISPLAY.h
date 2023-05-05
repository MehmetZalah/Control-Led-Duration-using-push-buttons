/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

typedef enum
{
	LED_USER
}tLED_x;

typedef enum
{
	LED_STATE_OFF,
	LED_STATE_ON
}tLED_STATE_x;

/*
 * Function: DISPLAY_Init
 * ----------------------------
 *	Display Intialization Module
 *
 *		@return void
 */
void DISPLAY_Init(tLED_x LED_x);

/*
 * Function: DISPLAY_ON
 * ----------------------------
 *	Display turn on
 *	@param tLED_x: LED_USER
 *
 *		@return void
 */
void DISPLAY_ON(tLED_x LED_x);

/*
 * Function: DISPLAY_OFF
 * ----------------------------
 *	Display turn off
 *	@param tLED_x: LED_USER
 *
 *		@return void
 */
void DISPLAY_OFF(tLED_x LED_x);

#endif