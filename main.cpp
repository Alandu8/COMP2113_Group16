#include <iostream>
#include <string>
using namespace std;

// create a board class to manipulate the chess board
//black -> ● 
//white -> ○

class board
{
public: 
    void init(); //create the board
    void arr_init();
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
            arr[i][j] = " "; //initially is blank, after input, change to ● (black) or ○ (white)
        }
    }
}

int main() {
    board gobang_board;
    gobang_board.arr_init();
    gobang_board.init();

}