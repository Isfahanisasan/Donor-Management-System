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

#ifndef DONORLIST_H
#define DONORLIST_H

#include "DonorType.h"

#include <string> 

class Node
{
    
public:
    Node() : ptrToNext(nullptr) {}

    Node(const DonorType& newDonor, Node* newPtrToNext)
        : ptrToNext(newPtrToNext), donor(newDonor) {}

    DonorType& getDonor() { return donor; }

    Node* getPtrToNext() const{ return ptrToNext; }

    void setDonor(const DonorType& newDonor) { donor = newDonor; }

    void setPtrToNext(Node* newPtrToNext)
        { ptrToNext =  newPtrToNext; }

    ~Node() {}

private:
    DonorType donor;
    Node* ptrToNext;
};

class DonorList
{
public:
    DonorList();
    
    void addDonor(const std::string& newFirstName,
                  const std::string& newLastName,
                  int newMembershipNo, double newDonationAmount);
    
    void createList();
    
    int getNoOfDonors() const;
    double getTotalDonations() const;
    
    bool isEmpty() const;
    bool searchID(int memberNoToSearch) const;
    
    void deleteDonor(int memberNoToDelete);
    
    void printAllDonors() const;
    void printAllDonations() const;
    
    void clearList();
    
    ~DonorList();
    
    DonorList(const DonorList& donorListToCopy);
    DonorList& operator=(const DonorList& listToAssign);
    
private:
    void copyCallingObjIsEmpty(const DonorList& listToAssign);
    void copyObjectsSameLength(const DonorList& listToAssign);
    void copyCallingObjLonger(const DonorList& listToAssign);
    void copyCallingObjShorter(const DonorList& listToAssign);
    
    Node* first;
    Node* last;
    int count;
};

#endif
