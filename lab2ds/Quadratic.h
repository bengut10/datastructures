//
//  Quadratic.h
//  Quadratic Expressions
//
//  Created by Jose Benjamin Gutierrez on 9/3/15.
//  Copyright (c) 2015 Jose Benjamin Gutierrez. All rights reserved.
//

#ifndef __Quadratic_Expressions__Quadratic__
#define __Quadratic_Expressions__Quadratic__
#include <stdio.h>

/*  This header file defines basic operations for Quadratic operations.
 Basic operations are:
 Setting new expressions.
 Evaluating expressions.
 Overloading +  and * operator to produce new expressions.
 Determining the number of roots
 Outputting the roots
 */


class Quadratic
{
private:
    /* Data members
    //----------------------------------------------------------------------------------------------
     Class quadratic has 3 private variables which represent the coefficients
     A, B, and C of a quadratic equation */
    
    float a;
    float b;
    float c;
    
    //----------------------------------------------------------------------------------------------
public:
    
    /* Function members */
    
    //----------------------------------------------------------------------------------------------
    
    Quadratic();
    /* Constructor that sets the default values to 0 
     Precondition: None
     Postcondition: Sets values to 0 */
    
    //----------------------------------------------------------------------------------------------
    
    void display();
    /* Display function allows the quadratic expressions to be printed out to the screen
     When it is called. 
     Precondition: None
     Postcontition: Displays the values for a, b and c */
    
    //----------------------------------------------------------------------------------------------
    
    void setQuadratic(float newa, float newb, float newc);
    /* Set quadratic sets the private variables to the coefficients of the expresion 
    Precondition: None
    Postcondition: Sets new values which are inputs from the user */
    
    //----------------------------------------------------------------------------------------------
    
    float getA() const;
    
    float getB()const;
    
    float getC()const;
    
    /* getA, getB, and getC are the "getter" functions to access the private variables
     Preconditions: None
     Postconditions: "Getter" functions access and return private member variables. */
    
    //----------------------------------------------------------------------------------------------
    
    float evaluate(float x) const;
    /* Evaluate takes an int as an arguement and sets it as the value for x and evaluates
     the quadratic expression.
     Precondition: A floating point value must be given ir order to evaluate the expression
     Postcondition: returns new coefficients to form a new expression the coefficients are the 
     product of the original expression times the floating number given by the user.*/
    
    //----------------------------------------------------------------------------------------------
    
    int numRoots(Quadratic &q1)const;
    /* numRoots determines the number of roots of a given expression.
     Precondition: Expression must be given
     Postcondition: Returns number of roots with possible values of 0,1,2, and 3 
     representing infinity */
    
    //----------------------------------------------------------------------------------------------
    
    float minRoot(Quadratic &q1) const;
    /*  minRoot determines the small root of a given expression
     Pre condition: A given expression must have at least one root, if expression has
     no real roots a "CERR" message is displayed.
     Post condition: Returns the small root of the quadratic expression,
     if infinite numnber of roots it returns 3 */
    
    //----------------------------------------------------------------------------------------------
    
    float maxRoot(Quadratic &q1) const;
    /* maxRoot determines the large root of a given expression
     Pre condition: A given expression must have at least one root, if expression has
     no real roots a "CERR" message is displayed.
     Post condition: Returns the large root of the quadratic expression,
     if infinite numnber of roots it returns 0 */

};
    /* Non - Member functions */

    //----------------------------------------------------------------------------------------------

Quadratic operator+(const Quadratic &q1, const Quadratic &q2);
    /* overloaded operator+ is used to add the coefficients of two quadratic expressions
     Pre condition: Coeficients for a second quadratic expresion must be given
     Post condition: Returns a new quadratic expression as a result of the sum of the
     coefficients */

    //----------------------------------------------------------------------------------------------

Quadratic operator*(double r, const Quadratic &q);
    /* overloaded operator * multiply takes r, a given float number by the
     and multiplies it by the coefficients of an expression.
     Pre condition: R must be given by the user
     Post condition: a new quadratic expression is returned */


#endif /* defined(__Quadratic_Expressions__Quadratic__) */
