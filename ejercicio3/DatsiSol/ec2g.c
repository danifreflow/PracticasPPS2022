#include <math.h>

int resolver(double a, double b, double c, double *px1, double *px2)
{
  int caso = 0;
  if ( a == 0 && b == 0 ) { /* Cualquier valor de c, incluido 0 */
    /* NO EXISTE SOLUCION */
    *px1 = 0; 
    *px2 = 0; 
    caso = 3;
  } else if ( a == 0 ) {
    /* Esto es una ecuación de 1 grado */
    *px1 = - c / b;
    *px2 = sqrt(-1);
    caso = 4;
  } else if ( (b*b - 4*a*c) < 0 ) {
    /* Soluciones complejas conjugadas */
    *px1 = - b / (2*a);
    *px2 = fabs(sqrt(-b*b + 4*a*c) / (2*a));
    caso = 2;
  } else {
    /* Formula habitual con solución real */
    *px1 = ( -b + sqrt(b*b - 4*a*c) ) / ( 2*a );
    *px2 = ( -b - sqrt(b*b - 4*a*c) ) / ( 2*a );
    caso = 1;
  }
  return caso;
}

