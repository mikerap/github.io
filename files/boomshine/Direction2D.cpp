// *****************************************************************
// File name:  Direction2D.cpp
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Circle Animation
// Hours:	     12 Hours
// Purpose:    The implementation of the class Direction2D
// *****************************************************************
#include "Direction2D.h"

/******************************************************************************
Constructor: Direction

Description: Initializes direction of circle to default value

Parameters:  CompassDirection direction

Returned:	   none
******************************************************************************/
Direction2D::Direction2D (CompassDirection direction)
{
	mCompassDirection = direction;
}

/******************************************************************************
Method:		   set

Description: Sets the value of mCompassDirection based on passed in value

Parameters:  CompassDirection direction

Returned:	   none
******************************************************************************/
void Direction2D::set (CompassDirection direction)
{
	mCompassDirection = direction;
}
/**************************************************************************************
Method:		   get

Description: Returns the value of mCompassDirection

Parameters:  none

Returned:	   none
**************************************************************************************/
Direction2D::CompassDirection Direction2D::get () const
{
	return mCompassDirection;
}