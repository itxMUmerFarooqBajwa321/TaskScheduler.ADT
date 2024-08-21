#ifndef TASK_H
#define TASK_H
#include "Date.h"
#include "Time.h"
class Task
{
public:
	Date taskDate;
	Time taskTime;
	String taskMsg;
	Task();
	Task(const Date&, const Time&, const String&);
	void updateDate(const Date&);   //setter
	void updateTime(const Time&);   //setter
	void updateMessage(const String&);   //setter
	Date getDate() const;
	Time getTime() const;
	String getMessage() const;
	void print() const;
	/*	no need of destructor as no heap allocation
	in this class.heap allocation is in String and
	it's responsibility of String class to handle this in destructor.*/
	/*
	No need of copy ctor ,the same reason for it
	that is for not making destructor ie. no heap allocation occurred
	here . it is occurred inString class so it's responsibility of String class
	to handle, not responsibility of Task class.
	*/
};
Task::Task() : taskDate{}, taskTime{}, taskMsg{}
{}
Task::Task(const Date& d, const Time& t, const String& m):  taskDate{d}, taskTime{t}, taskMsg{m}
{
	/*taskDate = d;
	taskTime = t;
	taskMsg.reSize(m.getSize());
	taskMsg.concatEqual(m);*/
}
void Task::updateDate(const Date& nd)
{
	taskDate.setDate(nd);
}
void Task::updateTime(const Time& nt)
{
	taskTime.setTime(nt);
}
void Task::updateMessage(const String& nm)
{
	taskMsg.~String();
	taskMsg.reSize(nm.getLength() + 1);
	//taskMsg.at(0) = '\0';
	taskMsg+=nm;
}
Date Task::getDate() const
{
	return taskDate;
}
Time Task::getTime() const
{
	return taskTime;
}
String Task::getMessage() const
{
	return taskMsg;
}
void Task::print() const
{
	taskMsg.display();
	cout << " at ";
	taskTime.printTwentyFourHourFormat();
	cout << " of ";
	taskDate.printFormat1();
}
#endif
