#include <cstdio>  //Standard Input/Output - Printf e Scanf

/*
1)	Construa um programa em linguagem C/C++ para imprimir os 
números entre 1 e N (dado pelo utilizador). Faça versões 
utilizando os três tipos de ciclos: for for ..., do ... while, 
e while ...
*/

//mudar para int main() para experimentar
int main1()
{
    int i, n;
    
	printf("N? "); 
	scanf("%d",&n);
    
    for(i=1; i<=n; i++) 
	    printf("%d ", i);
	    
    i=1;
    do {
	    printf("%d ", i);
        i++;
    } while(i<=n);
    
    i=1;
    while(i<=n) 
	    printf("%d ", i++);
}

/*
2)	Construa um programa em linguagem C/C++ para calcular a soma 
dos números inteiros entre 1 e N (dado pelo utilizador). Faça as 
versões utilizando os três tipos de ciclos: for ..., do ... while, 
e while ... 
Altere o programa para calcular exclusivamente a soma dos números 
pares entre 1 e N.
*/
// Estruturas de Controlo: Ciclos For, Do, While
/* Exercicio 2.1) Calcular a soma dos numeros entre 1 e N. Fazer versões 
   utilizando ciclo for ..., do ... while, e while ...
Analise
Variaveis  Ent/Sai  Tipo  Exemplos
   n       Entrada  int   3   5   7
   soma    Saida    int   6  15  28  
*/

//mudar para int main() para experimentar
int main2(void)
{

    int i, n, soma;
	printf("N? "); scanf("%d",&n);
    
    soma = 0;
    for(i=1; i<=n; i++)  //soma de pares for(i=2; i<=n; i+=2)
        soma = soma + i;
	
	printf("Soma = %d\n", soma);
/*      
    soma = 0;
    i=1;
    do {
        soma = soma + i;
        i++;
    } while(i<=n);
	
	printf("Soma = %d\n", soma);
*/
/*    
    soma = 0;
    i=1;
    while(i<=n) {
        soma = soma + i;
        i++;
    }
	
	printf("Soma = %d\n", soma);
*/
   
}

/*
3)	Construa um programa para imprimir no écran os 256 caracteres 
ASCII (nota: Utilize printf("%c ", i)).
*/

int main3(void)
{	
	for(int i=0; i<=255; i++)
		printf("%d -> %c\n",i,i);  //Imprime o nº e o caracter com esse numero
}

/*
4)	Dado um numero N escrever a tabuada dos N. Crie três soluções 
utilizando os três tipos de ciclos da linguagem C/C++.
Exemplo: N? 5
5 x   1 =  5
5 x   2 = 10
5 x   3 = 15
...
5 x 10 = 50
*/

int main4(void)
{
    int i,n;
    printf("Qual a Tabuada? ");
    scanf("%d",&n);
    
    //ciclo for...
    for(i=1; i<=10; i++) 
       printf("%d x %2d = %3d\n", n, i, n*i);
    
    //ciclo do...while
   	/*i=1;
    do {
        printf("%2d x %d = %3d\n", i, n, n*i);
        i++;
    } while(i<=10); 
 	*/
    //ciclo while...
    /*i=1;
    while(i<=10) {
        printf("%2d x %d = %3d\n", i, n, n*i);
        i++;
    }*/
}

/*
5)	Construa um programa em C/C++ que leia uma quantidade não 
determinada de números positivos. Calcule a quantidade de números 
pares e ímpares, a média de valores pares e a média geral dos 
números lidos. O número que encerrará a leitura será zero.
*/

int main5()
{
   int i = 0, num = 1, pares = 0, impares = 0, soma = 0, somapares = 0;
   
   while(num!=0) {
      printf("Entre um Numero Positivo (0-acaba)? ");          
      scanf("%d", &num);
      if (num>0) {
         soma += num;
         if (num%2==0) { pares++; somapares += num; }
         else impares++;
         i++;
      }
   }
   
   printf("Pares: %d  Impares: %d  Media: %.2f  MediaPares: %.2f \n",
          pares, impares, (float)soma/i, (float)somapares/pares);
} 


/*
6)	Construa um programa para desenhar triângulos de dimensão N 
(fornecido pelo utilizador).
Exemplos:
N=1 *       N=5 *
                **
N=3 *           ***
    **          ****
    ***         *****
*/

int main6(void)
{
    int i,j,n;
    printf("Tamanho do Triangulo? ");
    scanf("%d",&n);
    
    for(i=1; i<=n; i++) {
        for(j=1; j<=i; j++) printf("*");
        printf("\n");
    }   
    return 0;
}

