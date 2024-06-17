#include <iostream>
#include "SolarRadiation.h"
#include "Time.h"
#include "Temperature.h"
#include "date.h"
#include "WindSpeed.h"
#include "SensorRecords.h"
#include "Vector.h"
#include <string>
 typedef Vector<SensorRecords> WindlogType;
using namespace std;
int main()
{

    WindlogType wind_data;
    SensorRecords sr;
    Date d;
    d.SetDay(23);
    d.SetMonth(12);
    d.SetYear(1994);
    cout << d << endl;
    // testing loading into vector with sensor record class;
    sr.SetDate(d);
    wind_data.add(sr);
    // added sr into vect
    // trying to get dataout now
    Date x;
    wind_data[0].CopyDate(x);
    cout << "final test for date :"<< d << endl;


    return 0;
}
