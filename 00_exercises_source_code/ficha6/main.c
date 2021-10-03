#include <stdio.h>
#include <stdlib.h>

#define N 8

/*Escreva uma função void preenche_tabuleiro(int tab[N][N], int val, int rep) que introduza
numa matriz de dimensão N x N elementos (N definido com um define, ex: #define N 8) rep
números inteiros com o valor Val, em posições aleatórias inicialmente vazias (incialmente
com o valor 0).
*/
void preenche_tabuleiro(int tab[N][N], int val, int rep)
{
    int k;
    for (k = 0; k < rep; k++)
    {
        int i = rand() % N, j = rand() % N;
        while (tab[i][j] != 0)
        {
            i = rand() % N;
            j = rand() % N;
        }
        tab[i][j] = val;
    }
}

/*Escreva um algoritmo que mostre no écran, devidamente formatada a matriz com N x N
elementos void mostra_matriz(int tab[N][N]).*/
void mostra_matriz(int tab[N][N])
{
    int i = 0, j = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%.2d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

/*Escreva uma função que retorne o número de elementos da matriz com o valor x, int
conta_elementos(int tab[N][N], int val). Teste a função contando o número de 1s e número
de 2s na matriz, o que deverá retornar respetivamente 10 e 5 para o exemplo apresentado.*/
int conta_elementos(int tab[N][N], int val)
{
    int count = 0, i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (tab[i][j] == val)
            {
                count++;
            }
        }
    }
    return count;
}

/*Escreva uma função void elimina_isolados(int tab[N][N], int val) que elimine da matriz,
todos os elementos com valor val, que não tenham nenhum elemento adjacente (na horizontal
ou vertical) com um valor diferente de 0, isto é, que estejam rodeados de zeros. Teste a
função, eliminando todos os 1s isolados e visualizando o conteúdo final da matriz, semelhante
ao apresentado na segunda matriz.*/
void elimina_isolados(int tab[N][N], int val)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)                       //Para todas as posições do tabuleiro
            if (tab[i][j] == val &&                   //se a posição tem a peça procurada
                (i == 0 || tab[i - 1][j] == 0) &&     // e está na primeira linha do tabuleiro ou tem um 0 acima
                (i == N - 1 || tab[i + 1][j] == 0) && // e está na ultima linha do tab ou tem um 0 abaixo
                (j == 0 || tab[i][j - 1] == 0) &&     // e está na primeira coluna do tab ou tem um 0 'a esquerda
                (j == N - 1 || tab[i][j + 1] == 0))   // e está na ultima coluna do tab ou tem um 0 'a direita
                tab[i][j] = 0;                        //limpa essa posição colocando la' um zero
}

/*Escreva uma função void move_pecas1(int tab[N][N], int dirx, int diry, int val) que
movimente todas as peças com valor val (1 ou 2) na direção dirx, diry (dirx e diry com
valores, -1, 0 ou 1). Por exemplo se dirx = 1 e diry = 0 e val = 2, todas as peças do jogador 2
serão movimentadas para a direita. Caso uma peça se movimente para cima de outra peça,
essa peça desaparece e caso se movimente para fora do tabuleiro a peça deseparece também.*/
void move_pecas1(int tab[N][N], int dirx, int diry, int val)
{
    int i, j, auxTab[N][N];
    //copiar tabuleiro atual
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            auxTab[i][j] = tab[i][j];

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) //Para todas as posições do tabuleiro
            if (tab[i][j] == val)
            {
                auxTab[i][j] = 0;                                                                 //tirar a peça do valor inicial
                if ((i + dirx >= 0 && i + dirx <= N - 1) && (i + diry >= 0 && i + diry <= N - 1)) //se a peça se mover para uma posiçao que esta dentro do tabuleiro, pode mover-se
                    auxTab[i + dirx][j + diry] = val;
                else
                    continue;
            }

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            tab[i][j] = auxTab[i][j];
}

/*Escreva uma função void move_pecas2(int tab[N][N], int dirx, int diry, int val) que
movimente todas as peças com valor val (1 ou 2) na direção dirx, diry (dirx e diry com valores,
-1, 0 ou 1). Por exemplo se dirx = 1 e diry = 0 e val = 1, todas as peças do jogador 1 serão
movimentadas para a direita. Esta função difere da anterior pois as peças deverão ser
movimentadas exclusivamente se a nova posição estiver livre e dentro do tabuleiro.*/
void move_pecas2(int tab[N][N], int dirx, int diry, int val)
{
    int i, j, auxTab[N][N];
    //copiar tabuleiro atual
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            auxTab[i][j] = tab[i][j];

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) //Para todas as posições do tabuleiro
            if (tab[i][j] == val)
            {

                if ((i + dirx >= 0 && i + dirx <= N - 1) && (i + diry >= 0 && i + diry <= N - 1)) //se a peça se mover para uma posiçao que esta dentro do tabuleiro, pode mover-se
                    if (tab[i + dirx][j + diry] == 0)
                    {
                        auxTab[i][j] = 0; //tirar a peça do valor inicial
                        auxTab[i + dirx][j + diry] = val;
                    }
                    else
                        continue;
            }

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            tab[i][j] = auxTab[i][j];
}

/*Crie uma função void mostra_tabuleiro(int tab[N][N])que permita visualizar a matriz como se
fosse um tabuleiro com peças (X e O) e com o formato indicado a seguir (ou
melhor…). A função deve permitir visualizar tabuleiros com qualquer dimensão.*/

char conv(short int peca)
{
   if (peca==1) return 'X';    
   else if (peca==2) return 'O';    
   else return ' ';    
}
void num()
{
	int i;
	for(i=0; i<N; i++) printf("  %2d",i+1);
}
void tra(int tip)  //tip==0 cima, 1-meio, 2-baixo
{
	int i;
	for(i=0; i<N; i++) printf("%c%c%c%c",206,205,205,205); //printf("|---");
	printf("%c\n",206);
}
void mostra_tabuleiro(int tab[N][N])
{
     num();
     printf("\n ");
     tra(0);
     int i,j;
     for(i=0; i<N; i++) {
         printf("%c",i+65);    
         for(j=0; j<N; j++)
              printf("%c %c ", 186, conv(tab[i][j])); 
         printf("%c%c \n ",186,i+65); 
		 if (i==N-1) tra(2); else tra(1);
     }
     num();
	 printf("\n\n");
}

int main()
{
    int i, j;
    srand((unsigned)time(NULL));

    int tabela[N][N] = {0, 0, 0, 0, 0};

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            tabela[i][j] = 0;
    /*Construa o programa principal que lhe permita testar as duas funções anteriores (criando uma matriz com 8x8
zeros e mostrando o seu conteúdo no écran). Em seguida deverá introduzir na matriz 10 elementos com o valor 1 e
5 elementos com o valor 2, em posições aleatórias e mostrar o conteúdo da matriz final. Vá
actualizando o programa principal com testes adequados às restantes alíneas do exercício. O
resultado final deverá ser semelhante ao apresentado na primeira matriz.*/

    preenche_tabuleiro(tabela, 1, 10);
    preenche_tabuleiro(tabela, 2, 5);
    mostra_matriz(tabela);

    move_pecas2(tabela, 0, 1, 1);
    mostra_matriz(tabela);
    return 0;
}
