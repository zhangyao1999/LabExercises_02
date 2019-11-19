// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n,int d)
{
    numerator=n;
    if(d<=0)
    {
        d=1;
    }
    denominator=d;
    reduction();
}

// overloaded + operator
RationalNumber RationalNumber::operator+(const RationalNumber &right)
{

    RationalNumber Temp;
    if(right.denominator==denominator)
    {
        Temp.numerator=numerator+right.numerator;
        Temp.denominator=right.denominator;
        Temp.reduction();
        return Temp;
    }
    else
    {
        Temp.numerator=(numerator*right.denominator)+(right.numerator*denominator);
        Temp.denominator=denominator*right.denominator;
        Temp.reduction();
        return Temp;
    }

}


// overloaded - operator
RationalNumber RationalNumber::operator-(const RationalNumber &right)
{
    RationalNumber Temp;
    if(right.denominator==denominator)
    {
        Temp.numerator=numerator-right.numerator;
        Temp.denominator=right.denominator;
        Temp.reduction();
        return Temp;
    }
    else
    {
        Temp.numerator=(numerator*right.denominator)-(right.numerator*denominator);
        Temp.denominator=denominator*right.denominator;
        Temp.reduction();
        return Temp;

    }

}


// overloaded * operator
RationalNumber RationalNumber::operator*(const RationalNumber &right)
{
    RationalNumber Temp;
    if(right.numerator!=0&&numerator!=0)
    {
        Temp.numerator=numerator*right.numerator;
        Temp.denominator=denominator*right.denominator;
        Temp.reduction();
    }
    else
    {
        Temp=0;
    }


    return Temp;
}


// overloaded / operator
RationalNumber RationalNumber::operator/(const RationalNumber &right)
{
    RationalNumber Temp;
    Temp.numerator=numerator*right.denominator;
    if(right.numerator==0)
    {
        cout<<"Divisor cannot be 0"<<endl;
        exit(0);
    }
    Temp.denominator=denominator*right.numerator;
    Temp.reduction();
    return Temp;
}


// overloaded > operator
bool RationalNumber::operator>(const RationalNumber &right)const
{
    int a,b,c,d;//temporary variable
    if(right.denominator==denominator)
    {
        if(numerator>right.numerator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        a=numerator*right.denominator;
        b=denominator*right.denominator;
        c=right.numerator*denominator;
        d=right.denominator*denominator;
        if(a>c)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}

// overloaded < operator
bool RationalNumber::operator<(const RationalNumber &right)const
{
    int a,b,c,d;//temporary variable
    if(right.denominator==denominator)
    {
        if(numerator<right.numerator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        a=numerator*right.denominator;
        b=denominator*right.denominator;
        c=right.numerator*denominator;
        d=right.denominator*denominator;
        if(a<c)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}

// overloaded >= operator
bool RationalNumber::operator>=(const RationalNumber &right)const
{
    return !(*this<right);
}

// overloaded <= operator
bool RationalNumber::operator<=(const RationalNumber &right)const
{
    return !(*this>right);
}

// overloaded == operator
bool RationalNumber::operator==(const RationalNumber &right)const
{
    if(right.denominator==denominator)
    {
        if(right.numerator!=numerator)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }


}

// overloaded != operator
bool RationalNumber::operator!=(const RationalNumber &right)const
{
    if(right.denominator==denominator)
    {
        if(right.numerator!=numerator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
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

ostream &operator<<(ostream &output, const RationalNumber &right)
{
    if(right.numerator==0)
        output<<right.numerator;
    else if(right.denominator==1)
        output<<right.numerator;
    else
        output<<right.numerator<< '/'<<right.denominator;
    return output;
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
