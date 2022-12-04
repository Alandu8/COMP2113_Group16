#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "body.h"

using namespace std;


void change_value(string arr[15][15]){
    while (head != NULL){
        if (head->index%2 == 1){
            // this means the player1
            arr[head->row][head->col] = "●";
        }
        else {
            arr[head->row][head->col] = "○";
        }
        head = head->next;
    }
}



int main(int argc, char* argv[]) {
    int num_line = 0; // this is used for the file loading
    for (int i = 0; i<15; i++) {
            for (int j = 0; j<15; j++) {
                arr[i][j] = " "; //after input, change to ● (black) or ○ (white)
            }
    }
    
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