// ****************************************************************************
// File name:  BoomshineDriver.cpp
// Author:     Mike Rapacon 
// Date:       4/24/2015
// Class:      CS 250
// Assignment: Boomshine part II
// Hours:			 15 Hours
// Purpose:    Plays the game Boomshine
// ****************************************************************************
#include <iostream>
#include <string>
#include <DarkGDK.h>
#include "MovingCircle.h"
#include "ExpandingCircle.h"
#include "Boomshine.h"

void DarkGDK ()
{
	dbRandomize(dbTimer());
	Boomshine cBoom;
	const int MAX_CIRCLES = 5, RADIUS = 8, DISAPPEAR = 10000;
	int expandingCircles = 0;
	bool bClick = false;
	MovingCircle cCircle[MAX_CIRCLES];
	ExpandingCircle cExpand[MAX_CIRCLES];
	ExpandingCircle cUser;
	Direction2D cDirection;
	ColorSet cColorSet;
	Color cColor;

	dbSyncOn ();
	dbSyncRate (60);

	for (int i = 0; i < MAX_CIRCLES; i++)
	{
	 int direction = dbRND (Direction2D::NUMBER_OF_DIRECTIONS - 1);
	 while (direction == 0 || direction == 2 || direction == 4 || direction == 6)
	 {
		 direction = dbRND (Direction2D::NUMBER_OF_DIRECTIONS - 1);
	 }
	 cDirection.set(static_cast<Direction2D::CompassDirection>(direction));
	 cCircle[i].setDirection (cDirection.get ());
	 cColor = cColorSet.getRandomInSet ();
	 while (cColor.get () == Color::WHITE)
	 {
		 cColor = cColorSet.getRandomInSet ();
	 }
	 cCircle[i].setColor (cColor);
	 cCircle[i].setXCenter (dbRND(dbScreenWidth () - cCircle[i].getRadius ())
													+ cCircle[i].getRadius ());
	 cCircle[i].setYCenter (dbRND(dbScreenHeight () - cCircle[i].getRadius ())
													+ cCircle[i].getRadius ());
	 cCircle[i].setRadius (RADIUS);
	}


	while (LoopGDK ())
	{			
		dbClear(Color::ColorsRGB[0][0], Color::ColorsRGB[0][0], 
						Color::ColorsRGB[0][0]);
		if (1 == dbMouseClick () )
		{
		  cUser.setCircle (dbMouseX(), dbMouseY(), RADIUS);
			cUser.setColor (cColorSet.getRandomInSet ());
		  bClick = true;
		}
		if (bClick == true && cUser.getTime () < 120)
		{
			cUser.drawFilled();
			cUser.expandCircle ();
		}
		for (int i = 0; i < MAX_CIRCLES; i++)
		{
			cCircle[i].xBounce();
			cCircle[i].yBounce();
			cCircle[i].drawFilled();
			cCircle[i].move();
			if (cCircle[i].intersectsWith (cUser))
			{
				cExpand[expandingCircles].setCircle(cCircle[i].getXCenter(),
																						cCircle[i].getYCenter(), RADIUS);
				cExpand[expandingCircles].expandCircle ();
				cExpand[expandingCircles].setCircle (cCircle[i].getXCenter (),
																						cCircle[i].getYCenter (), RADIUS);
				cExpand[expandingCircles].setColor (cCircle[i].getColor ());
				cCircle[i].setRadius (0);
				cCircle[i].setXCenter (DISAPPEAR);
				cCircle[i].setYCenter (DISAPPEAR);
				cCircle[i].setSpeed (0);
				expandingCircles++;
				cBoom.setScore (expandingCircles);
			}
			for (int j = 0; j < expandingCircles && cCircle[i].getRadius () != 0; j++)
			{
				if (cCircle[i].intersectsWith (cExpand[j]))
				{
					cExpand[expandingCircles].setCircle (cCircle[i].getXCenter (),
																						cCircle[i].getYCenter (), RADIUS);
					cExpand[expandingCircles].setColor (cCircle[i].getColor ());
					expandingCircles++;
				}
			}
		}	
		for (int i = 0; i < expandingCircles; i++)
		{
			if (cExpand[i].getTime () < 120)
			{
				cExpand[i].drawFilled ();
				cExpand[i].expandCircle ();
			}
			else if (cExpand[i].getTime () >= 120)
			{
				cExpand[i].setXCenter (DISAPPEAR);
				cExpand[i].setYCenter (DISAPPEAR);
				cExpand[i].setRadius (0);
				expandingCircles--;
			}
		}
		if (expandingCircles == 0 && bClick == true && cUser.getTime () >= 120)
		{
			char buffer[100];
			char str[100];
			strcpy_s (str, "Boomshine Results\nLevel: ");
			_itoa_s (cBoom.getLevel (), buffer, 10);
			strcat_s (str, buffer);
			strcat_s (str, " Score: ");
			_itoa_s (cBoom.getScore (), buffer, 10);
			strcat_s (str, buffer);
			dbSetTextSize (32);
			dbSetTextToBold ();
			DWORD myColor = dbRGB (Color::BLACK, Color::BLACK, Color::BLACK);
			dbInk (myColor, myColor);
			dbCenterText ((dbScreenWidth () / 2), (dbScreenHeight () / 2), str);
			dbSyncOff ();
			dbWaitKey ();
		}
		dbSync ();
	} 
}