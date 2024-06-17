#include "Time.h"


Time :: Time ()
:m_hours(0),m_minutes(0)
{

}

Time :: Time (int hour,int minutes)
: m_hours(hour),m_minutes(minutes)
{

}

void Time :: SetHour(const int &hour)
{
   m_hours = hour;

}
void Time :: SetMinute(const int &minute)
{
   m_minutes= minute;

}
int Time :: GetHour() const
{
    return m_hours;
}
int Time :: GetMinutes() const
{
    return m_minutes;
}


istream & operator >> ( istream &input , Time &T)
{
     int data;
    input >> data;
    T.SetHour(data);
    T.SetMinute(data);

    return input;

}
ostream & operator << (ostream & os, const Time &T)
{
    os << "Time is :" << T.GetHour() << " Hours " << T.GetMinutes() << " Minutes " << endl;
    return os;
}


