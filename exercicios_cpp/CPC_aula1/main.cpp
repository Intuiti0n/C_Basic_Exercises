#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

/*
 * Escreva uma função int troco(int vNota, int aPagar) que dado um determinado valor inteiro a
pagar igual ou inferior a 50 Eur (aPagar) e o valor da nota entregue para o pagar (vNota) que pode ser (50, 20,
10 ou 5 Eur) calcule o troco a entregar (exclusivamente em notas de 20 e 5 Eur e moedas de 1 Eur) e o imprima
no écran. A função deve ainda imprimir e retornar o número de notas/moedas necessário para o troco. No caso
de a nota entregue ou o valor a pagar serem inválidos deve imprimir inválido e retornar 0.
 * */
int troco(int vNota, int aPagar){
    int troco = vNota - aPagar;
    int vTroco[3]={0,0,0};
    if(aPagar > 50 || !(vNota == 50||vNota == 20 || vNota == 10 || vNota == 5)){
        cout << "Invalido!"<<endl;

    }
    else {
        while(troco != 0){
            if(troco >= 20){
                troco -=20;
                vTroco[0]+=1;
            }
            else if(troco >= 5){
                troco -= 5;
                vTroco[1]+=1;
            }
            else if(troco >= 1){
                troco -=1;
                vTroco[2]+=1;
            }
        }

    }
    for(int j=0;j<3;j++)
        for(int i=0;i<vTroco[j];i++){
            if(j==0)
                cout << "20 ";
            else if(j==1)
                cout << "5 ";
            else if(j==2)
                cout << "1 ";
        }
    if(!troco)
        cout <<": "<< vTroco[0]+vTroco[1]+vTroco[2] << " notas/moedas"<<endl;
    return troco;
}

/*
Construa a função void num7(int dim) que dada a dimensão de um número sete dim desenhe números 7
compostos por caracteres ‘X’
*/
void nch(int n, char c) {
    for(int i=0; i<n; i++) printf("%c", c);
}

void num7(int dim){
    nch(dim,'X');
    printf("\n");
    for(int i=0;i<dim;i++){
        nch(dim-i-1,' ');
        nch(1,'X');
        printf("\n");
    }
}
/*Escreva uma função double frequenciasPal(char nome[20]) que receba uma string indicando o
nome de um ficheiro e imprima no écran uma tabela indicando a frequência de cada comprimento das palavra. A
função deve também escrever no écran o comprimento médio das palavras encontradas no ficheiro e retorna-lo.
Suponha que o tamanho máximo das palavras é 10.*/
double frequenciasPal(string nome){
    istringstream iss(nome);
    string token;
    int n=0;
    int soma=0;
    while(getline(iss,token,' ')){
        n++;
        soma+=token.size();
        cout << token.size()<<endl;
    }

    cout << "Media: "<< (float) soma / n<<endl;


}

struct tempo { short int hora, minu, segu; };
/*
Escreva uma função void incr100(tempo &t) que dado um determinado tempo, o incremente em
100 segundos, alterando convenientemente os respetivos campos e o mostre no ecrã devidamente
formatado (hora, minutos e segundos). Por exemplo, supondo t = {10, 59, 12} a chamada de
incr100(t) resulta em t={11, 00, 52} e imprime no écran “11 horas, 00 minutos e 50 segundos”.
*/
void incr100(tempo &t){
    t.segu +=100;
    if(t.segu > 59){
            t.minu++;
            t.segu -=60;
            if(t.segu > 59){
                t.minu++;
                t.segu -=60;
            }
    }
    if(t.minu > 59){
        t.hora++;
        t.minu = 0;
    }
    if(t.hora > 23){
        t.hora = 0;
    }

    cout << t.hora << " horas, "<< t.minu << " minutos e " << t.segu << " segundos"<<endl;
}

/*
b) Escreva o programa pedido, de forma a que o número de vezes que a frase deve surgir no ecrã seja
indicado na linha de comando.
*/
void nHelloWorld(int n){
    for(int i=0;i<n;i++)
        cout <<"Hello World!"<<endl;
}

/*
c) Escreva o programa pedido, mas agora de forma a que o número de vezes que a frase deve surgir
no ecrã seja recolhido da consola.
*/
void asknHelloWorld(void){
    int n=0;
    cout << "Quantas queres?"<<endl;
    cin >> n;
    for(int i=0;i<n;i++)
        cout <<"Hello World!"<<endl;
}

/*
d) Escreva o programa pedido mas, desta vez, uma frase qualquer, recolhida da consola, é que é
mostrada no ecrã tantas vezes quantas o número indicado na linha de comando.
*/
void askLine(void){
    string line;
    int n;
    cout << "que frase queres?"<<endl;
    getline(cin,line);
    cout << "Quantas queres?"<<endl;
    cin >> n;
    for(int i=0;i<n;i++)
        cout <<line<<endl;
}

/*
Pretende-se escrever um programa em C que calcule a hipotenusa de um triângulo rectângulo. Para tal
efeito, os valores das dimensões dos catetos deverão ser obtidos do utilizador de diferentes maneiras.
a) Obtenha as dimensões dos catetos da linha de comando, e apresente na consola, o valor da
hipotenusa (note que as medidas de qualquer um dos lados do triângulo poderão ser valores em
vírgula flutuante).
*/
void hipotenusa_ask(void){
    float c1,c2,hip;
    cout << "cat1"<<endl;
    cin >> c1;
    cout << "cat2"<<endl;
    cin >> c2;

    hip = (float)sqrt((double)c1*c1+c2*c2);

    cout << "hipotenusa: "<< hip <<endl;

}
int main()
{
    //exercicio 1
    /*
a) Escreva o programa base "Hello World!"
*/
    cout << "Hello World!" << endl;

//    troco(38,15);
//    troco(50,25);
//    troco(50,20);
//    troco(20,4);
//    troco(5,1);

    //num7(5);

    frequenciasPal("ola amigo hello ma friend");

    tempo test;
    test.hora = 10;
    test.minu = 59;
    test.segu = 12;
    incr100(test);
    return 0;
}
