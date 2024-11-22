#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>

struct Student
{
	int id;
	int age;
	bool sex;
	char name[64];
};

void studentPrint(Student &s);

#endif
