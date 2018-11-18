// *****************************************************************
// File name:  Boomshine.h
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Boomshine part II
// Purpose:    The interface of the class Boomshine
// *****************************************************************

#include "Boomshine.h"
#include <iostream>

using namespace std;

/******************************************************************************
Constructor:      Boomshine

Description:			sets the level to a number passed through

Parameters:				int num

Returned:					none
******************************************************************************/
Boomshine::Boomshine (int num)
{
	mLevel = num;
	mIntersect = 0;
	mIntersect = 0;
}

/******************************************************************************
Method:      getLevel

Description: gets the value of mLevel

Parameters:  none

Returned:	   int mLevel
******************************************************************************/
int Boomshine::getLevel ()
{
	return mLevel;
}

/******************************************************************************
Method:      setLevel

Description: sets the value of mLevel to a number passed through

Parameters:  int level

Returned:	   none
******************************************************************************/
void Boomshine::setLevel (int level)
{
	mLevel = level;
}

/******************************************************************************
Method:      setScore

Description: sets the value of mIntersect (number of circles intersected)

Parameters:  int score

Returned:	   none
******************************************************************************/
void Boomshine::setScore (int score)
{
	mIntersect = score;
}

/******************************************************************************
Method:      getScore

Description: returns the value of mIntersect

Parameters:  none

Returned:	   int mIntersect
******************************************************************************/
int Boomshine::getScore ()
{
	return mIntersect;
}