#include "../lib/PokemonLeague.h"

BEGIN_GAME
    CREATE POKEMON{
        NAME:"Pikachu",
        TYPE:"Electric",
        HP:100
    }
    CREATE POKEMONS[
        POKEMON{
            NAME:"Charmander",
            TYPE:"Fire",
            HP:100
        },
        POKEMON{
            NAME:"Squirtle",
            TYPE:"Water",
            HP:100
        },
        POKEMON{
            NAME:"Pidgey",
            TYPE:"Water",
            HP:100
        },
        POKEMON{
            NAME:"Rattata",
            TYPE:"Grass",
            HP:100
        }
    ]
    CREATE ABILITY {
        NAME: "Electric_Shock",
        ACTION: START
            IF GET_HP(ATTACKER) < 30 DO
                HEAL ATTACKER 25
            ELSE
                HEAL ATTACKER 15
            END
        END
    }
    CREATE ABILITY {
        NAME: "Solar_Power",
        ACTION: START
            POKEBALL ATTACKER ---α
            DAMAGE DEFENDER 20
        END
    }
    CREATE ABILITIES [
        ABILITY {
            NAME: "Electric_Shock",
            ACTION: START
                IF GET_HP(ATTACKER) < 30 DO
                    HEAL ATTACKER 25
                ELSE
                    HEAL ATTACKER 15
                END
            END
        },
        ABILITY {
            NAME: "Blaze",
            ACTION: START
                DAMAGE DEFENDER 22
            END
        }
    ]
    // CREATE ABILITY {
    //     NAME: "ability_name",
    //     ACTION: START
    //         DAMAGE ATTACKER 20
    //         POKEBALL DEFENDER ---a
    //     END
    // }
    // CREATE ABILITIES[
    //     ABILITY {
    //     NAME: "ability_name2",
    //     ACTION: START 
    //         cout<<"Hi alex\n"
    //     END
    //     },
    //     ABILITY {
    //     NAME: "ability_name3",
    //     ACTION: START
    //         cout<<"Hi jimmy\n"
    //     END
    //     }
    // ]

    // ;cout<<Pokemon::p_vec.size()<<endl;
    // for (unsigned i = 0; i < Pokemon::p_vec.size(); i++) {
    //     Pokemon::p_vec[i].print();
    // }
    // cout<<"\n";
    // cout<<Ability::a_vec.size()<<endl;
    // for (unsigned i = 0; i < Ability::a_vec.size(); i++) {
    //     Ability::a_vec[i].print();
    //     (Ability::a_vec[i].getFunc())();
    // }
END_GAME