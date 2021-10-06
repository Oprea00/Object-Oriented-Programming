#pragma once
#include "Person.h"

class UI {

private:
	Person& person;

public:
	UI(Person& p) : person(p) {};

	void addUI();

	void listAllUI();

	void printMenu();

	void run();
};