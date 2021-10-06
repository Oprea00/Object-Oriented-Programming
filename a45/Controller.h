#pragma once

#include "Repository.h"

using namespace std;

class Controller {

private:
	Repository& repository;

public:
	Controller(Repository& repository): repository(repository) {};

	bool addEvent(const string& title, const string& description, int day, int month, int year, int hour, int minutes, int numberOfPeople, const string& link);

	bool updateEvent(const string& title, const string& description, int day, int month, int year, int hour, int minutes, int numberOfPeople, const string& link);

	bool deleteEvent(const string& title);

	DynamicVector<Event> getAllEvents();

	bool validEvent(Event event);

	Event nextEvent();

	void goToEvent();

	void deleteEventFromList(const string& title);

	DynamicVector<Event> seeEventsList();

	DynamicVector<Event> filterByMonth(const string& month);

};