#include "Date.h"
#include <iostream>

using namespace std;

int main() 
{
	try
	{
		Date d1(26, 2, 2017);
		Date d2(27, d1.month() + 1, 2017);
		Date d3(d1);
		Date d4(d3.day(), d1.month(), 2016);

		Date::showDefault();

		d4.setDay(5);
		d4.setMonth(1);
		d4.setYear(2000);
		cout << "d4 day is: " << d4.day() << endl;
		cout << "d4 month is: " << d4.getMonthName() << endl;
		cout << "d4 year is: " << d4.year() << endl;
		cout << "d4++ " << d4++ << endl;
		cout << "++d4 " << ++d4 << endl;

		Date d5(26, 2, -5);
	}
	catch (const Date d)
	{
		cout << "ERROR" << endl;
	}
	

	system("pause");

	return 0;
}