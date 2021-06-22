#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//LIBRERIAS PARA LOS SOCKETS
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX 300
#define MAX2 925

int main(int argc, char *argv[]){
  int PORT;
  char *IP;
  system("clear");
  if(argc < 3){
    printf("\t\tError, parametros incompletos. \n\t\t-->Ingresa la ip: ");
    char portc[4];
    gets(portc);
    PORT = atoi(portc);
    printf("\t\t-->Ingresa el puerto: ");
    gets(IP);//LA ESTRUCTURA ES LA SIGUIENTE: 255.255.255.255 EJ: 192.168.1.1
  }else{
    IP = argv[1];
    PORT = atoi(argv[2]);
  }

  //DECLARAMOS LAS VARIABLES LOCALES
  int FD, nBytes;
  char BUF[MAX];

  struct hostent *H; //ENTIDAD QUE RECIBIRA INFORMACION DEL HOST
  struct sockaddr_in SV; //INFORMACION SOBRE LA DIRECCION DEL SERVIDOR

  if((H=gethostbyname(IP)) == NULL){ //LLAMAMOS AL HOST Y COMPARAMOS LA SALIDA PARA DETECTAR ERRORES
    perror("\t\t-->Error de gethostname().");
    return -1;
  }
  if((FD = socket(AF_INET, SOCK_STREAM, 0)) == -1){//CREAMOS EL SOCKET Y DETECTAMOS ERRORES
    perror("\t\t-->Error en la creacion del socket.");
    return -1;
  }
  //ASIGNAMOS LOS DATOS AL SERVIDOR
  SV.sin_family = AF_INET;
  SV.sin_port = htons(PORT);
  SV.sin_addr = *((struct in_addr *)H->h_addr);
  bzero(&(SV.sin_zero),8);

  //NOS CONECTAMOS AL SERVIDOR
  if(connect(FD, (struct sockaddr *)&SV, sizeof(struct sockaddr)) == -1){
    perror("\t\t-->Error al conectarse con el servidor.");
    return -1;
  }
  //LLAMAMOS A RECV 
  nBytes = recv(FD,BUF,MAX2,0);
  BUF[nBytes] = '\0';
  printf("%s\n",BUF);
  char num1[MAX], num2[MAX], *num = (char *)malloc(MAX);
  printf("\t\t-->Envia numero 1:");
  scanf("%s",num);
  strcpy(num1,num);
  send(FD,num1,MAX2,0);
  printf("\t\t-->Envia numero 2:");
  scanf("%s",num);
  strcpy(num2,num);
  send(FD,num2,MAX2,0);
  nBytes = recv(FD,BUF,MAX2,0);
  BUF[nBytes] = '\0';
  printf("\n\t\t**RESULTADO: %s\n",BUF);
  close(FD);
}
