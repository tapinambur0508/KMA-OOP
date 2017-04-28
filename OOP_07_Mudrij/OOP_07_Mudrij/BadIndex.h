#include <iostream>
#include "String.h"

using namespace std;

class String::BadIndex
{
private:
	const char* _reason;
public:
	BadIndex(const char* reason);
	~BadIndex();
	const char* getReason() const { return _reason; }
};

ostream& operator<<(ostream&, const String::BadIndex&);