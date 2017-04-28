#include "Point.h"

int Point::freeID = 0;

Point::Point(double x, double y) : pointID(freeID++), _x(x), _y(y)
{
	return;
}

Point::Point(const Point & u) : _x(u._x), _y(u._y), pointID(++freeID)
{
	return;
}

Point::~Point()
{
	return;
}

Point& Point::operator=(const Point& a)
{
	this->_x = a._x;
	this->_y = a._y;
	return *this;
}

ostream& operator<<(ostream& os, const Point& point)
{
	return os << "Point " << point.getID() << " (" << point.x() << ";" << point.y() << ")";
}

const Point operator+(const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}

bool operator==(const Point& u, const Point & v)
{
	return u.x() == v.x() && u.y() == v.y();
}

bool operator!=(const Point& u, const Point & v)
{
	return !(u.x() == v.x() && u.y() == v.y());
}

Point& operator+=(Point& u, const Point& v)
{
	u.x() = u.x() + v.x();
	u.y() = u.y() + v.y();
	return u;
}

double sqr(double x)
{
	return x * x;
}

double length(const Point& a, const Point& b)
{
	return sqrt(sqr(a.x() - b.x()) + sqr(a.y() - b.y()));
}