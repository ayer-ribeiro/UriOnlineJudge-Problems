#include <stdio.h>

int main() {

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     double a,b,c;
     double r1,r2;

     scanf("%lf %lf %lf",&a,&b,&c);
     double delta = b*b - 4*a*c;
     if(delta < 0 || a == 0) {
        printf("Impossivel calcular\n");
        return 0;
     }
     r1= (-b+sqrt(delta))/(2.0*(double)a);
     r2= (-b-sqrt(delta))/(2.0*(double)a);
     printf("R1 = %.5lf\nR2 = %.5lf\n",r1,r2);

    return 0;
}
