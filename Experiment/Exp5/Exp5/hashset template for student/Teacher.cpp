#include "Teacher.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &out, Teacher &s)
{
	out << s.id;
	return out;
}

int TeacherHash::operator()(Teacher &s)
{
	return s.id;
}

bool TeacherEqual::operator()(Teacher &s1, Teacher &s2)
{
	return s1.id == s2.id;
}
