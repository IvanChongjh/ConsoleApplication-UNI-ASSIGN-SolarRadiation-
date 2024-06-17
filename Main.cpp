#include "Operations.h"
#include "FilteredDatabase.h"
#include "SensorRecords.h"
using namespace std;
const string INPUT_FILENAME = "data/data_source.txt";// input file location and name of file
const string OUTPUT_FILENAME = "data/WindTempSolar.csv"; // output file location and name of file

int main()
{

    FilteredDatabase database; // FilterDatabase ONLY FOR STORING DATA
    database.LoadData(INPUT_FILENAME); // LOAD DATA INTO DATABASE;
    Operations op; // Operations maintain the interactions of user and commands all calculations/methods
    op.SycDatabase(database); // since there should be minimal database access we need to syc all data over for user operation
    op.SycFilteredDatabase(database); // syc map data
    op.Menu(OUTPUT_FILENAME); // we insert the outfile


    return 0;
}
