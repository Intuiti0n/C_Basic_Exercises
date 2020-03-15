#include <stdio.h>

/*
Construa um programa em linguagem C/C++ para imprimir os números entre 1 e N (dado pelo utilizador).
Faça versões utilizando os três tipos de ciclos: for for ..., do ... while, e while ...
*/
void printToNFor(int N){
    int i;
    for(i=1;i<=N;i++)
        printf("%d\n",i);
    printf("\n");
}

void printToNWhile(int N){
    int i=1;
    while(i<=N){
        printf("%d\n",i++);
    }

    printf("\n");
}

void printToNDoWhile(int N){
    int i=1;

    do{
        printf("%d\n",i++);
    }
    while (i<=N);
}
/*
Construa um programa em linguagem C/C++ para calcular a soma dos números inteiros entre 1 e N (dado pelo
utilizador). Faça as versões utilizando os três tipos de ciclos: for ..., do ... while, e while ... Altere o programa
para calcular exclusivamente a soma dos números pares entre 1 e N.
*/
int sumToNFor(int N){
    int sum=0,i;
    for(i=1;i<N;i++)
        sum+=i;

    return sum;
}

int sumToNWhile(int N){
    int sum=0,i=1;
    while(i<=N)
        sum+=i++;

    return sum;
}

int sumToNDoWhile(int N){
    int sum=0,i=1;
    do{
        sum+=i++;
    }
    while(i<=N);

    return sum;
}

/*
Construa um programa para imprimir no écran os 256 caracteres ASCII (nota: Utilize printf(“%c “, i))
*/
void print256(void){
    int i=0;

    for(i=0;i<256;i++)
        printf("Char num %d = %c",i,i);
}

/*
Dado um numero N escrever a tabuada dos N. Crie três soluções utilizando os três tipos de ciclos da linguagem
Exemplo: N? 5
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
...
5 x 10 = 50
*/
void tabuadaNFor(int N){
    int i;

    printf("Tabuada do %d:\n",N);
    for(i=1;i<=10;i++)
        printf("%d * %d = %d\n",N,i,N*i);
}

void tabuadaNWhile(int N){
    int i=1;

    printf("Tabuada do %d:\n",N);
    while(i<=10){
        printf("%d * %d = %d\n",N,i,N*i);
        i+=1;
    }
}

void tabuadaNDoWhile(int N){
    int i=1;

    printf("Tabuada do %d:\n",N);

    do{
        printf("%d * %d = %d\n",N,i,N*i);
        i+=1;
    }while(i<=10);
}

/*
Construa um programa em C/C++ que leia uma quantidade não determinada de números positivos. Calcule a
quantidade de números pares e ímpares, a média de valores pares e a média geral dos números lidos. O número
que encerrará a leitura será zero.
*/
void readNumbers(void){
    int n=0,pares=0,impares=0;
    //double mediaPares=0,mediaGeral=0;
    int somatorio_pares=0,somatorio_geral=0;
    int num=100;
    while(num!=0){
        printf("Insira numero:");
        scanf("%d",&num);

        n+=1;
        somatorio_geral +=num;
        if(num%2==0){
            pares+=1;
            somatorio_pares+=num;
        }
        else {
            impares+=1;
        }
    }

    printf("Numeros: %d\n",n);
    printf("Pares: %d\n",pares);
    printf("Impares: %d\n",impares);
    printf("Media pares: %.02f\n",(double)(somatorio_pares)/ pares);
    printf("Media: %.02f\n",(double)(somatorio_geral)/ n);
}


/*
Construa um programa para desenhar triângulos de dimensão N (fornecido pelo utilizador).
*/

void drawTriangle(int sizeN){
    int i=0,j=0;
    for(i=0;i<sizeN;i++){
        for(j=0;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}
int main()
{
    //    printToNFor(15);

    //    printToNWhile(10);

    //    printToNDoWhile(10);

    //    tabuadaNFor(5);

    //    tabuadaNWhile(4);

    //tabuadaNDoWhile(3);

    //readNumbers();

    drawTriangle(5);
    return 0;
}
