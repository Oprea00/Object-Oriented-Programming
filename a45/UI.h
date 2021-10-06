#pragma once

#include "Controller.h"
#include <iostream>

using namespace std;

class UI {

private:
	Controller& controller;

public:
	UI(Controller& controller) : controller(controller) {};

	void addEventUI();

	void updateEventUI();

	void deletEventUI();

	void listEventsUI();

	void listEventsListsUI();

	void nextUI();

	void goToEventUI();
	
	void deleteFromListUI();

	void filterEventsUI();

	void printMenu();

	void printUserMenu();

	void run();
};