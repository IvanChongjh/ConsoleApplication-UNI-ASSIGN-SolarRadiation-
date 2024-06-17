#include <iostream>
#include "Temperature.h"
#include <string>
using namespace std;
int main()
{
    Temperature temp(20.232);
    temp.SetTemperature(203.123);
    cout << temp<< endl;

    return 0;
}
