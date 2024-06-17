/****
@author Ivan Chong Jia Hao
@since 31/7/2023
@version 1.01
*/
#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED
#include "FilteredDatabase.h"
#include "SensorRecords.h"
#include "Date.h"
#include  "Time.h"
#include "WindSpeed.h"
#include "Temperature.h"
#include "SolarRadiation.h"
#include "SensorRecords.h"
#include "Vector.h"
#include "cmath"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
/// DECLARED CONSTANT TO PREVENT CHANGES
const char CSVDELIMITER = ','; // delimiter
const int SIZE_MONTH = 12; // num of months in year
const int AVG_WS_SSD_MY = 1; // option 1
const int AVG_AAT_SSD_MOY = 2; // option 2
const int T_SR_MOY =3; // option 3
const int AVG_WS_AAAT_T =4; // option 4
const int EXIT = 5;// option 5
using namespace std;

class Operations
{
private:
    /**
    Vector to store key values of years that have been loaded in to database
    @param int
    @return void
    */
    Vector<int> keys; /// store keys values for option 3
    /**
    Vector to store test values
    @param SensorRecords
    @return void
    */
    Vector<SensorRecords> data; // vector data for testing
    /**
    map key that stores year, holds value to map month key and BST for data
    @param map
    @return void
    */
    map<int,map<int,Bstx<SensorRecords>>> filterdata; // clone data from actual database
    /// MatchCalculateMeanSpeed option 1
    /**
    This static vector is to pull out data from function ptr, in BST Traversals, Data use for calculations
    @param vector
    @return static
    */
    static Vector<SensorRecords> dataout; // clone bst data for calculation

public :
    /// THIS CLASS IS MEANT FOR OPERATION USAGE, USER INTERACTIONS / CALCULATIONS
    /**
    Method to extract data from main database to maintain encapsulation
    @param FilteredDatabase
    @return void
    */
    void SycDatabase(FilteredDatabase & database); /// syc vector to check values (testing only )
    void SycFilteredDatabase(FilteredDatabase & data);/// syc filtered data
    /**
    just to print out for testing purpose ;
    @param
    @return void
    */
    void TestDuplication();
    /**
    This is the BST Traversal function ptr method; use for BST to call out data
    @param SensorRecord
    @return void
    */
    static void CollectionOfData(SensorRecords & data) /// Collect data from bst and populate to static variable
    {
        Date d;
        Time x;
        WindSpeed windspeed;
        SolarRadiation srx;
        Temperature temp;
        data.CopySolarRadiation(srx);
        data.CopyTemperature(temp);
        data.CopyWindSpeed(windspeed);
        data.CopyTime(x);
        data.CopyDate(d);
        SensorRecords sensor(d,srx,windspeed,temp,x);
        dataout.add(sensor); // adding data to static vector

    }
    /**
    Method for calculating Mean Speed
    @param int, month , year
    @return float
    */
    float MatchCalculateMeanSpeed(int &month,int &year ); // matches the month specified by user and calculate
    /**
    Method for calculating  SD speed
    @param int,month,year
    @param float mean
    @return float
    */
    float MatchFindSDSpeed(float &mean,int &month, int &year); // matches the month specified by user and calculate
    /**
    Method for converting MonthToString
    @param float month
    @return string
    */
    string MonthToString(int&month); // converts the month key in by user in int to string "january" for 1 example
    /**
    Method for calculating Average Temp
    @param int,month,year
    @return float
    */
    float MatchCalculateMeanTemp(int &month,int &year ); // calculates the mean temperature by year and output each month
    /**
    Method for calculating  SD Temp
    @param int,month,year
    @param float mean
    @return float
    */
    float MatchFindSDTemp(float &mean,int &month, int &year); // calculates the sd for each month from year provided
    /**
    Method for calculating total SR
    @param int,month,year
    @return float
    */
    float MatchCalculateTotalSR(int &month,int &year ); // calculates total solar radiation
    /**
    Method for printing Menu
    @return void
    */
    void PrintMenu(); // prints menu
    /**
    Method for loading menu
    @param string outfielx
    @return void
    */
    void Menu(string outfilex); // control centre
    /**
     Method for calculating Average Ambient Temperature
    @param int,month,year
    @return float
    */
    float AverageAmbientTemperature(int & month,int & year);
    /**
    Method for calculating Average Radiation
    @param int,month,year
    @return float
    */
    float AverageSolarRadiation(int & month,int & year);
    /**
    Method for calculating  SPCC
    @param int,month,year
    @return float
    */
    float sPCC(int & month,int & year);


};


#endif // OPERATIONS_H_INCLUDED
