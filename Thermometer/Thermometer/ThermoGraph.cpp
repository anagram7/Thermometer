#include <iostream>
#include "Clonable.h"
#include "StringBasic.h"

#include "Thermometer.h"
#include "ThermometerSimple.h"

#include <vector>

#include <iomanip>
#include <cmath>
#include "UtilityFunctions.h"

#include "ThermoGraph.h"

namespace mas
{

ThermoGraph::ThermoGraph(void): ThermometerSimple(), temperatures()
{
	temperatures.reserve(capacity);
}

ThermoGraph::ThermoGraph(int botom, int top): ThermometerSimple(botom, top), temperatures()
{
	temperatures.reserve(capacity);
}

ThermoGraph::ThermoGraph(const ThermoGraph& other): temperatures(other.temperatures)
{
}

ThermoGraph::~ThermoGraph(void)
{
}

void ThermoGraph::Take()
{
	temperatures.push_back(Value());
}

void ThermoGraph::Reset()
{
	temperatures.clear();
}

double ThermoGraph::Min() const
{
	unsigned index = 0;
	for(unsigned i = 1; i < temperatures.size(); i++)
		if(temperatures[i] < temperatures[index])
			index = i;
	return temperatures[index];
}

double ThermoGraph::Max() const
{
	unsigned index = 0;
	for(unsigned i = 1; i < temperatures.size(); i++)
		if(temperatures[i] > temperatures[index])
			index = i;
	return temperatures[index];
}

double ThermoGraph::Extent() const
{
	return Max() - Min();

}

double ThermoGraph::Average() const
{
	double sum = 0;
	for (unsigned i = 0; i < temperatures.size(); i++)
		sum += temperatures[i];
	return sum/temperatures.size();
}

	/*Calculates the Standart Deviation*/
double ThermoGraph::StandartDeviation() const
{
	double sum = 0.0;
	double sum2 = 0.0;

	for(unsigned i = 0; i < temperatures.size(); i++)
	{
		sum += temperatures[i];
		sum2 += Square(temperatures[i]);
	}
	return ::sqrt((temperatures.size() * sum2 - Square(sum)) / Square(temperatures.size()));
}

int ThermoGraph::Count() const
{
	return static_cast<int>(temperatures.size());
}


void ThermoGraph::Plot(std::ostream& output)
{
	output << std::fixed << std::setprecision(1);
	for(unsigned i = 0; i < temperatures.size(); i++)
		output << temperatures[i] << std::endl;
}

}