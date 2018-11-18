// *****************************************************************
// File name:  ACircle.h
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Boomshine part I
// Purpose:    The interface of the class ACircle
// *****************************************************************
#ifndef ACIRCLE_H
#define ACIRCLE_H

#include "ColorSet.h"
#include "DarkGDK.h"
#include "Move2D.h"
#include "Direction2D.h"
#include "Speed.h"

class ACircle
{
public:
	ACircle(int = 10, int = 10, int = 10, Color = Color::AQUA);
	void setRadius (int);
	int getRadius () const;
	void setXCenter (int);
	int getXCenter () const;
	void setYCenter (int);
	int getYCenter (int);
	int getYCenter () const;
	void setColor (const Color &);
	Color getColor () const;
	void draw () const;
	void drawFilled () const;
	bool intersectsWith (const ACircle &) const;

private:
	int mXCenter, mYCenter, mRadius;
	Color mColor;
};

#endif