//****************************************************************
//
//  HASH TABLE PROGRAM
//
//  The Table class uses Chaining
//	and allows insertions.
//	To be added:
//		a) erase
//		b) print
//
//*****************************************************************


#include <iostream>
#include <iomanip>

using namespace std;

#include "DRV_HWCH.h"

void printMenu( );

int capacity(int capacity, const Table &size);

int main( )
{
    char choice;   		// Command entered by the user
    Table dataTable;	// A table to perform tests on
    RecordType rec;
    int key;
    bool found;
    int size ,  number , spotsLeft;
    
    
    
    
    for (int i= 0; i < 40; i++)
    {rec.key = (rand() % 100);
        rec.data = (rand() % 100);
        dataTable.insert(rec);
    }
    
    
    
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
                    cout << "   key  = " << setw(8)
                    << rec.key << endl;
                    cout << "   data = " << setw(8)
                    << rec.data << endl;
                }
                else
                    cout << "Record with key " << key << " not found."
                    << endl << endl;
                break;
            case 'D': // delete
                cout << "Enter key (int >= 0) to delete: ";
                cin >> key;
                dataTable.find( key, found, rec );
                if ( found )
                {
                    cout << "Which record to delete?" << endl;
                    cin >> number;
                    dataTable.erase(key,number);
                }
                else
                {
                    cerr<< "Record not found" << endl;
                }
                break;
                
            case 'S': // size
                size = dataTable.size( );
                cout << "There are " << size << " records in the table."
                << endl;
                spotsLeft = capacity(CAPACITY, dataTable);
                cout << "There are " << spotsLeft
                     << " empty slots left in the table." << endl << endl;
                break;
            case 'P': // print table
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

int capacity(int capacity, const Table &dataTable){
    
    
    int size = dataTable.size();
    if (size > capacity)
    {
        return 0;
    }
    else
    {
        return capacity - size;
    }
    
}


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