#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main()
{
	testAll();
		cout << "Short done"<<endl;

	testAllExtended();
		cout << "Extended Done";

	//system("pause");

	return 0;
}