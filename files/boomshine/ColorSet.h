#ifndef COLORSET_H
#define COLORSET_H

#include "Color.h"

class ColorSet                                                                                 
{                                                                                                   
	public:
		ColorSet ();
		bool isInSet (const Color &) const;
    Color::BasicColor getRandomInSet () const;
		int size () const;
		friend ColorSet operator+ (ColorSet &, const Color &);
    static const int MAX_COLORS = Color::NUMBER_OF_COLORS;

   private:
		Color mcColors[MAX_COLORS];
		int mNumColors;
};
#endif