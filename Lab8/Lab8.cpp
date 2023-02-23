// модуль lab8.cpp

#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

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


	int array_l;
	cout << "Введите длинну массива: ";
	cin >> array_l;
	vector<float> values;
	vector<float> sorted_values;
	switch (lm) { //switch
	case 1:

		for (int i = 0; i < array_l; i++) {
			values.push_back(rand() / 100);
		}
		//решение задачи---------------------------------------------------------------------------------	
		sorted_values = values;
		sort(sorted_values.begin(), sorted_values.end());
		if (equal(sorted_values.begin(), sorted_values.end(), values.begin())) {
			for (int i = 0; i < values.size(); i++) {
				values[i] = sorted_values[sorted_values.size() - 1];
			}
		}
		else {

			reverse(sorted_values.begin(), sorted_values.end());
			// Проверка на отсутствие одинаковых элементов
			bool setLike = true;
			for (int i = 0; i < sorted_values.size() - 1; i++) {
				if (sorted_values[i] == sorted_values[i + 1]) {
					setLike = false;
					break;
				}
			}
			if (equal(sorted_values.begin(), sorted_values.end(), values.begin()) && setLike);
			else {
				for (int i = 0; i < size(values); i++) {
					values[i] *= values[i];
				}
			}
		}
		//вывод результатов-----------------------------------------------------------------------------
		for (int i = 0; i < values.size(); i++) {
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