#include <iostream>
#include "SolarRadiation.h"
#include <string>
using namespace std;
int main()
{
    SolarRadiation sr(20.232);
    sr.SetSolarRadiation(203.123);
    cout << " here " << sr.GetSolarRadiation() << endl;
    cout << sr<< endl;

    return 0;
}
