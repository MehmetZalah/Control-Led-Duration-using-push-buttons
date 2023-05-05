/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#include "DIO.h"
#include "../Utilities.h"

/*
 * Function: Dio_ReadChannel
 * ----------------------------
 *	Read PORT PIN State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param channelId: CHANNEL_0, CHANNEL_1, CHANNEL_2, CHANNEL_3, CHANNEL_4, CHANNEL_5, CHANNEL_6, CHANNEL_7
 *
 *	@return Dio_LevelType: 	LEVEL_LOW, LEVEL_HIGH
 */
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType channelId)
 {
	return READ_BIT(Dio_GetAddress(PortId)->GPIOMIS,channelId);
}


/*
 * Function: Dio_WriteChannel
 * ----------------------------
 *	Set PORT PIN State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param channelId: CHANNEL_0, CHANNEL_1, CHANNEL_2, CHANNEL_3, CHANNEL_4, CHANNEL_5, CHANNEL_6, CHANNEL_7
 *	@param level: LEVEL_LOW, LEVEL_HIGH
 *
 *	@return tGPIO_STATUS_x: GPIO_STATUS_SUCCESS, GPIO_STATUS_ERROR_PORT, GPIO_STATUS_ERROR_PIN, GPIO_STATUS_ERROR_DIR, GPIO_STATUS_ERROR_STATE
 */
void Dio_WriteChannel(Dio_PortType PortId, Dio_ChannelType channelId, Dio_LevelType level)
{
	if(PortId < PORT_A || PortId > PORT_F)
		return;
	
	switch(level)
	{
		case LEVEL_HIGH:
			SET_BIT(Dio_GetAddress(PortId)->GPIODATA,channelId);
			break;
		case LEVEL_LOW:
			CLEAR_BIT(Dio_GetAddress(PortId)->GPIODATA,channelId);
			break;
	}
}

/*
 * Function: Dio_Read
 * ----------------------------
 *	Read PORT State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *
 *	@return Dio_PortLevelType: 	0 .. 2^8
 */
Dio_PortLevelType Dio_Read(Dio_PortType PortId)
{
	return Dio_GetAddress(PortId)->GPIODATA;
}

/*
 * Function: Dio_WritePort
 * ----------------------------
 *	Set PORT State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param Dio_PortLevelType: 0 .. 2^8
 *
 *	@return void
*/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType level)
{
	Dio_GetAddress(PortId)->GPIODATA = level;
}

/*
 * Function: Dio_FlipChannel
 * ----------------------------
 *	Toggle PORT PIN State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param channelId: CHANNEL_0, CHANNEL_1, CHANNEL_2, CHANNEL_3, CHANNEL_4, CHANNEL_5, CHANNEL_6, CHANNEL_7
 *
 *	@return Dio_LevelType: LEVEL_LOW, LEVEL_HIGH
 */
Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
{
	TOGGLE_BIT(Dio_GetAddress(PortId)->GPIODATA, ChannelId);
	
	return READ_BIT(Dio_GetAddress(PortId)->GPIODATA, ChannelId);
}

/*
 * Function: Dio_GetAddress
 * ----------------------------
 *	Get MCU Port Address
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *
 *	@return *tDio_Address
 */
tDio_Address* Dio_GetAddress(Dio_PortType portId)
{
	switch(portId)
	{
		case PORT_A:
			return DIO_A_BASE;
		case PORT_B:
			return DIO_B_BASE;
		case PORT_C:
			return DIO_C_BASE;
		case PORT_D:
			return DIO_D_BASE;
		case PORT_E:
			return DIO_E_BASE;
		case PORT_F:
			return DIO_F_BASE;
	}
}