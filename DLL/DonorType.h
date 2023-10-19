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

#ifndef DONORTYPE_H
#define DONORTYPE_H

#include "MemberType.h"

class DonorType : public MemberType
{
public:
    DonorType();
    DonorType(const std::string& newFirstName,
              const std::string& newLastName,
              int newMemberNum, double newDonationAmount);
    
    void setDonorInfo(const std::string& newFirstName,
                      const std::string& newLastName,
                      int newMemberNum, double newDonationAmount);
    void setAmountDonated(double newDonationAmount);
    
    double getAmountDonated() const;
    
    void printDonor() const;
    void printDonation() const;
    
    ~DonorType();
    
    bool operator<(const DonorType& otherDonor) const;
    
private:
    double donationAmount;
};

#endif







