#include<cstdio>
#include<cstdlib>
#include<cstring>
/*
17) Construa uma fun��o int m�ltiplos(int n, int x1, int x2) para 
imprimir no �cran os n�meros m�ltiplos de n entre x1 e x2.  A fun��o 
deve retornar o n�mero de n�meros imprimidos. Exemplos: 
m�ltiplos(5,12,40)  Resultado: 15 20 25 30 35 40  Retorno: 6
m�ltiplos(4,24,38)  Resultado: 24 28 32 36        Retorno: 4
*/
int multiplos(int n, int x1, int x2) 
{
	int i, c=0;
	for(i=x1; i<=x2; i++)
		if(i%n==0) { c++; printf("%d ",i); }
	return c;
}

/*
18) Durante um campeonato de futebol os resultados de uma equipa foram 
anotados. Construir uma fun��o result campeonato(void) em linguagem C 
para ler os resultados (golos marcados e golos sofridos) da equipa em 
cada um dos seus jogos, calcular colocando na estrutura result e imprimir 
no �cran: a m�dia de golos marcados e sofridos, o n�mero total de pontos 
(sendo que uma vit�ria d� 3 pontos, empate 1e derrota 0), a diferen�a de 
golos do melhor resultado; a jornada com o melhor resultado (em caso de 
dois resultados com igual diferen�a de golos considere a primeira 
ocorr�ncia). N�o deve utilizar vetores na resolu��o deste exerc�cio. 
Garanta que os resultados s�o corretamente inseridos (golos marcados e 
sofridos n�o pode ser negativos). A entrada de dados � conclu�da 
introduzindo o resultado -1 -1. A estrutura result � a seguinte:
*/
struct result {double medMar, medSof; int pont, difGol, jorn;};
/*Exemplo: campeonato()
Entre Resultado 1? -1 5  Inv�lido!
Entre Resultado 1? 1 1 
Entre Resultado 2? 3 0
Entre Resultado 3? 5 2
Entre Resultado 4? 0 2
Entre Resultado 5? 1 1
Entre Resultado 6? -1 -1
Medias (Marc=2.0 Sofr=1.2), Pontos=8, MelhorDif=3, Jornada=2
*/

result campeonato(void)
{
	int gm,gs,n=0;
	result res={0.0,0.0,0,-1000,0};
	bool fim=false;
	do{
		do {
			scanf("%d %d",&gm,&gs);
			if (gm==-1 && gs==-1) fim = true;
			if ((gm<0 || gs<0) && !fim) printf("Invalido!\n");
		}while((gm<0 || gs<0) && !fim);
		if (!fim){
			n++; res.medMar+=gm; res.medSof+=gs;
			if(gm-gs>res.difGol) { res.difGol=gm-gs; res.jorn=n;}
			if(gm>gs) res.pont+=3; else if(gm==gs) res.pont++;
		}
	} while (!fim);
	res.medMar/=(double)n; res.medSof/=(double)n;
	return res;
}

/*
19) Construa a fun��o void num6(int dim) que dada a dimens�o do topo e 
base de um n�mero seis dim desenhe n�meros 6 compostos por caracteres 'X' 
com aspeto semelhante aos exemplos apresentados abaixo:
num6(1)	num6(2)	num6(3)	num6(4)
X    	 X	      X	       X
X	    X	     X	      X
	    XX	    X	     X
	    XX	    XXX	    X
		        X X	    XXXX
		        XXX	    X  X
			            X  X
			            XXXX
Suponha que disp�e da seguinte fun��o j� implementada:
*/
void nc(int n, char c){
	for (int i=0; i<n; i++) printf("%c",c);
}

void num_seis(int dim)
{
	for (int i=0; i<dim; i++){
		nc(dim-i-1,' '); nc(1,'X'); printf("\n");
	}
	for (int i=0; i<dim; i++)
		if(i==0 || i==dim-1) { nc(dim,'X'); printf("\n"); }
		else { nc(1,'X'); nc(dim-2,' '); nc(1,'X'); printf("\n"); }
}

void num_seis2(int dim)
{
	for (int i=0; i<dim; i++) {
		for (int j=0; j<dim; j++)	   
			if (i==dim-1-j) printf("X"); else printf(" ");
		printf("\n");
	}
	for (int i=0; i<dim; i++) {
		for (int j=0; j<dim; j++)	   
			if (i==0||i==dim-1||j==0||j==dim-1) printf("X"); else printf(" ");
		printf("\n");
	}
}

/*
20) Construa uma fun��o em linguagem C/C++ int sub_numeros(char frase[80]) 
que pe�a ao utilizador uma cadeia de caracteres com at� 80 caracteres 
(utilizando o comando gets) e retorne em frase[80] essa cadeia mas antes 
substituindo os algarismos encontrados ('1'-'9') pelas letras mai�sculas 
com a respetiva ordem no alfabeto ('A' a 'I'). O algarismo '0' e outros 
caracteres que n�o sejam num�ricos n�o devem ser substitu�dos. A fun��o 
deve retornar o n�mero de caracteres substitu�dos. Por exemplo, se o 
utilizador introduzir: "exame 123 1+programa��o*4A5B00xpto" frase[] 
ficaria com o conte�do: "exame ABC A+programa��o*DAEB00xpto".
*/
int sub_numeros(char frase[80])
{
	int n=0;
	gets(frase);
	for(int i=0; i<strlen(frase); i++)
	  if(frase[i]>48 && frase[i]<58) { n++; frase[i]+=16; }
	return n;
}

