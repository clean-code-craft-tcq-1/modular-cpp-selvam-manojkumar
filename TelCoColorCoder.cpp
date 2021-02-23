/**
*
* \file
*
* \brief This file defines the manespace TelCoColorCoder.
*
*
******************************************************************************/

#include <iostream>
#include "TelCoColorCoder.h"

namespace TelCoColorCoder
{
	const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
	const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
	int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
	int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

	CColorPair::CColorPair(MajorColor major, MinorColor minor) : majorColor(major), minorColor(minor) {}
	
	std::string CColorPair::ToString() 
	{
		std::string colorPairStr = MajorColorNames[majorColor];
		colorPairStr += " ";
		colorPairStr += MinorColorNames[minorColor];
		return colorPairStr;
	}
	
	MajorColor CColorPair::GetMajor()
	{
		return majorColor;
	}
	
	MinorColor CColorPair::GetMinor()
	{
		return minorColor;
	}

	CColorPair GetColorFromPairNumber(int pairNumber) 
	{
		int zeroBasedPairNumber;
		zeroBasedPairNumber = pairNumber - 1;
		MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
		MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
		return CColorPair(majorColor, minorColor);
	}

	int GetPairNumberFromColor(MajorColor major, MinorColor minor)
	{
		return major * numberOfMinorColors + minor + 1;
	}

	void PrintColorCodesForm() 
	{
		std::cout << "\t" << "ColorCode" << "\t" << "ColorPair"<<std::endl;
		for (uint16_t pairIndex = 1; pairIndex <= (numberOfMajorColors * numberOfMinorColors); pairIndex++)
		{
			CColorPair colorPair = GetColorFromPairNumber(pairIndex);
			std::cout << "\t" << pairIndex << "\t\t" << colorPair.ToString() << std::endl;
		}
	}
}
