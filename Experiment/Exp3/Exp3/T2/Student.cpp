#include "Student.h"
#include <iostream>
using namespace std;

void studentPrint(Student &s)
{
	cout << s.id;
}

int studentHash(Student &s)
{
	return s.id;
}

bool studentEqual(Student &s1, Student &s2)
{
	return s1.id == s2.id;
}
