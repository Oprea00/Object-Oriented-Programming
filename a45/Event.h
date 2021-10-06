#pragma once

#include <string>

using namespace std;

class Date {

private:
	int day;
	int month;
	int year;
	int hour;
	int minutes;

public:
	//constructors
	Date() : day(1), month(1), year(2021), hour(00), minutes(00) {}
	Date(int day, int monnth, int year, int hour, int minutes) : day(day), month(monnth), year(year), hour(hour), minutes(minutes) {}
	//getters
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	int getHour() const { return hour; }
	int getMinutes() const { return minutes; }
};

class Event {

private:
	string title;
	string description;
	Date dateAndTime;
	int numberOfPeople;
	string link;

public:
	//constructors
	Event();
	Event(const string& title, const string& description, const Date& dateAndTime, const int& numberOfPeople, const string& link);
	//getters
	string getTitle() const { return title; }
	string getDescription() const { return description; }
	Date getDateAndTime() const { return dateAndTime; }
	int getNumberOfPeople() const { return numberOfPeople; }
	string getLink() const { return link; }

	void addPeople(int newNumberOfPeople);

	bool operator==(const Event& event) const;
};