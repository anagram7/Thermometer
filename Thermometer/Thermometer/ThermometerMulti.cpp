#include "ThermometerMulti.h"

namespace mas {

ThermometerMulti::ThermometerMulti(int count): 
					t(count), 
					count(count),
					input(0),
					output(0)
{
}

ThermometerMulti::ThermometerMulti(const ThermometerMulti& other): 
					t(other.t), 
					count(other.count),
					input(other.input),
					output(other.output)
{
}

ThermometerMulti::~ThermometerMulti(void)
{
}

void ThermometerMulti::WarmUp()
{
	t[input].WarmUp();
}

void ThermometerMulti::CoolDown()
{
	t[input].CoolDown();
}

void ThermometerMulti::Set(double degreesCelsius)
{
	t[input].Set(degreesCelsius);
}

void ThermometerMulti::Reset()
{
	for(int i = 0; i < count; i++)
		t[i].Reset();
}

double ThermometerMulti::Value() const
{
	return t[output].Value();
}

double ThermometerMulti::Max() const
{
	return t[output].Max();
}
	
double ThermometerMulti::Min() const
{
	return t[output].Min();
}

int ThermometerMulti::Top() const
{
	return t[0].Top();
}

int ThermometerMulti::Bottom() const
{
	return t[0].Bottom();
}

void ThermometerMulti::ChangeMode()
{
	t[output].ChangeMode();
}

void ThermometerMulti::Display() const
{
	std::cout << output << " "; 
	t[output].Display();
}

void ThermometerMulti::SelectInputStation(int x)
{
	input = x;
}
	
void ThermometerMulti::ChangeOutputStation()
{
	++output %= count;
}

int ThermometerMulti::Count() const
{
	return count;
}

}