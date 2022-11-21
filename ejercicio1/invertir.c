#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 1000
/*atoi devuelve el numero si se puede , devuelve 0 si no*/
char * strdup(char * src);

int main ()
{
  char  dato [M];
  char * datos [M];
  char * cero = "0";
  int contados = 0;
  int i = 0, j = 0 ;
  int limpiar;
  /*int datosEnteros [M];*/
  int inverso [M];
  /*FILE * fp ;*/
  /*fp = fopen(argv[1],"r");*/

  while(scanf("%s",dato) != EOF)
  {
   datos[contados] = strdup(dato);
   /*strcpy(datos[contados],dato);*/
   /* printf("se leyo %s\n",dato);*/
    contados ++;
  }
  /*for(i = 0 ; i < contados;i++){
    printf("se leyo datos %s\n",datos[i]);
    datosEnteros[i] = atoi(datos[i]);
  }*/
  for(i = 0; i < contados; i++){
/*    printf(" datosEntero %d\n",datosEnteros[i]);*/
    if( atoi(datos[i]) != 0){
      inverso[j] = atoi(datos[i]);
      j++;
    }
    if( atoi(datos[i]) == 0){
      if(strcmp(datos[i],cero) == 0){
        inverso[j] = atoi(datos[i]);
        j++;
      }
      else{
      limpiar = j;
      j--;
      while (j>=0) {
        if(j == 0){
          printf("%d\n",inverso[j]);
          j--;
        }
        else{
          printf("%d ",inverso[j]);
          j--;
        }
      }
      
      memset(inverso,'0',sizeof(int) * limpiar);
      j = 0;
      }
    }
    }
  
  
  
  return 0;

}

char * strdup(char * src)
{
  char * str;
  size_t size = strlen(src) + 1;
  str = malloc(size);
  if(str){
    memcpy(str,src,size);
  }
  return str;
}


