#include "stdafx.h"
#include "AComplex.h"
#include "TComplex.h"
#include <iostream>

using namespace std;

int AComplex::_freeId = 0;

AComplex::AComplex(double re, double im) : _re(re), _im(im), _id(++_freeId)
{
	cout << _id << ": created AComplex number " << *this << endl;
	return;
}

AComplex::AComplex(const TComplex& tc) : _re(tc.re()), _im(tc.im()), _id(++_freeId)
{
	cout << _id << ": copied AComplex number from TComplex " << *this << endl;
	return;
}

AComplex::AComplex(const AComplex& ac) : _re(ac._re), _im(ac._im), _id(++_freeId)
{
	cout << _id << ": copied complex number " << *this << endl;
	return;
}

AComplex::~AComplex()
{
	cout << _id << ": removed AComplex number " << *this << endl;
	return;
}

AComplex& AComplex::operator=(const AComplex &ac)
{
	this->_re = ac._re;
	this->_im = ac._im;
	return *this;
}

double AComplex::mod() const
{
	return sqrt(pow(_re, 2) + pow(_im, 2));
}

double AComplex::arg() const
{
	if (_re > 0)
	{
		return atan2(_im, _re);
	}
	else if (_re < 0 && _im >= 0)
	{
		return atan2(_im, _re) + 3.1415;
	}
	else if (_re < 0 && _im < 0)
	{
		return atan2(_im, _re) - 3.1415;
	}
	else if (_re == 0 && _im > 0)
	{
		return 1.57075;
	}
	else if (_re == 0 && _im < 0)
	{
		return -1.57075;
	}
	else
	{
		return 0;
	}
}

const AComplex AComplex::conj() const
{
	AComplex a(_re, -_im);

	return a;
}

AComplex& operator+=(AComplex& a, const AComplex& b)
{
	a.re() += b.re();
	a.im() += b.im();

	return a;
}

AComplex& operator-=(AComplex& a, const AComplex& b)
{
	a.re() -= b.re();
	a.im() -= b.im();

	return a;
}

AComplex& operator*=(AComplex& a, const AComplex& b)
{
	a.re() = (a.re()*b.re() - a.im()*b.im());
	a.im() = (a.re()*b.im() + a.im()*b.re());

	return a;
}

AComplex& operator/=(AComplex& a, const AComplex& b)
{
	if (b.re() != 0 || b.im() != 0) {
		a.re() = (a.re()*b.re() + a.im()*b.im()) / (pow(b.re(), 2) + pow(b.im(), 2));
		a.im() = (a.im()*b.re() - a.re()*b.im()) / (pow(b.re(), 2) + pow(b.im(), 2));

		return a;
	}
	else
	{
		return AComplex(0, 0);
	}
}

const AComplex  operator+ (const AComplex& a, const AComplex& b)
{
	AComplex c;
	c.re() = a.re() + b.re();
	c.im() = a.im() + +b.re();

	return c;
}

const AComplex  operator- (const AComplex& a, const AComplex& b)
{
	AComplex c;
	c.re() = a.re() - b.re();
	c.im() = a.im() - +b.re();

	return c;
}

const AComplex  power(const AComplex& a, unsigned int n)
{
	TComplex b(a.re(), a.im());
	b.mod() = pow(b.mod(), 2);
	b.arg() *= n;

	return b;
}

bool operator==(const AComplex & a, const AComplex &b)
{
	if ((a.re() == b.re()) && (a.im() == b.im()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const AComplex & a, const AComplex &b)
{
	if ((a.re() != b.re()) && (a.im() != b.im()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream &os, const AComplex &ac)
{
	if (ac.im() > 0)
	{
		os << ac.re() << " + " << ac.im() << "i";
	}
	else if (ac.im() < 0)
	{
		os << ac.re() << " - " << -ac.im() << "i";
	}
	else
	{
		os << ac.re();
	}

	return os;
}

istream& operator >> (istream &is, AComplex &ac)
{
	cout << "Enter re" << endl;
	is >> ac.re();
	cout << "Enter im" << endl;
	is >> ac.im();
	
	return is;
}




