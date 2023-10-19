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

#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <string>
#include <iostream>

class MemberType
{
public:
    MemberType();
    MemberType(const std::string& newFirstName,
               const std::string& newLastName, int newMemberNum);
    
    void setMemberInfo(const std::string& newFirstName,
                       const std::string& newLastName,
                       int newMemberNum);
    
    std::string getFirstName() const;
    std::string getLastName() const;
    int getMembershipNo() const;
    
    void printName() const;
    void printMemberInfo() const;
    
    ~MemberType();
    
private:
    std::string firstName;
    std::string lastName;
    int memberNum;
};

#endif
