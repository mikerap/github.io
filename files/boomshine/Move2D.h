// *****************************************************************
// File name:  Speed.h
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Circle Animation
// Hours:	     12 Hours
// Purpose:    The interface for the class Move2D
// *****************************************************************
#ifndef MOVE2D_H
#define MOVE2D_H

#include "Direction2D.h"

class Move2D
{
	public:
		static int getNextXMove (Direction2D);
		static int getNextYMove (Direction2D);

	 private:
		static const int DIMENSIONS = 2;
		static const int X_MOVE = 0;
		static const int Y_MOVE = 1;
		static const int mDirectionalMove[][DIMENSIONS];
};

#endif