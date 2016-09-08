#include <stdio.h>
int abss(int a){
    if(a<0) return a*-1;
    return a;
}


int main() {

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     int a,b,c;
     scanf("%d %d %d",&a,&b,&c);
     int maiorAB = (a+b+abss(a-b))/2;
     int maiorABC = (maiorAB+c+abss(maiorAB-c))/2;
     printf("%d eh o maior\n",maiorABC);

    return 0;
}
