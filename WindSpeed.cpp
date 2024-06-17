#include "WindSpeed.h"

WindSpeed :: WindSpeed ()
:m_WindSpeed(0.0)
{

}

WindSpeed :: WindSpeed (float WindSpeed)
: m_WindSpeed(WindSpeed)
{

}

void WindSpeed :: SetWindSpeed(const float &WindSpeed)
{
   m_WindSpeed = WindSpeed;

}
float WindSpeed :: GetWindSpeed() const
{
    return m_WindSpeed;
}

istream & operator >> ( istream &input , WindSpeed &WindSpeed)
{
    float data;
    input >> data;
    WindSpeed.SetWindSpeed(data);
    return input;

}
ostream & operator << (ostream & os, const WindSpeed &WindSpeed)
{
    os << "WindSpeed is :" << WindSpeed.GetWindSpeed();
    return os;
}
