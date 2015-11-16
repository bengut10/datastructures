// Programmer: Jose Benjamin Gutierrez
// Project Number: 4
// Project Desc: List Class with a Linked List
// Course: Data Structures
// Date: Oct 05, 2015

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <string>       //Provides access to string class
#include "List.h"

using namespace std;

/***** Prints a menu *****/
void printMenu();
/* ----------------------------------------------------------------------------
 Precondition: None
 Postcondition: Prints out a menu
 ----------------------------------------------------------------------------*/

int main()
{
    List obj1;
	string name;
    string nameArray[5] = {"Jose","Luke","Alex","Michael","Floyd"};
    char command;
    int position, indexFound;
    bool empty;
    
    for(int i = 0 ; i < 5; i++)           // Initializes the list with 5 names.
    {
        string tempName;
        tempName = nameArray[i];
        obj1.insert(tempName, i);
    }
    
    do
    {
        printMenu();                     //Prints the main menu.
        cin >> command;
        command = toupper(command);    	 //Accepts A or a.
        
        switch(command)
        {
            case 'A':                //Insert 3 strings at the end of the list.
                for(int i = 0; i < 3; i++)
                {
                    cout << "Enter a name: " << endl;
                    cin >> name;
                    obj1.insert(name, obj1.getSize());
                }
                break;
                
            case 'S':                //Displays the size of the list.
               	obj1.displaySize(cout);
                break;
            
                
            case 'C':     //Explicitly calling the copy constructor
            	{
            		List obj3(obj1);
            		cout << "Contents of the new list using the CP:" <<endl;
            		obj3.display(cout);
					break;	
				}
				
            case 'O':   //Prints the results from using the assignment operator
            	{
            		List obj2;
				    obj2 = obj1;
   	             	cout << "Contents of List 1: " << endl;
    	            obj1.display(cout);
        	        
            	    cout << "Contents of List 2: " << endl;
                	obj2.display(cout);
                	break;
                }
                
            case 'E':                                  //Checks empty function.
                empty = obj1.empty();
                
                if(empty == 1)
                {
                    cout << "List is empty" << endl;
                }
                else
                {
                    cout << "List is not empty" << endl;
                }
                break;
                
            case 'P':                                 //Print the entire list.
                obj1.display(cout);
                break;
                
            case 'I':       //Inserts a name into the list at a given position.
                cout << "Please enter a name to insert into the list: "<< endl;
                cin >> name;
                cout << "Please enter a position" << endl;
                cin >> position;
                obj1.insert(name, position);
                break;
                
            case 'F': //Searches for name on the list
					  // and returns position on the list.
                cout << "Enter the name you are looking for: " 
				<< endl;
                cin >> name;
                indexFound = obj1.find(name);
                cout << "The number was found in the position "
				<< indexFound << endl;
                break;
                
                
            case 'R':               //Removes name from list at given position.
                cout << "Enter a position to remove the name from the list: "
				<< endl;
                cin >> position;
                obj1.erase(position);
                break;
                
            case 'Q':
            	break;	
        }
        
    }
    
    while((command != 'Q'));
}

/***** Print a menu *****/
void printMenu()
{
    cout << "========================================================" << endl;
    cout << "THE FOLLOWING CHOICES ARE AVAILABLE: " << endl;
    cout << "\n";
    cout << "A --> Append 3 strings to the list" << endl;
    cout << "S --> Display the list size" << endl;
    cout << "C --> Print the result from using the copy constructor" << endl;
    cout << "O --> Print the result from using the assignment operator" <<endl;
    cout << "E --> Print the result from the empty function" << endl;
    cout << "P --> Print the entire list" << endl;
    cout << "I --> Insert a new item with the insert(...) function" << endl;
    cout << "F --> Find an item with the find() function" << endl;
    cout << "R --> Remove an item with the erase() function" << endl;
    cout << "Q --> Quit "<< endl;
    cout << "========================================================" << endl;
}

