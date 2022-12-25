/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  MCAL            *****************/
/****************   SWC:    TIMER           *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


/* Timer0 Registers */
#define TCCR0        *((volatile u8*)0x53) //Timer/Counter0 control register
#define TCCR0_FOC0   7                     //Force output compare
#define TCCR0_WGM00  6                     //Waveform generation mode bit0
#define TCCR0_COM01  5                     //Compare match output mode bit1
#define TCCR0_COM00  4                     //Compare match output mode bit0
#define TCCR0_WGM01  3                     //Waveform generation mode bit1
#define TCCR0_CS02   2                     //Clock select bit2
#define TCCR0_CS01   1                     //clock select bit1
#define TCCR0_CS00   0                     //clock select bit0

#define TCNT0        *((volatile u8*)0x52) //Timer counter register

#define OCR0         *((volatile u8*)0x5C) //Output compare register

#define TIMSK        *((volatile u8*)0x59) //Timer Interrupt mask register
#define TIMSK_OCIE0  1                     //Output compare match interrupt enable
#define TIMSK_TOIE0  0                     //Overflow interrupt enable
/***********************************************************************************************/

/* Timer1 Register */
#define TCCR1A         *((volatile u8*)0x)   //Timer/Counter1 control register A
#define TCCR1A_COM1A1  7
#define TCCR1A_COM1A0  6
#define TCCR1A_COM1B1  5
#define TCCR1A_COM1B0  4
#define TCCR1A_FOC1A   3
#define TCCR1A_FOC1B   2
#define TCCR1A_WGM11   1
#define TCCR1A_WGM10   0

#define TCCR1B         *((volatile u8*)0x)   //Timer/Counter1 control register B
#define TCCR1B_ICNC1   7
#define TCCR1B_ICES1   6
#define TCCR1B_WGM13   4
#define TCCR1B_WGM12   3
#define TCCR1B_CS12    2
#define TCCR1B_CS11    1
#define TCCR1B_CS10    0

#endif /* TIMER_REGISTER_H_ */
