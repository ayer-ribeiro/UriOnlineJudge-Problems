#include <stdio.h>

int main() {

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     double a,b,c,d,f;
     scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
     double media = (2.0*a + 3.0*b + 4.0*c +d)/10.0;
     if(media >=7){
        printf("Media: %.1lf\nAluno aprovado.\n",media);
     }else if(media < 5){
        printf("Media: %.1lf\nAluno reprovado.\n",media);
     }else{
        scanf("%lf",&f);
        printf("Media: %.1lf\n",media);
        media = (media + f)/2.0;
        printf("Aluno em exame.\nNota do exame: %.1lf\n",f);
        if(media>=5)printf("Aluno aprovado.\n");
        else printf("Aluno reprovado.\n");
        printf("Media final: %.1lf\n",media);

     }
     return 0;

}
