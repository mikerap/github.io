// *****************************************************************
// File name:  Direction2D.h
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Circle Animation
// Hours:	     12 hours
// Purpose:    The interface for the class Direction2D
// *****************************************************************
#ifndef DIRECTION2D_H
#define DIRECTION2D_H

class Direction2D
{
	public:
		static const int NUMBER_OF_DIRECTIONS = 8;
		static enum CompassDirection {NORTH, NORTHEAST, EAST, SOUTHEAST,
									SOUTH, SOUTHWEST, WEST, NORTHWEST};

		Direction2D (CompassDirection = SOUTH);
		void set (CompassDirection);
		CompassDirection get () const;

	private:
		CompassDirection mCompassDirection;
};

#endif