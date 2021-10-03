#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<graphics.h>

//Resposta Multipla
void imp(int x, int tip) {
	do {
	  if (tip==1) x++; else x--;
		printf("%d ",++x);
	} while(x<10 && x>1);
}

void ciclos(int N){
  for(int i=1; i<N; i++) 
     for(int j=N; j<N+1; j++) 
        printf("%d-%d ",i, j);
}
void des(int n, int no) {
  for(int i=0; i<n-1; i++) {
     for(int j=0; j<n-1; j++) 
        if(i<=no && j<=no) printf("O");
          else printf("*");
     printf("\n");
  }   
}

void esc2(int a) {
  for(int i=1; i<=10; i++) 
     printf("%c",i+a);
}

int compara(void) {
  char s1[]="B00A"; char s2[]="b00A";
  char s3[]="B00"; char s4[]="b00";
  printf("%d %d %d \n", strcmp(s1,s2),
        strcmp(s1,s3), strcmp(s1,s4));
}

void st1() {
	char *st = "5 54 26 45"; 
	int x = atoi(st); 
	printf("%d\n",x);
}
void st2(){
char *st = "5 45 54 26";
	char *stid = strrchr(st,' ');
	int x = atoi(stid); 
	printf("%d\n",x);
}
void st3() {
	char *st = "5 45 54 26"; 
	st++; 
	int x = atoi(st); 
	printf("%d\n",x);
}

void resp_multipla()
{
	imp(3,1); printf("\n");
	//imp(5,0); printf("\n");
	ciclos(4); printf("\n");
	des(5,1); printf("\n");
	des(4,0); printf("\n");
	int x=5,y=15,z=1; x++; y=y-x++; z=z+(++x);
	printf("x:%d y:%d z:%d\n",x,y,z);
	esc2(47);printf("\n");
	compara();
	st1(); st2(); st3(); 
	int x1; for(x1=0; x1<10; x1++) {} 
	printf("%d\n",x1); 
}
/*
15) Escreva uma função int calculo(double *media, int *max) que peça números 
inteiros ao utilizador, terminando quando o utilizador introduzir dois 
números iguais seguidos. A função deve calcular a média dos valores, o maior 
valor introduzido e retornar o número total de valores introduzidos (sem 
contar o número final repetido). Por exemplo: Se o utilizador introduzir: 
3 4 3 2 -1 7 7  a função devolve 6, media = 3 e max=7. Nota: Não deve 
utilizar vetores na resolução deste exercício.
*/
int calculo(double *media, int *max) 
{
	int n=0, soma=0, val=-1000, pval;
	*max=-1000;
	do {
		pval=val;
		scanf("%d",&val);
		if(pval!=val) { n++, soma+=val;} 
		if(n==1 || val>*max) *max=val;
	} while (pval!=val || n<2);
	*media=(double)soma/n;
	return n;
}

/*
16) Construa a função void num5(int dim) que dada a dimensão do topo e base 
de um número cinco dim desenhe números 5 compostos por caracteres '#' com 
aspeto semelhante aos exemplos apresentados abaixo:
num5(1)	   num5(3)	   num5(4)	   num5(5)
#	      ###	      ####	      #####
	      #	          #	          #
num5(2)	  ##	      #	          #
##	        #	       ###	      #
#	      ##	          #	       ####
#		                  #	           #
		               ###	           #
			                           #
			                       ####
Suponha que dispõe da seguinte função já implementada:
*/
void nc(int n, char c) { 
    for(int i=0; i<n; i++) printf("%c", c); }

void num5(int dim)
{
	nc(dim,'#'); printf("\n");
	for (int i=0; i<dim-2; i++) 
		printf("#\n");
	nc(dim-1,'#'); printf("\n");
	for (int i=0; i<dim-2; i++){
		nc(dim-1,' ');
		printf("#\n");
	}
	nc(dim-1,'#'); printf("\n");
}

/*
17) Escreva uma função int descompString(char stIni[80], char stRes[80]) que 
receba uma string (array de caracteres) e a descomprima. A string inicial 
indica o número de caracteres de cada tipo que deve estar na string final 
(no primeiro exemplo 3 'A's depois aletra 'G', depois 2 'B's, depois a 
letra 'T', seguido de 6 'E's e finalmente  8 'I's. Todos os símbolos que 
não sejam letras maiúsculas os números são simplesmente eliminados. 
A função deve retornar o número de caracteres da string resultado. 
Exemplos:
     StIni   ->       StRes        Retorno
"3AG2BT6E8I" -> "AAAGBBTEEEEEEIIIIIIII" 21
"X2T*#abv4E" -> "XTTEEEE"                7
*/
int descompString(char stIni[80], char stRes[80])
{
	int i=0, j=0;
	do {
		if(isupper(stIni[i])) stRes[j++]=stIni[i++];
		else if(isdigit(stIni[i])){
				for(int k=0; k<stIni[i]-48; k++,j++) stRes[j]=stIni[i+1];
				i+=2;
		}
		else i++;
	} while(stIni[i]!='\0');
	stRes[j]='\0';
	return j;
}

