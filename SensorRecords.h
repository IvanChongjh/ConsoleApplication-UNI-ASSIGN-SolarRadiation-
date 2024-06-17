/****
@author Ivan Chong Jia Hao
@since 31/7/2023
@version 1.01
*/
#ifndef SENSORRECORDS_H_INCLUDED
#define SENSORRECORDS_H_INCLUDED
#include "Time.h"
#include "Date.h"
#include "Temperature.h"
#include "SolarRadiation.h"
#include "WindSpeed.h"
#include <iostream>
#include  <string>
using namespace std;

class SensorRecords
{

public :
    /**
     default constructor
    */
    SensorRecords();
    /**
    destructor
    */
    ~SensorRecords(){};
    /**
    Constructor overloading
    @param Date &d
    @param SolarRadiation & sr
    @param WindSpeed & ws
    @param Time & t
    */
    SensorRecords(Date &d,SolarRadiation & sr,WindSpeed &ws,Temperature &temp,Time & t);

    /**
    Assessor
    @param SolarRadiation & solar radiation
    */
    void GetSolarRadiation(SolarRadiation &solarradiation) const;
    /**
    Assessor
    @param Date & date
    */
    void GetDate(Date &date) const;
    /**
    Assessor
    @param WindSpeed &windspeed
    */
    void GetWindSpeed(WindSpeed &windspeed) const;
    /**
    Assessor
    @param Temperature & temperature
    */
    void GetTemperature(Temperature &temperature)const;
    /**
    Assessor
    @param Time & time
    */
    void GetTime(Time & time)const;

    /**
    Mutator
    @param Date & date
    */
    void SetDate(const Date & date);
    /**
    Mutator
    @param Time & Time
    */
    void SetTime(const Time & time);
    /**
    Mutator
    @param SolarRadiation & solar radiation
    */
    void SetSolarRadiation(const SolarRadiation & solarradiation);
    /**
    Assessor
    @param WindSpeed &WindSpeed
    */
    void SetWindSpeed(const WindSpeed &WindSpeed);
    /**
    Assessor
    @param Temperature & temperature
    */
    void SetTemperature(const Temperature &temperature);

    /**
    copy object temperature
    @param Temperature& anotherTemp
    */
    void CopyTemperature(Temperature& anotherTemp) const;
    /**
    copy object date
    @param date & anotherDate
    */
    void CopyDate(Date& anotherDate) const;
    /**
    copy object WindSpeed
    @param WindSpeed& anotherWindSpeed
    */
    void CopyWindSpeed(WindSpeed& anotherWindSpeed) const;
    /**
    copy object time
    @param Time& anotherTime
    */
    void CopyTime(Time& anotherTime) const;
    /**
    copy object solar radiation
    @param SolarRadiation& anotherSolarRadiation
    */
    void CopySolarRadiation(SolarRadiation& anotherSolarRadiation) const;
      /**
     Data tagging this is use to sort in binary search tree
    @param SensorRecord
    @return void
    */
    void SetDataTag(int tag);
        /**
     Assessor for tag
    @return int
    */
    int GetDataTag()const;
    bool operator > (SensorRecords & AnotherTag);
    /**
     operator overloading
    @param SensorRecord
    @return bool
    */
    bool operator < (SensorRecords & AnotherTag);
    /**
    operator overloading
    @param SensorRecord
    @return bool
    */
    bool operator == (SensorRecords & AnotherTag);

   /// private declared variables
    private :
    int m_datatagging;
    Date m_date;
    SolarRadiation m_sr;
    WindSpeed m_ws;
    Temperature m_temp;
    Time m_time;

};




#endif // SENSORRECORDS_H_INCLUDED
