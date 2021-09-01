// Tópicos de Resolução 
// Exame de 4 de Dezembro de 2013 - Programacao de Computadores

#include<stdio.h>

/*16) Construa uma função void imprime_let(void) que imprima no écran 
os códigos e símbolos de todas as letras minúsculas e maiúsculas 
(uma por linha e formatadas como se segue). Nota: no exemplo os '.' 
representam espaços. Exemplo:  imprime_let()
.97.->.a.|.65.->.A
.98.->.b.|.66.->.B
.99.->.c.|.67.->.C
100.->.d.|.68.->.D
...
121.->.y.|.89.->.Y
122.->.z.|.90.->.Z   */

void imprime_let(void)
{
	for(int i= 97; i<97+26; i++)  //ciclo %1  fim ciclo %1
		printf("%3d -> %c | %2d -> %c\n",i,i,i-32,i-32);  //print %2  +-32 %1
}

void imprime_let1(void)
{
	for(int i= 0; i<26; i++)  //ciclo %1  fim ciclo %1
		printf("%3d -> %c | %2d -> %c\n",i+97,i+97,i+65,i+65);  //print %2  +-32 %1
}

/*17) Construa a função void let_c(int alt, int larg) que dada a 
altura alt e a largura larg desenhe letras C compostas por símbolos 
'X' e '.' com aspeto semelhante ao apresentado abaixo, de acordo com os 
exemplos apresentados:
letc(1,1) letc(2,2) letc(3,1) letc(1,3) letc(3,2)
X	XX	X	XXX	    XX
	XX	X	    	X.
		X	   	    XX
letc(3,3) letc(3,5)	letc(4,4)
XXX		  XXXXX		XXXX
X..		  X....		X...
XXX		  XXXXX		X...
					XXXX
Suponha que dispõe da seguinte função já implementada (e que deve utilizar sempre que 
for útil): 
void nc(int n, char c) { 
    for(int i=0; i<n; i++) printf("%c", c); }*/

void nc(int n, char c) { 
    for(int i=0; i<n; i++) printf("%c", c); 
}

void letc(int alt, int larg)
{
	//if (alt<0) return;  
	nc(larg,'X'); printf("\n");  //primeira linha %1
	for(int i=1; i<=alt-2; i++){ //ciclo %1
		printf("%c",'X');
		nc(larg-1,'.');	
		printf("\n");			//X simples %1
	}
	if (alt>1) { nc(larg,'X'); printf("\n"); }  //ultima linha %1  + \n em todos %1
}

/* 18) Construa uma função double mensalidade(int tipo, int idade) que dado o tipo de 
cliente e a sua idade retorne e imprima no écran a mensalidade que este deve pagar.  
Para clientes com menos de 18 anos de idade, ou séniores (idade igual ou superior a 
65 anos), a mensalidade é metade da mensalidade dos adultos. A tabela de mensalidades 
para adultos é a seguinte: tipo 1: 10.50 Eur, tipo 2: 15.00 Eur, tipo 3: 18.30 Eur, 
tipo 4: 20.00 Eur, tipo 5: 23.20 Eur, Outro Tipo: 30.00 Eur. No entanto, devemos tomar 
em consideração que a bonificação de pagamento de metade da cota só se aplica a clientes 
dos tipos 1, 2, 3 e 4. Nota: Utilize a instrução switch case. Exemplos: 
mensalidade(2, 16)			mensalidade(8, 68)
Mensalidade = 7.50 Eur		Mensalidade = 30.00 Eur  */
 
double mensalidade(int tipo, int idade) 
{
	double mens;
	switch (tipo) {
		case 1: mens = 10.5; break;
		case 2: mens = 15.0; break;
		case 3: mens = 18.3; break;
		case 4: mens = 20.0; break;
		case 5: mens = 23.2; break;
		default: mens = 30.0; break;  //Casos para a mensalidade %1.5
	}
	if ((idade<18 || idade>=65) && tipo>=1 && tipo<=4) mens= mens/2;  //divisão/2 %1.5
	printf("Mensalidade = %.2f Eur\n", mens);  //printf %1
	return mens;  //variavel e retorno do valor %1
}

