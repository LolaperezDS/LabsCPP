#include <iostream>
#include "func.h"
#include <vector>
#include <string>
using namespace std;


int main() {
	setlocale(LC_ALL, "RUS");

	vector<Student> studenti = ReadFile();

	for (int i = 0; i < size(studenti); i++) {
		for (int j = 0; j < i; j++) {
			if (studenti[i].SName == studenti[j].SName) {
				cout << "Однофамильцы: " << endl;
				cout << studenti[i].SName << " " << studenti[i].Name << endl;
				cout << studenti[j].SName << " " << studenti[j].Name << endl;
				cout << "-----------------------" << endl;
			}
		}
	}

	bool isNorm;
	cout << "Нет оценок хуже 4 у студентов:" << endl;
	for (int i = 0; i < size(studenti); i++) {
		isNorm = true;
		for (int j = 0; j < size(studenti[i].Marks); j++) {
			if ((int)studenti[i].Marks[j] < 4) isNorm = false;
		}
		if (isNorm) {
			cout << studenti[i].Serialized() << endl;
		}
	}


	system("pause");
	return 0;
}