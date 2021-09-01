#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>

// Resposta Multipla

//1) Indique o que faz o seguinte programa:
void fich(void){ 
  int n;
  FILE *fich = fopen("t.txt","w");
  if (fich!=NULL) { 
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
       fprintf(fich,"%d %d\n", i, i*i);
    }
    fclose(fich);
  }
}
/* a) Lê um ficheiro com números de 1 a n (dado pelo utilizador) e e escreve os seus quadrados 
b) Cria um ficheiro com a tabuada dos n (dado pelo utilizador)
c) Cria um ficheiro com os números de 1 a n (dado pelo utilizador)
d) Cria um ficheiro com os números de 1 a n (dado pelo utilizador) e os seus quadrados 
e) Nenhuma das Anteriores
*/

//Suponha a seguinte função em linguagem C:
void fx(int a, int b)
{
  if(a>=8 && a<=b || a<6) printf("1");
  if(b>6||a<3) printf("2");
  else if (!(a!=b))printf("3"); 
}
//2) Se executar a chamada fx(8,8) o que é escrito no ecrã?
//a) 13   b) 1   c) 2   d) 3   e) Nenhuma das Anteriores
//
//3) Se executar a chamada fx(5,6) o que é escrito no ecrã?
//a) 13   b) 1   c) 2   d) 3   e) Nenhuma das Anteriores

//4) Supondo o seguinte programa em linguagem C/C++ indique o que é escrito no ecrã.
int ap1(void){   
  int *ap, x, y, z;
  x = 20; ap = &x; y = 2*x; z = 2*(*ap); *ap = 40;
  printf("x=%d y=%d z=%d \n", x,y,z);
}
/*a) x=40 y=40 z=40
b) x=20 y=40 z=40
c) Nada pois o programa dá erro na compilação
d) x=20 y=20 z=40
e) Nenhuma das Anteriores */

//5) Indique o que escreve no ecrã a seguinte função:
void fstring(void) {
    char st[] = "Mundial Futebol";
    printf("%c-%d\n", st[strlen(st)-3], strlen(st));
}
//a) o-15   b) i-15    c) l-16    d) b-16
//e) Nenhuma das Anteriores

//6) Diga o valor que é impresso no écran depois da seguinte sequência de operações: 
void c1(){
  int x,y,z,w; x=y=10; ++x; w =-x++; z = x+y+2*w;
  printf("%d\n",z);
}
//a)  2     b) 0     c) -18     d)  9     e) Nenhuma das Anteriores

//7) Diga o valor que é impresso no écran depois da seguinte sequência de operações 
void c2(){
  int x,y,z,w; x=10; y=x-1; w =-(--x*2); z = x+y+w;
  printf("%d\n",z);
}
//a) Nada pois dá erro de compilação   b) 0     c) -18     d)  9    
//e) Nenhuma das Anteriores

//8) Indique o que escreve no ecrã a seguinte função:
int compara1(void) {
  char s1[]="aaxa"; char s2[]="aXAA"; char s3[]="aaxaa"; 
  printf("%d %d \n", strcmp(s1,s2), strcmp(s1,s3));
}
//a)   -1 -1    b)     1 1    c)   -1 1    d)    1 -1
//e) Nenhuma das Anteriores

//9) Indique o que escreve no ecrã a seguinte função:
int compara2(void) {
  char s1[]="14"; char s2[]="1000"; char s3[]="140"; 
  printf("%d %d \n", strcmp(s1,s2), strcmp(s1,s3));
}
//a)   -1 -1    b)     1 1    c)   -1 1    d)    1 -1
//e) Nenhuma das Anteriores

