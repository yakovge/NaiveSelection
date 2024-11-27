#include "SelectionPolicy.h"
#include <vector>
#include "Facility.h"
#include <stdexcept>
using namespace std;




NaiveSelection:: NaiveSelection()
: lastSelectedIndex (-1){}

    const FacilityType& NaiveSelection:: selectFacility(const vector<FacilityType>& facilitiesOptions){
                lastSelectedIndex = (lastSelectedIndex + 1) % facilitiesOptions.size();
                return facilitiesOptions[lastSelectedIndex];
            }
            
    const string NaiveSelection:: toString() const{
            return "NaiveSelection: Last selected index = " + std::to_string(lastSelectedIndex);
    }
    NaiveSelection* NaiveSelection:: clone() const{
        NaiveSelection* copy = new  NaiveSelection();
        copy -> lastSelectedIndex = this -> lastSelectedIndex;
        return copy;
    }
