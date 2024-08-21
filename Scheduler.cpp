#include "Scheduler.h"
Scheduler::Scheduler() : taskList(nullptr), noOfTasks(0), capacity(0)
{}
Scheduler::Scheduler(Scheduler && ref)
{
	if (this == &ref)
	{
		return;
	}
	if (! this-> taskList)     // resources will be moved from *this  ie. from calling obj to ref.
	{
		return;
	}
	ref.~Scheduler();
	ref.taskList = taskList;   // for transfer of memory resource ie array.
	ref.noOfTasks = noOfTasks;
	ref.capacity = capacity;
	taskList = nullptr;    // to break the connection of calling obj with that array (i.e. memory resource)
	noOfTasks = capacity = 0; 
}
Scheduler::Scheduler(const Scheduler& ref): Scheduler()
{
	if (this == &ref)
	{
		return;
	}
	if (!ref.taskList)
	{
		exit(0);
	}
	noOfTasks = ref.noOfTasks;
	capacity = ref.capacity;
	taskList = new Task[capacity];
	for (int i = 0; i < noOfTasks; i++)
	{
		taskList[i] = ref.taskList[i];
		/*
		Other one point to remember is that I could do this ie:

		taskList[i]= ref.taskList[i];
		taskList[i].updateMessage(ref.taskList[i].getMessage());

		Means pehly 1st statement sy shallow copy kr leta phir object k jis
		waly part me issue aye ga (yani k String ko) uss ko deep copy kr k handle kr leta .
		But idhr phadda pr jaye ga. Issue ye aye ga k jb hm Task k object ko assignment operator sy
		shallow copy kr lein gy phir calling object k hr Task object k String me ref k
		String ka data member data (pointer to char) as it is ditto copy ho jaye ga.
		phir iss me Aap deep copy krny k liye jb
		taskList[i].updateMessage(ref.taskList[i].getMessage());
		use kro gy to updateMessage() waly function me pehly String ka destructor chaly ga according
		to logic. calling object ki array pr pary hoye sary Srings k data member data me refn k
		sary Strings ka data member data para h yani calling objs k Strings k data ussi character array ko point kr rhy hein jis ko
		ref k sary Strings k data kr ry hein. so destructor chaly sy na sirf this calling obj ki sari char arrays urr jaein gi
		blky ref ki b sari char arrays urr jaein gi. so avoid this logic.
		*/
	}
}
Scheduler Scheduler::operator = (const Scheduler & ref)
{
	if (this == &ref)
	{
		return *this;
	}
	if (!ref.taskList)   //if pointer to array of rvalue obj is nullptr or dangling.
	{
		exit(0);
	}
	this->~Scheduler();
	noOfTasks = ref.noOfTasks;
	capacity = ref.capacity;
	taskList = new Task[capacity];
	for (int i = 0; i < noOfTasks; i++)
	{
		taskList[i] = (ref.taskList)[i];
	}
	return *this;
}
void Scheduler::reSize(int newSize)
{
	if (newSize <= 0)
	{
		this->~Scheduler();
	}
	//Task* temp;
	Task * temp = new Task[newSize];
	int smallerVal = (newSize > capacity) ? capacity : newSize;
	for (int i = 0; i < smallerVal; i++)
	{
		temp[i].updateDate(this->taskList[i].getDate());
		temp[i].updateTime(this->taskList[i].getTime());
		temp[i].updateMessage(this->taskList[i].getMessage());
	}
	this->~Scheduler();
	taskList = temp;
	capacity = newSize;
}
void Scheduler::addTask(const Task& t)
{
	if (noOfTasks == capacity || capacity==0)
	{
		reSize(capacity + 5);
	}
	taskList[noOfTasks].updateDate(t.getDate());
	taskList[noOfTasks].updateTime(t.getTime());
	taskList[noOfTasks].updateMessage(t.getMessage());
	noOfTasks++;
}
void Scheduler::displayTask(const Date& d) const
{
	for (int i = 0; i < noOfTasks; i++)
	{
		if (taskList[i].getDate().getDay() == d.getDay() && taskList[i].getDate().getMonth() == d.getMonth() && taskList[i].getDate().getYear() == d.getYear())
		{
			/* i cannot do this ie. if(taskList[i].getDate() == d) because it (i.e. Date) is not a primitive type
			like int , double, float etc. it is user defined type. so == operator does not know how to compare
			two objects of this type. we'll have to overload == operator for this. if not overloaded, then
			we have to compare its parts/attributes of primitive types i.e. int, float , double, char etc, for which
			== operator is already available.*/
			taskList[i].getMessage().display();
			cout << " at ";
			taskList[i].getTime().printTwentyFourHourFormat();
			cout << '\n';
		}
	}
}
Task Scheduler::operator [](int index) const
{
	if (index >= noOfTasks)
	{
		exit(0);
	}
	return taskList[index];
}
void Scheduler::displayTodaysTasks() const
{
	time_t now = time(0);
	struct tm localTime;
	localtime_s(&localTime, &now);
	displayTask(Date{ localTime.tm_mday , 1 + localTime.tm_mon , 1900 + localTime.tm_year });
}
Scheduler::~Scheduler()
{
	delete[] taskList;
	noOfTasks = 0;
	capacity = 0;
}
