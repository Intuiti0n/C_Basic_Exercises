#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//function overloading
void show(int val){
    cout << val<<endl;
}

void show(float val){
    cout << val<<endl;
}

void show(double val){
    cout << val<<endl;
}

void show(string val="Bom dia!\n"){
    cout << val<<endl;
}


//implicit arguments
void dois(int i=1, int b=4){

}

void tres(int i,int b=4){//argumento mais a direita tem de ter default argument se algum deles tiver

}

void copiaFicheiro1para2(){
    std::ifstream origem("nome.txt");
    if(!origem)
        cerr << "erro a abrir ficheiro nome.txt"<<endl;

    ofstream destino("nome2.txt");
    if(!destino)
        cerr << "erro a abrir ficheiro nome.txt"<<endl;

    char c;
    while((c= origem.get() != EOF))
        destino.put(c);

    if(origem.eof()|| !destino){

        cerr << "error\n"<<endl;
        return;
    }

    origem.close();//fecha o ficheiro
    destino.close();

    destino.open("nome.txt");
    destino.close();
}

void troca(int &x,int &y){//passagem por referencia, permite alterar valores dos parametros passados, ao chamar na main vai ser troca(a,b)
    int temp = x;
    x= y;
    y= temp;
}

void troca(int a,int b){
    int temp = a;
    a=b;
    b=temp;
    //valores nao sao trocados, uma copia deles é que é
}

void troca(int * p1,int *p2){//passagem por apontador, ao chamar na main vai ser troca(&a,&b)
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}


int main()
{
    cout << "Hello World!" << endl;

    //casting

    int a = static_cast<int>(12.45);
    //int b = dynamic_cast<int>(12.45);//pointer casting
    //int c = const_cast<int*>(12.45);

    int const b = 15; //nao conseguimos alterar o conteudo
    int * const c = &a;
    //c = &b; //nao podemos alterar o valor para o qual esta a apontar mas podemos mdofiicar o conteudo
    *c = b;

    const int * ptr = c;
    ptr = &b; //podemos alterar o sitio para o qual esta a apontar mas nao podemos modificar o seu valor

    cout.put('a');//output de 1 char
    cin.eof();//testa se chegou ao fim da stream de entrada
    cin.get();//le um char, pode retornar EOF se chegar ao fim da stream
    cerr << "standard error" <<endl;

    string linha;
    getline(cin,linha);

    int pos=linha.find("palavra");
    linha.substr(pos);

    printf("%s\n",linha.c_str());



    return 0;
}
