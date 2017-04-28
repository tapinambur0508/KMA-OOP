// OOP_03_Mudrij.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "AComplex.h"
#include "TComplex.h"
#include <iostream>

using namespace std;

int main()
{
	AComplex ac1(4, 5);
	TComplex tc1(ac1);
	AComplex ac2 = ac1.conj();
	ac2 += ac1;
	cout << "ac2 += ac1 : " << ac2 << endl;
	ac2 -= ac1;
	cout << "ac2 -= ac1 : " << ac2 << endl;
	ac2 *= ac1;
	cout << "ac2 *= ac1 : " << ac2 << endl;
	ac2 /= ac1;
	cout << "ac2 /= ac1 : " << ac2 << endl;

	AComplex ac3;
	cin >> ac3;
	cout << "ac3 : " << ac3 << endl;
	cout << "ac3 mod : " << ac3.mod() << endl;
	cout << "ac3 arg : " << ac3.arg()  << endl;
	
	if (ac3 == ac1)
	{
		cout << "ac3 == ac1" << endl;
	}
	else if (ac3 != ac1)
	{
		cout << "ac3 != ac1" << endl;
	}

	AComplex ac4 = ac3 * ac1;
	cout << "ac4 = ac3 * ac1 : " << ac4 << endl;
	AComplex ac5 = ac4 / ac1;
	cout << "ac5 = ac4 / ac1 : " << ac5 << endl;
	AComplex ac6 = ac5 + ac1;
	cout << "ac6 = ac5 + ac1 : " << ac6 << endl;
	AComplex ac7 = ac5 - ac1;
	cout << "ac7 = ac5 - ac1 : " << ac7 << endl;

	TComplex tc2;
	cin >> tc2;
	cout << "tc2 : " << tc2 << endl;
	cout << "tc2 mod : " << tc2.mod() << endl;
	cout << "tc2 arg : " << tc2.arg() << endl;

	if (tc2 == tc1)
	{
		cout << "tc2 == tc1" << endl;
	}
	else if (tc2 != tc1)
	{
		cout << "tc2 != tc1" << endl;
	}

	tc2 += tc1;
	cout << "tc2 += tc1 : " << tc2 << endl;
	tc2 -= tc1;
	cout << "tc2 -= tc1 : " << tc2 << endl;
	tc2 *= tc1;
	cout << "tc2 *= tc1 : " << tc2 << endl;
	tc2 /= tc1;
	cout << "tc2 /= tc1 : " << tc2 << endl;

	TComplex tc3(tc2);
	tc3 = power(tc3, 4);
	cout << "tc3 ^ 4 : " << tc3 << endl;

	TComplex tc4 = tc3 + tc2;
	cout << "tc4 = tc3 + tc2 : " << tc4 <<endl;
	TComplex tc5 = tc4 - tc2;
	cout << "tc5 = tc4 - tc2 : " << tc5 << endl;
	TComplex tc6 = tc4 * tc2;
	cout << "tc6 = tc4 * tc2 : " << tc6 << endl;
	TComplex tc7 = tc6 / tc2;
	cout << "tc7 = tc6 / tc2 : " << tc7 << endl;

	system("pause");

    return 0;
}

