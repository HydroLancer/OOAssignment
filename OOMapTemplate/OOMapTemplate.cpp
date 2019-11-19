// OOMapTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "MapTemplate.h"
#include <iostream>

int main()
{
	MapTemplate<int, int>* test = new MapTemplate<int, int>;
	test->push();
	system("pause");
}