//Suponha as seguintes funções:
void st1() {
	char *st = "45 54 26"; 
	int x = atoi(st); 
	printf("%d\n",x);
}
void st2(){
char *st = "45 54 26";
	char *stid = strrchr(st,' ');
	int x = atoi(stid); 
	printf("%d\n",x);
}
void st3() {
	char *st = "45 54 26"; 
	st++; 
	int x = atoi(st); 
	printf("%d\n",x);
}
//10) O que escreve no ecran a função st1()?
//a)  26    b) 5    c) 45    d)  54    e) Nenhuma das Anteriores
//
//11) O que escreve no ecran a função st2()?
//a)  26    b) 5    c) 45    d)  54    e) Nenhuma das Anteriores
//
//12) O que escreve no ecran a função st3()?
//a)  26    b) 5    c) 45    d)  54    e) Nenhuma das Anteriores

void resp_mult()
{
	printf("\nEx1 : "); 	fich(); 
	printf("\nEx2 : ");		fx(8,8); 
	printf("\nEx3 : ");		fx(5,6); 
	printf("\nEx4 : ");		ap1(); 
	printf("\nEx5 : ");		fstring(); 
	printf("\nEx6 : ");		c1(); 
	printf("\nEx7 : ");		c2(); 
	printf("\nEx8 : ");   	compara1();
	printf("\nEx9 : ");   	compara2();
	printf("\nEx10: ");  	st1();
	printf("\nEx11: ");  	st2();
	printf("\nEx12: ");  	st3();
}

//Exercicio 13
void nl(){printf("\n");}
void nc(int n, char c) { for(int i=0; i<n; i++) printf("%c", c); }

void casa(int alt, int larg) 
{
	if (larg%2==0) return;   //%1
	for(int i=1; i<=larg; i+=2) {   //%1
		nc((larg-i)/2,' '); nc(i,'O'); nl();  //%1
	}
	for(int i=1; i<=alt; i++) {   //%1
		nc(larg,'X'); nl();      //%1
	}
}

//Exercicio 14
int substitui(char let, char frase[])
{
	char Nom1[50], Nom2[50], ch;
	printf("Entre Ficheiro 1:"); gets(Nom1);
	printf("Entre Ficheiro 2:"); gets(Nom2);
	FILE *fich1 = fopen(Nom1,"r");
	FILE *fich2 = fopen(Nom2,"w");
  	if (fich1==NULL || fich2==NULL) { printf("ERRO!\n"); return 0;}
  	while (!feof(fich1)) {
  		ch = getc(fich1);
		if (ch!=let) fputc(ch, fich2);	else fputs(frase, fich2);
  	}
  	fclose(fich1); fclose(fich2);
}

//Exercicio 15
int cidades(char cid1[], char cid2[], double &dif)
{
	char st[50], cid[20];
	int m; double pl, tot1=0.0, tot2=0.0;
	FILE *fich = fopen("cidades.txt","r");
	if (fich==NULL) { printf("ERRO!\n"); return 0;}
  	while (!feof(fich)) {
  		//fgets(st,50,fich);
  		fscanf(fich,"%s%d%f",cid, &m, &pl);
  		printf("%s*%d*%f*\n",cid,m,pl);
  		if (strcmp(cid,cid1)==0) tot1++; //=pl;
  		if (strcmp(cid,cid2)==0) tot2+=pl;
  	}
  	dif = tot1-tot2;
  	if (dif>10.0) return 1; 
	else if (dif<-10.0) return 2;
	else if(strcmp(cid1,cid2)==1) return 1;
	else return 2;
	 
	fclose(fich);	
}


