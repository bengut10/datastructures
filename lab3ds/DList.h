/*-- DList.h --------------------------------------------------------------
 
 This header file defines the data type List for processing lists.
 Basic operations are:
 Constructor
 Destructor
 Copy constructor
 Assignment operator
 empty:    Check if list is empty
 insert:   Insert an item
 erase:    Remove an item
 display:  Output the list, size and capacity.
 << :      Output operator
 resize: Changes the list's capacity.
 
 The list's capacity starting value is 10. Capacity will always be large 
 enough as it is always resized by multiplying the current capacity *2.
 Starting with capacity makes it easier for testing purposes.
 -------------------------------------------------------------------------*/

#include <stdio.h>
#include <iostream>
#ifndef DLIST
#define DLIST
using namespace std;


typedef int ElementType;
class List
{
    
private:
    /******** Data Members ********/
    
    int mySize;                     //Current size of the array
    int myCapacity;                 //Capacity of the array
    ElementType * myArray;          //Pointer to dynamic array
    
public:
    /******** Function Members ********/
    
    /***** Class constructor *****/
    List(int maxSize = 10);
    /*----------------------------------------------------------------------
     Construct a List object.
     
     Precondition:  maxSize is a positive integer with default value 1024.
     Postcondition: An empty List object is constructed; myCapacity ==
     maxSize (default value 1024); myArray points to a dynamic
     array with myCapacity as its capacity; and mySize is 0.
     -----------------------------------------------------------------------*/
    
    
    /***** Class destructor *****/
    ~List();
    /*----------------------------------------------------------------------
     Destroys a List object.
     
     Precondition:  The life of a List object is over.
     Postcondition: The memory dynamically allocated by the constructor
     for the array pointed to by myArray has been returned to the heap.
     -----------------------------------------------------------------------*/

    
    /***** Copy constructor *****/
    List(const List & origList);
    /*----------------------------------------------------------------------
     Construct a copy of a List object.
     
     Precondition:  A copy of origList is needed; origList is a const
     reference parameter.
     Postcondition: A copy of origList has been constructed.
     -----------------------------------------------------------------------*/
    

    /***** Assignment operator *****/
    List & operator=(const List & rightHandSide);
    /*----------------------------------------------------------------------
     Assign a copy of a List object to the current object.
     
     Precondition: none
     Postcondition: A copy of rightHandSide has been assigned to this
     object. A reference to this list is returned.
     -----------------------------------------------------------------------*/
   
   
    /****** Empty Operation ******/
    bool empty() const;
    /*----------------------------------------------------------------------
     Check if a list is empty.
     
     Precondition: None.
     Postcondition: True is returned if the list is emty, false if not.
    -----------------------------------------------------------------------*/
    
    
    /***** Insert operation *****/
    void insert(ElementType item, int pos);
     /*----------------------------------------------------------------------
      Insert a value into the list at a given position.
      
      Precondition: If capacity is not available for the item to be inserted
      the current capacity is resized by two with the resize function. The
      position must satisfied 0 <= pos <= mySize. Numbers are also to be 
      between 0 and 999 only.
      Postcondition: Item(s) has been inserted into the list at the position
      determined by pos (Provided is a legal position).
     -----------------------------------------------------------------------*/
    
    
    /***** Erase operatio *****/
    void erase(int pos);
     /*----------------------------------------------------------------------
      Remove a value from a list at a given position.
      
      Precondition: The list is not empty and the position satisfies 
      0 <= pos <= mySize.
      Postcondition: element at the position determined by pos is removed
      (provided pos is a legal position).
     -----------------------------------------------------------------------*/
    
    
    /***** output *****/
    void display(ostream & out) const;
     /*----------------------------------------------------------------------
      Display a list, it's capacity and size.
    
      Precondition: The ostream out is open.
      Postcondition: The list represented by this object has been inserted 
      into out.
     -----------------------------------------------------------------------*/
    
    
    
    /***** resize operation *****/
    void resize(int newCapacity);
    /*----------------------------------------------------------------------
     Change the capacity of a list
     Precondition: None.
     Postcondition: The list's current capacity is changed to newCapacity
     (but not less than the number of items already in the list).
     -----------------------------------------------------------------------*/
    
    
    
    /***** returns the value of mySize *****/
    int getSize();
    /*----------------------------------------------------------------------
     Return the value of a variable!
     Precondition: None.
     Postcondition: Returns the size of a private member variable of a list.
     (mySize).
     -----------------------------------------------------------------------*/
    
    
}; //--- end of List class

//------ Prototype of output operator
ostream & operator<< (ostream & out, const List & aList);


#endif /* defined(__lists__list__) */
