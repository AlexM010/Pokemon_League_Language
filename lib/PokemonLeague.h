#ifndef POKEMON_LEAGUE_H
#define POKEMON_LEAGUE_H

#include <iostream>
#include <vector>

using namespace std;

/* Language Macros */
#define BEGIN_GAME int main(){int i
#define END_GAME ;return 0;}
#define CREATE ;new
#define POKEMON Pokemon
#define POKEMONS int;Pokemon()



#define NAME false? ""
#define TYPE false? ""
#define HP false? 0

/*
#define NAME "NAME"
#define TYPE "TYPE"
#define HP "HP"
*/
/* Pokemon Type*/
typedef enum {
    Electric,
    Fire,
    Water,
    Grass
}Type;

class Pokemon{
    public:
        Pokemon()=default;
        Pokemon(string _name, string _type, unsigned _hp);
        string getName() const;
        Type getType() const;
        vector <Pokemon> getVec() const;
        unsigned getHp() const;
        void setName(string name);
        void setType(Type type);
        void setHp(unsigned hp);
        void print() const;
        Pokemon operator,(Pokemon a);
        Pokemon operator[](Pokemon a);
    private:
        string name;
        Type type;
        unsigned hp;
        vector <Pokemon> vec;
};

/* Pokemon Class */

Type StringToPokemonType(const std::string& typeStr);
std::string PokemonTypeToString(Type type);
#endif // POKEMON_LEAGUE_H
