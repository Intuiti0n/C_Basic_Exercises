//ficha 3 algoritmos com ciclos - Desenho

#include <stdio.h>

/*Escreva uma função void nl(void) que simplesmente mude o cursor de linha (a função faz um printf("\n").*/
void nl(void){
    printf("\n");
}

/*Escreva uma função que desenhe uma linha com N símbolos (caracteres do tipo simb passado como parâmetro à
função) void linha(int N, char simb).*/
void linha(int N, char simb){
    int i;
    for(i=0;i<N;i++){
        printf("%c",simb);
    }
}

/*Escreva uma função void desenha_quad(int N, char simb) que desenha quadrados de N*N
símbolos.*/
void desenha_quad(int N, char simb){
    int i;
    for(i=0;i<N;i++){
        linha(N,simb);
        nl();
    }
}
/*Escreva uma função void desenha_tria(int N, char simb) que desenha triângulos de N*N
símbolos.*/
void desenha_tria(int N, char simb){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N-i;j++){
            printf("%c",simb);
        }
        nl();
    }
}

/*Escreva uma função void desenha_quad_vazio(int N, char simb) que desenha quadrados com o
interior não preenchido de N*N símbolos.*/
void desenha_quad_vazio(int N, char simb){
    int i,j;
    for(i=0;i<N;i++){
        if(i==0||i==N-1){
            linha(N,simb);
        }
        else{
            for(j=0;j<N;j++){
                if(j==0||j==N-1)
                    printf("%c",simb);
                else printf(" ");
            }
        }
        nl();
    }
    nl();
}

/*Escreva uma função void desenha_arvore(int N, char simb) que desenha uma arvore de natal
com dimensão N utilizando um dado símbolo. Quer o tronco quer a copa têm altura N.*/
void desenha_arvore(int n, char simb)
{
     for(int j=1; j<=n; j++) {
         linha(n-j,' ');
         linha(j*2-1,simb); nl();
     }
     for(int j=1; j<=n; j++) {
         linha(n-1,' ');
         printf("%c\n",simb);
     }
}
/*Escreva uma função void desenha_cobra(int N, char simb) que desenha uma cobra com dimensão
N*2 por N utilizando um dado símbolo.*/
void desenha_cobra(int n, char simb)
{
   for(int i=1; i<=n; i++) {
      linha(n,simb); nl();
      if (i%2==1) linha(n-1,' ');
      printf("%c",simb); nl();
   }
}




/*Escreva um programa principal que desenhe 10 vezes todos os desenhos anteriores começando com a dimensão 1
e acabando com a dimensão 10.*/
int main()
{
     int dim; char ch;
	printf("Insira a Dimensao: "); scanf("%d",&dim);
	fflush(stdin);   //apaga o buffer para eliminar o enter
	printf("Insira o simbolo: "); scanf("%c",&ch);
	    
    //ch='#';
    //for(dim=1; dim<=10; dim++) {  //ex 8
       printf("Dimensao %d\n",dim); nl();
       linha(dim, ch); nl(); nl();
       desenha_quad(dim, ch); nl();
       desenha_tria(dim, ch); nl();
       desenha_quad_vazio(dim, ch); nl();
       desenha_arvore(dim, ch); nl();
       desenha_cobra(dim, ch); nl();
    return 0;
}
