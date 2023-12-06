#include "PokemonLeague.h"

Pokemon::Pokemon(string _name,string _type,unsigned _hp): name(_name), type(StringToPokemonType(_type)),hp(_hp) {
    if (name.empty()) {
        throw std::invalid_argument("Pokemon name cannot be empty");
    }
    if (hp == 0) {
        throw std::invalid_argument("Pokemon hp cannot be 0");
    }
    
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
    this->print();
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