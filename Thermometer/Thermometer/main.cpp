#include <iostream>
#include "ThermometerSimple.h"
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

void main()
{
	ThermometerSimpleTest();
}