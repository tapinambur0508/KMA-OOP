#include <cstring>
#include <iostream>
#include "string"

using namespace std;

class String
{
private:
	size_t _len;
	char* _allocator;

public:
	class BadString;
	class BadIndex;
	String();
	explicit String(const char*);
	String(const char);
	explicit String(const string&);
	String(const String & s, int multiplayer = 1);

	~String();

	String& operator=(const String&);
	String& operator=(const string&);
	String& operator=(const char*);
	String& operator=(const char);

	const string STL_string() const { return string(_allocator);  }
	const char* c_str() const { return _allocator;  }
	size_t length() const { return _len;  }

	bool empty() const { return (_len == 0); }
	void clear() { *this = String(); }

	char& operator[](size_t);
	const char operator[](size_t) const;

	bool operator == (const String&) const;
	bool operator != (const String&) const;

	bool operator< (const String&) const;
	bool operator <= (const String&) const;
	bool operator>(const String&) const;
	bool operator >= (const String&) const;

	String operator+(const String&) const;
	String& operator+=(const char*s);
	String& operator+=(const String&);
	String& operator+=(const string&);
};

ostream& operator<<(ostream&, const String&);