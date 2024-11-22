#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Student.h"
#include "StudentDeque.h"
using namespace std;

//#define LARGE_AMOUNT

#ifdef LARGE_AMOUNT
#define LOOP_COUNT 40000
#else
#define LOOP_COUNT 40
#endif

int main()
{
//    srand(998244353);
	clock_t startTime, endTime;
	startTime = clock();
	StudentDeque sdq;
	for (int i = 0, lastId = 0; i < LOOP_COUNT; i++)
	{
		Student *s = new Student;
		s->id = lastId + 1 + (rand() & 0xF);	//rand() & 0xF 得到0-15之间的随机数，即后一学生的ID比前一学生的ID增加量为1-16之间的随机数
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
	return 0;
}
