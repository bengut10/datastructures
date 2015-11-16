#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "DRV_HWCH.h"

Table::Table( )
{
    used = 0;
    for ( int i = 0; i < CAPACITY; i++ )
        table[i] = NULL;
}

void Table::insert( const RecordType& entry )
{
    bool alreadyThere;
    Node* nodePtr;
    
    assert( entry.key >= 0 );
    
    findPtr( entry.key, alreadyThere, nodePtr );
    if( !alreadyThere )
    {
        int i = hash( entry.key );      // get index of "bucket" where entry belongs
        // insert at beginning of list
        Node* temp = new Node;
        temp->rec = entry;      // copy record
        temp->next = table[i];
        table[i] = temp;
        used++;
    }
    else
    {
        // nodePtr points to existing record that should be updated
        nodePtr->rec = entry;
    }
}

void Table::print()
{
    cout << "Index      Key       Data:" << endl;
    cout << "-------------------------------" << endl;
    
    for(int i = 0; i < CAPACITY; i++)
    {
        Node * ptr = table[i];
        
        if(table[i] != NULL)
        {
            
            cout << "\n";
            cout << setw(3) << i << setw(10) << table[i]->rec.key << setw(10);
        }
        
        while (ptr != NULL)
        {
            cout << ptr->rec.data << setw(4) ;
            ptr = ptr->next;
        }
        
    }
}

void Table::erase(int key, int number)
{
    assert( key >= 0 );
    int i = 0;
    bool element = false;
    Node * first;
    Node * previous;
    
    i = hash(key);
    first =   table[i];
    
    if(table[i]->rec.data == number && table[i]->next == NULL)
    {
        table[i] = NULL;
        delete table[i];
        used --;
    }
    
    else
    {
        while(first != NULL)
        {
            if(first->rec.data == number)
            {
                element = true;
                first->rec = table[i]->rec;
                previous = table[i];
                table[i] = table[i]->next;
                delete previous;
                used --;
            }
            first = first->next;
        }
        
        if(element == false)
        {
            cerr << "The element was not found in the record" << endl;
        }
    }

}

int Table::hash( int key ) const
{
    return key % CAPACITY;
}

int Table::size( ) const
{
    return used;
}

// findPtr function
//     void findPtr( int key, bool& found, Node*& nodePtr ) const;
// Preconditions:  key >= 0
// Postconditions: If a record with the indicated key is in the table,
//    then found is true and nodePtr is set to point to that record.
//    Otherwise, found is false and nodePtr contains garbage.

void Table::findPtr( int key, bool& found, Node*& nodePtr ) const
{
    int i;
    Node* ptr;
    
    i = hash( key );
    ptr = table[i];
    found = false;
    while ( !found && ptr != NULL )
    {
        if ( key == ptr->rec.key )
        {
            found = true;
            nodePtr = ptr;
        }
        ptr = ptr->next;
    }
    if ( !found )
        nodePtr = NULL;
}

void Table::find( int key, bool& found, RecordType& result ) const
{
    Node* nodePtr;
    
    assert( key >= 0 );
    
    findPtr( key, found, nodePtr );
    if ( found )
    {
        result = nodePtr->rec;
    }
}