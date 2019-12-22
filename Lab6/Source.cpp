#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;



int main()
{
	testAll();
	cout << "Short done" << endl;

	testAllExtended();
	cout << "Extended done" << endl;

	system("pause");

	return 0;
}

