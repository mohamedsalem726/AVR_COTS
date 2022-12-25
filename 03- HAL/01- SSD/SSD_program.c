/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  HAL             *****************/
/****************   SWC:    SSD             *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

u8 SevenSegArr[10] = {
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111
};

u8 SDD_u8SetNumber(u8 Copy_u8Number, SSD_t *Copy_pSSD)
{
	u8 Local_u8ErrorStatus=0;

	if(Copy_pSSD->SSD_Type == COM_ANODE)
	{
		//DIO_u8SetPinValue(Copy_pSSD->SSD_EnablePort,Copy_pSSD->SSD_EnablePin,DIO_u8PIN_HIGH);
		SSD_voidEnable(Copy_pSSD);
		DIO_u8SetPortValue(Copy_pSSD->SSD_Port,~SevenSegArr[Copy_u8Number]);
	}
	else if(Copy_pSSD->SSD_Type == COM_CATHOD)
	{
		//DIO_u8SetPinValue(Copy_pSSD->SSD_EnablePort,Copy_pSSD->SSD_EnablePin,DIO_u8PIN_LOW);
		SSD_voidEnable(Copy_pSSD);
		DIO_u8SetPortValue(Copy_pSSD->SSD_Port,SevenSegArr[Copy_u8Number]);
	}
	else
	{
		Local_u8ErrorStatus=1;
	}


	return Local_u8ErrorStatus;
}


u8 SSD_voidEnable(SSD_t *Copy_pSSD)
{
	u8 Local_u8ErrorStatus=0;
	if(Copy_pSSD->SSD_Type == COM_ANODE)
	{
		DIO_u8SetPinValue(Copy_pSSD->SSD_EnablePort,Copy_pSSD->SSD_EnablePin,DIO_u8PIN_HIGH);
	}
	else if(Copy_pSSD->SSD_Type == COM_CATHOD)
	{
		DIO_u8SetPinValue(Copy_pSSD->SSD_EnablePort,Copy_pSSD->SSD_EnablePin,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorStatus=1;
	}

	return Local_u8ErrorStatus;
}

u8 SSD_voidDisable(SSD_t *Copy_pSSD)
{
	u8 Local_u8ErrorStatus=0;
	if(Copy_pSSD->SSD_Type == COM_ANODE)
	{
		DIO_u8SetPinValue(Copy_pSSD->SSD_EnablePort,Copy_pSSD->SSD_EnablePin,DIO_u8PIN_LOW);
	}
	else if(Copy_pSSD->SSD_Type == COM_CATHOD)
	{
		DIO_u8SetPinValue(Copy_pSSD->SSD_EnablePort,Copy_pSSD->SSD_EnablePin,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorStatus=1;
	}

	return Local_u8ErrorStatus;
}

