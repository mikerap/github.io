// ****************************************************************************
// File name:  MovingCircle.cpp
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Boomshine part II
// Purpose:    The implementation of the class MovingCircle
// ****************************************************************************
#include "MovingCircle.h"

/******************************************************************************
Constructor: MovingCircle

Description: sets the speed of circle to default value of 1 and
						 direction to north by default

Parameters:  none

Returned:	   none
******************************************************************************/
MovingCircle::MovingCircle (): ACircle (10, 10, 10, Color::BLACK)
{
	mDirection = Direction2D::NORTH;
	mcSpeed = 1;
}

/******************************************************************************
Method:      setSpeed

Description: sets the speed of circle to the value of the passed 
						 in variable

Parameters:  int speed

Returned:	   none
******************************************************************************/
void MovingCircle::setSpeed (int speed)
{
	mcSpeed = speed;
}

/******************************************************************************
Method:      getSpeed

Description: gets the speed of circle

Parameters:  none

Returned:	   int mcSpeed
******************************************************************************/
int MovingCircle::getSpeed () const
{
	return mcSpeed.get();
}

/******************************************************************************
Method:      setDirection

Description: sets the direction of the circle to the value of the 
						 passed in variable

Parameters:  Direction2D::CompassDirecction direction

Returned:	   none
******************************************************************************/
void MovingCircle::setDirection (Direction2D::CompassDirection direction)
{
	mDirection = direction;
}

/******************************************************************************
Method:      getDirection

Description: gets the diretion of the circle

Parameters:  none

Returned:	   mDirection - direction of the circle
******************************************************************************/
Direction2D::CompassDirection MovingCircle::getDirection () const
{
	return mDirection;
}

/******************************************************************************
Method:      move

Description: moves the circle according to its assigned speed 
						 and direction

Parameters:  none

Returned:	   none
******************************************************************************/
void MovingCircle::move ()
{
	setXCenter (getXCenter() + mcSpeed.get() * mcMove.getNextXMove(mDirection));
	setYCenter (getYCenter() + mcSpeed.get() * mcMove.getNextYMove(mDirection));
}

/******************************************************************************
Method:      hitXEdge

Description: determines if a circle hit the top or bottom of the screen

Parameters:  none

Returned:	   bool hit
******************************************************************************/

bool MovingCircle::hitXEdge ()
{
	bool hit = false;
	if (((getXCenter() + getRadius()) >= dbScreenWidth()) ||
			((getXCenter() - getRadius()) <= 0))
	{
		hit = true;
	}

	return hit;
}

/******************************************************************************
Method:      hitYEdge

Description: determines if a circle hit left or right sides of the screen

Parameters:  none

Returned:	   bool hit
******************************************************************************/
bool MovingCircle::hitYEdge ()
{
	bool hit = false;
	if (((getYCenter() + getRadius()) >= dbScreenHeight()) ||
			((getYCenter() - getRadius()) <= 0))
	{
		hit = true;
	}

	return hit;
}

/******************************************************************************
Method:      xBounce

Description: bounces circle off x edge of screen, switches direction

Parameters:  none

Returned:	   none
******************************************************************************/
void MovingCircle::xBounce ()
{
	if (hitXEdge() == true)
	{
		switch (mDirection)
		{
		case Direction2D::NORTHEAST:
			mDirection = Direction2D::NORTHWEST;
			break;
		case Direction2D::NORTHWEST: 
			mDirection = Direction2D::NORTHEAST;
			break;
		case Direction2D::SOUTHEAST: 
			mDirection = Direction2D::SOUTHWEST;
			break;
		case Direction2D::SOUTHWEST:
			mDirection = Direction2D::SOUTHEAST;
			break;
		case Direction2D::WEST:
			mDirection = Direction2D::EAST;
			break;
		case Direction2D::EAST:
			mDirection = Direction2D::WEST;
			break;
		}
	}
}

/******************************************************************************
Method:      yBounce

Description: bounces circle off y edge of screen, switches direction

Parameters:  none

Returned:	   none
******************************************************************************/
void MovingCircle::yBounce ()
{
	if (hitYEdge() == true)
	{
		switch (mDirection)
		{
		case Direction2D::NORTHEAST: 
			mDirection = Direction2D::SOUTHEAST;
			break;
		case Direction2D::NORTHWEST: 
			mDirection = Direction2D::SOUTHWEST;
			break;
		case Direction2D::SOUTHEAST: 
			mDirection = Direction2D::NORTHEAST;
			break;
		case Direction2D::SOUTHWEST:
			mDirection = Direction2D::NORTHWEST;
			break;
		case Direction2D::NORTH: 
			mDirection = Direction2D::SOUTH;
			break;
		case Direction2D::SOUTH: 
			mDirection = Direction2D::NORTH;
			break;
		}
	}
}