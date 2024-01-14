#include "PokemonLeague.h"


extern Player player1;
extern Player player2;
extern int turn;
extern unsigned _round;
extern vector<Round> RoundsF;
extern vector<Round> RoundsA;
extern vector<Pokemon> p_vec;
extern vector<Ability> a_vec;
extern Pokemon* learn;


void duel() {
    // clear the screen
    int i;
    i = system("clear");
    
    
    // aiding variables
    int winner = 0;
    string tmp;
    int healing = 0;

    
    // print Announcement
    cout << "--------------------------- Pokemon the game ---------------------------" << endl;

    // Initialize the players 
    player1.setOpponent(&player2);
    player2.setOpponent(&player1);






    // Players choose their pokemons
    for (i = 0; i < 2; i++) {
            cout <<endl<<((i == 0) ? player1.getName() : player2.getName()) << " select Pokemon: " << endl;
            cout << "---------------------------" << endl;
            // print p_vec
            for (unsigned j = 0; j < Pokemon::p_vec.size(); j++) {
                cout << j + 1 << ". " << Pokemon::p_vec[j].getName() << endl;
            }
            cout << "---------------------------" << endl;

            // get input 
            cin >> tmp;

            
            try {
                if (i == 0) {
                    player1.setP(*search_pokemon(tmp));
                    player1.setCurrentPokemon(player1.getP());
                } else {
                    player2.setP(*search_pokemon(tmp));
                    player2.setCurrentPokemon(player2.getP());
                }
            } catch (std::invalid_argument& e) {
                cout << e.what() << endl;
                i--;
            }

    }

    // Here the pokemons start to fight
    while (winner == 0) {
        _round++;
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Round " << _round << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        if(RoundsF.size()>0&&player1.getCurrentPokemon()!=NULL){
            cout << "------------------------------------" << endl;
            cout<<"Player 1 did:\n";
            RoundsF[0].play(1);
            cout << "------------------------------------" << endl;
        }
        if(RoundsA.size()>0&&player1.getCurrentPokemon()!=NULL){
            cout << "------------------------------------" << endl;
            cout<<"Player 1 did:\n";
            RoundsA[0].play(1);
            cout << "------------------------------------" << endl;
        }
    
        if(RoundsF.size()>0&&player2.getCurrentPokemon()!=NULL){
            cout << "------------------------------------" << endl;
            cout<<"Player 2 did:\n";
            RoundsF[0].play(2);
            RoundsF.erase(RoundsF.begin());
            cout << "------------------------------------" << endl;
        }
        if(RoundsA.size()>0&&player2.getCurrentPokemon()!=NULL){
            cout << "------------------------------------" << endl;
            cout<<"Player 2 did:\n";
            RoundsA[0].play(2);
            RoundsA.erase(RoundsA.begin());
            cout << "------------------------------------" << endl;
        }
        for (i = 0 ; i < 2; i++) {
            if (i == 0) {
                if (player1.getCurrentPokemon() == NULL) {
                    cout << player1.getName() << " has no pokemon to fight with." << endl;
                    turn == 1 ? turn = 2 : turn = 1;
                    if(RoundsF.size()>0){
                        RoundsF.push_back(Round([](){},[](){}));
                        for(unsigned k=0;k<RoundsF.size()-1;k++){
                            RoundsF[k+1].setPlayer1(RoundsF[k].getPlayer1());
                        }
                    }
                    if(RoundsA.size()>0){
                        RoundsA.push_back(Round([](){},[](){}));
                        for(unsigned k=0;k<RoundsA.size()-1;k++){
                            RoundsA[k+1].setPlayer1(RoundsA[k].getPlayer1());
                        }
                    }
                    continue;
                }
                if (_round % 2 == 0 && player1.getCurrentPokemon()->getType() == Grass) {
                    //player1.getCurrentPokemon()->setHp(player1.getCurrentPokemon()->getHp() + (int)(0.05 * (double)player1.getCurrentPokemon()->getMaxHp())); 
                    healing = (int)(0.05 * (double)player1.getCurrentPokemon()->getMaxHp());
                    int tmp = player1.getCurrentPokemon()->getHp() + healing >= player1.getCurrentPokemon()->getMaxHp() ? player1.getCurrentPokemon()->getMaxHp() : player1.getCurrentPokemon()->getHp() + healing;
                    player1.getCurrentPokemon()->setHp(tmp); 
                    cout << player1.getName() << "(" << player1.getCurrentPokemon()->getName() << ") healed for " << healing << "." << " Current hp: " << player1.getCurrentPokemon()->getHp() << endl;
                }
            } else {
                if (player2.getCurrentPokemon() == NULL) {
                    cout << player2.getName() << " has no pokemon to fight with." << endl;
                    turn == 1 ? turn = 2 : turn = 1;
                    if(RoundsF.size()>0){
                        RoundsF.push_back(Round());
                        for(unsigned k=0;k<RoundsF.size()-1;k++){
                            RoundsF[k+1].setPlayer2(RoundsF[k].getPlayer2());
                        }
                        RoundsF.erase(RoundsF.begin());
                    }
                    if(RoundsA.size()>0){
                        RoundsA.push_back(Round());
                        for(unsigned k=0;k<RoundsA.size()-1;k++){
                            RoundsA[k+1].setPlayer2(RoundsA[k].getPlayer2());
                        }
                        RoundsA.erase(RoundsA.begin());
                    }
                    continue;
                }      
                            
                if (_round % 2 == 0 && player2.getCurrentPokemon()->getType() == Grass) {
                    //heal(player2.getCurrentPokemon(), player2.getCurrentPokemon()->getHp() + (int)(0.05 * (double)player2.getCurrentPokemon()->getMaxHp());
                    healing = (int)(0.05 * (double)player2.getCurrentPokemon()->getMaxHp());
                    int tmp = player1.getCurrentPokemon()->getHp() + healing >= player1.getCurrentPokemon()->getMaxHp() ? player1.getCurrentPokemon()->getMaxHp() : player1.getCurrentPokemon()->getHp() + healing;
                    player2.getCurrentPokemon()->setHp(tmp); 
                    cout << player2.getName() << "(" << player2.getCurrentPokemon()->getName() << ") healed for " << healing << "." << " Current hp: " << player2.getCurrentPokemon()->getHp() << endl;
                }

                //player 1 for loop message

                
                    
                
            }
            int flag = 1;
            
            while (flag) {
                cout << ((i == 0) ? player1.getName() : player2.getName()) << "(" << ((i == 0) ? player1.getCurrentPokemon()->getName() : player2.getCurrentPokemon()->getName()) << ") select ability. \n" << endl; 
                cout << "------------------------------------" << endl;
                // print abilities
                for (unsigned j = 0; j < (i == 0 ? player1.getCurrentPokemon()->getAbilities().size() : player2.getCurrentPokemon()->getAbilities().size()); j++) {
                    cout << j << ". " << (i == 0 ? player1.getCurrentPokemon()->getAbilities()[j].getName() : player2.getCurrentPokemon()->getAbilities()[j].getName()) << endl;
                }
                cout << "------------------------------------" << endl;

                // get input
                cin >> tmp;
                // search if ability exists in pokemon;s ability vec
                // if exists execute it
                // else print error message and repeat
                for (unsigned j = 0; j < (i == 0 ? player1.getCurrentPokemon()->getAbilities().size() : player2.getCurrentPokemon()->getAbilities().size()); j++) {
                    if (tmp == (i == 0 ? player1.getCurrentPokemon()->getAbilities()[j].getName() : player2.getCurrentPokemon()->getAbilities()[j].getName())) {
                       
                        (i == 0 ? player1.getCurrentPokemon()->getAbilities()[j].getFunc() : player2.getCurrentPokemon()->getAbilities()[j].getFunc())();
                        flag = 0;
                        break;
                    } else if (j == (i == 0 ? player1.getCurrentPokemon()->getAbilities().size() : player2.getCurrentPokemon()->getAbilities().size()) - 1) {
                        cout << "Ability not found" << endl;
                    }
                }
            }

            cout << "------------------------------------" << endl;

            // printing stats in the end of each ability casted
            printStats(player1.getP(), player2.getP());

            // checking for end of game 
            if (player1.getP()->getHp() <= 0 || player2.getP()->getHp() <= 0) { 
                if (player1.getP()->getHp() <= 0) {
                    winner = 2;
                } else {
                    winner = 1;
                }    
                break;
            }

            turn == 1 ? turn = 2 : turn = 1;
        }
    
    }


    // printing winners
    cout << "Player" << winner << " (" << ((winner == 1) ? player1.getP()->getName() : player2.getP()->getName()) << ") wins. Gotta catch 'em all. \n" << endl;
    copyrights();


    return;
}


