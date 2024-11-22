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

class TeacherHash
{
public:
	int operator()(Teacher &s);
};

class TeacherEqual
{
public:
	bool operator()(Teacher &s1, Teacher &s2);
};

#endif
