#include <string>
#include <iostream>

using namespace std;

template<size_t n, typename T> 
class Array
{
private:
	size_t _size;
	T *all;
public:
	explicit Array();
	~Array();

	const size_t size() const { return _size; }

	T& operator [](size_t index);

	class BadArray;
};

template<size_t n, typename T>
class Array<n, T>::BadArray
{
private:
	const string _reason;
	const size_t _index;
public:
	BadArray(const string& reason = "unknown", const size_t index = 0);
	~BadArray();

	void diagnose() const;
};

template<size_t n, typename T>
inline Array<n, T>::Array() : _size(n), all(new T[_size])
{
	return;
}

template<size_t n, typename T>
inline Array<n, T>::~Array()
{
	delete[] all;
	
	return;
}

template<size_t n, typename T>
inline T & Array<n, T>::operator[](size_t index)
{
	if (index >= this->size() || index < 0)
	{
		throw BadArray("Bad index", index);
	}
		
	return all[index];
}

template<size_t n, typename T>
inline Array<n, T>::BadArray::BadArray(const string& reason, const size_t index) : _reason(reason), _index(index)
{
	return;
}

template<size_t n, typename T>
inline Array<n, T>::BadArray::~BadArray()
{
	return;
}

template<size_t n, typename T>
inline void Array<n, T>::BadArray::diagnose() const
{
	cerr << _reason << ": " << _index << endl;
}