// модуль lab2.cpp

#include <iostream>
#include <algorithm>
using namespace std;

#define ARRAY_LENGTH 4

int main()
{
	setlocale(LC_ALL, "RUS");
	//диалог и ввод данных--------------------------------------------------------------------------
	int lm = 0; //для меню
	cout << "Выберите желаемое действие: " << endl;
	cout << "1: Решить задачу: " << endl;
	cout << "2: Выйти из приложения (без решения задачи)" << endl;
	cout << "Введите желаемое действие: ";
	cin >> lm;
	switch (lm) { //switch
	case 1:
		float values[ARRAY_LENGTH];
		cout << "Введите " << ARRAY_LENGTH << " числа:" << endl;
		for (int i = 0; i < size(values); i++) {
			cin >> values[i];
		}
		//решение задачи---------------------------------------------------------------------------------	
		float sorted_values[ARRAY_LENGTH];
		copy(values, values + size(values), sorted_values);
		sort(sorted_values, sorted_values + size(sorted_values));
		if (equal(values, values + size(values), sorted_values)) {
			for (int i = 0; i < size(values); i++) {
				values[i] = values[size(values) - 1];
			}
		}
		else {

			reverse(sorted_values, sorted_values + size(sorted_values));
			// Проверка на отсутствие одинаковых элементов
			bool setLike = true;
			for (int i = 0; i < size(sorted_values) - 1; i++) {
				if (sorted_values[i] == sorted_values[i + 1]) {
					setLike = false;
					break;
				}
			}
			if (equal(values, values + size(values), sorted_values) && setLike);
			else {
				for (int i = 0; i < size(values); i++) {
					values[i] *= values[i];
				}
			}
		}
		//вывод результатов-----------------------------------------------------------------------------
		for (int i = 0; i < size(values); i++) {
			cout << "Элемент " << i << " :\t" << values[i] << "\n";
		}
		break;
	case 2:
		break;
	default:
		throw new exception("Неправильный выбор, доступно только 1 и 2\n");
	}// конец switch
	system("pause");
	return 0;
}
