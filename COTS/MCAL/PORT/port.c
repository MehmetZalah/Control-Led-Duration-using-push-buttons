/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 
 
#include "port.h"
#include "../Utilities.h"
/*
 * Function: Port_Init
 * ----------------------------
 *	Initialize PORT PIN
 *
 *	@param *Port_ConfigType struct
 * 					- Port_PinModeType PortPinMode;
 *					-	Port_PinDirectionType PortPinDirection;
 *					- Port_PinLevel PortPinLevelValue;
 *					- Port_PinInternalAttachType PortPinInternalAttachType;
 *					- Port_PinOutputCurrentType PortPinOutputCurrentType;
 *	        - Dio_PortType PortNum;
 *	        - Port_Pin_x PortPin;
 *
 *	@return void
 */
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	if(ConfigPtr->PortNum < PORT_A || ConfigPtr->PortNum > PORT_F)
		return;
	
	if(ConfigPtr->PortPin < PORT_PIN_0 || ConfigPtr->PortPin > PORT_PIN_7)
		return;
	
	/* 1- Enable PORT Clock */
	SET_BIT(RCC_GPIO,ConfigPtr->PortNum);

	/* 2- Set PIN Function */
	switch(ConfigPtr->PortPinMode)
	{
		case DIO_PIN:
		
			//A) set GPIO_FUNC_DIGITAL in port GPIOAFSEL
			CLEAR_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIOAFSEL,ConfigPtr->PortPin);
		
			//B) set DEN PIN
			SET_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIODEN,ConfigPtr->PortPin);
	
			break;
	}
	
	/* 3- Set PIN Direction */
	switch(ConfigPtr->PortPinDirection)
	{
		case PIN_OUTPUT:
		
			//A) set pin as output
			SET_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIODIR,ConfigPtr->PortPin);
		
			//B) set pin current
			switch(ConfigPtr->PortPinOutputCurrentType)
			{
				case PIN_2MA_CURRENT:
					SET_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIODR2R,ConfigPtr->PortPin);
					break;
				case PIN_4MA_CURRENT:
					SET_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIODR4R,ConfigPtr->PortPin);
					break;
				case PIN_8MA_CURRENT:
					SET_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIODR8R,ConfigPtr->PortPin);
					break;
			}
						
			//C) set pin data
			Dio_WriteChannel(ConfigPtr->PortNum,ConfigPtr->PortPin, ConfigPtr->PortPinLevelValue);
			break;
			
		case PIN_INPUT:
			
			//A) set pin as INPUT
			CLEAR_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIODIR,ConfigPtr->PortPin);
			
			//B) set input resistor
			switch(ConfigPtr->PortPinInternalAttachType)
			{
				case PIN_OPENDRAIN:
					SET_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIOODR,ConfigPtr->PortPin);
					break;
				case PIN_PULLUP:
					SET_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIOPUR,ConfigPtr->PortPin);
					break;
				case PIN_PULLDOWN:
					SET_BIT(Dio_GetAddress(ConfigPtr->PortNum)->GPIOPDR,ConfigPtr->PortPin);
					break;
			}
		
			break;
	}
}