//Exercicio 16
#define N 5
int conta_ac(int tab[N][N], int jog) 
{
	int count=0;
	for(int i=0; i<N; i++) 
		for(int j=0; j<N; j++)
			if(tab[i][j]==jog+2) {
				if(!((i==0 || tab[i-1][j]==0 || tab[i-1][j]==8)&&
					(i==N-1 || tab[i+1][j]==0 || tab[i+1][j]==8)&&
					(j==0 || tab[i][j-1]==0 || tab[i][j-1]==8)&&
					(j==N-1 || tab[i][j+1]==0 || tab[i][j+1]==8)))
					count++;
			} 
	return count;
}
//Exercicio 17
char movimento(int tab[N][N], int jog, char dir, int nc)
{
	int x,y,dx,dy;
	do{	
		x=rand()%N; y=rand()%N;	
	} while(tab[y][x]!=jog+2);   //%1.5
	switch (dir) {				//%1.5
		case 'c': dx=0; dy=-1; break;
		case 'b': dx=0; dy=1; break;
		case 'e': dx=-1; dy=0; break;
		case 'd': dx=1; dy=0; break;
	}
	for(int i=0; i<=nc; i++){  //%1
		tab[y][x]=0;
		x=x+dx; y=y+dy;	//%1
		if(x<0 || x>=N || y<0 || y>=N || i==nc ) {   //%2
			tab[y-dy][x-dx]=jog+2; return 'm'; } //fora do tab
		if(tab[y][x]==8) return'a';  //armadilha 
		if(tab[y][x]!=0) { tab[y][x]=jog+2; return'c'; } //peça (1,2,3 ou 4)
	}
}

void mostra_tab(int tab[N][N])
{
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++)
			printf("%d ",tab[i][j]);
		printf("\n");
	}
	printf("\n");
}	
//Exercicio 18
int joga(int tab[N][N]) 
{
	int ac1, ac2, nc, d, ch, jog=1;
	char dir;
	do {
		nc=rand()%5+1; 
		d=rand()%4;
		if(d==0) dir='c'; else if(d==1) dir='b'; else if(d==2) dir='e'; else dir='d';
		ch=movimento(tab, jog, dir, nc);  
		ac1 = conta_ac(tab,1); ac2 = conta_ac(tab,2);
		if (ac1==0 && ac2==0) return 0;
		else if (ac1==0) return 2;
		else if (ac2==0) return 1;
		if(jog==1) jog=2; else jog=1;
	} while (true);
}

//Exercicio 19
int main(void) 
{
	//resp_mult();

	casa(1,1); nl(); casa(3,1); nl(); casa(1,3); nl(); 	//Ex13
	casa(3,2); nl(); casa(2,3); nl(); casa(3,3); nl(); 
	casa(2,5); nl(); casa(1,7); nl(); casa(2,9); nl();
	
	substitui('o', "XXX");   //Ex14
	
	double dif; int cid;	
	cid = cidades("Porto", "Lisboa", dif);    //Ex15
	printf("Porto/Lisboa: %d Dif: %f\n",cid, dif);
	cid = cidades("Beja", "Evora", dif);
	printf("Beja/Evora: %d Dif: %f\n",cid, dif);
	
	int T1[N][N]= {1,1,0,0,1, 1,4,0,1,0, 0,0,0,2,0, 
	        8,0,2,0,3, 4,0,3,0,0};
	int T2[N][N]= {4,8,0,1,3, 0,8,0,1,2, 0,0,3,0,0,  
			3,8,0,3,4, 0,1,2,0,3};
	printf("%d %d %d %d\n", conta_ac(T1,1), conta_ac(T1,2),  //%Ex 16
			conta_ac(T2,1), conta_ac(T2,2));
			
	int Tab[N][N]= {1,2,0,0,1, 1,4,0,8,0, 0,0,0,2,0,
			8,0,2,0,3, 4,0,3,0,0};
	mostra_tab(Tab);
	
	srand(time(NULL));	 //%Ex 17
	movimento(Tab, 2, 'c', 3);  //Nota: Experimentar uma função de cada vez
	//movimento(Tab, 2, 'b', 2);	
	//movimento(Tab, 2, 'b', 5);	
	//movimento(Tab, 2, 'd', 3); 
	mostra_tab(Tab);	

	int Tab1[N][N]= {1,2,0,0,1, 1,4,0,8,0, 0,0,0,2,0,
			8,0,2,0,3, 4,0,3,0,0};   //%Ex 18
	joga(Tab1);   //incluir mostra_tab em cada iteração da função joga também
	mostra_tab(Tab1);

	return 0;
}
