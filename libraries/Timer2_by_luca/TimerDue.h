#ifndef TIMERDUE_h
#define TIMERDUE_h

#include <avr/io.h>
#include <avr/interrupt.h>


class TimerDue
{
  public:
  
    // properties
    unsigned int Pres_imp;
    

    // methods
    void Initialize(unsigned char Mode, unsigned int Prescaller = 1, unsigned int UP = 0xFF, unsigned char I_O_config = 0);
	void ModeSetup(unsigned char Mode);
    void IOConfig(unsigned char I_O_config);
	void PrescallerSetup(unsigned int Prescaller);
	void disableInterrupt();
	void enableInterrupt();

	
};

extern TimerDue Timer2;
#endif