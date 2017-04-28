#include "stdafx.h"
#include "TComplex.h"
#include "AComplex.h"
#include <iostream>
#include <cmath>

using namespace std;

int TComplex::_freeId = 0;

TComplex::TComplex(double ro, double phi) : _ro(ro), _phi(phi), _id(++_freeId)
{
	cout << _id << ": created complex number " << *this << endl;
	return;
}

TComplex::TComplex(const TComplex& tc) : _ro(tc._ro), _phi(tc._phi), _id(++_freeId)
{
	cout << _id << ": copied complex number " << *this << endl;
	return;
}

TComplex::TComplex(const AComplex& ac) : _ro(ac.mod()), _phi(ac.arg()), _id(++_freeId)
{
	cout << _id << ": copied complex number from AComplex " << *this << endl;
	return;
}

TComplex::~TComplex()
{
	cout << _id << ": removed complex number " << *this << endl;
	return;
}

TComplex& TComplex::operator=(const TComplex &tc)
{
	this->_ro = tc._ro;
	this->_phi = tc._phi;
	return *this;
}

TComplex& operator+=(TComplex& a, const TComplex& b) {
	return a = TComplex(AComplex(a) += AComplex(b));
}

TComplex& operator-=(TComplex& a, const TComplex& b) {
	return a = TComplex(AComplex(a) -= AComplex(b));
}

TComplex& operator*=(TComplex& a, const TComplex& b)
{
	a.mod() *= b.mod();
	a.arg() += b.arg();

	return a;
}

TComplex& operator/=(TComplex& a, const TComplex& b)
{
	a.mod() /= b.mod();
	a.arg() -= b.arg();

	return a;
}

const TComplex  operator* (const TComplex& a, const TComplex& b)
{
	TComplex c;
	c.mod() = a.mod() * b.mod();
	c.arg() = a.arg() + b.arg();

	return c;
}

const TComplex  operator/ (const TComplex& a, const TComplex& b)
{
	TComplex c;
	c.mod() = a.mod() / b.mod();
	c.arg() = a.arg() - b.arg();

	return c;
}

const TComplex  power(const TComplex& a, unsigned int n)
{
	TComplex b;
	b.mod() = pow(a.mod(), n);
	b.arg() = a.arg() * n;

	return b;
}

ostream& operator<<(ostream &os, const TComplex &tc)
{
	os << tc.mod() << " * (cos(" << tc.arg() << ") + isin(" << tc.arg() << "))";

	return os;
}

istream& operator >> (istream &is, TComplex &tc)
{
	cout << "Enter mod" << endl;
	is >> tc.mod();
	cout << "Enter arg" << endl;
	is >> tc.arg();

	return is;
}