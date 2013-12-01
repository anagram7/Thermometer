#pragma once

#include <iostream>
#include <vector>
#include "thermometersimple.h"

namespace mas 
{

class ThermoGraph :
	public ThermometerSimple
{
public:
	ThermoGraph(void);
	ThermoGraph(int bottom, int top);
	ThermoGraph(const ThermoGraph& other);
	virtual ~ThermoGraph(void);

	/*Register the current temperature*/
	virtual void Take();

	/*Clean all the Temperature Registers*/
	virtual void Reset();

	/*Calculates the Minimum Temperature*/
	virtual double Min() const;

	/*Calculates the maximum temperature*/
	virtual double Max() const;

	/*Calculates the difference between the minimum and maximum temperature */
	virtual double Extent() const;

	/*Calculates the average temperature*/
	virtual double Average() const;

	/*Calculates the Standart Deviation*/
	virtual double StandartDeviation() const;

	/*Return the number of temperature registers*/
	virtual int Count() const;

	/*Writes the registered values (one by line with one tenth number precision)*/
	virtual void Plot(std::ostream& output = std::cout);

private:
	static const int capacity = 128;
	std::vector<double> temperatures;

};

}

