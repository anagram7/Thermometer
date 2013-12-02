#include <iostream>
#include <iomanip>
#include "ThermoGraph.h"
#include "ThermometerExtreme.h"
#include "ThermometerSimple.h"
#include "ThermometerMulti.h"
#include "StringBasic.h"
#include "Thermometer.h"
#include "Clonable.h"
#include "UtilityFunctions.h"

void ThermometerSimpleTest()
{
	mas::ThermometerSimple t;

	for(;;)
	{
		t.Display();
		std::cout << std::endl;
		mas::StringBasic s(32);
		s.Accept("");
		if(s.Empty())
			continue;
		if(s.First() == '!')
			break;
		switch (s.First())
		{
		case '+':
			t.WarmUp();
			break;
		case '-':
			t.CoolDown();
			break;
		case '?':
			double x;
			std::cout << "Temperature: ";
			std::cin >> x;
			mas::SkipLine();
			if(t.Bottom() <= x && t.Top() >= x)
				t.Set(x);
			break;
		default:
			break;
		}
	}
}

void ThermometerExtremeTest()
{
	mas::ThermometerExtreme t(-20, 60);

	for(;;)
	{
		t.Display();
		std::cout << std::endl;
		mas::StringBasic s(32);
		s.Accept("");
		if(s.Empty())
			continue;
		if(s.First() == '!')
			break;
		switch (s.First())
		{
		case '+':
			t.WarmUp();
			break;
		case '-':
			t.CoolDown();
			break;
		case '?':
			double x;
			std::cout << "Temperature: ";
			std::cin >> x;
			mas::SkipLine();
			if(t.Bottom() <= x && t.Top() >= x)
				t.Set(x);
			break;
		case '#':
			t.Reset();
			break;
		case '*':
			t.ChangeMode();
			break;
		default:
			break;
		}
	}
}

void ThermometerMultiTest()
{
	mas::ThermometerMulti t(2);

	for(;;)
	{
		t.Display();
		std::cout << std::endl;
		mas::StringBasic s(32);
		s.Accept("");
		if(s.Empty())
			continue;
		if(s.First() == '!')
			break;
		switch (s.First())
		{
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			int temp = s.First() - '0';
			if (temp < t.Count())
				t.SelectInputStation(temp);
		}
		break;
		case '+':
			t.WarmUp();
			break;
		case '-':
			t.CoolDown();
			break;
		case '?':
			double x;
			std::cout << "Temperature: ";
			std::cin >> x;
			mas::SkipLine();
			if(t.Bottom() <= x && t.Top() >= x)
				t.Set(x);
			break;
		case '#':
			t.Reset();
			break;
		case '*':
			t.ChangeMode();
			break;
		case':':
			t.ChangeOutputStation();
			break;

		default:
			break;
		}
	}
}

void ThermoGraphTest()
{
	mas::ThermoGraph t;

	for(;;)
	{
		t.Display();
		std::cout << std::endl;
		mas::StringBasic s(32);
		s.Accept("");
		if(s.Empty())
			continue;
		if(s.First() == '!')
			break;
		switch (s.First())
		{
		case '+':
			t.WarmUp();
			break;
		case '-':
			t.CoolDown();
			break;
		case '?':
			double x;
			std::cout << "Temperature: ";
			std::cin >> x;
			mas::SkipLine();
			t.Set(x);
			break;
		case '#':
			t.Reset();
			break;
		case '=':
			t.Take();
			break;
		case '%':
			t.Plot();
			break;
		case '$':
			std::cout << std::fixed << std::setprecision(1);
			std::cout << t.Value();
			if(t.Count() > 0)
				std::cout << " " << t.Count() << " " << t.Min() << " " << t.Max () << " " 
				<< t. Extent() << " " << t.Average() << " " << t.StandartDeviation();
			std::cout << std::endl;
			break;
		default:
			break;
		}
	}
	
}

void main()
{
	ThermoGraphTest();
}