#include "Tests.h"
#include <iostream>

void Tests::runTests(){
	testEvent();
	cout << "Event tests passed\n";
	testDynamicVector();
	cout << "Dynamic Vector tests passed\n";
	testRepository();
	cout << "Repository tests passed\n";
	testController();
	cout << "Controller tests passed\n";
}

void Tests::testEvent() {
	testEmptyEvent();
	testGetTitle();
	testGetDescription();
	testGetNumberOfPeople();
	testGetLink();
	testGetDateAndTime();
	testGetDay();
	testGetMonth();
	testGetYear();
	testGetHour();
	testGetMinutes();
	testEqulEvents();
	testSetNumberOfPeople();
}

void Tests::testEmptyEvent() {
	Event event{};
	assert(event.getTitle() == "");
}

void Tests::testGetTitle() {
	Event event{ "Snyder's Cut","a",Date{18,03,2021, 20, 00}, 500, "event.com" };
	assert(event.getTitle() == "Snyder's Cut");
}

void Tests::testGetDescription() {
	Event event{ "Snyder's Cut","WatchParty",Date{18,03,2021, 20, 00}, 500, "event.com" };
	assert(event.getDescription() == "WatchParty");
}

void Tests::testGetNumberOfPeople() {
	Event event{ "Snyder's Cut","WatchParty",Date{18,03,2021, 20, 00}, 500, "event.com" };
	assert(event.getNumberOfPeople() == 500);
}

void Tests::testGetLink() {
	Event event{ "Snyder's Cut","WatchParty",Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	assert(event.getLink() == "incaceva.ro");
}

void Tests::testGetDateAndTime() {
	Event event{ "Snyder's Cut","WatchParty",Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	assert(event.getDateAndTime().getDay() == 18);
}

void Tests::testGetDay(){
	Date dateAndTime{ 18, 03, 2021, 20, 00 };
	assert(dateAndTime.getDay() == 18);
}

void Tests::testGetMonth(){
	Date dateAndTime{ 18, 03, 2021, 20, 00 };
	assert(dateAndTime.getMonth() == 03);
}

void Tests::testGetYear(){
	Date dateAndTime{ 18, 03, 2021, 20, 00 };
	assert(dateAndTime.getYear() == 2021);
}

void Tests::testGetHour(){
	Date dateAndTime{ 18, 03, 2021, 20, 00 };
	assert(dateAndTime.getHour() == 20);
}

void Tests::testGetMinutes(){
	Date dateAndTime{ 18, 03, 2021, 20, 00 };
	assert(dateAndTime.getMinutes() == 00);
}

void Tests::testSetNumberOfPeople() {
	Event event{ "Snyder's Cut","WatchParty",Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	event.addPeople(20);
	assert(event.getNumberOfPeople() == 520);
}

void Tests::testEqulEvents() {
	Event event1{ "a", "a", Date{ 1, 1, 2021, 12, 12}, 100, "link" };
	Event event2{ "a", "a", Date{ 1, 1, 2021, 12, 12}, 100, "link" };
	assert(event1 == event2);
}

// --------------------- Dynamic Vector Part ---------------------------

void Tests::testDynamicVector() {
	testEmptyDynamicVector();
	testAdd();
	testRemove();
	testResize();
	testUpdate();
	testCopyConstructor();
	testEqualOperator();
}

void Tests::testEmptyDynamicVector() {
	DynamicVector<int> dynamicVector{};
	assert(dynamicVector.getSize() == 0);
}

void Tests::testAdd() {
	DynamicVector<int> dynamicVector{};
	dynamicVector.add(10);
	assert(dynamicVector.getSize() == 1);
}

void Tests::testRemove() {
	DynamicVector<int> dynamicVector{};
	dynamicVector.add(10);
	dynamicVector.add(20);
	dynamicVector.remove(0);
	assert(dynamicVector.getSize() == 1);
}

void Tests::testResize() {
	DynamicVector<int> dynamicVector{};
	for (int index = 0; index < 15; index++)
		dynamicVector.add(index);
	assert(dynamicVector.getCapacity() == 20);
}

void Tests::testUpdate() {
	DynamicVector<int> dynamicVector{};
	dynamicVector.add(1);
	dynamicVector.update(0, 100);
	assert(dynamicVector[0] == 100);
}

void Tests::testCopyConstructor() {
	DynamicVector<int> dynamicVector{};
	dynamicVector.add(123);
	DynamicVector<int> dynamicVectorCopy(dynamicVector);
	assert(dynamicVectorCopy[0] == 123);
}

void Tests::testEqualOperator() {
	DynamicVector<int> dynamicVector{};
	DynamicVector<int> dynamicVector2{};
	dynamicVector.add(123);
	dynamicVector2 = dynamicVector;
	assert(dynamicVector2[0] == 123);
}

// --------------------- Repository Part ---------------------------

void Tests::testRepository() {
	testAddToRepository();
	testAddExistingElementToRepository();
	testGetAll();
	testUpdateInRepository();
	testUpdateNonExistentInRepository();
	testDeleteFromRepository();
	testDeleteNonExistentFromRepository();
	testNext();
	testFilterNoMonth();
	testGoToEvent();
	testGoTwiceToEvent();
	testDeleteFromList();
	testChronologically();
}

void Tests::testAddToRepository() {
	Repository repository;
	Event event{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	assert(repository.addToRepository(event) == true);
}

void Tests::testAddExistingElementToRepository() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	Event event2{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	repository.addToRepository(event1);
	assert(repository.addToRepository(event2) == false);
}

void Tests::testGetAll() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	Event event2{ "Justice League", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	repository.addToRepository(event1);
	repository.addToRepository(event2);
	DynamicVector<Event> events = repository.getAll();
	assert(events.getSize() == 2);
}

void Tests::testUpdateInRepository() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	repository.addToRepository(event1);
	Event event2{ "Snyder's Cut", "aaa", Date{18,03,2021, 20, 00}, 500, "link" };
	assert(repository.updateInRepository(event2) == true);
	assert(repository.findEvent(event2) == 0);
}

void Tests::testUpdateNonExistentInRepository() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	Event event2{ "aaa", "aa", Date{18,03,2021, 20, 00}, 500, "link" };
	repository.addToRepository(event1);
	assert(repository.updateInRepository(event2) == false);
}

void Tests::testDeleteFromRepository() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	repository.addToRepository(event1);
	assert(repository.deleteFromRepository(event1) == true);
	assert(repository.findEvent(event1) == -1);
}

void Tests::testDeleteNonExistentFromRepository() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	assert(repository.deleteFromRepository(event1) == false);
}

