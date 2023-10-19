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

#include "DonorType.h"

using namespace std;

DonorType::DonorType()
{
    donationAmount = 0.0;
}

DonorType::DonorType
          (const std::string& newFirstName,
           const std::string& newLastName,
           int newMemberNum, double newDonationAmount)
          : MemberType(newFirstName, newLastName, newMemberNum)
{
    donationAmount = newDonationAmount;
}

void DonorType::setDonorInfo
                (const std::string& newFirstName,
                 const std::string& newLastName,
                 int newMemberNum, double newDonationAmount)
{
    MemberType::setMemberInfo(newFirstName,
                              newLastName, newMemberNum);
    donationAmount = newDonationAmount;
    
}

void DonorType::setAmountDonated(double newDonationAmount)
{
    donationAmount = newDonationAmount;
}

double DonorType::getAmountDonated() const
{
    return donationAmount;
}

void DonorType::printDonor() const
{
    MemberType::printMemberInfo();
}

void DonorType::printDonation() const
{
    MemberType::printMemberInfo();
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Donation amount: $" << donationAmount << endl;
}

DonorType::~DonorType()
{
    
}

bool DonorType::operator<(const DonorType& otherDonor) const
{
    return (getMembershipNo()<otherDonor.getMembershipNo());
}

bool DonorType::operator==(int membershipNo) const
{
    return (getMembershipNo() == membershipNo);
}
