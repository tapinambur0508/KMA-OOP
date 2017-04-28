#include "Segment.h"
#include <math.h>

int Segment::_freeID = 0;

Segment::Segment(const double x1, const double y1, const double x2, const double y2) : _myId(_freeID++), _a(x1, y1), _b(x2, y2)
{
	return;
}

Segment::Segment(const Point &start, const Point &end) : _myId(_freeID++), _a(start), _b(end)
{
	return;
}

Segment::Segment(const Segment& source) : _myId(_freeID++), _a(source.start()), _b(source.end())
{
	return;
}

Segment::~Segment()
{
	return;
}

Segment& Segment::operator=(const Segment& source)
{
	if (&source == this)
	{
		return *this;
	}

	_a = source._a;
	_b = source._b;

	return *this;
}

const Point& Segment::start() const
{
	return _a;
}
const Point& Segment::end() const
{
	return _b;
}

Point& Segment::start()
{
	return _a;
}

Point& Segment::end()
{
	return _b;
}

const double &Segment::startX() const
{
	return _a.x();
}

const double &Segment::startY() const
{
	return _a.y();
}

const double &Segment::endX() const
{
	return _b.x();
}

const double &Segment::endY() const
{
	return _b.y();
}

double &Segment::startX()
{
	return _a.x();
}

double &Segment::startY()
{
	return _a.y();
}

double &Segment::endX()
{
	return _b.x();
}

double &Segment::endY()
{
	return _b.y();
}

double Segment::length() const
{
	return sqrt(sqr(_a.x() - _b.x()) + sqr(_a.y() - _b.y()));
}

const int Segment::getID() const
{
	return _myId;
}

double dist2(const Point& v, const Point& w)
{
	return sqr(v.x() - w.x()) + sqr(v.y() - w.y());
}

double dst(const Point& p, const Point& v, const Point& w)
{
	double l2 = dist2(v, w);

	if (l2 == 0)
	{
		return dist2(p, v);
	}

	double t = ((p.x() - v.x()) * (w.x() - v.x()) + (p.y() - v.y()) * (w.y() - v.y())) / l2;

	if (t < 0)
	{
		return dist2(p, v);
	}

	if (t > 1)
	{
		return dist2(p, w);
	}

	return dist2(p, Point(v.x() + t * (w.x() - v.x()), v.y() + t * (w.y() - v.y())));
}

double Segment::distance(const Point& p) const
{
	return sqrt(dst(p, _a, _b));
}

ostream& operator<<(ostream& os, const Segment& seg)
{
	return os << "Segment " << seg.getID() << " [" << seg.start() << "; " << seg.end() << "]";
}