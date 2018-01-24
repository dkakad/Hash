#pragma once
#include "Data.h"
#include "Data.cpp"

#define DEFAULT_SIZE 10

template <typename T>
class Hash {
	Data<T> **arr;
	int tableSize;
	int occSize;
	int getNextPrime(int n);
public:
	Hash();
	Hash(int Size);
	Data<T>** getArray();
	void setArray(Data<T> **newArray);
	int getTableSize();
	void setTableSize(int newTableSize);
	int getOccSize();
	void setOccSize(int newOccSize);
	int hashFunc(T data);
	void rehash();
	void insertHash(Data<T> *newData);
	bool searchHash(Data<T> *findData);
	void deleteHash(Data<T> *delData);
};