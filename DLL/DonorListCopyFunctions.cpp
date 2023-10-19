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

#include <iostream>

using namespace std;

DonorList::DonorList(const DonorList& listToCopy)
{
    count = listToCopy.count;
    first = nullptr;
    last = nullptr;
    if (count >0)
    {
        Node* current = listToCopy.first->getPtrToNext();
        while(current != nullptr)
        {
            DonorType currentDonor = current->getDonor();
            addDonor(currentDonor.getFirstName(),
                     currentDonor.getLastName(),
                     currentDonor.getMembershipNo(),
                     currentDonor.getAmountDonated());
            current = current->getPtrToNext();
        }
    }

}

void DonorList::copyCallingObjIsEmpty(const DonorList& listToAssign)
{
    count = listToAssign.count;
    first = new Node(listToAssign.first->getDonor(), nullptr);
    Node* current = listToAssign.first->getPtrToNext();
    while(current != nullptr)
    {
        DonorType currentDonor = current->getDonor();
        addDonor(currentDonor.getFirstName(),
                 currentDonor.getLastName(),
                 currentDonor.getMembershipNo(),
                 currentDonor.getAmountDonated());
        current = current->getPtrToNext();
        
    }
}

void DonorList::copyObjectsSameLength(const DonorList& listToAssign)
{
    Node* current = listToAssign.first;
    Node* callingObjCurrent = first;
    while(current != nullptr)
    {
        callingObjCurrent->setDonor(current->getDonor());
        current = current->getPtrToNext();
        callingObjCurrent = callingObjCurrent->getPtrToNext();
    }
}

void DonorList::copyCallingObjLonger(const DonorList& listToAssign)
{
    count = listToAssign.count;
    Node* current = listToAssign.first;
    Node* callingObjCurrent = first;
    while(current != listToAssign.last)
    {
        callingObjCurrent->setDonor(current->getDonor());
        current = current->getPtrToNext();
        callingObjCurrent = callingObjCurrent->getPtrToNext();
    }
    callingObjCurrent->setDonor(current->getDonor());
    last = callingObjCurrent;
    callingObjCurrent = callingObjCurrent->getPtrToNext();
    Node* callingObjTrail = callingObjCurrent->getPtrToNext();
    last->setPtrToNext(nullptr);
    while(callingObjTrail != nullptr)
    {
        delete callingObjCurrent;
        callingObjCurrent = callingObjTrail;
        callingObjTrail = callingObjTrail->getPtrToNext();
    }
    delete callingObjCurrent;
    callingObjCurrent = nullptr; 
}

void DonorList::copyCallingObjShorter(const DonorList& listToAssign)
{
    count = listToAssign.count;
    Node* current = listToAssign.first;
    Node* callingObjCurrent = first;
    while(callingObjCurrent != nullptr)
    {
        callingObjCurrent->setDonor(current->getDonor());
        current = current->getPtrToNext();
        callingObjCurrent = callingObjCurrent->getPtrToNext();
    }
    
    while(current != nullptr)
    {
        DonorType currentDonor = current->getDonor();
        addDonor(currentDonor.getFirstName(),
                 currentDonor.getLastName(),
                 currentDonor.getMembershipNo(),
                 currentDonor.getAmountDonated());
        current = current->getPtrToNext();
    }
    
}

DonorList& DonorList::operator=(const DonorList& listToAssign)
{
    if(&listToAssign != this)
    {
        if(count == 0)
        {
            copyCallingObjIsEmpty(listToAssign);
        }
        else if(count == listToAssign.count)
        {
            copyObjectsSameLength(listToAssign);
        }
        else if(count > listToAssign.count)
        {
            copyCallingObjLonger(listToAssign);
        }
        else
        {
            copyCallingObjShorter(listToAssign);
        }

    }
    else
        cerr << "Attempted assignment to itself.";

    return *this;
}
