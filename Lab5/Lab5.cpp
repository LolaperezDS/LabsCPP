// модуль lab5.cpp 
#include <iostream>
#include <string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "RUS");

	string instr;
	string outstr = "";
	int spaceIndex;
	bool withSpace;

	int engLowEdges[]{ 97, 122 };
	int engUpEdges[]{ 65, 90 };
	int rusUpEdges[]{ -64, -33 };
	int rusLowEdges[]{ -32, -1 };
	int numbersEdges[]{ 48, 57 };

	// Проверка на пробел 1 символом и на наличие пробела
	do {
		withSpace = false;
		cout << "Введите строку содержащую пробел, первый символ не должен быть пробелом" << endl;

		// СЧИТАТЬ СТРОКУ С ПРОБЕЛАМИ
		getline(cin, instr);
		for (int i = 0; i < instr.length(); i++) {
			if ((char)instr[i] == ' ') {
				withSpace = true;
				spaceIndex = i;
				break;
			}
		}
	} while (instr[0] == ' ' || !withSpace);
	
	for (int i = 0; i < spaceIndex; i++) {
		if ((int)instr[i] >= engLowEdges[0] && (int)instr[i] <= engLowEdges[1] || (int)instr[i] >= engUpEdges[0] && (int)instr[i] <= engUpEdges[1] ||
			(int)instr[i] >= rusUpEdges[0] && (int)instr[i] <= rusUpEdges[1] || (int)instr[i] >= rusLowEdges[0] && (int)instr[i] <= rusLowEdges[1] ||
			(int)instr[i] >= numbersEdges[0] && (int)instr[i] <= numbersEdges[1]) {
			outstr += tolower(instr[i]);
		}
	}

	outstr += instr.substr(spaceIndex, instr.length() - spaceIndex);

	cout << outstr << endl;

	system("pause");
	return 0;
}