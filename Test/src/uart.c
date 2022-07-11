/*
 ============================================================================
 Name        : uart.c
 Author      : FlorMolla
 Version     :
 Copyright   : Your copyright notice
 Description : Dentro de esta funcion se recibirian los datos provenientes de la uart
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void uart(void) {
	//datos que provendrian de uart
	char datos_uart[34]={"mm/dd/yyyy hh:mm:ssAAA 1111P123422"};
	char *datos;

	time_t tiempoahora;
	time(tiempoahora);
	ctime(&tiempoahora);

	//se almacenan los datos de uart en una variable
	datos = &datos_uart;

}
