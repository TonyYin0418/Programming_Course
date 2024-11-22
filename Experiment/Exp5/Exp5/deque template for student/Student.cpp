#include "Student.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &out, Student &s)
{
    out << "ID: " << s.id << ", age: " << s.age << ", sex: " << (s.sex ? 'M' : 'F') << endl;
    return out;
}
