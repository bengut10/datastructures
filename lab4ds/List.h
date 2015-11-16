/*-- List.h --------------------------------------------------------------
 This header file defines the data type List for processing  linked lists.
 Basic operations are:
 Constructor
 Destructor
 Copy constructor
 Assignment operator
 empty:    Check if list is empty
 insert:   Insert an item(s)
 erase:    Remove an item
 display:  Output the list.
 Display size: Output the size of the list.
 
 The linked list of names is set to 5 initial values (strings).
 -------------------------------------------------------------------------*/

#ifndef __Lab4datagood__List__
#define __Lab4datagood__List__
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

typedef string ElementType;

class List
{
    
private:
    
    class Node
    {
    public:
        ElementType data;
        Node * next;
        
        Node( )
        {
            data = ElementType( );
            next= NULL;
        }
        
        Node( ElementType initData )
        {
            data = initData;
            next = NULL;
        }
        
    };
    
    typedef Node * NodePointer;
    NodePointer first;
    int mySize;
    
    
public:
	
    List( );
    /* Construct a List object
     
     Precondition: none.
     Postcondition: An empty List object has been constructed.
     */
    
    List( const List &source );
    /* Construct a copy of a List object.
     
     Precondition: None.
     Postcondition: A copy of source has been constructed.
     */
    
    ~List( );
    /* Destroys a List object.
     
     Precondition:  None.
     Postcondition: Any memory allocated to the List object has been freed.
     */
    
    List & operator=( const List &rightSide );
    /* Assign a copy of a List object to the current object.
     
     Precondition: none
     Postcondition: A copy of rightside has been assigned to this
     object. A reference to this list is returned.
     */
    
    int getSize( ) const;
    /* Returns the size of the list (number of items in the list)
     
     Precondition: none
     Postcondition: The return value is the number of items in the list.
     */
    
    bool empty( ) const;
    /* Check if this List is empty
     
     Precondition: none
     Postcondition: The return value is true if this List object is empty;
     otherwise the return value is false.
     */

    void insert( ElementType dataVal, int index );
    /* Insert a value into this List at a given index
     
     Precondition:  The index is valid (0 <= index <= the list size).
     The first position is index 0, the second position is index 1, etc.
     Postcondition: dataval has been inserted into the list at the position
     determined by index (provided there is room and index is a legal
     position).
     */
    
    void erase( int index );
    /* Remove the value from this List at a given index.
     
     Precondition:  The list is not empty and index is valid
     (0 <= index < the list size).
     Postcondition: the element at position index has been
     removed (provided index is a legal position).
     */

    void display(ostream &out ) const;
    /* Display the contents of this List
     
     Precondition:  ostream out is open
     Postcondition: the items in this List have been output to stream out
     */
    
    int find( ElementType value) const;
    /* Find the first occurrence of a value in this List
     
     Preconditions:  None
     Postconditions: The return value is the index of the first List item
     that matches value. The first list item has index 0, the second has
     index 1, etc. The return value is -1 if value is not found in the list.
     */

     void displaySize(ostream &out) const;
    /* Display the size of this List
     
     Precondition:  ostream out is open
     Postcondition: the size of this List has been output to stream out
     */
	
	
	ElementType getFirst() const;
	/* Returns the first element in the list
	
	Precondition: The list contains at least one element.
	PostCondition: Returns the data in the first element of the list.
	*/
	
};

#endif
