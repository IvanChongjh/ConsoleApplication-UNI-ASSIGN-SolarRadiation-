#include <iostream>
#include  "FilteredDatabase.h"
#include "Date.h"
#include  "Time.h"
#include "WindSpeed.h"
#include "Temperature.h"
#include "SolarRadiation.h"
#include "SensorRecords.h"
#include "Operations.h"

using namespace std;
int main ()
{
    Date date;
    date.SetDay(23);
    date.SetMonth(12);
    date.SetYear(1994);

    Time time;
    time.SetTime("12:20");

    Temperature temp;
    temp.SetTemperature(92.0);

    WindSpeed x;
    x.SetWindSpeed(123.3);

    SolarRadiation sr;
    sr.SetSolarRadiation(912.0);

    SensorRecords package(date,sr,x,temp,time);

    FilteredDatabase WindlogType;
    WindlogType.SetDatabase(package);
    WindlogType.SetDatabase(package);
    WindlogType.SetDatabase(package);
    Date d;

    WindlogType.GetDatabase().at(0).GetDate(d);
    WindlogType.GetDatabase().at(1).GetDate(d);
    WindlogType.GetDatabase().at(2).GetDate(d);
    cout << d << endl;
    cout << "Testing Sync Database" << endl;
    Operations os;
    os.SycDatabase(WindlogType);
    os.TestDuplication();

    return 0;
}
