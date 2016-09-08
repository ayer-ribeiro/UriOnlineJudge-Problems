#include <stdio.h>

int main() {

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     double vet[6];
     vet[1] = 4.0;
     vet[2] = 4.5;
     vet[3] = 5.0;
     vet[4] = 2.0;
     vet[5] = 1.5;

     int a,b;
     scanf("%d %d",&a,&b);
     printf("Total: R$ %.2lf\n",vet[a]*b);
}
