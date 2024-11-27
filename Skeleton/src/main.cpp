#include "Simulation.h"
#include <iostream>
#include <vector>
#include "Facility.h"


using namespace std;

Simulation* backup = nullptr;


    int main(int argc, char** argv){
    vector<FacilityType> vec = {
        {"Hospital", FacilityCategory::LIFE_QUALITY, 200, 95, 20, 10},
        {"Bank1", FacilityCategory::ECONOMY, 100, 50, 80, 20},
        {"Park", FacilityCategory::ENVIRONMENT, 50, 70, 10, 100},
        {"Bank2", FacilityCategory::ECONOMY, 120, 40, 90, 30},
        {"Mall", FacilityCategory::LIFE_QUALITY, 150, 60, 50, 40}
    };
    NaiveSelection* eco = new NaiveSelection();
    cout << eco->selectFacility(vec).getName()<<endl;
    cout<< "__________"<<endl;
    cout << eco->selectFacility(vec).getName()<<endl;
    cout<< "__________"<<endl;
    cout << eco->selectFacility(vec).getName()<<endl;
    cout<< "__________"<<endl;

    delete eco;
    return 0;
}
    
