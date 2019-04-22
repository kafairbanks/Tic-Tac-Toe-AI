//
//  Computer.h
//  Project3Computer
//
//  Created by Katie Fairbanks on 3/30/18.
//  Copyright © 2018 Katie Fairbanks. All rights reserved.
//

#ifndef Computer_h
#define Computer_h

#include <vector>
#include <stdio.h>
#include "MinimaxTree.h"

class Computer {
private:
    MinimaxTree * tree;
public:
    Computer();							// constructor
	std::vector<std::vector<std::vector<char> > > board;	// board that computer uses
    int pointToIndex(std::vector<int> v);			// translates 3d point to single int 0-63
    void update(std::vector<int> move, char humanChar);		// updates board and tree with player's move
    int computerMove(char humanChar);				// computer moves its piece and updates tree

	int test = 5;
};


#endif /* Computer_h */