void printStats(Pokemon *p1, Pokemon *p2) {
    for (int i = 0; i < 2; i++) {
        cout << endl;
        cout << "########################" << endl;
        if(i == 0) {
            p1->print();
            if(player1.getCurrentPokemon()){
                cout<<"Pokemon out of Pokeball"<<endl;
            }else{
                cout<<"Pokemon in Pokeball"<<endl;
            }
         }else{
            p2->print();
            if(player2.getCurrentPokemon()){
                cout<<"Pokemon out of Pokeball"<<endl;
            }else{
                cout<<"Pokemon in Pokeball"<<endl;
            }
         } 
            
        cout << "########################\n" << endl;
    }
}


void damage(Pokemon p,int hp){
    int damage = hp; 
    Pokemon *attacker;
    Pokemon *defender;    
    
    if (p.getType()==Undefined) { 
        cout << "Pokemon is in pokeball" << endl;
        return;
    }
    defender = p.getOwner()->getCurrentPokemon();
    if (turn == 1) {
        if (p.getOwner()->getName() == string("Player 1")) {
            attacker = p.getOwner()->getCurrentPokemon();
        } else {
            attacker = p.getOwner()->getOpponent()->getCurrentPokemon();
        }
    } else {
        if (p.getOwner()->getName() == string("Player 2")) {
            attacker = p.getOwner()->getCurrentPokemon();
        } else {
            attacker = p.getOwner()->getOpponent()->getCurrentPokemon();
        }
    }



    // Damge based on types 
    if (defender->getType() == Electric) {
        if (attacker->getType() == Fire) {
            damage = damage - (int)(0.3 * (double)damage);
        } else {
            damage = damage - (int)(0.2 * (double)damage);
        }
    } 
    
    if (attacker->getType() == Fire) {
        if (defender->getType() == Electric) {
            damage = damage + (int)(0.2 * (double)damage);
        } else {
            damage = damage + (int)(0.15 * (double)damage);
        }
    }

    if (attacker->getType() == Water) {
        damage = damage + (int)(0.07 * (double)damage);
    }

    if (defender->getType() == Water) {
        damage = damage - (int)(0.07 * (double)damage);
    }

    if (attacker->getType() == Grass) {
        if (_round % 2 == 1) {
            damage = damage + (int)(0.07 * (double)damage);
        }
        // else get healed 5% max health 
        
    }

    if ((int)defender->getHp() - damage <= 0) {
        defender->setHp(0);
    } else {
        defender->setHp((int)defender->getHp() - damage);
    }

    cout << attacker->getName() << " dealt " << damage << " damage to " << defender->getName() << endl;
}

