#include <iostream>
#include "Bstx.h"
#include "Date.h"
#include <fstream>
#include <sstream>
const string INPUT_FILENAME = "data/data_source.txt";// input file location and name of file
const string OUTPUT_FILENAME = "data/WindTempSolar.csv"; // output file location and name of file
void print(Date &d)
{
    cout<< d<<endl;
}
int main ()
{

//    Bst<Date> DateTree;
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
    Bstx<Date> dateTree;
    ifstream inputfile(INPUT_FILENAME.c_str());// read into a file & gets the constant declared file name
    string x; // string declared to get a line string file name
    Date d;
    while (getline(inputfile,x)) // get one line in file
    {

        x = "data/" + x; // add to the front of the file, data/ indicative of location to read at
        cout << x << endl;
        ifstream anotherfile(x.c_str());

        if(anotherfile.rdstate() == 0) // read state 0 means ready to be read;
        {

            cout << "file ready.. reading file..." << endl;
            string data;
            int trackerpost = 0;
            int counter = 0;
            int trackerpossr = 0;// position of Solar Radiation
            int trackposwast =0; // position of WAST in data
            int trackposspeed = 0; // position of WindSpeed
            int trackercounter = 0; // count to limit of column values
            int checker =0;
            int numofinputdata = 0;

            string header;
            string txt;
            getline(anotherfile, header);
            stringstream mystream(header);
            bool checkerx = true;
            while (getline(mystream, txt, ','))
            {
                if (txt == "WAST")
                {
                    trackposwast = trackercounter;
                }
                if  (txt == "S")
                {
                    trackposspeed = trackercounter;
                }
                if (txt == "T")
                {
                    trackerpost = trackercounter;
                }
                if (txt == "SR")
                {
                    trackerpossr = trackercounter;
                }

                trackercounter++;
            }

///////////////// read header file //////////////////////////////////////////////////////////

            string values;
            while(getline(anotherfile,data)) // get data of whole line;
            {

                if(!data.empty())
                {
//                    cout << data << endl;
                    checker++;
                    stringstream myvalues(data);
                    getline(myvalues,values,' ');

                    stringstream date(values);
                    string datesplit;
                    getline(date,datesplit,'/'); // day
                    int day = stoi(datesplit);
                    getline(date,datesplit,'/'); // month
                    int month = stoi(datesplit);
                    getline(date,datesplit,'/'); // year
                    int year = stoi(datesplit);

                    getline(myvalues, values, ','); // time
                    string time = values;

                    d.SetDay(day);
                    d.SetMonth(month);
                    d.SetYear(year);
                    float windspeed = 0.0;
                    float temperature = 0.0;
                    float SolarRadiation = 0.0;
                    counter = 1;
                    while( counter <= trackercounter)
                    {
                        getline(myvalues,values,',');

                        if(counter == trackposspeed)
                        {

                            if (values == "N/A" || values.empty())
                            {
                                checkerx = false; // false data
                            }
                            else
                                windspeed = stof(values); // WindSpeed data
                        }
                        if(counter == trackerpost)
                        {
                            if (values == "N/A" || values.empty())
                            {
                                checkerx = false; // false data
                            }
                            else
                                temperature = stof(values); // Temperature data
                        }
                        if(counter == trackerpossr) // SolarRadiation data
                        {
                            if (values == "N/A" || values.empty())
                            {
                                checkerx = false; // false data
                            }
                            else
                                SolarRadiation = stof(values);
                        }
                        counter++; // count to end of data while extracting windspeed
                    }



                }
                else
                    checkerx = false;


                if (checkerx == true)
                {

                    dateTree.insertNode(d);

                }
                else
                {

                    checkerx = true;

                }


//                temp.SetTemperature(temperature);
//
//                ws.SetWindSpeed(windspeed);
//
//                t.SetTime(time);
//
//                srx.SetSolarRadiation(SolarRadiation);
//                SensorRecords sr(d,srx,ws,temp,t);
//
//                datas.add(sr);
                numofinputdata ++;
                counter = 0; // reset counter
            } // end while loop

        }
        else
        {
            cerr << "File " << x << " cannot be read !" << endl;
        }

    }


    dateTree.inOrder(print);
    cout << "after delete " << endl;
    dateTree.deleteBST();
    dateTree.inOrder(print);

//       dateTree.inOrder(print);


    return 0;
}
