#include "Settlement.h"


// Constructor implementation
Settlement::Settlement(const string &name, SettlementType type)
    : name(name), type(type) {}


// Getter for name
const string &Settlement::getName() const {
    return name;
}

// Getter for type
SettlementType Settlement::getType() const {
    return type;
}

const string Settlement:: SettlementTypeToString(SettlementType type)const{
    switch (type)
    {
    case SettlementType:: VILLAGE:
        return "Village";
    case SettlementType:: CITY:
        return "City";    
    case SettlementType:: METROPOLIS:
        return "Metropolis";
    default:
        return "ERROR: Settlement type does not exist";
    }
} 

const string Settlement:: toString()const{
    return "Settlement name: " + name + "\nSettlement type: " + SettlementTypeToString(type);
}
