#include "Task.h"
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
