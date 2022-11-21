#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int resolver(double a, double b, double c, double* px1, double *px2);
int discriminante(double a ,double b , double c);

int main(){
  double a , b , c ;
  double p1,p2;
  while(scanf("%lf %lf %lf",&a,&b,&c)== 3){
    /*resolver(a,b,c,&p1,&p2);*/
    printf("Caso %d: %f, %f\n",resolver(a,b,c,&p1,&p2),p1,p2);
  }
  return 0;
}
