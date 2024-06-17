#include "Operations.h"

void Operations ::SycDatabase(FilteredDatabase & database)
{
    data = database.GetDatabase(); //  By using the vector operator = we are performing deep copy of data;
}
void Operations :: SycFilteredDatabase(FilteredDatabase & data)
{
    filterdata = data.GetFilteredDatabaseYears(); // Get Map Values Year/months
}

void Operations :: Menu(string outfile)
{
    ofstream outfilex(outfile);
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
            case  AVG_WS_SSD_MY: /// option 1
                cout << "Enter Month followed by year:" << endl;
                cin >> month >> year;
                mean =  MatchCalculateMeanSpeed(month,year);
                SD = MatchFindSDSpeed(mean,month,year);
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
            case AVG_AAT_SSD_MOY: /// option 2 SORT BY YEAR /// create a list for input years and month

                cout << "Enter year:" << endl;
                cin  >> year;


                while(counter <= SIZE_MONTH) // loop through to 12
                {
                    mean = 0;
                    SD = 0;
                    mean =  MatchCalculateMeanTemp(counter,year); // return mean or 0
                    monthx = MonthToString(counter); // takes counter and convert to string to print out
                    SD = MatchFindSDTemp(mean,counter,year); // calculate SD

                    if (mean  > 0)
                    {
                        cout << monthx <<":"<< "average :"<<fixed<<setprecision(1)<<mean<<" degrees C,"<<"stdev:"<<SD<<endl;

                    }
                    else
                    {
                        cout << monthx <<":"<< "No Data"<<endl;

                    }
                    counter ++;

                }
                break;
            case T_SR_MOY: // Option 3 sort by year display all months
//                cout << " Enter Month : " << endl;
//                cin >> month;

//                for(auto it = filterdata.begin(); it !=filterdata.end(); it ++) /// this will loop through map to get key
//                {
//                    keys.add(it->first); /// store key into vector
//                }
                /// Avg Wind Speed  and ambient temp S_T
//                for(int i = 0 ; i <keys.size(); i ++ ){
//                     MeanSpeed = MatchCalculateMeanSpeed(month,key[i]); /// will give avg wind for that month
//                      mean = MatchCalculateMeanTemp(month,year);
//                }


                break;
            case AVG_WS_AAAT_T: // option 4 SORT BY YEAR
                cout << " Enter Year :"<< endl;
                cin >> year;
                outfilex << year << endl;
                outfilex << "Month"<<","<< "Average Wind Speed(stdev)"<<","<<  "Average Ambient Temperature(stdev)"<<","<<  "Solar Radiation"<< endl;

                while(counter <= 12) // for temp
                {
                    mean = 0;
                    SD = 0;
                    MeanSpeed = 0;
                    SDSpeed =0;

                    MeanSpeed =  MatchCalculateMeanSpeed(counter,year); // 1)windspeed
                    SDSpeed = MatchFindSDSpeed(MeanSpeed,counter,year);

                    mean =  MatchCalculateMeanTemp(counter,year); // 2 )change // temperature
                    SD = MatchFindSDTemp(mean,counter,year); // change // temperature

                    total =  MatchCalculateTotalSR(counter,year); // 3) for total SR
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


float Operations::AverageSolarRadiation(int & month, int & year)
{
     float sum =0;
    Date d;
    SolarRadiation sr;
    int counter = 0;
    float mean = 0;
    filterdata[year][month].inOrder(CollectionOfData);

    if ( dataout.size() != 0)
    {
        for ( int i = 0 ; i < dataout.size() ; i ++ ) //  loop through datasize
        {
            dataout[i].GetDate(d);
            dataout[i].GetSolarRadiation(sr);
            if (month == d.GetMonth() && year == d.GetYear()) // month match data month and year matched user defined year
            {
                sum += sr.GetSolarRadiation(); // add speed if match month and year; // will add all temp values that matched this month and year
            }
            counter ++ ;
        }

        sum = sum/6000;
        mean = sum/counter;
        return mean;
    }
    else
    {
        return 0;
    }
}
//float Operations::sPCC(int & month,int & year, float & meanspeed , float & meantemp)
//{
//    float R = 0.0
//    float sum = 0.0
//    filterdata[year][month].inOrder(CollectionOfData);
//    WindSpeed wx;
//    float denominator = 0.0;
//    float sum1 = 0.0;
//    float sum2 = 0.0
//    Temperature temp;
//    Date d;
//    if(dataout.size() != 0)
//    {
//
//        for (int i = 0 ; i < dataout.size ; i ++ )
//        {
//                    dataout[i].GetDate(d)
//                    dataout[i].GetWindSpeed(wx);
//                    dataout[i].GetTemperature(temp);
//                    if ( d.GetMonth() == month  && d.GetYear() == year)
//                    {
//                        sum += ((wx.GetWindSpeed()- meanspeed)*(temp.GetTemperature()- meantemp))
//                        sum1 = (wx.GetWindSpeed() - meanspeed)* (temp.GetTemperature()-)
//                    }
//
//        }
//
//
//    }
//
//}

void Operations::Operations :: TestDuplication()
{
    Date d;
    SolarRadiation r;
    Temperature temp;
    for(int i = 0 ; i < data.size(); i ++)
    {
        data.at(i).GetDate(d);
        cout << d << endl;
        data.at(i).GetSolarRadiation(r);
        cout << r << endl;
        data.at(i).GetTemperature(temp);
        cout << temp << endl;
    }
}
void Operations :: PrintMenu()
{
    cout << "1 : The Average WindSpeed & Standard Deviation given a specified month and year"<< endl;
    cout << "2 : The Average Ambient Air Temperature & Standard Deviation given for each month and year"<< endl;
    cout << "3 : The Total Solar Radiation in Kw/m^2 for each month of a specified year "<< endl;
    cout << "4 : The Average WindSpeed & Average Ambient Air Temperature \n& Total Solar Radiation in kw/m^2 for each specified month and year"<< endl;
    cout << "5 : Exit Menu"<<endl;
}
float Operations :: MatchCalculateMeanSpeed(int &month,int &year ) // matches the month specified by user and calculate
{

    float mean=0.0;
    float sum = 0.0;
    int numx =0 ; // counter for match data
    Date d;
    WindSpeed ws;
    filterdata[year][month].inOrder(CollectionOfData); // this will load data into static vect for calculation

    for ( int i = 0 ; i < dataout.size() ; i ++ ) // grouping data; using one as reference each time scan the rest
    {
        dataout[i].GetDate(d);


        if (month == d.GetMonth() && year == d.GetYear())// matching date and year
        {

            dataout[i].GetWindSpeed(ws);
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
float Operations :: MatchFindSDSpeed(float &mean,int &month, int &year) // matches the month specified by user and calculate
{

    float meanx = mean/3.6; // done don't touch /// mean is pass into this from previous

    float sum = 0.0;
    int counterx = 0;
    float SD = 0.0;
    Date d;
    WindSpeed ws;

    filterdata[year][month].inOrder(CollectionOfData);

    for(int i = 0 ; i < dataout.size() ; i++)
    {
        dataout[i].GetDate(d);
        dataout[i].GetWindSpeed(ws);
        if (month == d.GetMonth() && year == d.GetYear())
        {

            sum +=(ws.GetWindSpeed() - meanx) * (ws.GetWindSpeed() - meanx); /// using each value to - mean
            counterx ++ ;
        }
    }


    SD = sqrt(sum/counterx) * 3.6;
    return SD;
}
string Operations :: MonthToString(int&month) // converts the month key in by user in int to string "january" for 1 example
{
    if (month >0 && month <= 12)
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
float Operations :: MatchCalculateMeanTemp(int &month,int &year ) // calculates the mean temperature by year and output each month
{

    float sum =0;
    int numx =0; // counter for match data
    float mean =0;
    Date d;
    Temperature t;
    filterdata[year][month].inOrder(CollectionOfData); // loads data in static vector
    if (dataout.size() != 0) // check if data null // if null return 0 ;
    {

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

        mean = sum/numx;
        return mean;


    }
    else
    {

        return 0;
    }

}



float Operations :: MatchFindSDTemp(float &mean,int &month, int &year) // calculates the sd for each month from year provided
{
    int counterx = 0;
    float sum = 0.0;
    float meanx = 0.0;
    meanx = mean;
    Date d;
    Temperature t;
    filterdata[year][month].inOrder(CollectionOfData); // load data /// fix this
    if(dataout.size() != 0 )
    {

        for(int i = 0 ; i < dataout.size() ; i++)
        {
            dataout[i].GetDate(d);
            dataout[i].GetTemperature(t);
            if (month == d.GetMonth() && year == d.GetYear())
            {
                sum +=(t.GetTemperature()-(meanx)) * (t.GetTemperature() - (meanx));
                counterx++;

            }
        }

        return sqrt(sum/counterx);
    }
    else
    {

        return 0;
    }

}
float Operations :: MatchCalculateTotalSR(int &month,int &year ) // calculates total solar radiation
{
    float sum =0;
    Date d;
    SolarRadiation sr;
    filterdata[year][month].inOrder(CollectionOfData);

    if ( dataout.size() != 0)
    {
        for ( int i = 0 ; i < dataout.size() ; i ++ ) //  loop through datasize
        {
            dataout[i].GetDate(d);
            dataout[i].GetSolarRadiation(sr);
            if (month == d.GetMonth() && year == d.GetYear()) // month match data month and year matched user defined year
            {
                sum += sr.GetSolarRadiation(); // add speed if match month and year; // will add all temp values that matched this month and year
            }

        }

        sum = sum/6000;

        return sum;
    }
    else
    {
        return 0;
    }


}
/// INITIALISING OF STATIC VARIABLE
Vector<SensorRecords> Operations :: dataout;
