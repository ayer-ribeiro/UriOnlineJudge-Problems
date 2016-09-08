#include <stdio.h>

int main() {
    double sal,vendas;
    char nome[100];
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     scanf("%s %lf %lf",nome,&sal,&vendas);
     printf("TOTAL = R$ %.2lf\n",sal+vendas*0.15);

    return 0;
}