/*
21) Construa a fun��o int copiaPares(int vec[], int dim, int res[], int x) 
que dado um vetor ordenado de n�meros inteiros (vec[])e a respetiva dimens�o 
(dim) crie um vector res[], que copie os valores de vec[] para res[] mas 
substituindo todos os pares de n�meros repetidos de vec[] por uma ocorr�ncia 
do valor x. A fun��o deve retornar o n�mero de pares substitu�dos. 
Por exemplo, supondo o seguinte vetor: int vec[10]={1,2,2,2,3,5,5,5,7,7}, 
a chamada de copiaPares (vec,10,res,0) retorna o valor 3 e o vetor res[] 
ficar� com: {1,0,2,3,0,5,0}.
*/

int copiaPares(int vec[], int dim, int res[], int x)
{
	int n=0;
	for(int i=0; i<dim-1; i++)
		if(vec[i]==vec[i+1]){ res[i]=x; res[i+1]=x; n++; i++; }
		else res[i]=vec[i]; 
	return n;
}

/*
22) Suponha uma matriz, j� inicializada mat[A][B] contendo n�meros 
inteiros representando o estado de um jogo com pe�as de seis tipos (1-6) e 
espa�os vazios (0) num tabuleiro com dimens�o NxN. Construa a fun��o 
int atualiza(int mat[A][B], int pec1, int pec2) que dada a matriz com o 
estado do jogo movimente todas as pe�as do tipo pec1 para cima e, depois, 
todas as pecas do tipo pec2 para baixo. As pe�as s� se movimentam caso 
n�o saiam do tabuleiro, podendo no entanto de sobrepor a outras pe�as 
(diferentes) no tabuleiro. A fun��o deve retornar o n�mero de pecas do 
tabuleiro que se movimentarm. Exemplos: 
Matriz Inic1:  atualiza(mat,1,2) atualiza(mat,5,2) atualiza(mat,6,4)
1  1  0  2  4  	 1  1  0  1  4	  1  1  0  0  4  	 1  1  0  2  0
1  4  0  1  0  	 1  4  0  0  0	  1  4  0  2  0  	 1  6  0  1  4
0  6  0  2  0    1  6  0  0  0	  0  6  0  0  0   	 0  6  0  6  0
1  6  2  6  3  	 0  6  0  2  3	  1  6  0  2  3  	 1  0  2  0  3
0  0  3  2  4	 0  0  2  2  4	  0  0  2  2  4      0  0  3  2  4
Valor de Retorno:	   4	            3	               4
*/
#define A 5
#define B 5
int atualiza(int mat[A][B], int pec1, int pec2)
{
	int n=0;
	for (int i=1; i<A; i++) 
		for (int j=0; j<B; j++)	 
			if (mat[i][j]==pec1 && mat[i-1][j]!=pec1 ) { 
				n++; mat[i][j]=0; mat[i-1][j]=pec1; 
			}
	for (int i=A-2; i>=0; i--) 
		for (int j=0; j<B; j++)	 
			if (mat[i][j]==pec2 && mat[i+1][j]!=pec2) { 
				n++; mat[i][j]=0; mat[i+1][j]=pec2; 
			}	
	return n;		 	
}

//fun��o auxiliar
int mostra(int mat[A][B])
{
	for (int i=0; i<A; i++) {
		for (int j=0; j<B; j++)	   
			printf("%d ", mat[i][j]); 
		printf("\n");
	}	
}

int main()
{
	printf("\nRetorno: %d \n", multiplos(5,12,40));
	printf("\nRetorno: %d \n", multiplos(4,24,38));

	result res=campeonato();
	printf("%.2f %.2f %d %d %d\n\n", res.medMar, res.medSof, 
		   res.pont, res.difGol, res.jorn);
		
	num_seis(1); printf("\n");	num_seis(2); printf("\n");
	num_seis(3); printf("\n");	num_seis(5); printf("\n");	
	
	char st[80];
	fflush(stdin);
	printf("\nSubst:%d\n %s", sub_numeros(st), st);
	
	int v2[10], vec[10]={1,2,2,2,3,5,5,5,7,7};
	printf("\nAlterados:%d\n",copiaPares(vec,10,v2,0));
	for(int i=0; i<10; i++) printf("%d ", v2[i]);
	printf("\n\n");
	
	int m[A][B]= {1,1,0,2,4, 1,4,0,1,0, 0,6,0,2,0, 1,6,2,6,3, 0,0,3,2,4};
	mostra(m); printf("\n");
	printf("Alt:%d\n",atualiza(m,1,2)); mostra(m); printf("\n");
	//printf("Alt:%d\n",atualiza(m,5,2)); mostra(m); printf("\n");
	//printf("Alt:%d\n",atualiza(m,6,4)); mostra(m); printf("\n");
	
}




