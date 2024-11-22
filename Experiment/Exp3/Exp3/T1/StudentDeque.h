#include "Student.h"

#ifndef _STUDENT_DEQUE_H
#define _STUDENT_DEQUE_H

class StudentDeque
{
public:
	StudentDeque();
	~StudentDeque();
	void pushFront(Student *);
	void pushBack(Student *);
	Student *popFront();
	Student *popBack();
	void showInfo(bool);

private:
	Student **rootArr;
	int rootCapacity;
	int rootFrontIndex;
	int rootBackIndex;
	void expandRoot();

	int indexOfFrontArr;
	int indexOfBackArr;
	void addFrontArr();
	void removeFrontArr();
	void addBackArr();
	void removeBackArr();

	const int ARR_SIZE = 16;
};

#endif
