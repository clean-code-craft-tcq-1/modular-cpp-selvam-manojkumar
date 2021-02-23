/**
*
* \file
*
* \brief This file has declaration for namespace TelCoColorCoder.
*
*
******************************************************************************/
#pragma once

namespace TelCoColorCoder
{
	enum MajorColor { WHITE = 0, RED, BLACK, YELLOW, VIOLET };
	enum MinorColor { BLUE = 0, ORANGE, GREEN, BROWN, SLATE };
	extern const char* majorColorNames[];
	extern int numberOfMajorColors;
	extern int numberOfMinorColors;
	extern const char* MinorColorNames[];

/**
 * This class represents a Colorpair as a single entity.
 *
 */
	class CColorPair
	{
		private:
			MajorColor majorColor;
			MinorColor minorColor;
		public:
			CColorPair(MajorColor major, MinorColor minor);
			MajorColor GetMajor();
			MinorColor GetMinor(); 
			std::string ToString();
	};

	extern CColorPair GetColorFromPairNumber(int pairNumber);
	extern int GetPairNumberFromColor(MajorColor major, MinorColor minor);
	extern void PrintColorCodesForm();
}
