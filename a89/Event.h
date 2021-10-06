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
	string dateToString();
	//setters
	void setDay(const int& day) { this->day = day; };
	void setMonth(const int& month) { this->month = month; };
	void setYear(const int& year) { this->year = year; };
	void setHour(const int& hour) { this->hour = hour; };
	void setMinutes(const int& minutes) { this->minutes = minutes; };

	friend istream& operator>>(istream& inputStream, Date& date);
	friend ostream& operator<<(ostream& outputStream, const Date& date);
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
	string getDateAndTimeString() { return dateAndTime.dateToString(); }
	//setters
	void setTitle(const string& title) { this->title = title; };
	void setDescription(const string& description) { this->description = description; };
	void setDate(const Date& date) { this->dateAndTime = date; };
	void setNumberOfPeople(const int& numberOfPeople) { this->numberOfPeople = numberOfPeople; };
	void setLink(const string& link) { this->link = link; };

	void addPeople(int newNumberOfPeople);

	bool operator==(const Event& event) const;

	string toString();

	friend istream& operator>>(istream& inputStream, Event& event);
	friend ostream& operator<<(ostream& outputStream, const Event& event);
};