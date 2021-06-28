#include <stdio.h>
#include <stdlib.h>

typedef struct{
int tiempo;
int valido;
char nombre[50];
}Proceso;

int main(int argc, char *argv[]){
	int i,noProc,valTiem;
	printf("Introduce el numero de procesos: ");
	scanf("%i",&noProc);
	Proceso procesos[noProc];
	for(i=0;i<noProc;i++){
		printf("Introduce el nombre de proceso ");
		scanf("%s", procesos[i].nombre);
		printf("Introduce el tiempo del proceso %i (milisegundos:)",i+1);
		scanf("%i",&valTiem);
		procesos[i].tiempo=valTiem;
		if(valTiem=!0){
			procesos[i].valido=1;
		}else{
			procesos[i].valido=0;
		}
	}

    int valQuantum;
	printf("Introduce el valor del quantum: ");
	scanf("%i",&valQuantum);
	int procesosR=noProc,aux=0,vueltas=0;
	while(procesosR!=0){
		for(i=0;i<noProc;i++){
			if(procesos[i].valido==1){
				if(procesos[i].tiempo<=valQuantum){
				procesos[i].tiempo=0;
				procesos[i].valido=0;
				printf("Proceso [%i]:[%s] quedo invalido\n",i+1,procesos[i].nombre);
                }else{
                    procesos[i].tiempo=procesos[i].tiempo-valQuantum;

                }
            }
		}
		vueltas++;
        aux=0;
        for(i=0;i<noProc;i++){
            if(procesos[i].valido==0){
                aux++;
            }
        }
        if(aux==noProc){
            procesosR=0;
        }

	}
	printf("Vueltas totales: %i\n",vueltas);
	return 0;
}
