#include <cstdlib>
#include <iostream>
#include "Zoo.h"

using namespace std;

int main()
{
    CJardimZoologico zoo1, zoo2;
    
    ifstream fich("animais.txt");
    zoo1.loadAnimals(fich);
    
    ifstream fich2("animais2.txt");
    zoo2.loadAnimals(fich2);
    
    cout << zoo1 << zoo2;
    
    if (zoo1.animalJovem("Margarida")) cout << "Margarida e' Jovem" << endl;
    if (zoo1.animalJovem("Mikado")) cout << "Mikado e' Jovem" << endl;
    
    if (zoo2>zoo1) cout << "Zoo2 Maior!" << endl;
    else cout << "Zoo1 Maior!" << endl;
    
}
