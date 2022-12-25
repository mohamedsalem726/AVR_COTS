/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  MCAL            *****************/
/****************   SWC:    TIMER           *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
/* Timer0 Mode Options */
#define PWM_PHASE_CORRECT     1
#define CTC_MODE              2
#define FAST_PWM              3
/**************************************************/

/* Timer0 OC0 pin Mode Options */
#define OC0_DISCONNECTED      1
#define OC0_TOGGLE            2
#define OC0_CLEAR             3
#define OC0_SET               4
/***************************************************/

/* Timer0 prescaler Options */
#define NO_PRESCALER          1
#define DIV_BY_8              2
#define DIV_BY_64             3
#define DIV_BY_256            4
#define DIV_BY_1024           5
/***************************************************/

/* Timer0 interrupt options */
#define ENABLE    1
#define DISABLE   2
/***************************************************/
#endif /* TIMER_PRIVATE_H_ */
