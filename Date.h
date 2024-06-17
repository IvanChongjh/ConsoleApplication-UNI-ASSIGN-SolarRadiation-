/****
@author Ivan Chong Jia Hao
@since 29/5/2023
@version 1.01
*/

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Date
{

public:
     /*
    Default constructor
    */
    Date();
     /*
    Default constructor
    */
    ~Date(){};
    /**
    Constructor to store values of 3 variables
    @param Day , Day
    @param Month , Month
    @param Year , Year
    */
    Date(int Day, int Month, int year);

    /**
    Assessor returns a const int
    @return int m_day
    */
    int GetDay() const;
    /**
    Assessor returns a const int
    @return int m_month
    */
    int GetMonth() const;
    /**
    Assessor returns a const int
    @return int m_year
    */
    int GetYear() const;


    /**
    Mutators to set new values to private declared data
    @param int const day
    @return void
    */
    void SetDay( const int & Day);
    /**
    Mutators to set new values to private declared data
    @param int const month
    @return void
    */
    void SetMonth(const int & Month);
    /**
    Mutators to set new values to private declared data
    @param int const year
    @return void
    */
    void SetYear(const int & Year);

    bool operator < (const Date & anotherdate);
    bool operator > (const Date & anotherdate);
    bool operator == (const Date & anotherdate);
    /**
    Declaration of private variables
    */
private :
    int m_day;
    int m_month;
    int m_year;
};

/**
 IO Operator overloading
 @warning do not remove !
 */
ostream & operator <<( ostream & os, const Date & date);
istream & operator >>( istream & input, Date & date );

#endif // DATE_H_INCLUDED
