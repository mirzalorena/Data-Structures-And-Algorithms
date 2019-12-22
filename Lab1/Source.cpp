
#pragma once
#include <iostream>
#include "DA_short.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
//#include "DA_extended.h"
using namespace std;

int main() {

	//Dynamic Array tests
	testAllDA();
	std::cout << "Short tests for Dynamic Array" << std::endl;

	testAll();
	std::cout << "Short Success" << std::endl;

	testAllExtended();
	std::cout << "Extended Success" << std::endl;


	system("pause");
	return 0;
}