void Tests::testNext() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "https://www.google.ro/" };
	Event event2{ "Justice League", "WatchParty", Date{18,03,2021, 20, 00}, 500, "https://www.google.ro/" };
	repository.addToRepository(event1);
	repository.addToRepository(event2);
	repository.filter("03");
	repository.next();
	assert(repository.next().getTitle() == event2.getTitle());
}

void Tests::testFilterNoMonth() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "https://www.google.ro/" };
	Event event2{ "Justice League", "WatchParty", Date{18,05,2021, 20, 00}, 500, "https://www.google.ro/" };
	repository.addToRepository(event1);
	repository.addToRepository(event2);
	assert(repository.filter("").getSize() == 2);
}

void Tests::testGoToEvent() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,05,2021, 20, 00}, 500, "https://www.google.ro/" };
	Event event2{ "Justice League", "WatchParty", Date{18,03,2020, 20, 00}, 500, "https://www.google.ro/" };
	repository.addToRepository(event1);
	repository.addToRepository(event2);
	repository.filter("");
	repository.goToEvent();
	assert(repository.getEventsList()[0].getTitle() == event2.getTitle());
	repository.next();
	repository.goToEvent();
	assert(repository.getEventsList()[1].getTitle() == event1.getTitle());
}

void Tests::testGoTwiceToEvent() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "https://www.google.ro/" };
	repository.addToRepository(event1);
	repository.filter("03");
	repository.goToEvent();
	repository.goToEvent();
	assert(repository.getEventsList().getSize() == 1);
}

void Tests::testDeleteFromList() {
	Repository repository;
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "https://www.google.ro/" };
	repository.addToRepository(event1);
	repository.filter("03");
	repository.goToEvent();
	repository.deleteFromList(event1);
	assert(repository.getEventsList().getSize() == 0);
}

void Tests::testChronologically() {
	Repository repository;
	Event event1{ "a1", "a", Date{11, 03, 2021, 20, 30}, 500, "https://www.google.ro/" };
	Event event2{ "a2", "a", Date{11, 02, 2021, 20, 30}, 500, "https://www.google.ro/" };
	Event event3{ "a3", "a", Date{11, 03, 2021, 21, 30}, 500, "https://www.google.ro/" };
	Event event4{ "a4", "a", Date{11, 03, 2021, 20, 37}, 500, "https://www.google.ro/" };
	Event event5{ "a5", "a", Date{11, 05, 2021, 20, 30}, 500, "https://www.google.ro/" };
	Event event6{ "a6", "a", Date{11, 01, 2021, 20, 30}, 500, "https://www.google.ro/" };
	Event event7{ "a7", "a", Date{11, 07, 2021, 20, 30}, 500, "https://www.google.ro/" };
	Event event8{ "a8", "a", Date{19, 11, 2021, 20, 30}, 500, "https://www.google.ro/" };
	Event event9{ "a9", "a", Date{11, 11, 2021, 20, 30}, 500, "https://www.google.ro/" };
	Event event0{ "a0", "a", Date{11, 10, 2021, 20, 30}, 500, "https://www.google.ro/" };
	repository.addToRepository(event1);
	repository.addToRepository(event2);
	repository.addToRepository(event3);
	repository.addToRepository(event4);
	repository.addToRepository(event5);
	repository.addToRepository(event6);
	repository.addToRepository(event7);
	repository.addToRepository(event8);
	repository.addToRepository(event9);
	repository.addToRepository(event0);
	repository.filter("");
	repository.next();
	repository.goToEvent();
	assert(repository.getEventsList()[0].getTitle() == "a1");
}

