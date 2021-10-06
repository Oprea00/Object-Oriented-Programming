#include "Controller.h"

/* Add an event
*  Input: title, description link - strings, numberOfPeople - int  representing the fields of an event
*		  day, month, year, hour, minutes - int  representing the fields of a Date which is a field of an event
*  Output: true if the events was added, false otherwise
*/
bool Controller::addEvent(const string& title, const string& description, int day, int month, int year, int hour, int minutes, int numberOfPeople, const string& link){
	Event event{ title, description, Date{day, month, year, hour, minutes}, numberOfPeople, link };
	return this->repository.addToRepository(event);
}

/* Update an event
*  Input: title, description link - strings, numberOfPeople - int  representing the fields of an event
*		  day, month, year, hour, minutes - int  representing the fields of a Date which is a field of an event
*  Output: true if the events was updated, false otherwise
*/
bool Controller::updateEvent(const string& title, const string& description, int day, int month, int year, int hour, int minutes, int numberOfPeople, const string& link){
	Event event{ title, description, Date{day, month, year, hour, minutes}, numberOfPeople, link };
	return this->repository.updateInRepository(event);
}

/* Delete an event
*  Input: title - a string representing the title of the event which will be deleted
*  Output: true if the events was deleted, false otherwise
*/
bool Controller::deleteEvent(const string& title){
	Event event{ title, "", Date{}, 0, "" };
	return this->repository.deleteFromRepository(event);
}

/* Get all events 
*  Output: a dynamicArray containing all events
*/
DynamicVector<Event> Controller::getAllEvents(){
	return this->repository.getAll();
}

/* Validate an event
*  Input: event - the event to be validated
*  Output: true if the events does not contain empty strings or negative numbers, false otherwise
*/
bool Controller::validEvent(Event event) {
	if (event.getTitle() == "" || event.getDescription() == "" || event.getNumberOfPeople() < 0 || event.getLink() == "")
		return false;
	return true;
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
void Controller::deleteEventFromList(const string& title){
	Event event{ title, "", Date{}, 0, "" };
	this->repository.deleteFromList(event);
}

/* Get eventsList
*  Output: a dynamicVector containing the events saved by the user
*/
DynamicVector<Event> Controller::seeEventsList() {
	return this->repository.getEventsList();
}

/* Get all events from a specific month 
*  Input: month - the given month
*  Output: a dynamicVector containing the events from that month
*/
DynamicVector<Event> Controller::filterByMonth(const string& month)
{
	return this->repository.filter(month);
}
