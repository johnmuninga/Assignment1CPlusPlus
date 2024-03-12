#pragma once
#ifndef Student_hpp
#define Student_hpp
#include<string>

using namespace std;

class Student 
{

protected:
	int studentNumber;
	char name[30];
	char surname[30];

public:
	Student();
	void setStudent(int, char[], char[]);
	void displayStudent();
};

#endif // !Student_hpp

