#include <stdio.h>
#include <stdlib.h>
// programa 1
int main (){
 int x;         //paso 1
 int *p; 	//paso 2
 int y; 
 int *puntero;
	x=10;   //paso 3
	p=&x;   //Paso 4
	
	printf("\nValor de Puntero P es: %i\n",*p);      // paso 5
	p+=1;				                 // paso 6
	printf("Valor de Puntero P es: %i\n",*p);        // paso 7
	p+=2;				                 // paso 8	
	printf("Valor de Puntero P es: %i\n",*p);        // paso 9
	y=20;				                 // paso 10		
	puntero=&y;				         // paso 11	
	printf("Valor de Puntero P es: %i\n",*puntero);  // paso 12	


//programa 2
 int arrayint[5];
     arrayint[0] = 0;
     arrayint[1] = 1;
     arrayint[2] = 2;
     arrayint[3] = 3;
     arrayint[4] = 4;
     arrayint[5] = 5;

    int *punteroint;
        punteroint = arrayint;
    int *punterointdos;
	punterointdos = &arrayint[0];
	
printf("\n El contenido de el primer elemento array es: %i\n",arrayint[1]);
printf("\n El contenido de el primer elemento del puntero es: %i\n",*punteroint);
printf("\n El contenido de el primer elemento del puntero: %i\n",*punterointdos);
printf("\n El contenido de el quinto elemento array es: %i\n",arrayint[5]);
printf("\n El contenido de el quinto elemento del puntero es: %i \n",*punteroint+4);
printf("\n El contenido de el quinto elemento del puntero es: %i \n",*punterointdos+4);



return 0;
}
