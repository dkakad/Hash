#pragma once
#include <stdio.h>

template <typename T>
class Data {
	T val;
	int freq;
public:
	Data();
	Data(T newVal, int newFreq);
	T getVal();
	void setVal(T newVal);
	int getFreq();
	void setFreq(int newFreq);
};