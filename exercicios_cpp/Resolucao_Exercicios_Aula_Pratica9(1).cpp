#include <stdio.h>
#include <stdlib.h>

/*
15) Construa a fun��o void pira(int alt) que dada a altura alt desenhe 
pir�mides compostas de s�mbolos * e O, com aspeto semelhante ao apresentado abaixo, de acordo com os exemplos apresentados:
pira(1)	pira(2)	pira(3)	pira(5)
**	 **	      **	    **
	*OO*	 *OO*	   *OO*
		    *OOOO*	  *OOOO*
		        	 *OOOOOO*
		        	*OOOOOOOO*
*/

void nc(int n, char c) { 
	for(int i=0; i<n; i++) printf("%c",c); 
}

void pira(int N2)
{
    for(int i=0; i<N2; i++) {
       nc(N2-i-1,' '); printf("*"); nc(i*2, 'O'); printf("*\n"); 
    } 
    printf("\n");        
}

/*
16) Construa uma fun��o void calculos(int a, double x) que receba dois 
n�meros (um inteiro e um real) e escreve no �cran (sempre utilizando 
campos com 10 casas (nos exemplos os '.' representam espa�os): os dois 
n�meros; a divis�o (real) dos n�meros por 5 (com duas casas decimais); 
a divis�o inteira dos n�meros por 5 e os n�meros formatados, com a 
formata��o apresentada abaixo (colocando 1 a 5 zeros � esquerda e 
colocando 1 a 5 casas decimais).
Exemplos: calculos(2, 9.5)	calculos(10,15.2344)
.........2......9.50	........10.....15.23
......0.40......1.90	......2.00......3.05
.........0.........1	.........2.........3
.........2.......9.5	........10......15.2
........02......9.50	........10.....15.23
.......002.....9.500	.......010....15.234
......0002....9.5000	......0010...15.2344
.....00002...9.50000	.....00010..15.23440
*/
	
void calculos(int a, double x) 
{
     printf("%10d%10.2f\n", a, x);
     printf("%10.2f%10.2f\n", a/5.0, x/5.0);
     printf("%10d%10d\n", a/5, (int)x/5);
     
     for(int i=1; i<=5; i++)
         printf("%10.*d%10.*f\n", i, a, i, x);
}

/*
17) Escreva uma fun��o bool pede_data(int *dia, int *mes, int *ano) que pe�a 
uma data ao utilizador (dia, m�s e ano) e verifique se a data � v�lida. 
Na resolu��o do exerc�cio siga as seguintes regras:
- Considere que o ano � v�lido se for igual ou inferior a 2012. 
- Ignore os anos bissextos considerando que Fevereiro tem sempre 28 dias. 
- Utilize a instru��o switch ... case, na fun��o, para determinar o n�mero 
 de dias do m�s.
- Caso a data seja v�lida retorne verdadeiro e os valores correspondentes 
  do dia, m�s e ano. 
- Caso a data seja inv�lida retorne falso e 0, 0, 0 para o dia, m�s e ano.
*/

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

/*            
18) Construa uma fun��o int inverte(int v1[], int n1, int val1, int val2) 
que dado um vector de inteiros inverta o vetor e ao mesmo tempo substitua 
todos os elementos iguais a val1 por val2 retornando o n�mero de elementos 
substituidos. 
Por exemplo: Supondo int v1[11]={1,2,3,5,7,3,8,9,9,3,4}, a chamada de 
inverte(v1,11,3,10) retorna o valor 3 e o vector v1[11] ficar� com os 
valores:
{4,10,9,9,8,10,7,5,10,2,1}
*/

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

/*
19) Construa um programa principal que lhe permita testar, com exemplos 
relevantes, os programas constru�dos nas al�neas 15, 16, 17 e 18.
*/

int main()
{
   // Exerc 15 - Exemplo de chamada 
   pira(1); pira(2); pira(3); pira(5); 
   
   // Exerc 16 - Exemplo de chamada para teste
   calculos(2, 9.5);  
   calculos(10, 15.2344);
    
   // Exerc 17 - Exemplo de chamada para teste
   bool valida;
   int d,m,a;
   valida = pede_data(&d, &m, &a);
   if (valida) printf("Data: %2.2d/%2.2d/%2.2d\n", d,m,a);
   else printf("Data Invalida\n");

   // Exerc 18 - Exemplo de chamada 
   int v1[11]={1,2,3,5,7,3,8,9,9,3,4};
   int n = inverte(v1, 11, 3, 10);
   printf("n= %d  v1[11]= ", n);
   for(int i=0; i<11; i++) printf("%d ", v1[i]);
    
   printf("\n"); system("PAUSE");   return 0;   
}
