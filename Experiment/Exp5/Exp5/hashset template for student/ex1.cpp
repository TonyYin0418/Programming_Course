#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Student.h"
#include "Teacher.h"
#include "Hashset.h"
using namespace std;

#define LARGE_AMOUNT

#ifdef LARGE_AMOUNT
#define LOOP_COUNT 40000
#else
#define LOOP_COUNT 40
#endif

int main()
{
	cout << "Student Section:" << endl;
	{
		clock_t startTime, endTime;
		startTime = clock();
		Hashset<Student, StudentHash, StudentEqual> shs;
		int idForLaterOperation;
		for (int i = 0, lastId = 0; i < LOOP_COUNT; i++)
		{
			Student *s = new Student;
			s->id = lastId + 1 + (rand() & 0xF);
			lastId = s->id;
			s->age = 20;
			s->sex = (s->id & 1) ? true : false;
			shs.insert(s);
			if (i == LOOP_COUNT >> 1)
				idForLaterOperation = s->id;
		}
		endTime = clock();

#ifndef LARGE_AMOUNT
		shs.showInfo(true);
#else
		shs.showInfo(false);
#endif

		Student *stu = new Student;
		stu->id = idForLaterOperation;
		cout << "Time cost: " << endTime - startTime << endl;
		Student *s = shs.find(*stu);
		cout << "Find by ID: " << idForLaterOperation << ", age: " << s->age << ", sex: " << (s->sex ? 'M' : 'F') << endl;
		shs.remove(*stu);
		cout << "After removing by ID: " << idForLaterOperation << endl;
		shs.showInfo(false);
	}
	//---------------------------------------------
	cout << "\n\nTeacher Section:" << endl;
	//---------------------------------------------
	{
		clock_t startTime, endTime;
		startTime = clock();
		Hashset<Teacher, TeacherHash, TeacherEqual> shs;
		int idForLaterOperation;
		for (int i = 0, lastId = 0; i < LOOP_COUNT; i++)
		{
			Teacher *s = new Teacher;
			s->id = lastId + 1 + (rand() & 0xF);
			lastId = s->id;
			s->age = 20;
			s->sex = (s->id & 1) ? true : false;
			shs.insert(s);
			if (i == LOOP_COUNT >> 1)
				idForLaterOperation = s->id;
		}
		endTime = clock();

#ifndef LARGE_AMOUNT
		shs.showInfo(true);
#else
		shs.showInfo(false);
#endif

		Teacher *stu = new Teacher;
		stu->id = idForLaterOperation;
		cout << "Time cost: " << endTime - startTime << endl;
		Teacher *s = shs.find(*stu);
		cout << "Find by ID: " << idForLaterOperation << ", age: " << s->age << ", sex: " << (s->sex ? 'M' : 'F') << endl;
		shs.remove(*stu);
		cout << "After removing by ID: " << idForLaterOperation << endl;
		shs.showInfo(false);
	}
	return 0;
}
