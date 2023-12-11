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
std::string PokemonTypeToString(Type type) {
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

