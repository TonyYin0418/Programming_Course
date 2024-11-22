#ifndef _TEACHER_H
#define _TEACHER_H

#include <iostream>
using namespace std;

struct Teacher
{
	int id;
	int age;
	bool sex;
	char name[64];
};

ostream &operator<<(ostream &out, Teacher &s);

#endif
