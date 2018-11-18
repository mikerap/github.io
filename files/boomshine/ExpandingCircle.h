// *****************************************************************
// File name:  ExpandingCircle.h
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Boomshine part II
// Purpose:    The interface of the class ExpandingCircle
// *****************************************************************

#ifndef EXPANDINGCIRCLE_H
#define EXPANDINGCIRCLE_H

#include "ACircle.h"

class ExpandingCircle: public ACircle
{
public:
	ExpandingCircle (int);
	ExpandingCircle ();
	void setTime (int);
	int getTime ();
	void expandCircle ();
	void setCircle (int, int, int);

private:
	int mExpTime;
};

#endif