/* 19) Construa uma função int par_ou_impar(int vpar[], int *np, int vimp[], int *ni) 
que permita ao utilizador introduzir elementos inteiros positivos e coloque todos os 
numeros impares introduzidos no vetor vimp[] e todos os elementos pares no vetor vpar[]. 
Deve ainda calcular o total de numeros pares (*np) e impares (*ni) introduzidos. 
Por fim, a função deve retornar o número total valores inválidos itroduzidos. 
Por exemplo, supondo que os seguintes números são introduzidos pelo utilizador:
3 -5 0 10 6 3 4 5 4 2 8 -5 1 -1
vpar[]={10, 6, 4, 4, 2, 8}, vimp[]={3, 3, 5, 1}, *np = 6, *ni = 4. A função, no final 
retorna 3 (dado que foram introduzidos três valores inválidos -5, 0 e -5). */

//Função auxiliar para teste pr_vec
int pr_vec(int v[], int n) { for(int i=0; i<n; i++) printf("%d ",v[i]); printf("\n"); }

int par_ou_impar(int vpar[], int *np, int vimp[], int *ni)
{
   int num, n=0;
   *np=0; *ni=0; 
   do {  //ciclo
      printf("N? "); scanf("%d",&num);  //scanf num %1
      if (num>0) {    // contagem e não consideração invalidos e retorno %1
         if(num%2==0) 
		 	vpar[(*np)++]=num; else vimp[(*ni)++]=num;     // par ou impar %2             
      } 
      else n++;  //contagem
   } while(num!=-1);   //ciclo %1    
   return n-1;    //retorno contagem
}
	
/* 20) Suponha uma matriz, já inicializada tab[N][N] contendo números inteiros 
representando peças e damas de dois jogadores (1 - peça jogador 1, 2 - peça jogador 
2, 3 - dama do jogador  1, 4 - dama do jogador 2) e espaços vazios (0) num tabuleiro 
com dimensão NxN. Construa a função int move_pec_Jog(int tab[N][N], int jog, int dir) 
que dada a matriz com o estado do jogo movimente todas as peças e damas isoladas 
(i.e. sem nenhuma peça/dama de nenhum jogador na vizinhança), do jogador jog  na 
direção dir (em que dir = 1: direita; dir =2: esquerda; dir = 3: cima e dir=4: baixo). 
As peças só se movimentam caso estejam inicialmente isoladas, a casa de destino esteja 
dentro do tabuleiro e livre. A função deve retornar o número de movimentos realizados.
Exemplo: Aplicando a função move_pec_Jog(tab, 1, 2), à matriz inicial em baixo, é 
retornado o valor 3 (3 peças movimentadas para a esquerda) e muda a matriz para a 
matriz representada como resultado final:
Matriz Inicial:		Resultado Final:
1  1  0  0  1  		1  1  0  1  0
1  4  0  1  0  		1  4  1  0  0
0  0  0  2  0   	0  0  0  2  0
1  0  2  0  3  		1  0  2  3  0
0  0  3  0  0		0  0  3  0  0   */
#define N 5
//Função auxiliar para teste pr_mat
int pr_mat(int m[N][N]) {
   	for(int i=0; i<N; i++) { 
   		for(int j=0; j<N; j++) printf("%d ",m[i][j]);
		printf("\n");
	}
   	printf("\n");
}

int move_pec_Jog(int tab[N][N], int jog, int dir) 
{
	int dirx=0, diry=0, pec=0;
	switch (dir){
		case 1: dirx=1; diry=0; break;  //dir  
		case 2: dirx=-1; diry=0; break; //esq
		case 3: dirx=0; diry=-1; break; //cima
		case 4: dirx=0; diry=1; break;  //baixo  conversão direção %1
	}
	for(int i=0; i<N; i++)
   		for(int j=0; j<N; j++)    //Para todas as casas %1
			if((tab[i][j]==jog || tab[i][j]==jog+2) &&    //peça/dama do jogador jog
			   (i==0 || tab[i-1][j]==0) &&  
			   (i==N-1 || tab[i+1][j]==0) && 
			   (j==0 || tab[i][j-1]==0) && 
			   (j==N-1 || tab[i][j+1]==0) && //isolada  %1
				//tab[i+diry][j+dirx]==0 && //casa vazia (não necessario pois está isolada...)
			    i+diry>=0 && i+diry<N && j+dirx>=0 && j+dirx<N){ //dentro tabuleiro %1.0
			   		tab[i+diry][j+dirx]=tab[i][j];  //movimento %1
					tab[i][j]=0; 
					pec++;  //contagem e retorno de pecas movimentadas %1
			   }  
	return pec;  //retorno pecas
} //Total = 6(maximo 5) 

