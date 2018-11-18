// *****************************************************************
// File name:  ExpandingCircle.cpp
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Boomshine part II
// Purpose:    The implementation of the class ExpandingCircle
// *****************************************************************

#include "ExpandingCircle.h"

/******************************************************************************
Constructor:      ExpandingCircle

Description:			sets mExpTime, calls ACircle constructor

Parameters:				none

Returned:					none
******************************************************************************/

ExpandingCircle::ExpandingCircle () : ACircle(-100, -100, 0, Color::AQUA)
{
	mExpTime = 2;
}

/******************************************************************************
Constructor:      ExpandingCircle

Description:			sets the time to the number passed through

Parameters:				int time

Returned:					none
******************************************************************************/
ExpandingCircle::ExpandingCircle (int time) : ACircle(10, 10, 10, Color::AQUA)
{
	mExpTime = time;
}

/******************************************************************************
Method:      setTime

Description: sets the value of mExpTime

Parameters:  int time

Returned:	   none
******************************************************************************/
void ExpandingCircle::setTime (int time)
{
	mExpTime = time;
}

/******************************************************************************
Method:      getTime

Description: gets the value of mExpTime

Parameters:  none

Returned:	   int mExpTime
******************************************************************************/
int ExpandingCircle::getTime ()
{
	return mExpTime;
}

/******************************************************************************
Method:      expandCircle

Description: expands the circle, increments mExpTime

Parameters:  none

Returned:	   none
******************************************************************************/
void ExpandingCircle::expandCircle ()
{
		setRadius (getRadius() + 1);
		drawFilled();
		mExpTime++;
}

/******************************************************************************
Method:      setCircle

Description: sets the values of the circle

Parameters:  int x, int y, int radius

Returned:	   none
******************************************************************************/
void ExpandingCircle::setCircle (int x, int y, int radius)
{
	setXCenter (x);
	setYCenter (y);
	setRadius (radius);
}