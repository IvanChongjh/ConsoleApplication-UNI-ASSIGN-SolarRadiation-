/****
@author Ivan Chong Jia Hao
@since 29/5/2023
@version 1.01
*/
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>
#include  <string>
using namespace std;

class Time
{
private :
//    string m_time;
    int m_hours;
    int m_minutes;

public :
    /**
    Default Constructor
    */
    Time();
    /**
    destructor
    */
    ~Time(){};
    /**
    Constructor overloading
    @param string time
    */
    Time(int hour,int minutes);
    /**
    assessor get time value
    @return m_time
    */
    int GetHour()const;
    int GetMinutes()const;
    /**
    mutator set time value
    @param string time
    @return void
    */
    void SetHour(const int &hour);
    void SetMinute(const int &minute);
    // printvalues to help test value


};
ostream & operator <<( ostream & os, const Time & T );
istream & operator >>( istream & input, Time & T );
#endif
