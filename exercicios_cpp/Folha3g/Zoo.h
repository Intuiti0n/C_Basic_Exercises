#include<vector>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class ANIMAL {
  public:
    string categoria; // urso, girafa, etc
    string nome; 
    string veterinario;
    int idade; // anos
};

class CJardimZoologico {
  private:
    vector<ANIMAL> animais;
  public:
    bool animalJovem(const char *nome);
    vector<ANIMAL> animaisJovens();
    void loadAnimals(istream& is);
    vector<string> veterinarioComMaisTrabalho();
    friend ostream &operator<<( ostream &, const CJardimZoologico&);
    bool operator> (CJardimZoologico& zoo2);
};
