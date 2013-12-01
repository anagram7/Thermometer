#pragma once

namespace mas
{
class Thermometer
{
public:
	virtual ~Thermometer(void) = 0;

	/*Raises Temeprature by one Degree*/
	virtual void WarmUp() = 0;
	/*Lowers Down Temperature by one Degree*/
	virtual void CoolDown() = 0;
	/*Registers the instance temperature in Celsius Degrees*/
	virtual void Set(double degreesCelsius) = 0;
	/*Returns the temperature value*/
	virtual double Value() const = 0;
	/*Temperature Upper Limit*/
	virtual int Top () const = 0;
	/*Temeprature Lower Limit*/
	virtual int Bottom() const = 0;
	/*Displays the Temeprature value*/
	virtual void Display() const = 0;
};
}
