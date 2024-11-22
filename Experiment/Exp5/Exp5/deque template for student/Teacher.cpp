#include "Teacher.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &out, Teacher &s)
{
    out << "ID: " << s.id << ", age: " << s.age << ", sex: " << (s.sex ? 'M' : 'F') << endl;
    return out;
}
