#include "Time.h"
Time::Time()
{
	resetFactoryVersion();
}
Time::Time(int h, int m, int s) :Time()
{
	hours = h;
	minutes = m;
	seconds = s;
	if (!validateTime())
	{
		resetFactoryVersion();
	}
}
bool Time::valiadteHours() const
{
	return ((hours >= 0) && (hours < 24));
}
bool Time::validateMinutes() const
{
	return ((minutes >= 0) && (minutes < 60));
}
bool Time::validateSeconds() const
{
	return ((seconds >= 0) && (seconds < 60));
}
bool Time::validateTime() const
{
	return (valiadteHours() && validateMinutes() && validateSeconds());
}
void Time::resetFactoryVersion()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}
int Time::getHours() const
{
	return hours;
}
int Time::getMinutes()const
{
	return minutes;
}
int Time::getSeconds()const
{
	return seconds;
}
void Time::setHours(int h)
{
	if (h >= 0 && h < 24)
	{
		hours = h;
	}
}
void Time::setMinutes(int m)
{
	if (m >= 0 && m < 60)
	{
		minutes = m;
	}
}
void Time::setSeconds(int s)
{
	if (s >= 0 && s < 60)
	{
		seconds = s;
	}
}
void Time::setTime(int h, int m, int s)
{
	if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60))
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
}
void Time::setTime(Time t)
{
	setHours(t.hours);
	setMinutes(t.minutes);
	setSeconds(t.seconds);
}
void Time::incHour(int inc)
{
	setHours((inc + hours) % 24);
}
void Time::incMin(int inc)
{
	incHour((minutes + inc) / 60);
	setMinutes((minutes + inc) % 60);
}
void Time::incSec(int inc )
{
	incMin((seconds + inc) / 60);
	setSeconds((seconds + inc) % 60);
	// due to this % operator value passed to setSeconds() is always <60 i.e. if (seconds>=60) or if(seconds<60), in both case vale passed will be less than 60. so no issue in setting a value of seconds.
}
void Time::decHour(int dec )
{
	int decrementedHours = hours - dec;
	if (decrementedHours < 0)
	{
		hours = 24 + decrementedHours;
		if (hours < 0)
		{
			hours = hours + 24;
		}
		return;
	}
	hours = hours - dec;
}
void Time::decMin(int dec )
{
	int decrementedMin = minutes - dec;
	if (decrementedMin >= 0)
	{
		minutes = minutes - dec;
		return;
	}
	decrementedMin = decrementedMin * (-1);
	int decrementHours = (decrementedMin / 60) + 1;
	if (decrementedMin == 60)
	{
		decrementHours--;
	}
	decHour(decrementHours);
	dec = dec * (-1);
	minutes = 60 + dec + minutes;
	if (minutes < 0)
	{
		minutes = minutes + 60;
	}
}
void Time::decSec(int dec )
{
	int decrementedSec = seconds - dec;
	if (decrementedSec < 0)
	{
		decrementedSec = decrementedSec * (-1);
		int decrementMin = (decrementedSec / 60) + 1;
		if (decrementedSec == 60)
		{
			decrementMin--;
		}
		decMin(decrementMin);
		dec = dec * (-1);
		seconds = 60 + dec + seconds;
		if (seconds < 0)
		{
			seconds = seconds + 60;
		}
	}
	else
	{
		seconds = seconds - dec;
	}
}
void Time::printTwentyFourHourFormat()const
{
	cout << hours << ':' << minutes << ':' << seconds << '\n';
}
void Time::printTwelveHourFormat()const
{
	if (hours == 0)
	{
		cout << "12";
	}
	else
	{
		if (hours == 12)
		{
			cout << hours;
		}
		else
		{
			cout << (hours % 12);
		}
	}
	cout << ':' << minutes << ':' << seconds << ' ';
	if ((hours >= 0) && (hours <= 11))
	{
		cout << "AM";
		return;
	}
	cout << "PM";
}
