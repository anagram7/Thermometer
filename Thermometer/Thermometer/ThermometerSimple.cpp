#include "ThermometerSimple.h"
#include "StringBasic.h"
#include <iostream>
#include "Clonable.h"

#include "Thermometer.h"

namespace mas{

ThermometerSimple::ThermometerSimple(void): bottom(defaultBottom), top(defaultTop), tenths((bottom + top) * 5)
{
}

ThermometerSimple::ThermometerSimple(int bottom, int top): bottom(bottom), top(top), tenths((bottom + top) * 5)
{
}

ThermometerSimple::ThermometerSimple(const ThermometerSimple& other): bottom(other.bottom), top(other.top), tenths(other.tenths)
{
}

ThermometerSimple::~ThermometerSimple(void)
{
}

void ThermometerSimple::WarmUp()
{
	if (tenths < top * 10)
		tenths++;
}

void ThermometerSimple::CoolDown()
{
	if(tenths > bottom * 10)
		tenths--;
}

void ThermometerSimple::Set(double degreesCelsius)
{
	tenths = static_cast <int> (degreesCelsius);
}

double ThermometerSimple::Value() const
{
	return tenths / 10.0;
}

int ThermometerSimple::Bottom() const
{
	return bottom;
}

int ThermometerSimple::Top() const
{
	return top;
}

void ThermometerSimple::Display() const
{
	StringBasic::Fixed(tenths / 10.0, 1).Write();
}
}
