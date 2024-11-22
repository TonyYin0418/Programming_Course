#ifndef _STUDENT_H
#define _STUDENT_H

struct Student
{
	int id;
	int age;
	bool sex;
	char name[64];
	Student *next;
};

void studentPrint(Student &s);
int studentHash(Student &s);
bool studentEqual(Student &s1, Student &s2);

#endif
