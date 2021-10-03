#include "Zoo.h"
   
bool CJardimZoologico::animalJovem(const char *nome)
{
     for(int i=0; i<animais.size(); i++)
         if (animais[i].nome==nome) return animais[i].idade <=5;
     return false;
}

vector<ANIMAL> CJardimZoologico::animaisJovens()
{
    vector<ANIMAL> anjov;
	for(int i=0; i<animais.size(); i++)
         if (animais[i].idade <=5) anjov.push_back(animais[i]);
	return anjov;
}

void CJardimZoologico::loadAnimals(istream& is)
{
     ANIMAL an;
     string lixo;
     while(!is.eof())
     {
          getline(is,an.categoria);
          getline(is,an.nome);
          getline(is,an.veterinario);
          is >> an.idade; getline(is,lixo); 
          animais.push_back(an);
          //cout << an.nome << "  " << an.idade << endl; //Teste/Debug         
     }  
}

vector<string> CJardimZoologico::veterinarioComMaisTrabalho()
{
/*
    vector<string> vets;
	vector<int> an_vet;
	for(int i=0; i<animais.size(); i++)
		if (!existe(animais[i].veterinario,vets) {
			vets.push_back(animais[i].veterinario);
			int num=1;
			for(int j=i+1; j<animais.size(); j++)
				if (animais[i].veterinario == animais[j].veterinario) num++;
			an_vet.push_back(num);
*/
}

bool CJardimZoologico::operator>(CJardimZoologico& zoo2)
{
     int soma1=0, soma2=0;
     for(int i=0; i<animais.size(); i++) 
         soma1 += animais[i].idade;          
     for(int i=0; i<zoo2.animais.size(); i++)
         soma2 += zoo2.animais[i].idade;
     cout << "Zoo: " << soma1 << " Zoo2: " << soma2 << endl;       
     return soma1<soma2;
}

ostream &operator<<( ostream &os, const CJardimZoologico& zoo)
{
       cout << "Jardim Zoologico!" << endl;
       for(int i=0; i<zoo.animais.size(); i++) {
          cout << zoo.animais[i].nome << " e' um " 
               << zoo.animais[i].categoria 
               << " e tem " << zoo.animais[i].idade << " anos! " << endl
               << "Veterinario: " << zoo.animais[i].veterinario << endl
               << "-----------------" << endl;
       }
       cout << "------FIM DO ZOO----" << endl;
       return os;
}
