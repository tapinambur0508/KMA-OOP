#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
	const size_t _size;
	T *_allocator;

	Array& operator= (const Array&);
	Array(const Array&);
public:
	class BadArray;

	explicit Array(const size_t size);
	~Array();

	size_t size() const { return _size; }

	T& operator[] (const size_t);
	const T operator[] (const size_t) const;
};

template<class T>
class Array<T>::BadArray
{
private:
	const string _reason;
	const size_t _index;
public:
	BadArray(const string& reason = "", const size_t index = 0);
	~BadArray();

	const string& reason() const { return _reason; }
	const size_t index() const { return _index; }

	void diagnose();
};

//Array
template<class T>
Array<T>::Array(const size_t my_size) : _size(my_size), _allocator(new T[size()])
{
	return;
};

template<class T>
Array<T>::~Array()
{
	delete[] this->_allocator;

	return;
};

template<class T>
T& Array<T>::operator[] (const size_t index) 
{
	if (index >= size() || index < 0)
	{
		throw BadArray("Bad index: ", index);
	}
		
	return _allocator[index];
};

template<class T>
const T Array<T>::operator[](const size_t index) const 
{
	if (index >= size() || index < 0)
	{
		throw BadArray("Bad index: ", index);
	}

	return _allocator[index];
};

//BadArray
template<class T>
Array<T>::BadArray::BadArray(const string& reason, const size_t index) : _reason(reason), _index(index)
{
	return;
};

template<class T>
Array<T>::BadArray::~BadArray()
{
	return;
}

template<class T>
void Array<T>::BadArray::diagnose()
{
	cout << reason() << " : " << index() << endl;
};