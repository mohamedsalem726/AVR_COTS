/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  MCAL            *****************/
/****************   SWC:    TIMER           *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/* Choose Timer0 Mode
 * Options:
 *        1- PWM_PHASE_CORRECT
 *        2- CTC_MODE
 *        3- FAST_PWM
 ***************************************************************************/
#define TIMER0_MODE       CTC_MODE

/* Choose Timer0 OC0 Pin Mode
 * Options:
 *        1- OC0_DISCONNECTED
 *        2- OC0_TOGGLE
 *        3- OC0_CLEAR
 *        4- OC0_SET
 ***************************************************************************/
#define TIMER0_OC0_MODE   OC0_DISCONNECTED

/* Choose Timer0 Clock prescaler
 * Options:
 *        1- NO_PRESCALER
 *        2- DIV_BY_8
 *        3- DIV_BY_64
 *        4- DIV_BY_256
 *        5- DIV_BY_1024
 ****************************************************************************/
#define TIMER0_PRESCALER  DIV_BY_8

/* Choose Timer0 interrupt
 * Options:
 *        1- ENABLE
 *        2- DISABLE
 ****************************************************************************/
#define TIMER0_INTERRUPT  ENABLE

/* Choose Timer0 Compare match value between 0 - 255  */
#define TIMER0_COMPARE_VALUE    250

#endif /* TIMER_CONFIG_H_ */
