// ****************************************************************************
// File name:  Speed.cpp
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Circle Animation
// Hours:	     12 Hours
// Purpose:    The implementation of the class Speed
// ****************************************************************************
#include "Speed.h"
#include <iostream>
using namespace std;

/******************************************************************************
Constructor: Speed

Description: sets the speed of circle to default value

Parameters:  int speed

Returned:	   none
******************************************************************************/
Speed::Speed (int speed)
{
	mSpeed = speed;
}

/******************************************************************************
Method:		   set

Description: set the speed of the circle to the integer value passed in

Parameters:  int speed

Returned:	   none
******************************************************************************/
void Speed::set (int speed)
{
	mSpeed = speed;
}

/******************************************************************************
Method:		   get

Description: return the value of mSpeed

Parameters:  none

Returned:	   int mSpeed
******************************************************************************/
int Speed::get () const
{
	return mSpeed;
}

/******************************************************************************
Method:		   incrementSpeed

Description: increments the speed of the circle by the integer value passed in

Parameters:  int accelerate

Returned:	   none
******************************************************************************/
void Speed::incrementSpeed (int accelerate)
{
	mSpeed += accelerate;
}

/******************************************************************************
Method:		   decrementSpeed

Description: decrements the speed of the circle by the integer value passed in

Parameters:  int decelerate

Returned:	   none
******************************************************************************/
void Speed::decrementSpeed (int decelerate)
{
	mSpeed -= decelerate;
}

// Main for Game2DUtilities
int main ()
{
	return EXIT_SUCCESS;
}