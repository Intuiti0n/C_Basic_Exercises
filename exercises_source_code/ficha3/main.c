//ficha 3 algoritmos com ciclos - Desenho

#include <stdio.h>

/*Escreva uma função void nl(void) que simplesmente mude o cursor de linha (a função faz um printf("\n").*/
void nl(void){
    printf("\n");
}

/*Escreva uma função que desenhe uma linha com N símbolos (caracteres do tipo simb passado como parâmetro à
função) void linha(int N, char simb).*/
void linha(int N, char simb){
    int i;
    for(i=0;i<N;i++){
        printf("%c",simb);
    }
}

/*Escreva uma função void desenha_quad(int N, char simb) que desenha quadrados de N*N
símbolos.*/
void desenha_quad(int N, char simb){
    int i;
    for(i=0;i<N;i++){
        linha(N,simb);
        nl();
    }
}
/*Escreva uma função void desenha_tria(int N, char simb) que desenha triângulos de N*N
símbolos.*/
void desenha_tria(int N, char simb){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N-i;j++){
            printf("%c",simb);
        }
        nl();
    }
}

/*Escreva uma função void desenha_quad_vazio(int N, char simb) que desenha quadrados com o
interior não preenchido de N*N símbolos.*/
void desenha_quad_vazio(int N, char simb){
    int i,j;
    for(i=0;i<N;i++){
        if(i==0||i==N-1){
            linha(N,simb);
        }
        else{
            for(j=0;j<N;j++){
                if(j==0||j==N-1)
                    printf("%c",simb);
                else printf(" ");
            }
        }
        nl();
    }
    nl();
}

/*Escreva uma função void desenha_arvore(int N, char simb) que desenha uma arvore de natal
com dimensão N utilizando um dado símbolo. Quer o tronco quer a copa têm altura N.*/
void desenha_arvore(int N, char simb){
    int i,j;

    if(N==1)
        printf("%c\n%c\n",simb,simb);
    else{
        for (i=0;i<N;i++) {
            for (j=0;j<N;j++) {
                if(j==N-1)
                    printf()
            }
        }
    }


}
/*Escreva uma função void desenha_cobra(int N, char simb) que desenha uma cobra com dimensão
N*2 por N utilizando um dado símbolo.*/

/*Escreva um programa principal que desenhe 10 vezes todos os desenhos anteriores começando com a dimensão 1
e acabando com a dimensão 10.*/



int main()
{
    //printf("Hello World!\n");

    nl();
    linha(4,'*');
    nl();
    desenha_quad(6,'#');
    nl();
    desenha_tria(5,'$');
    nl();


    return 0;
}
