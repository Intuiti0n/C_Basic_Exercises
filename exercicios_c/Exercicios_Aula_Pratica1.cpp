#include <cstdio>

/*
1)	Escreva um algoritmo e correspondente programa em C/C++ 
para calcular o maior de dois números inteiros fornecidos pelo 
utilizador (N1 e N2).
*/

int main()
{
    int n1, n2;  // Definicao das Variaveis de entrada
    int maior;   // Definicao das Variaveis de saida
    
    printf("Entre dois numeros Inteiros: ");
    scanf("%d %d", &n1, &n2);  // input - entrada de dados
    
    if (n1>n2) maior=n1; else maior=n2;  // processamento - calculo da solução
    
    printf("O Maior Numero e' %d \n", maior);  // output - saida de dados
    
	return 0;   
}

//Testes:
// 3 4  O Maior Numero e' 4
// 2 9  O Maior Numero e' 9
// 5 5  O Maior Numero e' 5

/*
2)	Escreva um algoritmo e correspondente programa em C/C++ 
para calcular o maior de três números inteiros dados pelo 
utilizador (N1, N2 e N3).
*/
/*Analise
Variaveis  Ent/Sai  Tipo    Exemplos
   n1      Entrada  int   3  12  4  8 
   n2      Entrada  int   5   8  6  8
   n3      Entrada  int   9   3  4  8
   maior   Saida    int   9  12  6  8
*/
/*
int main(void)
{
    int n1,n2,n3;  //variaveis de entrada
    int maior;     //variavel de saida
   
    printf("Entre tres numeros Inteiros: ");
    scanf("%d %d %d",&n1,&n2,&n3);  //input de três numeros inteiros
   
    if (n1>n2 && n1>n3) maior = n1; 
       else if (n2>n3) maior = n2; 
	        else maior = n3;
       
    //outra solução:
    //if (n1>n2) maior = n1; else maior = n2;
    //if (n3>maior) maior = n3;
    
    printf("O maior e' %d\n", maior);   //output
   
    return 0;
}
*/

/*
3)	Escreva um algoritmo e correspondente programa em C/C++ 
para calcular, dados três números inteiros, a soma dos dois 
menores.
*/
/*
int main(void)
{
    int n1, n2, n3;   // var entrada
    int maior, soma;  // var saida
   
    printf("Entre tres numeros Inteiros: ");
    scanf("%d %d %d", &n1, &n2, &n3);  // input de 3 números inteiros (%d)
   
    if (n1>n2 && n1>n3) maior = n1; 
       else if (n2>n3) maior = n2; 
	        else maior = n3;  //calculo do maior
   
    soma = n1 + n2 + n3 - maior;  // soma dos 2 menores = soma de todos - maior
    
    printf("A soma e' %d\n", soma); // output
   
    return 0;
}
*/

/*
4)	Construa um programa em C/C++ que calcule a média aritmética 
das 3 notas de um aluno e mostre, além do valor da média, uma 
mensagem de "Aprovado", caso a média seja igual ou superior a 9.5, 
ou a mensagem "Reprovado", caso contrário. 
*/
/*
int main(void)
{
    int n1, n2, n3;   // var entrada
    float media;  // var saida
   
    printf("Entre tres numeros Inteiros: ");
    scanf("%d %d %d", &n1, &n2, &n3);  // input de 3 números inteiros (%d)
   
    media = (float)(n1+n2+n3)/3;  // ou media =(n1+n2+n3)/3.0; 
    if (media>=9.5) printf("Aprovado\n"); else printf("Reprovado\n");
	printf("Media = %.2f\n", media); // output
   
    return 0;
}
*/

/*
5)	Construa um algoritmo e correspondente programa em C/C++ que 
leia um nº inteiro e mostre uma mensagem indicando se este número 
é par ou ímpar, e se é positivo ou negativo.
*/
/*
int main(void)
{
    int n; 
   
    printf("Entre um Numero Inteiro: ");
    scanf("%d", &n); 
   
    if (n%2==0) printf("Par "); else printf("Impar ");
    if (n>0) printf("e Positivo!"); 
	    else if (n<0)printf("e Negativo!");
	         else printf("e Nulo!");
    return 0;
}
*/

