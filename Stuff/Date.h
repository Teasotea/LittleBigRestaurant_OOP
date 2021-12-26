#pragma once
class Date
{
private:

	int day;
	int month;
	int year;

public:

	Date();

	Date(int day, int month, int year);

	void setDay(int day);

	int getDay() const;

	void setMonth(int month);

	int getMonth() const;

	void setYear(int year);

	int getYear() const;

	~Date();
};



