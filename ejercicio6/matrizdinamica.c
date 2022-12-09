#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*resumen del problema:
 * lo primero que debmemos de hacer es generar una matriz dinamica 
 * es decir un puntero que apunta a una array de puntero es decir doble puntero
 * luego debemos rellenar la fila 1 de1 
 *
 * FILA 1 = todos los elementos a 1
 * 
 * COLUMNA 1 = todos los elementos a 1
 *
 * reto de elementos :
 *
 * a12=a02 + a11 // 3 = 2 + 1
 * a12 = 3
 * a02 = 1
 * a11 = 2
 * */
/*[matriz]-> [submat1 , submat2 , submat3]
 *              |          |         |        
 *              v          v         v         //nota , las flechas son punteros
 *              
 *              1          1         1
 *
 *              1          2         3
 *
 *              1          3         6
 * */
int main (int argc, char * argv []){
  int m,n,i,j; /*m filas , n columans , j e i son para recorrer las matrices*/
  long ** matriz; /*doble puntero para la matriz*/
  
  /*bucle de creacion de memoria*/
  if(argc!=3){
    r = 0;
  }
  m =atoi(argv[1]);
  n =atoi(argv[2]);
  matriz = malloc(sizeof(long)*m);
   if(matriz == NULL){
    exit(71);
  }
  for(i=0;i<m;i++){
    matriz[i] =malloc(sizeof(long)*n); 
    if(matriz[i] == NULL){
    exit(71);
    }
  }
  
  /*parte del codigo que realiza la funcion de las matrices dinamicas*/
  /*primero la rellenamos*/
  for(i =0;i<m;i++){
    for(j = 0;j<n;j++){
      if(i == 0){
        matriz[i][j]=1;
      }
      else if(j == 0){
        matriz[i][j] = 1;
      }
      else{
        matriz[i][j] = matriz[i-1][j] + matriz[i][j-1] ;
      }
    }
  }
  
  /*luego la imprimimos*/
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){ 
      printf("%li",matriz[i][j]);
      if(j<n-1){
        printf("ñ\t");
      }
    }
    printf("\n");
  }
  /*recordar posibles problemas de formato , alomejor la ultima iteracion no necesita el \t*/

  /*bucle de liberar la memoria*/
  for(i = 0 ; i<m; i++){
    free(matriz[i]);
    matriz[i] = NULL;
  }
  free(matriz);
  matriz = NULL;

   
  return 0;
}
