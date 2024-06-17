#ifndef TEMPERATURE_H_INCLUDED
#define TEMPERATURE_H_INCLUDED
#include <iostream>

using namespace std;

class Temperature
{
private :
    float m_Temperature;

public :
    /**
    default constructor
    */
    Temperature();


    /**
    Destructor
    */

    ~Temperature () {};
    /**
    constructor overloading
    */

    Temperature(float Temperature);
    /**
    Assessor
    @return float
    */
    float GetTemperature()const;
    /**
    @param float &Temperature
    @return void
    */
    void SetTemperature(const float &Temperature);


};
ostream & operator <<( ostream & os, const Temperature &Temperature );
istream & operator >>( istream & input, Temperature & Temperature );

#endif // TEMPERATURE_H_INCLUDED