void heal(Pokemon p,int hp){
    if (p.getType() == Undefined) {
        cout << "Pokemon is in pokeball" << endl;
        return;
    }
    
    p.getOwner()->getCurrentPokemon()->setHp((p.getHp() + hp >= p.getMaxHp()) ? p.getMaxHp() : p.getHp() + hp);
    cout << p.getOwner()->getCurrentPokemon()->getName() << " healed " << hp << " hp" << endl;
}

void pokeball(Pokemon p, Dummy d){
    if(p.getType()==Undefined&&!d.getI()){
        cout << "Pokemon is already in pokeball" << endl;
        return;
    }
    Player* player= p.getOwner();
    if(!d.getI()){
        player->setCurrentPokemon(NULL);
        cout << player->getName() << "'s pokemon went into the pokeball." << endl;
    } else {
        if(player1.getCurrentPokemon()==NULL){
            player=&player1;
        }else if(player2.getCurrentPokemon()==NULL){
            player=&player2;
        }
        player->setCurrentPokemon(player->getP());
        cout << player->getName() << "'s pokemon came out of the pokeball." << endl;
    }
    return;
}

int getHp(Pokemon p1,Pokemon p2){
    p2.getName();
    return p1.getHp();
}

string get_Type(Pokemon p1,Pokemon p2){
    p2.getName();
    return PokemonTypeToString(p1.getType());
}

