#ifndef POKEMON_LEAGUE_H
#define POKEMON_LEAGUE_H

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/* Language Macros */

/* Begining of Program Macro with global object definitions*/
#define BEGIN_GAME \
    Dummy α(1);\
    Dummy _(0);\
    int k=0;\
    int turn=1;\
    int rounds=0;\
    Player player1("Player 1");\
    Player player2("Player 2");\
    vector <Pokemon> Pokemon::p_vec;\
    vector <Ability> Ability::a_vec;\
    int main(){\
        turn=1\

/* End of Program Macro */
#define END_GAME ;\
        return 0;\
    }

/* Macro for declaring objects - it doesnt do anything just for terminating lines with semicolon */
#define CREATE ;

/* LANGUAGE'S OBJECT DECLARATION AND ITS PROPERTIES MACROS */

/* Pokemon Object */
#define POKEMON Pokemon
/* Pokemon Object used for its operator overload that adds Pokemon Objects into static vector "p_vec" */
#define POKEMONS ;Pokemon()
/* Ability Object */
#define ABILITY Ability
/* Ability Object used for its operator overload that adds Ability Objects into static vector "a_vec" */
#define ABILITIES ;Ability()
/* Action Declaration - used to reduce to Start Action Macro */
#define ACTION false?[]()->void{}
/* Starting Action Macro used for declaring a lambda function which is a function used as action in an Ability */
#define START []()->void{Dummy(
/* Ending Action Macro used for terminating the lambda function */
#define END_A );}
/* Macro for naming a Pokemon Object - reducing to a string given */
#define NAME false? ""
/* Macro for giving a type to a Pokemon Object - reducing to a string given */
#define TYPE false? ""
/* Macro for setting the health points (hp) to a Pokemon Object - reducing to an integer given */
#define HP false? 0
/* Macro for returning the attacking Pokemon Object based on the Player playing */
#define ATTACKER *(turn==1?player1.getCurrentPokemon():player2.getCurrentPokemon()),
/* Macro for returning the defending Pokemon Object based on the Player playing */
#define DEFENDER *(turn==2?player1.getCurrentPokemon():player2.getCurrentPokemon()),
/* Macro for dealing damage to a Pokemon Object */
#define DAMAGE );damage(
/* Macro for healing a Pokemon Object */
#define HEAL  );heal(
/* Macro for adding a Pokemon Object to a Player's vector of Pokemon Objects (Pokeball) */
#define POKEBALL );pokeball(
/* Macro for returning the health points (hp) of a Pokemon Object */
#define GET_HP(x)  getHp(x Pokemon())
/* Macro for returning the type of a Pokemon Object */
#define GET_TYPE(x)  get_Type(x Pokemon())
/* Macro for returning the name of a Pokemon Object */
#define GET_NAME(x)  getName(x Pokemon())
/* Macro for returning if the Pokemon is in the Pokeball */
#define IS_IN_POKEBALL(x)   (x Pokemon()==NULL)


/* If Macro */
#define IF );if(
/* Else If Macro */
#define ELSE_IF );}else if(
/* Else Macro */
#define ELSE );}else{Dummy(
/* End of condition of an 'if' statement*/
#define DO ){Dummy(
/* End Macro */
#define END );}Dummy(


/* Logical Operation Macros */
#define AND(x,y)    (x and y)
#define OR(x,y)     (x or y)
#define NOT(x)      (not x)


/* Macro for printing */
#define SHOW cout<<



/* Pokemon Type Enumerator*/
typedef enum {
    Undefined,
    Electric,
    Fire,
    Water,
    Grass
}Type;

class Pokemon;

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
    private:
        string name;
        Type type;
        unsigned hp;
        vector <Pokemon> vec;
        Player* owner;
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
	Dummy(int);
	int getI();
    Dummy& operator-(Dummy x);
	Dummy& operator--();
    Dummy& operator-();
};
//comment above functions

void damage(Pokemon,int);
void heal(Pokemon,int);
void pokeball(Pokemon p, Dummy d);
int getHp(Pokemon p1,Pokemon p2);
string get_Type(Pokemon p1,Pokemon p2);
string getName(Pokemon p1,Pokemon p2);
#endif // POKEMON_LEAGUE_H
