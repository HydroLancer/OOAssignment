// OOMapTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "MapTemplate.h"
#include <iostream>
#include <string>

int main()
{
	MapTemplate<int, int>* test = new MapTemplate<int, int>(5, 4);
	test->push(3, 2);
	
	std::cout << test->output(5) << std::endl;
	std::cout << test->output(3) << std::endl;
	std::cout << test->output(1) << std::endl;
	test->erase(11);
	std::cout << "Array size: " << test->size() << std::endl;
	std::cout << "---------------" << std::endl;

	MapTemplate<char, char>* test2 = new MapTemplate<char, char>('a', 'z');
	test2->push('b', 'y');
	std::cout << test2->output('b') << std::endl;
	std::cout << test2->output('a') << std::endl;
	system("pause");

	delete test;
	delete test2;
	return 0;
}