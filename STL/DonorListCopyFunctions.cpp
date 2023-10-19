/*
    Bug Squashers
  
    Esfahani, Sasan
    Nguyen, Katelynn
    Lynch, Christopher
    Fisher, Justin
  
    November 21, 2021
  
    CSA250
    Project2
*/

#include "DonorList.h"

using namespace std;

DonorList::DonorList(const DonorList& listToCopy)
{
    donorList = new set<DonorType>;
    *donorList = *(listToCopy.donorList);
}

DonorList& DonorList::operator=(const DonorList& listToAssign)
{
    if(&listToAssign == this)
    {
        cerr << "Attempt assignment to itself.";
    }
    else
    {
        *donorList = *(listToAssign.donorList);
    }
    return *this;
}
