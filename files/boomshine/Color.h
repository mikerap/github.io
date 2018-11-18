#ifndef COLOR_H
#define COLOR_H

class Color
{
	public:
    static const int RED_PEN = 0;
    static const int GREEN_PEN = 1;
    static const int BLUE_PEN = 2;
		static const int NUMBER_OF_COLORS = 12;
		static enum BasicColor {WHITE, BLACK, RED, BLUE, GREEN, PURPLE, YELLOW, ORANGE, VIOLET, SILVER, FUSCIA, AQUA};
		static const int ColorsRGB[NUMBER_OF_COLORS]
                              [RED_PEN + GREEN_PEN + BLUE_PEN];

		Color (BasicColor = BLACK);
		void set (BasicColor);
		BasicColor get () const;
		int getRed () const;
		int getGreen () const;
		int getBlue () const;

	private:
		BasicColor mColor;	
};

#endif