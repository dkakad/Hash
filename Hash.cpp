#include "Hash.h"
#include <math.h>

template class Data<int>;
template class Hash<int>;

template <typename T>
Hash<T>::Hash() {
	tableSize = DEFAULT_SIZE;
	arr = new Data<T>*[tableSize];
	for (int i = 0; i < tableSize; i++) {
		arr[i] = new Data<T>(NULL, 0);
	}
	occSize = 0;
}

template <typename T>
Hash<T>::Hash(int size) {
	tableSize = size;
	arr = new Data<T>*[tableSize];
	for (int i = 0; i < tableSize; i++) {
		arr[i] = new Data<T>(NULL, 0);
	}
	occSize = 0;
}

template <typename T>
Data<T>** Hash<T>::getArray() {
	return arr;
}

template <typename T>
void Hash<T>::setArray(Data<T> **newArr) {
	arr = newArr;
}

template <typename T>
int Hash<T>::getTableSize() {
	return tableSize;
}

template <typename T>
void Hash<T>::setTableSize(int newTableSize) {
	tableSize = newTableSize;
}

template <typename T>
int Hash<T>::getOccSize() {
	return occSize;
}

template <typename T>
void Hash<T>::setOccSize(int newOccSize) {
	occSize = newOccSize;
}

/*
 * Define this function according to data type T.
 */

template <typename T>
int Hash<T>::hashFunc(T data) {
	int n = data;
	int sum = 0;
	int fact = 7;

	while (n != 0) {
		sum = ((sum + (n % tableSize)) % tableSize) * fact;
		fact = fact * 7;
		n = n / 10;
	}
	return (sum % tableSize);
}

template <typename T>
void Hash<T>::rehash() {
	double load = (double)occSize / tableSize;
	int newSize = getNextPrime(2 * tableSize);

	Data<T> **arr1 = new Data<T>*[newSize];
	for (int i = 0; i < newSize; i++) {
		arr1[i] = new Data<T>(NULL, 0);
	}
	int oldSize = tableSize;
	tableSize = newSize;
	for (int i = 0; i < oldSize; i++) {
		if (arr[i] == 0) {
			continue;
		}
		int idx = hashFunc(arr[i]->getVal());
		int j;
		for (j = idx; arr1[j % tableSize]->getVal() != 0; j++) {

		}
		arr1[j] = arr[i];
	}
	arr = arr1;
}
template <typename T>
void Hash<T>::insertHash(Data<T> *newData) {
	if (searchHash(newData)) {
		int hashVal = hashFunc(newData->getVal());
		int idx;

		for (idx = hashVal; arr[idx % tableSize]->getVal() != 0; idx++) {
			if (arr[idx]->getVal() == newData->getVal()) {
				arr[idx]->setFreq(arr[idx]->getFreq() + 1);
			}
		}
		return;
	}
	occSize = occSize + 1;
	double loadFactor = (double)occSize / tableSize;
	if (loadFactor > 0.5) {
		rehash();
	}
	int hashVal = hashFunc(newData->getVal());
	int idx;

	for (idx = hashVal; arr[idx % tableSize]->getVal() != 0; idx++) {

	}
	arr[idx % tableSize] = newData;
	
}

template <typename T>
bool Hash<T>::searchHash(Data<T> *findData) {
	int hashVal = hashFunc(findData->getVal());
	int idx;

	for (idx = hashVal; arr[idx % tableSize]->getVal() != 0; idx++) {
		if (arr[idx]->getVal() == findData->getVal()) {
			return true;
		}
	}
	return false;
}

template <typename T>
void Hash<T>::deleteHash(Data<T> *delData) {
	int hashVal = hashFunc(delData->getVal());
	int idx;
	for (idx = hashVal; arr[idx % tableSize]->getVal() != 0; idx++) {
		if (arr[idx]->getVal() == delData->getVal()) {
			delData->setVal(NULL);
		}
	}
}

template <typename T>
int Hash<T>::getNextPrime(int n) {
	n = n + 1;
	while (true) {
		double limit = sqrt((double)n);
		int lowlimit = (int)limit + 1;
		int i;
		for (i = 2; i <= lowlimit; i++) {
			if ((n % i) == 0) {
				break;
			}
		}
		if (i > lowlimit) {
			return n;
		}
		n = n + 1;
	}
}

