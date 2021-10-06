#pragma once

#include "Event.h"
#include "DynamicVector.h"
#include "Repository.h"
#include "Controller.h"
#include <assert.h>

using namespace std;

class Tests {

private:
	// tests for Event
	static void testEvent();
	static void testEmptyEvent();
	static void testGetTitle();
	static void testGetDescription();
	static void testGetNumberOfPeople();
	static void testGetLink();
	static void testGetDateAndTime();
	static void testGetDay();
	static void testGetMonth();
	static void testGetYear();
	static void testGetHour();
	static void testGetMinutes();
	static void testEqulEvents();
	static void testSetNumberOfPeople();
	// tests for Dynamic Vector
	static void testDynamicVector();
	static void testEmptyDynamicVector();
	static void testAdd();
	static void testRemove();
	static void testResize();
	static void testUpdate();
	static void testCopyConstructor();
	static void testEqualOperator();
	// tests for Repository
	static void testRepository();
	static void testAddToRepository();
	static void testAddExistingElementToRepository();
	static void testGetAll();
	static void testUpdateInRepository();
	static void testUpdateNonExistentInRepository();
	static void testDeleteFromRepository();
	static void testDeleteNonExistentFromRepository();
	static void testNext();
	static void testFilterNoMonth();
	static void testGoToEvent();
	static void testGoTwiceToEvent();
	static void testDeleteFromList();
	static void testChronologically();
	// tests for Controller
	static void testController();
	static void testValidEvent();
	static void testInvalidEvent();
	static void testAddEvent();
	static void testAddExistingEvent();
	static void testGetAllEvents();
	static void testUpdateEvent();
	static void testUpdateNonExistentEvent();
	static void testDeleteEvent();
	static void testDeleteNonExistentEvent();
	static void testNextEvent();
	static void testSaveEvent();
	static void testDeleteEventFromList();

public:
	static void runTests();
};