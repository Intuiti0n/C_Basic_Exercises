/* Ficha de Exercicios 4: Algoritmos com Vectores
4.1)	Escreva uma fun��o void preenche_aleatorio(int v[], int n) que preencha um vetor com n n�meros inteiros aleat�rios com valores entre 1 e 100 
4.2)	Escreva um algoritmo que mostre no �cran, devidamente formatado um vetor com n elementos void mostra_vetor(int v[], int n)
4.3)	Construa o programa principal que lhe permita testar as duas fun��es anteriores (criando um vetor com 20 elementos e mostrando o seu conte�do no �cran). V� actualizando o programa principal com testes adequados �s restantes al�neas do exerc�cio.
4.4)	Escreva uma fun��o que calcule a soma dos elementos de um vetor com n elementos inteiros int calcula_soma(int v[], int n).
4.5)	Escreva uma fun��o que calcule a m�dia dos elementos de um vetor com n elementos inteiros double calcula_media(int v[], int n).
4.6)	Escreva uma fun��o int pesquisa(int v[], int n, int elem) que dado um vetor com n elementos inteiros permita pesquisar a exist�ncia de um dado valor (fornecido pelo utilizador) nesse vetor retornando a posi��o respetiva do elemento no vetor ou -1 caso n�o exista.
4.7)	Escreva uma fun��o que permita ordenar um vetor com n  n�meros inteiros void ordena(int v[], int n)
4.8)	Escreva uma fun��o que dados dois vetores com o mesmo numero de elementos some os elementos, um a um, dos dois vetores gerando um novo vetor void soma_vetores(int v1[], int v2[], int v3[], int n)
4.9)	Escreve uma fun��o int ocorrencias(int v[], int n, int elem) que dado um vetor e um dado n�mero inteiro, calcule o n�mero de ocorr�ncias desse n�mero no vetor.
4.10)	Escreva uma fun��o que dado um vetor v1 calcula o seu inverso e coloque num vetor v2: void inverte_vetor(int v1[], int v2[], int n)
4.11)	Escreva uma fun��o semelhante � do exerc�cio anterior mas que inverta o pr�prio vetor de entrada: void inverte_vetor(int v[], int n)
*/
#include<cstdio>
#include<cstdlib>
#include<ctime>

// 4.1)
void preenche_aleatorio(int v[], int n) 
{
	for(int i=0; i<n; i++)
		v[i]=1+rand()%100;
}
// 4.2)
void mostra_vetor(int v[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ",v[i]);
	printf("\n\n");
}
// 4.4)
int calcula_soma(int v[], int n)
{
	int soma = 0;
	for(int i=0; i<n; i++)
		soma += v[i];
	return soma;
}
// 4.5)
double calcula_media(int v[], int n)
{
	return (float)calcula_soma(v,n)/n;
}
// 4.6)
int pesquisa(int v[], int n, int elem) 
{
	for(int i=0; i<n; i++)
		if(elem==v[i]) return i;
	return -1;
}
// Funcao Auxiliar
void troca(int &a, int &b)
{
	int aux=a; a=b; b=aux;
}
// 4.7)
void ordena(int v[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(v[i]>v[j]) troca(v[i],v[j]);
}
// 4.8)
void soma_vetores(int v1[], int v2[], int v3[], int n)
{
	for(int i=0; i<n; i++)
		v3[i] = v1[i]+v2[i];
}
// 4.9)
int ocorrencias(int v[], int n, int elem)
{
	int ocorr=0;
	for(int i=0; i<n; i++)
		if(elem==v[i]) ocorr++;
	return ocorr;
}
// 4.10)
void inverte_vetor(int v1[], int v2[], int n)
{
	for(int i=0; i<n; i++)
		v2[n-1-i] = v1[i];
}
// 4.11)
void inverte_vetor(int v[], int n)
{
	for(int i=0; i<n/2; i++){
		troca(v[n-1-i],v[i]);	
	}
}

#define N1 20
#define N2 100
//4.3 Programa Principal e Teste das Funcoes
int main()
{
	int vec[N1], vec2[N1], vec3[N2], vecsoma[N1];
	srand(time(NULL));
	
	preenche_aleatorio(vec,N1);
	printf("Vec1:  "); mostra_vetor(vec,N1);
	
	preenche_aleatorio(vec2,N2);
	printf("Vec2:  "); mostra_vetor(vec2,N2);
	
	soma_vetores(vec,vec2,vecsoma,N1);
	printf("VSoma: "); mostra_vetor(vecsoma,N1);
	
	preenche_aleatorio(vec3,N2);
	printf("Vec3:  ");mostra_vetor(vec3,N2);
		
	printf("Soma Vec1 = %d\n", calcula_soma(vec, N1));
	printf("Soma Vec3 = %d\n", calcula_soma(vec3, N2));
	printf("Media Vec1= %.2f\n", calcula_media(vec, 20));
		
	int elem, pos;
	printf("Entre Elem a Pesquisar no Vec3: ");
	scanf("%d", &elem);
	pos = pesquisa(vec3, N2, elem);
	if(pos==-1) printf("Nao Existe!\n"); 
	else printf("Existe na Posicao  %d!\n", pos);

	int elem2;
	printf("Entre Elem a Calcular Ocorrencias no Vec3: ");
	scanf("%d", &elem2);
	printf("Ocorrencias de %d = %d\n", elem2, ocorrencias(vec3,N2,elem2));	
	
	ordena(vec3,N2);
	printf("Vetor Vec3 Ordenado: ");
	mostra_vetor(vec3, N2);
	
	inverte_vetor(vec, vec2, N1);
	printf("Vetor Vec1 Invertido: ");
	mostra_vetor(vec2, N1);
	
	inverte_vetor(vec3, N2);
	printf("Vetor Vec3 Invertido: ");
	mostra_vetor(vec3, N2);
	
	return 0;
}

