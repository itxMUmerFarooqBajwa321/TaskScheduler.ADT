#ifndef DATE_H
#define DATE_H
#include "String.h"
class Date
{
	int day;
	int month;
	int year;
	static const int daysInMonth[13];
	bool isLeapYear() const;
	int getDaysInMonth() const;
	void setFactoryVersion();
	String getMonthName() const;
	static bool isValidDate(int d, int m, int y);
	static bool isLeapYear(int y);
public:
	Date();
	Date(int, int, int);
	Date(const Date& ref);
	void setDate(int d, int m, int y);
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	void setDate(Date d);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	void incDay(int inc = 1);
	void incMonth(int inc = 1);
	void incYear(int inc = 1);
	void decDay(int dec = 1);
	void decMonth(int dec = 1);
	void decYear(int dec = 1);
	String getDateInFormat1() const;
	String getDateInFormat2() const;
	String getDateInFormat3() const;
	void printFormat1() const;
	void printFormat2() const;
};
#endif
