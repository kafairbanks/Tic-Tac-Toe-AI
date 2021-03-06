//
//  Node.cpp
//  Project3Computer
//
//  Created by Katie Fairbanks on 3/23/18.
//  Copyright © 2018 Katie Fairbanks. All rights reserved.
//

#include <vector>
#include "Node.h"
using namespace std;

// constructor
Node::Node(Node *p, vector<int> x, vector<int> o,
           vector<vector<vector<char> > > b, std::vector<int> m, char player) {
    parent = p;
    Xs = x;                                                       // inherits list of rows, columns, and diagonals with X's
    Os = o;                                                       // and O's from parent
    
    board = b;
    board.at(m.at(0)).at(m.at(1)).at(m.at(2)) = player;           // make move onto this local board
    
    move = m;
    value = 0;
    
    this->setValue();                                             // initialize the value of the node
}

// destructor
Node::~Node() {
           // deletes all of the children of the node
    for(int i=0; i<children.size(); i++) {
        delete children.at(i);
    }
}

vector<int> Node::getMove() {
    return move;
}

vector<vector<vector<char> > > Node::getBoard(){
    return board;
}

vector<int> Node::getXs() {
    return Xs;
}

vector<int> Node::getOs() {
    return Os;
}

int Node::getValue() {
    return value;
}

// sets value of the node to a value (for computer move)
void Node::setValue(int v) {
    value = v;
}

