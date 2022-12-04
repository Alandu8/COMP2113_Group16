// BODY.h
#ifndef BODY_H
#define BODY_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include<bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "body.h"
using namespace std;


extern int flag;
extern int col,row;
extern char mode;
extern string arr[15][15];
extern string save_address;
extern string mode_indicator;

extern vector<vector<int>> B_set_support_co;
extern vector<int> B_support_co;
extern vector<vector<int>> W_set_support_co;
extern vector<int> W_support_co;
extern bool bomb_cout;
extern bool convert_cout;
extern bool support_add_cout;
extern bool support_del_cout;

struct Move{
    int index,row,col;
    Move *next;
};


extern Move *head, *tail;
extern string player1,player2;
// load rules of our game
void load_rule();

// create a board class to manipulate the chess board
//black -> ● 
//white -> ○

void string_to_int(string s, int &num);

void tail_insertation(Move * &head, Move * &tail, int row,int col ,int index);

int num_empty(string *arr[15][15]);

void print_board();

// use for save board
void save_board(string *arr[15][15],string player1, string player2, int col, int row, bool game_signal,string save_address, int flag,char mode);

void random_bomb();

void random_convert();

void random_support();

// this function is used to take in the user input and change the values inside arr
// this function will avoid the case 1) user input is out of range 2)the user input is already occupied
// the player will input row and then col, flag is used todetermine it is player 1 or player 2
void player(int &flag,int &col, int &row, string *arr[15][15],string player1,string player2,bool &game_signal);

int Rand(int i);

void block();

int straight_five(string *arr[15][15],int row,int col);

bool success(string *arr[15][15]);

void classic(string &player1,string &player2);

void blocked_mountains(string &player1,string &player2);

void wild_parties(string &player1,string &player2);

// initialize game:
// 1. choose mode: A.classic, B.blocked mountains (having blocked cells), C. wild parties (several cooool things may happen)
// 2. save and load chess board
// 3. Rename Players !!to be implemented
string initialize(string &player1,string &player2);

void file_input(string fn,string &player1, string &player2,char &mode,string &save_address,int num_line);

//this function is used to delete 34 lines
void delete_line(const char *filename,int num_line);


#endif