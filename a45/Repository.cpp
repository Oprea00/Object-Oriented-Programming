#include "Repository.h"
#include <iostream>
#include <sstream>
#include <windows.h>
#include <shellapi.h>

/* Add an event in repository
*  Input: event - the event to be added
*  Output: true if event was added, false if event already exists
*/
bool Repository::addToRepository(const Event& event) {
	int eventPosition = this->findEvent(event);
	if (eventPosition != -1)
		return false;
	this->events.add(event);
	return true;
}

/* Update an event in repository
*  Input: event - the event to be updated
*  Output: true if event was updated, false if the event does not exist in repository
*/
bool Repository::updateInRepository(const Event& event) {
	int eventPosition = this->findEvent(event);
	if (eventPosition == -1)
		return false;
	this->events.update(eventPosition, event);
	return true;
}

/* Delete an event from repository
*  Input: event - the event to be deleted
*  Output: true if event was deleted, false if the event does not exist in repository
*/
bool Repository::deleteFromRepository(const Event& event) {
	int eventPosition = this->findEvent(event);
	if (eventPosition == -1)
		return false;
	this->events.remove(eventPosition);
	return true;
}

/* Get all events from repository
*  Output: a dynamicArray containing all events
*/
DynamicVector<Event> Repository::getAll()
{
	return this->events;
}

/* Find an event in repository
*  Input: event - the event 
*  Output: the position of the event, -1 if the event does not exist in repository
*/
int Repository::findEvent(const Event& event) {
	int position = -1;
	for (int index = 0; index < events.getSize(); index++) 
		if (this->events[index].getTitle() == event.getTitle()) {
			position = index;
			break;
		}
	return position;
}

/* Goes to the next event in the repository for a specific month
*  Input: -
*  Output: the next event
*/
Event Repository::next() {
	Event nextEvent = this->eventsByMonth[currentEvent];
	this->currentEvent++;
	if (this->currentEvent == this->eventsByMonth.getSize())
		currentEvent = 0;
//	string op = string("start ").append(nextEvent.getLink());
//	system(op.c_str());
	return nextEvent;
}

/* Saves an event in the user's eventList
*  Input: -
*  Output: - , just add the event(by the cureent event index) in the list
*/
void Repository::goToEvent(){
	int currentIndex = this->currentEvent;
	if (currentIndex != 0)
		currentIndex--;
	else 
		currentIndex = this->eventsByMonth.getSize() - 1;
	
	int indexInList = searchEventInList(this->eventsByMonth[currentIndex]);
	if (indexInList == -1) {
		this->eventsByMonth[currentIndex].addPeople(1);
		int position = this->findEvent(this->eventsByMonth[currentIndex]);
		this->events[position].addPeople(1);
		this->eventsList.add(this->eventsByMonth[currentIndex]);
	}
}

/* Search if an event is present in the user's list
*  Input: the event to be searched
*  Output: the position of the event, -1 if the event does not exist in the list
*/
int Repository::searchEventInList(const Event& event){
	int position = -1;
	for (int index = 0; index < eventsList.getSize(); index++)
		if (this->eventsList[index].getTitle() == event.getTitle()) {
			position = index;
			break;
		}
	return position;
}

/* Delete an event from the user's list
*  Input: the event to be deleted
*  Output: -
*/
void Repository::deleteFromList(const Event& event){
	int eventPosition = this->searchEventInList(event);
	if (eventPosition != -1)
		this->eventsList.remove(eventPosition);
	// decrease number of participants also
	int position = this->findEvent(event);
	this->events[position].addPeople(-1);
}

/* Get all events from user's list
*  Output: a dynamicVector containing all events
*/
DynamicVector<Event> Repository::getEventsList() {
	return this->eventsList;
}

/* Filter the events from the repository by a given month and add them in the eventByMonth vector sorted chronologically
*  Input: the given month
*  Output: the filteredEvents dynamicVector
*/
DynamicVector<Event> Repository::filter(const string& month)
{
	DynamicVector<Event> filteredEvents;
	if (month == "") {
		for (int index = 0; index < events.getSize(); index++)
			filteredEvents.add(this->events[index]);
	}
	else {
		int theMonth = 0;
		stringstream intMonth(month);
		intMonth >> theMonth;
		
		for (int index = 0; index < events.getSize(); index++) {
			Date date = this->events[index].getDateAndTime();
			if(date.getMonth() == theMonth)
				filteredEvents.add(this->events[index]);
		}
	}
	//DynamicVector<Event> sortedEvents = 
	this->eventsByMonth = filteredEvents;

	//string op = string("start ").append(filteredEvents[0].getLink());
	//system(op.c_str());

	return this->sortChronologically(filteredEvents);
}

/* Sort chronologically events from a dynamicVector
*  Input: events - the dynamicVector to be sorted
*  Output: the sorted dynamicVector
*/
DynamicVector<Event> Repository::sortChronologically(DynamicVector<Event>& events){
	Event event1;
	Event event2;
	Date date1;
	Date date2;
	int index1, index2;
	for (index1 = 0; index1 < events.getSize() - 1; index1++) {
		for (index2 = index1 + 1; index2 < events.getSize(); index2++) {
			event1 = events[index1];
			event2 = events[index2];
			date1 = event1.getDateAndTime();
			date2 = event2.getDateAndTime();
			if (date1.getYear() > date2.getYear())
				this->swapElements(events, index1, index2);	
			else if(date1.getYear() >= date2.getYear() && date1.getMonth() > date2.getMonth())
				this->swapElements(events, index1, index2);
			else if(date1.getYear() >= date2.getYear() && date1.getMonth() >= date2.getMonth() && date1.getDay() > date2.getDay())
				this->swapElements(events, index1, index2);
			else if(date1.getYear() >= date2.getYear() && date1.getMonth() >= date2.getMonth() && date1.getDay() >= date2.getDay() && date1.getHour() > date2.getHour())
				this->swapElements(events, index1, index2);
			else if (date1.getYear() >= date2.getYear() && date1.getMonth() >= date2.getMonth() && date1.getDay() >= date2.getDay() && date1.getHour() >= date2.getHour() && date1.getMinutes() > date2.getMinutes())
				this->swapElements(events, index1, index2);
		}
	}
	// open the first event in the browser
	string op = string("start ").append(events[0].getLink());
	system(op.c_str());
	return events;
}

/* Swap 2 elements at given indexes in a dynamicVector 
*  Input: events - the dynamicVector , index1, index2 - the given indexes
*  Output: - , elements from indexes swapped accordingly
*/
void Repository::swapElements(DynamicVector<Event>& events, int index1, int index2){
	Event auxEvent = events[index1];
	events[index1] = events[index2];
	events[index2] = auxEvent;
}