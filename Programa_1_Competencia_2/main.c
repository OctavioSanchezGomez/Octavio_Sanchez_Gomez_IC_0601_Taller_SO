#include <stdio.h> 
#include <pthread.h>
#include "scheduler.h"

void *reproducir_musica(void *musica)
{	
	printf("Reproduciendo Música\n");
}

void *abrir_youtube(void *videos){
	printf("Usando Youtube\n");
}

void *escribir_texto_word(void *texto){
	printf("Escribiendo Texto en Word\n");
}

void *descargar_archivo(void *archivo){
	printf("Descargando Archivo\n");
}

void *subiendo_archivo(void *subir){
	printf("Subiendo Archivo\n");
}

void *compilando_programa(void *program){
	printf("Compilando programa\n");
}

void *ejecutando_programa(void *ejecutar){
	printf("Ejecutando programa\n");
}

void *usando_terminal(void *terminal){
	printf("Usando la terminal\n");
}



int main(int argc, char const *argv[]){

	pthread_t h1;
	pthread_t h2;
	pthread_t h3;
	pthread_t h4;
	pthread_t h5;
	pthread_t h6;
	pthread_t h7;
	pthread_t h8;


	pthread_create(&h1,NULL,reproducir_musica,NULL);
	pthread_join(h1,NULL);

	pthread_create(&h2,NULL,abrir_youtube,NULL);
	pthread_join(h2,NULL);

	pthread_create(&h3,NULL,escribir_texto_word,NULL);
	pthread_join(h3,NULL);

	pthread_create(&h4,NULL,descargar_archivo,NULL);
	pthread_join(h4,NULL);

	pthread_create(&h5,NULL,subiendo_archivo,NULL);
	pthread_join(h5,NULL);

	pthread_create(&h6,NULL,compilando_programa,NULL);
	pthread_join(h6,NULL);

	pthread_create(&h7,NULL,ejecutando_programa,NULL);
	pthread_join(h7,NULL);


	pthread_create(&h8,NULL,usando_terminal,NULL);
	pthread_join(h8,NULL);

process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 	
//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	
process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	
//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	
//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);		
	
process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	
process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	
//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		
//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	
//<--



array_procesos *array = crear_ArrayProcesos();
	
agregar_Proceso(array, *p1);
	
agregar_Proceso(array, *p2);
	
agregar_Proceso(array, *p3);

agregar_Proceso(array, *p4);

agregar_Proceso(array, *p5);

agregar_Proceso(array, *p6);

agregar_Proceso(array, *p7);

agregar_Proceso(array, *p8);

agregar_Proceso(array, *p9);
	
ejecutar_Procesos(array);

free(array);
free(p1);
free(p2);
free(p3);
free(p4);
free(p5);
free(p6);
free(p8);
free(p9);
return 0;

}



