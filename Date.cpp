#include"Date.h"
const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
Date::Date()
{
	setFactoryVersion();
}
Date::Date(int d, int m, int y) : Date()
{
	if (!isValidDate(d, m, y))
	{
		return;
	}
	setMonth(m);
	setYear(y);
	setDay(d);

}
Date::Date(const Date& ref)
{
	day = ref.day;
	month = ref.month;
	year = ref.year;
}
bool Date::isLeapYear() const
{
	return isLeapYear(year);
}
void Date::setFactoryVersion()
{
	day = 1;
	month = 1;
	year = 1500;
}
String Date::getMonthName() const
{
	String months[12][10] = { "January","Febrary","March","April","May","June","July","August", "September","October","November","December" };
	return months[month - 1][0];
}
bool Date::isValidDate(int d, int m, int y)
{
	if (m > 12 || m <= 0 || y < 1500)
	{
		return false;
	}
	if (m !=2 && d<=daysInMonth[m])
	{
		return true;
	}
	if (m == 2 && isLeapYear(y))
	{
		return (d <= 29) ? true : false;
	}
	return false;
}
 bool Date::isLeapYear(int year)
{
	 if (!(year % 4))
	 {
		 if (!(year % 100))
		 {
			 if (!(year % 400))
			 {
				 return true;
			 }
			 return false;
		 }
		 return true;
	 }
	 return false;
}
void Date::setDate(int d, int m, int y)
{
	if (isValidDate(d,m,y))
	{
		day = d;
		month = m;
		year = y;
	}
}
void Date::setDate(Date d)
{
	setDay(d.day);
	setMonth(d.month);
	setYear(d.year);
}
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
int Date::getDaysInMonth() const
{
	if (month == 2)
	{
		return (isLeapYear()) ? 29 : 28;
	}
	return daysInMonth[month];
}
void Date::setDay(int d)
{
	if (d > getDaysInMonth() || d <= 0)
	{
		return;
	}
	day = d;
}
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
		if (day > getDaysInMonth())
		{
			day = getDaysInMonth();
		}
	}
}
void Date::setYear(int y)
{
	if ((y >= 1500) && (y <= 3000))
	{
		year = y;
		if ((month == 2) && (day == 29))
		{
			day = getDaysInMonth();
		}
	}
}
void Date::incDay(int inc)
{
	int i = 0;
	day = day + inc;
	if (day > getDaysInMonth())
	{
		day = day - inc;
		int i = 0;
		while (i < inc)
		{
			day = day + 1;
			if (day == (getDaysInMonth() + 1))
			{
				day = 1;
				incMonth();
			}
			i++;
		}
	}
}
void Date::incMonth(int inc)
{
	month = month + inc;
	if (month > 12)
	{
		incYear((month - 1) / 12);
		month = ((month) % 12);
		if (!month)
		{
			month = 12;
		}
	}
	if (day > getDaysInMonth())
	{
		day = getDaysInMonth();
	}
}
void Date::incYear(int inc)
{
	year = year + inc;
	if (month == 2 && day == 29)
	{
		day = getDaysInMonth();
	}
}
void Date::decDay(int dec)
{
	day = day - dec;
	if (day <= 0)
	{
		day = day + dec;
		dec = dec - day;
		decMonth(1);    //when day will be last day of previous month
		day = getDaysInMonth();
		while (dec)
		{
			if (dec >= getDaysInMonth())
			{
				dec = dec - day;
				decMonth();
				day = getDaysInMonth();
			}
			else
			{
				day = day - dec;
				dec = 0;
			}
		}
	}
}
void Date::decMonth(int dec)
{
	month = month - dec;
	if (month <= 0)
	{
		month = month + dec;
		dec = dec - month;
		decYear(1);     // when month will be 12 of first previous year.
		month = 12 * ((dec / 12) + 1) - dec;
		decYear(dec / 12);
	}
	if (day > getDaysInMonth())
	{
		day = getDaysInMonth();
	}
}
void Date::decYear(int dec)
{
	setYear(year - dec);
	if (month == 2 && day == 29)
	{
		day = getDaysInMonth();
	}
}
String Date::getDateInFormat1() const
{
	String date{ "00/00/0000" };
	date[0] = (month / 10) + '0';
	date[1] = (month % 10) + '0';
	date[3] = (day / 10) + '0';
	date[4] = (day % 10) + '0';
	date[6] = (year / 1000) + '0';
	date[7] = (year / 100) % 10 + '0';
	date[8] = (year / 10) % 10 + '0';
	date[9] = (year % 10) + '0';
	return date;
}
String Date::getDateInFormat2() const
{
	String date{ "" };
	String monthName = getMonthName();
	date.insert(0, monthName);
	date.insert(date.getLength(), String{ " " });
	String dayString;
	dayString = day;
	date.insert(date.getLength(), dayString);
	date.insert(date.getLength(), String{ " " });
	String yearString;
	yearString = year;
	date.insert(date.getLength(), yearString);
	date.reSize(date.getLength() + 1);
	return date;
}
String Date::getDateInFormat3() const
{
	return String{ "" };
}
void Date::printFormat1() const
{
	getDateInFormat1().display();
}
void Date::printFormat2() const
{
	getDateInFormat2().display();
}
