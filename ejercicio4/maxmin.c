#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char * argv[]){
  FILE * fp; /*fp viene de file pointer , puntero al archivo a leer*/
  float max,min; /*max es el numero mayor , min es el numero menor*/
  float actual; /*el que estamos leyendo actualmente*/
  int PrimeraIteracion = 1 ; /*primera iteracion necesita copiar el primer valor en min y max*/
  fp = fopen(argv[1],"r"); /*abrimos el primer fichero en modo de lectura*/
  if (argc != 2){
    printf("no archivo\n");
    return -1;
  }/*si los argumenros son menos de dos error devuelvo -1*/
  if (fp == NULL){
    printf("no se puede leer\n");
    return -1;
  } /*si el fp es NULL ha habido error en el fichero y no se ha podido leer*/
  while(fscanf(fp,"%f",&actual) == 1){
    if (PrimeraIteracion == 1){
      max = actual;
      min = actual;
      PrimeraIteracion--;
    }
    else{
      if(actual > max){
        max = actual;
      }
      if(actual<min){
        min = actual;
      }
    }
  }
  /*si no se ha decrementado PrimeraIteracion significa 
   * que no se ha entrado en el while por tanto el fichero esta vacio */
  if (PrimeraIteracion == 1 ){
    printf("fichero vacio\n");
      max = 0.00;
      min = 0.00;
  }
  printf("%10.2f %10.2f\n",max,min);
  fclose(fp);
  return 0;
}
