#ifndef WINDSPEED_H_INCLUDED
#define WINDSPEED_H_INCLUDED
#include <iostream>
using namespace std;

class WindSpeed
{
private :
    float m_WindSpeed;

public :
    /**
    Default construct
    */
    WindSpeed();
      /**
    destructor
    */
    ~WindSpeed(){}
    /**
      constructor overloading
      @param float WindSpeed

      */
    WindSpeed(float WindSpeed);
    /**
    assessor
    @return float
    */
    float GetWindSpeed()const;
    /**
    mutator
    @param float &WindSpeed
    */
    void SetWindSpeed(const float &WindSpeed);


};
ostream & operator <<( ostream & os, const WindSpeed & WindSpeed );
istream & operator >>( istream & input, WindSpeed & WindSpeed );


#endif // WINDSPEED_H_INCLUDED
