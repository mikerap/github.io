// *****************************************************************
// File name:  Circle.h
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Circle Animation
// Hours:	     12 Hours
// Purpose:    The interface for the class used to animate and 
//			       draw the circle
// *****************************************************************
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Direction2D.h"
#include "Move2D.h"
#include "Speed.h"
#include "Color.h"
#include "ColorSet.h"

class Circle
{
	public:
		Circle (int, int, int);
		void move () ;																																
		void setDirection (Direction2D::CompassDirection);
		void setColor (Color);
		void draw ();																					

	private:
		int mXCenter, mYCenter, mRadius;
		Direction2D::CompassDirection mDirection;
		Move2D mcMove;
		Speed mcSpeed;
		Color mColor;
};

#endif