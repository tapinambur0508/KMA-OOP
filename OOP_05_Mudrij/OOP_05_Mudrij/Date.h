#include <string>
#include <iostream>

using namespace std;

class Date
{
public:
	struct BadDate;
	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	Date(int d = 0, Month m = Month(0), int y = 0);
	Date(int d, int m, int y);
	Date(const Date&);
	~Date();

	int day() const { return _day; };
	Month month() const { return Month(_month); };
	int year() const { return _year; };
	const string getMonthName() const { return monthNames[_month - 1]; };
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	static void setDefault(int, Month, int);
	static void setDefault();
	static void showDefault();
	const Date& operator++();
	const Date operator++(int);
	const Date& operator--();
	const Date operator--(int);

	int maxDays();
private:
	int _day, _month, _year;
	bool leapYear(int y);
	void fillDate(int d, Month m, int y);
	static string monthNames[12];
	static bool defaultSet;
	static Date defaultDate;
};

ostream& operator<<(ostream& os, const Date & d);

struct Date::BadDate
{
	int _day, _month, _year;
	BadDate(int d, int m, int y) :_day(d), _month(m), _year(y) {};
};

ostream& operator<<(ostream& os, const Date::BadDate & bd);