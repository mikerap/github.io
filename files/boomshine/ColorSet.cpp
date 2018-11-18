#include "ColorSet.h"
#include <DarkGDK.h>

ColorSet::ColorSet ()
{
	mNumColors = 0;
}

bool ColorSet::isInSet (const Color & color) const
{
	bool bTru = false;

	for (int i = 0; i < MAX_COLORS; i++)
	{
		if (mcColors[i].get() == color.get())
		{
			bTru = true;
		}
	}

	return bTru;
}

Color::BasicColor ColorSet::getRandomInSet () const
{

 Color::BasicColor cColor = static_cast<Color::BasicColor>(dbRND(MAX_COLORS + 1));

 return cColor;
}

int ColorSet::size () const
{
	return mNumColors;
}




