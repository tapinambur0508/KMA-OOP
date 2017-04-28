#include <iostream>
#include "Point.h"
#include "Segment.h"

using namespace std;

class Point;
class Segment;
class Triangle
{
private:
	Point _a, _b, _c;
	mutable Segment *_ab, *_bc, *_ca;
public:
	Triangle(const double x1 = 0, const double y1 = 0, const double x2 = 1, const double y2 = 0, const double x3 = 0, const double y3 = 1);
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Point& a, const Segment& _bc);
	Triangle(const Triangle& t);
	~Triangle();

	Triangle& operator= (const Triangle&);
	double perimeter() const;
	double area() const;

	const Point& apexA() const { return _a; }
	const Point& apexB() const { return _b; }
	const Point& apexC() const { return _c; }

	const Segment& side_a() const
	{
		if (_bc == 0)
		{
			_bc = new Segment(_b, _c);
		}

		return *_bc;
	}

	const Segment& side_b() const
	{
		if (_ca == 0)
		{
			_ca = new Segment(_c, _a);
		}

		return *_ca;
	}

	const Segment& side_c() const
	{
		if (_ab == 0) {
			_ab = new Segment(_a, _b);
		}

		return *_ab;
	}

	double length_a() const;
	double length_b() const;
	double length_c() const;

	const Segment height_a() const;
	const Segment height_b() const;
	const Segment height_c() const;
};

ostream& operator<<(ostream & os, const Triangle &);