#include "Hash.h"

int main() {
	Hash<int> *h = new Hash<int>();
	Data<int> *d1 = new Data<int>(5, 1);
	Data<int> *d2 = new Data<int>(8, 1);
	Data<int> *d3 = new Data<int>(8, 1);
	Data<int> *d4 = new Data<int>(8, 1);
	Data<int> *d5 = new Data<int>(1, 1);
	Data<int> *d6 = new Data<int>(4, 1);

	h->insertHash(d1);
	h->insertHash(d2);
	h->insertHash(d3);
	h->insertHash(d4);
	h->insertHash(d5);
	h->insertHash(d6);

	for (int i = 0; i < h->getTableSize(); i++) {
		printf("%d = %d, %d \n", i, h->getArray()[i]->getVal(), h->getArray()[i]->getFreq());
	}
	printf("\n");


	return 0;
}