#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Student.h"
#include "Teacher.h"
#include "Deque.h"
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
		Deque<Student> sdq;
		for (int i = 0, lastId = 0; i < LOOP_COUNT; i++)
		{
			Student *s = new Student;
			s->id = lastId + 1 + (rand() & 0xF);
			lastId = s->id;
			s->age = 20;
			s->sex = (s->id & 1) ? true : false;
			if (s->sex)
				sdq.pushFront(s);
			else
				sdq.pushBack(s);
			delete s;
		}
		endTime = clock();

#ifndef LARGE_AMOUNT
		sdq.showInfo(true);
#else
		sdq.showInfo(false);
#endif

		cout << "Time cost: " << endTime - startTime << endl;

		cout << "Pop Front: " << sdq.popFront()->id << endl;
		cout << "Pop Back: " << sdq.popBack()->id << endl;
	}
	//---------------------------------------------
	cout << "\n\nTeacher Section:" << endl;
	//---------------------------------------------
	{
		clock_t startTime, endTime;
		startTime = clock();
		Deque<Teacher> sdq;
		for (int i = 0, lastId = 0; i < LOOP_COUNT; i++)
		{
			Teacher *s = new Teacher;
			s->id = lastId + 1 + (rand() & 0xF);
			lastId = s->id;
			s->age = 20;
			s->sex = (s->id & 1) ? true : false;
			if (s->sex)
				sdq.pushFront(s);
			else
				sdq.pushBack(s);
			delete s;
		}
		endTime = clock();

#ifndef LARGE_AMOUNT
		sdq.showInfo(true);
#else
		sdq.showInfo(false);
#endif

		cout << "Time cost: " << endTime - startTime << endl;

		cout << "Pop Front: " << sdq.popFront()->id << endl;
		cout << "Pop Back: " << sdq.popBack()->id << endl;
	}
	return 0;
}
