#include <stdio.h>

int main() {

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     int x;
     scanf("%d",&x);
     int a,m,d;
     a = x/365;
     x = x%365;
     m = x/30;
     x = x%30;
     d = x;


     /*
     h = a/3600;
     a = a%3600;
     m = a/60;
     a = a%60;
     s = a;
     */
     printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n",a,m,d);

    return 0;
}
