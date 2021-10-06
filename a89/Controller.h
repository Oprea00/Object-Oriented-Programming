#pragma once
#include "Repository.h"
#include "HtmlRepository.h"
#include "CsvRepository.h"

using namespace std;

class Controller {

private:
	Repository& repository;

public:
	Controller(Repository& repository) : repository(repository) {};

	void addEvent(const string& title, const string& description, int day, int month, int year, int hour, int minutes, int numberOfPeople, const string& link);

	void updateEvent(const string& title, const string& description, int day, int month, int year, int hour, int minutes, int numberOfPeople, const string& link);

	void deleteEvent(const string& title);

	vector<Event> getAllEvents();

	vector<Event> getByParticipants(int partcipants);

	Event nextEvent();

	void goToEvent();

	void deleteEventFromList(const string& title);

	vector<Event> seeEventsList();

	vector<Event> filterByMonth(const string& month);

	void openFile();

};