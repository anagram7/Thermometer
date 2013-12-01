#include "ThermometerExtreme.h"

namespace mas
{

ThermometerExtreme::ThermometerExtreme(void): 
			ThermometerSimple(), 
			max(Value()), 
			min(Value()), 
			mode(0)
{
}

ThermometerExtreme::ThermometerExtreme(int bottom, int top): 
			ThermometerSimple(bottom, top), 
			max(Value()),
			min(Value()), 
			mode(0)
{
}

ThermometerExtreme::ThermometerExtreme(const ThermometerExtreme& other): 
			ThermometerSimple(other),
			max(other.max),
			min(other.min), 
			mode(other.mode)
{
}

ThermometerExtreme::~ThermometerExtreme(void)
{
}

void ThermometerExtreme::WarmUp()
{
	ThermometerSimple::WarmUp();
	if(Value() > max)
		max = Value();
}

void ThermometerExtreme::CoolDown()
{
	ThermometerSimple::CoolDown();
	if(Value() < min)
		min = Value();
}
	
void ThermometerExtreme::Set(double degreesCelsius)
{
	ThermometerSimple::Set(degreesCelsius);
	if(Value() < min)
		min = Value();
	if(Value() > max)
		max = Value();
}

void ThermometerExtreme::Reset()
{
	max = min = Value();
}

double ThermometerExtreme::Min() const
{
	return min;
}

double ThermometerExtreme::Max() const
{
	return max;
}

const StringBasic ThermometerExtreme::modes[] = {" ", "m", "M"};

void ThermometerExtreme::Display() const
{
	double x = (mode == 0? Value() : mode == 1? min : max);
	std::cout << modes[mode] << StringBasic::Fixed(x,1);
}

void ThermometerExtreme::ChangeMode()
{
	++mode %= 3; //3 modes: corrent, min, max
}

}