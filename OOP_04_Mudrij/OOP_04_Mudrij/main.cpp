#include "Triangle.h"

int main() 
{
	Point a(0, 0);
	Point b(0, 4);
	Point c(3, 0);

	Triangle ABC(a, b, c);
	cout << "Triangle ABC: " << ABC << endl;

	Triangle A1B1C1(ABC);
	cout << "Triangle A1B1C1: " << A1B1C1 << endl;

	Segment s(a, b);
	Point _c(-3, 0);

	Triangle _ABC(_c, s);
	cout << "Triangle _ABC: " << _ABC << endl;

	ABC = _ABC;
	cout << "ABC = _ABC, ABC: " << ABC << endl;

	Triangle abc;
	cout << "Triangle abc: " << abc << endl;

	Segment hA = abc.height_a();
	cout << "Height A: " << hA << ", length Height A: " << hA.length() << endl;
	Segment hB = abc.height_b();
	cout << "Height B: " << hB << ", length Height B: " << hB.length() << endl;
	Segment hC = abc.height_c();
	cout << "Height C: " << hC << ", length Height C: " << hC.length() << endl;
	cout << "Side A: " << abc.side_a() << endl;
	cout << "Side B: " << abc.side_b() << endl;
	cout << "Side C: " << abc.side_c() << endl;
	cout << "Vertex A: " << abc.apexA() << endl;
	cout << "Vertex B: " << abc.apexB() << endl;
	cout << "Vertex C: " << abc.apexC() << endl;
	cout << "Area abc: " << abc.area() << endl;
	cout << "Perimeter abc: " << abc.perimeter() << endl;

	system("pause");

	return 0;
}