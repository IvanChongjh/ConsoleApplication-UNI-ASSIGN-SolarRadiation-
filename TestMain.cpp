#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include  "Time.h"
#include "WindSpeed.h"
#include "Temperature.h"
#include "SolarRadiation.h"
#include "SensorRecords.h"
#include "Menu.h"
#include "Vector.h"
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;
const string INPUT_FILENAME = "data_source.txt";
const string OUTPUT_FILENAME = "WindTempSolar.csv";


const char CSVDELIMITER = ','; // delimiter
const int SIZE_MONTH = 12; // num of months in year
const int AVG_WS_SSD_MY = 1; // option 1
const int AVG_AAT_SSD_MOY = 2; // option 2
const int T_SR_MOY =3; // option 3
const int AVG_WS_AAAT_T =4; // option 4
const int EXIT = 5;// option 5

//typedef struct
//{
//    Date d;
//    Time t;
//    WindSpeed ws;
//    Temperature temp;
//    SolarRadiation sr;
//} WindRecType;

//typedef Vector<SensorRecords> WindlogType; // Vector that stores "WindRecType" which is struct;
//void LoadData(string filename,WindlogType &data); // loads data from input file into vector data
//void PrintData(WindlogType &data);// prints out all information currently in vector
//float MatchCalculateMeanSpeed(WindlogType &data,int month,int year ); // matches the month specified by user and calculate
//float MatchFindSDSpeed(WindlogType &data,float mean,int month, int year); // matches the month specified by user and calculate
//string MonthToString(int month); // converts the month key in by user in int to string "january" for 1 example
//float MatchCalculateMeanTemp(WindlogType &data,int month,int year ); // calculates the mean temperature by year and output each month
//float MatchFindSDTemp(WindlogType &data,float mean,int month, int year); // calculates the sd for each month from year provided
//float MatchCalculateTotalSR(WindlogType &data,int month,int year ); // calculates total solar radiation
//void PrintMenu(); // prints menu
//void Menu(WindlogType &data,ofstream & outfilex); // control centre

int main()
{

    LoadData(INPUT_FILENAME);
    bool option= true;
    ofstream outfilex(OUTPUT_FILENAME);

    Menu(wind_data,outfilex);

    return 0;
}
void Menu(WindlogType & data,ofstream &outfilex)
{
    bool option= true;
    do
    {
        float MeanSpeed = 0;
        float SDSpeed = 0;
        float mean = 0;
        float SD = 0;
        int UserInput = 0;
        int month =0;
        int year = 0;
        int total =0;
        string monthx = "";
        int counter =1;

        PrintMenu();
        cin >> UserInput;
        if (UserInput >0 && UserInput <=5 )
        {
            switch(UserInput)
            {
            case  AVG_WS_SSD_MY:
                cout << "Enter Month followed by year:" << endl;
                cin >> month >> year;
                mean =  MatchCalculateMeanSpeed(data,month,year);
                SD = MatchFindSDSpeed(data,mean,month,year);
                monthx = MonthToString(month);
                if (mean  > 0)
                {
                    cout << monthx << " " << year <<":"<< endl;
                    cout << "Average speed:"<<fixed<<setprecision(1)<<mean<<"km/h"<<endl;
                    cout << "Sample Stdev:"<<fixed<<setprecision(1)<<SD<<endl;

                }
                else
                {
                    cout << monthx << " " << year <<":"<< " No Data"<<endl;
                }

                break;
            case AVG_AAT_SSD_MOY:

                cout << "Enter year:" << endl;
                cin  >> year;
                while(counter <= SIZE_MONTH)
                {
                    mean = 0;
                    SD = 0;

                    mean =  MatchCalculateMeanTemp(data,counter,year);
                    monthx = MonthToString(counter);
                    SD = MatchFindSDTemp(data,mean,counter,year);

                    if (mean  > 0)
                    {
                        cout << monthx <<":"<< "average :"<<mean<<" degrees C,"<<"stdev:"<<SD<<endl;

                    }
                    else
                    {
                        cout << monthx <<":"<< "No Data"<<endl;

                    }
                    counter ++;

                }
                break;
            case T_SR_MOY:
                cout << "Enter year:" << endl;
                cin  >> year;
                while(counter <= SIZE_MONTH)
                {

                    total =  MatchCalculateTotalSR(data,counter,year); // change
                    monthx = MonthToString(counter);


                    if (total  > 0 )
                    {
                        cout << monthx <<":"<<total<<"kWh/m^2"<<endl;

                    }
                    else
                    {
                        cout << monthx <<":"<< "No Data"<<endl;

                    }
                    counter ++;

                }
                break;
            case AVG_WS_AAAT_T:
                cout << " Enter Year :"<< endl;
                cin >> year;
                outfilex << year << endl;
                outfilex << "Month"<<","<< "Average Wind Speed(stdev)"<<","<<  "Average Ambient Temperature(stdev)"<<","<<  "Solar Radiation"<< endl;

                while(counter <= SIZE_MONTH) // for temp
                {
                    mean = 0;
                    SD = 0;
                    MeanSpeed = 0;
                    SDSpeed =0;

                    MeanSpeed =  MatchCalculateMeanSpeed(data,counter,year); // 1)windspeed
                    SDSpeed = MatchFindSDSpeed(data,MeanSpeed,counter,year);

                    mean =  MatchCalculateMeanTemp(data,counter,year); // 2 )change // temperature
                    SD = MatchFindSDTemp(data,mean,counter,year); // change // temperature

                    total =  MatchCalculateTotalSR(data,counter,year); // 3) for total SR
                    monthx = MonthToString(counter);

                    if (mean  > 0)
                    {
                        cout << monthx <<fixed<<setprecision(1)<<","<< MeanSpeed<<"("<<SDSpeed<<fixed<<setprecision(1)<<"),"<<mean<<fixed<<setprecision(1)<<"("
                             <<SD<<fixed<<setprecision(1)<<"),"<<total<<fixed<<setprecision(1)<<endl;
                        outfilex << monthx <<fixed<<setprecision(1)<<","<< MeanSpeed<<"("<<SDSpeed<<fixed<<setprecision(1)<<"),"<<mean<<fixed<<setprecision(1)<<"("
                                 <<SD<<fixed<<setprecision(1)<<"),"<<total<<fixed<<setprecision(1)<<endl;


                    }
                    else
                    {
                        cout << year << endl;
                        cout << monthx <<":"<< "No Data"<<endl;

                    }
                    counter ++;
                }
                outfilex.close();
                break;
            case EXIT :
                cout << " Program Exiting "<<endl;
                option = false;
                break;
            }

        }
        else
            cout << "Invalid Input" << endl;


    }
    while(option);

}


