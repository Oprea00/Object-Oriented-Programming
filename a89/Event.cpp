#include "Event.h"
#include <sstream>
#include <vector>

Event::Event() : title(""), description(""), dateAndTime(Date()), numberOfPeople(0), link("") {}

Event::Event(const string& title, const string& description, const Date& dateAndTime, const int& numberOfPeople, const string& link) {
	this->title = title;
	this->description = description;
	this->dateAndTime = dateAndTime;
	this->numberOfPeople = numberOfPeople;
	this->link = link;
}


void Event::addPeople(int newNumberOfPeople)
{
	this->numberOfPeople += newNumberOfPeople;
}

/* Overload the == operator to check if 2 events are equal
*  Input: event - the second event which will be verified with the current one
*  Output: true if events are equal, false otherwise
*/
bool Event::operator==(const Event& event) const {
	return title == event.title; //&& description == event.description && numberOfPeople == event.numberOfPeople && link == event.link;
}

string Event::toString()
{
	string event = "";

	event += this->title;
	event += "-";
	event += this->description;
	event += "-";
	//event += to_string(this->dateAndTime);
	event += "-";
	event += to_string(this->numberOfPeople);
	event += "-";
	event += this->link;

	return event;
}

ostream& operator<<(ostream& outputStream, const Date& date)
{
	outputStream << date.getDay() << "-" <<
		date.getMonth() << "-" <<
		date.getYear() << "-" <<
		date.getHour() << "-" <<
		date.getMinutes();
	return outputStream;
}

ostream& operator<<(ostream& outputStream, const Event& event)
{
	outputStream << event.getTitle() << ", " <<
		event.getDescription() << ", " <<
		event.getDateAndTime() << ", " <<
		event.getNumberOfPeople() << ", " <<
		event.getLink() << "\n";
	return outputStream;
}

istream& operator>>(istream& inputStream, Date& date)
{
	/*	string inputData;
		getline(inputStream, inputData);
		vector<string> splittedLine;
		string tokenAfterSplit;
		stringstream stringStreamSplit(inputData);
		int day, month, year, hour, minutes;
		while (std::getline(stringStreamSplit, tokenAfterSplit, '-'))
			splittedLine.push_back(tokenAfterSplit);
		date.day = stoi(splittedLine[0]);
		date.month = stoi(splittedLine[1]);
		date.year = stoi(splittedLine[2]);
		date.hour = stoi(splittedLine[3]);
		date.minutes = stoi(splittedLine[4]);  */
	return inputStream;
}

istream& operator>>(istream& inputStream, Event& event)
{
	string inputData;
	getline(inputStream, inputData);

	int position = inputData.find(", ");
	string currentToken = inputData.substr(0, position);
	event.setTitle(currentToken);
	inputData.erase(0, position + 2);

	position = inputData.find(", ");
	currentToken = inputData.substr(0, position);
	event.setDescription(currentToken);
	inputData.erase(0, position + 2);

	Date date;
	position = inputData.find("-");
	currentToken = inputData.substr(0, position);
	try {
		date.setDay(stoi(currentToken));
	}
	catch (const std::invalid_argument& ia) {}
	inputData.erase(0, position + 1);

	position = inputData.find("-");
	currentToken = inputData.substr(0, position);
	try {
		date.setMonth(stoi(currentToken));
	}
	catch (const std::invalid_argument& ia) {}
	inputData.erase(0, position + 1);

	position = inputData.find("-");
	currentToken = inputData.substr(0, position);
	try {
		date.setYear(stoi(currentToken));
	}
	catch (const std::invalid_argument& ia) {}
	inputData.erase(0, position + 1);

	position = inputData.find("-");
	currentToken = inputData.substr(0, position);
	try {
		date.setHour(stoi(currentToken));
	}
	catch (const std::invalid_argument& ia) {}
	inputData.erase(0, position + 1);

	position = inputData.find(", ");
	currentToken = inputData.substr(0, position);
	try {
		date.setMinutes(stoi(currentToken));
	}
	catch (const std::invalid_argument& ia) {}
	event.setDate(date);
	inputData.erase(0, position + 2);

	position = inputData.find(", ");
	currentToken = inputData.substr(0, position);
	event.setNumberOfPeople(atoi(currentToken.c_str()));
	inputData.erase(0, position + 2);

	currentToken = inputData.substr(0, inputData.size());
	event.setLink(currentToken);

	return inputStream;
}

string Date::dateToString()
{
	string date = "";
	date += to_string(this->day);
	date += "/";
	date += to_string(this->month);
	date += "/";
	date += to_string(this->year);
	date += " ";
	date += to_string(this->hour);
	date += ":";
	date += to_string(this->minutes);
	return date;
}
