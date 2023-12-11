#ifndef POKEMON_LEAGUE_H
#define POKEMON_LEAGUE_H

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/* Language Macros */
#define BEGIN_GAME vector <Pokemon> Pokemon::p_vec;vector <Ability> Ability::a_vec;int main(){cout<<""
#define END_GAME ;return 0;}
#define CREATE ;
#define POKEMON Pokemon
#define POKEMONS ;Pokemon()
#define ABILITY Ability
#define ABILITIES ;Ability()


#define START []()->void{
#define END ;}




#define NAME false? ""
#define TYPE false? ""
#define HP false? 0
#define ACTION false?[]()->void{}


/* Pokemon Type*/
typedef enum {
    Undefined,
    Electric,
    Fire,
    Water,
    Grass
}Type;

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
        Pokemon operator,(Pokemon a);
        Pokemon operator[](Pokemon a);
        static vector <Pokemon> p_vec;
    private:
        string name;
        Type type;
        unsigned hp;
        vector <Pokemon> vec;
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
        Ability operator,(Ability a);
        Ability operator[](Ability a);
        Ability operator()();
        void print() const;
        string getName() const;
        vector<Ability> getVec() const;
        function<void()> getFunc() const;
        void setName(string name);
        void setFunc(function<void()> func);
        void setVec(vector<Ability> vec);
};
#endif // POKEMON_LEAGUE_H
