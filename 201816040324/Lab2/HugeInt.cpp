// Lab 2: Hugeint.cpp
// HugeInt member-function and friend-function definitions.
#include <iostream>
#include <cctype> // isdigit function prototype
#include <cstring> // strlen function prototype
using namespace std;

#include "Hugeint.h" // HugeInt class definition

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt( long value )
{
   // initialize array to zero
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;

   // place digits of argument into array
   for ( int j = 29; value != 0 && j >= 0; j-- )
   {
      integer[ j ] = value % 10;
      value /= 10;
   } // end for
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt( const char *string )
{
   // initialize array to zero
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;

   // place digits of argument into array
   int length = strlen( string );

   for ( int j = 30 - length, k = 0; j <= 29; j++, k++ )

      if ( isdigit( string[ k ] ) )
         integer[ j ] = string[ k ] - '0';

} // end HugeInt conversion constructor

// get function calculates length of integer
int HugeInt::getLength() const
{
    int i=0 ;
   for ( i = 0; i <= 29; i++ )
      if ( integer[ i ] != 0 )
         break; // break when first digit is reached

   return 30-i; // length is from first digit (at i) to end of array
} // end function getLength

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+( const HugeInt &op2 ) const
{
   HugeInt temp; // temporary result
   int carry = 0;

   for ( int i = 29; i >= 0; i-- )
   {
      temp.integer[ i ] =
         integer[ i ] + op2.integer[ i ] + carry;

      // determine whether to carry a 1
      if ( temp.integer[ i ] > 9 )
      {
         temp.integer[ i ] %= 10;  // reduce to 0-9
         carry = 1;
      } // end if
      else // no carry
         carry = 0;
   } // end for

   return temp; // return copy of temporary object
} // end function operator+

// addition operator; HugeInt + int
HugeInt HugeInt::operator+( int op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+( const char *op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+
bool HugeInt::operator==( const HugeInt &op2 ) const//判断是先判断长度   长度相等时在用循环一位一位比较
{
    int a=getLength() ;
    if (a<op2.getLength())
    {
        return false ;
    }
    if (a>op2.getLength())
    {
        return false;
    }
    if (a==op2.getLength())
    {
           for ( int i = 0; i <= 29; i++ )
      {
             if( integer[ i ] > op2.integer[ i ] )
         {
           return false;
         }
             if(integer[i]<op2.integer[ i ] )
         {
            return false ;
         }
      }
      return true ;
    }
}
bool HugeInt::operator<( const HugeInt &op2 ) const//判断是先判断长度   长度相等时在用循环一位一位比较
{
    int a=getLength() ;
    if (a==op2.getLength())
    {
           for ( int i = 0; i <= 29; i++ )
      {
             if( integer[ i ] > op2.integer[ i ] )
         {
           return false;
         }
             if(integer[i]<op2.integer[ i ] )
         {
            return true ;
         }
      }
      return false ;
    }
    if (a<op2.getLength())
    {
        return true ;
    }
    if (a>op2.getLength())
    {
        return true ;
    }

}
bool HugeInt::operator!=( const HugeInt &op2 ) const//判断是先判断长度   长度相等时在用循环一位一位比较
{
    int a=getLength() ;
    if (a<op2.getLength())
    {
        return true ;
    }
    if (a>op2.getLength())
    {
        return true;
    }
    if (a==op2.getLength())
    {
           for ( int i = 0; i <= 29; i++ )
      {
             if( integer[ i ] > op2.integer[ i ] )
         {
           return true;
         }
             if(integer[i]<op2.integer[ i ] )
         {
            return true;
         }
      }
      return false ;
    }
}
bool HugeInt::operator>( const HugeInt &op2 ) const//判断是先判断长度   长度相等时在用循环一位一位比较
{
    int a=getLength() ;
    if (a>op2.getLength())
    {
        return true;
    }
    else if (a<op2.getLength())
    {
        return false ;
    }
    else   if (a==op2.getLength())
    {
           for ( int i = 0; i <= 29; i++ )
      {
             if( integer[ i ] > op2.integer[ i ] )
         {
           return true;
         }
             if(integer[i]<op2.integer[ i ] )
         {
            return false ;
         }
      }
      return false;
    }
}
bool HugeInt::operator>=( const HugeInt &op2 ) const//判断是先判断长度   长度相等时在用循环一位一位比较
{
    int a=getLength() ;
    if (a>op2.getLength())
    {
        return true;
    }
    else if (a<op2.getLength())
    {
        return false ;
    }
    else   if (a==op2.getLength())
    {
           for ( int i = 0; i <= 29; i++ )
      {
             if( integer[ i ] > op2.integer[ i ] )
         {
           return true;
         }
             if(integer[i]<op2.integer[ i ] )
         {
            return false ;
         }
      }
      return true;
    }
}
bool HugeInt::operator<=( const HugeInt &op2 ) const//判断是先判断长度   长度相等时在用循环一位一位比较
{
    int a=getLength() ;
    if (a==op2.getLength())
    {
           for ( int i = 0; i <= 29; i++ )
      {
             if( integer[ i ] > op2.integer[ i ] )
         {
           return false;
         }
             if(integer[i]<op2.integer[ i ] )
         {
            return true ;
         }
      }
      return false ;
    }
    if (a<op2.getLength())
    {
        return true ;
    }
    if (a>op2.getLength())
    {
        return false ;
    }
}
// equality operator; HugeInt == HugeInt
/* Write a definition for the == operator */

// inequality operator; HugeInt != HugeInt
/* Write a definition for the != operator
   by calling the == operator */

// less than operator; HugeInt < HugeInt
/* Write a definition for the < operator */

// less than or equal operator; HugeInt <= HugeInt
/* Write a definition for the <= operator
   by calling the < and == operators */

// greater than operator; HugeInt > HugeInt
/* Write a definition for the > operator
   by calling the <= operator */

// greater than or equal operator; HugeInt >= HugeInt
/* Write a definition for the >= operator
   by calling the > and == operators */

// overloaded output operator
ostream& operator<<( ostream &output, const HugeInt &num )
{
   int i;

   for ( i = 0; ( num.integer[ i ] == 0 ) && ( i <= 29 ); i++ )
      ; // skip leading zeros

   if ( i == 30 )
      output << 0;
   else

      for ( ; i <= 29; i++ )
         output << num.integer[ i ];

   return output;
} // end function operator<<
