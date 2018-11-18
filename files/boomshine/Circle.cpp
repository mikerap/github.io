// *****************************************************************
// File name:  Circle.h
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Circle Animation
// Hours:			 12 Hours
// Purpose:    The implementation of the class Circle
// *****************************************************************
#include "Circle.h"
#include <DarkGDK.h>

/**************************************************************************************
Constructor: Circle

Description: sets the speed of circle to default value

Parameters:  int x, int y, int r

Returned:	   none
**************************************************************************************/
Circle::Circle (int x, int y, int r)
{
	mXCenter = x;
	mYCenter = y;
	mRadius = r + 15;

	mcSpeed.set((dbRND(4)) + 1);
}
/**************************************************************************************
Method:		   move

Description: gets the next X and Y location of the circle

Parameters:  none

Returned:	   none
**************************************************************************************/
void Circle::move ()
{
	mXCenter = mXCenter + mcSpeed.get() * mcMove.getNextXMove(mDirection);
	mYCenter = mYCenter + mcSpeed.get() * mcMove.getNextYMove(mDirection);
}
/**************************************************************************************
Method:		   setDirection

Description: sets the direction the circle will move in

Parameters:  CompassDirection direction

Returned:	   none
**************************************************************************************/
void Circle::setDirection (Direction2D::CompassDirection direction)
{
	mDirection = direction;
}
/**************************************************************************************
Method:		   draw

Description: calls the functions necessary to draw the circle

Parameters:  none

Returned:	   none
**************************************************************************************/
void Circle::draw ()
{
	DWORD myColor = dbRGB (mColor.getRed (), mColor.getGreen (), mColor.getBlue ());
	dbInk (myColor, myColor);
	dbCircle (mXCenter, mYCenter, mRadius);
}

void Circle::setColor(Color color)
{
	mColor = color;
}