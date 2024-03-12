#include"Student.h"
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

Student::Student() 
{
	studentNumber = 0;
	strcpy_s(name, "");
	strcpy_s(surname, "");	
}

void Student::setStudent(int studentNumber, char name[], char surname[])
{
	this->studentNumber = studentNumber;
	strcpy_s(this->name, name);
	strcpy_s(this->surname, surname);
}



void Student::displayStudent()
{
	cout <<  studentNumber << "\t";
	cout <<  name << "\t";
	cout <<  surname << endl;
}