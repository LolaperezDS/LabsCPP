//модуль lab1.cpp
#include <cmath>
#include <iostream>
using namespace std;


struct Vector3Float {
public:
	float x, y, z;
	float Length() { return length(); }
	Vector3Float Normalized() { return normalize(); }

	Vector3Float(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3Float() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	float operator*(const Vector3Float &b) {
		return this->x * b.x + this->y * b.y + this->z * b.z;
	}
private:
	Vector3Float normalize() {
		float length = Length();
		return Vector3Float(x / length, y / length, z / length);
	}

	float length() {
		return sqrt(x * x + y * y + z * z);
	}
};



int main()
{ //добавление возможности писать на русском языке
	setlocale(LC_ALL, "RUS");
	Vector3Float vec1, vec2;
	printf("Введите координаты первого вектора: x, y, z = \n");
	cin >> vec1.x;
	cin >> vec1.y;
	cin >> vec1.z;
	printf("Введите координаты второго вектора: x, y, z = \n");
	cin >> vec2.x;
	cin >> vec2.y;
	cin >> vec2.z;

	cout << "Длина 1 вектора: " << vec1.Length() << endl;
	cout << "Длина 2 вектора: " << vec2.Length() << endl;
	cout << "Скалярное произведение: " << vec1 * vec2 << endl;
	system("pause"); //Для продолжения нажмите любую клавишу...
	//(чтобы окошко не закрывалось)
	return 0;
}