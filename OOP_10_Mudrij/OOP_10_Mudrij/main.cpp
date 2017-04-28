#include "Sequence.h"

int main() 
{
	Sequence<int> *s1 = new Sequence<int>(5);

	for (int i = 0; i < 10; ++i) {
		(*s1).add(i);
	}

	cout << *s1 << endl;

	(*s1).remove(0);
	(*s1).remove(2);
	(*s1).remove(4);

	cout << *s1 << endl;

	(*s1).insert(10, 0);

	cout << *s1 << endl;

	if ((*s1).contains(5))
	{
		cout << "Element 5 in s1" << endl;
	}
	else
	{
		cout << "Element 5 not in s1" << endl;
	}

	if ((*s1).full())
	{
		cout << "Sequence s1 is full" << endl;
	}
	else
	{
		cout << "Sequence s1 is not full" << endl;
	}

	(*s1).cut();

	cout << *s1 << endl;

	(*s1).clear();

	cout << *s1 << endl;

	system("pause");

	return 0;
}