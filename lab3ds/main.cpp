
// Programmer: Jose Benjamin Gutierrez
// Project Number: 3
// Project Desc: List Class with a Dynamic Array
// Course: Data Structures
// Date: Sep 19, 2015

#include <cctype>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "DList.h"

using namespace std;

/***** Prints a menu *****/
void printMenu();
/* -----------------------------------------------------------------------------------------------------
 Precondition: None!
 Postcondition: Prints out a menu
 -----------------------------------------------------------------------------------------------------*/


/***** Gets a positive number between 0 -999 for multiple uses *****/
int getNumber();
/* -----------------------------------------------------------------------------------------------------
 Library facilities used: Iostream!
 Gets an integer from the user to test differrent functions
 Precondition: Integer must be positive!
 Postcondition: A positive number is returned to the test driver
 -----------------------------------------------------------------------------------------------------*/


int main()
{
    
    List test;                                          // A list to perform tests on.
    char choice, command;
    int intResult;
    
    for(int i = 0; i < 5; i++)                          //For loop generates a list of 5
                                                        //random numbers.
    {
        int ramdonNum = rand() & 999;
        test.insert(ramdonNum, test.getSize());
    }
    
    cout << "A list of random numbers has been generated" << endl;
        do
    {
        
        printMenu();                                     //Prints the main menu.
        cin >> command;
        command = toupper(command);                      //Toupper function accepts A or a
                                                         //as valid inputs.
        
        switch(command)
        {
            case 'A':
                intResult = getNumber();                 //Positive number to add to the list.
                cout << "Adding "<< intResult << " numbers to the end of the current list. \n" << endl;
                
                for(int i = 0; i < intResult; i++)        //For loop inserts random numbers to the
                {                                         //end of list.
                    int ramdonNum = rand() & 999;
                    test.insert(ramdonNum, test.getSize());
                }
                cout << "------------------------------------------------\n";
                break;
                
                
            case 'C':
                intResult = getNumber();                   // Positive number to resize the list.
                test.resize(intResult);                    //Changes the capacity of list
                cout << "Capacity has been resized!" << endl;
                cout << "------------------------------------------------\n";
                break;
            
                
            case 'E':
                cout << "------------------------------------------------\n";
                if(test.empty())                           //Tests to see if list is empty
                {
                    cout << "Empty list!" << endl;
                }
                else
                {
                    cout << "List is not empty!" << endl;
                }
                cout << "------------------------------------------------\n";
                break;
                
                
            case 'P':
                if(test.empty())                            //If list empty, do this.
                {
                    cout << "------------------------------------------------\n";
                    cout << "Empty list!" << endl;
                    cout << test << endl;
                    cout << "------------------------------------------------\n";
                }
                else                                         //Not empty, do this.
                {
                    cout << "------------------------------------------------\n";
                    cout << test << endl;                    //Prints the list, size & capacity
                    cout << "------------------------------------------------\n";
                }
                break;
                
            case 'I':
                int position;
                intResult = getNumber();                    //Inserts a number at a given position
                cout << "Which position would you like to input " << intResult << endl;
                cin >> position;
                test.insert(intResult, position);
                cout << "------------------------------------------------\n";
                break;
                
                
                
            case 'R':
                intResult = getNumber();                     //Deletes a number at a given position
                test.erase(intResult);
                cout << "------------------------------------------------\n";
                break;
                
        }
        cout << "Would you like to continue? [Y/N]" << endl;   //Continue?
        cin >> choice;
        choice = toupper(choice);
    }
    
    while((choice != 'N'));

}



/***** Get a number operation *****/
int getNumber()
{
    int result;
    do
    {
        cout << "------------------------------------------------\n";
        cout << "Please enter an integer: \n";
        cin >> result;
        if(result<0)
        {
            cerr << "Error: Number must be positive" << endl;
        }
    }
    while (result < 0);
    return result;
}


/***** Print a menu *****/
void printMenu()
{
    cout << endl;
    cout << "The following choices are available: " << endl;
    cout << "A	Add a number of random integers to the end of the list!" << endl;
    cout << "C	Change the capacity of the list!" << endl;
    cout << "E	Check to see if the list is empty!" << endl;
    cout << "P	Print a copy of the entire list!" << endl;
    cout << "I	Insert a new number!" << endl;
    cout << "R	Remove a number!" << endl;
}
