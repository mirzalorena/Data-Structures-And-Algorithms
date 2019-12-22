#include "ShortTest.h"
#include <assert.h>
#include <iostream>
#include "Bag.h"
#include "BagIterator.h"

using namespace std;


void testAll() {
	Bag b;
	assert(b.isEmpty() == true);
	assert(b.sizeArray() == 0);
	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	assert(b.sizeArray() == 7);
	assert(b.search(10) == true);
	assert(b.search(20) == false);
	assert(b.nrOccurences(1) == 2);
	assert(b.nrOccurences(7) == 1);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.sizeArray() == 6);
	assert(b.nrOccurences(1) == 1);

	assert(b.elementsWithThisFrequency(10) == 0);
	assert(b.elementsWithThisFrequency(1) == 6);

	BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		//cout << it.getCurrent() << endl;
		it.next();
	}
}
