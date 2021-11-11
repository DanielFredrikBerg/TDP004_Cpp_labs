#ifndef TIME_H
#define PERSON_H

class Time
{
public:
   Time() const&;
   Time( Time const& baseTime, int const seconds) const&;
   bool operator<( Time rhs );
   Time operator+( Time rhs );
   Time operator-( Time rhs );
   Time operator++( int );

   string toString();

   friend ostream& operator<<( ostream & lhs, Person const& rhs);

private:
   
}

#endif
