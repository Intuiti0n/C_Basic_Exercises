#include <stdio.h>
#include <stdlib.h>

void nl(void) 
{ 
	printf("\n"); 
}

void linha(int n, char simb)
{
   for(int i=0; i<n; i++)
       printf("%c",simb);
}

void desenha_quad(int n, char simb)
{
     for(int i=0; i<n; i++) {
         linha(n,simb); nl();
     }
}

void desenha_quad_vazio(int n, char simb)
{
     for(int i=0; i<n; i++) {
         for(int j=0; j<n; j++)
             if(i==0 || i==n-1 || j==0 || j==n-1) 
			 	printf("%c",simb);
             else printf(" ");
         nl();
     }
}

void desenha_quad_vazio2(int n, char simb) //outra resolucao
{
     linha(n,simb); nl();
     if(n==1) return;
	 for(int i=1; i<n-1; i++) {
         printf("%c",simb); linha(n-2,' '); printf("%c",simb); nl();
     }
     linha(n,simb); nl();
}
void desenha_tria(int n, char simb)
{
     for(int i=0; i<n; i++) {
         linha(n-i,simb); nl();
     }
}
void desenha_tria2(int n, char simb)  //outra resolucao
{
     for(int i=n; i>=1; i--) {
         linha(i,simb); nl();
     }
}

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

void desenha_cobra(int n, char simb)
{
   for(int i=1; i<=n; i++) {
      linha(n,simb); nl();
      if (i%2==1) linha(n-1,' ');
      printf("%c",simb); nl();
   }
}

int main(void)
{    
    int dim; char ch;
	printf("Entre a Dimensao: "); scanf("%d",&dim);
	fflush(stdin);   //apaga o buffer para eliminar o enter
	printf("Entre o Caracter: "); scanf("%c",&ch);
	    
    //ch='#';
    //for(dim=1; dim<=10; dim++) {  //ex 8
       printf("Dimensao %d\n",dim); nl();
       linha(dim, ch); nl(); nl();
       desenha_quad(dim, ch); nl();
       desenha_tria(dim, ch); nl();
       desenha_quad_vazio(dim, ch); nl();
       desenha_arvore(dim, ch); nl();
       desenha_cobra(dim, ch); nl();
	//}  //ex8
    //system("PAUSE"); return 0;
}


