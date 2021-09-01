#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define LIN 5
#define COL 10


/*
5.1) Escreva uma função void preenche_aleatorio(int x[LIN][COL], int nl, int nc) que preencha uma matriz de
dimensão nl x nc elementos com números inteiros aleatórios com valores entre 1 e 100*/
void preenche_aleatorio(int x[LIN][COL], int nl, int nc){
    int i=0,j=0;

    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            x[i][j]=rand()%100 + 1;
        }

    }
}

/*
 *
5.2) Escreva um algoritmo que mostre no écran, devidamente formatada a matriz com nl x nc elementos void
mostra_matriz(int x[LIN][COL], int nl, int nc)
*/
void mostra_matriz(int x[LIN][COL], int nl, int nc){
    int i=0,j=0;

    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
}
/*
5.3) Construa o programa principal que lhe permita testar as duas funções anteriores (criando uma matriz com 5x10
elementos e mostrando o seu conteúdo no écran). Vá actualizando o programa principal com testes adequados às
restantes alíneas do exercício. Utilize as instruções: #define LIN 5 e #define COL 10 para definir (e poder
alterar facilmente o tamanho da matriz.*/

/*
5.4) Escreva uma função que calcule a soma dos elementos uma matriz com nl x nc elementos inteiros int
calcula_soma(int x[LIN][COL], int nl, int nc).*/
int calcula_soma(int x[LIN][COL], int nl, int nc){
    int i=0,j=0,sum=0;

    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            sum+= x[i][j];
        }
    }
    return sum;
}
/*
5.5) Escreva uma função que calcule a média dos elementos de uma matriz com nl x nc elementos inteiros double
calcula_media(int x[LIN][COL], int nl, int nc).*/
double calcula_media(int x[LIN][COL], int nl, int nc){
    return calcula_soma(x,nl,nc) / (double) (nl*nc);
}

/*
5.6) Escreva uma função void preenche_borda(int x[LIN][COL], int nl, int nc) que preencha o rebordo da matriz
(elementos na coluna 0 ou coluna N-1 ou na linha 0 ou linha N-1) com zeros.
*/
void preenche_borda(int x[LIN][COL], int nl, int nc){
    int i=0,j=0;

    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            if(i==0||i==nl-1||j==0||j==nc-1)
                x[i][j]=0;
        }
    }
}

/*
5.7) Escreva uma função int pesquisa_matriz(int x[LIN][COL], int nl, int nc, int elem, int &co, int &li) que dado um
vetor com n elementos inteiros permita pesquisar a existência de um dado valor (fornecido pelo utilizador) nesse
vetor retornando nas variáveis co e li a posição (co/li) respetiva do elemento no vetor. A função deve retornar 1
caso encontre o elemento ou -1 caso esse elemento não exista na matriz.*/
int pesquisa_matriz(int x[LIN][COL], int nl, int nc, int elem, int *co, int *li){
    int i=0,j=0;

    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            if(x[i][j]==elem){
                *co=j;
                *li=i;
                return 1;
            }
        }
    }
    return -1;
}


/*
5.8) Escreva uma função que dadas duas matrizes com as mesmas dimensões some os seus elementos, um a um,
gerando uma nova matriz void soma_matrizes(int x1[LIN][COL], int x2[LIN][COL], int x3[LIN][COL], int nl,
int nc)
*/
void soma_matrizes(int x1[LIN][COL], int x2[LIN][COL], int x3[LIN][COL], int nl, int nc){
    int i=0,j=0;

    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            x3[i][j]=x1[i][j]+x2[i][j];
        }
    }
}


/*
5.9) Escreve uma função int ocorrencias(int x[LIN][COL], int nl, int nc, int elem) que dada uma matriz com nl x nc
elementos e um número inteiro, calcule o número de ocorrências desse número na matriz.
*/
int ocorrencias(int x[LIN][COL], int nl, int nc, int elem){
    int i=0,j=0,count=0;

    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            if(x[i][j]==elem)
                count++;
        }
    }

    return count;
}
/*
5.10) Escreve uma função void substitui_elemento(int x[LIN][COL], int nl, int nc, int elem1, int elem2) que dada uma
matriz com nl x nc elementos substitua todas as ocorrências na matriz no número elem1 por elem2.*/
void substitui_elemento(int x[LIN][COL], int nl, int nc, int elem1, int elem2){
    int i=0,j=0;

    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            if(x[i][j]==elem1)
                x[i][j]=elem2;
        }
    }
}
/*
5.11) Escreva uma função que dada que dada uma matriz qudrada com nl x nc elementos calcule a sua transposta e
coloque numa matriz x2: void transposta_matriz(int x[LIN][COL], int x2[COL][LIN], int nl, int nc)
*/
void transposta_matriz(int x[LIN][COL], int x2[COL][LIN], int nl, int nc){
    int i=0,j=0;

    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            x2[j][i]=x[i][j];
        }
    }
}
/*
5.12) Escreva uma função semelhante à do exercício anterior mas que calcule a transposta de uma matriz quadrada nxn
na própria matriz: void transposta_matriz_quad(int x[LIN][COL], int n)
*/

/*
5.13) Escreva uma função que calcule a multiplicação de duas matrizes: void multiplica_matriz(int x[LIN][COL], int
x2[COL][LIN], x3[LIN][LIN], int nl, int nc)
*/

int main()
{
    srand((unsigned int)time(NULL));
    printf("Hello World!\n");
    return 0;
}
