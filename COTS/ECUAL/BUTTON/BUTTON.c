/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#include "BUTTON.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/PORT/port.h"
#include "../../MCAL/INTERRUPT/interrupt.h"

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
void BTN_Init(Dio_PortType PortId,Port_Pin_x pin)
{
	Port_ConfigType ConfigType;
	
	ConfigType.PortPinMode = DIO_PIN;
	ConfigType.PortPinDirection = PIN_INPUT;
	ConfigType.PortPinInternalAttachType = PIN_PULLUP;
	ConfigType.PortNum = PortId;
	ConfigType.PortPin = pin;

	Port_Init(&ConfigType);
	
	Interrupt_ConfigType btnCnf = {PortId,pin};
	INTERRRUPT_Init(&btnCnf);
}

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
tBTN_STATE BTN_GetState(Dio_PortType PortId,Port_Pin_x pin)
{
	return Dio_ReadChannel(PortId,pin);
}