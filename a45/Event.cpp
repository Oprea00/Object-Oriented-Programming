#include "Event.h"

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
	return title == event.title && description == event.description && numberOfPeople == event.numberOfPeople && link == event.link;
}