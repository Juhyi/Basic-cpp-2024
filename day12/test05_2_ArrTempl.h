// date : 2024-03-08
// file : test05_2_ArrTempl.h
// desc : p.562

/*
#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) { }
	BoundCheckArray& operator=(const BoundCheckArray& arr) { }

public:
	BoundCheckArray(int len);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
	arr = new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
}

template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]arr;
}
#endif // !__ARRAY_TEMPLATE_H_
*/