// Resposta Multipla

void f1(int a, int b)
{
  if(a>8 || a<b && a<6) printf("1");
  if(b>6||a<3) printf("2");
  else if (!(a>b))printf("3"); 
}

void f2(int op)
{
  switch(op) {
     case 1: printf("1");
     case 2: case 3: printf("3");     
     case 4: printf("4"); break;
     default: printf("5");
  }
}

void imp(int x, int tip)
{
	do {
		printf("%d",x);
		if (tip==0) x++; else x*=2;
	} while(x<10);
}

void ciclos(int n1, int n2)
{
  for(int i=1; i<n1; i++) 
     for(int j=i+5; j>n2; j--) 
        printf("%d-%d ",i, j);
}

void ciclos2(int N1, int N2)
{
  for(int i=1; i<=N1; i++) {
     for(int j=1; j<N2; j++) 
        if(i<j) printf("#");
          else printf("O");
     printf("\n");
  }   
}

int xpto1()
{
  int v[10];
  for(int i=0; i<=9; i++) 
     v[i]= i*2;
  for(int i=0; i<=9; i++) 
     printf("%d ",v[9-i]);
  return v[5];
}

void ap1(void){   
  int *ap, x, y, z;
  x = 10; y=10; ap = &y; 
  y = 2*x; z = 2*(*ap); *ap = 20;
  printf("x=%d y=%d z=%d \n", 
         x,y,z);
}

//Erro de compilação
/*void xpto(int *a, int *b, int *c){
    a = 1;  *b = 2;  *c = 3; 
}*/

//Resposta Multipla
void resposta_multipla(void)
{
	f1(8,8); printf("\n");  //2
	f1(5,6); printf("\n");  //13
	f2(1); printf("\n");    //134
	f2(6); printf("\n");    //5
	imp(5,0); printf("\n");  //56789
	imp(1,1); printf("\n");  //1248
	ciclos(2,5); printf("\n");
	ciclos(3,3); printf("\n");
	ciclos2(4,3); printf("\n");
	ciclos2(2,2); printf("\n");
	int a = xpto1(); printf(" a= %d\n",a);
	ap1();
	//xpto();
	int x=10,y,z,w; y=x++; z=++x; x =++z; w=x++; 
	printf("%d %d %d %d",x,y,z,w);	
}

/* 21) Construa um programa principal que lhe permita testar, com exemplos relevantes, 
os programas construídos nas alíneas 16, 17, 18, 19 e 20. */
void exercicios_16_20(void)
{
	imprime_let();  //%1
	
	letc(1,1); printf("\n"); letc(2,2); printf("\n"); letc(3,1); printf("\n");
	letc(1,3); printf("\n"); letc(3,2); printf("\n"); letc(3,3); printf("\n");
	letc(3,5); printf("\n"); letc(4,4); printf("\n");  //%1 ou scanf(x,y)+letc(x,y)
	
	double me1 = mensalidade(2, 16);	
	double me2 = mensalidade(8, 68);
	printf("Me1= %.2f Me2= %.2f\n",me1,me2); //%1
	
	int np, ni, vp[10], vi[10];
	printf("Inv: %d\n",par_ou_impar(vp, &np, vi, &ni));
	pr_vec(vp,np); pr_vec(vi,ni);   //%1.5
	
	int mat[N][N]={1,1,0,0,1,  1,4,0,1,0,  0,0,0,2,0,  1,0,2,0,3,  0,0,3,0,0};
	pr_mat(mat);
	printf("Mov: %d\n", move_pec_Jog(mat, 1, 2));   //%1.5
	pr_mat(mat);	
} //max = 5.0

int main()
{
	printf("\nResposta Multipla:\n");
	resposta_multipla();
	printf("\n\nExercicios 16-20:\n");
	exercicios_16_20();
	return 0;
}


