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

#ifndef DONORLIST_H
#define DONORLIST_H

#include "DonorType.h"

#include <set>

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
    double getHighestDonation() const; 
    
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
    
    std::set<DonorType>* donorList;
};

#endif /* DonorList_hpp */

