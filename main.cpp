#include <iostream>
#include <assert.h>

#include "TelCoColorCoder.h"


void TestNumberToPair(int pairNumber,
	TelCoColorCoder::MajorColor expectedMajor,
	TelCoColorCoder::MinorColor expectedMinor)
{
	TelCoColorCoder::CColorPair colorPair =
		TelCoColorCoder::GetColorFromPairNumber(pairNumber);
	std::cout << "Got pair" << colorPair.ToString() << std::endl;
	assert(colorPair.GetMajor() == expectedMajor);
	assert(colorPair.GetMinor() == expectedMinor);
}

void TestPairToNumber(
	TelCoColorCoder::MajorColor major,
	TelCoColorCoder::MinorColor minor,
	int expectedPairNumber)
{
	int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
	std::cout << "Got pair number " << pairNumber << std::endl;
	assert(pairNumber == expectedPairNumber);
}
void TestRefferenceManual() 
{
	TelCoColorCoder::PrintColorcodes();
 }

int main() {
	TestNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
	TestNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

	TestPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
	TestPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
	TestRefferenceManual();

	return 0;
}
