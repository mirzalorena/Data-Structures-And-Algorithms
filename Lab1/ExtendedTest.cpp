#include <assert.h>
#include "Bag.h"
#include "ExtendedTest.h"
#include "BagIterator.h"
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

void testCreate() {
	Bag b;
	assert(b.sizeArray() == 0);
	assert(b.isEmpty() == true);
	for (int i = -5; i < 5; i++) {
		assert(b.search(i) == false);
	}
	for (int i = -10; i < 10; i++) {
		assert(b.remove(i) == false);
	}
	for (int i = -10; i < 10; i++) {
		assert(b.nrOccurences(i) == 0);
	}

	BagIterator it = b.iterator();
	assert(it.valid() == false);
}

void testAdd() {
	Bag b;
	for (int i = 0; i < 10; i++) {
		b.add(i);
	}
	assert(b.isEmpty() == false);
	assert(b.sizeArray() == 10);
	for (int i = -10; i < 20; i++) {
		b.add(i);
	}
	assert(b.isEmpty() == false);
	assert(b.sizeArray() == 40);
	for (int i = -100; i < 100; i++) {
		b.add(i);
	}
	assert(b.isEmpty() == false);
	assert(b.sizeArray() == 240);
	for (int i = -200; i < 200; i++) {
		int count = b.nrOccurences(i);
		if (i < -100) {
			assert(count == 0);
			assert(b.search(i) == false);
		}
		else if (i < -10) {
			assert(count == 1);
			assert(b.search(i) == true);
		}
		else if (i < 0) {
			assert(count == 2);
			assert(b.search(i) == true);
		}
		else if (i < 10) {
			assert(count == 3);
			assert(b.search(i) == true);
		}
		else if (i < 20) {
			assert(count == 2);
			assert(b.search(i) == true);
		}
		else if (i < 100) {
			assert(count == 1);
			assert(b.search(i) == true);
		}
		else {
			assert(count == 0);
			assert(b.search(i) == false);
		}
	}
	for (int i = 10000; i > -10000; i--) {
		b.add(i);
	}
	assert(b.sizeArray() == 20240);
}

void testRemove() {
	Bag b;
	for (int i = -100; i < 100; i++) {
		assert(b.remove(i) == false);
	}
	assert(b.sizeArray() == 0);
	for (int i = -100; i < 100; i = i + 2) {
		b.add(i);
	}
	for (int i = -100; i < 100; i++) {

		if (i % 2 == 0) {
			assert(b.remove(i) == true);
		}
		else {
			assert(b.remove(i) == false);
		}
	}
	assert(b.sizeArray() == 0);
	for (int i = -100; i <= 100; i = i + 2) {
		b.add(i);
	}
	for (int i = 100; i > -100; i--) {
		if (i % 2 == 0) {
			assert(b.remove(i) == true);
		}
		else {
			assert(b.remove(i) == false);
		}
	}

	assert(b.sizeArray() == 1);
	b.remove(-100);
	for (int i = -100; i < 100; i++) {
		b.add(i);
		b.add(i);
		b.add(i);
		b.add(i);
		b.add(i);
	}
	assert(b.sizeArray() == 1000);
	for (int i = -100; i < 100; i++) {
		assert(b.nrOccurences(i) == 5);
	}
	for (int i = -100; i < 100; i++) {
		assert(b.remove(i) == true);
	}
	assert(b.sizeArray() == 800);
	for (int i = -100; i < 100; i++) {
		assert(b.nrOccurences(i) == 4);
	}
	for (int i = -200; i < 200; i++) {
		if (i < -100 || i >= 100) {
			assert(b.remove(i) == false);
			assert(b.remove(i) == false);
			assert(b.remove(i) == false);
			assert(b.remove(i) == false);
			assert(b.remove(i) == false);
		}
		else {
			assert(b.remove(i) == true);
			assert(b.remove(i) == true);
			assert(b.remove(i) == true);
			assert(b.remove(i) == true);
			assert(b.remove(i) == false);
		}
	}
	assert(b.sizeArray() == 0);
	for (int i = -1000; i < 1000; i++) {
		assert(b.nrOccurences(i) == 0);
	}
	int min = -200;
	int max = 200;
	while (min < max) {
		b.add(min);
		b.add(max);
		min++;
		max--;
	}
	b.add(0);
	b.add(0);
	assert(b.sizeArray() == 402);
	for (int i = -30; i < 30; i++) {

		assert(b.search(i) == true);
		assert(b.remove(i) == true);
		if (i != 0) {
			assert(b.search(i) == false);
		}
		else {
			assert(b.search(i) == true);
		}
	}
	assert(b.sizeArray() == 342);

}


