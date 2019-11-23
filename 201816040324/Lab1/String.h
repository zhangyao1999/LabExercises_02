// Lab 1: String.h
// Header file for class String.
#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class String
{
   friend ostream &operator<<( ostream &output, const String &s );
public:
   String( const char * const = "" ); // conversion constructor
   String( const String & ); // copy constructor
   ~String(); // destructor
   const String &operator=( const String & );
   const String operator+( const String &) ;
   /* Write a prototype for the operator+ member function */
private:
   char *sPtr; // pointer to start of string
   int length; // string length
}; // end class String

#endif
