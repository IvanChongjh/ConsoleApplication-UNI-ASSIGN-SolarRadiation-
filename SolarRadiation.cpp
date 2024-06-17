#include "SolarRadiation.h"

SolarRadiation ::SolarRadiation ()
:m_SolarRadiation(0.0)
{

}

SolarRadiation :: SolarRadiation (float& SolarRadiation)
: m_SolarRadiation(SolarRadiation)
{

}

void SolarRadiation :: SetSolarRadiation(const float&SolarRadiation)
{
   m_SolarRadiation = SolarRadiation;

}
float SolarRadiation :: GetSolarRadiation() const
{
    return m_SolarRadiation;
}

istream & operator >> ( istream &input , SolarRadiation&SolarRadiation)
{
    double data;
    input >> data;
    SolarRadiation.SetSolarRadiation(data);
    return input;

}
ostream & operator << (ostream & os, const SolarRadiation &SolarRadiation)
{
    os << "Solar Radiation is :" << SolarRadiation.GetSolarRadiation();
    return os;
}
