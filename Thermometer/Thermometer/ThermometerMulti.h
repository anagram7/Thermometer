#pragma once
#include <vector>
#include "Thermometer.h"
#include "ThermometerExtreme.h"

namespace mas
{

class ThermometerMulti :
	public Thermometer
{
public:
	ThermometerMulti(int count = 2);
	ThermometerMulti(const ThermometerMulti& other);
	virtual ~ThermometerMulti(void);

	/*Raises Temeprature by one Degree*/
	virtual void WarmUp();
	
	/*Lowers Down Temperature by one Degree*/
	virtual void CoolDown();
	
	/*Registers the instance temperature in Celsius Degrees*/
	virtual void Set(double degreesCelsius);
	
	/*Reset the Values of all the Thermometers*/
	virtual void Reset();
	
	/*Returns the temperature value*/
	virtual double Value() const;
	
	/*returns the max value of the Thermometer*/
	virtual double Max() const;
	
	/*retruns the min value of the thermometer*/
	virtual double Min() const;
	
	/*Temperature Upper Limit*/
	virtual int Top () const;
	
	/*Temperature Lower Limit*/
	virtual int Bottom() const;
	
	/*Changes/Set the mode of the display: current, minimum, maximum*/
	virtual void ChangeMode();
	
	/*Displays the Temeprature value*/
	virtual void Display() const;
	
	/*Selects the input variable with a number which represents the station number*/
	virtual void SelectInputStation(int x);
	
	/*Selects the output variable - bahaves like a button who makes the staion runs like 
	0,1,2,3,...,0,1,2,3,... etc.*/
	virtual void ChangeOutputStation();
	
	/*Returns the number of Stations*/
	virtual int Count() const;

private:
	std::vector<ThermometerExtreme> t;
	int count;//ccounts the number of thermometers
	int input;//variable which indicates the station who emits warmup and cool down signals
	int output;//variable which indicates the staion who is being shown in the display
};

}

