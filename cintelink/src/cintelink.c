/*
 ============================================================================
 Name        : cintelink.c
 Author      : FlorMolla
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Uart(void);
int log_transactions(const char *, char *, size_t);

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	Uart();
	return EXIT_SUCCESS;
}

void Uart(void) {
	//datos que provendrian de uart
	char datos_uart[]={"[23/02/2020 04:03:20 AAA 1111 P123422]"};
	char *buffer = (char *)malloc(sizeof(datos_uart) * 1000);
	char log[100];
	int trans_count=0;
	time_t dif = 0;

	time_t inicio = time(NULL);

	do{
		if (buffer[0] != '['){
			strcpy(buffer,datos_uart);
		}else if (buffer[0] == '[') {
			strcat(buffer,datos_uart);
		}
		time_t fin = time(NULL);
		time_t diferencia = fin - inicio;
		dif = diferencia;
		trans_count++;
	}while(dif<30 && trans_count<5);

	log_transactions(buffer, log, trans_count);


}

int log_transactions(const char *data, char *log, size_t trans_count){

	    int count = 0;
	    char bufferr[300];
	    char *auxSt= (char *) malloc(20*sizeof(char));;
	    char logg[65];
	    char datos[100][65]={0};
	    //primer valor de la trama
	    char* ptr = strtok(data, "[]");

	    do{
	    	strcpy(logg, "[");
	    	strncat(logg, ptr, 19);
	    	strcat(logg, "] id: ");
	    	strncat(logg, ptr + 34, 2);
	    	strcat(logg, ", reg: ");
	    	strncat(logg, ptr + 20, 8);
	    	strcat(logg, ", prod: ");
	    	strncat(logg, ptr + 29, 1);
	    	strcat(logg, ", ltrs: ");
	    	strncat(logg, ptr + 30, 4);

	    	if(datos[count][0]==0)
	    		strcpy(datos[count],logg);
	    	else

	    	sscanf(ptr,"%d/", auxSt);
	    	strcat(logg,auxSt);
	    }while(trans_count<count);

	    puts("!!!Hello World!!!");
	return 0;
}

