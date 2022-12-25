/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  HAL             *****************/
/****************   SWC:    CLCD            *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"


void CLCD_voidInit(void)
{
	/* Wait for more than 30ms */
	_delay_ms(40);

	/* Function Set Command: 2 lines, 5*8 font size */
	CLCD_voidSendCommand(0b00111000);

	/* Display ON/OFF control: display enable, disable cursor, no blinking cursor */
	CLCD_voidSendCommand(0b00001100);

	/* Display Clear */
	CLCD_voidSendCommand(0b00000001);

}

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/* Set RS pin to low for Command */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/* Set RW pin to low for write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/* Set command to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/* Send enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/* Set RS pin to high for data */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/* Set RW pin to low for write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/* Set Data to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/* Send enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendString(const char *Copy_pcString)
{
	u8 Local_u8Counter=0;

	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPostion, u8 Copy_u8YPostion)
{
	u8 Local_u8Address;

	if(Copy_u8XPostion==0)
	{
		/* Location is at first line */
		Local_u8Address=Copy_u8YPostion;
	}
	else if(Copy_u8XPostion==1)
	{
		/* Location is at second line */
		Local_u8Address=0x40+Copy_u8YPostion;
	}

	/* Set bit number 7 for set DDRAM address command then send the command */
	Local_u8Address=SET_BIT(Local_u8Address,7);
	CLCD_voidSendCommand(Local_u8Address);
}

void CLCD_voidWriteSpecialCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPostion , u8 Copy_u8YPostion)
{
	u8 Local_u8CGRAMAddress=0;
	u8 Local_u8Iterator;
	/* Calculate the CGRAM address whose each block is 8 bytes */
	Local_u8CGRAMAddress=Copy_u8PatternNumber*BLOCK_SIAZE;

	/* Send CGRAM address command to LCD with setting bit 6 , clearing bit 7 */
	Local_u8CGRAMAddress=SET_BIT(Local_u8CGRAMAddress,6);
	CLCD_voidSendCommand(Local_u8CGRAMAddress);

	/* Write the pattern into CGRAM */
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}

	/* Go back to DDRAM to display the pattern */
	CLCD_voidGoToXY(Copy_u8XPostion,Copy_u8YPostion);

	/* Display the pattern written in the CGRAM */
	CLCD_voidSendData(Copy_u8PatternNumber);
}
