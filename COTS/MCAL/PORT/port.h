/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 
 
#ifndef __PORT_H__
#define __PORT_H__

#include "../DIO/DIO.h"

typedef enum
{
	DIO_PIN
}Port_PinModeType;

typedef enum
{
	PIN_INPUT,
	PIN_OUTPUT
}Port_PinDirectionType;

typedef enum
{
	PIN_LOW,
	PIN_HIGH
}Port_PinLevel;

typedef enum
{
	PIN_PULLUP,
	PIN_PULLDOWN,
	PIN_OPENDRAIN
}Port_PinInternalAttachType;

typedef enum
{
	PIN_2MA_CURRENT,
	PIN_4MA_CURRENT,
	PIN_8MA_CURRENT
}Port_PinOutputCurrentType;

typedef enum
{
	PORT_PIN_0,
	PORT_PIN_1,
	PORT_PIN_2,
	PORT_PIN_3,
	PORT_PIN_4,
	PORT_PIN_5,
	PORT_PIN_6,
	PORT_PIN_7
}Port_Pin_x;

typedef struct
{
	Port_PinModeType PortPinMode;
	Port_PinDirectionType PortPinDirection;
	Port_PinLevel PortPinLevelValue;
	Port_PinInternalAttachType PortPinInternalAttachType;
	Port_PinOutputCurrentType PortPinOutputCurrentType;
	Dio_PortType PortNum;
	Port_Pin_x PortPin;
}Port_ConfigType;


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
void Port_Init(const Port_ConfigType* ConfigPtr);

#endif