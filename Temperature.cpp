#include "Temperature.h"

Temperature ::Temperature ()
:m_Temperature(0.0)
{

}

Temperature :: Temperature(float Temperature)
: m_Temperature(Temperature)
{

}

void Temperature :: SetTemperature(const float &Temperature)
{
   m_Temperature = Temperature;

}
float Temperature:: GetTemperature() const
{
    return m_Temperature;
}

istream & operator >> ( istream &input , Temperature& Temperature)
{
    float data;
    input >> data;
    Temperature.SetTemperature(data);
    return input;

}
ostream & operator << (ostream & os, const Temperature &Temperature)
{
    os << "Temperature is :" << Temperature.GetTemperature();
    return os;
}
