#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
4.1) Escreva uma função void preenche_aleatorio(int v[], int n) que preencha um vetor com n números inteiros
aleatórios com valores entre 1 e 100
*/
void preenche_aleatorio(int v[], int n){
    int i=0;
    for(i=0;i<n;i++){
        v[i]=rand()%100 + 1;
    }

}

/*4.2) Escreva um algoritmo que mostre no écran, devidamente formatado um vetor com n elementos void
mostra_vetor(int v[], int n)*/
void mostra_vetor(int v[], int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("Elemento n %d = %d\n",i,v[i]);
    }
}

void print_vector(int v[], int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
/*
4.3) Construa o programa principal que lhe permita testar as duas funções anteriores (criando um vetor com 20
elementos e mostrando o seu conteúdo no écran). Vá actualizando o programa principal com testes adequados às
restantes alíneas do exercício.
*/

/*
4.4) Escreva uma função que calcule a soma dos elementos de um vetor com n elementos inteiros int calcula_soma(int
v[], int n).
*/
int calcula_soma(int v[], int n){
    int i=0,sum=0;
    for(i=0;i<n;i++){
        sum+=v[i];
    }
    return sum;
}

/*
4.5) Escreva uma função que calcule a média dos elementos de um vetor com n elementos inteiros double
calcula_media(int v[], int n).*/
double calcula_media(int v[], int n){
    int soma = calcula_soma(v,n);
    double media = soma / (double) n;

    return media;
}


/*
4.6) Escreva uma função int pesquisa(int v[], int n, int elem) que dado um vetor com n elementos inteiros permita
pesquisar a existência de um dado valor (fornecido pelo utilizador) nesse vetor retornando a posição respetiva do
elemento no vetor ou -1 caso não exista.*/
//linear search
int pesquisa(int v[], int n, int elem){
    int i=0;
    for(i=0;i<n;i++){
        if(v[i]==elem)
            return i;
    }
    return -1;
}

/*
4.7) Escreva uma função que permita ordenar um vetor com n números inteiros void ordena(int v[], int n)
*/
//Selection Sort
void ordena_SelectionSort(int v[], int n){
    int i=0,j=0;

    for(j=0;j<n-1;j++){
        int iMin=j;
        for(i=j+1;i<n;i++){
            if(v[i]<v[iMin])
                iMin=i;
            if(iMin!=j){
                //swap using xor
                v[j]^=v[iMin];
                v[iMin]^=v[j];
                v[j]^=v[iMin];
            }
        }
        print_vector(v,n);
    }
}

/*
4.8) Escreva uma função que dados dois vetores com o mesmo numero de elementos some os elementos, um a um, dos
dois vetores gerando um novo vetor void soma_vetores(int v1[], int v2[], int v3[], int n)
*/
void soma_vetores(int v1[], int v2[], int v3[], int n){
    int i=0;
    for(i=0;i<n;i++){
        v3[i]=v1[i]+v2[i];
    }
}

/*
4.9) Escreve uma função int ocorrencias(int v[], int n, int elem) que dado um vetor e um dado número inteiro, calcule
o número de ocorrências desse número no vetor.
*/
int ocorrencias(int v[], int n, int elem){
    int i=0,count=0;
    for(i=0;i<n;i++){
        if(v[i]==elem)
            count++;
    }

    return count;
}

/*
4.10) Escreva uma função que dado um vetor v1 calcula o seu inverso e coloque num vetor v2: void inverte_vetor(int
v1[], int v2[], int n)*/
void inverte_vetor(int v1[], int v2[], int n){
    int i=0,v2Index=0;

    for(i=n-1;i>=0;i--,v2Index++){
        v2[v2Index]=v1[i];
    }
}

/*
4.11) Escreva uma função semelhante à do exercício anterior mas que inverta o próprio vetor de entrada: void
inverte_vetor(int v[], int n)
**/
void inverte_vetor2(int v[], int n){
    int i=0,v2Index=0,aux=0;

    for(i=n-1;i>=0;i--,v2Index++){
        aux=v[v2Index];
        v[v2Index]=v[i];
        v[i]=aux;
    }
}


int main()
{
    srand(time(NULL));
    printf("Hello World!\n");

    int vec[10]={2,8,5,3,9,4,1,0,10,23};

    //preenche_aleatorio(vec,10);

    ordena_SelectionSort(vec,10);
    return 0;
}
