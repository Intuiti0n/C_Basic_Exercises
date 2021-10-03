#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<graphics.h>

/* a) Escreva uma função int troco(int vNota, int aPagar) que dado um determinado valor 
inteiro a pagar igual ou inferior a 50 Eur (aPagar) e o valor da nota entregue para o 
pagar (vNota) que pode ser (50, 20, 10 ou 5 Eur) calcule o troco a entregar (exclusivamente 
em notas de 20 e 5 Eur e moedas de 1 Eur) e o imprima no écran. A função deve ainda 
imprimir e retornar o número de notas/moedas necessário para o troco. No caso de a nota 
entregue ou o valor a pagar serem inválidos deve imprimir inválido e retornar 0. 
Exemplos: 
troco(38,15) -> Inválido!
troco(50,25) -> 20 5: 2 notas/moedas
troco(50,20)-> 20 5 5: 3 notas/moedas
troco(20,4)-> 5 5 5 1: 4 notas/moedas
troco(5,1) -> 1 1 1 1: 4 notas/moedas

*/
int troco(int vNota, int aPagar) 
{
	if(vNota!=50&&vNota!=20&&vNota!=10&&vNota!=5) { printf("Invalido!\n"); return 0;} 
	int n=0, tro = vNota-aPagar;  
	while (tro>=20) { printf("20 "); n++; tro-=20;}  
	while (tro>=5) { printf("5 "); n++; tro-=5;}     
	while (tro>=1) { printf("1 "); n++; tro--;}	   
	printf(": %d notas/moedas\n",n);    
	return n;	   
}

/* b) Construa a função void num7(int dim) que dada a dimensão de um número sete dim desenhe 
números 7 compostos por caracteres 'X' com aspeto semelhante aos exemplos apresentados 
abaixo:
num7(1)	num7(3)	num7(4)	num7(5)
X	     XXX	XXXX	XXXXX
X	       X	   X	    X
num7(2)	  X	      X	       X
XX	     X	     X	      X
 X		        X   c    X
X			            X
Suponha que dispõe da seguinte função já implementada:
*/
void nch(int n, char c) { 
    for(int i=0; i<n; i++) printf("%c", c); }

void num7(int dim)
{
	nch(dim,'X'); printf("\n");   
	for (int i=1; i<=dim; i++) {  
		nch(dim-i,' ');           
		printf("X\n");            
	}
}

/* c) Escreva uma função double frequenciasPal(char nome[20]) que receba uma string 
indicando o nome de um ficheiro e imprima no écran uma tabela indicando a frequência 
de cada comprimento das palavra. A função deve também escrever no écran o comprimento 
médio das palavras encontradas no ficheiro e retorna-lo. Suponha que o tamanho máximo 
das palavras é 10. Sugestão utilize um vetor de inteiros para as frequências: 
int freq[10] inicializado a 0.	
Exemplo:
1 ->  50
2 -> 180
3 -> 220
...	
10 ->  8
Med: 4.6
*/

double frequenciasPal(char nome[20]) 
{
	int freq[10]={}, n=0; 
	double med=0.0;
	char pal[11];
	FILE *fich;  
    if ( (fich= fopen( nome, "r") ) == NULL ) {
         printf( "Impossivel ler o ficheiro %s \n",nome ); return ' ';}  
    while (!feof(fich)) {  
    	fscanf(fich, "%s", pal); 
    	freq[strlen(pal)-1]++;     
    	med+=strlen(pal); n++;
    	//printf("%d->#%s#%d\n",n,pal,strlen(pal));
    } 
    for(int i=0; i<10; i++)   
		printf("%d -> %d\n", i+1, freq[i]);	
	med = med/n;
	printf("Media: %.2f\n",med);	 
    fclose(fich);	
	return med;
}

// d) Suponha a estrutura tempo seguinte:
struct tempo { short int hora, minu, segu; };
/*
Escreva uma função void incr100(tempo &t) que dado um determinado tempo, o incremente 
em 100 segundos, alterando convenientemente os respetivos campos e o mostre no ecrã 
devidamente formatado (hora, minutos e segundos). Por exemplo, supondo t = {10, 59, 12} 
a chamada de incr100(t) resulta em t={11, 00, 52} e imprime no écran "11 horas, 00 minutos 
e 50 segundos".
*/
void incr100(tempo &t)
{
	t.segu += 40;  
	t.minu++;      
	if (t.segu>=60) { t.segu -=60; t.minu++;}    
	if (t.minu>=60) { t.minu -=60; t.hora++;}  
	printf("%2d horas, %2.2d minutos e %2.2d segundos\n", t.hora, t.minu, t.segu); 
}

