#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

enum mark;


struct Student {
public:
	std::string Name;
	std::string SName;
	int ClassNum;
	std::vector<mark> Marks;
	Student(std::string, std::string, int, std::vector<mark>);
	Student(std::string);
	~Student();
	std::string Serialized();
};


std::vector<std::string> Split(std::string, char);
void WriteFile(std::vector<Student>);
std::vector<Student> ReadFile();