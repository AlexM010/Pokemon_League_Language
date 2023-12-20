#include "PokemonLeague.h"


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

    p_vec.push_back(*this);

}
void Pokemon::print() const{
    cout << "Pokemon: " << name << endl;
    cout << "Type: " << PokemonTypeToString(type) << endl;
    cout << "HP: " << hp << endl;
    /*print vec*/
    for (unsigned i = 0; i < vec.size(); i++) {
        cout << "Pokemon: " << vec[i].name << endl;
        cout << "Type: " << PokemonTypeToString(vec[i].type) << endl;
        cout << "HP: " << vec[i].hp << endl;
    }
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
            return "Unknown";
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
/*getters*/
string Pokemon::getName() const{
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
//sethp
void Pokemon::setHp(unsigned hp){
    this->hp = hp;
}
void Pokemon::setOwner(Player* owner){
    this->owner = owner;
}
Player* Pokemon::getOwner() const{
    return owner;
}
//ability
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
void Player::addPokemon(Pokemon p){
    p_vec.push_back(p);
    p.setOwner(this);
}
void Player::givePokemon(string p){
    for (unsigned i = 0; i < p_vec.size(); i++) {
        if (p_vec[i].getName() == p) {
            opponent->addPokemon(p_vec[i]);
            p_vec[i].setOwner(opponent);
            p_vec.erase(p_vec.begin() + i);
            break;
        }
    }
}
string Player::getName() const{
    return name;
}
vector <Pokemon> Player::getP_vec() const{
    return p_vec;
}
Player* Player::getOpponent() const{
    return opponent;
}
void Player::setName(string name){
    this->name = name;
}
void Player::setP_vec(vector <Pokemon> p_vec){
    this->p_vec = p_vec;
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
// extern vector <Pokemon> Pokemon::p_vec;
// extern vector<Ability> Ability::a_vec;
// extern Player player1;
// extern Player player2;
void damage(Pokemon p,int hp){
    p.getOwner()->getCurrentPokemon()->setHp(p.getHp() - hp);
}
void heal(Pokemon p,int hp){
    p.getOwner()->getCurrentPokemon()->setHp(p.getHp() + hp);
}
void pokeball(Pokemon p, Dummy d){
    Player* player= p.getOwner();
    if(d.getI()){
       player->setCurrentPokemon(NULL);
       player->getP_vec().push_back(p);
    }else{
        //search in p_vec
        for (unsigned i = 0; i < player->getP_vec().size(); i++) {
            if (player->getP_vec()[i].getName() == p.getName()) {
                player->setCurrentPokemon(&(player->getP_vec()[i]));
                player->getP_vec().erase(player->getP_vec().begin() + i);
                break;
            }
        }
    }
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
