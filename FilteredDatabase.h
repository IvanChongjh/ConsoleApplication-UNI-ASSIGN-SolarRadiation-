/****
@author Ivan Chong Jia Hao
@since 31/7/2023
@version 1.01
*/

#ifndef FILTEREDDATABASE_H_INCLUDED
#define FILTEREDDATABASE_H_INCLUDED
#include "Vector.h"
#include "SensorRecords.h"
#include <fstream>
#include <sstream>
#include <map>
#include "BSTx.h"


using namespace std;
/// DECLARTION OF DATA STRUCTURE HERE

class FilteredDatabase
{

private :
     /**
    This is used as reference for testing since assignment 1 is loaded into vector to cross reference
    @param Vector Database
    @return void
    */
    Vector <SensorRecords> database; /// vector to check values // counter check purpose

    /**
    This is the BST to store individual data within the month
    @param BST Database
    @return void
    */
    Bstx<SensorRecords> FilterSerialCode; // store all values for given month through sorting of time < > = operation
     /**
    This is the BST to store individual data within the month
    @param MAP Database that stores month as key and BST as value
    @return void
    */
    map<int,Bstx<SensorRecords>> FilterMonths; // filtered by key 1-13 month sorted for quick search
      /**
    This is the BST to store individual data within the month
    @param this is the map that hold keys to month map which holds bst
    @return void
    */
    map<int,map<int,Bstx<SensorRecords>>> FilterYears; // sorted by years 1 file data;

public :
    /// THE IDEA IS THAT SINCE WE GOT 4 years or more data we will first split the files cat by year;
    /// BY USING MAP FOR YEARS;
    /// TO MAINTAIN ENCAPSULATION THIS IS THE DATABASE CLASS
    /**
    mutator for setting database into set database value
    @param SensorRecords
    @return void
    */
    void SetDatabase(SensorRecords & details);
       /**
    assessor to return the entire database for copying purpose
    @param SensorRecords
    @return void
    */
    map<int,map<int,Bstx<SensorRecords>>> & GetFilteredDatabaseYears();
    /**
    assessor to return the entire bst for testing
    @param SensorRecords
    @return void
    */
    Bstx<SensorRecords> & GetFilteredDatabaseSerialCode();
     /**
    assessor to return the entire vector for testing
    @param SensorRecords
    @return void
    */
    Vector<SensorRecords> & GetDatabase();
     /**
     Load Function to load file into data base
    @param SensorRecords
    @return void
    */
    void LoadData(string filename); // loads data from input file into vector data
};


#endif // FILTEREDDATABASE_H_INCLUDED
