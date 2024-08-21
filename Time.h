#ifndef TIME_H
#define TIME_H
#include<iostream>
using namespace std;
class Time
{
private:
	int hours;
	int minutes;
	int seconds;
	bool valiadteHours() const;
	bool validateMinutes() const;
	bool validateSeconds() const;
	bool validateTime() const;
	void resetFactoryVersion();	
public:
	Time();
	Time(int h, int m, int s);
	int getHours() const;
	int getMinutes()const;
	int getSeconds()const;
	void setHours(int h);
	void setMinutes(int m);
	void setSeconds(int s);
	void setTime(int h, int m, int s);
	void setTime(Time t);
	void incHour(int inc = 1);
	void incMin(int inc = 1);
	void incSec(int inc = 1);
	void decHour(int dec = 1);
	void decMin(int dec = 1);
	void decSec(int dec = 1);
	void printTwentyFourHourFormat()const;
	void printTwelveHourFormat()const;
};
#endif
