#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int parser(FILE * file){
  int Bcampos = 1,i=0;j;
  char linea[MaxLinea];
  char * campos[MaxCampos];
  char * token; /*token es donde voy a ir guardando las partes de strtok*/
  /*necesito usar strtok para cortar por las comas*/  
  /*Como gestionar la movida , guardas la linea 1 , y lees la demas separadas por comas*/
  file = fopen(argv[1],"r");/*abro el archivo*/
  while(fgets(linea,MaxLinea,file)){ /*mientras se pueda coger una linea*/
  token = strtok(linea,","); /*cargo en token la primera palabra hasta la coma*/

  while(token != NULL){
    if(Bcampos == 1){ /*si es la primera linea , guardo los tokens en la array*/
      campos[i] = strdup(token);
      /*printf("Carga el campo %s",token)*/
      token = strtok(NULL,","); /*cargamos el siguiente campo*/
      i++;
    }
    else{/*si no imprimo los tokens en función de su campo*/
      printf("%s: %s"campos[i],token);
      if(i == j){
        printf("\n"); /*Si i == J , es el ultimo campo y por tanto imprimo salto de linea*/ 
      }
      else{
        printf(";"); /*Si no , no es el ultimo campo y pongo ;*/
      }
      token = strtok(NULL,",");
      i++;
    }
  }
  
  if(Bcampos == 1){ /*si ha sido la primera iteracion*/
   j = i; /*cargo en j los datos totales*/
   Bcampos = 0 ; /*ya no es la primera iteracion*/
  }
  
   i = 0;
  }
  fclose(file);
  return 0;
}



/*este metodo lo utilizo para copiar la primera linea a la array campos*/
char * strdup(char * src){
  char * str;
  size_t size = strlen(src)+1;
  str = malloc(size);
  if(str){
    memcpy(str,src,size);
  }
  return str;
}
