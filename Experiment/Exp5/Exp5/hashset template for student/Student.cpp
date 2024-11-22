#include "Student.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &out, Student &s)
{
	out << s.id;
	return out;
}

int StudentHash::operator()(Student &s)
{
	return s.id;
}

bool StudentEqual::operator()(Student &s1, Student &s2)
{
	return s1.id == s2.id;
}
