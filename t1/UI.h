#pragma once
#include "Controller.h"
#include <iostream>

using namespace std;

class UI {

private:
	Controller& controller;

public:
	UI(Controller& controller) : controller(controller) {};

	void addGeneUI();

	void listGenesSortedUI();

	void listFilteredUI();

	void printMenu();

	void run();
};