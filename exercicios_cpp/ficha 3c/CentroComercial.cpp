#include "CentroComercial.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CCentroComercial::ler_lojas (const char * filename)
{
	ifstream input(filename);
	string line;
	if (!input) { cerr << "Error :  Can't Open File! "; return; }
    LOJA lj;
    while (!input.eof()) 
	{
		getline (input,lj.nome);
		getline (input,lj.tipo);
		getline (input,line);
		lj.renda = atoi(line.c_str());
		lojas.push_back(lj);
	}	
}

//void CCentroComercial::imprimir_lojas(ostream &output, string tipo)
//{
//	for (int i=0 ; i< lojas.size() ; i++ )
//	{
// 		if (lojas[i].tipo == tipo)
//		{
//			output << "Nome:"  << lojas[i].nome << endl;
//			output << "Tipo:"  << lojas[i].tipo << endl;
//			output << "Renda:"  << lojas[i].renda << endl <<  endl;
//		}
//	}	
//}

void CCentroComercial::imprimir_lojas(ostream &output, string tipo)
{
      for (int i=0; i<lojas.size(); i++) {
          if (lojas[i].tipo==tipo)
            output << lojas[i].nome << "  " << lojas[i].tipo << " "
                 << lojas[i].renda << endl;  
     }    
}


void CCentroComercial::imprimir_lojas (ostream &output)
{
	for (int i=0 ; i< lojas.size() ; i++ )
	{
	output << "Loja:"  << i+1 << endl;
	output << "Nome:"  << lojas[i].nome << endl;
	output << "Tipo:"  << lojas[i].tipo << endl;
	output << "Renda:"  << lojas[i].renda << endl <<  endl;
	}
}

void CCentroComercial::ordenarLojas ()
{  		
	int i, j, first;
	LOJA temp;
    int numLength = lojas.size( );
    for (i= numLength - 1; i > 0; i--)
    {
		first = 0;                 // initialize to subscript of first element
        for (j=1; j<=i; j++)   // locate smallest between positions 1 and i.
        {
            if (lojas[j].renda < lojas[first].renda)
            first = j;
        }
        temp = lojas[first];   // Swap smallest found with element in position i.
        lojas[first] = lojas[i];
        lojas[i] = temp;
    }
}
  
void CCentroComercial::alterarRenda(int a , int b)
{
  	--a;
  	if (a < lojas.size())
	  {
    	int rendaanterior = lojas[a].renda;
  		lojas[a].renda = b;
  		cout << "Renda da Loja "  << lojas[a].nome  << " atualizada de " << rendaanterior << " para " << lojas[a].renda << endl;
  	  }
  	else cout << "Essa loja não existe neste centro comercial" << endl;
}
   
void CCentroComercial::gravarLojas (const char *filename, CCentroComercial LJ)
{
    ofstream output(filename);
	if (!output) { cerr << "Error :  Can't save File! "; return; }
	for(int i=0; i< lojas.size(); i++) {
	    output << lojas[i].nome<<  endl;
		output << lojas[i].tipo<<  endl;
		if (i < lojas.size()- 1)
		output << lojas[i].renda<<  endl;
		else
        output << lojas[i].renda;
  	}
}


//void CCentroComercial::show_lista()
//{
//     for (int i=0; i<lojas.size(); i++) {
//			cout << lojas[i].nome << " "<< lojas[i].tipo << " "<< lojas[i].renda << " "<< endl;
//		}
//}

