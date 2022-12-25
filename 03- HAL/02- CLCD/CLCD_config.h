/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  HAL             *****************/
/****************   SWC:    CLCD            *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/********************************************************/
/* Option:  DIO_u8PORTA
 * 			DIO_u8PORTB
 * 			DIO_u8PORTC
 * 			DIO_u8PORTD
 */
/********************************************************/
#define CLCD_DATA_PORT       DIO_u8PORTA

/********************************************************/
/* Option:  DIO_u8PORTA
 * 			DIO_u8PORTB
 * 			DIO_u8PORTC
 * 			DIO_u8PORTD
 */
/********************************************************/
#define CLCD_CTRL_PORT       DIO_u8PORTC

/* Select the control pins */
#define CLCD_RS_PIN        	 DIO_u8PIN0
#define CLCD_RW_PIN          DIO_u8PIN1
#define CLCD_E_PIN           DIO_u8PIN2


#endif /* CLCD_CONFIG_H_ */
