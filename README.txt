##Donor Management System


#Project Overview
This Donor Management System is a C++ program designed to manage donor information for a nonprofit organization. It allows users to add, delete, and retrieve donor information, as well as perform various operations like calculating total donations and finding the highest donation. The project was developed by the Bug Squashers team as part of a course (CSA250) and was completed on November 21, 2021.

Project Features
Donor Information Management: The system can store donor information, including first name, last name, membership number, and donation amount.

Add Donor: Users can add new donors to the system by providing their personal information and donation amount.

Delete Donor: Donors can be removed from the system using their membership number.

Display Donor List: The program can display a list of all donors, including their names and membership numbers.

Display Donor Donations: It can display a list of all donors and their corresponding donation amounts.

Total Donations: The system can calculate the total amount of donations made by all donors.

Highest Donation: It can identify the donor with the highest donation amount.

Search by Membership Number: Users can search for donors by their membership number.

User-Friendly Interface: The program offers a menu-driven interface for easy navigation.

Project Components
The project consists of several key components:

DonorList Class: Manages the list of donors and provides methods for adding, deleting, and accessing donor information.

DonorType Class: Represents individual donors and includes methods for setting and retrieving donor information.

MemberType Class: A base class for DonorType, containing common attributes and methods.

Interface Module: Provides a user-friendly command-line interface with options to perform various actions.

InputHandler Module: Responsible for reading donor data from an input file.

Main Program: The main entry point of the application, where user interaction is initiated.

How to Run the Program
To run the Donor Management System, follow these steps:

Compile the source code files (DonorList.cpp, DonorType.cpp, MemberType.cpp, Interface.cpp, InputHandler.cpp, and Main.cpp) using a C++ compiler (e.g., g++).
Ensure you have an input file named "donors_data.txt" containing donor information in the format: <First Name> <Last Name> <Membership Number> <Donation Amount>.
Execute the compiled program.
Project Team
Sasan Esfahani
Katelynn Nguyen
Christopher Lynch
Justin Fisher
Project Date
Completed on November 21, 2021
Skills Demonstrated
C++ programming
Object-oriented design
File handling
User interface design
Data management