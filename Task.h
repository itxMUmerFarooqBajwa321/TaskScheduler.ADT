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
#endif