void LoadData(string filename,WindlogType &datas)
{

    ifstream inputfile(INPUT_FILENAME.c_str()); // filename;
    string x;
    getline(inputfile,x);
    ifstream anotherfile(x.c_str());
    if(anotherfile.rdstate() == 0 ) // read state 0 means ready to be read;
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
//        WindRecType package;

        string header;
        string txt;
        getline(anotherfile, header);
        stringstream mystream(header);
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

            // date and time is considered  count 0


            // the rest of date should start from 1 which is counter + 1;
            float windspeed = 0.0;
            float temperature = 0.0;
            double SolarRadiation = 0.0;
            counter = 1;
            while( counter <= trackercounter)
            {
                getline(myvalues,values,',');

                if(counter == trackposspeed)
                {
                    windspeed = stof(values); // WindSpeed data
                }
                if(counter == trackerpost)
                {
                    temperature = stof(values); // Temperature data
                }
                if(counter == trackerpossr) // SolarRadiation data
                {
                    SolarRadiation = stod(values);
                }
                counter++; // count to end of data while extracting windspeed
            }

            // sensorrecord obj

            // set values to struct date,time,speed WindRecType

//            package.d.SetDay(day);
//            package.d.SetMonth(month);
//            package.d.SetYear(year);

            d.SetDay(day);
            d.SetMonth(month);
            d.SetYear(year);

//            package.temp.SetTemperature(temperature);
            temp.SetTemperature(temperature);
//            package.ws.SetWindSpeed(windspeed);
            ws.SetWindSpeed(windspeed);
//            package.t.SetTime(time);
            t.SetTime(time);
//            package.sr.SetSolarRadiation(SolarRadiation);
            srx.SetSolarRadiation(SolarRadiation);
            SensorRecords sr(d,srx,ws,temp,t);
//            sr(d,srx,ws,temp,t);
//            cout << d.GetDay()<<"/"<<d.GetMonth()<<"/"<<d.GetYear()<< "WindSpeed :" <<ws.GetWindSpeed()<<
//            "Time : " << t.GetTime() << " SolarRadiation " << srx.GetSolarRadiation() << endl;
            datas.add(sr);

            Menu m;
            SensorRecords s;
            Date x;

            s.GetDate(x);
            cout << x.GetDay() << x.GetMonth() << x.GetYear() << endl;
            numofinputdata ++;
            counter = 0; // reset counter
        } // end while loop

    }
    else
    {
        cerr << "File" << INPUT_FILENAME << "cannot be read !" << endl;
    }

}

//void PrintData(WindlogType &data)
//{
//    for(int i = 0 ; i < data.size() ; i ++)
//    {
//
//        cout << "Date :" << data[i].d.GetDay() << "/" << data[i].d.GetMonth()<<"/" << data[i].d.GetYear() << endl;
//        cout << "Time : " << data[i].t.GetTime() <<endl;
//        cout << "WindSpeed(Mps)" << data[i].t.GetTime()<<endl;
//        cout << "Entry Number :" << i << endl;
//    }
//}


