#include "Repository.h"
#include <iostream>
#include <sstream>
#include <windows.h>
#include <shellapi.h>
#include "Exceptions.h"
#include <fstream>

void Repository::readFromFile()
{
	if (this->filePath == "")
		return;
	Event event;
	ifstream fin(this->filePath);
	while (fin >> event) {
		this->events.push_back(event);
	}
	fin.close();
}

void Repository::writeToFile()
{
	if (this->filePath == "")
		return;
	ofstream fout(this->filePath);
	for (auto event : this->events) {
		fout << event;
	}
	fout.close();
}

/* Add an event in repository
*  Input: event - the event to be added
*  Output: true if event was added, false if event already exists
*/
void Repository::addToRepository(const Event& event) {
	if (find(events.begin(), events.end(), event) != events.end())
		throw RepositoryException(string("event already exists"));
	this->events.push_back(event);
	writeToFile();
}

/* Update an event in repository
*  Input: event - the event to be updated
*  Output: true if event was updated, false if the event does not exist in repository
*/
void Repository::updateInRepository(const Event& event) {
	auto eventIterator = find(this->events.begin(), this->events.end(), event);
	if (eventIterator != this->events.end())
		this->events.at(eventIterator - this->events.begin()) = event;
	else throw RepositoryException(string("event doesn't exists"));
	writeToFile();
}

/* Delete an event from repository
*  Input: event - the event to be deleted
*  Output: true if event was deleted, false if the event does not exist in repository
*/
void Repository::deleteFromRepository(const Event& event) {
	auto eventIterator = find(this->events.begin(), this->events.end(), event);
	if (eventIterator != this->events.end())
		this->events.erase(eventIterator);
	else throw RepositoryException(string("event doesn't exists"));
	writeToFile();
}

/* Get all events from repository
*  Output: a dynamicArray containing all events
*/
vector<Event> Repository::getAll()
{
	return this->events;
}

/* Goes to the next event in the repository for a specific month
*  Input: -
*  Output: the next event
*/
Event Repository::next() {
	Event nextEvent = this->eventsByMonth[currentEvent];
	this->currentEvent++;
	if (this->currentEvent == this->eventsByMonth.size())
		currentEvent = 0;
	return nextEvent;
}

/* Saves an event in the user's eventList
*  Input: -
*  Output: - , just add the event(by the cureent event index) in the list
*/
void Repository::goToEvent() {
	int currentIndex = this->currentEvent;
	if (currentIndex != 0)
		currentIndex--;
	else
		currentIndex = this->eventsByMonth.size() - 1;

	auto eventIterator = find(this->eventsList.begin(), this->eventsList.end(), this->eventsByMonth[currentIndex]);
	if (eventIterator == this->eventsList.end()) {
		this->eventsByMonth[currentIndex].addPeople(1);
		auto eventIterator = find(this->events.begin(), this->events.end(), this->eventsByMonth[currentIndex]);
		this->events.at(eventIterator - this->events.begin()).addPeople(1);
		this->eventsList.push_back(this->eventsByMonth[currentIndex]);
	}
	else throw RepositoryException(string("event already exist in your list"));
}

/* Delete an event from the user's list
*  Input: the event to be deleted
*  Output: -
*/
void Repository::deleteFromList(const Event& event) {
	auto eventIterator = find(this->eventsList.begin(), this->eventsList.end(), event);
	if (eventIterator != this->eventsList.end())
		this->eventsList.erase(eventIterator);
	else throw RepositoryException(string("event doesn't exist in your list"));
	// decrease number of participants also
	//int position = this->findEvent(event);
	//this->events[position].addPeople(-1);
	auto eventIt = find(this->events.begin(), this->events.end(), event);
	this->events.at(eventIt - this->events.begin()).addPeople(-1);
}

string Repository::getListLocation()
{
	return "";
}

/* Get all events from user's list
*  Output: a dynamicVector containing all events
*/
vector<Event> Repository::getEventsList() {
	return this->eventsList;
}

/* Filter the events from the repository by a given month and add them in the eventByMonth vector sorted chronologically
*  Input: the given month
*  Output: the filteredEvents dynamicVector
*/
vector<Event> Repository::filter(const string& month)
{
	vector<Event> filteredEvents;
	if (month == "") {
		for (auto event : this->events)
			filteredEvents.push_back(event);
	}
	else {
		int theMonth = 0;
		stringstream intMonth(month);
		intMonth >> theMonth;

		for (auto event : this->events) {
			Date date = event.getDateAndTime();
			if (date.getMonth() == theMonth)
				filteredEvents.push_back(event);
		}
	}
	vector<Event> sortedEvents = this->sortChronologically(filteredEvents);
	this->eventsByMonth = sortedEvents;

	return sortedEvents;
}

vector<Event> Repository::getByParticipants(int participants)
{
	vector<Event> filteredByParticipants;
	copy_if(events.begin(), events.end(), back_inserter(filteredByParticipants), [participants](const Event& event) {return event.getNumberOfPeople() > participants; });
	sort(filteredByParticipants.begin(), filteredByParticipants.end(), &Repository::sortFunction);
	filteredByParticipants.erase(unique(filteredByParticipants.begin(), filteredByParticipants.end(), &Repository::compareFunction), filteredByParticipants.end());
	return filteredByParticipants;
}

bool Repository::sortFunction(const Event& event1, const Event& event2)
{
	return (event1.getDescription() > event2.getDescription());
}

bool Repository::compareFunction(const Event& event1, const Event& event2)
{
	return (event1.getDescription() == event2.getDescription());
}

/* Sort chronologically events from a dynamicVector
*  Input: events - the dynamicVector to be sorted
*  Output: the sorted dynamicVector
*/
vector<Event> Repository::sortChronologically(vector<Event>& events) {
	//sort(events.begin(), events.end(), sortFunction());
	
	Event event1;
	Event event2;
	Date date1;
	Date date2;
	int index1, index2;
	for (index1 = 0; index1 < events.size() - 1; index1++) {
		for (index2 = index1 + 1; index2 < events.size(); index2++) {
			event1 = events[index1];
			event2 = events[index2];
			date1 = event1.getDateAndTime();
			date2 = event2.getDateAndTime();
			if (date1.getYear() > date2.getYear())
				this->swapElements(events, index1, index2);
			else if (date1.getYear() >= date2.getYear() && date1.getMonth() > date2.getMonth())
				this->swapElements(events, index1, index2);
			else if (date1.getYear() >= date2.getYear() && date1.getMonth() >= date2.getMonth() && date1.getDay() > date2.getDay())
				this->swapElements(events, index1, index2);
			else if (date1.getYear() >= date2.getYear() && date1.getMonth() >= date2.getMonth() && date1.getDay() >= date2.getDay() && date1.getHour() > date2.getHour())
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
void Repository::swapElements(vector<Event>& events, int index1, int index2) {
	Event auxEvent = events[index1];
	events[index1] = events[index2];
	events[index2] = auxEvent;
}