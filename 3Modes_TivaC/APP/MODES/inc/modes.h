#ifndef _MODES_H
#define _MODES_H

#include "StandardTypes.h"

extern uint8 NUMBER1 , NUMBER2 , OPERATION;
extern uint8 seconds , minutes;
extern uint8 sec , min;
extern uint8 result_str[10];
extern uint16 result, ipart;
extern uint32 result_div, fpart;
extern uint8 state_flag ;
extern uint8 flag ;


void CalcMode ( void );
void TimerMode ( void );
void StopWatchMode ( void );
void displayTime(void);
void time(void);
void start (void);
void pause (void);
void reset (void);
void tostring(uint8 str[], uint16 num);
void displayResult(uint8 num1, uint8 OPERATION, uint8 num2);
void sendResultNumber(uint8 result[]);
void SystickNewTick(void);
#endif