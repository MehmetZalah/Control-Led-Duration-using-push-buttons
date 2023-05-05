/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/PORT/port.h"

typedef enum
{
	BTN_ON_COUNT,
	BTN_OFF_COUNT
}tBTN_x;

typedef enum
{
	BTN_RELEASED,
	BTN_PRESSED
}tBTN_STATE;

/*
 * Function: BTN_Init
 * ----------------------------
 *	Initialize PORT PIN
 *
 *	@param Dio_PortType: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param Port_Pin_x: 	PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *	@return void
 */
void BTN_Init(Dio_PortType PortId,Port_Pin_x pin);

/*
 * Function: BTN_GetState
 * ----------------------------
 *	Get BUTTON State
 *
 *	@param Dio_PortType: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param Port_Pin_x: 	PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *		@return tBTN_STATE: BTN_PRESSED, BTN_RELEASED
 */
tBTN_STATE BTN_GetState(Dio_PortType PortId,Port_Pin_x pin);
#endif
