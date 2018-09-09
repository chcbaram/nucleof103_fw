/*
 * main.c
 *
 *  Created on: 2018. 9. 9.
 *      Author: Baram
 */


#include "main.h"



int main(int argc, char *argv[])
{
  hwInit();
  apInit();

  apMain(argc, argv);
}

