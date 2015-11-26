//****************************************************************
//  Programmer: Jose Gutierrez
//  Project Number: 7
//  Hash Tables: Linear Probing
//  Data Structures
//  11/23/15
//
//  HASH TABLE PROGRAM
//
//  The Table class uses linear probing 
//	and allows insertions. 
//	To be added:	
//		a) erase
//		b) print
//*****************************************************************


#include <iostream>
#include <iomanip>
#include "hash_lp.h"

using namespace std;

//*****************************************************************
//Print menu function.
//Precondition: None
//Postcondition: Prints out driver menu.
//*****************************************************************
void printMenu( );

int main( )
{
   
    char choice;		// Command entered by the user
    Table dataTable;	// A table to perform tests on
    RecordType rec;
    int key;
    bool found;
    int size;
    
    do
    {
        printMenu( );
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl; 
        choice = toupper(choice);
        
        switch (choice)
        {
            case 'I': // insert
                      cout << "Enter key (int >= 0) for record: ";
                      cin >> rec.key;
                      cout << "Enter data (int) for record: ";
                      cin >> rec.data;
                      dataTable.insert( rec );
                      cout << "Record was inserted in table" << endl << endl;
                      break;
            case 'F': // find
                      cout << "Enter key (int >= 0) to search for: ";
                      cin >> key;
                      dataTable.find( key, found, rec );
                      if ( found )
                      {
                         cout << "Record was found." << endl;
                         cout << "   key            = " << setw(8) 
                              << rec.key << endl;
                         cout << "   data = " << setw(8) 
                              << rec.data << endl << endl;
                      }
                      else
                         cout << "Record with key " << key << " not found." 
                              << endl << endl;
                      break;
            case 'D': // delete
                      cout << "Enter key (int >= 0) to delete: ";
                      cin >> key;
                      dataTable.erase( key );
                      break;
            case 'S': // size
                      size = dataTable.size( );
                      cout << "There are " << size << " records in the table." 
                           << endl;
                      cout << "There are " << (CAPACITY - size) 
                           << " empty slots left in the table." << endl << endl;
                      break;
            case 'P': // print
                      dataTable.print();
                      break;
            case 'Q': cout << "Test program ended." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));
    
    return 0;
}
//Print menu definition
void printMenu( )
{
    cout << endl; 
    cout << "The following choices are available: " << endl;
    cout << " I   Insert a new record or update existing record" << endl;
    cout << " F   Find a record" << endl;
    cout << " D   Delete a record" << endl;
    cout << " S   Get the number of records" << endl;
    cout << " P   Print the contents of the table" << endl;
    cout << " Q   Quit this test program" << endl << endl;
}
