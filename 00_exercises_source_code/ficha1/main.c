#include <stdio.h>

/*
Escreva um algoritmo e correspondente programa em C/C++ para calcular o maior de dois números inteiros
fornecidos pelo utilizador (N1 e N2).
*/
int max2(int a, int b){
    if(a>b)
        return a;
    else return b;
}

/*
Escreva um algoritmo e correspondente programa em C/C++ para calcular o maior de três números inteiros
dados pelo utilizador (N1, N2 e N3).
*/
int max3(int a, int b,int c){
    if(a>b&&a>c)
        return a;
    else if(c>b&&c>a)
        return c;
    else return b;
}

/*
Escreva um algoritmo e correspondente programa em C/C++ para calcular, dados três números inteiros, a soma
dos dois menores.
*/
int returnSum2lowerValues(int a, int b, int c){
    return (a+b+c - max3(a,b,c));
}

/*
 * Construa um programa em C/C++ que calcule a média aritmética das 3 notas de um aluno e mostre, além do
valor da média, uma mensagem de "Aprovado", caso a média seja igual ou superior a 9.5, ou a mensagem
"Reprovado", caso contrário.
*/
double media3(int a,int b,int c){
    double media =(double)(a+b+c) / 3;
    if(media >= 9.5)
        printf("Aprovado!\r\n");
    else printf("Reprovado!!\r\n");

    return media;
}

/*
Construa um algoritmo e correspondente programa em C/C++ que leia um nº inteiro e mostre uma mensagem
indicando se este número é par ou ímpar, e se é positivo ou negativo.
*/
void analyseInt(int x){
    if(x%2==0)
        printf(("Par!\n"));
    else printf("Impar!\n");

    if(x>=0)
        printf("Positivo!\n");
    else printf("Negativo!\n");

}

int main()
{
    //printf("Hello World!\n");
    printf("Media: %lf\n",media3(4,4,5));

    printf("max2: %d\n",max2(4,5));

    printf("max3: %d\n",max3(4,5,6));

    printf("%d\n",returnSum2lowerValues(2,3,4));

    analyseInt(10);
    return 0;
}
