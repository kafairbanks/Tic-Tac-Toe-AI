//
//  Computer.cpp
//  Project3Computer
//
//  Created by Katie Fairbanks on 3/30/18.
//  Copyright © 2018 Katie Fairbanks. All rights reserved.
//

#include <vector>
#include <iostream>
#include "Computer.h"
#include "MinimaxTree.h"
using namespace std;

// constructor
Computer::Computer() {
	// create blank board
	vector<vector<vector<char> > > b(4, vector<vector<char> >(4, vector<char>(4, ' ')));
	board = b;
	// initialize minimax tree
    tree = new MinimaxTree(b);
}

// takes vector and translates to an index 0-63
int Computer::pointToIndex(vector<int> v) {
    int x = v.at(0);
    int y = v.at(1);
    int z = v.at(2);
    
    return x + 4*y + 16*z;
}

// To update tree with human's move
void Computer::update(vector<int> move, char humanChar) {
	// place character piece at place on board
	board[move.at(0)][move.at(1)][move.at(2)] = humanChar;
	// update minimax tree with player's move
    tree->update(move, humanChar);
    return;
}

// returns the index of the position the computer wants to place its character on
int Computer::computerMove(char humanChar) {
	// gets computer's move
    vector<int> move = tree->getMove(humanChar);
	
	// place computer piece at place on board and update tree
	if(humanChar == 'X') {
		board[move.at(0)][move.at(1)][move.at(2)] = 'O';
		tree->update(move, 'O');
	}
    else {
		board[move.at(0)][move.at(1)][move.at(2)] = 'X';
		tree->update(move, 'X');
	}
    
    return pointToIndex(move);
}
