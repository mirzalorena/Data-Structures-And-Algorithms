#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"

using namespace std;

bool rel(TComp r1, TComp r2) {
	return r1 <= r2;
}

int main()
{
	testAll();
	cout << "Short done"<<endl;

	testAllExtended();
	cout << "Extended done" << endl;




	system("pause");
	return 0;
}