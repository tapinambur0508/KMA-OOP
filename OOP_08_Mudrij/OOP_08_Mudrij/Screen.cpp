#define _CRT_SECURE_NO_WARNINGS
#include "Screen.h"

const int Screen::maxHeight = 50;
const int Screen::maxWidth = 50;
const char Screen::_filler = '$';

Screen::Screen(int width, int height, char *pc) : _width(width), _height(height), _cursor(0)
{
	if (_width > Screen::maxWidth)
	{
		_width = Screen::maxWidth;
	}

	if (_height > Screen::maxHeight)
	{
		_height = Screen::maxHeight;
	}

	_wContent = new char[_width * _height + 1];

	if (pc == 0)
	{
		for (int i = 0, length = _width * _height; i < length; ++i)
		{
			_wContent[i] = Screen::_filler;
		}

		_wContent[_width * _height] = '\0';
	}
	else 
	{
		strcpy(_wContent, pc);
	}

	cout << "Screen has been created: " << *this << endl;

	return;
}

Screen::~Screen()
{
	delete[] _wContent;
	cout << "Screen has been removed: " << *this << endl;

	return;
}

const Screen & Screen::home() const
{
	_cursor = 0;

	return *this;
}

Screen & Screen::home()
{
	_cursor = 0;

	return *this;
}

const Screen & Screen::move() const
{
	if ((_width * _height) < (++_cursor))
	{
		_cursor = 0;
	}

	return *this;
}

Screen & Screen::move()
{
	if ((_width * _height) < (++_cursor))
	{
		_cursor = 0;
	}

	return *this;
}

const Screen & Screen::back() const
{
	if (--_cursor < 0)
	{
		_cursor = (_width * _height - 1);
	}

	return *this;
}

Screen & Screen::back()
{
	if (--_cursor < 0)
	{
		_cursor = (_width * _height - 1);
	}

	return *this;
}

const Screen & Screen::show() const
{
	home();

	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j)
		{
			cout << get();
			move();
		}

		cout << endl;
	}

	return *this;
}

Screen & Screen::show()
{
	home();

	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j)
		{
			cout << get();
			move();
		}

		cout << endl;
	}

	return *this;
}

const Screen & Screen::move(int i, int j) const
{
	if ((i >= _height) || (j >= _width))
	{
		_cursor = 0;
	}	
	else
	{
		_cursor = (i * j);
	}
		
	return *this;
}

Screen & Screen::move(int i, int j)
{
	if ((i >= _height) || (j >= _width))
	{
		_cursor = 0;
	}
	else
	{
		_cursor = (i * j);
	}

	return *this;
}

Screen & Screen::clear()
{
	for (int i = 0, length = _width * _height; i < length; ++i)
	{
		_wContent[i] = Screen::_filler;
	}

	_wContent[_width * _height] = '\0';
	
	return *this;
}

const Screen & Screen::showCurrent() const
{
	cout << _wContent[_cursor];

	return *this;
}

char Screen::get() const
{
	return _wContent[_cursor];
}

Screen & Screen::set(char ch)
{
	_wContent[_cursor] = ch;

	return *this;
}

ostream & operator<<(ostream &os, const Screen &s)
{
	return os << endl << "width: " << s.width() << endl << "height: " << s.height() << endl << "content: " << s.content();
}

void doActionConst(const Screen & s, ConstAction act, int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		(s.*act)();
	}
}

void doActionNonConst(Screen & s, NonConstAction act, int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		(s.*act)();
	}
}