#include "Segment.h";

using namespace std;

int main() {
	Point p = Point(1, 1);
	Point p2 = Point(2, 3);

	cout << "p = " << p << endl;
	cout << "p2 = " << p2 << endl;

	Segment s1 = Segment(p, p2);
	Segment s2 = Segment(0, 0, 2, 0);

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	Segment s3 = Segment(s1);
	cout << "s3 = " << s3 << endl;

	cout << "distance s2 -> p = " << s2.distance(p) << endl;
	cout << "s2.length = " << s2.length() << endl;

	system("pause");

	return 0;
}