/*
18) Escreva uma função char ocorrencias(char nome[20]) que receba uma string 
indicando o nome de um ficheiro e imprima no écran uma tabela indicando o 
número de ocorrências das letras minúsculas nesse ficheiro. A função deve 
retornar o caracter com maior número de ocorrências.
Char  Occur
a      138
b        9
c       35
…
z        8
*/
char ocorrencias(char nome[20]) 
{
	int oc[26]={};
	FILE *fich;  
    if ( (fich= fopen( nome, "r") ) == NULL ) {
         printf( "Impossivel ler o ficheiro %s \n",nome ); return ' ';}
    while (!feof(fich)) {
    	char ch = fgetc(fich);
    	if (islower(ch)) oc[ch-97]++;
    } 
    int max=0, n=0;
    for(int i=0; i<26; i++) {
    	if (oc[i]>max){ max=oc[i]; n=i; }
		printf("%c -> %d\n", i+97, oc[i]);	
    }
    fclose(fich);	
	return n+97;
}

/*
19) Suponha uma matriz, já inicializada mat[N][N] contendo números inteiros 
representando o estado de um jogo com torres de alturas entre 0 e 6 num 
tabuleiro com dimensão NxN. Construa a função int cresce(int mat[N][N], 
int newmat[N][N] que dada a matriz com o estado do jogo faça crescer todas 
as torres que não têm nenhuma torre maior ou igual a cima, baixo, esquerda 
e direita. Se uma torre tiver duas torres maiores ou iguais ao seu lado (esquerda e direita) 
superior deve reduzir o seu tamanho. As torres têm dimensão mínima de (0) 
e máxima de (6). A função deve retornar a soma do tamanho de todas as torres.
Matriz Inic1:	cresce(m0,m1)	 cresce(m1,m2)	    cresce(m2,m3)
1  1  0  2  4  	 1  1  0  1  4	  1  1  0  0  4      1  1  0  2  0
1  4  0  1  0  	 1  4  0  0  0	  1  4  0  2  0      1  6  0  1  4
0  6  0  2  0  	 1  6  0  0  0	  0  6  0  0  0      0  6  0  6  0
1  6  2  6  3  	 0  6  0  2  3	  1  6  0  2  3      1  0  2  0  3
0  0  3  2  4	 0  0  2  2  4	  0  0  2  2  4      0  0  3  2  4
Valor de Retorno:	4	             3	              4
*/
#define N 5
int cresce(int m[N][N], int nm[N][N])
{
	int pec=0;
	for (int i=0; i<N; i++) 
		for (int j=0; j<N; j++)	 {
			if ((i==0 || m[i-1][j]<m[i][j]) &&
				(i==N-1 || m[i+1][j]<m[i][j]) &&
				(j==0 || m[i][j-1]<m[i][j]) &&
				(j==N-1 || m[i][j+1]<m[i][j]))
					nm[i][j]=m[i][j]+1;

			else if (j!=0 && m[i][j-1]>=m[i][j] &&
				     j!=N-1 && m[i][j+1]>=m[i][j])
				    nm[i][j]=m[i][j]-1;
			else nm[i][j]=m[i][j];
			if (nm[i][j]>6 || nm[i][j]<0) nm[i][j]=0;
			pec+=nm[i][j];
		}	
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

/*
20) construa uma função void visualiza(int mat[N][N]) que permita visualizar 
em modo gráfico (utilizando a interface BGI descrita nas aulas e acetatos 
da disciplina) a matriz com as torres. A dimensão do tabuleiro deve ser 
500x500 píxeis e cada torre deve ser representada por círculos concêntricos 
de dimensão 1/6*500/N, 2/6*500/N até 500/N.
*/
void visualiza(int mat[N][N])
{
	setbkcolor(15); setcolor(0); cleardevice();
	for (int i=0; i<N; i++) 
		for (int j=0; j<N; j++)	{
			rectangle(j*500/N,i*500/N,j*500/N+500/N,i*500/N+500/N);
			for(int k=1; k<=mat[i][j]; k++) 
				circle(j*500/N+500/N/2,i*500/N+500/N/2,k*500/2/N/6);
		}
}

/*
21) Construa um programa principal que lhe permita testar devidamente todos 
os exercícios anteriores
*/
int main()
{
	//resp_multipla();
	
	double media; int max;
	int nval=calculo(&media, &max);
	printf("%d valores, Media=%.2f  Max=%d\n",nval,media,max);  //%1
	
	num5(1); printf("\n");	num5(2); printf("\n");
	num5(3); printf("\n");	num5(5); printf("\n");   //%1
	
	char st1[80];
	int nc = descompString("3AG2BT6E8I", st1);
	printf("%d : %s\n", nc, st1);
	nc= descompString("X2T*#abv4E", st1);
	printf("%d : %s\n", nc, st1);          //%1
	
	printf("Mais Votado: %c\n\n", ocorrencias("texto.txt"));   //%0.5
	
	int m1[N][N]= {1,1,0,2,4, 1,4,0,1,0, 0,6,0,2,0, 1,6,2,6,3, 0,0,3,2,4};
	int m2[N][N], m3[N][N], m4[N][N];
	mostra(m1); printf("\n");
	printf("\nNPec: %d\n",cresce(m1,m2)); mostra(m2); printf("\n");
	printf("\nNPec: %d\n",cresce(m2,m3)); mostra(m3); printf("\n");
	printf("\nNPec: %d\n",cresce(m3,m4)); mostra(m4); printf("\n");  //%1
	
	initwindow(509,511);
	visualiza(m1); delay(1000);
	visualiza(m2); delay(1000);
	visualiza(m3); delay(1000);
	visualiza(m4); delay(1000);   //%1
	system("pause"); return 0;
}




