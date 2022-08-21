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

#include "DonorList.h"
#include "Database.h"

#include <iostream>

using namespace std;

DonorList::DonorList()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

void DonorList::addDonor(const string& newFirstName,
                         const string& newLastName,
                         int newMembershipNo,
                         double newDonationAmount)
{
    if (count == 0)
        {
            Node* toAdd = new Node(*new DonorType(newFirstName,
                                                  newLastName,
                                                  newMembershipNo,
                                                  newDonationAmount),
                                 nullptr);
            first = toAdd;
            last = first;
        }
        else
        {
            if(first->getDonor().getMembershipNo() > newMembershipNo)
            {
                first = new Node(*new DonorType(newFirstName,
                                                newLastName,
                                                newMembershipNo,
                                                newDonationAmount),
                                 first);
            }
            else
            {
                Node* current = first->getPtrToNext();
                Node* trailer = first;
                while(current != nullptr &&
                      current->getDonor().getMembershipNo()
                      < newMembershipNo)
                {
                    trailer = current;
                    current = current->getPtrToNext();
                }
            
                trailer->setPtrToNext(new Node(*new DonorType
                                               (newFirstName,
                                                newLastName,
                                                newMembershipNo,
                                                newDonationAmount),
                                               current));
                if(current == nullptr)
                    last = trailer->getPtrToNext();
            }
        }
        ++count;
}

void DonorList::createList()
{
    set<DonorType> toTransfer = getData();
    if (toTransfer.size() != 0)
    {

        for ( const DonorType& elem : toTransfer)
        {
            addDonor(elem.getFirstName(),
                     elem.getLastName(),
                     elem.getMembershipNo(),
                     elem.getAmountDonated());
        }
    }
    else
    {
        cout << "Database has no data.";
    }
    
}

int DonorList::getNoOfDonors() const
{
    return count;
}

double DonorList::getTotalDonations() const
{
    Node* current = first;
    double sum = 0.0;
    while (current != nullptr)
    {
        sum += current->getDonor().getAmountDonated();
        current = current->getPtrToNext();
    }
    return sum;
    
}

bool DonorList::isEmpty() const
{
    return (count == 0);
}

bool DonorList::searchID(int memberNoToSearch) const
{
    Node* current = first;
    while(current != nullptr)
    {
        if(current->getDonor().getMembershipNo() == memberNoToSearch)
        {
            return true;
        }
        current = current->getPtrToNext();
    }
    return false;
}

void DonorList::deleteDonor(int memberNoToDelete)
{
    Node* current = first->getPtrToNext();
    if(first->getDonor().getMembershipNo() == memberNoToDelete)
    {
        delete first;
        first = current;
        --count;
    }
    else
    {
        Node* trailCurrent = first;
        
        while(current != nullptr)
        {
            if(current->getDonor().getMembershipNo()
               == memberNoToDelete)
            {
                trailCurrent->setPtrToNext(current->getPtrToNext());
                delete current;
                current = nullptr;
                --count;
            }
            else
            {
                trailCurrent = trailCurrent->getPtrToNext();
                current = current->getPtrToNext();
            }
            
        }
    }
    
}

void DonorList::printAllDonors() const
{
   Node* current = first;
   while(current != nullptr)
   {
       current->getDonor().printMemberInfo();
       current = current->getPtrToNext();
   }
}

void DonorList::printAllDonations() const
{
    Node* current = first;
    while(current != nullptr)
    {
        current->getDonor().printDonation();
        current = current->getPtrToNext();
    }
}

void DonorList::clearList()
{
    Node* current = first;
    while(current != nullptr)
    {
        first = first->getPtrToNext();
        delete current;
        current = first;
    }
    last = nullptr;
    count = 0;
}

DonorList::~DonorList()
{
    clearList(); 
}
