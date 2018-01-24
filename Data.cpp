#include "Data.h"

template <typename T>
Data<T>::Data() {
	val = NULL;
	freq = 1;
}

template <typename T>
Data<T>::Data(T newVal, int newFreq) {
	val = newVal;
	freq = newFreq;
}

template <typename T>
T Data<T>::getVal() {
	return val;
}

template <typename T>
void Data<T>::setVal(T newVal) {
	val = newVal;
}

template <typename T>
int Data<T>::getFreq() {
	return freq;
}

template <typename T>
void Data<T>::setFreq(int newFreq) {
	freq = newFreq;
}