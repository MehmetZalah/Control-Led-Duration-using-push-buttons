/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 
 
#include "INPUT.h"
#include "../../SERVICES/Config.h"
#include "../../../../ECUAL/BUTTON/BUTTON.h"
#include "../../../../MCAL/INTERRUPT/interrupt.h"

/*
 * Function: INPUT_Init
 * ----------------------------
 *	Initialize INPUT Module
 *
 *		@return void
 */
void INPUT_Init(tINPUT_xSWITCH INPUT_xSWITCH)
{	
	switch(INPUT_xSWITCH)
	{
		case INPUT_ONSWITCH:
			BTN_Init(INPUT_ONSWITCH_PORT,INPUT_ONSWITCH_PORT_PIN);
			break;
		case INPUT_OFFSWITCH:
			BTN_Init(INPUT_OFFSWITCH_PORT,INPUT_OFFSWITCH_PORT_PIN);
			break;
	}
}

/*
 * Function: INPUT_GetState
 * ----------------------------
 *	Get Input state pressed/released
 *	@param tINPUT_xSWITCH: INPUT_ONSWITCH, INPUT_OFFSWITCH
 *
 *		@return tINPUT_STATE_x: INPUT_STATE_PRESSED, INPUT_STATE_RELEASED
 */
tINPUT_STATE_x INPUT_GetState(tINPUT_xSWITCH INPUT_xSWITCH)
{
	switch(INPUT_xSWITCH)
	{
		case INPUT_ONSWITCH:
			if(BTN_GetState(INPUT_ONSWITCH_PORT,INPUT_ONSWITCH_PORT_PIN) == BTN_PRESSED)
			{
				return INPUT_STATE_PRESSED;
			}
			else
			{
				return INPUT_STATE_RELEASE;
			}
		
		case INPUT_OFFSWITCH:
			if(BTN_GetState(INPUT_OFFSWITCH_PORT,INPUT_OFFSWITCH_PORT_PIN) == BTN_PRESSED )
			{
				return INPUT_STATE_PRESSED;
			}
			else
			{
				return INPUT_STATE_RELEASE;
			}
	}
}

void INPUT_ClearFlag(tINPUT_xSWITCH INPUT_xSWITCH)
{
	switch(INPUT_xSWITCH)
	{
		case INPUT_ONSWITCH:
			INTERRRUPT_ClearFlag(INPUT_ONSWITCH_PORT,INPUT_ONSWITCH_PORT_PIN);
		break;
		
		case INPUT_OFFSWITCH:
			INTERRRUPT_ClearFlag(INPUT_OFFSWITCH_PORT,INPUT_OFFSWITCH_PORT_PIN);
		break;
	}
}