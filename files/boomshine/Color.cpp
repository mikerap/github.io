#include "Color.h"

const int Color::ColorsRGB[NUMBER_OF_COLORS][RED_PEN + GREEN_PEN + BLUE_PEN] =
		{{255, 255, 255}, // white
		 {0, 0, 0},	// black
		 {255, 0, 0}, // red
		 {0, 0, 255}, // blue
		 {0, 108, 0}, // green
		 {108, 0, 108}, // purple
		 {255, 255, 0}, // yellow
		 {255, 165, 0}, //orange
	 {238, 130, 238}, //violet
	 {192, 192, 192}, //silver
		 {255, 0, 255}, //fuscia
		 {0, 255, 255}, //aqua
		};     

Color::Color (BasicColor color)
{
	mColor = color;
}

void Color::set (BasicColor color)
{
	mColor = color;
}

Color::BasicColor Color::get () const
{
	return mColor;
}

int Color::getRed () const
{
	return ColorsRGB[mColor][Color::RED_PEN];
}

int Color::getGreen () const
{
	return ColorsRGB[mColor][Color::GREEN_PEN];
}

int Color::getBlue () const
{
	return ColorsRGB[mColor][Color::BLUE_PEN];
}