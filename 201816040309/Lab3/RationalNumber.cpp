// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

RationalNumber::RationalNumber(int a,int b)
{
    int r;
    if(b<=0)
    {
        cout<<"The denominator should not be negative"<<endl;
    }
    else
    {
        r = Maximum_common_factor(a,b);
        if(r!=0)
        {
            numerator = a/r;
            denominator = b/r;
        }
        else
        {
            numerator = a;
            denominator =b;
        }

    }

}
// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber RationalNumber::operator+(  RationalNumber &op2 )
{
    int temp_numerator,temp_denominator;

    if(this->denominator != op2.denominator)
    {
        temp_denominator = Least_common_multiple(this->denominator,op2.denominator);
        int a = temp_denominator/this->denominator;
        int b  = temp_denominator/op2.denominator;
        this->numerator *= a;
        op2.denominator *= b;
        temp_numerator = this->numerator + op2.numerator;
    }
    else
    {
        temp_denominator = this->denominator;
        temp_numerator = this->numerator + op2.numerator;
    }
    RationalNumber temp(temp_numerator,temp_denominator);
    return temp;
}


// overloaded + operator
/* Write definition for overloaded operator + */

// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(  RationalNumber &op2 )
{
    int temp_numerator,temp_denominator;
    if(this->denominator != op2.denominator)
    {
        temp_denominator = Least_common_multiple(this->denominator,op2.denominator);
        int a = temp_denominator/this->denominator;
        int b  = temp_denominator/op2.denominator;
        this->numerator *= a;
        op2.denominator *= b;
        temp_numerator = this->numerator - op2.numerator;
    }
    else
    {
        temp_denominator = this->denominator;
        temp_numerator = this->numerator - op2.numerator;
    }
    RationalNumber temp(temp_numerator,temp_denominator);
    return temp;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(  RationalNumber &op2 )
{
    int temp_numerator,temp_denominator;
    temp_numerator = this->numerator * op2.numerator;
    temp_denominator = this->denominator * op2.denominator;
    RationalNumber temp(temp_numerator,temp_denominator);
    return temp;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(  RationalNumber &op2 )
{
    int temp_numerator,temp_denominator;
    if(op2.numerator==0)
    {
        cout<<"can't divide by zero"<<endl;
    }
    else
    {
        temp_numerator = this->numerator * op2.denominator;
        temp_denominator = this->denominator * op2.numerator;
    }
    RationalNumber temp(temp_numerator,temp_denominator);


    return temp;
}
// overloaded > operator
bool RationalNumber::operator>( RationalNumber &op2)
/* Write definition for operator > */
{
    int temp_denominator;
    if(this->denominator!=op2.denominator)
    {
        temp_denominator = Least_common_multiple(this->denominator,op2.denominator);
        int a = temp_denominator/this->denominator;
        int b  = temp_denominator/op2.denominator;
        this->numerator *= a;
        op2.denominator *= b;
        if(this->numerator>op2.numerator)
        {
            return true;
        }
        else
            return false;
    }
    else
    {
        if(this->numerator>op2.numerator)
            return true;
        else
            return false;

    }
}
// overloaded < operator
bool RationalNumber::operator<( RationalNumber &op2)
{
    int temp_denominator;
    if(this->denominator!=op2.denominator)
    {
        temp_denominator = Least_common_multiple(this->denominator,op2.denominator);
        int a = temp_denominator/this->denominator;
        int b  = temp_denominator/op2.denominator;
        this->numerator *= a;
        op2.denominator *= b;
        if(this->numerator<op2.numerator)
        {
            return true;
        }
        else
            return false;
    }
     else
    {
        if(this->numerator<op2.numerator)
            return true;
        else
            return false;
    }
}
/* Write definition for operator < */

// overloaded >= operator
bool RationalNumber::operator>=( RationalNumber &op2)
{
    return !(*this<op2);
}
/* Write definition for operator >= */
bool RationalNumber::operator<=( RationalNumber &op2)
{
    return !(*this>op2);
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator==( RationalNumber &op2)
{
    if(this->denominator==op2.denominator)
    {
        if(this->numerator==op2.numerator)
            return true;
        else
            return false;
    }
    else
        return false;
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator!=( RationalNumber &op2)
{
    return !(*this==op2);
}
// overloaded != operator
/* Write definition for operator != */

// function printRational definition
void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
} // end function printRational

// function reduction definition
void RationalNumber::reduction()
{
   int largest, gcd = 1;  // greatest common divisor;

   largest = ( numerator > denominator ) ? numerator: denominator;

   for ( int loop = 2; loop <= largest; loop++ )
       if ( numerator % loop == 0 && denominator % loop == 0 )
          gcd = loop;

   numerator /= gcd;
   denominator /= gcd;
} // end function reduction
int RationalNumber::Maximum_common_factor(int a,int b)
{
    int temp1,temp2,r;
    if(b>a)
    {
        temp1 = b;
        temp2 = a;
    }
    else
    {
        temp1 = a;
        temp2 = b;
    }
    r = temp2;
    while(r!=0)
    {
        r = temp1%temp2;
        temp1 = temp2;
        temp2 = r;
    }
    return temp1;
}
int RationalNumber::Least_common_multiple(int a,int b)
{
    int r;
    r = Maximum_common_factor(a,b);
    if(r!=0)
    {
        return b/r*a;
    }
    else
    {
        return a*b;
    }

}


/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