// --------------------- Controller Part ---------------------------

void Tests::testController() {
	testValidEvent();
	testInvalidEvent();
	testAddEvent();
	testAddExistingEvent();
	testGetAllEvents();
	testUpdateEvent();
	testUpdateNonExistentEvent();
	testDeleteEvent();
	testDeleteNonExistentEvent();
	testNextEvent();
	testSaveEvent();
	testDeleteEventFromList();
}

void Tests::testValidEvent() {
	Repository repository;
	Controller controller{ repository };
	Event event1{ "Snyder's Cut", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	assert(controller.validEvent(event1) == true);
}

void Tests::testInvalidEvent() {
	Repository repository;
	Controller controller{ repository };
	Event event1{ "", "WatchParty", Date{18,03,2021, 20, 00}, 500, "incaceva.ro" };
	assert(controller.validEvent(event1) == false);
}

void Tests::testAddEvent() {
	Repository repository;
	Controller controller{ repository };
	assert(controller.addEvent("Snyder's Cut", "WatchParty", 18, 03, 2021, 20, 00, 500, "incaceva.ro") == true);
}

void Tests::testAddExistingEvent() {
	Repository repository;
	Controller controller{ repository };
	controller.addEvent("Snyder's Cut", "WatchParty", 18, 03, 2021, 20, 00, 500, "incaceva.ro");
	assert(controller.addEvent("Snyder's Cut", "WatchParty", 18, 03, 2021, 20, 00, 500, "incaceva.ro") == false);
}

void Tests::testGetAllEvents() {
	Repository repository;
	Controller controller{ repository };
	controller.addEvent("a", "a", 11, 11, 2021, 11, 11, 100, "aaa");
	controller.addEvent("b", "b", 11, 11, 2021, 11, 11, 100, "bbb");
	DynamicVector<Event> events = controller.getAllEvents();
	assert(events.getSize() == 2);
}

void Tests::testUpdateEvent() {
	Repository repository;
	Controller controller{ repository };
	controller.addEvent("a", "a", 11, 11, 2021, 11, 11, 100, "aaa");
	assert(controller.updateEvent("a", "ab", 11, 11, 2021, 11, 11, 100, "aaa") == true);
}

void Tests::testUpdateNonExistentEvent() {
	Repository repository;
	Controller controller{ repository };
	assert(controller.updateEvent("a", "ab", 11, 11, 2021, 11, 11, 100, "aaa") == false);
}

void Tests::testDeleteEvent() {
	Repository repository;
	Controller controller{ repository };
	controller.addEvent("a", "a", 11, 11, 2021, 11, 11, 100, "aaa");
	assert(controller.deleteEvent("a") == true);
}

void Tests::testDeleteNonExistentEvent() {
	Repository repository;
	Controller controller{ repository };
	controller.addEvent("a", "a", 11, 11, 2021, 11, 11, 100, "aaa");
	assert(controller.deleteEvent("aaa") == false);
}

void Tests::testNextEvent() {
	Repository repository;
	Controller controller{ repository };
	controller.addEvent("a", "a", 11, 11, 2021, 11, 11, 100, "https://untold.com/");
	controller.addEvent("b", "a", 11, 11, 2021, 11, 11, 100, "https://untold.com/");
	DynamicVector<Event> events = controller.filterByMonth("");
	controller.nextEvent();
	assert(controller.nextEvent().getTitle() == "b");
}

void Tests::testSaveEvent() {
	Repository repository;
	Controller controller{ repository };
	controller.addEvent("a", "a", 11, 11, 2021, 11, 11, 100, "https://untold.com/");
	DynamicVector<Event> events = controller.filterByMonth("");
	controller.nextEvent();
	controller.goToEvent();
	assert(controller.seeEventsList().getSize() == 1);
}

void Tests::testDeleteEventFromList() {
	Repository repository;
	Controller controller{ repository };
	controller.addEvent("a", "a", 11, 11, 2021, 11, 11, 100, "https://untold.com/");
	DynamicVector<Event> events = controller.filterByMonth("");
	controller.nextEvent();
	controller.goToEvent();
	controller.deleteEventFromList("a");
	assert(controller.seeEventsList().getSize() == 0);
}