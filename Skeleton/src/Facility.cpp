#include "Facility.h"

// Constructor implementation
FacilityType::FacilityType(const string &name, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
    :name(name), category(category), price(price), lifeQuality_score(lifeQuality_score), economy_score(economy_score),environment_score(environment_score){}


const string &FacilityType:: getName() const{
    return name;}

int FacilityType:: getCost() const{
    return price;}

int FacilityType:: getLifeQualityScore() const{
    return lifeQuality_score;}

int FacilityType:: getEnvironmentScore() const{
    return environment_score;}

int FacilityType:: getEconomyScore() const{
    return economy_score;}

FacilityCategory FacilityType:: getCategory() const{
    return category;}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//


Facility :: Facility(const string &name, const string &settlementName, const FacilityCategory category
        , const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
        :FacilityType(name,category,price,lifeQuality_score,economy_score,environment_score),settlementName(settlementName),status(FacilityStatus :: UNDER_CONSTRUCTIONS),timeLeft(price){}

Facility ::Facility(const FacilityType &type, const string &settlementName)
        : FacilityType(type) ,
          settlementName(settlementName),
          status(FacilityStatus :: UNDER_CONSTRUCTIONS),
          timeLeft(type.getCost()){}

const string &Facility:: getSettlementName() const{
    return settlementName;
}

const int Facility:: getTimeLeft() const{
    return timeLeft;
}

FacilityStatus Facility :: step(){
    if(timeLeft==1){
            setStatus(FacilityStatus :: OPERATIONAL);
    }
    timeLeft--;
    return this->getStatus();
}

void Facility:: setStatus(FacilityStatus status){
    this->status = status;
}

const FacilityStatus &Facility:: getStatus() const{
    return this->status;
}

// toString Method Implementation
const string Facility::toString() const {
    return "name: " + this->getName() +
           "\nsettlementName: " + this->getSettlementName() +
           "\nFacility category: " + CategoryToString(this->category) +
           "\nprice: " + std::to_string(this->getCost()) +
           "\nlifeQuality score: " + std::to_string(this->getLifeQualityScore()) +
           "\neconomy score: " + std::to_string(this->getEconomyScore()) +
           "\nenvironment score: " + std::to_string(this->getEnvironmentScore()) +
           "\ncurrent status: " + StatusToString(status) +
           "\nTime left: " + std::to_string(this->getTimeLeft());
}



const string Facility:: CategoryToString(FacilityCategory facilityCategory)const{
    switch (facilityCategory){
    case FacilityCategory::ECONOMY:
        return "ECONOMY";
    case FacilityCategory::ENVIRONMENT:
        return "ENVIRONMENT";    
    case FacilityCategory::LIFE_QUALITY:
        return "LIFE_QUALITY";
    default:
        return "ERROR: Facility category  does not exist";
    }
} 

const string Facility:: StatusToString(FacilityStatus facilityStatus)const{
    if(facilityStatus== FacilityStatus::OPERATIONAL){
        return "OPERATIONAL";
    }
    else{
         return "UNDER_CONSTRUCTION";
    }
    }


    // private:
    //     const string name;
    //     const FacilityCategory category;
    //     const int price;
    //     const int lifeQuality_score;
    //     const int economy_score;
    //     const int environment_score;
    //     const string settlementName;
    //     FacilityStatus status;
    //     int timeLeft;