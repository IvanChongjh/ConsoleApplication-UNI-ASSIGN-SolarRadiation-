
#include "Date.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Bstx.h"
const string INPUT_FILENAME = "data/data.txt";// input file location and name of file
const string OUTPUT_FILENAME = "data/WindTempSolar.csv"; // output file location and name of file
using namespace std;
//void print (Date & d)
//{
//    cout <<d <<endl;
//}
int main ()
{

//
//
//    Date d1(26,8,2014);
//    Date d2(23,7,2014);
//    Date d3(25,1,2013);
//    Date d4(10,1,1994);
//    DateTree.insertNode(d1);
//    DateTree.insertNode(d2);
//    DateTree.insertNode(d3);
//    DateTree.insertNode(d4);
//    DateTree.preOrder();
//    DateTree.postOrder();
//    DateTree.inOrder();
//
    Bstx<Date> DateTree;

    ifstream inputfile(INPUT_FILENAME.c_str());
    string data;
    string values;
    Date d;


    if(inputfile.rdstate() == 0) // read state 0 means ready to be read;
    {

        cout << "file ready.. reading file..." << endl;
        while(getline(inputfile,data))
        {

            stringstream myvalues(data);
            getline(myvalues,values,' '); // date in 320222017 format
            stringstream date(values);
            string datesplit;
            getline(date,datesplit,'/'); // day
            int day = stoi(datesplit);
            getline(date,datesplit,'/'); // month
            int month = stoi(datesplit);
            getline(date,datesplit,'/'); // year
            int year = stoi(datesplit);

            d.SetDay(day);
            d.SetMonth(month);
            d.SetYear(year);
           cout << "Date : " << d.GetDay() << "/ Month : " << d.GetMonth() << " / Year : " << d.GetYear() << endl;
            DateTree.insertNode(d);


        }
    }
    else
    {
        cerr << "File " << data << " cannot be read !" << endl;
    }

    // testing search data
    Date x(1,1,2015);
    if(DateTree.searchData(x))
    {
        cout << "Data found " << endl;
    }
    else
        cout << "Not Found " << endl;
     DateTree.inOrder(print);
    DateTree.deleteBST();
    DateTree.inOrder(print);
    return 0;
}
