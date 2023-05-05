/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#ifndef __INPUT_SERVICE_H__
#define __INPUT_SERVICE_H__

typedef enum
{
	INPUT_STATE_PRESSED,
	INPUT_STATE_RELEASE
}tINPUT_STATE_x;

typedef enum
{
	INPUT_ONSWITCH,
	INPUT_OFFSWITCH
}tINPUT_xSWITCH;

typedef void(*cbType)(void);
void INPUT_cb_register(cbType ptr);


/*
 * Function: INPUT_Init
 * ----------------------------
 *	Initialize INPUT Module
 *
 *		@return void
 */
void INPUT_Init(tINPUT_xSWITCH INPUT_xSWITCH);


/*
 * Function: INPUT_GetState
 * ----------------------------
 *	Get Input state pressed/released
 *	@param tINPUT_xSWITCH: INPUT_ONSWITCH, INPUT_OFFSWITCH
 *
 *		@return tINPUT_STATE_x: INPUT_STATE_PRESSED, INPUT_STATE_RELEASED
 */
tINPUT_STATE_x INPUT_GetState(tINPUT_xSWITCH INPUT_xSWITCH);

void INPUT_ClearFlag(tINPUT_xSWITCH INPUT_xSWITCH);
#endif