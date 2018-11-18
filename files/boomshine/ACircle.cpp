// ****************************************************************************
// File name:  ACircle.cpp
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Boomshine part II
// Purpose:    The implementation of the class ACircle
// ****************************************************************************
#include "ACircle.h"

#include <cmath>

/******************************************************************************
Constructor: ACircle

Description: sets mXCenter, mYCenter, mRadius, and mColor

Parameters:  int x, int y, int radius, Color cColor

Returned:	   none
******************************************************************************/
ACircle::ACircle (int x, int y, int radius, Color color)
{
	mXCenter = x;
	mYCenter = y;
	mRadius = radius;
	mColor = color;
}

/******************************************************************************
Method:      setRadius

Description: sets the radius of the circle

Parameters:  int radius

Returned:	   none
******************************************************************************/
void ACircle::setRadius(int radius)
{
	mRadius = radius;
}

/******************************************************************************
Method:      getRadius

Description: gets the radius of the circle

Parameters:  none

Returned:	   int mRadius 
******************************************************************************/
int ACircle::getRadius () const
{
	return mRadius;
}

/******************************************************************************
Method:      setXCenter

Description: sets the X coordinate of the circle

Parameters:  int x

Returned:	   none
******************************************************************************/
void ACircle::setXCenter (int x)
{
	mXCenter = x;
}

/******************************************************************************
Method:      getXCenter

Description: gets the X coordinate of the circle

Parameters:  none

Returned:	   int mXCenter
******************************************************************************/
int ACircle::getXCenter () const
{
	return mXCenter;
}

/******************************************************************************
Method:      setYCenter

Description: sets the Y coordinate of the circle

Parameters:  int y

Returned:	   none
******************************************************************************/
void ACircle::setYCenter (int y)
{
	mYCenter = y;
}

/******************************************************************************
Method:      getYCenter

Description: gets the Y coordinate of the circle

Parameters:  none

Returned:	   int mYCenter
******************************************************************************/
int ACircle::getYCenter () const
{
	return mYCenter;
}

/******************************************************************************
Method:      setColor

Description: sets the color of the circle

Parameters:  const Color &color

Returned:	   none
******************************************************************************/
void ACircle::setColor (const Color &color)
{
	mColor = color;
}

/******************************************************************************
Method:      getColor

Description: gets the color of the circle

Parameters:  none

Returned:	   Color mColor
******************************************************************************/
Color ACircle::getColor () const
{
	return mColor;
}

/******************************************************************************
Method:      draw

Description: draws the circle to the screen

Parameters:  none

Returned:	   none
******************************************************************************/
void ACircle::draw () const
{
 DWORD myColor = dbRGB (mColor.getRed (), mColor.getGreen (),
												mColor.getBlue ());
 dbInk (myColor, myColor);
 dbCircle (mXCenter, mYCenter, mRadius);
}

/******************************************************************************
Method:      drawFilled

Description: draws the circle filled with color to the screen

Parameters:  none

Returned:	   none
******************************************************************************/
void ACircle::drawFilled () const
{
 for (int i = mRadius; i > 0; i--)
 {
	DWORD myColor = dbRGB (mColor.getRed (), mColor.getGreen (),
																						mColor.getBlue ());
	dbInk (myColor, myColor);
	dbCircle (mXCenter, mYCenter, i);
 }
}

/******************************************************************************
Method:      intersectsWith

Description: determines if two circles intersect

Parameters:  const ACircle & cCircle

Returned:	   bool intersect
******************************************************************************/
bool ACircle::intersectsWith (const ACircle & cCircle) const
{
	bool intersect = false;
	double d = sqrt(pow((cCircle.getXCenter() - mXCenter), 2.0) 
								+ pow((cCircle.getYCenter() - mYCenter), 2.0));

	if ((mRadius + cCircle.getRadius()) >= d && cCircle.getRadius () != 0)
	{
		intersect = true;
	}

	return intersect;
}