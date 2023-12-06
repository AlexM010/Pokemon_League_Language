#ifndef POKEMON_LEAGUE_H
#define POKEMON_LEAGUE_H

#include <iostream>
using namespace std;

/* Language Macros */
#define BEGIN_GAME int main(){
#define END_GAME return 0;}


/* Pokemon Type*/
typedef enum {
    Electric,
    Fire,
    Water,
    Grass
}Type;

/* Pokemon Class */
class Pokemon{
    string name;
    Type type;
    unsigned hp;
};

#endif // POKEMON_LEAGUE_H
