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

#include <iomanip>
#include <iostream>

using namespace std;

void displayMenu()
{
    for (int i = 0; i < 49; i++)
    {
        cout << '*' ;
    }
    cout << endl;
    cout << setw(29) << "MAIN MENU" << endl;
    for (int i = 0; i < 49; i++)
    {
        cout << '*' ;
    }
    cout << endl;
    cout << "\nSelect one of the following:" << endl;
    cout << "\n    1. Add a donor" << endl <<
    "    2. Delete a donor" << endl;
    cout << "    3. Print all donors" << endl <<
    "    4: To exit\n" << endl;
         
}


                                    
void addDonor(DonorList& donorListToAddTo)
{
    cout << "\n  => Enter donor's first name: ";
    //setDonorFirstName
    string firstName;
    cin >> firstName;
    
    cout << "  => Enter donor's last name: ";
    string lastName;
    cin >> lastName;
    
    cout << "  => Enter donor's membership number: ";
    int memberNo;
    cin >> memberNo;
    
    cout << "  => Enter amount donated: $ ";
    double donationAmount;
    cin >> donationAmount;
    
    
    donorListToAddTo.addDonor(firstName,
                              lastName, memberNo, donationAmount);
    cout << "\n  => Donor has been added." << endl;
    
}

void deleteDonor(DonorList& donorListToDeleteFrom)
{
    if(donorListToDeleteFrom.isEmpty())
    {
        cout << "\nThe database has no donors." << endl;
    }
    else
    {
        cout << "\n  => Enter donor's membership number: ";
        int memberNoToDelete;
        cin >> memberNoToDelete;
        if (donorListToDeleteFrom.searchID(memberNoToDelete))
        {
            donorListToDeleteFrom.deleteDonor(memberNoToDelete);
            cout << "\n  => Donor has been deleted." << endl;
        }
        else
        {
            cout << "\n  => Donor is not in the list." << endl;
        }
    }
}

void printAllMembers(const DonorList& donorListToPrint)
{
    cout << endl;
    donorListToPrint.printAllDonors();
}

void processSelection(DonorList& paramDonorList)
{
    char charSelection = 'y';
    int numSelection = 0;
    bool firstTime = true;
    while(charSelection == 'y')
    {
        if(!firstTime)
        {
            cout << endl;
            displayMenu();
        }
        cout << "  => Enter your selection: ";
        cin >> numSelection;
        if(numSelection == 4)
        {
            cout << "\n  => Thank you for visiting our site!\n"
            << endl;
            cout << "Press any key to continue . . .";
            charSelection = 'n';
        }
        else
        {
            if (numSelection == 1)
            {
                addDonor(paramDonorList);
            }
            else if(numSelection == 2)
            {
                deleteDonor(paramDonorList);
            }
            else if(numSelection == 3)
            {
                printAllMembers(paramDonorList);
            }
            else
            {
                cout << "\n  => Sorry. That is not a selection."
                << endl;
            }
            cout << "\n  => Would you like to continue? (y/n) ";
            cin >> charSelection;
            firstTime = false;
            if (charSelection == 'n')
            {
                cout << "\n  => Thank you for visiting our site!\n"
                << endl;
                cout << "Press any key to continue . . .";
            }
        }
    }
}
