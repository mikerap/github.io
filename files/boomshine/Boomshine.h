#ifndef BOOMSHINE_H
#define BOOMSHINE_H
#include "DarkGDK.h"
#include "MovingCircle.h"
#include "ExpandingCircle.h"

class Boomshine
{
public:
	Boomshine (int = 1);
	int getLevel ();
	void setLevel (int);
	void setScore (int);
	int getScore ();
private:
	int mLevel;
	int mIntersect;
};

#endif
