#include "FilteredDatabase.h"


void FilteredDatabase :: SetDatabase(SensorRecords & details)
{
    database.add(details);
}

Bstx<SensorRecords> & FilteredDatabase :: GetFilteredDatabaseSerialCode()
{
    return FilterSerialCode;
}
map<int,map<int,Bstx<SensorRecords>>> & FilteredDatabase ::GetFilteredDatabaseYears()
{
    return FilterYears;
}
Vector<SensorRecords> & FilteredDatabase :: GetDatabase() // return vector;
{
    return database;
}

void FilteredDatabase :: LoadData(string INPUT_FILENAME)
{
    ifstream inputfile(INPUT_FILENAME.c_str());// read into a file & gets the constant declared file name
    string x; // string declared to get a line string file name

    while (getline(inputfile,x)) // get one line in file
    {

        x = "data/" + x; // add to the front of the file, data/ indicative of location to read at
        cout << x << endl; // able to new file here
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
            Date d;
            Time t;
            SolarRadiation srx;
            WindSpeed ws;
            Temperature temp;

            int counterforserial = 0;
            int monthdata = 0;
            int yeardata = 0;
            int serialdata = 0;

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



            string values;
            while(getline(anotherfile,data))
            {
                if(!data.empty())
                {
                    checker++;
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

                    getline(myvalues, values, ','); // time
                    string time = values;

                    stringstream timex(time);
                    string split;
                    getline(timex,split,':');
                    int  hour = stoi(split);
                    getline(timex,split,' ');
                    int minutes = stoi(split);

                    d.SetDay(day);
                    d.SetMonth(month);
                    d.SetYear(year);
                    t.SetHour(hour);
                    t.SetMinute(minutes);
                    // date and time is considered  count 0
                    monthdata = month;
                    yeardata = year;


                    // the rest of date should start from 1 which is counter + 1;
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
                        temp.SetTemperature(temperature);
                        ws.SetWindSpeed(windspeed);
                        srx.SetSolarRadiation(SolarRadiation);
                    }

                }
                else
                    checkerx = false;

                if ( checkerx == true )
                {

                    SensorRecords sr(d,srx,ws,temp,t);
                    sr.SetDataTag(serialdata);
                    FilterMonths.insert(pair<int,Bstx<SensorRecords>>(monthdata,FilterSerialCode));
                    FilterYears.insert(pair<int,map<int,Bstx<SensorRecords>>>(yeardata,FilterMonths));
                    FilterYears[yeardata][monthdata].insertNode(sr);
                    database.add(sr); // vector cross check
                    serialdata++;// used for tagging data
                }
                else
                {
                    checkerx = true;
                }
                numofinputdata ++;
                counter = 0; // reset counter
            } // end while loop

            cout << " Year : " << yeardata << endl;
            cout << " Filter Years : " << FilterYears.size() << endl;
            cout << " Filter Months : " << FilterMonths.size() << endl;
        }
        else
        {
            cerr << "File " << x << " cannot be read !" << endl;
        }

    }
}
