#ifndef _MODES_H
#define _MODES_H

extern uint8 state_flag;
extern uint8 flag;

void CalcMode ( void );
void tostring(uint8 str[], uint16 num);
void displayResult(uint8 num1, uint8 OPERATION, uint8 num2);
void sendResultNumber(uint8 result[]);
void TimerMode ( void );
void time(void);
void StopWatchMode ( void );
void displayTime(void);
void start(void);
void pause(void);
void reset (void);

#endif