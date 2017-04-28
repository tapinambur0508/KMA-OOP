#include "Point.h"

int main()
{
	Point p1(10, 5);
	Point p2(-4, 0);
	cout << "Point amount " << Point::amount() << endl;
	Point p3;
	Point p4(p2);
	cout << "Point p2 ID " << p2.getID() << endl;
	cout << "Point p3 ID " << p3.getID() << endl;

	p1 != p2 ? cout << "Point p1 != Point p2" << "\n" : cout << "Point p1 == Point p2" << endl;
	p2 == p4 ? cout << "Point p2 == Point p4" << "\n" : cout << "Point p2 != Point p4" << endl;

	p3 = p1;
	cout << "p3 = p1" << endl;
	p1 == p3 ? cout << "Point p1 == Point p3" << "\n" : cout << "Point p1 == Point p3" << endl;

	cout << "p5 = p1 + p2" << endl;
	Point p5 = p1 + p2;

	p5 += p2;
	cout << "p5 += p2: " << p5 << endl;

	system("pause");

	return 0;
}