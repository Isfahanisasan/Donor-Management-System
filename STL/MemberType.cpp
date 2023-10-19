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

#include "MemberType.h"

using namespace std;

MemberType::MemberType()
{
    firstName = "N/A";
    lastName = "N/A";
    memberNum = 0;
}

MemberType::MemberType(const string& newFirstName,
                       const string& newLastName, int newMemberNum)
{
    firstName = newFirstName;
    lastName = newLastName;
    memberNum = newMemberNum;
}

void MemberType::setMemberInfo(const string& newFirstName,
                               const string& newLastName,
                               int newMemberNum)
{
    firstName = newFirstName;
    lastName = newLastName;
    memberNum = newMemberNum;
}

string MemberType::getFirstName() const
{
    return firstName;
}

string MemberType::getLastName() const
{
    return lastName;
}

int MemberType::getMembershipNo() const
{
    return memberNum;
}

void MemberType::printName() const
{
    cout << lastName << ", " << firstName << endl;
}

void MemberType::printMemberInfo() const
{
    cout << memberNum << " - "
         << firstName << " " << lastName << endl;
}

MemberType::~MemberType()
{
    
}
