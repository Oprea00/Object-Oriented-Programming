#include "Controller.h"
#include "Validator.h"

/* Add an event
*  Input: title, description link - strings, numberOfPeople - int  representing the fields of an event
*		  day, month, year, hour, minutes - int  representing the fields of a Date which is a field of an event
*  Output: true if the events was added, false otherwise
*/
void Controller::addEvent(const string& title, const string& description, int day, int month, int year, int hour, int minutes, int numberOfPeople, const string& link) {
	Event event{ title, description, Date{day, month, year, hour, minutes}, numberOfPeople, link };
	Validator::validateEvent(event);
	this->repository.addToRepository(event);
}

/* Update an event
*  Input: title, description link - strings, numberOfPeople - int  representing the fields of an event
*		  day, month, year, hour, minutes - int  representing the fields of a Date which is a field of an event
*  Output: true if the events was updated, false otherwise
*/
void Controller::updateEvent(const string& title, const string& description, int day, int month, int year, int hour, int minutes, int numberOfPeople, const string& link) {
	Event event{ title, description, Date{day, month, year, hour, minutes}, numberOfPeople, link };
	Validator::validateEvent(event);
	this->repository.updateInRepository(event);
}

/* Delete an event
*  Input: title - a string representing the title of the event which will be deleted
*  Output: true if the events was deleted, false otherwise
*/
void Controller::deleteEvent(const string& title) {
	Event event{ title, " ", Date{}, 0, " " };
	Validator::validateEvent(event);
	this->repository.deleteFromRepository(event);
}

/* Get all events
*  Output: a dynamicArray containing all events
*/
vector<Event> Controller::getAllEvents() {
	return this->repository.getAll();
}

vector<Event> Controller::getByParticipants(int participants)
{
	return this->repository.getByParticipants(participants);
}

/* Go to next event
*  Input: -
*  Output: the next event
*/
Event Controller::nextEvent() {
	return this->repository.next();
}

/* Go to an event
*  Input: -
*  Output: -
*/
void Controller::goToEvent() {
	this->repository.goToEvent();
}

/* Delete an event from events list
*  Input: title of the event to be deleted
*  Output: -
*/
void Controller::deleteEventFromList(const string& title) {
	Event event{ title, "", Date{}, 0, "" };
	this->repository.deleteFromList(event);
}

/* Get eventsList
*  Output: a dynamicVector containing the events saved by the user
*/
vector<Event> Controller::seeEventsList() {
	return this->repository.getEventsList();
}

/* Get all events from a specific month
*  Input: month - the given month
*  Output: a dynamicVector containing the events from that month
*/
vector<Event> Controller::filterByMonth(const string& month)
{
	return this->repository.filter(month);
}

void Controller::openFile()
{
	system(this->repository.getListLocation().c_str());
}