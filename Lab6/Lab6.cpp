#include <iostream>
#include "functions.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	int k, n, m;
	cout << "Введите k:" << endl;
	cin >> k;
	cout << "Введите длину 1 массива:" << endl;
	cin >> n;
	cout << "Введите длину 2 массива:" << endl;
	cin >> m;

	int arr1[100]{ 0 };
	int arr2[100]{ 0 };

	ArrayInstance(begin(arr1), n, false);
	PrintArray(begin(arr1), end(arr1), "Массив 1 до преобразования");
	if (!InArray(begin(arr1), end(arr1), k)) *FirstMax(begin(arr1), end(arr1)) = k;
	PrintArray(begin(arr1), end(arr1), "Массив 1 после преобразования");

	
	ArrayInstance(begin(arr2), m, false);
	PrintArray(begin(arr2), end(arr2), "Массив 2 до преобразования");
	if (!InArray(begin(arr2), end(arr2), 10)) *FirstMax(begin(arr2), end(arr2)) = 10;
	PrintArray(begin(arr2), end(arr2), "Массив 2 после преобразования");

	system("pause");
	return 0;
}