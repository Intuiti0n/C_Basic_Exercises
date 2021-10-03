#include "JogoMedieval.h"
     
	  
CJogoMedieval::CJogoMedieval (int nPlayers, int nMonsters)
{
//    srand (time(NULL));
    CHARACTER ch;
    for (int i=0 ; i < nPlayers+nMonsters ; i++) {
       if (i<nPlayers) ch.tipo="player"; else ch.tipo ="monster";
       ch.health = 100; 
       ch.strength= 40 + rand() % 61;
       ch.x = (double)(rand() % 11)/10; 
       ch.y = (double)(rand() % 11)/10;
       characters.push_back(ch);
    }
    activeCharacter = 0;
}

CJogoMedieval::CJogoMedieval () 
{ 
    activeCharacter = 0; 
}

void CJogoMedieval::saveGame (const char *filename, CHARACTER ch)
{
    ofstream output(filename);
	if (!output) { cerr << "Error :  Can't save File! "; return; }
	for(int i=0; i< characters.size(); i++) {
	    output << characters[i].tipo << " " << characters[i].health << " " 
               << characters[i].strength << " " << characters[i].x << " " 
               << characters[i].y << endl;
  	}
	    output << endl; 
		output << "A criatura mais fraca e' " << ch.tipo << " " << ch.health << " " 
               << ch.strength << " " << ch.x << " " 
               << ch.y << endl;
}

void CJogoMedieval::loadGame (const char *filename)
{
    ifstream input(filename);
	if (!input) { cerr << "Error :  Can't Open File! "; return; }
    CHARACTER ch;
	while (!input.eof()) {
			input >> ch.tipo >> ch.health >> ch.strength >> ch.x >> ch.y;
			characters.push_back(ch);
    }
}

CHARACTER CJogoMedieval::findWeakestMonster(int maxHealth)
{
    int pos=0,min=101, changePos=0;
	for (int i=0 ; i< characters.size() ; i++ )
	    if (characters[i].health <= maxHealth && characters[i].tipo=="monster" && 
            characters[i].strength < min) {
			    min=characters[i].strength;
			    pos=i;
			    changePos=1;
		}
	// retorna a posição do jogador mais fraco caso seja menor que o maxHealth, senão retorna a posição do jogador mais fraco do jogo.
	if (changePos==1) return characters[pos];
	else {
		for (int i=0 ; i< characters.size() ; i++ )
	    if (characters[i].tipo=="monster" && 
            characters[i].strength < min) {
			    min=characters[i].strength;
			    pos=i;
		}
		return characters[pos];
	}

}

//istream& operator>> (std::istream& is, CHARACTER& character)
//{
//	is >> character;
//	return is;
//};

void CJogoMedieval::show_monsters_players()
{
     for (int i=0; i<characters.size(); i++) {
			cout << characters[i].tipo << " " << characters[i].health << " " 
                 << characters[i].strength << " " << characters[i].x << " " 
                 << characters[i].y << endl;
		}
}
 
     
