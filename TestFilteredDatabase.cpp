#include <iostream>
#include  "FilteredDatabase.h"
#include "Date.h"
#include  "Time.h"
#include "WindSpeed.h"
#include "Temperature.h"
#include "SolarRadiation.h"
#include "SensorRecords.h"

void print(SensorRecords & sr)
{
    Date d;
    Temperature t;
    Time x;
    sr.CopyDate(d);
    sr.CopyTime(x);
    sr.CopyTemperature(t);
    cout << x.GetHour()<< "Hours" << x.GetMinutes()<< " Minutes" << endl;
    cout << " ===================== " << endl;
    cout << d << endl;
    cout << t <<endl;
}
using namespace std;

int main()
{

    Date date;
    date.SetDay(23);
    date.SetMonth(12);
    date.SetYear(1994);

    Time time;
    time.SetHour(1);
    time.SetMinute(30);

    Temperature temp;
    temp.SetTemperature(30.0);

    WindSpeed x;
    x.SetWindSpeed(123.3);

    SolarRadiation sr;
    sr.SetSolarRadiation(912.0);
    /// next data stimulating input from program;
     Date date1;
    date1.SetDay(1);
    date1.SetMonth(12);
    date1.SetYear(1994);

    Time time2;
    time2.SetHour(9);
    time2.SetMinute(32);

    Temperature tempx;
    tempx.SetTemperature(90.0);

    WindSpeed xr;
    xr.SetWindSpeed(1233.3);

    SolarRadiation srx;
    srx.SetSolarRadiation(9112.0);

    SensorRecords package(date,sr,x,temp,time);
    SensorRecords package1(date1,srx,xr,tempx,time2);

    /// setting tag by data unique to each for BST TO SORT
    package.SetDataTag(1);
    package1.SetDataTag(2);

    FilteredDatabase WindlogType;
    WindlogType.SetDatabase(package);
    Date d;

//    WindlogType.GetDatabase().at(0).GetDate(d);
//    cout << d << endl;
//    WindlogType.GetDatabase().at(0).GetDate(d);
//    cout << d << endl;




    Bstx<SensorRecords> FilterTimes; // bst
    Bstx<SensorRecords> FilterTimesTwo;
//    FilterTimes.insertNode(package); // overload the SensorRecords;
//    FilterTimes.insertNode(package1); // add data
//    cout << "============ One FilterTime ===============" << endl;
//    FilterTimes.inOrder(print);
//    FilterTimesTwo.insertNode(package);
//    FilterTimesTwo.insertNode(package1);
//    cout << "================ Data From Second BST  ===============" << endl;
//    FilterTimesTwo.inOrder(print);
//    FilterTimes.insertNode(package1);
//    FilterTimes.insertNode(package);
//    FilterTimes.inOrder(print);
//
//
//    FilterTimesTwo.insertNode(package1);
//    FilterTimesTwo.insertNode(package);

//    FilterTimes.inOrder(print); // check data
    map<int,Bstx<SensorRecords>> FilterMonths;
    /// Input Data into the FilterMonth
    FilterMonths.insert(pair<int,Bstx<SensorRecords>>(2014,FilterTimes));
    FilterMonths.insert(pair<int,Bstx<SensorRecords>>(2015,FilterTimesTwo));
    /// Checking Data from 2014
    FilterMonths[2014].insertNode(package1);
    FilterMonths[2014].insertNode(package);
    cout << " Testing INSERT AFTER DECLARATION "<<endl;
    FilterMonths[2014].inOrder(print);

    /// WORKS
    cout << " Testing MultiMap " << endl;
    map<int,map<int,Bstx<SensorRecords>>> FilterYears;
    FilterYears.insert(pair<int,map<int,Bstx<SensorRecords>>>(12,FilterMonths));

    FilterYears[12][2014].inOrder(print);
    cout << "============2015 =================" << endl;
    FilterYears[12][2015].inOrder(print);
    for (int i = 0 ; i <15; i ++)
    {
        FilterYears[12][2015].insertNode(package1);
        package1.SetDataTag(i);
        cout << i << endl;
    }
//    FilterYears[12][2015].insertNode(package1);
//    FilterYears[12][2015].insertNode(package);
    FilterYears[12][2015].inOrder(print);




    return 0;

}
