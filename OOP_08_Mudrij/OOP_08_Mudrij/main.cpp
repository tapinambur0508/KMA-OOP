#include "Screen.h"

int main() 
{
	Screen s1(5, 2);
	Screen s2(51, 51);
	Screen s3(10, 10, "I like C++!");
	cout << "s3.show():" << endl << s3.show() << endl;
	cout << "s3.get(): " << s3.get() << endl;

	for (int i = 0; i < 15; ++i) 
	{
		s3.move();
		cout << s3.get() << endl;
	}

	s3.home();
	s3.show().move(1, 1).showCurrent();
	s3.move().set('!').get();

	int action = 0;
	int count = 1;

	//doActionConst
	const Screen s4(20, 20, "I like Const Action!");
	const ConstAction const_menu[] = {
		&Screen::move,
		&Screen::back,
		&Screen::home,
		&Screen::show,
		&Screen::showCurrent
	};
	cout << endl << "doActionConst: " << endl;

	while (true) 
	{
		cout << endl << "0 - move()" << endl;
		cout << "1 - back()" << endl;
		cout << "2 - home()" << endl;
		cout << "3 - show()" << endl;
		cout << "4 - showCurrent()" << endl;
		cout << "5 - stop" << endl;

		cin >> action;

		if (action == 0 || action == 1)
		{
			cout << "How many times?" << endl;
			cin >>  count;

			while (!count)
			{
				cout << "How many times?" << endl;
				cin >> count;
			}
		} 
		else if (action == 2 || action == 3 || action == 4)
		{
			count = 1;
		}
		else if (action == 5)
		{
			break;
		}
		else
		{
			continue;
		}

		doActionConst(s4, const_menu[action], count);
	}

	//doActionNonConst
	Screen s5(25, 25, "I like Non Const Action!");
	NonConstAction non_const_menu[] = {

		&Screen::move,
		&Screen::back,
		&Screen::home,
		&Screen::show,
		&Screen::clear
	};
	cout << "doActionNonConst: " << endl;

	while (true) 
	{
		cout << endl << "0 - move()" << endl;
		cout << "1 - back()" << endl;
		cout << "2 - home()" << endl;
		cout << "3 - show()" << endl;
		cout << "4 - showCurrent()" << endl;
		cout << "5 - stop" << endl;

		cin >> action;

		if (action == 0 || action == 1)
		{
			cout << "How many times?" << endl;
			cin >> count;

			while (!count)
			{
				cout << "How many times?" << endl;
				cin >> count;
			}
		}
		else if (action == 2 || action == 3 || action == 4)
		{
			count = 1;
		}
		else if (action == 5)
		{
			break;
		}
		else
		{
			continue;
		}

		doActionNonConst(s5, non_const_menu[action], count);
	}

	system("pause");

	return 0;
}