#pragma once
#include "Thermometer.h"

namespace mas
{
class ThermometerSimple :
	public mas::Thermometer
{
public:
	ThermometerSimple(void);
	ThermometerSimple(int bottom, int top);
	ThermometerSimple(const ThermometerSimple& other);
	virtual ~ThermometerSimple(void);
	virtual void WarmUp();
	virtual void CoolDown();
	virtual void Set(double degreesCelsius);
	virtual double Value() const;
	virtual int Bottom() const;
	virtual int Top() const;
	virtual void Display() const;

private:
	int bottom; //degrees celsius
	int top;    //degrees celcius
	int tenths; //tenths of degrees celcius

	static const int defaultBottom = -40;
	static const int defaultTop = 80;
};
}
