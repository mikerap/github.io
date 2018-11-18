// *****************************************************************
// File name:  Speed.h
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Circle Animation
// Hours:	     12 Hours
// Purpose:    The interface for the class Speed
// *****************************************************************
#ifndef SPEED_H
#define SPEED_H

class Speed
{
	public:
		Speed (int = 1);
		void set (int);
		int get () const;
		void incrementSpeed (int);
		void decrementSpeed (int);

	private:
		int mSpeed;
};

#endif