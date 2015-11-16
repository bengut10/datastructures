// Programmer: Jose Gutierrez
// Project Number: 5
// Project Desc: Evaluating Postfix Expressions
// Course: Data Structures
// Date: Oct 20, 2015

#include <iostream>
#include "LStack.h"
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


int addNums(Stack & obj);
/* Add two numbers 

Precondition: An onject is passed to the function by reference.
Postcondition: Pops 2 numbers from the stack, adds them, pops
them off the stack and returns the value.
*/

int subtractNums(Stack & obj);
/* Subtract two numbers 

Precondition: An onject is passed to the function by reference.
Postcondition: Pops 2 numbers from the stack, subtracts them, pops
them off the stack and returns the value.
*/

int multiplyNums(Stack & obj);
/* Multiply two numbers 

Precondition: An onject is passed to the function by reference.
Postcondition: Pops 2 numbers from the stack, multiplies them, pops
them off the stack and returns the value.
*/

int divideNums(Stack & obj);
/* Divide two numbers 

Precondition: An onject is passed to the function by reference.
Postcondition: Pops 2 numbers from the stack, divides them, pops
them off the stack and returns the value.
*/

void evaluateExp(Stack & obj, string expression);
/*Evaluates the string
Precondition: RPN expression must be valid, else error. 
Stack must be empty.
Postcondition: Evaluates the values from the string and determines
whether they are an operand or operator. Calls functions that manage the stack.
*/

void clearStack(Stack & obj);
/*Clears the stack
Precondition: stack is not empty.
Postcondition: pops all values from the stack if an error was encounterred or
a new expression is given.
*/

string removeSpaces(string temp);
/*Removes spaces in the string
Precondition: A string is passed.
Postcondition:  Uses an iterator from the Stl. and removes all spaces from 
the string. Returns a new string.
*/

int main()
{
	Stack obj;
	string temp, exp;
	char keepGoing;



	do 
	{
		cout << "=================================" << endl;
		cout << "Enter postfix expression" << endl;
		getline(cin,temp);
		exp = removeSpaces(temp);
		cout << "=================================" << endl;

		evaluateExp(obj, exp);
		
		if(!obj.empty())
		{
			cout << "The value of the expression is "; obj.display(cout);
			cout << endl;
		}
		
		cout << "More expressions?" << endl;
		cin >> keepGoing;
		cin.ignore();
		keepGoing = toupper(keepGoing);
	}
	
	while(keepGoing == 'Y');

}

//evaluates the expression, if errors clears the stack...
void evaluateExp(Stack & obj, string exp)
{	
	int value, num1, num2;
	int i, opCount = 0;
	char token;
	
	clearStack(obj);
	
	for(i = 0; i < exp.length(); i++)
	{
		// checks to see if is an operator. Also checks that there
		// is at least two operands before a function is called.
		if((exp.at(i) == '+')
		&& (((i+1) - opCount) < opCount) && (opCount >= 2))
		{
			addNums(obj);	
		}
		
		else if((exp.at(i) == '-') 
		&& (((i+1) - opCount) < opCount) && (opCount >= 2))
		{
			subtractNums(obj);
		}
	
		else if((exp.at(i) == '*') 
		&& (((i+1) - opCount) < opCount) && (opCount >= 2))
		{
			 multiplyNums(obj);
	
		}
		else if((exp.at(i) == '/') 
		&& (((i+1) - opCount) < opCount) && (opCount >= 2))
		{
			divideNums(obj);
		}
		
		else   // is an operand... check to see if its valid!
		{
			token = exp.at(i);
			value = token - 48;
			
			if (value > -1 and value < 10)
			{
				obj.push(value);
				opCount++;
			} 
			else 	
			{
				cerr << "*** Invalid expression ***" << endl;
				clearStack(obj);
				break;
			}
	 	}
	} 
	
	if((opCount - (i - opCount)) > 1 ) //last check for valid expression
	{
		cerr << "*** Invalid expression ***" << endl;
		clearStack(obj);
	}
}



//Definition of evaluate
string removeSpaces(string temp)
{
	temp.erase(remove(temp.begin(),temp.end(),' '),temp.end());
	return temp;
}


//Definition of clearStack
void clearStack(Stack & obj)
{
	while(!obj.empty())
	{
		obj.pop();
	}
}

//Definition of addNums
int addNums(Stack & obj)
{
	
	int result;
	int num1, num2;
	num1 = obj.top();
	obj.pop();
	num2 = obj.top();
	obj.pop();
	result = num2+num1;
	obj.push(result);
	return result;
}

//Definition of subtractNums
int subtractNums(Stack & obj)
{
	int result;
	int num1,num2;
	num1 = obj.top();
	obj.pop();
	num2 = obj.top();
	obj.pop();
	result = num2-num1;
	obj.push(result);
	return result;
}


//Definition of multiplyNums
int multiplyNums(Stack & obj)
{
	int result;
	int num1,num2;
	num1 = obj.top();
	obj.pop();
	num2 = obj.top();
	obj.pop();
	result = num2*num1;
	obj.push(result);
	return result;
}


//Definition of divideNums
int divideNums(Stack & obj)
{
	int result;
	int num1, num2;
	num1 = obj.top();
	obj.pop();
	num2 = obj.top();
	obj.pop();
	result = num2/num1;
	obj.push(result);
	return result;
}
