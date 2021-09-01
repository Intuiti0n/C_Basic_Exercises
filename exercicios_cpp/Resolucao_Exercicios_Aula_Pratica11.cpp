#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*10.1) Escreva uma função void grava_numeros(void) que 
permita ao utilizador introduzir numero inteiros 
(terminados por -1) e escreva num ficheiro de texto 
("numeros.txt") esses números inteiros. Escreva uma 
função int leitura_numero(void) que leia um ficheiro 
de texto ("numeros.txt") com números inteiros e 
determine (retornando esse valor) o maior número contido 
nesse ficheiro. */
void grava_numeros(void)
{
	FILE *fich;  
    if ( (fich= fopen( "numeros.txt", "w") ) == NULL ) {
         printf( "Impossivel criar ficheiro \n" ); return;}  
    int num;
    do{
    	printf("N?"); scanf("%d",&num);
    	if(num>0) fprintf(fich,"%d ",num);
    } while(num!=-1);
    fclose(fich);
}

int leitura_numeros(void)
{
	FILE *fich;  
    if ( (fich= fopen( "numeros.txt", "r") ) == NULL ) {
         printf( "Impossivel abrir o ficheiro \n" ); return 0;}
    int num, maior=0;
	while(!feof(fich)){
		fscanf(fich,"%d",&num);
		if(num>maior) maior=num;
	}
	fclose(fich);
	return maior;
}

int main1()
{ 
	grava_numeros();
	printf("Maior: %d\n",leitura_numeros());
	return 0;
}

/*10.2)	Escreva as funções void grava_estado(void) e 
void le_estado(void) que permitam armazenar o estado 
do seu jogo de tabuleiro (trabalho prático da disciplina) 
num ficheiro de texto e que permitam ler o estado do 
jogo do ficheiro e continuar o jogo a partir desse 
estado. Introduza no código do jogo a possibilidade de 
em qualquer instante gravar o estado e/ou abortar o 
jogo atual e continuar um jogo anteriormente gravado. */
/*Exemplo: Ficheiro. Chamar le_estado() em vez de 
inicializa_tabuleiro
1 0 1
2 1 0
0 0 0 */
int tabul[3][3];

void le_estado()
{
	FILE *fich;  
    if ( (fich= fopen( "estado.txt", "r") ) == NULL ) {
         printf( "Impossivel abrir o ficheiro \n" ); return;}
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            fscanf(fich, "%d",&tabul[i][j]);
    fclose(fich);
}

void escreve_estado()
{
	FILE *fich; 
	
	//...
	
	fclose(fich); 	
}

/*10.3)	Escreva uma função void converte(void) em 
linguagem C/C++ que converta todos os nomes de
pessoas contidos no ficheiro de texto "nomes.txt" 
(um nome por linha), de um "formato normal" para um 
"formato compacto", como se exemplifica a seguir. 
O resultado (nomes num formato compacto) devem ser 
colocados num outro ficheiro de texto "nom_compactos.txt". 
Exemplo:
Formato Normal:   	Zeferino Pedro Dinis Aguiar
Formato Compacto:	Aguiar, Z. P. D.
*/  /*
Começar por criar um ficheiro de texto  “nomes.txt” 
utilizando o notepad (ou outro editor) com o conteudo:
Zeferino Pedro Dinis Aguiar
Ana Isabel Afonso Gouveia
Joana Maria Sousa Reis
...  */
//Exercicio Aula 8
void converteNome(const char nomeNorm[], char nomeComp[])
{
	char *stUlt = strrchr(nomeNorm,' ');
	stUlt++; 
	strcpy(nomeComp, stUlt);
	strcat(nomeComp, ",");
	for (int i=0; i<strlen(nomeNorm)-strlen(stUlt)-1; i++)
		if (nomeNorm[i-1]==' ' || i==0) {
			strcat(nomeComp, " ");
			strncat(nomeComp, &nomeNorm[i], 1);
			strcat(nomeComp, ".");
		}	
}

void converte(void)
{
	FILE *fEnt, *fSai; 
	char nome[80],ncom[50]; 
	if ((fEnt= fopen( "nomes.txt", "r") ) == NULL ) {
         printf( "Impossivel abrir o ficheiro de nomes \n" ); return;}
  	if ((fSai= fopen( "nom_compactos.txt", "w") ) == NULL ) {
         printf( "Impossivel criar ficheiro \n" ); return;} 
    do{
    	fgets(nome,80,fEnt);
    	if (nome[strlen(nome)-1]=='\n')
    		nome[strlen(nome)-1]='\0';  //para eliminar o \n considerado pelo fgets
    	converteNome(nome,ncom);
    	printf("|%s|->|%s|\n",nome,ncom);
		fputs(ncom,fSai); fputc('\n',fSai);
    } while(!feof(fEnt));
    fclose(fEnt); fclose(fSai);
}

int main()
{ 
	converte();
	return 0;
}

/*Suponha  um  ficheiro  de  texto  (“Futebol.txt”)  contendo  em
cada  linha,  ordenado  alfabeticamente  a  seguinte informação 
acerca dos clubes que disputam um campeonato de futebol: 
- Nome do clube (sem espaços); 
-Número de golos marcados; 
- Número de golos sofridos; 
- Pontuação. 
Suponha  que  tem  disponível  um  ficheiro  de  texto  
(“Result01.txt”),  contendo  os  resultados  da  jornada  1  
do campeonato, com o aspecto que se exemplifica a seguir. 
Ficheiro Exemplo: 
PORTO 5 BENFICA 0 
VITORIAGUIMARAES 2 SPORTING 1 
BELENENSES 0 BOAVISTA 1 
Escreva uma função que actualize o ficheiro “Futebol.txt” 
tendo em conta os resultados de “Result01.txt” e que, 
no  final  escreva  o  conteúdo  do  ficheiro  actualizado 
também  no  écran.  Para  tal,  a  função  deverá  ler  o  
ficheiro “Result01.txt” e atualizar o ficheiro “Futebol.txt”. 
Deverá ler cada linha do ficheiro “Result01.txt”  e decompô-la 
nos  seus  elementos,  depois  procurar os clubes no 
ficheiro  “Futebol.txt”. Atualizar os registos e reescrever  
o conteúdo do ficheiro “Futebol.txt”. */
struct equipa{
	char nome[20];
	int gm, gs, pont;
}; 
#define NEQ 6

void le_classif(equipa cla[])
{
	FILE *fich = fopen("Futebol.txt","r");
	if (fich==NULL) return;
	int i=0; char st[10];
	while(!feof(fich)){
		fscanf(fich,"%s%d%d%d", cla[i].nome, &cla[i].gm, 
		       &cla[i].gs, &cla[i].pont);
		i++;	
	}
}

void mostra_classif(equipa cla[])
{
	for(int i=0; i<NEQ; i++) {
		printf("%15s (%2d-%2d) %2d p\n", cla[i].nome,
			cla[i].gm, cla[i].gs, cla[i].pont);
	}
}

int main3()
{
	equipa cla[18];
	le_classif(cla);
	mostra_classif(cla);
	//atualiza_classif("Result01.txt");
	//mostra_classif(cla);
	return 0;	
}

