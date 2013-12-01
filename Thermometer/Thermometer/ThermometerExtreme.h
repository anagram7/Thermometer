#pragma once
#include "Thermometersimple.h"
#include "StringBasic.h"

namespace mas{

class ThermometerExtreme :
	public ThermometerSimple
{
public:
	ThermometerExtreme(void);
	ThermometerExtreme(int bottom, int top);
	ThermometerExtreme(const ThermometerExtreme& other);
	virtual ~ThermometerExtreme(void);
	virtual void WarmUp();
	virtual void CoolDown();
	virtual void Set(double degreesCelsius);
	virtual void Reset();
	virtual double Min() const;
	virtual double Max() const;
	virtual void Display() const;
	virtual void ChangeMode();
	
private:
	double max;
	double min;
	int mode;
	static const StringBasic modes[];
};

}
