#include "Point.h"

int Point::freeID = 0;

Point::Point(double x, double y) : _x(x), _y(y), pointID(++freeID)
{
	cout << pointID << ": created " << *this << endl;

	return;
}

Point::Point(const Point & u) : _x(u._x), _y(u._y), pointID(++freeID)
{
	cout << pointID << ": copied  " << *this << endl;

	return;
}

Point::~Point()
{
	cout << pointID << ": removed " << *this << endl;

	return;
}

Point& Point::operator=(const Point & u)
{
	this->_x = u._x;
	this->_y = u._y;
	return *this;
}

ostream& operator<<(ostream &os, const Point& u)
{
	os << '(' << u.x() << ',' << u.y() << ')';
	return os;
}

const Point operator+(const Point & u, const Point &v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& operator+=(Point&u, const Point& v)
{
	u.x() += v.x();
	u.y() += v.y();

	return u;
}

bool operator==(const Point & u, const Point &v)
{
	if ((u.x() == v.x()) && (u.y() == v.y()))
	{
		return true;
	}

	return false;
}

bool operator!=(const Point & u, const Point &v)
{
	if (u == v) {
		return false;
	}

	return true;
}