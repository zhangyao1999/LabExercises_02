// Lab 3: RationalNumber.h
// RationalNumber class definition.
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
    friend ostream &operator<<( ostream &, const RationalNumber & );
public:
   RationalNumber( int = 0, int = 1 ); // default constructor
   RationalNumber operator+(const RationalNumber & )const ;
   RationalNumber operator-(const RationalNumber & )const ;
   RationalNumber operator*(const RationalNumber & )const ;
   RationalNumber operator/(const RationalNumber & ) const;
   /* Write prototype for operator + */
   /* Write prototype for operator - */
   /* Write prototype for operator * */
   /* Write prototype for operator / */
   bool operator> ( const RationalNumber &) const;
   bool operator< ( const RationalNumber &) const;
   bool operator>= ( const RationalNumber &) const;
   bool operator<= ( const RationalNumber &) const;
   // relational operators
   /* Write prototype for operator > */
   /* Write prototype for operator < */
   /* Write prototype for operator >= */
   /* Write prototype for operator <= */
    bool operator== ( const RationalNumber &) const;
    bool operator!= ( const RationalNumber &) const;
   // equality operators
   /* Write prototype for operator == */
   /* Write prototype for operator != */

   void printRational() const; // display rational number
private:
   int numerator; // private variable numerator·Ö×Ó
   int denominator; // private variable denominator·ÖÄ¸
   void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif
