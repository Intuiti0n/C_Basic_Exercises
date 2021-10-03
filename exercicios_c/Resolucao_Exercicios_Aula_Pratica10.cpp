#include <cstdio>

struct data { 
	int dia, mes, ano; 
}; 

struct hora { 
	short int hor, min, seg; 
};

/* 
10.1)  Escreva uma função data pede_data(); que peça ao 
utilizador uma data e a retorne. A data deve ser validada 
(mês entre 1 e 12 e dia entre 1 e o número de dias do 
ano respetivo. 
*/
bool data_valida(data d)
{
	if (d.mes<1 || d.mes>12) return false;
	int diasm=31; 
	if (d.mes==4||d.mes==6||d.mes==9||d.mes==11) diasm=30;
	if (d.mes==2) 
		if (d.ano%400==0||d.ano%4==0&&d.ano%100!=0) diasm=29;
		else diasm=28;
	if (d.dia<1 || d.dia>diasm) return false; 
	return true;
}

data pede_data(void)
{	
	data d;
	do {
		printf("\nEntre uma data no formato dd/mm/aa\n");
		scanf("%d%*c%d%*c%d", &d.dia, &d.mes, &d.ano);
	} while (!data_valida(d));
	return d;
}

/*
10.2)  Escreva uma função mostra_data(const data da);
que dada uma determinada data a mostre no ecrã 
devidamente formatada. 
*/
void mostra_data(const data da)
{
	printf("%2.2d/%2.2d/%4.4d ",da.dia,da.mes,da.ano);
	return;
}
void mostra_data2(const data da)
{
	printf("%d de ",da.dia);
	switch (da.mes){
		case 1:printf("Janeiro");break;
		case 2:printf("Fevereiro");break;
		case 3:printf("Marco");break;
		case 4:printf("Abril");break;
		case 5:printf("Maio");break;
		case 6:printf("Junho");break;
		case 7:printf("Julho");break;
		case 8:printf("Agosto");break;
		case 9:printf("Setembro");break;
		case 10:printf("Outubro");break;
		case 11:printf("Novembro");break;
		case 12:printf("Dezembro");break;
	}
	printf(" de %d ",da.ano);
	return;
}

/*
10.4)  Escreva uma função  incrementa_data(data &da);que incremente uma data para o dia seguinte (com odevido 
cuidado de verificar se passamos para o mês ou ano seguinte). 
*/
void incrementa_data(data &da)
{
	da.dia++;
	if (data_valida(da)) return;
	da.dia=1; da.mes++;
	if (data_valida(da)) return;
	da.mes=1; da.ano++;
}
/*
10.5)  Escreva uma função  hora pede_hora();  que peça ao utilizador uma hora e a retorne. A horadeve ser validada 
(hora entre 0 e 23, minutos e segundos entre 0 e 59). 
*/
bool hora_valida(hora h)
{
	return (h.hor>=0 && h.hor<=23 && h.min>=0 &&
		    h.min<=59 && h.seg>=0 && h.seg<=59);
}

hora pede_hora(void)
{
	hora h;
	do {
		printf("\nEntre uma Hora no formato hh:mm:ss\n");
		scanf("%d%*c%d%*c%d", &h.hor, &h.min, &h.seg);
	} while (!hora_valida(h));
	return h;	
}
/*
10.6)  Escreva uma função mostra_hora(const hora ho);que dada uma determinada hora a mostre no ecrã devidamente 
formatada (hora, minutos e segundos). 
*/
void mostra_hora(const hora ho)
{
	printf("%2.1d:%2.2d:%2.2d ",ho.hor,ho.min,ho.seg);
}

/*
10.7)  Escreva  uma  função  incrementa_hora(hora  &ho); que  incremente  uma  hora  para  o  segundo  seguinte  (com  o 
devido cuidado de verificar se passamos para o minuto, hora ou dia seguinte). 
*/
void incrementa_hora(hora &ho)
{
	ho.seg++;
	if (ho.seg>59) { 
		ho.seg=0; ho.min++;
		if (ho.min>59){
			ho.min=0; ho.hor++;
			if (ho.hor>23) ho.hor=0;
		}
	}
}

/*
10.8)  Utilizando as funções anteriores crie uma função 
relogio(data dinit, hora hinit);que recebe uma data e hora 
inicial e vai incrementando (a grande velocidade) a hora 
e data e fazendo o display no ecrã. 
*/
void relogio(data dinit, hora hinit)
{
	do {
		mostra_hora(hinit); 
		mostra_data(dinit); printf("\n");
		incrementa_hora(hinit);
		if (hinit.hor==0 && hinit.min==0 && hinit.seg==0)
			incrementa_data(dinit);
	}while(true);
}

/*
10.9)  Crie uma estrutura  pessoa que tenha o nome, 
número do bilhete de identidade,morada e data de 
nascimento de uma pessoa. Crie funções 
pessoa pede_pessoa(); e mostra_pessoa(const pessoa pe);
que permitam introduzir os valores para preencher a 
estrutura e visualizar no ecran o  seu  conteúdo. 
Utilize a estrutura anterior (data) e respetivas 
funções para tratar da introdução e visualização 
da data de nascimento. 
*/
/*
pessoa pede_pessoa(void)
{
	
}*/

/*
10.3)  Experimente  as  funções  a  cima  no  programa  
principal.  Experimente  sempre  também  as  próximas  
funções  no programa principal com exemplos apropriados. 
*/
int main()
{
	data d1=pede_data();
	mostra_data(d1);
	mostra_data2(d1);
	hora h1=pede_hora();
	mostra_hora(h1);
	relogio(d1,h1);
	return 0;
}