string getName(Pokemon p1,Pokemon p2){
    p2.getName();
    return p1.getName();
}

Pokemon* search_pokemon(string str){
    for (unsigned i = 0; i < Pokemon::p_vec.size(); i++) {
        if (Pokemon::p_vec[i].getName() == str) {
            return &Pokemon::p_vec[i];
        }
    }
    throw std::invalid_argument("Pokemon not found");
}


Pokemon::Pokemon(){
    name = "";
    type = Undefined;
    hp = 0;
    vec = {};
}

Pokemon::Pokemon(string _name,string _type,unsigned _hp): name(_name), type(StringToPokemonType(_type)),hp(_hp) {
    if (name.empty()) {
        throw std::invalid_argument("Pokemon name cannot be empty");
    }
    if (hp == 0) {
        throw std::invalid_argument("Pokemon hp cannot be 0");
    }

    this->setMaxHp(_hp);
    p_vec.push_back(*this);

}
void Pokemon::print() const{
    cout << "Name: " << name << endl;
   // cout << "Type: " << PokemonTypeToString(type) << endl;
    cout << "HP: " << hp << endl;
    /*print vec*/
    for (unsigned i = 0; i < vec.size(); i++) {
        cout << "Pokemon: " << vec[i].name << endl;
        cout << "Type: " << PokemonTypeToString(vec[i].type) << endl;
        cout << "HP: " << vec[i].hp << endl;
    }


}

Pokemon Pokemon::operator,(Pokemon a){
    vec.push_back(a);
    return *this;
}

Pokemon Pokemon::operator[](Pokemon a){
    vec.push_back(a);
    for (unsigned i = 0; i < a.getVec().size(); i++) {
        vec.push_back(a.getVec()[i]);
    }

    return *this;
}

void Pokemon::addAbility(Ability a){
    abilities.push_back(a);
}

string Pokemon::getName() {
    return name;
}
Type Pokemon::getType() const{
    return type;
}
vector <Pokemon> Pokemon::getVec() const{
    return vec;
}
unsigned Pokemon::getHp() const{
    return hp;
}

unsigned Pokemon::getMaxHp() const{
    return maxHp;
}

void Pokemon::setHp(unsigned hp){

    this->hp = hp;
}

void Pokemon::setMaxHp(unsigned maxHp){
    this->maxHp = maxHp;
}
void Pokemon::setOwner(Player* owner){
    this->owner = owner;
}
Player* Pokemon::getOwner() const{
    return owner;
}

vector <Ability> Pokemon::getAbilities() const{
    return abilities;
}

string PokemonTypeToString(Type type) {
    switch (type) {
        case Electric:
            return "Electric";
        case Fire:
            return "Fire";
        case Water:
            return "Water";
        case Grass:
            return "Grass";
        default:
            return "Undefined";
    }
}
Type StringToPokemonType(const std::string& typeStr) {
    if (typeStr == "Electric") {
        return Electric;
    } else if (typeStr == "Fire") {
        return Fire;
    } else if (typeStr == "Water") {
        return Water;
    } else if (typeStr == "Grass") {
        return Grass;
    } else {
        throw std::invalid_argument("Invalid Pokemon type: " + typeStr);
    }
}



