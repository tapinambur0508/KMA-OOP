#include "Time.h"

const double Time::hourToDec = 1 / 3600;

void Time::normalizeTime() 
{

	while (this->seconds() == 60) {
		this->minutes() = this->minutes() + 1;
		this->seconds() = 0;
	}

	while (this->minutes() == 60) {
		++this->hours();
		this->minutes() = 0;
	}

	while (this->hours() == 24) {
		this->date().setDay(this->date().day() + 1);
		this->hours() = 0;
	}

	return;
}

Time::Time(int s, int m, int h) : _seconds(s), _minutes(m), _hours(h) 
{
	cout << "Time has been created: " << *this << endl;
	return;
}

Time::Time(const Time& t) : _seconds(t.seconds()), _minutes(t.minutes()), _hours(t.hours()) 
{
	cout << "Time has been copied: " << *this << endl;
	return;
}

Time::~Time() 
{
	cout << "Time has been removed: " << *this << endl;
	return;
}

Time& Time::operator=(const Time & u)
{
	this->_seconds = u.seconds();
	this->_minutes = u.minutes();
	this->_hours = u.hours();
	return *this;
}

Time::operator int() const
{
	return _hours * 3600 + _minutes * 60 + _seconds;
}

Time::operator double() const
{
	return hourToDec * int(*this);
}

const Time& Time::operator++() 
{
	++seconds();
	normalizeTime();
	return *this;
};

const Time Time::operator++(int) 
{
	Time res(*this);
	++(*this);
	return res;
};

const Time& Time::operator--() 
{
	if (seconds() == 0) 
	{
		seconds() = 59;

		if (minutes() == 0)
		{
			minutes() = 59;

			if (hours() == 0)
			{
				hours() = 23;
				this->date().setDay(this->date().day() - 1);
			}
			else
			{
				--hours();
			}
		}
		else 
		{
			--minutes();
		}
	}
	else
	{
		--seconds();
	}

	return *this;
};

const Time Time::operator--(int) 
{
	Time res(*this);
	--(*this);
	return res;
};

double operator+ (const Time& u, const Time& v)
{
	Time sum;
	sum.seconds() = u.seconds() + v.seconds();
	sum.minutes() = u.minutes() + v.minutes() + sum.seconds() / 60;
	sum.hours() = u.hours() + v.hours() + sum.minutes() / 60;
	sum.seconds() %= 60;
	sum.minutes() %= 60;

	return double(sum);
}

ostream& operator<<(ostream& os, const Time & t) 
{
	os << t.hours() << ":" << t.minutes() << ":" << t.seconds();
	return os;
}