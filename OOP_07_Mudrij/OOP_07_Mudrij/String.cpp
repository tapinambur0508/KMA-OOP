#define _CRT_SECURE_NO_WARNINGS
#include "BadIndex.h"

String::String() : _len(0), _allocator(new char[1]) 
{
	_allocator[0] = '\0';
	cout << "String has been created: " << *this << endl;

	return;
}

String::String(const char* ch) : _len(strlen(ch)), _allocator(new char(strlen(ch) + 1))
{
	strcpy(this->_allocator, ch);
	cout << "String has been created by const char*: " << *this << endl;

	return;
}

String::String(const char ch) : _allocator(new char[2]), _len(1)
{
	_allocator[0] = ch;
	_allocator[1] = '\0';
	cout << "String has been created by const char: " << *this << endl;

	return;
}

String::String(const string &s) : _len(strlen(s.c_str())), _allocator(new char[this->length() + 1]) 
{
	strcpy(this->_allocator, s.c_str());
	cout << "String has been created by string: " << *this << endl;

	return;
}

String::String(const String & s, int multiplayer) : _len(s._len * multiplayer), _allocator(new char[_len + 1])
{
	char * target = _allocator;

	for (size_t i = 0; i <multiplayer; i++)
	{
		strcpy(target, s._allocator);
		target += s._len;
	}

	cout << "String has been copied with multiplayer = " << multiplayer << ": " << *this << endl;

	return;
};


String::~String()
{
	delete[] this->_allocator;
	cout << "String has been removed: " << *this << endl;

	return;
}

String & String::operator=(const String &s)
{
	if (this == &s)
	{
		return *this;
	}
		
	delete[] _allocator;
	_len = s._len;
	_allocator = new char[_len + 1];
	strcpy(_allocator, s._allocator);

	return *this;
}

String & String::operator=(const string &s)
{
	this->_len = s.length();
	
	return *this = s.c_str();
}

String & String::operator=(const char *ch)
{
	delete[] _allocator;
	_len = strlen(ch);
	_allocator = new char[_len + 1];
	strcpy(_allocator, ch);

	return *this;
}

String& String::operator=(const char ch) 
{
	this->_len = 1;
	this->_allocator[0] = ch;
	_allocator[1] = '\0';

	return *this;
}

char & String::operator[](size_t pos)
{
	if (pos < 0 || pos > this->length()) {
		throw String::BadIndex("BadIndex");
	}

	return _allocator[pos];
}

const char String::operator[](size_t pos) const
{
	if (pos < 0 || pos > this->length()) {
		throw String::BadIndex("BadIndex");
	}

	return c_str()[pos];
}

bool String::operator==(const String &s) const
{
	bool result = false;

	if (strcmp(_allocator, s._allocator) == 0) 
	{
		result = true;
	}	

	return result;
}

bool String::operator!=(const String &s) const
{
	bool result = false;

	if (strcmp(_allocator, s._allocator) != 0) 
	{
		result = true;
	}

	return result;
}

bool String::operator<(const String &s) const
{
	bool result = false;

	if (strlen(_allocator) < strlen(s._allocator))
	{
		result = true;
	}

	return result;
}

bool String::operator<=(const String &s) const
{
	bool result = false;

	if (strlen(_allocator) <= strlen(s._allocator))
	{
		result = true;
	}

	return result;
}

bool String::operator>(const String &s) const
{
	bool result = false;

	if (strlen(_allocator) > strlen(s._allocator))
	{
		result = true;
	}

	return result;
}

bool String::operator>=(const String &s) const
{
	bool result = false;

	if (strlen(_allocator) >= strlen(s._allocator))
	{
		result = true;
	}

	return result;
}

String String::operator+(const String &s) const
{
	unsigned int len = length() + s.length() + 1;
	char *new_str = new char[len];
	memset(new_str, 0, len);
	memcpy(new_str, c_str(), length());
	memcpy(new_str + length(), s.c_str(), s.length());
	String res(new_str);
	delete[] new_str;

	return res;
}

String & String::operator+=(const char*s)
{
	return *this += String(s);
}

String & String::operator+=(const String &s)
{
	_len += s._len;
	char *temp = _allocator;
	_allocator = new char[_len + 1];
	strcpy(_allocator, temp);
	strcat(_allocator, s._allocator);
	delete[] temp;

	return *this;
}

String & String::operator+=(const string &s)
{
	return *this = *this + String(s);
}

ostream& operator<<(ostream& os, const String& s)
{
	return os << s.STL_string();
}
