//Programmer: Jose Gutierrez
//Project Number: 6
//Project Desc: Search Binary Trees
//Course: Data Structures
//Date: Nov. 04, 2015

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <time.h>		// Provides time
#include "BST.h"  

using namespace std;
 
// PROTOTYPES:
void printMenu( );
// Postcondition: A menu of choices has been printed.
/*----------------------------------------------------*/
void display(ostream & out, BST<int> & obj);
/* Displays the items in the list in order, the height 
of a tree and the number of leaves in a tree.
Precondition: Tree is not empty. Ostream is open.
Postcondition: Prints the items in the list, height
and the number of leaves.
------------------------------------------------------*/
 
int main( )
{
    srand(time(0));		//Seeds rand function with time.
    BST<int> intBST;	// A BST to perform tests on
    char choice;   		// Command entered by the user
    int randomNum, num, counter, userItem;
    bool check;
    cout << "I have initialized an empty BST of int." << endl;
 
    do
    {
        printMenu( );
        cout << "Enter choice: ";
        cin >> choice; 
        choice = toupper(choice);
        
        switch (choice)
        {
            case 'A': // prompt the user for a number n
					  // and insert n random numbers 0-999 into the tree
                cout << "How many numbers would "
				   	 << "you like to add to the list?" << endl;
                cin >> num;
                for(counter = 0; counter < num; counter ++)
                {
                    randomNum = (rand() % 1000);
                    intBST.insert(randomNum);
                }
                break;
                
			case 'H': // print the result of height()
                num = intBST.height();
                cout <<"Height of the BST: " << num << endl;
                break;
                
            case 'L': // print the result of leafCount()
                num = intBST.leafCount();
                cout << "Number of leaves in the BST: " << num << endl;
                break;
                
            case 'G': //  print the result of graph()
                intBST.graph(cout);
                break;
            case 'E': // print the result of empty( )
                check = intBST.empty();
                if (check == true)
                {
                    cout << "The list is empty" << endl;
                }
                else
                {
                    cout << "List is not empty" << endl;
                }
                
                break;
            case 'P': // print the result of inorder(), 
					  //height() and leafCount() with labels
                display(cout,intBST);
                break;
                
            case 'I': //  insert a user given
					  // item into the tree using insert()
                cout << "Please enter the number to be " 
				     <<"added to the list" << endl;
                cin >> userItem;
                intBST.insert(userItem);
                break;
                
            case 'S': // search for a user given item in the 
					  //tree using search() and print result
                cout << "Please enter the number you are looking for " << endl;
                cin >> userItem;
                check = intBST.search(userItem);
                if (check == true)
                {
                    cout << "Item was found on the list " << endl;
                }
                else
                {
                    cout << "Item not found " << endl;
                }
                break;
                
            case 'R': //  remove a user given  item in the tree using remove()
                cout << "Please enter the number you wish to remove " << endl;
                cin >> userItem;
                intBST.remove(userItem);
                break;
                
            case 'Q': cout << "Test program ended." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));
 
    return EXIT_SUCCESS;
}


void display(ostream & out, BST<int> & obj)
{
    if(!obj.empty())
    {
        obj.inorder(cout);
        out << endl;
        out << "Height: " << obj.height() << endl;
        out << "Leaves: " << obj.leafCount() << endl;
    }
    else
    {
        cerr << "The list is emptty" << endl;
    }
}
void printMenu( )
{
    cout << endl; 
    cout << "The following choices are available: " << endl;
    cout << " A   Add n random numbers to the tree" << endl;
    cout << " H   Print the height of the tree" << endl;
    cout << " L   Print the leaf count of the tree" << endl;
    cout << " G   Print a graph of the tree using graph()" << endl;
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print the entire tree,  height, and the leaf count" << endl;
    cout << " I   Insert a new item with the insert() function" << endl;
    cout << " S   Find an item with the search( ) function" << endl;
    cout << " R   Remove an item with the remove( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
}
