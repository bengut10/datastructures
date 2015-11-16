#include <iostream>
#include "List.h"
#include <cassert>
using namespace std;

//======================================================================
//Definition of List Constructor
List::List()
{
    first = NULL;
    mySize = 0;
}

//======================================================================
//Definition of List Copy Constructor
List::List(const List &source)
{	
	first= 0;
	mySize = source.mySize;
    
    if(!source.empty())
    {
    	first = new List::Node(source.getFirst());
    	
        List::NodePointer lastPtr = first;
        List::NodePointer origPtr = source.first->next;
    
        while(origPtr != 0)
        {
            lastPtr->next = new List::Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}

//======================================================================
//Definition of List Destructor
List::~List()
{
    List::NodePointer current = first;
    List::NodePointer nextPtr;
    
    while(current !=0)
    {
        nextPtr = current->next;
        delete current;
        current = nextPtr;
    }
}
//======================================================================
//Definition of getSize
int List::getSize() const
	{
	  return mySize;
	}


//======================================================================
//Definition of Assignment operator
List & List::operator=( const List &rightSide )
{
    if (this != &rightSide)
    {
        this->~List();
        
        if(rightSide.empty())
        {
            first = NULL;
        }
        else
        {
        	mySize = rightSide.mySize;
            first = new List::Node(rightSide.getFirst());
            List::NodePointer lastPtr = first;
            List::NodePointer rhsPtr = rightSide.first->next;
            
            while(rhsPtr != 0)
            {
                lastPtr->next = new List::Node(rhsPtr->data);
                lastPtr = lastPtr->next;
                rhsPtr = rhsPtr->next;
                
            }
        }
    }
    
    return *this;
}

//======================================================================
//Definition of empty
bool List::empty( ) const
{
    bool empty;
    if(first != NULL)
    {
        empty = false;
        
    }
    else
    {
        empty = true;
    }
    return empty;
}

//======================================================================
//Definition of display list
void List::display(ostream &out )const
{    
	
    Node *ptr = first;
    while(ptr != NULL)
    {
        out <<"Name: " << ptr->data << endl;
        ptr = ptr->next;
    }
    
   	out<< "Current size of the list: " << mySize << endl;
    out << endl;
}

//======================================================================
//Definition of display size
void List::displaySize(ostream &out)const
{
	out<< "Current size of the list: " << mySize << endl;
}


//======================================================================
//Definition of insert
void List::insert( ElementType dataVal, int index )
{
    Node * ptr = first;
	Node * predPtr = NULL;
	Node * newPtr = new Node(dataVal);
	
	while(ptr!= 0)
	{
		predPtr = ptr;
		ptr = ptr->next;
	}

	if(predPtr != 0)
	{
	

			newPtr->next = predPtr->next;
			predPtr->next = newPtr;

	}
	
	else
	{
	newPtr->next = first;
	first = newPtr;
	}
	mySize++;
}


//======================================================================
//Definition of Find
int List::find( ElementType value) const
{
    
    Node* current = first;
    int temIndex = 0;
    int number;
    
    if(first != NULL)
    {
        while (temIndex != mySize)
        {
            if(current->data == value)
            {
                number = temIndex;
                break;
            }
            else
            {
                number = -1;
            }
            
            current = current->next;
            temIndex++;
        }
    }
    return number;
    
}

//======================================================================
//Definition of Erase
void List::erase(int index)
{
    Node* current;
    Node* previous = 0;
    
    int temIndex = 0;
    current = first;
    
    if (empty() == true)                          //Precondition Check
    {
        cerr << "*** Error: Empty List ***"<< endl;
        return;
    }
    
    else
    {
        while (current->next != NULL && temIndex != index)
        {
            previous = current;
            current = current->next;
            temIndex++;
        }
        
        if(index > temIndex)
        {
            cerr << "INVALID: ILLEGAL POSITION" << endl;
            return;
        }
        else if (index == 0)
        {
            current = first;
            first = current->next;
        }
        else
        {
            current = previous->next;
            previous->next= current->next;
        }
        
        delete current;
    }
    mySize--;
}
//======================================================================
//Definition of getFirst
ElementType List::getFirst() const
{
	if(!empty())
	{
		return (first->data);
	}
	
	else
	{
		ElementType* temp = new(ElementType);
		ElementType garbage = *temp;
		delete temp;
		return garbage;
	}
}
