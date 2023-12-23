#include "../lib/PokemonLeague.h"

BEGIN_GAME
    CREATE ABILITY {
        NAME: "Bite",
        ACTION: START
            POKEBALL DEFENDER _
            AFTER 2 ROUNDS DO
                POKEBALL DEFENDER ---α
            END
            DAMAGE ATTACKER 20
        END
    }
    CREATE ABILITY {
        NAME: "Solar_Power",
        ACTION: START
            FOR 5 ROUNDS DO
                IF GET_HP(ATTACKER) < 30 DO
                    HEAL ATTACKER 25
                    AFTER 2 ROUNDS DO
                        POKEBALL ATTACKER ---α
                    END
                    DAMAGE DEFENDER 22
                ELSE
                    HEAL ATTACKER 15
                ENDIF
                DAMAGE DEFENDER 8
            END
        END
    }
    CREATE ABILITY {
        NAME: "Slash",
        ACTION: START
        // Κάνει 22 damage στον αντίπαλο (DEFENDER)
        DAMAGE DEFENDER 22
        END
    }
    CREATE ABILITY {
        NAME: "Blaze",
        ACTION: START
            HEAL ATTACKER 30
        END
    }
    CREATE POKEMON {
        NAME: "Charizard",
        TYPE: "Fire",
        HP: 100
    }
    CREATE POKEMON {
        NAME: "Pikachu",
        TYPE: "Electric",
        HP: 90
    }
    DEAR "Charizard" LEARN [
        ABILITY_NAME(Bite)
        ABILITY_NAME(Solar_Power)
        ABILITY_NAME(Slash)
        ABILITY_NAME(Blaze) 
    ]
    DEAR "Pikachu" LEARN [
        ABILITY_NAME(Bite)
        ABILITY_NAME(Slash)
        ABILITY_NAME(Electric_Shock)
    ]
    DUEL
// BEGIN_GAME
//     CREATE POKEMON{
//         NAME:"Pikachu",
//         TYPE:"Electric",
//         HP:100
//     }
//     CREATE POKEMONS[
//         POKEMON{
//             NAME:"Charmander",
//             TYPE:"Fire",
//             HP:100
//         },
//         POKEMON{
//             NAME:"Squirtle",
//             TYPE:"Water",
//             HP:100
//         },
//         POKEMON{
//             NAME:"Pidgey",
//             TYPE:"Water",
//             HP:100
//         },
//         POKEMON{
//             NAME:"Rattata",
//             TYPE:"Grass",
//             HP:100
//         }
//     ]
//     CREATE ABILITY {
//         NAME: "Electric_Shock",
//         ACTION: START
//             IF GET_HP(ATTACKER) < 30 DO
//                 HEAL ATTACKER 25
//             ELSE
//                 HEAL ATTACKER 15
//             END
//         END_A
//     }
//     CREATE ABILITY {
//         NAME: "Solar_Power",
//         ACTION: START
//             POKEBALL ATTACKER ---α
//             DAMAGE DEFENDER 20
//             IF AND (GET_HP(DEFENDER) > 30, GET_HP(DEFENDER) < 70) DO
//                 DAMAGE DEFENDER 20
//             END
//             DAMAGE ATTACKER 20
//         END_A
//     }
//     CREATE ABILITIES [
//         ABILITY {
//             NAME: "Slash",
//             ACTION: START
//                 DAMAGE DEFENDER 20
//             END_A
//         },
//         ABILITY {
//             NAME: "Blaze",
//             ACTION: START
//                 DAMAGE DEFENDER 22
//             END_A
//         }
//     ]
//     DEAR "Pikachu" LEARN [
//         ABILITY_NAME(Blaze)
//         ABILITY_NAME(Slash)
//         ABILITY_NAME(Electric_Shock)
//     ];
//     DEAR "Charmander" LEARN [
//         ABILITY_NAME(Solar_Power)
//         ABILITY_NAME(Blaze)
//         ABILITY_NAME(Slash)
//     ];
//     DEAR "Squirtle" LEARN [
//         ABILITY_NAME(Solar_Power)
//         ABILITY_NAME(Blaze)
//         ABILITY_NAME(Slash)
//     ];
//     //search the pikachu pokemon
//     for(unsigned i=0;i<Pokemon::p_vec.size();i++){
//         cout<<"--------------------------------------"<<endl;
//         Pokemon::p_vec[i].print();
//     }


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