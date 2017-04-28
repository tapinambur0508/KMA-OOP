#include "Point.h"

class Segment {
private:
	static int _freeID;
	const int _myId;
	Point _a;
	Point _b;
public:
	Segment(const double x1 = 0, const double y1 = 0, const double x2 = 1, const double y2 = 0);
	Segment(const Point &start, const Point &end);
	Segment(const Segment&);
	~Segment();

	Segment& operator=(const Segment&);

	const Point& start() const { return _a; }
	const Point& end() const { return _b; }

	Point &Segment::start() { return _a; }
	Point &Segment::end() { return _b; }

	const double &Segment::startX() const;
	const double &Segment::startY() const;
	const double &Segment::endX() const;
	const double &Segment::endY() const;

	double &Segment::startX();
	double &Segment::startY();
	double &Segment::endX();
	double &Segment::endY();

	double length() const;
	double distance(const Point&) const;
	const int getID() const;
};

ostream& operator<<(ostream &, const Segment &);