// sets value of the node based on formula
void Node::setValue() {
    int x = move.at(0);
    int y = move.at(1);
    int z = move.at(2);
    
    vector<int> numXs = vector<int>(13);
    vector<int> numOs = vector<int>(13);
    vector<int> numSpaces = vector<int>(13, 1);
    
           // deletes rows columns and diagonals with X's and O's before move was made
           // adds rows columns and diagonals with X's and O's after move was made
    for(int iter=0; iter<2; iter++) {
        for(int i=1; i<4; i++) {
                   //Check x row positive
            if(x+i < 4) {
                if(board[x+i][y][z] == 'X') {
                    numXs.at(0)++;
                }
                else if(board[x+i][y][z] == 'O') {
                    numOs.at(0)++;
                }
                else {
                    numSpaces.at(0)++;
                }
            }
            
                   //check x row negative
            if(x-i >= 0) {
                if(board[x-i][y][z] == 'X') {
                    numXs.at(0)++;
                }
                else if(board[x-i][y][z] == 'O') {
                    numOs.at(0)++;
                }
                else {
                    numSpaces.at(0)++;
                }
            }
            
                   //check y row positive
            if(y+i < 4) {
                if(board[x][y+i][z] == 'X') {
                    numXs.at(1)++;
                }
                else if(board[x][y+i][z] == 'O') {
                    numOs.at(1)++;
                }
                else {
                    numSpaces.at(1)++;
                }
            }
            
                   //check y row negative
            if(y-i >= 0) {
                if(board[x][y-i][z] == 'X') {
                    numXs.at(1)++;
                }
                else if(board[x][y-i][z] == 'O') {
                    numOs.at(1)++;
                }
                else {
                    numSpaces.at(1)++;
                }
            }
            
                   //check z column positive
            if(z+i < 4) {
                if(board[x][y][z+i] == 'X') {
                    numXs.at(2)++;
                }
                else if(board[x][y][z+i] == 'O') {
                    numOs.at(2)++;
                }
                else {
                    numSpaces.at(2)++;
                }
            }
            
                   //check z column negative
            if(z-i >= 0) {
                if(board[x][y][z-i] == 'X') {
                    numXs.at(2)++;
                }
                else if(board[x][y][z-i] == 'O') {
                    numOs.at(2)++;
                }
                else {
                    numSpaces.at(2)++;
                }
            }
            
                   //check xy plane diagonal positive (up and right)
            if(x+i < 4 && y+i < 4) {
                if(board[x+i][y+i][z] == 'X') {
                    numXs.at(3)++;
                }
                else if(board[x+i][y+i][z] == 'O') {
                    numOs.at(3)++;
                }
                else {
                    numSpaces.at(3)++;
                }
            }
            
                   //check xy plane diagonal negative (up and right)
            if(x-i >= 0 && y-i >= 0) {
                if(board[x-i][y-i][z] == 'X') {
                    numXs.at(3)++;
                }
                else if(board[x-i][y-i][z] == 'O') {
                    numOs.at(3)++;
                }
                else {
                    numSpaces.at(3)++;
                }
            }
            
                   //check xy plane diagonal positive (down and right)
            if(x+i < 4 && y-i >= 0) {
                if(board[x+i][y-i][z] == 'X') {
                    numXs.at(4)++;
                }
                else if(board[x+i][y-i][z] == 'O') {
                    numOs.at(4)++;
                }
                else {
                    numSpaces.at(4)++;
                }
            }
            
                   //check xy plane diagonal negative (down and right)
            if(x-i >= 0 && y+i < 4) {
                if(board[x-i][y+i][z] == 'X') {
                    numXs.at(4)++;
                }
                else if(board[x-i][y+i][z] == 'O') {
                    numOs.at(4)++;
                }
                else {
                    numSpaces.at(4)++;
                }
            }
            
                   //check xz plane diagonal positive (up and right)
            if(x+i < 4 && z+i < 4) {
                if(board[x+i][y][z+i] == 'X') {
                    numXs.at(5)++;
                }
                else if(board[x+i][y][z+i] == 'O') {
                    numOs.at(5)++;
                }
                else {
                    numSpaces.at(5)++;
                }
            }
            
                   //check xz plane diagonal negative (up and right)
            if(x-i >= 0 && z-i >= 0) {
                if(board[x-i][y][z-i] == 'X') {
                    numXs.at(5)++;
                }
                else if(board[x-i][y][z-i] == 'O') {
                    numOs.at(5)++;
                }
                else {
                    numSpaces.at(5)++;
                }
            }
            
                   //check xz plane diagonal positive (down and right)
            if(x+i < 4 && z-i >= 0) {
                if(board[x+i][y][z-i] == 'X') {
                    numXs.at(6)++;
                }
                else if(board[x+i][y][z-i] == 'O') {
                    numOs.at(6)++;
                }
                else {
                    numSpaces.at(6)++;
                }
            }
            
                   //check xz plane diagonal negative (down and right)
            if(x-i >= 0 && z+i < 4) {
                if(board[x-i][y][z+i] == 'X') {
                    numXs.at(6)++;
                }
                else if(board[x-i][y][z+i] == 'O') {
                    numOs.at(6)++;
                }
                else {
                    numSpaces.at(6)++;
                }
            }
            
                   //check yz plane diagonal positive (up and right)
            if(y+i < 4 && z+i < 4) {
                if(board[x][y+i][z+i] == 'X') {
                    numXs.at(7)++;
                }
                else if(board[x][y+i][z+i] == 'O') {
                    numOs.at(7)++;
                }
                else {
                    numSpaces.at(7)++;
                }
            }
            
                   //check yz plane diagonal negative (up and right)
            if(y-i >= 0 && z-i >= 0) {
                if(board[x][y-i][z-i] == 'X') {
                    numXs.at(7)++;
                }
                else if(board[x][y-i][z-i] == 'O') {
                    numOs.at(7)++;
                }
                else {
                    numSpaces.at(7)++;
                }
            }
            
                   //check yz plane diagonal positive (down and right)
            if(y+i < 4 && z-i >= 0) {
                if(board[x][y+i][z-i] == 'X') {
                    numXs.at(8)++;
                }
                else if(board[x][y+i][z-i] == 'O') {
                    numOs.at(8)++;
                }
                else {
                    numSpaces.at(8)++;
                }
            }
            
                   //check yz plane diagonal negative (down and right)
            if(y-i >= 0 && z+i < 4) {
                if(board[x][y-i][z+i] == 'X') {
                    numXs.at(8)++;
                }
                else if(board[x][y-i][z+i] == 'O') {
                    numOs.at(8)++;
                }
                else {
                    numSpaces.at(8)++;
                }
            }
            
                   //check true diagonal 1 positive
            if(x+i < 4 && y+i < 4 && z+i < 4) {
                if(board[x+i][y+i][z+i] == 'X') {
                    numXs.at(9)++;
                }
                else if(board[x+i][y+i][z+i] == 'O') {
                    numOs.at(9)++;
                }
                else {
                    numSpaces.at(9)++;
                }
            }
            
                   //check true diagonal 1 negative
            if(x-i >= 0 && y-i >= 0 && z-i >= 0) {
                if(board[x-i][y-i][z-i] == 'X') {
                    numXs.at(9)++;
                }
                else if(board[x-i][y-i][z-i] == 'O') {
                    numOs.at(9)++;
                }
                else {
                    numSpaces.at(9)++;
                }
            }
            
                   //check true diagonal 2 positive
            if(x-i >= 0 && y+i < 4 && z+i < 4) {
                if(board[x-i][y+i][z+i] == 'X') {
                    numXs.at(10)++;
                }
                else if(board[x-i][y+i][z+i] == 'O') {
                    numOs.at(10)++;
                }
                else {
                    numSpaces.at(10)++;
                }
            }
            
                   //check true diagonal 2 negative
            if(x+i < 4 && y-i >= 0 && z-i >= 0) {
                if(board[x+i][y-i][z-i] == 'X') {
                    numXs.at(10)++;
                }
                else if(board[x+i][y-i][z-i] == 'O') {
                    numOs.at(10)++;
                }
                else {
                    numSpaces.at(10)++;
                }
            }
            
                   //check true diagonal 3 positive
            if(x+i < 4 && y-i >= 0 && z+i < 4) {
                if(board[x+i][y-i][z+i] == 'X') {
                    numXs.at(11)++;
                }
                else if(board[x+i][y-i][z+i] == 'O') {
                    numOs.at(11)++;
                }
                else {
                    numSpaces.at(11)++;
                }
            }
            
                   //check true diagonal 3 negative
            if(x-i >= 0 && y+i < 4 && z-i >= 0) {
                if(board[x-i][y+i][z-i] == 'X') {
                    numXs.at(11)++;
                }
                else if(board[x-i][y+i][z-i] == 'O') {
                    numOs.at(11)++;
                }
                else {
                    numSpaces.at(11)++;
                }
            }
            
                   //check true diagonal 4 positive
            if(x+i < 4 && y+i < 4 && z-i < 4) {
                if(board[x+i][y+i][z-i] == 'X') {
                    numXs.at(12)++;
                }
                else if(board[x+i][y+i][z-i] == 'O') {
                    numOs.at(12)++;
                }
                else {
                    numSpaces.at(12)++;
                }
            }
            
                   //check true diagonal 4 negative
            if(x-i >= 0 && y-i >= 0 && z+i <4) {
                if(board[x-i][y-i][z+i] == 'X') {
                    numXs.at(12)++;
                }
                else if(board[x-i][y-i][z+i] == 'O') {
                    numOs.at(12)++;
                }
                else {
                    numSpaces.at(12)++;
                }
            }
        }
        
        if(iter == 0) {          // deleting in first iteration
            for(int i=0; i<13; i++) {
                if(numXs.at(i) == 4) Xs.at(3)--;
                else if(numXs.at(i) == 3 && numSpaces.at(i) == 1) Xs.at(2)--;
                else if(numXs.at(i) == 2 && numSpaces.at(i) == 2) Xs.at(1)--;
                else if(numXs.at(i) == 1 && numSpaces.at(i) == 3) Xs.at(0)--;
                else if(numOs.at(i) == 4) Os.at(3)--;
                else if(numOs.at(i) == 3 && numSpaces.at(i) == 1) Os.at(2)--;
                else if(numOs.at(i) == 2 && numSpaces.at(i) == 2) Os.at(1)--;
                else if(numOs.at(i) == 1 && numSpaces.at(i) == 3) Os.at(0)--;
                
                if(board[x][y][z] == 'X') {
                    numXs.at(i) = 1;
                    numOs.at(i) = 0;
                }
                else if(board[x][y][z] == 'O') {
                    numXs.at(i) = 0;
                    numOs.at(i) = 1;
                }
                numSpaces.at(i) = 0;
            }
        }
        else {                   // adding in second iteration
            for(int i=0; i<13; i++) {
                if(numXs.at(i) == 4) Xs.at(3)++;
                else if(numXs.at(i) == 3 && numSpaces.at(i) == 1) Xs.at(2)++;
                else if(numXs.at(i) == 2 && numSpaces.at(i) == 2) Xs.at(1)++;
                else if(numXs.at(i) == 1 && numSpaces.at(i) == 3) Xs.at(0)++;
                else if(numOs.at(i) == 4) Os.at(3)++;
                else if(numOs.at(i) == 3 && numSpaces.at(i) == 1) Os.at(2)++;
                else if(numOs.at(i) == 2 && numSpaces.at(i) == 2) Os.at(1)++;
                else if(numOs.at(i) == 1 && numSpaces.at(i) == 3) Os.at(0)++;
            }
        }
    }
    
           // calculate value
    value = (1000 * (Xs.at(3) - Os.at(3))) +
            (100 * (Xs.at(2) - Os.at(2))) +
            (10 * (Xs.at(1) - Os.at(1))) +
            (Xs.at(0) - Os.at(0));
    return;
}

void Node::setParent(Node * n) {
    parent = n;
    return;
}

Node * Node::getParent() {
    return parent;
}

vector<Node*> Node::getChildren() {
    return children;
}

void Node::addChild(Node* n) {
    children.push_back(n);
    return;
}

// for memory management
void Node::eraseChild(int index) {
    children.erase(children.begin() + index);
    return;
}
