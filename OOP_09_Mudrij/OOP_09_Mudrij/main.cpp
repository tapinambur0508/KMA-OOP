#include "Array.h"
#include "Point.h"

using namespace std;

int main()
{
	try 
	{
		Array<10, int> arrOfInt;

		for (int i = 0, len = arrOfInt.size(); i < len; ++i)
		{
			arrOfInt[i] = i*i + i;
			cout << "i: " << arrOfInt[i] << endl;
		}

		cout << arrOfInt[11];
	}
	catch (const Array<10, int>::BadArray& badArray)
	{
		badArray.diagnose();
	}

	try
	{
		Array<5, Point> arrOfPoint;
		Point p1(1, 1);
		arrOfPoint[0] = p1;
		cout << "arrOfPoint[0]: " << arrOfPoint[0] << endl;
	}
	catch (const Array<5, Point>::BadArray& badArray)
	{
		badArray.diagnose();
	}

	system("pause");

	return 0;
}