// OOMapTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "MapTemplate.h"
#include <iostream>
#include <string>

int main()
{
	MapTemplate<int, int>* test = new MapTemplate<int, int>(50);
	test->push(9, 5);
	test->push(4, 2);
	test->push(1, 6);
	std::cout << test->output(9) << std::endl;
	std::cout << test->output(4) << std::endl;
	std::cout << test->output(1) << std::endl;
	test->erase(11);
	std::cout << "Array size: " << test->size() << std::endl;
	std::cout << "---------------" << std::endl;

	MapTemplate<char, char>* test2 = new MapTemplate<char, char>;
	test2->push('a', '4');
	test2->push('b', '6');
	std::cout << test2->output('b') << std::endl;
	std::cout << test2->output('a') << std::endl;
	system("pause");

	delete test;
	delete test2;
	return 0;
}