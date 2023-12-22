//header guard
#ifndef POKEMON_MACROS_H
#define POKEMON_MACROS_H
//include the header file for Pokemon class
#include "PokemonLeague.h"
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/* Language Macros */

/* BEGIN_GAME : Begining of Program Macro with global object definitions*/
/* α : is a dummy object that is used for POKEBALL macro (out of pokeball) - (--- : are 2 operator overloadings; prefix decrement and unary minus)*/
/* _ : is a dummy object that is used for POKEBALL macro (back to pokeball)*/
/* turn : is an int used for ATTACKER/DEFENDER macros to specify which Pokemon object should be used */
/* _round : is an int used for keeping track of the current round */
/* player1 : is a Player object for the first player */
/* player2 : is a Player object for the second player */
/* Pokemon::p_vec : is a static vector of Pokemon objects used for keeping track of all Pokemon objects */
/* Ability::a_vec : is a static vector of Ability objects used for keeping track of all Ability objects */
/* rounds : is a vector of Round objects used for keeping the code that has to be executed each round
   because actions have code for multiple rounds (e.g. for-loops (FOR macro), AFTER macro)
*/
#define BEGIN_GAME \
    Dummy α(1);\
    Dummy _(0);\
    int turn=1;\
    unsigned _round=0;\
    Player player1("Player 1");\
    Player player2("Player 2");\
    vector <Pokemon> Pokemon::p_vec;\
    vector <Ability> Ability::a_vec;\
    Pokemon* learn; \
    vector <Round> rounds;\
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
#define START []()->void{ \
    _round++; \
    if(rounds.size()<_round){\
        rounds.push_back(Round()); \
    } \
    Dummy(
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

/* Macros for learning a specific pokemon some abilities*/
#define DEAR ;\
    learn=search_pokemon(
#define LEARN );\
    Dummy()
#define ABILITY_NAME(x) -0],Dummy( #x )[1


/* Macro for printing */
#define SHOW cout<<

#endif // POKEMON_MACROS_H
