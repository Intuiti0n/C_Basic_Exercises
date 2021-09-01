/*5.1)  Escreva  uma  função  void  preenche_aleatorio(int  x[LIN][COL],  int  nl,  int  nc) que  preencha  uma  matriz  de 
dimensão nl x nc elementos com números inteiros aleatórios com valores entre 1 e 100 
5.2)  Escreva  um  algoritmo  que  mostre  no  écran,  devidamente  formatada  a  matriz  com  nl  x  nc  elementos  void
mostra_matriz(int x[LIN][COL], int nl, int nc)
5.3)  Construa o programa principal que lhe permita testar as duas funções anteriores (criando uma matriz com 5x10 
elementos e mostrando o seu conteúdo no écran). Vá  actualizando o programa principal com testes adequados às 
restantes alíneas do exercício. Utilize as instruções: #define LIN 5 e #define COL 10 para definir (e poder 
alterar facilmente o tamanho da matriz. 
5.4)  Escreva  uma  função  que  calcule  a  soma  dos  elementos uma  matriz  com  nl  x  nc  elementos  inteiros  int
calcula_soma(int x[LIN][COL], int nl, int nc). 
5.5)  Escreva  uma  função que calcule a  média dos elementos de uma  matriz com  nl  x  nc elementos inteiros  double
calcula_media(int x[LIN][COL], int nl, int nc). 
5.6)  Escreva  uma  função  void  preenche_borda(int  x[LIN][COL],  int  nl,  int  nc) que  preencha  o  rebordo  da  matriz 
(elementos na coluna 0 ou coluna N-1 ou na linha 0 ou linha N-1) com zeros. 
5.7)  Escreva uma funçãoint pesquisa_matriz(int x[LIN][COL], int nl, int nc, int elem, int &co, int &li) que dado um 
vetor com n elementos inteiros permita pesquisar a existência de um dado valor (fornecido pelo utilizador) nesse 
vetor retornando nas variáveis co e li a posição (co/li) respetiva do elemento no vetor. A função deveretornar 1 
caso encontre o elemento ou -1 caso esse elemento não exista na matriz. 
5.8)  Escreva  uma  função  que  dadas  duas  matrizes  com  as  mesmas  dimensões  some  os  seus  elementos,  um  a  um, 
gerando uma nova matriz  void soma_matrizes(int x1[LIN][COL], int x2[LIN][COL], int x3[LIN][COL], int nl, 
int nc)
5.9)  Escreve uma função int ocorrencias(int x[LIN][COL], int nl, int nc, int elem)  que dada uma matriz com nl x nc 
elementos e um número inteiro, calcule o número de ocorrências desse número na matriz. 
5.10)  Escreve uma função void substitui_elemento(int x[LIN][COL], int nl, int nc, int elem1, int elem2) que dada uma 
matriz com nl x nc elementos substitua todas as ocorrências na matriz no número elem1 por elem2. 
5.11)  Escreva uma  função que dada que dada uma  matriz qudrada com  nl x  nc elementos calcule a sua transpostae 
coloque numa matriz x2: void transposta_matriz(int x[LIN][COL], int x2[COL][LIN], int nl, int nc)
5.12)  Escreva uma função semelhante à do exercício anterior mas que calcule a transposta de uma matriz quadrada nxn 
na própria matriz: void transposta_matriz_quad(int x[LIN][COL], int n)
5.13)  Escreva uma função que calcule a multiplicação de duas matrizes:  void multiplica_matriz(int x[LIN][COL], int 
x2[COL][LIN], x3[LIN][LIN], int nl, int nc)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LIN 5
#define COL 8

// 5.1)
void preenche_aleatorio(int x[LIN][COL], int nl, int nc) 
{
	for(int i=0; i<nl; i++)
		for(int j=0; j<nc; j++)
			x[i][j]=1+rand()%100;
}

// 5.2)
void mostra_matriz(int x[LIN][COL], int nl, int nc)
{
	for(int i=0; i<nl; i++) {
		for(int j=0; j<nc; j++)
			printf("%3d",x[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
// 5.2) Outra resolução
void mostra_matriz2(int x[LIN][COL], int nl, int nc)
{
	printf("-");
	for(int j=0; j<nc; j++) printf("----");
	printf("\n");
	for(int i=0; i<nl; i++) {
		printf("|");
		for(int j=0; j<nc; j++)
			printf("%3d|",x[i][j]);
		printf("\n-");
		for(int j=0; j<nc; j++) printf("----");
		printf("\n");
	}
	printf("\n\n");
}

// 5.4)
int calcula_soma(int x[LIN][COL], int nl, int nc)
{
	int soma = 0;
	for(int i=0; i<nl; i++) 
		for(int j=0; j<nc; j++)
			soma += x[i][j];
	return soma;
}
// 5.5)
double calcula_media(int x[LIN][COL], int nl, int nc)
{
	return (float)calcula_soma(x,nl,nc)/(nl*nc);
}
//5.6)
void preenche_borda(int x[LIN][COL], int nl, int nc) 
{
	for(int i=0; i<nl; i++)
		for(int j=0; j<nc; j++)
			if(i==0 || j==0 || i==nl-1 || j==nc-1)
				x[i][j]=0;
}
//5.7)
int pesquisa_matriz(int x[][COL], int nl, int nc, int elem, 
                    int &co, int &li)
{
	for(int i=0; i<nl; i++) 
		for(int j=0; j<nc; j++)
			if(x[i][j]==elem) { co=j; li=i; return 1; }
	return -1;
}
//5.8)
void soma_matrizes(int x1[][COL], int x2[][COL], 
                   int x3[][COL], int nl, int nc)
{
	for(int i=0; i<nl; i++) 
		for(int j=0; j<nc; j++)  
			x3[i][j]=x1[i][j]+x2[i][j];          	
}
//5.9)
int ocorrencias(int x[][COL], int nl, int nc, int elem) 
{
	int ocorr=0;
	for(int i=0; i<nl; i++) 
		for(int j=0; j<nc; j++)
			if(x[i][j]==elem) ocorr++;
	return ocorr; 
}
//5.10)
void substitui_elemento(int x[LIN][COL], int nl, int nc, int elem1, int elem2)
{
	for(int i=0; i<nl; i++) 
		for(int j=0; j<nc; j++)
			if (x[i][j]==elem1) x[i][j]=elem2;
}
//5.11)
void transposta_matriz(int x[LIN][COL], int x2[COL][LIN], int nl, int nc)
{
	for(int i=0; i<nl; i++) 
		for(int j=0; j<nc; j++)
			x2[i][j]=x[j][i];
}
//5.12)
void transposta_matriz_quad(int x[][COL], int n)
{
	for(int i=0; i<n-1; i++) 
		for(int j=i+1; j<n; j++){
			int aux=x[i][j]; x[i][j]=x[j][i]; x[j][i]=aux;
		}
}

// 5.3) Programa principal para Teste das funções
int main()
{
	srand(time(NULL));
	int mat[LIN][COL];
	preenche_aleatorio(mat,LIN,COL);
	mostra_matriz2(mat,LIN,COL);	
	printf("Soma: %d\n", calcula_soma(mat,LIN,COL));
	printf("Media: %.2f\n", calcula_media(mat,LIN,COL));
	
	int pc,pl,res,el,el2;
	printf("Elemento a Pesquisar");  scanf("%d",&el);
	res = pesquisa_matriz(mat,LIN,COL,el,pc,pl); 
	if(res==-1) printf("Nao Existe!\n");
	else printf("%d Existe na Lin: %d Col: %d\n\n",el,pl,pc);
	
	printf("Elemento a Substituir e Novo Elem");  
	scanf("%d%d",&el, &el2);
	substitui_elemento(mat,LIN,COL,el,el2);
	mostra_matriz(mat,LIN,COL);
	
	transposta_matriz_quad(mat,LIN);
	printf("Transposta:\n");
	mostra_matriz2(mat,LIN,COL);
	
	printf("Sem Borda:\n");
	preenche_borda(mat,LIN,COL); 
	mostra_matriz(mat,LIN,COL);
	
	return 0;
}


