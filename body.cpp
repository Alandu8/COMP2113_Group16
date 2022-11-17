#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;


void save_board(int map[15][15]) {
    ofstream fout;
    string save_address;
    cout << "Please enter the address you want to save the board" << endl;
    cin >> save_address;
    fout.open(save_address);

    if ( fout.fail() ) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    fout << "There is the final board:" << endl;
 

    fout.close();
}