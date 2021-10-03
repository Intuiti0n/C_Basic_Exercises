#include <cstdlib>
#include <iostream>
#include "JogoMedieval.h"

using namespace std;

int main()
{
    //CJogoMedieval game(15,8);  //constru��o de um jogo com 15 players e 8 monsters
    //game.show_monsters_players();
    
    CJogoMedieval game;     //constru��o de jogo vazio a ser lido de ficheiro
	game.loadGame("JMedieval.txt");
    game.show_monsters_players();
    
    int maxHealth;
	cout << "Entre a Health Max: "; 
    cin >> maxHealth;	
    CHARACTER ch = game.findWeakestMonster(maxHealth);
	cout << "A criatura mais fraca e': " << ch.tipo << " " 
         << ch.health << " " << ch.strength << " " << ch.x << " " << ch.y << endl;
    game.saveGame("jogo1.txt", ch);
    return EXIT_SUCCESS;
}
