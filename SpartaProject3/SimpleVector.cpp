#include <iostream>
#include "SimpleVector.h"

using namespace std;

template <typename T>
void SimpleVector<T>::push_back(const T& value) {

}

template <typename T>
void SimpleVector<T>::pop_back() {

}

template <typename T>
int SimpleVector<T>::size() {
	return currentSize;
}

template <typename T>
int SimpleVector<T>::capacity() {
	return currentCapacity;
}