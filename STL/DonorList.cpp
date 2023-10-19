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

#include <algorithm>
#include <iomanip>

#include "DonorList.h"

using namespace std;

DonorList::DonorList()
{
    donorList = new set<DonorType>;
}

void DonorList::addDonor(const string& newFirstName,
                         const string& newLastName,
                         int newMembershipNo,
                         double newDonationAmount)
{
    DonorType tempDonor(newFirstName, newLastName, newMembershipNo,
                        newDonationAmount);
    donorList->insert(tempDonor);
}

int DonorList::getNoOfDonors() const
{
    return (static_cast<int>(donorList->size()));
}

double DonorList::getTotalDonations() const
{
    
    double sum = 0.0;
    for(const auto& elem : *donorList)
    {
        sum += elem.getAmountDonated();
    }
    return sum;
    
}

double DonorList::getHighestDonation() const
{
    double highestAmount = 0.0;
    for(const auto& elem : *donorList)
    {
        if(highestAmount < elem.getAmountDonated())
            highestAmount = elem.getAmountDonated();
    }
    return highestAmount;
}

bool DonorList::isEmpty() const
{
    return (donorList->empty());
}

bool DonorList::searchID(int memberNoToSearch) const
{
    return find(donorList->begin(), donorList->end(),
                memberNoToSearch) != donorList->end();
}

void DonorList::deleteDonor(int memberNoToDelete)
{
    auto elemToDelete = find(donorList->begin(), donorList->end(),
                             memberNoToDelete);
    if(elemToDelete != donorList->end())
    {
        donorList->erase(elemToDelete);
    }
}

void DonorList::printAllDonors() const
{
   for (const auto& elem : *donorList)
   {
      elem.printMemberInfo();
   }
}

void DonorList::printAllDonations() const
{
    for (const auto& elem : *donorList)
    {
        cout << "(" << elem.getMembershipNo() << ") "
        << elem.getLastName() << ", " << elem.getFirstName() << endl;
        cout << fixed << showpoint;
        cout << setw(5) << setprecision(2);
        cout << "    Donation amount: $"
        << elem.getAmountDonated() << endl;
    }
}

void DonorList::clearList()
{
    donorList->clear();
}

DonorList::~DonorList()
{
    delete donorList;
    donorList = nullptr; 
}
