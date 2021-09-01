#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void entra_string(char st[])
{
	printf("Entre um Nome Completo e Idade? ");
	gets(st);	
}
	
void separa(const char st[], char nome[], int &idade)
{
	char *stid = strrchr(st,' ');  //apontador para string que começa no ultimo espaço
	idade = atoi(stid);  //converte para inteiro
	//strncpy(nome, st, strlen(st)-strlen(stid)); //copia n caracteres de st para nome
	//strcat(nome,"\0");
	*stid='\0'; strcpy(nome, st);  //Outra solucao: substitui espaço por \0 terminando st ai'
}

void nome_maiusculas(const char nome[], char nomeMai[])
{
	for(int i=0; i<=strlen(nome); i++)
		nomeMai[i]=toupper(nome[i]);
	//strcpy(nomeMai,nome); strupr(nomeMai); //outra hipotese de solução
}

void nome_eliminaChar(const char nome[], char Ch, char nomeRes[]) 
{
	for(int i=0, j=0; i<=strlen(nome); i++)
		if (nome[i]!=Ch) { nomeRes[j]=nome[i]; j++; } 
}

void converte(const char nomeNorm[], char nomeComp[])
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

bool existe_nome(const char nome[], char nomeProc[], 
      int&pos, int &nCar)
{
  char *pch;
  pch = strstr(nome,nomeProc);
  if (pch==NULL) return false;
  pos = pch - nome; //pos é o endereço da posicao e nome o endereço do inicio
  nCar = strlen(nomeProc);
  return true;
}

int idade_ano(const char st[], int anoX)
{
	char nom[40]; int id;
	separa(st, nom, id);
	return id+anoX-2014;
}

int  compara_nome(const  char  nome1[],  const  char  nome2[])
{
	return strcmp(nome1,nome2);
} 

int main()
{
	char st[40], nome[40], nomeMai[40], 
	     nomeSem[40], nomeC[20], nomeP[20];
	int idade, anoX, pos, nCar;
	
	entra_string(st);
	printf("String: %s\n", st);
	
	separa(st,nome,idade);
	printf("Nome: #%s# Idade: #%d#\n", nome, idade);
	
	nome_maiusculas(nome,nomeMai);
	printf("NomeMaiusculas: %s\n", nomeMai);
	
	nome_eliminaChar(nome, ' ', nomeSem);
	printf("Nome sem ' 's: %s\n", nomeSem);
	
	converte(nome,nomeC);
	printf("NomeCompacto: %s\n", nomeC);
	
	printf("Ano? "), scanf("%d", &anoX); 
	printf("Idade em %d e' %d!\n", anoX, idade_ano(st,anoX));
	
	fflush(stdin); //limpa buffer de entrada do teclado
	printf("Nome a Procurar? "); gets(nomeP);
	bool ex=existe_nome(nome, nomeP, pos, nCar);
	if (ex) printf("Existe na Pos = %d com %d caracteres!\n",pos,nCar);
	else printf("Nao Existe!\n");	
	
	char nome1[]="Luis", nome2[]="Antonio";
	printf("Compara %s e %s = %d",nome1, nome2, compara_nome(nome1,nome2));	
	return 0;
}
