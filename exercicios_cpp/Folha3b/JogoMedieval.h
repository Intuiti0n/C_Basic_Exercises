#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct CHARACTER {
  public:
    string tipo; // “monster” or “player”
    int health;
    int strength;
    double x;   
    double y;
    bool operator==(CHARACTER c2) {
    	return tipo==c2.tipo && health==c2.health && strength==c2.strength;
    }
   
  
};

class CJogoMedieval {
  private:
    vector <CHARACTER> characters;
    int activeCharacter;
  public:
    CJogoMedieval (int nPlayers, int nMonsters);
    CJogoMedieval ();
    void saveGame (const char *filename, CHARACTER ch); 
    void loadGame (const char *filename);
    CHARACTER findWeakestMonster(int maxHealth);
    void show_monsters_players();
};
