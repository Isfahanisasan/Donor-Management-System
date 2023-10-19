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

#ifndef INTERFACE_H
#define INTERFACE_H

#include "DonorList.h"

void displayMenu();
void processSelection(DonorList& pramDonorList);
void addDonor(DonorList& donorListToAdd);
void deleteDonor(DonorList& donorListToDelete);
void printAllDonors(const DonorList& donorListToPrint);

#endif /* Interface_hpp */
