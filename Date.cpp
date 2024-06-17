#include "Date.h"

// default constructor
Date :: Date ():m_day(0),m_month(0),m_year(0)
{

}

// constructor
Date :: Date (int Day, int Month, int Year)
    :m_day(Day),m_month(Month),m_year(Year)
{

}

int Date :: GetDay() const
{
    return m_day;
}
void Date :: SetDay(const int & Day)
{
    m_day = Day;

}
int Date :: GetMonth() const
{
    return m_month;
}
void Date :: SetMonth(const int & Month)
{
    if(Month > 0 && Month <= 12)
        m_month = Month;

}
int Date :: GetYear() const
{
    return m_year;
}

void Date :: SetYear( const int & Year)
{
    m_year = Year;
}
bool Date :: operator < (const Date & anotherdate)
{
    if(m_day  < anotherdate.GetDay() && m_month <= anotherdate.GetMonth() && m_year <= anotherdate.GetYear())
    {
        return true;
    }
    else
        return false;
}
bool Date :: operator > (const Date & anotherdate)
{
    if(m_day > anotherdate.GetDay()&& m_month >= anotherdate.GetMonth() && m_year >= anotherdate.GetYear())
    {
        return true;
    }
    else
        return false;
}
bool Date ::operator == (const Date & anotherdate)
{
    if(m_day == anotherdate.GetDay() && m_month == anotherdate.GetMonth() && m_year == anotherdate.GetYear())
    {
        return true;
    }
    else
        return false;
}
ostream & operator <<( ostream & os, const Date  & date)
{
    os << "     Date: " << date.GetDay() << " " << date.GetMonth() << " " << date.GetYear()<< "\n" ;
    return os;
}

istream & operator >>( istream & input, Date & date )
{
    int TempDate;
    int TempYear;
    int TempMonth;
    input >> TempDate >> TempMonth >> TempYear;
    date.SetDay(TempDate);
    date.SetMonth(TempMonth);
    date.SetYear(TempYear);

    return input;
}
