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

#include "hash_chn.h"

void printMenu( );

int main( )
{
    char choice;   		// Command entered by the user
    Table dataTable;	// A table to perform tests on
    RecordType rec;
    int key;
    bool found;
    int size ,  number;
    
    
    
    
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
                      cout << "Which record to delete?" << endl;
                      cin >> number;
                      dataTable.erase(key,number);
                      break;
                      
            case 'S': // size
                      size = dataTable.size( );
                      cout << "There are " << size << " records in the table." 
                           << endl;
                     // cout << "There are " << (CAPACITY - size) 
                     //      << " empty slots left in the table." << endl << endl;
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
/*

The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice: i

Enter key (int >= 0) for record: 620
Enter data (int) for record: 620
Record was inserted in table


The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice: i

Enter key (int >= 0) for record: 64
Enter data (int) for record: 64
Record was inserted in table


The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice: i

Enter key (int >= 0) for record: 128
Enter data (int) for record: 128
Record was inserted in table


The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice: i

Enter key (int >= 0) for record: 467
Enter data (int) for record: 467
Record was inserted in table


The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice: i

Enter key (int >= 0) for record: 777
Enter data (int) for record: 777
Record was inserted in table


The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice: i

Enter key (int >= 0) for record: 35
Enter data (int) for record: 35
Record was inserted in table


The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice: i

Enter key (int >= 0) for record: 127
Enter data (int) for record: 127
Record was inserted in table


The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice: i

Enter key (int >= 0) for record: 282
Enter data (int) for record: 282
Record was inserted in table


The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice: p

Print the contents of the table.
The hash table is:
Index  Key/Data
    0  620/620
    1
    2  777/777  467/467   64/64
    3  282/282  127/127
    4   35/35  128/128
    5
    6
    7
    8
    9
   10
   11
   12
   13
   14
   15
   16
   17
   18
   19
   20
   21
   22
   23
   24
   25
   26
   27
   28
   29
   30

The following choices are available:
 I   Insert a new record or update existing record
 F   Find a record
 S   Get the number of records
 P   Print the contents of the table
 Q   Quit this test program

Enter choice:

*/
