#include <ctime>
#include "Date.h"

string Date::monthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
bool Date::defaultSet = false;
Date Date::defaultDate;

Date::Date(int d, Month m, int y)
{
	fillDate(d, m, y);
}

Date::Date(int d, int m, int y)
{
	fillDate(d, Month(m), y);
}

Date::Date(const Date& d)
{
	fillDate(d.day(), d.month(), d.year());
	cout << "Date has been copied: " << *this << endl;
}

Date::~Date()
{
	cout << "Date has been removed: " << *this << endl;
}

void Date::setDay(int day)
{
	fillDate(day, Month(_month), _year);
	return;
}

void Date::setMonth(int month)
{
	fillDate(_day, Month(month), _year);
	return;
}

void Date::setYear(int year)
{
	fillDate(_day, Month(_month), year);
	return;
}

void Date::setDefault()
{
	struct tm today;
	time_t timer;
	time(&timer);
	gmtime_s(&today, &timer);

	defaultDate._day = today.tm_mday;
	defaultDate._month = ++(today.tm_mon);
	defaultDate._year = today.tm_year += 1900;
	defaultSet = true;
}

void Date::setDefault(int d, Month m, int y)
{
	defaultDate = Date(d, m, y);
	defaultSet = true;
}

const Date& Date::operator++()
{
	if ((++_day) > maxDays())
	{
		_day = 1;
		if ((++_month)>12)
		{
			_month = Month(1);
			++_year;
		}
	}

	return *this;
}

const Date Date::operator++(int)
{
	Date temp(*this);

	if ((++_day) > maxDays())
	{
		_day = 1;

		if ((++_month) > 12)
		{
			_month = Month(1);
			++_year;
		}
	}

	return temp;
}

const Date& Date::operator--()
{
	if ((--_day) < 1)
	{
		if ((--_month)<1)
		{
			--_year;
			_month = Month(12);
		}

		_day = maxDays();
	}

	return *this;
}

const Date Date::operator--(int)
{
	Date temp(*this);

	if ((--_day) < 1)
	{
		if ((--_month)<1)
		{
			--_year;
			_month = Month(12);
		}

		_day = maxDays();
	}

	return temp;
}

bool Date::leapYear(int y)
{
	bool leap;

	if (y % 4) {
		leap = false;
	}
	else if (y % 100) {
		leap = true;
	}
	else if (y % 400) {
		leap = false;
	}
	else {
		leap = true;
	}

	return leap;
}

void Date::fillDate(int d, Month m, int y)
{
	if (!defaultSet)
	{
		defaultSet = true;
		setDefault();
	}

	_day = d ? d : defaultDate._day;
	_month = m ? m : defaultDate._month;
	_year = y ? y : defaultDate._year;

	if ((_day < 1) || (maxDays() < _day) || (_year < 0))
	{
		throw BadDate(_day, _month, _year);
	}

	cout << "Date has been created: " << *this << endl;
}

void Date::showDefault()
{
	cout << "Default Date: " << defaultDate << endl;
}

ostream& operator<<(ostream& os, const Date & d)
{
	os << d.day() << ' ' << d.getMonthName() << ' ' << d.year();
	return os;
}

int Date::maxDays()
{
	int m = 0;

	switch (month())
	{
		case jan:case mar:case may:case jul:case aug:case oct:case dec: m = 31; break;
		case feb: if (leapYear(year())) m = 29; else m = 28; break;
		case apr:case jun:case sep:case nov: m = 30; break;
		default: throw BadDate(day(), month(), year()); break;
	}

	return m;
}

ostream& operator<<(ostream& os, const Date::BadDate & bd)
{
	os << bd._day << '.' << bd._month << '.' << bd._year;
	return os;
}

