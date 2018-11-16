#include "stm32f4xx.h"                  // Device header
#include <stdio.h> 

#pragma import(__use_no_semihosting_swi)

//volatile int ITM_RxBuffer = ITM_RXBUFFER_EMPTY;  /*  CMSIS Debug Input        */

int fputc(int c, FILE *f) {
  return (ITM_SendChar(c));
}

int fgetc(FILE *f) {
  while (ITM_CheckChar() != 1) __NOP();
  return (ITM_ReceiveChar());
}
