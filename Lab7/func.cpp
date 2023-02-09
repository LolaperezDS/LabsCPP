#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define PATH_TO_FILE "test.txt"

std::vector<std::string> Split(std::string, char);

enum mark { very_bad = 1, bad = 2, satisfactory = 3, good = 4, excellent = 5 };

struct Student {
public:
	std::string Name;
	std::string SName;
	int ClassNum;
	std::vector<mark> Marks;

	Student(std::string Name, std::string SName, int ClassNum, std::vector<mark> marks) {
		this->ClassNum = ClassNum;
		this->Name = Name;
		this->SName = SName;
		this->Marks = marks;
	}

	Student(std::string serializedString) {
		std::vector<std::string> tmp = Split(serializedString, ';');
		this->Name = tmp[0];
		this->SName = tmp[1];
		this->ClassNum = stoi(tmp[2]);
		for (size_t i = 3; i < size(tmp); i++) {
			this->Marks.push_back((mark)stoi(tmp[i]));
		}
	}


	std::string Serialized() {
		std::string out = Name + ";" + SName + ";" + std::to_string(ClassNum);
		for (size_t i = 0; i < size(Marks); i++) {
			out = out + ";" + std::to_string((int)Marks[i]);
		}
		return out;
	}
};


std::vector<std::string> Split(std::string strToSplit, char separator = ' ') {
	int i = 0;
	std::vector<std::string> out;
	// Temporary string used to split the string.
	std::string s;
	while (strToSplit[i] != '\0') {
		if (strToSplit[i] != separator) {
			// Append the char to the temp string.
			s += strToSplit[i];
		}
		else {
			out.push_back(*&s);
			s.clear();
		}
		i++;
	}
	out.push_back(*&s);
	return out;
}

void WriteFile(std::vector<Student> students) {
	std::ofstream out;
	out.open(PATH_TO_FILE);
	for (size_t i = 0; i < size(students); i++) {
		out << students[i].Serialized() << "\n";
	}
	out.close();
}

std::vector<Student> ReadFile() {
	std::vector<Student> out;
	std::ifstream in(PATH_TO_FILE); // окрываем файл для чтения
	std::string line;
	while (getline(in, line))
	{
		out.push_back(Student(line));
	}
	in.close();
	return out;
}