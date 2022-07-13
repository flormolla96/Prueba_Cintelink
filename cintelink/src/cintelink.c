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
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#define len 5

void Uart(void);
void log_transactions(char*[], int* , int);
time_t string_to_seconds (char*[], int);

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	Uart();
	return EXIT_SUCCESS;
}

void Uart(void) {
	//datos que provendrian de uart
	char *datos_uart[5]={{"12/08/1996 17:23:20AAA 1111 P123422"},{"13/08/2001 14:34:20AAA 1111 P123422"},
			{"25/04/1997 13:25:30AAA 1111 P123422"},{"25/08/2022 13:25:30AAA 1111 P123422"},{"25/04/2020 13:25:30AAA 1111 P123422"}};
	//char datos_uart[]={"[23/02/2020 04:03:20 AAA 1111 P123422]"};
	char *buffer[100];
	char log[100];
	int trans_count=0;
	time_t dif = 0;

	time_t inicio = time(NULL);

	do{
		buffer[trans_count]=datos_uart[trans_count];

		time_t fin = time(NULL);
		time_t diferencia = fin - inicio;
		dif = diferencia;

		trans_count++;
	}while(dif<30 && trans_count<5);

	string_to_seconds(buffer, trans_count);

}



time_t string_to_seconds(char *timestamp_str[], int trans)
{
	struct tm tm[trans];
	time_t seconds[trans],seconds2[trans];
	int r[trans],pos[trans];
	long  aux;

	if (timestamp_str == NULL) {
		return (time_t)-1;
	}

	for(int i=0; i<trans; i++){
		r[i] = sscanf(timestamp_str[i], "%d/%d/%d %d:%d:%d", &tm[i].tm_mday, &tm[i].tm_mon, &tm[i].tm_year, &tm[i].tm_hour, &tm[i].tm_min, &tm[i].tm_sec);
		if (r[i] != 6) {
			return (time_t)-1;
		}

		tm[i].tm_year -= 1900;
		tm[i].tm_mon -= 1;
		tm[i].tm_isdst = 0;

		seconds[i] = mktime(&tm[i]);
		seconds2[i] = mktime(&tm[i]);
	}

	for (int i = 0; i < trans ; i++) {
		for (int j = i + 1; j < trans; j++) {
			if(seconds[i]>seconds[j]){// cambia "<" a ">" para cambiar la manera de ordenar
				aux=seconds[i];
				seconds[i]=seconds[j];
				seconds[j]=aux;
			}
		}
	}

	for (int i = 0; i < trans ; i++) {
		for (int j = 0; j < trans; j++) {
			if (seconds[i] == seconds2[j])
				pos[i]=j;
		}
	}

	log_transactions(timestamp_str, pos, trans);

	return 0;
}

void log_transactions(char *data[], int *log, int trans_count){

	    char *bufferr[trans_count];
	    char logg[65];
	    int count=0;
	    char *trama[trans_count];

	   for (int i = 0; i < trans_count ; i++) {
	       	bufferr[i]=data[*log];
	       	log++;
	   }

	    for (int i = 0; i < trans_count ; i++) {
	    	strcpy(logg, "[");
	    	strncat(logg, bufferr[count], 19);
	    	strcat(logg, "] id: ");
	    	strncat(logg, bufferr[count] + 33, 2);
	    	strcat(logg, ", reg: ");
	    	strncat(logg, bufferr[count] + 19, 8);
	    	strcat(logg, ", prod: ");
	    	strncat(logg, bufferr[count] + 28, 1);
	    	strcat(logg, ", ltrs: ");
	    	strncat(logg, bufferr[count] + 29, 4);

	    	trama[count]=logg;
	    	count++;
	    }
	    puts("!!!Hello World!!!");
}

