#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// variables 
int flag = 0;
int col,row;
char mode;
string arr[15][15];
string save_address;
string mode_indicator;

vector<vector<int>> B_set_support_co;
vector<int> B_support_co = {-1,-1};
vector<vector<int>> W_set_support_co;
vector<int> W_support_co = {-1,-1};
bool bomb_cout;
bool convert_cout;
bool support_add_cout;
bool support_del_cout;

struct Move{
    int index,row,col;
    Move *next;
};

Move *head, *tail;

int main(int argc, char* argv[]) {
    int num_line = 0; // this is used for the file loading
    for (int i = 0; i<15; i++) {
            for (int j = 0; j<15; j++) {
                arr[i][j] = " "; //after input, change to ● (black) or ○ (white)
            }
    }
    string player1,player2;
    if (argc<2){ //there is no file input if argc < 2
        mode_indicator = initialize(player1,player2);

        // starting game

        if (mode_indicator == "a"){
            mode = 'a';
            cout << "You have chosen classic mode" << endl;
            cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
            classic(player1,player2);
        } else {
            if (mode_indicator == "b"){
                mode = 'b';
                cout << "You have chosen blocked mode" << endl;
                cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
                blocked_mountains(player1,player2);
            } else {
                if (mode_indicator == "c"){
                    mode = 'c';
                    cout << "You have chosen wild mode, let's go crazzzy!" << endl;
                    cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
                    wild_parties(player1,player2);
                } else {
                    cout << "Error in game mode indicator! Please re-start" << endl;
                    exit(1);
                }
            }
        }
    }
    else { 
        // there is file input 
        // file_input(fn,player1,player2,arr,flag);
        // cout << player1 << " " << player2 << " " << flag << endl;
        file_input(argv[1],player1,player2,mode,save_address,num_line);
        delete_line(argv[1],num_line);
        change_value(arr);
        if (mode == 'a'){
            classic(player1,player2);
        }
        else if (mode == 'b'){
            blocked_mountains(player1,player2);
        }
        else if (mode == 'c'){
            wild_parties(player1,player2);
        }
    }
}
