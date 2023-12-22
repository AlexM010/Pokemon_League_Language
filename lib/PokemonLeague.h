#ifndef POKEMON_LEAGUE_H
#define POKEMON_LEAGUE_H

#include "PokemonMacros.h"
/* Pokemon Type Enumerator*/
typedef enum {
    Undefined,
    Electric,
    Fire,
    Water,
    Grass
}Type;

class Pokemon;
class Ability;
class Player;
class Round;
class Dummy;
class Player{
    private:
        string name;
        vector <Pokemon> p_vec;
        Pokemon* currentPokemon;
        Player* opponent;
    public:
        Player()=default;
        Player(string _name);
        string getName() const;
        vector <Pokemon> getP_vec() const;
        Player* getOpponent() const;
        void setName(string name);
        void setP_vec(vector <Pokemon> p_vec);
        void setOpponent(Player* opponent);
        void addPokemon(Pokemon p);
        void givePokemon(string p);
        void setCurrentPokemon(Pokemon* currentPokemon);
        Pokemon* getCurrentPokemon() const;
};
class Round{
    private:
        function<void()> player1;
        function<void()> player2;
    public:
        Round()=default;
        Round(function<void()> _player1, function<void()> _player2);
        void setPlayer1(function<void()> player1);
        void setPlayer2(function<void()> player2);
        function<void()> getPlayer1() const;
        function<void()> getPlayer2() const;
        void play(int);
};
class Pokemon{
    public:
        Pokemon();
        Pokemon(string _name, string _type, unsigned _hp);
        string getName() const;
        Type getType() const;
        vector <Pokemon> getVec() const;
        unsigned getHp() const;
        void setName(string name);
        void setType(Type type);
        void setHp(unsigned hp);
        void print() const;
        Pokemon operator,(Pokemon p);
        Pokemon operator[](Pokemon p);
        static vector <Pokemon> p_vec;
        void setOwner(Player* owner);
        Player* getOwner() const;
        Pokemon& operator=(Dummy d);
        void addAbility(Ability a);
        vector <Ability> getAbilities() const;
    private:
        string name;
        Type type;
        unsigned hp;
        vector <Pokemon> vec;
        Player* owner;
        vector <Ability> abilities;
};

Type StringToPokemonType(const std::string& typeStr);
std::string PokemonTypeToString(Type type);
class Ability{
    private:
        string name;
        function<void()>func;
        vector<Ability> vec;
    public:
        static vector <Ability> a_vec;
        Ability()=default;
        Ability(string _name, function<void()>_func);
        Ability operator,(Ability A);
        Ability operator[](Ability A);
        Ability operator()();
        void print() const;
        string getName() const;
        vector<Ability> getVec() const;
        function<void()> getFunc() const;
        void setName(string name);
        void setFunc(function<void()> func);
        void setVec(vector<Ability> vec);
};
class Dummy {
private:
	int i;
public:
	Dummy(int i = 0);
    Dummy(string str);
	int getI();
    Dummy& operator-(Dummy x);
	Dummy& operator--();
    Dummy& operator-();
    Dummy& operator[](Dummy);
    Dummy& operator[](int);
    Dummy& operator,(Dummy);
};
//comment above functions

void damage(Pokemon,int);
void heal(Pokemon,int);
void pokeball(Pokemon p, Dummy d);
int getHp(Pokemon p1,Pokemon p2);
string get_Type(Pokemon p1,Pokemon p2);
string getName(Pokemon p1,Pokemon p2);
Pokemon* search_pokemon(string str);
#endif // POKEMON_LEAGUE_H
