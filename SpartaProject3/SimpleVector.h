#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <algorithm>
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
		delete[] data;
	}

 	T& operator[](int idx) {
		return data[idx];
	}

	void push_back(const T& value)
	{
		if (currentSize < currentCapacity) {
			currentSize++;
			data[currentSize - 1] = value;
		}
		else {
			currentCapacity += 5;

			T* newData = new T[currentCapacity + 1]; // +1 미적용시 버퍼 오버런 경고문구가뜸..
			for (int i = 0; i < currentSize; i++) {
				newData[i] = data[i];
			}

			currentSize++;
			newData[currentSize - 1] = value;

			delete data;
			data = newData;
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