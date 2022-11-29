#ifndef _DATE_
#define _DATE_
#include <string>
#include <iostream>
#include <time.h>
#include <ctime>
#include <cmath>
#include <sstream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(const int & = -1, const int & = -1, const int & = -1);
	Date(const Date &);
	~Date();

	friend istream &operator>>(istream &, Date &);
	friend ostream &operator<<(ostream &, const Date &);
	const Date &operator=(const Date &);
	bool operator==(const Date &);

	int Get_day();
	int Get_month();
	int Get_year();
	void Set_day(int);
	void Set_month(int);
	void Set_year(int);

	bool IsLeapYear();
	bool IsValidDate();
	static int DayInMonth(const int &, const int &);
	void PreviousDay(int &, int &, int &);
	int countDay(Date);
	bool operator<(Date);
	int operator-(Date);
	void getToDay();
	string toString()
	{
		stringstream res;
		res << this->day << "/" << this->month << "/" << this->year;
		return res.str();
	}
	string toString1()
	{
		stringstream res;
		res << this->day << "_" << this->month << "_" << this->year;
		return res.str();
	}
	int daysBetweenDates(Date date2)
	{
		string str1, str2;
		str1 = this->toString();
		str2 = date2.toString();

		stringstream ss(str1 + "/" + str2);
		int year, month, day;
		char hyphen;
		
		ss >> day >> hyphen >> month >> hyphen >> year;
		struct tm starttm = {0, 0, 0, day,
							 month - 1, year - 1900};
		time_t start = mktime(&starttm);

		ss >> hyphen >> day >> hyphen >> month >> hyphen >> year;
		struct tm endtm = {0, 0, 0, day,
						   month - 1, year - 1900};
		time_t end = mktime(&endtm);

		return abs(end - start) / 86400;
	}
};
#endif
