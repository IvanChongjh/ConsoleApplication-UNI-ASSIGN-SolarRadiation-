#include "SensorRecords.h"

SensorRecords::SensorRecords()
{
    Date myDate;
    SolarRadiation mySolar;
    Temperature myTemp;
    WindSpeed myWind;
    Time myTime;

    m_date = myDate;
    m_sr = mySolar;
    m_temp = myTemp;
    m_ws = myWind;
    m_time = myTime;

}

SensorRecords::SensorRecords(Date &d,SolarRadiation & sr,WindSpeed &ws,Temperature &temp,Time & t)
{
    m_date = d;
    m_sr = sr;
    m_temp = temp;
    m_ws = ws;
    m_time = t;
}

void  SensorRecords::GetDate(Date &d) const
{
    d  = m_date;

}
void SensorRecords::GetSolarRadiation(SolarRadiation & sr) const
{
    sr = m_sr;

}
void SensorRecords::GetTemperature(Temperature &temp) const
{
    temp = m_temp;

}
void SensorRecords::GetWindSpeed(WindSpeed &ws) const
{
    ws = m_ws;

}
void SensorRecords::GetTime(Time &time) const
{
    time= m_time;

}

void SensorRecords::SetDate(const Date & d)
{
    m_date = d;

}
void SensorRecords::SetTemperature(const Temperature &temperature)
{
    m_temp= temperature;

}
void SensorRecords::SetSolarRadiation(const SolarRadiation & solarradiation)
{
    m_sr= solarradiation;

}
void SensorRecords::SetTime(const Time & time)
{
    m_time= time;

}
void SensorRecords::SetWindSpeed(const WindSpeed &WindSpeed)
{
    m_ws= WindSpeed;

}

void SensorRecords :: CopyTime( Time& anotherTime) const
{
    anotherTime = m_time;
}
void SensorRecords :: CopyDate(Date& anotherDate) const
{
    anotherDate = m_date;
}
void SensorRecords :: CopyTemperature(Temperature& anotherTemp) const
{
    anotherTemp = m_temp;
}

void SensorRecords :: CopyWindSpeed(WindSpeed& anotherWindSpeed) const
{
    anotherWindSpeed = m_ws;
}

void SensorRecords :: CopySolarRadiation(SolarRadiation& anotherSolarRadiation) const
{
    anotherSolarRadiation = m_sr;
}
bool SensorRecords :: operator > (SensorRecords & AnotherTag)
{
    if(m_datatagging > AnotherTag.GetDataTag())
    {
        return true;
    }
    else
        return false;
}
bool SensorRecords :: operator < (SensorRecords & AnotherTag)
{
    if(m_datatagging < AnotherTag.GetDataTag())
    {
        return true;
    }
    else
        return false;
}
bool SensorRecords :: operator == (SensorRecords & AnotherTag)
{
    if (m_datatagging ==  AnotherTag.GetDataTag())
    {
        return true;
    }
    else
        return false;

}
void SensorRecords :: SetDataTag(int tag)
{
    m_datatagging = tag;
}
int SensorRecords :: GetDataTag()const
{
    return m_datatagging;
}


istream & operator >>( istream & input, SensorRecords & s )
{
//        Date d;
//        Time x;
//        WindSpeed ws;
//        SolarRadiation sr;
//        Temperature temp;
//        s.SetSolarRadiation(sr);
//        s.SetTemperature(temp);
//        s.SetTime(x);
//        s.SetDate(d);
//        input >> d >> x  >> ws >> sr >> temp >> endl;

    return input;
}

ostream & operator <<( ostream & os, const SensorRecords & s )

{

        Date d;
        Time x;
        WindSpeed ws;
        SolarRadiation sr;
        Temperature temp;
        s.CopySolarRadiation(sr);
        s.CopyTemperature(temp);
        s.CopyTime(x);
        s.CopyDate(d);
        os << d << x << ws <<sr << temp << endl;

    return os;
}
