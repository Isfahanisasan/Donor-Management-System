/*
    Bug Squashers
  
    Esfahani, Sasan
    Nguyen, Katelynn
    Lynch, Christopher
    Fisher, Justin
  
    November 21, 2021
  
    CSA250
    Project1
*/

#include "Interface.h"

using namespace std;

int main()
{
    DonorList newDonorList3;
    newDonorList3.createList();
    if (!newDonorList3.isEmpty())
    {
        displayMenu();
        processSelection(newDonorList3);
    }

    return 0;
}
