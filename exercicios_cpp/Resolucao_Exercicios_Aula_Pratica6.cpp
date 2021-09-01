// Exerc�cio de Matrizes - Jogo Simples
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8
void preenche_tabuleiro(int tab[N][N], int val, int rep)
{
	int x,y;
	for(int i=0; i<rep; i++){  //Executa rep vezes a coloca��o de pe�as aleatorias
		do {
			y=rand()%N; x=rand()%N;   //Sorteia posi��o (x,y) aleatoria 
		} while(tab[y][x]!=0);		//at� a posi��o sorteada estar vazia
		tab[y][x]=val;    //Coloca pe�a na posi��o sorteada
	}
}
void mostra_matriz(int tab[N][N])
{
	//return;   //Descomentar para acelerar a execu��o dos 10000 jogos
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%d ", tab[i][j]);
		printf("\n");
	}
	printf("\n");
}
int conta_elementos(int tab[N][N], int val)
{
	int oc=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if (tab[i][j]==val) oc++;
	return oc;
}
void elimina_isolados(int  tab[N][N],  int  val)
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)   //Para todas as posi��es do tabuleiro
			if(tab[i][j]==val &&    //se a posi��o tem a pe�a procurada
			   (i==0 || tab[i-1][j]==0) &&  // e est� na primeira linha do tabuleiro ou tem um 0 acima
			   (i==N-1 || tab[i+1][j]==0) && // e est� na ultima linha do tab ou tem um 0 abaixo
			   (j==0 || tab[i][j-1]==0) &&  // e est� na primeira coluna do tab ou tem um 0 'a esquerda
			   (j==N-1 || tab[i][j+1]==0))   // e est� na ultima coluna do tab ou tem um 0 'a direita
			   tab[i][j]=0;   //limpa essa posi��o colocando la' um zero
}
void copia_tab(int tab[N][N], int tab2[N][N])
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			tab2[i][j]=tab[i][j];  //cria uma copia do tab copiando todas as linhas/colunas
}

char conv(short int peca)
{
   if (peca==1) return 'X';    
   else if (peca==2) return 'O';    
   else return ' ';    
}
void num()
{
	for(int i=0; i<N; i++) printf("  %2d",i+1);
}
void tra(int tip)  //tip==0 cima, 1-meio, 2-baixo
{
	for(int i=0; i<N; i++) printf("%c%c%c%c",206,205,205,205); //printf("|---");
	printf("%c\n",206);
}
void mostra_tabuleiro(int tab[N][N])
{
     num();
     printf("\n ");
     tra(0);
     for(int i=0; i<N; i++) {
         printf("%c",i+65);    
         for(int j=0; j<N; j++)
              printf("%c %c ", 186, conv(tab[i][j])); 
         printf("%c%c \n ",186,i+65); 
		 if (i==N-1) tra(2); else tra(1);
     }
     num();
	 printf("\n\n");
}

void move_pecas1(int tab[N][N],  int  dirx,  int  diry, int  val)
{
	int newtab[N][N];
	copia_tab(tab, newtab);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(tab[i][j]==val) {  
				if(i+diry>=0 && i+diry<N && j+dirx>=0 && j+dirx<N)
					newtab[i+diry][j+dirx]=val;  //coloca pe�a na celula para onde ser movimenta
				if(i-diry<0 || i-diry>=N || j-dirx<0 || j-dirx>=N || 
				    tab[i-diry][j-dirx]!=val)
				 	newtab[i][j]=0;  //Limpa celula se a pe�a que vai ser colocada n�o for val
			} 
	copia_tab(newtab, tab);
}
void move_pecas2(int tab[N][N],  int  dirx,  int  diry, int  val)
{
}
int teste()
{
	int tabul[N][N]={};  // tabul incializado a 0s
	mostra_matriz(tabul);
	preenche_tabuleiro(tabul,1,10); mostra_matriz(tabul);
	preenche_tabuleiro(tabul,2,5); mostra_tabuleiro(tabul);
	printf("Num 1s: %d, Num 2s: %d\n", 
	        conta_elementos(tabul,1), conta_elementos(tabul,2));
	elimina_isolados(tabul,1); mostra_matriz(tabul);
	elimina_isolados(tabul,2); mostra_matriz(tabul);
	move_pecas1(tabul,1,0,1); mostra_matriz(tabul);
	move_pecas1(tabul,0,1,2); mostra_matriz(tabul);	
	//move_pecas2(tabul,1,0,1); mostra_matriz(tabul);
	//move_pecas2(tabul,0,1,2); mostra_matriz(tabul);	
}

void move_aleatorio(int tab[N][N], int val)
{
	int dirx, diry;
	int dir = rand()%4;    //Sorteia uma de 4 possiveis dire��es (0, 1, 2 ou 3)
	switch (dir){
		case 0: dirx=1; diry=0; break;  //Dire��o 0: direita move uma casa no eixo dos xx
		case 1: dirx=0; diry=1; break;  //baixo
		case 2: dirx=-1; diry=0; break; //Dire��o 2: esquerda move uma casa para tr�s no exio dos xx
		case 3: dirx=0; diry=-1; break; //cima
	}
	move_pecas1(tab,diry,dirx,val);	
	//move_pecas2(tab,diry,dirx,val);  //Descomentar para usar move_pecas2
}

bool fim_jogo(int tabul[N][N], int njog, int &venc)
{
	int c1 = conta_elementos(tabul,1);
	int c2 = conta_elementos(tabul,2);
	if (njog<10 && c1>0 && c2>0) { venc = 0; return false; }  // Ainda n�o acabou
		// Jogo acabou dado que um dos jogadores n�o tem pe�as ou foram feitas 10 jogadas
	if (c1==c2) venc = 3;      //Empate pois t�m ambos 0 pe�as ou igual numero de pe�as
	else if (c1>c2) venc = 1;  //Vencedor � o 1
		 else venc = 2;        //Vencedor � o 2
	return true;
}

int jogo()
{
	int tabul[N][N]={};  // tabul incializado a 0s
	mostra_matriz(tabul);
	int dir, dirx, diry, venc, njog = 1;
	do {
		preenche_tabuleiro(tabul,1,10-njog); //Introduz 10-njog pe�as aleatorias do jog 1
		preenche_tabuleiro(tabul,2,10-njog);
		mostra_matriz(tabul);
		elimina_isolados(tabul,1); elimina_isolados(tabul,2);
		mostra_matriz(tabul);
		move_aleatorio(tabul,2); move_aleatorio(tabul,1);
		mostra_matriz(tabul);
		elimina_isolados(tabul,1); elimina_isolados(tabul,2);
		mostra_matriz(tabul);
	} while(!fim_jogo(tabul, njog++, venc));
	if (venc==3) printf("Empate!\n"); else printf("Vencedor: %d\n",venc);
	return venc;
}
int main()
{
	srand(time(NULL));
	teste();			//Teste das Funo��es individuais
	//int res = jogo(); //Execu��o de um �nico jogo
	/*int v, v1=0,v2=0,emp=0;
	for(int i=0; i<10000; i++) {   //Execu��o de 10000 Jogos
		v=jogo(); if (v==1) v1++; else if (v==2) v2++; else emp++;
	}
	printf("Vitorias Jog1: %d, Jog2: %d, Emp: %d\n",v1,v2,emp); 
	return 0;*/
}