/* e) Suponha uma matriz, já inicializada m[N][N] contendo números inteiros representando o
estado de um jogo com peças de seis tipos 1-6, e ainda armadilhas (8) e espaços vazios (0)
num tabuleiro com dimensão NxN. Construa a função int move(int m[N][N]) que dada a matriz 
com o estado do jogo execute a movimentação do jogo que consiste nos seguintes passos. 
a) As armadilhas que não tenham peças à sua volta (só espaços vazio ou outras armadilhas) 
no início do ciclo, expandem-se (caso seja possível) para baixo embora as novas armadilhas 
não capturem peças neste ciclo, só no próximo. b) Todas as peças com valor superior capturam 
as peças de valor menor que estejam a cima, baixo, esquerda e/ou direita da peça. 
c) As quadrículas que estejam próximas de armadilhas ficam vazias mas só após a expansão 
feita em b) caso seja o caso. A função deve retornar o número de peças alteradas no 
tabuleiro. 
Matriz m0:	         move(m0)	      move(m0)	    move(m0)
1  1  0  2  4  	 1  4  0  4  4	  4  6  0  4  4    6  6  0  4  4
1  4  0  1  0  	 4  6  0  2  0	  6  6  0  4  0    6  6  0  4  0
0  6  8  2  0  	 0  0  8  0  0	  0  0  8  0  0    0  0  8  0  0
1  6  2  6  3  	 0  6  0  6  6	  0  6  8  6  6    0  0  8  0  6
8  2  3  2  4	 8  0  3  6  4	  8  0  6  6  6    8  0  0  6  6
Valor de Retorno:	12	               7	            4
*/
#define N 5
int move(int m[N][N])
{
	int pec=0;
	for (int i=0; i<N-1; i++)   
		for (int j=0; j<N; j++)	 
			if (m[i][j]==8 && 
			    (i==0 || m[i-1][j]==0 || m[i-1][j]==8) &&
				(i==N-1 || m[i+1][j]==0 || m[i+1][j]==8) &&
				(j==0 || m[i][j-1]==0 || m[i][j-1]==8) &&
				(j==N-1 || m[i][j+1]==0 || m[i][j+1]==0)) {
					m[i+1][j]=8; pec++;
				}
	// ... captura de pecas menores /
	// ... eliminaca de pecas por armadilhas  

	return pec;  
}

//função auxiliar
int mostra(int mat[N][N])
{
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)	   
			printf("%d ", mat[i][j]); 
		printf("\n");
	}	
}

/* f) construa uma função void visualiza(int vec[10]) que permita visualizar 
em modo gráfico (utilizando a interface BGI descrita nas aulas e acetatos 
da disciplina) o conteudo de um dado vetor de numeros inteiros contendo
10 valores de percentagens (valores entre 0 e 100). 
A visualização deve ser numa janela de aproximadamente 600x600 píxeis, através de
barras coloridas, representadas verticalmente e com uma cor distinta.
Exemplo para vetor contendo {5, 50, 100, 30, 80, 90, 100, 50, 50, 100};
*/
void visualiza(int vec[10])
{
	initwindow(609,611); setbkcolor(15); cleardevice();  
	for (int i=0; i<10; i++) {                           
		setcolor(i); setfillstyle(i+1,i);                
		bar(i*60,600,i*60+60,600-vec[i]*6);              
		rectangle(i*60,600,i*60+59,600-vec[i]*6);        
	}
}

/* g) Construa um programa principal que lhe permita testar devidamente todos 
os exercícios anteriores */
int main()
{
	troco(38,15); troco(50,25); troco(50,20);  
	troco(20,4); troco(5,1);
	
	num7(1); printf("\n");	num7(2); printf("\n"); num7(3); printf("\n");	
	num7(4); printf("\n"); num7(5); printf("\n");  

	printf("Media Tamanho Palavras: %.2f\n\n", frequenciasPal("texto.txt"));   
		
	tempo t1={10, 59, 12};   
	incr100(t1);      
	printf("%2d/%2.2d/%2d\n", t1.hora, t1.minu, t1.segu); 
	
	int m1[N][N]= {1,1,0,2,4, 1,4,0,1,0, 0,6,8,2,0, 1,6,2,6,3, 8,2,3,2,4};
	mostra(m1); printf("\n");
	printf("\nNPec: %d\n",move(m1)); mostra(m1); printf("\n");
	printf("\nNPec: %d\n",move(m1)); mostra(m1); printf("\n");
	printf("\nNPec: %d\n",move(m1)); mostra(m1); printf("\n");  
	
	int v[10]={5, 50, 100, 30, 80, 90, 100, 50, 50, 100};  
	visualiza(v);   
	system("pause"); return 0;
}




