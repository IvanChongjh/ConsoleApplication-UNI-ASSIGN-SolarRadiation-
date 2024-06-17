#include <iostream>
#include "Vector.h"
#include <string>
using namespace std;
int main ()
{
    Vector<int> numbers; // 1)  testing creation of vector called number with int variables ;
    cout << "managed to create numbers" << endl;

    Vector <string> strings; //2 )  testing creation of vector called strings with strings variable;
    cout<< "managed to create strings" << endl;

    for ( int i = 0 ; i < 8 ; i ++ )
    {
        numbers.add(i);  //3 ) testing pushback or add element

    }
    for (int i = 0 ; i < 8; i ++ ){

        cout << " Values : " << numbers[i] <<endl;
    }

    cout << " Size of Vector / number of elements : " << numbers.size() << endl; // 4 ) Testing Check element size()
    cout << " The New Capacity is : " << numbers.capacity() << endl; // 5 ) Testing Capacity number of capacity
    cout << "Number at [0] is : " << numbers[0] << endl; // 6 ) testing number[] operator

    numbers.InsertAt(3,500); // 7)  testing insertAt index 3 , value 500
    cout << "Value at index 3 : " << numbers[3] << endl;// verify details;

    for (int i = 0 ; i < 9 ; i ++ )
    {
        cout <<"index [" << i << "] " << "Value :" << numbers[i] << endl;
    }
    cout << " New The Number at 8 : " << numbers[8] << endl;
    cout << " The New Element Size is : " << numbers.size() << endl;
    cout << " The New Capacity is : " << numbers.capacity() << endl;

    cout << " testing delete from " << endl;
    numbers.deletefrom(3,5); // 8 ) testing delete from



    for ( int i = 0 ; i < numbers.size() ; i ++ )
    {
    cout << "Values in array after deleting  " << " index  : "  << i << "  value  :" << numbers[i]  << endl;
    }
    cout << " Number Vector New Size : " << numbers.size() <<endl;
    cout << " Number Vector New Capacity : " << numbers.capacity() << endl;


    Vector <int> test(10); // testing constructor over loading 9 ) assigning size with 10 elements
    cout << " successfully created " << endl;
    cout << " Size of test : " << test.size()<<endl;
    cout << " capacity of test : " << test.capacity()<<endl;


    Vector <int> test1(0);
    cout << " Successfully created " << endl;
    cout << " Size of test : " << test1.size()<<endl;
    cout << " capacity of test : " << test1.capacity()<< endl;

    test = test1; // 10 ) testing assignment operator = "="
    cout << " Size of test : " << test.size()<<endl;
    cout << " capacity of test : " << test.capacity()<<endl;
    Vector <int>test3(100);
    test = test3;

    cout << " Size of test : " << test.size()<<endl;
    cout << " capacity of test : " << test.capacity()<<endl;
    test.remove(); // 11 ) testing  remove
    cout << " Size of test : " << test.size()<<endl;
    cout << " capacity of test : " << test.capacity()<<endl;
    test.modifyAt(5,50); // 12 ) testing modify at

    cout << test[5] << endl;

    if (!test.empty()) // 13     ) testing empty () checks if vector is empty
    {
        cout << "implementation successful for empty()" << endl;
    }


    return 0;

}
