#ifndef POKEMON_LEAGUE_H
#define POKEMON_LEAGUE_H

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/* Language Macros */
#define BEGIN_GAME Dummy α(1);Dummy _(0);int k=0;int turn=1;Player player1("Player 1");Player player2("Player 2");vector <Pokemon> Pokemon::p_vec;vector <Ability> Ability::a_vec;int main(){turn=1
#define END_GAME ;return 0;}
#define CREATE ;
#define POKEMON Pokemon
#define POKEMONS ;Pokemon()
#define ABILITY Ability
#define ABILITIES ;Ability()


#define START []()->void{Dummy(
#define END );}

#define NAME false? ""
#define TYPE false? ""
#define HP false? 0
#define ACTION false?[]()->void{}



#define ATTACKER *(turn==1?player1.getCurrentPokemon():player2.getCurrentPokemon()),
#define DEFENDER *(turn==2?player1.getCurrentPokemon():player2.getCurrentPokemon()),


#define DAMAGE );damage(
#define HEAL  );heal(
#define POKEBALL );pokeball(
#define GET_HP(x)  getHp(x Pokemon())
#define GET_TYPE(x)  get_Type(x Pokemon())
#define GET_NAME(x)  getName(x Pokemon())
#define IS_IN_POKEBALL(x)   (x Pokemon()==NULL)



#define IF );if(
#define ELSE_IF );}else if(
#define ELSE );}else{Dummy(
#define DO ){Dummy(
#define AND(x,y)    (x and y)
#define OR(x,y)     (x or y)
#define NOT(x)      (not x)
#define SHOW cout<<
#define ENDIF );}



/* Pokemon Type*/
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

/* Pokemon Class */

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
	Dummy(int i = 0)
	{
		this->i = i;
	}
	int getI(){
	    return i;
	}
    Dummy& operator-(Dummy x)
	{
		x.getI();
		return *this;
	}
	Dummy& operator--()
	{
		return *this;
	}
	void display()
	{
		cout << "i = " << i << endl;
	}
    Dummy& operator-()
	{
		return *this;
	}

};
void damage(Pokemon,int);
void heal(Pokemon,int);
void pokeball(Pokemon p, Dummy d);
int getHp(Pokemon p1,Pokemon p2);
string get_Type(Pokemon p1,Pokemon p2);
string getName(Pokemon p1,Pokemon p2);
#endif // POKEMON_LEAGUE_H
