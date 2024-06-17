#include "Date.h"
#include <iostream>
using namespace std;

int main ()
{
    cout << "============ Testing for Date Class =========" <<endl;

    Date s2;
    s2.SetDay(23); // 1)  mutator for day
    s2.SetMonth(12); // 2 ) mutator for month
    s2.SetYear(1994); // 3 ) mutator for year
    cout << "Day : " << s2.GetDay() <<endl; // 4) assessor for day
    cout << "Month : " << s2.GetMonth() << endl; // 5 ) assessor for month
    cout << "Year : " << s2.GetYear() << endl; // 6 ) assessor for year

    cout << "=========== assessor and mutator testing  Complete =================" << endl;

    cout << "Testing constructor Date Object" << endl;

    Date s3(26,10,1995); // 7 ) testing constructor of object assigning values , 26 days , 10 month , 1994 year
    cout << "Day : " << s3.GetDay() <<endl; //  assessor
    cout << "Month : " << s3.GetMonth() << endl; // assessor
    cout << "Year : " << s3.GetYear() << endl;// assesor

    cout << "Final Test :" << s3 << endl;

    //// test bool
    Date s4(25,11,2015);


    // which is nearer
    if(s3 < s4)
    {
        cout << " S3 is older than S4 " << endl;
    }
    else
    {
        cout <<" S4 is older than S3 " << endl;
    }

    return 0;
}
