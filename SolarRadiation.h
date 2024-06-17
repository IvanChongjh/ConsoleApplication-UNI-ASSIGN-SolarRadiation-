#ifndef SOLARRADIATION_H_INCLUDED
#define SOLARRADIATION_H_INCLUDED

#include <iostream>
#include  <string>
using namespace std;

class SolarRadiation
{
private :
    double m_SolarRadiation;

public :
    /**
    constructor
    */
    SolarRadiation();
    /**
    Destructor
    */
    ~SolarRadiation(){};
    /**
    constructor overloading
    @param SolarRadiation
    */
    SolarRadiation(float &SolarRadiation);
    /**
    assessor
    @return double;
    */
    float GetSolarRadiation()const;
    /**
    mutator
    @param double &SolarRadiation
    @return void
    */
    void SetSolarRadiation(const float &SolarRadiation);


};
ostream & operator <<( ostream & os, const SolarRadiation & SolarRadiation );
istream & operator >>( istream & input, SolarRadiation & SolarRadiation);

#endif // SOLARRADIATION_H_INCLUDED
