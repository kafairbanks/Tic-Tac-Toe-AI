//
//  MinimaxTree.cpp
//  Project3Computer
//
//  Created by Katie Fairbanks on 3/23/18.
//  Copyright © 2018 Katie Fairbanks. All rights reserved.
//

#include <vector>
#include <iostream>
#include "MinimaxTree.h"
#include "Node.h"
using namespace std;

const int INFINITY = 1000000000;

// constructor
MinimaxTree::MinimaxTree(vector<vector<vector<char> > > b){
	// initializations
    head = new Node(nullptr, vector<int>(4, 0), vector<int>(4, 0), b, vector<int>(3, 0), ' ');
    Node * currentNode = head;
    vector<int> move(3);
    
	// populate head's children
    for(int x=0; x<4; x++) {
        for(int y=0; y<4; y++) {
            for(int z=0; z<4; z++) {
                move.at(0) = x;
                move.at(1) = y;
                move.at(2) = z;
                head->addChild(new Node(head, head->getXs(), head->getOs(), head->getBoard(), move, 'X'));
            }
        }
    }
    
	// populate head's children's children
    Node * currentChild;
    for(int i=0; i<currentNode->getChildren().size(); i++) {
        currentChild = currentNode->getChildren().at(i);
        vector<vector<vector<char> > > currentBoard = currentChild->getBoard();
        
        for(int x=0; x<4; x++) {
            for(int y=0; y<4; y++) {
                for(int z=0; z<4; z++) {
                    if(currentBoard.at(x).at(y).at(z) == ' ') {
                        move.at(0) = x;
                        move.at(1) = y;
                        move.at(2) = z;
                        currentChild->addChild(new Node(currentChild, currentChild->getXs(),
                                                        currentChild->getOs(), currentBoard, move, 'O'));
                    }
                }
            }
        }
    }
}

// returns computer's move
vector<int> MinimaxTree::getMove(char humanChar) {
	// if player is X, we try to minimize the value
	if(humanChar == 'X') {
		int value = 0;
		int minValue = INFINITY;
		Node * minNode = head;
	
		Node * currentNode = head;
		vector<Node*> children = head->getChildren();
		
		// for each child of the children of the head, we find minimum value
		// and assign the minimum value to its parent
		for(int i=0; i < children.size(); i++) {
			currentNode = children.at(i);
			minValue = INFINITY;
			vector<Node*> children2 = currentNode->getChildren();
			for(int j=0; j < children2.size(); j++) {
				value = children2.at(j)->getValue();
				if(value < minValue) minValue = value;
			}
			currentNode->setValue(minValue);
		}
		
		// go through all of the head's children
		// find minimum value and take that branch
		minValue = INFINITY;
		for(int i=0; i < children.size(); i++) {
			if(children.at(i)->getValue() < minValue) {
				minValue = children.at(i)->getValue();
				minNode = children.at(i);
			}
		}
	
		return minNode->getMove();
	}
	else { // if player is O, we try to maximize the value
		int value = 0;
		int maxValue = -1 * INFINITY;
		Node * maxNode = head;
	
		Node * currentNode = head;
		vector<Node*> children = head->getChildren();
	
		// for each child of the children of the head, we find maximum value
		// and assign the maximum value to its parent
		for(int i=0; i < children.size(); i++) {
			currentNode = children.at(i);
			maxValue = -1 * INFINITY;
			vector<Node*> children2 = currentNode->getChildren();
			for(int j=0; j < children2.size(); j++) {
				value = children2.at(j)->getValue();
				if(value > maxValue) maxValue = value;
			}
			currentNode->setValue(maxValue);
		}
	
		// go through all of the head's children
		// find maximum value and take that branch
		maxValue = -1 * INFINITY;
		for(int i=0; i < children.size(); i++) {
			if(children.at(i)->getValue() > maxValue) {
				maxValue = children.at(i)->getValue();
				maxNode = children.at(i);
			}
		}
	
		return maxNode->getMove();
	}
}

// updates minimax tree with most recent move
void MinimaxTree::update(vector<int> lastMove, char player) {
    vector<Node*> children = head->getChildren();
    Node * lastHead = head;
    
	// go through children of head and go to branch that represents move recent move made
    for(int i=0; i<children.size(); i++) {
        vector<int> currentMove = children.at(i)->getMove();
        if(currentMove.at(0) == lastMove.at(0) && currentMove.at(1) == lastMove.at(1) &&
           currentMove.at(2) == lastMove.at(2)) {
            head = children.at(i);
            lastHead->eraseChild(i);	// removes this branch from previous head's children to avoid destruction
            break;
        }
    }
    head->setParent(nullptr);		// make new head's parent null
    delete lastHead;			// destroy previous head and its children for memory management

    Node * currentChild;
    vector<int> move(3);
    
	// create new layer of nodes
    for(int i=0; i<head->getChildren().size(); i++) {
        currentChild = head->getChildren().at(i);
        vector<vector<vector<char> > > currentBoard = currentChild->getBoard();
        
        for(int x=0; x<4; x++) {
            for(int y=0; y<4; y++) {
                for(int z=0; z<4; z++) {
                    if(currentBoard.at(x).at(y).at(z) == ' ') {
                        move.at(0) = x;
                        move.at(1) = y;
                        move.at(2) = z;
                        currentChild->addChild(new Node(currentChild, currentChild->getXs(),
                                                        currentChild->getOs(), currentBoard, move, player));
                    }
                }
            }
        }
    }
    
    return;
}
