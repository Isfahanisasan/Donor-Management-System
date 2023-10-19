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

#include "Interface.h"
#include "InputHandler.h"

using namespace std;

int main()
{
    DonorList newDonorList;
    getDonorData(newDonorList);
    if (!newDonorList.isEmpty())
    {
        displayMenu();
        processSelection(newDonorList);
    }

    return 0;
}
