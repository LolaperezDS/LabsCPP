#include <iostream>
using namespace std;


void PrintArray(int* begin, int* end, string msg) {
	cout << msg << endl;
	for (int* ptr = begin; ptr != end; ptr++) {
		if (*ptr != 0) {
			cout << *ptr << ", ";
		}
	}
	cout << endl;
}

bool InArray(int* begin, int* end, int y) {
	for (int* ptr = begin; ptr != end; ptr++) {
		if (*ptr == y) return true;
	}
	return false;
}

void ArrayInstance(int* begin, int count, bool isRandomized) {
	if (isRandomized) for (int* ptr = begin; ptr <= begin + count - 1; ptr++) *ptr = rand();
	else 
	{
		cout << "¬ведите массив вручную" << endl;
		for (int* ptr = begin; ptr <= begin + count - 1; ptr++) cin >> *ptr;
	}
}


int* FirstMax(int* begin, int* end) {
	int max = *begin;
	int* maxRef = begin;
	for (int* ptr = begin; ptr != end; ptr++) {
		if (*ptr > max) {
			maxRef = ptr;
			max = *ptr;
		}
	}
	return maxRef;
}