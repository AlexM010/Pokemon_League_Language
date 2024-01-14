#include "../lib/PokemonLeague.h"

BEGIN_GAME
    CREATE ABILITY {
        NAME: "Electric_Shock",
        ACTION: START
            FOR 1 ROUNDS DO
                SHOW "MY OPPONENTS HP IS"<< GET_HP(DEFENDER)<<endl
            END
            DAMAGE DEFENDER 10
        END
    }
    CREATE ABILITY {
        NAME: "Bite",
        ACTION: START
            IF GET_NAME(ATTACKER) == "Pikachu" DO
                SHOW "I AM PICKACHU "<< "AND MY TYPE IS "<<GET_TYPE(ATTACKER)<<" MY HP IS" << GET_HP(ATTACKER)<<endl
            ENDIF

            IF AND(NOT( IS_IN_POKEBALL(DEFENDER)),GET_NAME(DEFENDER)=="Charizard")  DO
                SHOW "CHARIZARD NOT IN POKEBALL"<<endl
            ENDIF

            DAMAGE DEFENDER 20
        END
    }
    CREATE ABILITY {
        NAME: "Solar_Power",
        ACTION: START
            POKEBALL DEFENDER _
        END
    }
    CREATE ABILITY {
        NAME: "Slash",
        ACTION: START
            HEAL DEFENDER 22
        END
    }
    CREATE ABILITY {
        NAME: "Blaze",
        ACTION: START
            POKEBALL DEFENDER _
            AFTER 3 ROUNDS DO
                POKEBALL DEFENDER ---α
                DAMAGE ATTACKER 10
            END
        END
    }


    CREATE POKEMON {
        NAME: "Bulbasaur",
        TYPE: "Grass",
        HP: 100,
    }
    CREATE POKEMON {
        NAME: "Squirtle",
        TYPE: "Water",
        HP: 120,
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
        ABILITY_NAME(Blaze)
    ]
    DEAR "Squirtle" LEARN [
        ABILITY_NAME(Bite)
        ABILITY_NAME(Slash)
        ABILITY_NAME(Electric_Shock)
        ABILITY_NAME(Blaze)
    ]
    DEAR "Bulbasaur" LEARN [
        ABILITY_NAME(Bite)
        ABILITY_NAME(Slash)
        ABILITY_NAME(Electric_Shock)
        ABILITY_NAME(Blaze)
    ]
    DUEL
END_GAME
