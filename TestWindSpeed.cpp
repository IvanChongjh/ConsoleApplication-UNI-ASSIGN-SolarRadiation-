#include <iostream>
#include "WindSpeed.h"
#include <string>
using namespace std;
int main()
{
    WindSpeed ws;
    ws.SetWindSpeed(203);
    cout << ws << endl;
     ws.GetWindSpeed();
    return 0;
}
