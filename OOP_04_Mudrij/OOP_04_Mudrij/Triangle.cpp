#include "Triangle.h"

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) :
	_a(x1, y1), _b(x2, y2), _c(x3, y3), _ab(0), _bc(0), _ca(0)
{
	return;
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : _a(a), _b(b), _c(c), _ab(0), _bc(0), _ca(0)
{
	return;
}

Triangle::Triangle(const Point& a, const Segment& bc) : _a(a), _b(bc.start()), _c(bc.end()), _ab(0), _bc(new Segment(_b, _c)), _ca(0)
{
	return;
}

Triangle::Triangle(const Triangle& t) : _a(t._a), _b(t._b), _c(t._c), _ab(0), _bc(0), _ca(0)
{
	return;
}

Triangle::~Triangle()
{
	delete _ab;
	delete _bc;
	delete _ca;
}

Triangle& Triangle::operator=(const Triangle& t)
{
	delete _ab;
	delete _bc;
	delete _ca;
	_a = Point(t._a);
	_b = Point(t._b);
	_c = Point(t._c);

	return *this;
}

double Triangle::length_a() const
{
	return length(_b, _c);
}

double Triangle::length_b() const
{
	return length(_c, _a);
}

double Triangle::length_c() const
{
	return length(_a, _b);
}

double Triangle::perimeter() const
{
	return length_a() + length_b() + length_c();
}

double Triangle::area() const
{
	double p = perimeter() / 2.0;

	return sqrt(p * (p - length_a()) * (p - length_b()) * (p - length_c()));
}

ostream& operator<<(ostream & os, const Triangle& t)
{
	os << "Triangle : \n  A: " << t.apexA() << ", \n  B: " << t.apexB() << ", \n  C: " << t.apexC() << endl;
	return os;
}

Point normal(double la, double lb, double lc, const Point& p)
{
	double k = (la * p.x() + lb * p.y() + lc) / (la * la + lb * lb);

	return Point((p.x() - la * k) / 2.0, (p.y() - lb * k) / 2.0);
}

Point normal(const Point& la, const Point& lb, const Point& p)
{
	double A = lb.y() - la.y();
	double B = la.x() - lb.x();
	double C = -2 * la.x() * lb.y() + la.x() * la.y() + la.y() * lb.x();

	return normal(A, B, C, p);
}

const Segment Triangle::height_a() const
{
	return Segment(_a, normal(_b, _c, _a));
}

const Segment Triangle::height_b() const
{
	return Segment(_b, normal(_c, _a, _b));
}

const Segment Triangle::height_c() const
{
	return Segment(_c, normal(_a, _b, _c));
}