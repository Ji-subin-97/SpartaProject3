#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* data;
	int currentSize;
	int currentCapacity;

	void resize();
public:
	SimpleVector() : currentSize(0), currentCapacity(10)
	{
		data = new T[10];
	}
	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity)
	{
		data = new T[capacity];
	}
	SimpleVector(const SimpleVector& object)
	{
		data = object.data;
		currentSize = object.currentSize;
		currentCapacity = object.currentCapacity;
	}
	~SimpleVector() 
	{
		delete data;
	}

	/* === 연산자 오버로딩 === */
 	T& operator[](int idx) {
		return data[idx];
	}
	/* ======================= */

	void push_back(const T& value)
	{
		if (currentSize < currentCapacity) {
			currentSize++;
			data[currentSize - 1] = value;
		}
	}
	void pop_back()
	{
		if (currentSize != 0) {
			currentSize--;
		}
	}
	int size() 
	{
		return currentSize;
	}
	int capacity() 
	{
		return currentCapacity;
	}
};

#endif