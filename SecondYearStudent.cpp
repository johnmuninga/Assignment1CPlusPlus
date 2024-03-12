#include"SecondYearStudent.h"
#include<string>
#include<iostream>
#include<cstring>
#include <cstdlib>
#include <ctime>
using namespace std;


SecondYearStudent::SecondYearStudent() 
{
	for (int i = 0; i < 4; i++) {
		code[i] = "";
		assignment[i] = 0.0;
		test[i] = 0.0;
		predicate[i] = 0.0;
		exam[i] = 0.0;
		final[i] = 0.0;
	}

	testWeight = 60;
	assignmentWeight = 40;
}

void SecondYearStudent::setStudent(int studentNumber, char name[], char surname[], string code[], double assignment[], double test[]) {

	this->studentNumber = studentNumber;
	strcpy_s(this->name, name);
	strcpy_s(this->surname, surname);

	for (int i = 0; i < 4; i++) {
		this->code[i] = code[i];
		this->assignment[i] = assignment[i];
		this->test[i] = test[i];
	}
}

void SecondYearStudent::calcPredicate() 
{
	for (int i = 0; i < 4; ++i) {
		predicate[i] = (assignment[i] * assignmentWeight / 100.0) + (test[i] * testWeight / 100.0);
	}
}

void SecondYearStudent::calcFinalMark() 
{
	SecondYearStudent::calcPredicate();
	
	for (int i = 0; i < 4; i++) 
	{
		exam[i] = rand() % 101;
		final[i] = (predicate[i] + exam[i]) / 2.0;
	}
}

double SecondYearStudent::determineStudentAvg() 
{
	double total = 0.0;
	for (int i = 0; i < 4; i++) 
	{
		total = total + final[i];
	}

	return total / 4;
}

void SecondYearStudent::displayStudent() 
{
	
	Student::displayStudent();

	for (int i = 0; i < 4; i++) {
		cout << "\t" << code[i] << "\t" << predicate[i] << "\t" << exam[i] << "\t" << final[i] << "%" << std::endl;
	}

	cout << "\nAverage Mark: " << determineStudentAvg() << endl;
}
