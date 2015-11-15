//
//  Quadratic.cpp
//  Quadratic Expressions
//
//  Created by Jose Benjamin Gutierrez on 9/3/15.
//  Copyright (c) 2015 Jose Benjamin Gutierrez. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "Quadratic.h"
using namespace std;


// Function Quadratic is a user defined constructor which sets values for
//a,b and c to 0.
Quadratic::Quadratic()
{   a= 0;
    b= 0;
    c= 0;
};



// Function setQuadratic sets private member variables to new variables.
void Quadratic::setQuadratic(float newa, float newb, float newc)
{
    a = newa;
    b = newb;
    c = newc;
    
}

//Function display() displays the expression of a quadratic.
void Quadratic::display()
{	
	cout << "A quadratic expression has been set to: ";
    cout << a << "(x)^2" << " + " << b << "(x) + " << c << endl;
}


//Function getA returns a (our private member variable).

float Quadratic::getA()const
{
    return a;
}

// function getB returns b (our private member variable).
float Quadratic::getB()const
{
    return b;
}

//function getC returns c (out private member variable).
float Quadratic::getC()const
{
    return c;
}

//Function evaluate takes in a value for x and evaluates the expression.
float Quadratic::evaluate(float x)const
{
    float result;
    result = ((a)*pow(x,2))+(b * x) + c;
    return result;
}

//Function numRoots receives an object as an arguement and returns
// the number of of roots a given expression has.
int Quadratic::numRoots(Quadratic &q1)const
{
    int num;
    
    if((q1.a == 0) && (q1.b == 0) && (q1.c == 0))
    {
        num = 3;
        
    }
    else if((q1.a == 0) && (q1.b ==0) && (q1.c != 0))
    {
        num = 0;
    }
    
    else if(((q1.a) == 0) && (q1.b != 0))
    {
        num = 1;
        
    }
    
    else if((q1.a != 0) && (pow(q1.b,2) < (4*(q1.a)*(q1.c))))
    {
        num = 0;
        
    }
    else if((q1.a != 0) && (pow(q1.b,2) == (4*(q1.a)*(q1.c))))
    {
        num = 1;
    }
    
    else if((q1.a != 0) && (pow(q1.b,2) > (4* q1.a * q1.c)))
    {
        num = 2;
    }
    
    return num;
    
}

//Function minRoot determines the smaller root in a given expression, if
//infinte number of expressions it returns 0.
float Quadratic::minRoot(Quadratic &q1)const
{
    float minroot;
    
    while(q1.numRoots(q1) == 1)
    {
        if(((q1.a) == 0) && (q1.b != 0))
        {
            minroot = ((q1.c) * (-1)) / q1.b;
        }
        else
        {
            minroot = ((q1.b) * (-1)) / ((2) * (q1.a));
        }
        return minroot;
    }
    
    if (q1.numRoots(q1) == 2)
        
    {
        minroot = ((-1 * q1.b) + sqrt((pow(q1.b,2)-(4 * q1.a * q1.c)))) / (2 * q1.a);
    }
    
    
    else if (q1.numRoots(q1) == 3)
    {
        minroot = 0;
    }
    
    return minroot;
    
}

//Function maxRoot determines the larger root in a given expression, if
//infinite number of roots it returns 0.
float Quadratic::maxRoot(Quadratic &q1)const
{
    float maxroot;
    
    while(q1.numRoots(q1) == 1)
    {
        if(((q1.a) == 0) && (q1.b != 0))
        {
            maxroot = ((q1.c) * (-1)) / q1.b;
        }
        else
        {
            maxroot = ((q1.b) * (-1)) / ((2) * (q1.a));
        }
        return maxroot;
    }
    
    if (q1.numRoots(q1) == 2)
    {
        maxroot = ((-1 * q1.b) - sqrt((pow(q1.b,2)-(4 * q1.a * q1.c)))) / (2 * q1.a);
    }
    else if (q1.numRoots(q1) == 3)
    {
        maxroot = 0;
    }
    return maxroot;
}

//Function operator + allows the user to add two objects. In this case the result
// is the quadratic expression from adding object 1 to object 2.
Quadratic operator+(const Quadratic &q1, const Quadratic &q2)
{
    float aSum, bSum, cSum;
    aSum = (q1.getA() + q2.getA());
    bSum = (q1.getB() + q2.getB());
    cSum = (q1.getC() + q2.getC());
    Quadratic q3;
    q3.setQuadratic(aSum, bSum, cSum);
    return q3;
}

//Function operator* allows the user to enter a floating point number and multiply it
// times an object. In this case, the result is a quadratic expression.
Quadratic operator*(double r, const Quadratic &q1)
{
    float aMul, bMul, cMul;
    
    aMul = (q1.getA() * r);
    bMul = (q1.getB() * r);
    cMul = (q1.getC() * r);
    Quadratic q4;
    q4.setQuadratic(aMul, bMul, cMul);
    
    return q4;
}
