#include"SecondYearStudent.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


void loadStudentInfo(string, SecondYearStudent[]);

int main() 
{
	srand(static_cast<unsigned int>(time(nullptr)));
	SecondYearStudent *students = new SecondYearStudent[4];

	string filename = "Students.csv";
	loadStudentInfo(filename, students);

	for (int i = 0; i < 4; i++) 
	{
		students[i].calcFinalMark();
		students[i].displayStudent();
		
	}

	delete[] students;

	system("pause");
	return 0;
}

void loadStudentInfo(string filename, SecondYearStudent students[]) 
{
	ifstream file(filename);

	if (!file.is_open()) 
	{
		cout << "Your file coudln't be opened Sorry!!." << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	string subCodes[] = { "DSO", "TPG", "ISY", "SSF" };
	int count = 0;

	while (getline(file, line)) 
	{
		istringstream iss(line);
		int studentNumber;
		string name, surname;
		double assignmentMarks[4], testMarks[4];

		getline(iss, line, ',');
		studentNumber = std::stoi(line);
		getline(iss, name, ',');
		getline(iss, surname, ',');
		for (int j = 0; j < 4; j++) {
			std::getline(iss, line, ',');
			assignmentMarks[j] = std::stod(line);
			std::getline(iss, line, ',');
			testMarks[j] = std::stod(line);
		}
		char cName[30];
		char cSurname[30];
		strncpy_s(cName, name.c_str(), sizeof(cName));
		cName[sizeof(cName) - 1] = '\0';

		strncpy_s(cSurname, surname.c_str(), sizeof(cSurname));
		cSurname[sizeof(cSurname) - 1] = '\0';

		students[count].setStudent(studentNumber, cName, cSurname, subCodes, assignmentMarks, testMarks);
		count++;
	}
	file.close();
}