float MatchCalculateMeanSpeed(WindlogType &data,int month,int year )
{
    float mean=0.0;
    float sum = 0.0;
    int numx =0 ; // counter for match data
    Date d;
    WindSpeed ws;
    for ( int i = 0 ; i < data.size() ; i ++ ) // grouping data; using one as reference each time scan the rest
    {
            data[i].GetDate(d);


        if (month == d.GetMonth() && year == d.GetYear())// matching date and year
        {

              data[i].GetWindSpeed(ws);
            sum += ws.GetWindSpeed(); // add speed if match month and year;



            numx++; // count number added to calculate mean;

        }

    }

    if (sum > 0 )
    {
        mean = sum/numx;
        mean *= 3.6;
        return mean;
    }
    else
        return 0;

}
float MatchFindSDSpeed(WindlogType &data,float mean,int month, int year)
{
    float meanx = mean/3.6;
    float sum = 0.0;
    int counterx = 0;
    float SD = 0.0;
    Date d;
    WindSpeed ws;
    for(int i = 0 ; i < data.size() ; i++)
    {
        data[i].GetDate(d);
        data[i].GetWindSpeed(ws);
        if (month == d.GetMonth() && year == d.GetYear())
        {

            sum +=(ws.GetWindSpeed() - meanx) * (ws.GetWindSpeed() - meanx);
            counterx ++ ;
        }
    }

    SD = sqrt(sum/counterx) * 3.6;

    return SD;
}
string MonthToString(int month)
{
    if (month >0 && month <= SIZE_MONTH)
    {
        if (month == 1)
            return "January";
        if (month == 2)
            return "February";
        if (month == 3)
            return "March";
        if (month == 4)
            return "April";
        if (month == 5)
            return "May";
        if (month == 6)
            return "June";
        if (month == 7)
            return "July";
        if (month == 8)
            return "August";
        if (month == 9)
            return "September";
        if (month == 10)
            return "October";
        if (month == 11)
            return "November";
        if (month == 12)
            return "December";

    }
    else
    {
        cout << "invalid month" <<endl;
    }
}
float MatchCalculateMeanTemp(WindlogType &data,int month,int year )
{

    float sum =0;
    int numx =0; // counter for match data
    Date d;
    Temperature t;
    for ( int i = 0 ; i < data.size() ; i ++ ) //  loop through datasize
    {
        data[i].GetDate(d);
        data[i].GetTemperature(t);
        if (month == d.GetMonth() && year == d.GetYear()) // month match data month and year matched user defined year
        {


            sum += t.GetTemperature(); // add speed if match month and year; // will add all temp values that matched this month and year
            numx++; // count number added to calculate mean;

        }

    }
    if (sum > 0 && numx > 0)
    {
        float mean = sum/numx;
        return mean;
    }
    else
    {
        return 0;
    }

}
float MatchFindSDTemp(WindlogType &data,float mean,int month, int year)
{
    int counterx = 0;
    float sum = 0.0;
    Date d;
    Temperature t;
    for(int i = 0 ; i < data.size() ; i++)
    {
        data[i].GetDate(d);
        data[i].GetTemperature(t);
        if (month == d.GetMonth() && year == d.GetYear())
        {
            sum +=(t.GetTemperature()-(mean)) * (t.GetTemperature() - (mean));
            counterx++;

        }
    }
    return sqrt(sum/counterx);
}
float MatchCalculateTotalSR(WindlogType &data,int month,int year )
{

    double sum =0;
    Date d;
    SolarRadiation sr;
    for ( int i = 0 ; i < data.size() ; i ++ ) //  loop through datasize
    {
        data[i].GetDate(d);
        data[i].GetSolarRadiation(sr);
        if (month == d.GetMonth() && year == d.GetYear()) // month match data month and year matched user defined year
        {

            sum += sr.GetSolarRadiation(); // add speed if match month and year; // will add all temp values that matched this month and year
        }

    }
    if (sum > 0)
    {
        sum = sum/6000 ;
        return sum;
    }
    else
    {
        return 0;
    }

}
void PrintMenu()
{
    cout << "1 : The Average WindSpeed & Standard Deviation given a specified month and year"<< endl;
    cout << "2 : The Average Ambient Air Temperature & Standard Deviation given for each month and year"<< endl;
    cout << "3 : The Total Solar Radiation in Kw/m^2 for each month of a specified year "<< endl;
    cout << "4 : The Average WindSpeed & Average Ambient Air Temperature \n& Total Solar Radiation in kw/m^2 for each specified month and year"<< endl;
    cout << "5 : Exit Menu"<<endl;
}
