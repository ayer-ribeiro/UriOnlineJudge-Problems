#include <stdio.h>

int main() {

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     int cod,quant;
     double valor;
     double total = 0;
     scanf("%d %d %lf",&cod,&quant,&valor);
     total+=(quant*valor);
     scanf("%d %d %lf",&cod,&quant,&valor);
     total+=(quant*valor);
     printf("VALOR A PAGAR: R$ %.2lf\n",total);

    return 0;
}
