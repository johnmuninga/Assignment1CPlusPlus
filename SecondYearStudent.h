#pragma once
#ifndef SecondYearStudent_hpp
#define SecondYearStudent_hpp
#include"Student.h"
#include<string>
using namespace std;

class SecondYearStudent: Student
{
private:
	string code[4];
	double assignment[4];
	double test[4];
	double predicate[4];
	double exam[4];
	double final[4];
	int testWeight;
	int assignmentWeight;
	void calcPredicate();
	double determineStudentAvg();

public:
	SecondYearStudent();
	void setStudent(int, char[], char[], string[], double[], double[]);
	void calcFinalMark();
	void displayStudent();

};
#endif // !SecondYearStudent_hpp
