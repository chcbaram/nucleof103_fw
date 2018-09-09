/*
 * ap.c
 *
 *  Created on: 2018. 5. 12.
 *      Author: Baram
 */


#include "ap.h"



void apInit(void)
{
  uartOpen(_DEF_UART1, 115200);
  uartOpen(_DEF_UART2, 115200);
}

void apMain(void)
{
  while(1)
  {
    // PC로 부터 명령 받아서 _DEF_UART2 포트로 문자열 출력
    //
    if (uartAvailable(_DEF_UART1) > 0)
    {
      uint8_t data;

      data = uartRead(_DEF_UART1);

      if (data == '1')
      {
        uartPrintf(_DEF_UART1, "uart ch1 trigger\n");
        uartPrintf(_DEF_UART2, "uart ch2 tx : 0x%X\n", data);
      }
    }


    // _DEF_UART2 포트로 들어오는 문자열을 PC로 전송하여 출력
    //
    if (uartAvailable(_DEF_UART2) > 0)
    {
      uint8_t data;

      data = uartRead(_DEF_UART2);

      uartPrintf(_DEF_UART1, "%c", data);
    }
  }
}