Ability::Ability(string _name, function<void()>_func): name(_name), func(_func) {
    if (name.empty()) {
        throw std::invalid_argument("Ability name cannot be empty");
    }
    a_vec.push_back(*this);
}
Ability Ability::operator,(Ability a){
    vec.push_back(a);
    return *this;
}
Ability Ability::operator[](Ability a){
    vec.push_back(a);
    for (unsigned i = 0; i < a.getVec().size(); i++) {
        vec.push_back(a.getVec()[i]);
    }
    return *this;
}
//setters and getters of Ability
string Ability::getName() const{
    return name;
}
function<void()> Ability::getFunc() const{
    return func;
}
vector<Ability> Ability::getVec() const{
    return vec;
}
Ability Ability::operator()(){
    func();
    return *this;
}
void Ability::print() const{
    cout << "Ability: " << name << endl;
    for (unsigned i = 0; i < vec.size(); i++) {
        cout << "Ability: " << vec[i].name << endl;
    }
}


Player::Player(string _name): name(_name){
    if (name.empty()) {
        throw std::invalid_argument("Player name cannot be empty");
    }
}

string Player::getName() const{
    return name;
}

Pokemon* Player::getP() {
    return p;
}

Player* Player::getOpponent() const{
    return opponent;
}
void Player::setName(string name){
    this->name = name;
}
void Player::setP(Pokemon p){
    this->p = new Pokemon;
    *this->p = p;
    this->p->setOwner(this);
}
void Player::setOpponent(Player* opponent){
    this->opponent = opponent;
}
void Player::setCurrentPokemon(Pokemon* currentPokemon){
    this->currentPokemon = currentPokemon;
}
Pokemon* Player::getCurrentPokemon() const{
    return currentPokemon;
}


Round::Round(function<void()> _player1, function<void()> _player2): player1(_player1), player2(_player2) {
}
void Round::play(int i){
    if (i == 1) {
        if(player1)
            player1();
    } else {
        if(player2)
            player2();
    }
}

void Round::setPlayer1(function<void()> player1){
    this->player1.swap(player1);
}
void Round::setPlayer2(function<void()> player2){
    this->player2.swap(player2);
}
function<void()> Round::getPlayer1() const{
    return player1;
}
function<void()> Round::getPlayer2() const{
    return player2;
}
void Round::addToVector(bool for_or_after,unsigned _rounds,int turn,function<void()> fun){
    if(for_or_after==true){     //for
        fun();
        for(unsigned i=0;i<_rounds;i++){
            if(i>=RoundsF.size()){
                if(turn == 1){
                    RoundsF.push_back(Round(fun,[](){}));
                }else{
                    RoundsF.push_back(Round([](){},fun));
                }
            }else{
                if(turn == 1){
                    RoundsF[i].setPlayer1(fun);
                }else{
                    RoundsF[i].setPlayer2(fun);
                }
            }
        }
    }else{  //after
        _rounds++;
        for(unsigned i=0; i <= _rounds; i++){
            if(i >= RoundsA.size()){
                RoundsA.push_back(Round([](){},[](){}));
            }
        }
        if(turn == 1){
            RoundsA[_rounds].setPlayer1(fun);
        }else{
            RoundsA[_rounds].setPlayer2(fun);
        }
    }
}

Dummy::Dummy(int i)
{
    this->i = i;
}
int Dummy::getI(){
    return i;
}
Dummy& Dummy::operator-(Dummy x)
{
    x.getI();
    return *this;
}
Dummy& Dummy::operator--()
{
    return *this;
}
Dummy& Dummy::operator-()
{
    return *this;
}
extern Pokemon* learn;
Dummy::Dummy(string str)
{
    bool exists=false;
    for (unsigned i = 0; i < Ability::a_vec.size(); i++) {
        if (Ability::a_vec[i].getName() == str) {
            exists=true;
            learn->addAbility(Ability::a_vec[i]);
            break;
        }
    }
    if (exists==false) {
        throw std::invalid_argument("Ability not found");
    }
}
//operator[] with int - do nothiung
Dummy& Dummy::operator[](int index){
    index++;
    return *this;
}
Dummy& Dummy::operator[](Dummy d)
{
    d.getI();
    return *this;
}
Dummy& Dummy::operator,(Dummy d)
{
    d.getI();
    return *this;
}

void copyrights() {
    cout << "Project Devs ALexM, PercyS" << endl;
    cout << "© 2020 - 2023 https://github.com/AlexM010 - All Rights Reserved." << endl;
    cout << "© 2020 - 2023 https://github.com/PercySS - All Rights Reserved." << endl;
}
