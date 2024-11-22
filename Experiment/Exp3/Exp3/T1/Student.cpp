#include "Student.h"
#include <iostream>

using namespace std;

void studentPrint(Student &s)
{
    cout << "ID: " << s.id << ", age: " << s.age << ", sex: " << (s.sex ? 'M' : 'F') << endl;
}
