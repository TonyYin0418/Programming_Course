#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Student.h"
#include "StudentHashset.h"
using namespace std;

//#define LARGE_AMOUNT

#ifdef LARGE_AMOUNT
#define LOOP_COUNT 40000
#else
#define LOOP_COUNT 40
#endif

int main()
{
	clock_t startTime, endTime;
	startTime = clock();
	StudentHashset shs;
	int idForLaterOperation;
	for (int i = 0, lastId = 0; i < LOOP_COUNT; i++)
	{
		Student *s = new Student;
		s->id = lastId + 1 + (rand() & 0xF);	//rand() & 0xF 得到0-15之间的随机数，即后一学生的ID比前一学生的ID增加量为1-16之间的随机数
		lastId = s->id;
		s->age = 20;
		s->sex = (s->id & 1) ? true : false;
		shs.insert(s);
		if (i == LOOP_COUNT >> 1)	//LOOP_COUNT >> 1 得到总循环次数的一半，即循环执行到某一轮，把这一轮的学生ID记下来，用于后续测试操作
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
	return 0;
}
