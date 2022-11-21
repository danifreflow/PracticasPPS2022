#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/* Si las soliciones son reales , discriminante == 1 , son imaginarias si son discriminante == -1
  Si son reales , se guardan en px1 y px2
   Si son imaginarias se guarda -b / 2a en px1 y el imaginario en px2
  NOTA: la parte imaginaria sera raiz de d /2a */
int resolver(double a, double b, double c, double* px1, double *px2);
double discriminante(double a ,double b , double c);


int resolver(double a, double b, double c, double* px1, double *px2){
  const double nan = sqrt(-1.0);
  double dis; int sol ;
  dis = discriminante(a,b,c);
   /*printf(" discriminante = %f\n",dis);*/
  if(a == 0.000000 ){
    if (b == 0.000000 ){
      *px1 = 0;
      *px2 = 0;
      sol = 3;
    }
    else{
    *px1 = (-1 * c)/ b;
    *px2 = nan;
     sol = 4;
    }
  }
  else if(dis >= 0.000000){
    if(dis == 0.00000){
      *px1 = *px2 = -b / 2*a;
      sol = 1;
    }else{
    *px1 = (-b + sqrt(dis)) / 2*a;
    *px2 = (-b - sqrt(dis)) / 2*a;
    sol = 1;
    }
  }
  else if(dis < 0.000000){
    *px1 = -b / 2*a;
    *px2 = dis/2*a;
    sol = 2;
  }
  /*printf(" px1 = %f\n",*px1);
  printf("px2 = %f\n",*px2);*/
  return sol;
}


double discriminante(double a ,double b , double c){
  double resultado;
  resultado = (b*b) - (4*a*c);
  return resultado;
}
