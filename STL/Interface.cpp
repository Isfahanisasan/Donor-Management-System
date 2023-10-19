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
    "    4. Print all donations" << endl;
    cout << "    5. Print total donations" << endl <<
    "    6. Print highest donation" << endl;
    cout << "    7: To exit\n" << endl;
         
}

void printAllDonations(const DonorList& donorListToPrintFrom)
{
    donorListToPrintFrom.printAllDonations();
}

void printTotalDonations(const DonorList& donorListToPrintFrom)
{
    cout << "     Total donations: $";
    cout << fixed << showpoint;
    cout << setw(5) << setprecision(2)
    << donorListToPrintFrom.getTotalDonations() << endl;
}

void printHighestDonation(const DonorList& donorListToPrintFrom)
{
    cout << "     Highest donation: $";
    cout << fixed << showpoint;
    cout << setw(5) << setprecision(2) <<
    donorListToPrintFrom.getHighestDonation() << endl;
    
}

void addDonor(DonorList& donorListToAddTo)
{
    cout << "  => Enter donor's first name: ";
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
        cout << "The database has no donors." << endl;
    }
    else
    {
        cout << "  => Enter donor's membership number: ";
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
        cout << endl;
        if(numSelection == 7)
        {
            cout << "  => Thank you for visiting our site!\n"
            << endl;
            cout << "Press any key to continue . . ." << endl;
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
            else if(numSelection == 4)
            {
                printAllDonations(paramDonorList);
            }
            else if(numSelection == 5)
            {
                printTotalDonations(paramDonorList);
            }
            else if(numSelection == 6)
            {
                printHighestDonation(paramDonorList);
            }
            else
            {
                cout << "  => Sorry. This is not a selection."
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
