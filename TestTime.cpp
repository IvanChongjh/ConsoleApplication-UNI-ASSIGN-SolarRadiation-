#include <iostream>
#include "time.h"
#include <string>

int main()
{
    Time test("9:00"); // 1) testing constructor
    std::cout << " Time :" << test.GetTime() << std::endl; // 2) assessor get value
    test.SetTime("12:00"); // 3 ) mutator  change value
    std::cout << " Time :" << test.GetTime() << std::endl;
    std::cout << " Value :" << test << std::endl;

    return 0;
}
