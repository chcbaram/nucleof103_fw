/*
 * ap.c
 *
 *  Created on: 2018. 5. 12.
 *      Author: Baram
 */


#include "ap.h"



void led_isr(void)
{
  ledToggle(0);
}



void apInit(void)
{
  uartOpen(_DEF_UART1, 115200);


  timerSetPeriod(_DEF_TIMER1, 500*1000);
  timerAttachInterrupt(_DEF_TIMER1, led_isr);
  timerStart(_DEF_TIMER1);
}

void apMain(void)
{
  while(1)
  {
    if (buttonGetPressedEvent(0) == true)
    {
      uartPrintf(_DEF_UART1, "PressedEvent\r\n");
    }
    if (buttonGetPressed(0) == true)
    {
      uartPrintf(_DEF_UART1, "PressedTime : %d\r\n", buttonGetPressedTime(0));
    }
    if (buttonGetReleasedEvent(0) == true)
    {
      uartPrintf(_DEF_UART1, "ReleasedEvent\r\n");
    }

    if (uartAvailable(_DEF_UART1) > 0)
    {
      uartPrintf(_DEF_UART1, "rx : 0x%X\r\n", uartRead(_DEF_UART1));
    }
  }
}
