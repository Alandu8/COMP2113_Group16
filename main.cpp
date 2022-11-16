#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

// create a board class to manipulate the chess board
//black -> ● 
//white -> ○

class board
{
public: 
    
    void arr_init();
    void block();
    void init(); //create the board
private:
    string arr[15][15]; //use a 2-D array to store data

};

void board::init() {
    cout << "    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14" << endl;
    for (int i = 0; i<15; i++) {
        cout << "  ·---+---+---+---+---+---+---+---+---+---+---+---+---+---+---·" << endl;
        if (i >= 10) {
            cout << i << '|';
            for (int j = 0; j<15; j++) {
                cout << ' ' << arr[i][j] << " |";
        }
        }
        else {
            cout << ' ' << i << '|';
                for (int j = 0; j<15; j++) {
                    cout << ' ' << arr[i][j] << " |";
        }
        }
        cout << endl;
    }
    cout << "  ·---+---+---+---+---+---+---+---+---+---+---+---+---+---+---·" << endl;
}

void board::arr_init() { //arr is for storage of use input data
    for (int i = 0; i<15; i++) {
        for (int j = 0; j<15; j++) {
            arr[i][j] = " "; //initially is blank or x(blocked), after input, change to ● (black) or ○ (white)
        }
    }
}

void board::block() { //initialize board with blocks stopping user input
    int number = 20; //number of blocks, can be modified by user later
    srand(time(0));
    //int myrandom (int i) { return rand()%i;}
    vector<string> board_item;
    for (int i = 0; i<15; i++) {
        for (int j = 0; j<15; j++) {
            board_item.push_back(arr[i][j]);
        }
    }
    vector<string>::iterator itr = board_item.begin();
    for (int i = 0; i< number; i++) {
        *itr = "x";
        itr++;
    }
    random_shuffle(board_item.begin(), board_item.end());
    
    for (int i = 0; i<15; i++) {
        for (int j = 0; j<15; j++) {
            arr[i][j] = board_item[i*15+j];
        }
    }
}

int main() {
    
    board gobang_board;
    gobang_board.arr_init();
    gobang_board.block();
    gobang_board.init();

}