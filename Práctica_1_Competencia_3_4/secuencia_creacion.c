#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

//DECLARACION DE ESTRUCTURAS
typedef struct elemento{
  char palabra[MAX];
  struct elemento *sig;
}Nodo;

typedef struct {
  char palabra[MAX];
}Palabras;

//DECLARACION DE FUNCIONES
Nodo *crear_lista(Nodo *lista); //INICIA LA LISTA ENLAZADA
Nodo *agregar_elemento(Nodo *lista, char *palabra); //LIGA LOS ELEMENTOS DE LA LISTA
void ordenar_elementos(Nodo *lista); //ORDENA LOS ELEMENTOS DE LA LISTA Y LOS ALMACENA EN UN ARRAY SIMULANDO STRINGS

//DECLARACION DE VARIABLES GLOBALES
Palabras array_ordenado[1000];
int c=0;

//FUNCION MAIN
int main(int argc, char *argv[]){
  Nodo *lista_enlazada = crear_lista(lista_enlazada);
  FILE *f_entrada, *f_salida;
  char palabra[MAX];
  f_entrada = fopen(argv[1],"r");

  if(f_entrada == NULL){
    printf("No existe el fichero");
    fclose(f_entrada);
  }else{
    while(!feof(f_entrada)){
      fscanf(f_entrada,"%s",palabra);
      if(strcmp(palabra,"") != 0){
	  lista_enlazada = agregar_elemento(lista_enlazada,palabra);
      }
      memset(palabra,0,MAX);
    }
  }
  ordenar_elementos(lista_enlazada);
  fclose(f_entrada);
  f_salida = fopen(argv[2],"w");
  printf("Abriendo/creando Archivo llamado : %s\nEscribiendo...\n",argv[2]);
  for(int i=0; i<=c; i++){
    strcpy(palabra,array_ordenado[i].palabra);
    if(strcmp(palabra,"") != 0){
      fprintf(f_salida,"%s\n",palabra);
    }
  }
  printf("Archivo \"%s\" escrito de manera correcta\n",argv[2]);
  fclose(f_salida);
}

//DESARROLLO DE FUNCIONES
Nodo *crear_lista(Nodo *lista){
  lista = NULL;
  return lista;
};
Nodo *agregar_elemento(Nodo *lista, char *palabra){
  Nodo *nuevo_Elemento, *aux; // SE CREAN ESTAS VARIABLES PARA NO PERDER INFORMACION
  nuevo_Elemento = (Nodo*)malloc(sizeof(Nodo));
  strcpy(nuevo_Elemento->palabra,palabra);
  nuevo_Elemento->sig = NULL;
  
  if(lista == NULL){
    lista = nuevo_Elemento;
  }else{
    aux = lista;
    while(aux->sig != NULL){ //NOS MOVEMOS HASTA EL ULTIMO ELEMENTO DE LA LISTA ENLAZADA CON (AUX)
      aux = aux->sig;
    }
    aux->sig = nuevo_Elemento; // ASIGNAMOS EL NUEVO ELEMENTO EN LA DIRECCION DE MEMORIA A LA QUE APUNTA AUX, ES DECIR EL ULTIMO ELEMENTO
  }
  return lista;
};
void ordenar_elementos(Nodo *lista){
  Palabras array[1000];
  //strcpy(array[0].palabra,lista->palabra);
  //c++;
  while(lista->sig != NULL){
    strcpy(array[c].palabra,lista->palabra); // COPIAMOS EL CONTENIDO DE LA LISTA HACIA EL ARREGLO PARA ORDENARLO
    //puts(array[c].palabra);
    lista = lista->sig;
    c++;
  }
  strcpy(array[c].palabra,lista->palabra);
  //INICIA EL METODO DE ORDENAMIENTO DE BURBUJA
  char temp[MAX];
  for(int i=0; i<c; i++){
    for(int j=0; j<c; j++){
      if(strcmp(array[j].palabra,array[j+1].palabra) >= 0){
	strcpy(temp,array[j].palabra);
	strcpy(array[j].palabra,array[j+1].palabra);
	strcpy(array[j+1].palabra,temp);
      }
    }
  } 
  for(int i=0; i<=c; i++){ //COPIAMOS EL ARRAY LOCAL AL ARRAY GLOBAL
    //if(strcmp(array[i].palabra,"") != 0){
      strcpy(array_ordenado[i].palabra,array[i].palabra);
      //printf("palabra [ %s ]\n",array_ordenado[i].palabra);
    //}
  }
};

