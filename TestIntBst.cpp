#include <iostream>
#include <string>
#include "Bstx.h"
#include <fstream>
using namespace std;
const string INPUT_FILENAME = "data/datanumber.txt";// input file location and name of file
const string OUTPUT_FILENAME = "data/WindTempSolar.csv"; // output file location and name of file
//void print(int &x )
//{
//    cout << x << endl;
//}
int main()
{
//    Bst<int> intTree;
//    intTree.insertNode(5);
//    intTree.insertNode(3);
//    intTree.insertNode(4);
//    intTree.insertNode(2);
//    intTree.insertNode(7);
//    intTree.insertNode(6);
//    intTree.insertNode(10);
//
//
//
//    int h = intTree.getHeight();
//    cout << " Height of BST is : " << h << endl;
//
//
//    bool balance = intTree.isBalance();
//    if(balance)
//        cout << "BST is balance" << endl;
//    else
//        cout << "BST unbalanced" << endl;
//
//    cout << " in-order Traverse is : " << endl;
//    intTree.inOrder();
//
//    cout << "\n pre-order Traverse is : " << endl;
//    intTree.preOrder();
//
//    cout<< "\n post-order Traverse is : " << endl;
//    intTree.postOrder();
//
//    int x = 3;
//    cout << " \n search for "<< x << " in BST : " << endl;
//    bool finditem = intTree.searchData(x);
//    if (finditem)
//    {
//        cout << "item found " << endl;
//
//    }
//    else
//    {
//        cout << " item not found " << endl;
//    }

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
    Bstx<int> DateTree;

    ifstream inputfile(INPUT_FILENAME.c_str());
    string data;
    string values;



    if(inputfile.rdstate() == 0) // read state 0 means ready to be read;
    {

        cout << "file ready.. reading file..." << endl;
        while(getline(inputfile,data))
        {

            int num = stoi(data);
            cout << num << endl;


            DateTree.insertNode(num);

        }
    }
    else
    {
        cerr << "File " << data << " cannot be read !" << endl;
    }

    cout << " ==============inorder =============" << endl;
    DateTree.inOrder(print);
    cout << " ============post order ==========" << endl;
    DateTree.postOrder(print);
    cout << " =============pre order ==========" << endl;
    DateTree.preOrder(print);

    cout << " ============After Delete ============" << endl;

    bool searching = true;
    cout << " ===========search tree test==================" << endl;
    searching = DateTree.searchData(5);
    if(searching)
    {
        cout << " found value  !" << endl;
    }
    else
        cout << " Value not found " << endl;
    DateTree.deleteBST();
    DateTree.inOrder(print);


    return 0;
}
