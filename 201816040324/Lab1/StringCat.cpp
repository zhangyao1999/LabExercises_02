// Lab 1: StringCat.cpp
// Demonstrating overloaded + operator that does not modify operands
#include <iostream>
using namespace std;

#include "String.h"

int main()
{
   String string1, string2( "The date is" );
   String string3( " August 1, 1993" );
   string1=string3+string2 ;

   // test overloaded operators
   cout << "string1 = string2 + string3\n";
   /* Write a statement to concatenate string2 and string3,
      and assign the result to string1 */
   cout << "\"" << string1 << "\" = \"" << string2 << "\" + \""
      << string3 << "\"" << endl;
} // end main
