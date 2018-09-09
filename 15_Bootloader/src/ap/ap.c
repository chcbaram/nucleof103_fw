/*
 * ap.c
 *
 *  Created on: 2018. 5. 12.
 *      Author: Baram
 */


#include "ap.h"



cmd_t cmd_boot;



void apInit(void)
{
  cmdInit(&cmd_boot);
  cmdBegin(&cmd_boot, _DEF_UART1, 115200);
}

void apMain(void)
{
  uint32_t pre_time;


  pre_time = millis();
  while(1)
  {
    if (cmdReceivePacket(&cmd_boot) == true)
    {
      bootProcessCmd(&cmd_boot);
    }

    if (millis()-pre_time >= 100)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }
  }
}
