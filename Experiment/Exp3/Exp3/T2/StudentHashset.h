#include "Student.h"

#ifndef _STUDENT_HASHSET_H
#define _STUDENT_HASHSET_H

class StudentHashset
{
public:
	StudentHashset();
	~StudentHashset();
	void insert(Student *);
	void remove(Student &);
	Student *find(Student &);
	void showInfo(bool);

private:
	Student **rootArr;	//根数组
	int rootCapacity;	//根数组容量
	int totalCount;		//整个容器中容纳的学生元素个数
	void expandRoot();

	const int INITIAL_ROOT_CAPACITY = 16;
};

#endif
