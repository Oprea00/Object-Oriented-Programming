#pragma once

#include "Event.h"
#include <vector>
#include <algorithm>

using namespace std;

class Repository {

protected:
	vector<Event> events;
	vector<Event> eventsList;
	vector<Event> eventsByMonth;
	int currentEvent = 0;
	string filePath;
	void readFromFile();
	void writeToFile();

public:
	Repository(const string& fileName) {
		this->filePath = fileName; 
		readFromFile(); };

	void addToRepository(const Event& event);

	void updateInRepository(const Event& event);

	void deleteFromRepository(const Event& event);

	vector<Event> getAll();

	Event next();

	virtual void goToEvent();

	virtual void deleteFromList(const Event& event);

	virtual string getListLocation();

	vector<Event> getEventsList();

	vector<Event> filter(const string& month);

	vector<Event> sortChronologically(vector<Event>& events);

	vector<Event> getByParticipants(int participants);

	static bool sortFunction(const Event& event1, const Event& event2);

	static bool compareFunction(const Event& event1, const Event& event2);

	void swapElements(vector<Event>& events, int index1, int index2);
};