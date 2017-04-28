#include "BadIndex.h"

String::BadIndex::BadIndex(const char* reason) : _reason(reason)
{
	return;
}

String::BadIndex::~BadIndex()
{
	return;
}

ostream& operator<<(ostream& os, const String::BadIndex& badIndex) 
{
	return os << badIndex.getReason();
}