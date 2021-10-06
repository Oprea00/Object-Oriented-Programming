#pragma once

#include "Event.h"
#include "DynamicVector.h"

using namespace std;

class Repository {

private:
	DynamicVector<Event> events;
	DynamicVector<Event> eventsList;
	DynamicVector<Event> eventsByMonth;
	int currentEvent = 0;

public:
	Repository() {};

	bool addToRepository(const Event& event);

	bool updateInRepository(const Event& event);

	bool deleteFromRepository(const Event& event);

	DynamicVector<Event> getAll();

	int findEvent(const Event& event);

	Event next();

	void goToEvent();

	int searchEventInList(const Event& event);

	void deleteFromList(const Event& event);

	DynamicVector<Event> getEventsList();

	DynamicVector<Event> filter(const string& month);

	DynamicVector<Event> sortChronologically(DynamicVector<Event> &events);

	void swapElements(DynamicVector<Event>& events, int index1, int index2);
};