void testIterator() {
	Bag b;
	BagIterator it = b.iterator();
	assert(it.valid() == false);
	try {
		it.next();
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		it.getCurrent();
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	for (int i = 0; i < 100; i++) {
		b.add(33);
	}
	BagIterator it2 = b.iterator();
	assert(it2.valid() == true);
	for (int i = 0; i < 100; i++) {
		TElem elem = it2.getCurrent();
		assert(elem == 33);
		it2.next();
	}
	assert(it2.valid() == false);
	it2.first();
	assert(it2.valid() == true);
	for (int i = 0; i < 100; i++) {
		TElem elem = it2.getCurrent();
		TElem elem2 = it2.getCurrent();
		assert(elem == 33);
		assert(elem2 == 33);
		it2.next();
	}
	assert(it2.valid() == false);
	try {
		it2.next();
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		it2.getCurrent();
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}


	Bag b2;
	for (int i = -100; i < 100; i++) {
		b2.add(i);
		b2.add(i);
		b2.add(i);
	}
	BagIterator it3 = b2.iterator();
	assert(it3.valid() == true);
	for (int i = 0; i < 600; i++) {
		TElem e1 = it3.getCurrent();
		it3.next();
	}
	assert(it3.valid() == false);
	it3.first();
	assert(it3.valid() == true);
	Bag b3;
	for (int i = 0; i < 200; i = i + 4) {
		b3.add(i);
	}
	BagIterator it4 = b3.iterator();
	assert(it4.valid() == true);
	int count = 0;
	while (it4.valid()) {
		TElem e = it4.getCurrent();
		assert(e % 4 == 0);
		it4.next();
		count++;
	}
	assert(count == 50);
	Bag b4;
	for (int i = 0; i < 100; i++) {
		b4.add(i);
		b4.add(i * (-2));
		b4.add(i * 2);
		b4.add(i / 2);
		b4.add(i / (-2));
	}
	vector<TElem> elements;
	BagIterator it5 = b4.iterator();
	while (it5.valid()) {
		TElem e = it5.getCurrent();
		elements.push_back(e);
		it5.next();
	}

	assert(elements.size() == b4.sizeArray());
	for (unsigned int i = 0; i < elements.size(); i++) {
		TElem lastElem = elements.at(elements.size() - i - 1);
		assert(b4.search(lastElem) == true);
		b4.remove(lastElem);
	}

	Bag b5;
	for (int i = 0; i < 100; i++) {
		b5.add(i);
		b5.add(i * (-2));
		b5.add(i * 2);
		b5.add(i / 2);
		b5.add(i / (-2));
	}
	vector<TElem> elements2;
	BagIterator it6 = b5.iterator();
	while (it6.valid()) {
		TElem e = it6.getCurrent();
		elements2.push_back(e);
		it6.next();
	}

	assert(elements2.size() == b5.sizeArray());
	for (unsigned int i = 0; i < elements2.size(); i++) {
		TElem firstElem = elements2.at(i);
		assert(b5.search(firstElem) == true);
		b5.remove(firstElem);
	}
}

void testQuantity() {
	Bag b;
	for (int i = 10; i >= 1; i--) {
		for (int j = -30000; j < 30000; j = j + i) {
			b.add(j);
		}
	}
	assert(b.sizeArray() == 175739);
	assert(b.nrOccurences(-30000) == 10);
	BagIterator it = b.iterator();
	assert(it.valid() == true);
	for (int i = 0; i < b.sizeArray(); i++) {
		it.next();
	}
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		assert(b.search(e) == true);
		assert(b.nrOccurences(e) > 0);
		it.next();
	}
	assert(it.valid() == false);
	for (int i = 0; i < 10; i++) {
		for (int j = 40000; j >= -40000; j--) {
			b.remove(j);
		}
	}
	assert(b.sizeArray() == 0);
}


void testAllExtended() {
	testCreate();
	testAdd();
	testRemove();
	testIterator();
	testQuantity();


}
