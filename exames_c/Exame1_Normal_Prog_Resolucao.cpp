// Exame Exemplo de Programa��o (T�picos de Resolu��o dos Exerc�cios 16 - 19)
// Nota: Obviamente existem muitas outras solu��es poss�veis para cada exerc�cio

/*
16) Escreva uma fun��o bool pede_data(int *dia, int *mes, int *ano) que pe�a uma 
data ao utilizador (dia, m�s e ano) e verifique se a data � v�lida. Na resolu��o 
do exerc�cio siga as seguintes regras:
- Considere que o ano � v�lido se for igual ou inferior a 2012. 
- Ignore os anos bissextos considerando que Fevereiro tem sempre 28 dias. 
- Utilize a instru��o switch ... case na fun��o.
- Caso a data seja v�lida retorne verdadeiro e os valores correspondetes do dia, 
  m�s e ano. 
- Caso a data seja inv�lida retorne falso e 0, 0, 0 para o dia, m�s e ano.

17) Construa a fun��o void pira(int alt) que dada a altura alt desenhe pir�mides compostas de s�mbolos * e O, com aspeto semelhante ao apresentado abaixo, de acordo com os exemplos apresentados:
pira(1)	pira(2)	pira(3)	pira(5)
**	 **	      **	    **
	*OO*	 *OO*	   *OO*
		    *OOOO*	  *OOOO*
		        	 *OOOOOO*
		        	*OOOOOOOO*

			            
18) Construa uma fun��o int inverte(int v1[], int n1, int val1, int val2) que dado 
um vector de inteiros inverta o vetor e ao mesmo tempo substitua todos os elementos 
iguais a val1 por val2 retornando o n�mero de elementos substituidos. 
Por exemplo: Supondo int v1[11]={1,2,3,5,7,3,8,9,9,3,4}, a chamada de 
inverte(v1,11,3,10) retorna o valor 3 e o vector v1[11] ficar� com os valores:
{4,10,9,9,8,10,7,5,10,2,1}

19)Suponha uma matriz, j� inicializada (tabul[N][N]) contendo n�meros 
inteiros representando pe�as e damas de dois jogadores (1 - pe�a 1, 2 - pe�a 2,
3 - dama 1, 4 - dama 2) e espa�os vazios (0) num tabuleiro com dimens�o NxN.
Construa uma fun��o int move_pecas1(int tabul[N][N]) que dada 
a matriz com o estado do jogo movimente todas as pe�as do jogador 1 uma casa em frente. 
Caso as pe�as atinjam o fim do tabuleiro (parte inferior do tabuleiro), e ainda 
n�o sejam damas, transformam-se em damas. Suponha que as pe�as (e damas) do jogador
1 movem-se na horizontal para baixo. As pe�as s� se podem movimentar para casas 
que vazias ou que sejam esvaziadas na movimenta��o (caso contr�rio permanecem im�veis). 
Sugest�o: Comece pela linha de baixo (N-1) verificando que pelas se podem movimentar 
essa linha e v� subindo, acabando na segunda linha (linha 1).
A fun��o deve retornar o n�mero de pe�as efetivamente movimentadas.
Exemplo com Tabul[5][5]=:
1 1 0 0 1
1 4 0 1 0
0 0 0 2 0
1 0 2 0 3
0 0 3 2 0
supondo move_pecas1(tabul), retorna o valor 4 e muda a matriz para a seguinte:
0 1 0 0 0
1 4 0 1 1
1 0 0 2 0
0 0 2 0 0
3 0 3 2 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 5


void calculos(int a, double x) 
{
     printf("%10d%10.2f\n", a, x);
     printf("%10.2f%10.2f\n", a/5.0, x/5.0);
     printf("%10d%10d\n", a/5, (int)x/5);
     
     for(int i=1; i<=5; i++)
         printf("%10.*d%10.*f\n", i, a, i, x);
}


//Exercicio 16
bool pede_data(int *dia, int *mes, int *ano)
{
   bool valida=true;
   int ndias;   
   printf("Entre uma data dia mes ano?"); 
   scanf("%d %d %d", dia, mes, ano);
   switch (*mes) {
     case 2: ndias=28; break;
     case 4: case 6: case 9: case 11: ndias=30; break;       
     default: ndias=31;
   }
   if (*ano>2012 || *mes<1 || *mes>12 || *dia<1 || *dia>ndias) {
      valida=false; *dia=0; *mes=0; *ano=0; } 
   return valida;
}

void nc(int n, char c) { for(int i=0; i<n; i++) printf("%c",c); }

//Exercicio 17
void pira(int N2)
{
    for(int i=0; i<N2; i++) {
       nc(N2-i-1,' '); printf("*"); nc(i*2, 'O'); printf("*\n"); 
    } 
    printf("\n");        
}

//Exercicio 18
int inverte(int vec[11], int n1, int val1, int val2) 
{
    int i, aux, nv=0;
    for(i=0; i<n1/2+1; i++) {  //at� meio do vetor
       if(vec[i]==val1) { vec[i]=val2; nv++;} 
       aux = vec[i]; vec[i] = vec[n1-i-1]; vec[n1-i-1] = aux;  
       if(vec[i]==val1) { vec[i]=val2; nv++;} 
    } 
    return nv; 
}

//Exercicio 19
int move_pecas1(int tab[N][N])
{
    int pec = 0;
    for(int i=N; i>0; i--)
       for(int j=0; j<N; j++) 
          if ((tab[i-1][j]==1 || tab[i-1][j]==3) && tab[i][j]==0) {  
                  if (i==N-1) tab[i][j] = 3; else tab[i][j] = tab[i-1][j];
                  tab[i-1][j] = 0;
                  pec++; 
              }              
    return pec;
}

// Exercicio 19 Fun��o Main para teste dos programas
int main()
{
   // Exerc 15 - Exemplo de chamada para teste
   calculos(2, 9.5);  
   calculos(10, 15.2344);
    
   // Exerc 16 - Exemplo de chamada para teste
   bool valida;
   int d,m,a;
   valida = pede_data(&d, &m, &a);
   if (valida) printf("Data: %2.2d/%2.2d/%2.2d\n", d,m,a);
   else printf("Data Invalida\n");
   
   // Exerc 17 - Exemplo de chamada 
   pira(1); pira(2); pira(3); pira(5); 
   
   // Exerc 18 - Exemplo de chamada 
   int v1[11]={1,2,3,5,7,3,8,9,9,3,4};
   int n = inverte(v1, 11, 3, 10);
   printf("n= %d  v1[11]= ", n);
   for(int i=0; i<11; i++) printf("%d ", v1[i]);
   
   // Exerc 19 - Exemplo de chamada 
   int tab[N][N]= {{1,1,0,0,1}, {1,4,0,1,0}, {0,0,0,2,0}, {1,0,2,0,0}, {0,0,3,2,0}};
   int np=move_pecas1(tab);
   printf("\n\nPecas: %d,  Novo Tab: \n", np);
   for(int i=0; i<N; i++) {
       for(int j=0; j<N; j++) 
           printf("%d ", tab[i][j]);
       printf("\n");
    }
   
   printf("\n"); system("PAUSE"); return 0;   
}
