#include "Timer.h"
#include <iostream>

using namespace std;

int main()
{
	Time t1(10, 22, 13);
	cout << "t1.date().day(): " << t1.date().day() << endl;

	Time t2(t1);

	cout << "t1 + t2: " << t1 + t2;

	t1++;
	cout << "t1++: " << t1 << endl;
	++t2;
	cout << "++t2: " << t2 << endl;

	Time t3(59, 59, 23);
	t3++;
	cout << "t3++: " << t3 << endl;

	int day = 0;
	cout << "Enter day:" << endl;
	cin >> day;
	int month = 0;
	cout << "Enter month:" << endl;
	cin >> month;
	int year = 0;
	cout << "Enter year:" << endl;
	cin >> year;
	int hours = 0;
	cout << "Enter hours:" << endl;
	cin >> hours;
	int minutes = 0;
	cout << "Enter minutes:" << endl;
	cin >> minutes;
	int seconds = 0;
	cout << "Enter seconds:" << endl;
	cin >> seconds;
	int replay_count = 0;
	cout << "Enter replay count:" << endl;
	cin >> replay_count;
	int interval_between_replay = 0;
	cout << "Enter interval between replay in seconds:" << endl;
	cin >> interval_between_replay;
	Date d(day, month, year);
	Time t(seconds, minutes, hours);
	Timer timer(d, t, replay_count, interval_between_replay);
	timer.launch();

	system("pause");

	return 0;
}