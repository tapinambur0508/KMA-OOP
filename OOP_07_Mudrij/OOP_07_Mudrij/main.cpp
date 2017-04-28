#include <iostream>
#include "BadIndex.h"

using namespace std;

int main()
{
	const char* char_1 = "I like C++!";

	String str_1(char_1);
	cout << "str_1(char_1): " << str_1 << endl;

	const char ch_1 = 'C';

	String str_2(ch_1);
	cout << "str_2(ch1): " << str_2 << endl;

	string string_1 = "c++ library string string_1";

	String str_3(string_1);
	cout << "str_3(string_1): " << str_3 << endl;

	String str_4("Hello, World ");

	String str_5(str_4, 3);
	cout << "str_5(str_4, 3): " << str_5 << endl;

	cout << "str_5.STL_string(): " << str_5.STL_string() << endl;
	cout << "str_5.c_str(): " << str_5.c_str() << endl;
	cout << "str_5.length(): " << str_5.length() << endl;

	if (str_5.empty())
	{
		cout << "str_5 is empty" << endl;
	}
	else
	{
		cout << "str_5 is not empty" << endl;
	}

	str_5.clear();

	if (str_5.empty() != 0)
	{
		cout << "str_5 is empty" << endl;
	}
	else
	{
		cout << "str_5 is not empty" << endl;
	}

	str_2 = str_1;
	cout << "str_2 = str_1: " << str_2 << endl;

	if (str_2 == str_1)
	{
		cout << "str_2 == str_1" << endl;
	}
	else if (str_2 != str_1)
	{
		cout << "str_2 != str_1" << endl;
	}

	str_2 = string_1;
	cout << "str_2 = string_1: " << str_2 << endl;

	str_2 = char_1;
	cout << "str_2 = char_1: " << str_2 << endl;

	str_2 = ch_1;
	cout << "str_2 = ch_1: " << str_2 << endl;

	try {
		cout << "str_3[-1]";
		str_3[-1];
		cout << endl;
	}
	catch (String::BadIndex e) {
		cout << e << endl;
	}

	try {
		cout << "str_3[2]";
		str_3[2];
		cout << endl;
	}
	catch (String::BadIndex e) {
		cout << e << endl;
	}

	try {
		cout << "str_4[-1]";
		str_4[-1];
		cout << endl;
	}
	catch (String::BadIndex e) {
		cout << e << endl;
	}

	try {
		cout << "str_4[2]";
		str_4[2];
		cout << endl;
	}
	catch (String::BadIndex e) {
		cout << e << endl;
	}

	String str_6("333");
	String str_7("4444");
	String str_8("333");
	String str_9("4444");

	if (str_6 < str_7)
	{
		cout << "str_6 < str_7" << endl;
	}
	else if (str_6 > str_7)
	{
		cout << "str_6 > str_7" << endl;
	}

	if (str_6 <= str_8)
	{
		cout << "str_6 <= str_8" << endl;
	} 
	else
	{
		cout << "str_6 > str_8" << endl;
	}

	if (str_7 >= str_9)
	{
		cout << "str_7 >= str_9" << endl;
	}
	else
	{
		cout << "str_7 < str_9" << endl;
	}

	str_6 += string_1;
	cout << "str_6 += string_1: " << str_6 << endl;

	str_7 += char_1;
	cout << "str_7 += char_1: " << str_7 << endl;

	str_8 += ch_1;
	cout << "str_8 += ch_1: " << str_8 << endl;

	str_9 = str_9 + str_9;
	cout << "str_9 = str_9 + str_9: " << str_9 << endl;

	system("pause");
	return 0;
}