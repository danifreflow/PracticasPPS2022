#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 64
/*para multiplicar matrices el numero de columnas de A = numero de filas de B*/
/*
  A = 2x3  Esto quiere decir que A tiene dos filas y tres columnas
  entonces en este caso para que la multiplicación sea valida 
  A = 3x3  * b = 3x1
        |        |
        |        |         
        |________|
            =
   */
/*




[ 1  7 ]        [ 3  3 ]     [ 38  17 ]
          x               =   
[ 2  4 ]        [ 5  2 ]     [ 26  14 ]

 A        x        B      =      C

FILA POR COLUMNA PARA MULTIPLICAR MATRICES
*/
int main()
{
   int a,b,c;  /*a = columnas primera , b = columnas segunda , 
               c = b por que si no no se pueden multiplicar y d columnas de la segunda matriz
                la matriz solucion sera sol[a][d]*/
  /*int ins;*/
  int i , j, k;
  
  /*me genero las matrices porque ansii c no me deja poner valores fijos*/
  int mat1[MAX][MAX];
  int mat2[MAX][MAX];
  int sol[MAX][MAX];
  /*introduzco los valores utilizando scanf*/
  scanf("%d %d %d ", &a , &b ,&c);
  /*printf("numero de filas primera matriz%d \n",a);*/
  /*scanf("%d",&b);*/
  /*printf("numero de :filas segunda matriz%d \n",b);
  printf("numero de filas tercera matriz %d \n",c);*/
  /*scanf("%d",&c);*/
  /*printf("numero de filas cuarta matriz %d \n",d);*/

  
/*:  printf("primera matriz\n");
  cargamos los valores de la primera matriz*/
  for(i=0;i<a;i++)
  {
    for(j=0; j < b ; j++)
    {
      scanf("%d ",&mat1[i][j]);
      /*printf(" el numero mat1[%d][%d] = %d\n",i,j,mat1[i][j]);*/
    }
  }
  /*cargamos los valores de la segunda matriz*/
  for(i=0;i<b;i++)
  {
    for(j=0;j<c;j++)
    {
      scanf("%d ",&mat2[i][j]);
      /*printf("el numero de mat2[%d][%d] = %d\n",i,j,mat2[i][j]);*/
    }
  }
  /*imprimimos primera Matriz
  
  for(i=0;i<a;i++)
  {
    for(j=0;j<d;j++)
    {
      printf("%d ",mat1[i][j]);
    }
    printf("\n");
  }*/
  
  /*imprimimos segunda matriz
  
  for(i=0;i<b;i++)
  {
    for(j=0;j<c;j++)
    {
      printf("%d ",mat2[i][j]);
    }
    printf("\n");
  }*/
  /*Aqui multiplico las matrices*/
  for(i=0;i<a;i++){
    for(j=0;j<c;j++){
      sol[i][j] = 0;
      for(k=0;k<b;k++){
        /*+= va incrementando mi variable , es como sol[i][j] = sol[i]][j] + (mat1[i][k]*mat2[k][j])*/
        sol[i][j]+= mat1[i][k]*mat2[k][j];
      }
    }
  }
  /*por ultimo imprimo mi matriz , si es el ultimo elemento de la fila imprimo salto de linea , sino imprimo espacio*/
  for(i=0;i<a;i++){
    for(j=0;j<c;j++){
      if((j+1) == c){
        printf("%d\n",sol[i][j]);
      }
      else{
        printf("%d ",sol[i][j]);
      }
    }
  }

 return 0;

}
