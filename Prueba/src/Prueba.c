/*
 ============================================================================
 Name        : Prueba.c
 Author      : FlorMolla
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"

void Uart(void);

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	Uart();
	return EXIT_SUCCESS;
}
