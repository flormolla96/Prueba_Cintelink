/*
 ============================================================================
 Name        : uart.c
 Author      : FlorMolla
 Version     :
 Copyright   : Your copyright notice
 Description : Dentro de esta funcion se recibirian los datos provenientes de la uart
 ============================================================================
 */


#include <stdio.h> /* Declaración librerías*/
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Uart(void) {
	//datos que provendrian de uart
	char datos_uart[34]={"mm/dd/yyyy hh:mm:ssAAA 1111P123422"};
	char *buffer;
	int cont=0;

	do{
		if (buffer == NULL){
			strcpy(buffer,datos_uart);
		}else{
			strcpy(buffer,datos_uart);
		}
		cont++;
	}while(cont<5);
	/*char datos_uart[34][2]={"mm/dd/yyyy hh:mm:ssAAA 1111P123422","1234","222"};
	char *datos;

	time_t tiempoahora;
	//time(tiempoahora);
	ctime(&tiempoahora);

	//se almacenan los datos de uart en una variable
	datos = &datos_uart[0];*/

}



