// Exercício Diversos - Switch Case e Recursividade
#include <cstdio>
#include <cstdlib>
/* 
a) Construa funções para calcular o fatorial de um dado número inteiro.
a1) Função Recursiva, a2) Função Iterativa
Experimente as funções construídas para calcular o fatorial dos números de 1 a 10.

b) Construa funções para calcular o fibonacci de um dado número inteiro.
b1) Função Recursiva, b2) Função Iterativa
Experimente as funções construídas para calcular o fibonacci dos números de 1 a 30.
*/

//Fatorial - versão recursiva
long fatorial(long n)
{
	if (n==0||n==1) return 1;
	else return n*fatorial(n-1);
}
//Fatorial - versão iterativa
long fatorial2(long n)
{
	long fact=1;
    for(int i=1; i<=n; i++)
        fact*=i;  // fact = fact*i;
    return fact;
}

//Fibonacci - versão recursiva
long fibonacci(long n)
{
	if (n==0||n==1) return n;
	else return fibonacci(n-1) + fibonacci(n-2);
}

//Fibonacci - versão iterativa
long fibonacci2(long n)
{
	int first = 0, second = 1, next;
   	for (int c = 0; c <= n; c++){
    	if (c <= 1) next = c;
      	else {
         	next = first + second;
         	first = second;
         	second = next;
      	}
 	}
 	return next;
}

int main()
{
	for(int x=1; x<=10; x++) 
		printf("Fatorial %3d = %7d %7d\n", x, 
			fatorial(x), fatorial2(x));
	for(int x=1; x<=30; x++) 
		printf("Fibonacci %2d = %7d %7d\n", x, 
			fibonacci(x), fibonacci2(x));
}

// Estruturas de Controlo: Utilização da Instrução switch ... case...
// Ex: Dado o modo de jogo 1-4 escreve-lo no ecran
// Nota: Utilize a instrução switch. 
// Experimente a utilização ou não do break.

/*
int main2(void)
{
    int modo;
    printf("Modo de Jogo 1-4? ");
    scanf("%d", &modo);

    switch(modo)
    {
         case 1: printf("Modo 1: Humano vs Humano!\n"); break;         
         case 2: printf("Modo 2: Humano vs PC!\n"); break;           
         case 3: printf("Modo 3: PC vs Humano!\n"); break;           
         case 4: printf("Modo 4: PC vs PC!\n"); break;
         default: printf("Modo Invalido!\n");                  
    }

    system("PAUSE");
    return 0;
}*/
