#ifndef SCHEDULER_H
#define SCHEDULER_H
#include"Task.h"
#include <ctime>
class Scheduler
{
public:
	Task* taskList;
	int noOfTasks;
	int capacity;
	Scheduler();
	//Scheduler(int = 0);
	Scheduler(const Scheduler&);
	Scheduler(Scheduler&&);
	Scheduler operator = (const Scheduler&);
	void reSize(int newSize);
	void addTask(const Task&);
	Task operator [](int index) const;
	//void removeTask(const Task&);
	//int getNoOfTasks() const;
	//int getCapacity() const;
	void displayTask(const Date& d = Date{ 1,1,1500 }) const;
	void displayTodaysTasks()const;
	~Scheduler();
};
#endif
