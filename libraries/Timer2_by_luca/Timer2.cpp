#ifndef TIMERDUE_cpp
#define TIMERDUE_cpp

#include "TimerDue.h"

TimerDue Timer2;


void TimerDue::Initialize(unsigned char Mode, unsigned int Prescaller, unsigned int UP, unsigned char I_O_config)
{
  cli();
  TCCR2B =0;
  TCCR2A =0;
  disableInterrupt();
  
  // if((Mode==1) || (Mode==3) || (Mode==5) || (Mode==7))  // se pwm
  // {
	// to do
	// }
  // else
  // {
	OCR2A=UP;
	ModeSetup(Mode);
	PrescallerSetup(Prescaller);
	IOConfig(I_O_config);	
  // }
  
  sei();
}

void TimerDue::ModeSetup(unsigned char Mode)                      //uso solo i 3 bit per il settaggio
{
  // if((Mode <= 7) && (Mode != 4) && (Mode != 6))
  // {
	TCCR2A &= 0b11111100;
	TCCR2B &= 0b11110111; 
	
	TCCR2A |= (1 << WGM21);  //debug
    //TCCR2A |= (((Mode >> 1) & 1) << WGM21) | ((Mode & 1) << WGM20);
    //TCCR2B |= (((Mode >> 2) & 1) << WGM22); 
  //}
 }
  
 void TimerDue::IOConfig(unsigned char I_O_config)
 {
   TCCR2A &= 0b00001111;
   TCCR2A |= (I_O_config) << 4;
 }
 
 void TimerDue::PrescallerSetup(unsigned int Prescaller)
 {
	TCCR2B &= 0b11111000;  //set to 0 the last 3 bit
   switch(Prescaller)
   {
     case 0:
       TCCR2B |= (0 << CS22)|(0 << CS21)|(0 << CS20);
     break;
       
     case 1:
       TCCR2B |= (0 << CS22)|(0 << CS21)|(1 << CS20);
     break;
       
     case 8:
       TCCR2B |= (0 << CS22)|(1 << CS21)|(0 << CS20);
     break;
     
     case 32:
       TCCR2B |= (0 << CS22)|(1 << CS21)|(1 << CS20);
     break;
     
     case 64:
       TCCR2B |= (1 << CS22)|(0 << CS21)|(0 << CS20);
     break;
     
     case 128:
       TCCR2B |= (1 << CS22)|(0 << CS21)|(1 << CS20);
     break;
     
     case 256:
       TCCR2B |= (1 << CS22)|(1 << CS21)|(0 << CS20);
     break;
     
     case 1024:
       TCCR2B |= (1 << CS22)|(1 << CS21)|(1 << CS20);
     break;
     
     default:
       TCCR2B |= (0 << CS22)|(0 << CS21)|(1 << CS20);        //prescaller ad 1
   }
 }
void TimerDue::disableInterrupt()
{
  TIMSK2 &= 0b11111110;                                   // clears the timer overflow interrupt enable bit 
}

void TimerDue::enableInterrupt()
{
  TIMSK2 |= (1 << TOIE2);									// set the timer overflow interrupt enable bit 
}

#endif