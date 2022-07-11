/*
 ============================================================================
 Name        : Main.c
 Author      : FlorMolla
 Version     :
 Copyright   : Your copyright notice
 Description : Se ejecuta la inicializacion de todos los perifericos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void uart(void);

int Test(void) {
	puts("Comienzo de prueba"); /* prints !!!Hello World!!! */
	uart();
	return EXIT_SUCCESS;
}
