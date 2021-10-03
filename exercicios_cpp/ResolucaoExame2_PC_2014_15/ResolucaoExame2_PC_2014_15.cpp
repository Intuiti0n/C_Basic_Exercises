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
15) Escreva uma fun��o int calculo(double *media, int *max) que pe�a n�meros 
inteiros ao utilizador, terminando quando o utilizador introduzir dois 
n�meros iguais seguidos. A fun��o deve calcular a m�dia dos valores, o maior 
valor introduzido e retornar o n�mero total de valores introduzidos (sem 
contar o n�mero final repetido). Por exemplo: Se o utilizador introduzir: 
3 4 3 2 -1 7 7  a fun��o devolve 6, media = 3 e max=7. Nota: N�o deve 
utilizar vetores na resolu��o deste exerc�cio.
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
16) Construa a fun��o void num5(int dim) que dada a dimens�o do topo e base 
de um n�mero cinco dim desenhe n�meros 5 compostos por caracteres '#' com 
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
Suponha que disp�e da seguinte fun��o j� implementada:
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
17) Escreva uma fun��o int descompString(char stIni[80], char stRes[80]) que 
receba uma string (array de caracteres) e a descomprima. A string inicial 
indica o n�mero de caracteres de cada tipo que deve estar na string final 
(no primeiro exemplo 3 'A's depois aletra 'G', depois 2 'B's, depois a 
letra 'T', seguido de 6 'E's e finalmente  8 'I's. Todos os s�mbolos que 
n�o sejam letras mai�sculas os n�meros s�o simplesmente eliminados. 
A fun��o deve retornar o n�mero de caracteres da string resultado. 
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
18) Escreva uma fun��o char ocorrencias(char nome[20]) que receba uma string 
indicando o nome de um ficheiro e imprima no �cran uma tabela indicando o 
n�mero de ocorr�ncias das letras min�sculas nesse ficheiro. A fun��o deve 
retornar o caracter com maior n�mero de ocorr�ncias.
Char  Occur
a      138
b        9
c       35
�
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
19) Suponha uma matriz, j� inicializada mat[N][N] contendo n�meros inteiros 
representando o estado de um jogo com torres de alturas entre 0 e 6 num 
tabuleiro com dimens�o NxN. Construa a fun��o int cresce(int mat[N][N], 
int newmat[N][N] que dada a matriz com o estado do jogo fa�a crescer todas 
as torres que n�o t�m nenhuma torre maior ou igual a cima, baixo, esquerda 
e direita. Se uma torre tiver duas torres maiores ou iguais ao seu lado (esquerda e direita) 
superior deve reduzir o seu tamanho. As torres t�m dimens�o m�nima de (0) 
e m�xima de (6). A fun��o deve retornar a soma do tamanho de todas as torres.
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

//fun��o auxiliar
int mostra(int mat[N][N])
{
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)	   
			printf("%d ", mat[i][j]); 
		printf("\n");
	}	
}

/*
20) construa uma fun��o void visualiza(int mat[N][N]) que permita visualizar 
em modo gr�fico (utilizando a interface BGI descrita nas aulas e acetatos 
da disciplina) a matriz com as torres. A dimens�o do tabuleiro deve ser 
500x500 p�xeis e cada torre deve ser representada por c�rculos conc�ntricos 
de dimens�o 1/6*500/N, 2/6*500/N at� 500/N.
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
os exerc�cios anteriores
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




