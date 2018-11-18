// *****************************************************************
// File name:  MovingCircle.h
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Boomshine part II
// Purpose:    The interface of the class MovingCircle
// *****************************************************************
#ifndef MOVINGCIRCLE_H
#define MOVINGCIRCLE_H

#include "ACircle.h"

class MovingCircle: public ACircle
{
public:
	MovingCircle ();
	MovingCircle (Direction2D::CompassDirection north, int = 1);
	void setSpeed (int);
	int getSpeed () const;
	void setDirection(Direction2D::CompassDirection);
	Direction2D::CompassDirection getDirection () const;
	bool hitXEdge ();
	bool hitYEdge ();
	void xBounce ();
	void yBounce ();
	void move ();

private:
	Direction2D::CompassDirection mDirection;
	Speed mcSpeed;
	Move2D mcMove;
};

#endif