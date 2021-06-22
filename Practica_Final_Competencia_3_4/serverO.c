//LIBRERIAS
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

#define TAM 300
#define TAM2 925

int puerto_serv = 0;

int main(int argc, char *argv[]){
  system("clear");
  if(argc < 2){
    printf("\t\t-->Ingrese el puerto:");
    char Puerto[4];
    gets(Puerto);
    puerto_serv = atoi(Puerto);
  }else{
    puerto_serv = atoi(argv[1]);
  }
  int FD,FD2,LEN_CLIENT;
  int SSOCKET;

  struct sockaddr_in servidor;
  struct sockaddr_in cliente;

  //CONFIGURAMOS EL SERVIDOR
  servidor.sin_family = AF_INET; //DECLARAMOS LA NATURALEZA DEL SOCKET ( TCP/IP )
  servidor.sin_port = htons(puerto_serv); //DECLARAMOS EL PUERTO DEL SERVIDOR 
  servidor.sin_addr.s_addr = INADDR_ANY; //CUALQUIER CLIENTE PUDE CONECTARSE
  bzero(&(servidor.sin_zero),8); //RELLENAMOS CON CEROS
  
  SSOCKET = socket(AF_INET, SOCK_STREAM,0);
  FD = SSOCKET;
  if(SSOCKET < 0){
    printf("\t\t-->Error al abrir el socket\n");
    return -1;
  }else{
    printf("\t\t-->Exito al abrir el socket\n");
  }
  //CREAMOS EL SERVIDOR CON BIND
  if(bind(SSOCKET,(struct sockaddr*)&servidor, sizeof(struct sockaddr)) == -1){
    printf("\t\t-->Error con el BIND");
    return -1;
  }else{
    printf("\t\t-->Bind asignado\n");
  }
  if(listen(SSOCKET,5) == -1){
    printf("\t\t-->Error en escucha\n");
    return -1;
  }
  //aceptamos conexiones
  printf("\t\tEn escucha...\n");
  while(1){
    LEN_CLIENT = sizeof(struct sockaddr_in);
    if((FD2 = accept(SSOCKET,(struct sockaddr*)&cliente,&LEN_CLIENT)) == -1){
      printf("\t\tError en las conexiones\n");
      return -1;
    }
    send(FD2,"Estas dentro del servidor\n",TAM2,0);
    char NUM1[TAM],NUM2[TAM];
    int Bytes=0;
    Bytes = recv(FD2,NUM1,TAM2,0);
    NUM1[Bytes] = '\0';
    send(FD2,NUM1,TAM,0);
    Bytes = recv(FD2,NUM2,TAM2,0);
    NUM2[Bytes] = '\0';
    send(FD2,NUM2,TAM2,0);

    char aa[202],bb[202];
    int a[202],b[202],c[203];
    int i,j,k,ki;
    strcpy(aa,NUM1);
    strcpy(bb,NUM2);
    int m,n,len;
    m=strlen(aa);
    n=strlen(bb);
    len = ( m > n)? m:n ;
    for ( i=0; i<m; i++)
      a[i]=aa[i]-'0'; //i=m;
    for ( j=0; j<n; j++)
      b[j]=bb[j]-'0'; //j=n;
    for( i=m-1,j=n-1,k=len-1; i>=0 && j>=0; i--,j--,k--){
      c[k] = a[i] + b[j];
    }
    for( ;i>=0; i--,k--)
      c[k] = a[i];
    for( ;j>=0; j--,k--)
      c [k] = b [j]; // Alto guardado
         // Cada décimo
    for( k=len-1; k>0; k--){
      if( c[k] >9 ){
	c[k] = c[k]%10;
        c[k-1] += 1;
      }
    }
    char res[TAM];
    for( k=0; k<len; k++)
      sprintf(&res[strlen(res)],"%d",c[k]);
    send(FD2,res,TAM2,0);


    close(FD2);
  }
  close(SSOCKET);
  
  
  return 0;
} 

