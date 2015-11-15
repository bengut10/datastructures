/* Programmer: Jose Benjamin Gutierrez
 * Project Number: 2
 * Project Description: Quadratic Expressions
 * Course: Data Structures - COSC2436
 * Date: 09/04/2015
 */

#include <iostream>
#include <cmath>
#include "Quadratic.h"

using namespace std;

//----------------------------------------------------------------------------------------------
void menu();
/* this is the function to display the main menu 
Precondition: None

Post Condition: Displays menu with 9 options */

//----------------------------------------------------------------------------------------------


int main()
{
   
    Quadratic q1,q2,q3,q4;                                //Declaration of objects
    
    float a1, b1, c1, xValue, smallRoot, bigRoot;         //Declaration of variables.
    double r;
    char choice;
    
    cout << "A quadratic called q1 has been created and initialized to a default value." << endl;
    
    menu();
    
    do
        
    {
        cout << "\nEnter your choice: ";
        cin  >> choice;
        
        if (choice == '1')
        {
            // code to test display() function (if you wrote one, probably a good idea)
            q1.display();
        }
        
        else if (choice == '2')
        {
            // code to test get functions
            cout << "--------------------\n";
            cout << "A has been set to: " <<q1.getA() << endl;
            cout << "B has been set to: " <<q1.getB() << endl;
            cout << "C has been set to: " <<q1.getC() << endl;
            cout << "--------------------\n";
        }
        
        else if (choice == '3')
        {
            // code to test set function
            cout << "Enter value for a: " << endl;
            cin  >> a1;
            cout << "Enter value for b: " << endl;
            cin  >> b1;
            cout << "Enter value for c: " << endl;
            cin  >> c1;
            q1.setQuadratic(a1, b1, c1);
        }
        
        else if (choice == '4')
        {
            // code to test evaluate function
            cout << "Enter a value for x: "<< endl;
            cin  >> xValue;
            q1.evaluate(xValue);
            cout << endl;
            q1.display();
            cout << "And when x = " << xValue << ", the solution is: " << q1.evaluate(xValue);
            cout << endl;
        }
        
        else if (choice == '5')
        {
            // code test number of roots function
            q1.numRoots(q1);
            
            if ((q1.numRoots(q1) == 0))
            {
                cout << "There are no roots";
            }
            
            else if ((q1.numRoots(q1) == 1))
            {
                cout << "There is only one real root";
            }
            
            else if ((q1.numRoots(q1) == 2))
            {
                cout << "There are two real roots";
            }
            else if ((q1.numRoots(q1) == 3))
            {
                cout << "Every value of X is a real root";
            }
        }
        
        else if (choice == '6')
        {
            // code to test small root and large root functions
            
            if ((q1.numRoots(q1) == 1) || (q1.numRoots(q1) == 2) || (q1.numRoots(q1)== 3))
            {
                smallRoot = q1.minRoot(q1);
                bigRoot = q1.maxRoot(q1);
                cout << "The roots of the quadratic equation are: " << bigRoot
                << " and " << smallRoot;
            }
            else
            {
                cerr << "The expression has no real roots \n";
                cerr << "please change the value of the coefficients";
            }
        }
        
        
        else if (choice == '7')
        {
            // code to test the addition operator
            // create a second quadratic from user inputted coefficients
            // and display the sum of q1 and the second quadratic
            
            cout << "Please enter a for the second quadratic: " << endl;
            cin >> a1;
            cout << "Please enter b for the second quadratic: " << endl;
            cin >> b1;
            cout << "Please enter c for the second quadratic: " << endl;
            cin >> c1;
            q2.setQuadratic(a1, b1, c1);
            q3 = q1 + q2;
            q3.display();
        }
        
        else if (choice == '8')
        {
            // code to test multiplication operator
            // and display the result
            cout << "Please enter a floating point value: ";
            cin  >> r;
            q4 = r * q1;
            q4.display();
        }
        
        else
            cout << "Not a valid option\n";
        
    } while (choice != '9');
    
    return 0;
}

//----------------------------------------------------------------------------------------------
// Menu function definition
void menu()
{
    cout << "Please choose one of the following:\n"
    << "-----------------------------------------------------------------------\n"
    << "   1 - Display q1\n"
    << "   2 - Display the coefficients of q1\n"
    << "   3 - Modify the coefficients of q1\n"
    << "   4 - Display the value of q1 at a given value of x\n"
    << "   5 - Display the number of roots for q1\n"
    << "   6 - Display the roots of q1\n"
    << "   7 - Display the sum of q1 and a second quadratic\n"
    << "   8 - Display the product of q1 and a given floating-point value\n"
    << "   9 - Exit \n"
    << "-----------------------------------------------------------------------"<<endl;
}
//----------------------------------------------------------------------------------------------
