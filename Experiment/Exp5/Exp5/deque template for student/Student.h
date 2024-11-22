#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
using namespace std;

struct Student
{
	int id;
	int age;
	bool sex;
	char name[64];
};

ostream &operator<<(ostream &out, Student &s);

#endif
