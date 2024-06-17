#include <iostream>
#include "Date.h"
#include "Bst.h"
#include <unordered_map> // ordered or unordered
#include <string>
using namespace std;
int main()
{
//    unordered_map<string,string> myDictionary;
//    myDictionary.insert(pair<string,string>("Apple"," der Apfel")); // left is key , right is data
//    myDictionary.insert(pair<string,string>("Banana"," der Banane"));
//    myDictionary.insert(pair<string,string>("Orange"," der Apfelsine"));
//    myDictionary["Apple"] ="Die Erdbeere"; // change element
////    cout << myDictionary.size() << endl; // check size
//
////    myDictionary.clear(); // clear all in map
//
////    cout << myDictionary.size() << endl; // check size 0 cause cleared
//    for(auto pair : myDictionary )
//    {
//        cout << pair.first<<"-" << pair.second<< endl; // print key , data;
//
//    }
    Date d;
    d.SetDay(25);
    d.SetMonth(12);
    d.SetYear(1933);
//
//    unordered_map<string,Date> myDictionary;
//    myDictionary.insert(pair<string,Date>("1",d)); // using date to store into map and key is 1;
//
//    for(auto pair: myDictionary)
//    {
//        cout << pair.first << " -";
//        cout << pair.second<< ",";
//    }

    Bst<int> bs;
    bs.insertNode(15);
    bs.insertNode(20);
    bs.insertNode(12);
    bs.insertNode(15);
    bs.inOrder();cout << endl;

    unordered_map<int,Bst<int>> testing;
    testing.insert(pair<int,Bst<int>>(12,bs));

    unordered_map<int,Date> myDictionary;
    myDictionary.insert(pair<int,Date>(d.GetMonth(),d)); // using date to store into map and key is 1;
//
//    for(auto pair: myDictionary)
//    {
//        cout << pair.first << " -";
//        cout << pair.second<< ",";
//    }
//    unordered_map<string,unordered_map<int,Date>> datastruct; // putting a map into a map; key is month
//
//    datastruct.insert(pair<string,unordered_map<int,Date>>("1994",myDictionary));
//    for(auto pair: datastruct)
//    {
//        cout << pair.first<< " - ";
//        for(auto pair : myDictionary)
//        {
//            cout<<pair.first << " -";
//            cout<<pair.second<< " ,";
//        }
//    }



    return 0;
}
