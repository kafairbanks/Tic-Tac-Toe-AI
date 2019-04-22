//
//  Node.h
//  Project3Computer
//
//  Created by Katie Fairbanks on 3/23/18.
//  Copyright © 2018 Katie Fairbanks. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include <stdio.h>
#include <vector>

class Node {
private:
    int value;                  // value that computer uses to decide its move
    std::vector<int> Xs;        // vector of # of rows with certain number of X's and spaces used to assign value to node
    std::vector<int> Os;        // vector of # of rows with certain number of O's and spaces used to assign value to node
    Node *parent;
    std::vector<Node*> children;    // vector of children
    std::vector<std::vector<std::vector<char> > > board;    // board that node uses to calculate value
    std::vector<int> move;                                  // move that this node represents
    friend class MinimaxTree;
public:
    // constructor
    Node(Node *p = nullptr, std::vector<int> x = std::vector<int>(4),
         std::vector<int> o = std::vector<int>(4),
         std::vector<std::vector<std::vector<char> > > b = std::vector<std::vector<std::vector<char> > >(), std::vector<int> m = std::vector<int>(3), char player = 'X');
    ~Node();                                                    // destructor
    std::vector<int> getMove();                                 // returns move that this node represents
    std::vector<std::vector<std::vector<char> > > getBoard();   // returns board that this node is using
    std::vector<int> getXs();                                   // returns Xs vector
    std::vector<int> getOs();                                   // returns Os vector
    int getValue();                                             // returns value of node
    void setValue(int v);                                       // sets value to an int
    void setValue();                                            // calculate value based on formula
    void setParent(Node * n);                                   // sets parent
    Node * getParent();                                         // returns parent
    std::vector<Node*> getChildren();                           // returns vector of this node's children
    void addChild(Node* n);                                     // adds a child node to this node
    void eraseChild(int index);                                 // removes a child from children vector
};

#endif /* Node_h */
