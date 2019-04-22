//
//  MinimaxTree.h
//  Project3Computer
//
//  Created by Katie Fairbanks on 3/23/18.
//  Copyright © 2018 Katie Fairbanks. All rights reserved.
//

#ifndef MinimaxTree_h
#define MinimaxTree_h

#include <stdio.h>
#include <vector>
#include "Node.h"

class MinimaxTree {
private:
    Node * head;                                                    // head node of the minimax tree
public:
    MinimaxTree(std::vector<std::vector<std::vector<char> > > b);   // constructor
    std::vector<int> getMove(char humanChar);                       // chooses computer's move
    void update(std::vector<int> lastMove, char player);            // updates the minimax tree with most recent move
};

#endif /* MinimaxTree_h */
