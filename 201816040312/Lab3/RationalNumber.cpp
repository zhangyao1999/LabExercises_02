// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"
using namespace std;

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
   RationalNumber::RationalNumber(int a,int b)
   {
       if(b>0)
        denominator=b;
       if(b<=0)
        denominator=1;
       numerator=a;
   }

// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(const RationalNumber &con)const
{
    RationalNumber tem;
    tem.numerator=this->numerator*con.denominator+this->denominator*con.numerator;
    tem.denominator=this->denominator*con.denominator;
    tem.reduction();
    return tem;
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber &con)const
{
    RationalNumber tem;
    tem.numerator=this->numerator*con.denominator-this->denominator*con.numerator;
    tem.denominator=this->denominator*con.denominator;
    tem.reduction();
    return tem;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber &con)const
{
    RationalNumber tem;
    tem.numerator=this->numerator*con.numerator;
    tem.denominator=this->denominator*con.denominator;
    tem.reduction();
    return tem;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber &con)const
{
    if(con.numerator==0)
    {
        cout<<"error";
    }
    if(con.numerator!=0)
    {
        RationalNumber tem;
        tem.numerator=this->numerator*con.denominator;
        tem.denominator=this->denominator*con.numerator;
        tem.reduction();
        return tem;
    }
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(RationalNumber &con)
{
    RationalNumber tem;
    tem=*this-con;
    con.reduction();
    if(tem.numerator>0)
        return true;
    else
        return false;

}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(RationalNumber &con)
{
    RationalNumber tem;
    tem=*this-con;
    con.reduction();
    if(tem.numerator<0)
        return true;
    else
        return false;
}
// overloaded >= operator
/* Write definition for operator >= */

bool RationalNumber::operator>=(RationalNumber &con)
{
    RationalNumber tem;
    tem=*this-con;
    con.reduction();
    if(tem.numerator>=0)
        return true;
    else
        return false;
}
// overloaded <= operator
/* Write definition for operator <= */

bool RationalNumber::operator<=(RationalNumber &con)
{
    RationalNumber tem;
    tem=*this-con;
    con.reduction();
    if(tem.numerator<=0)
        return true;
    else
        return false;
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(RationalNumber &con)
{
    RationalNumber tem;
    tem=*this-con;
    con.reduction();
    if(tem.numerator==0)
        return true;
    else
        return false;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(RationalNumber &con)
{
   RationalNumber tem;
    tem=*this-con;
    con.reduction();
    if(tem.numerator==0)
        return false;
    else
        return true;
}
// function printRational definition
/*void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
} // end function printRational*/

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
ostream &operator<<(ostream &output,const RationalNumber &rat)
{
    if ( rat.numerator == 0 ) // print fraction as zero
      output << rat.numerator;
   else if ( rat.denominator == 1 ) // print fraction as integer
      output << rat.numerator;
   else
      output << rat.numerator << '/' << rat.denominator;
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
