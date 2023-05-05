/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 
 

#ifndef __LED_H__
#define __LED_H__

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/PORT/port.h"

/*
 * Function: LED_Init
 * ----------------------------
 *	Initialize LED x
 *
 *	@param Dio_PortType: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param Port_Pin_x: 	PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *	@return void
 */
void LED_Init(Dio_PortType PortId,Port_Pin_x pin);


/*
 * Function: LED_SetState
 * ----------------------------
 *	Set LED State
 *
 *	@param Dio_PortType: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param Port_Pin_x: 	PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 * 	@param Port_PinLevel: PIN_LOW, PIN_HIGH
 *
 *	@return void
 */
void LED_SetState(Dio_PortType PortId,Port_Pin_x pin, Port_PinLevel level);

#endif