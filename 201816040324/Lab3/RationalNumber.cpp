// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber RationalNumber::operator+( const RationalNumber &b ) const
{
    RationalNumber temp ;
    temp.numerator=denominator*b.numerator+b.denominator*numerator ;
    temp.denominator=denominator*b.denominator ;
    temp.reduction() ;
    return temp ;
}
RationalNumber::RationalNumber( int n, int d )
{
    if(d==0)
    {
        cout<<"\n\n\nData entry error:\nData denominator is zero, cannot be calculated next\n\n\n" ;
        exit(0) ;
    }
    numerator = n;
    denominator = d;
    reduction();
}
RationalNumber RationalNumber::operator-( const RationalNumber &b ) const
{
    RationalNumber temp ;
    temp.numerator = numerator * b.denominator - denominator * b.numerator;
    temp.denominator = denominator * b.denominator;
    //temp.numerator=numerator-b.numerator ;
    temp.reduction() ;
    return temp ;
}
RationalNumber RationalNumber::operator*( const RationalNumber &b ) const
{
    RationalNumber temp ;
    temp.denominator=denominator*b.denominator ;
    temp.numerator=numerator*b.numerator ;
    temp.reduction() ;
    return temp ;
}
RationalNumber RationalNumber::operator/( const RationalNumber &b ) const
{
    RationalNumber temp ;
    temp.denominator=denominator*b.numerator ;
    temp.numerator=numerator*b.denominator ;
    //temp.numerator=numerator+b.numerator ;
    temp.reduction() ;
    return temp ;
}
// overloaded + operator
/* Write definition for overloaded operator + */

// overloaded - operator
/* Write definition for overloaded operator - */

// overloaded * operator
/* Write definition for overloaded operator * */

// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
bool RationalNumber::operator> ( const RationalNumber &b) const
{
    double a=0.0 ;
    a=numerator/denominator ;
    double c=0.0 ;
    c=b.numerator/b.denominator ;
    return a>c ;
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator< ( const RationalNumber &b) const
{
    double a=numerator/denominator  ;
    double c=b.numerator/b.denominator ;
    return a<c ;
}
// overloaded < operator
/* Write definition for operator < */

// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=( const RationalNumber &b) const
{
    double a=numerator/denominator  ;
    double c=b.numerator/b.denominator ;
    return a>=c ;
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=( const RationalNumber &b) const
{
    double a=numerator/denominator  ;
    double c=b.numerator/b.denominator ;
    return a<=c ;
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==( const RationalNumber &b) const
{
    double a=numerator/denominator  ;
    double c=b.numerator/b.denominator ;
    return a==c ;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=( const RationalNumber &b) const
{
    double a=numerator/denominator  ;
    double c=b.numerator/b.denominator ;
    return a!=c ;
}
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
