// *****************************************************************
// File name:  Move2D.cpp
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Circle Animation
// Hours:	     12 Hours
// Purpose:    The implementation of the class Move2D
// *****************************************************************
#include "Move2D.h"

const int Move2D::mDirectionalMove[][Move2D::DIMENSIONS] = {{0,-1},
																														{1,-1},
																														{1,0},
																														{1,1},
																														{0,1},
																														{-1,1},
																														{-1,0},
																														{-1,-1}};

/******************************************************************************
Method:		   getNextXMove

Description: gets the x value that will increase or decrease the x value of the
			       circles place on the screen moving it

Parameters:  Direction2D move

Returned:	   int xMove
******************************************************************************/
int Move2D::getNextXMove (Direction2D move)
{
	int xMove = 0;

	xMove = mDirectionalMove[move.get()][X_MOVE];

	return xMove;
}
/******************************************************************************
Method:		   getNextYMove

Description: gets the y value that will increase or decrease the y value of the
			       circles place on the screen moving it

Parameters:  Direction 2D move

Returned:	   int yMove
******************************************************************************/
int Move2D::getNextYMove (Direction2D move)
{
	int yMove = 0;

	yMove = mDirectionalMove[move.get()][Y_MOVE];

	return yMove;
}