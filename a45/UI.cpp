#include "UI.h";

void UI::addEventUI() {
	string title, description, link;
	int day, month, year, hour, minutes, numberOfPeople;
	cout << "Enter the title: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter the description: ";
	getline(cin, description);
	cout << "Enter the day: ";
	cin >> day;
	cout << "Enter the month: ";
	cin >> month;
	cout << "Enter the year: ";
	cin >> year;
	cout << "Enter the hour: ";
	cin >> hour;
	cout << "Enter the minutes: ";
	cin >> minutes;
	cout << "Enter the number of people: ";
	cin >> numberOfPeople;
	cout << "Enter the link: ";
	cin.ignore();
	getline(cin, link);

	Event event{ title, description, Date{day, month, year, hour, minutes}, numberOfPeople, link };
	if (this->controller.validEvent(event) == false) {
		cout << "Invalid event\n";
		return;
	}

	bool result = this->controller.addEvent(title, description, day, month, year, hour, minutes, numberOfPeople, link);
	if (result)
		cout << "Event added\n";
	else
		cout << "Event already exists\n";
}

void UI::updateEventUI() {
	string title, description, link;
	int day, month, year, hour, minutes, numberOfPeople;
	cout << "Enter the title: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter the description: ";
	getline(cin, description);
	cout << "Enter the day: ";
	cin >> day;
	cout << "Enter the month: ";
	cin >> month;
	cout << "Enter the year: ";
	cin >> year;
	cout << "Enter the hour: ";
	cin >> hour;
	cout << "Enter the minutes: ";
	cin >> minutes;
	cout << "Enter the number of people: ";
	cin >> numberOfPeople;
	cout << "Enter the link: ";
	cin.ignore();
	getline(cin, link);

	Event event{ title, description, Date{day, month, year, hour, minutes}, numberOfPeople, link };
	if (this->controller.validEvent(event) == false) {
		cout << "Invalid event\n";
		return;
	}

	bool result = this->controller.updateEvent(title, description, day, month, year, hour, minutes, numberOfPeople, link);
	if (result)
		cout << "Event updated\n";
	else
		cout << "Event with that title does not exist. Can't update\n";
}

void UI::deletEventUI() {
	string title;
	cout << "Enter the title: ";
	cin.ignore();
	getline(cin, title);

	bool result = this->controller.deleteEvent(title);
	if (result)
		cout << "Event deleted\n";
	else
		cout << "Event with that title does not exist. Can't delete\n";
}

void UI::listEventsUI() {
	DynamicVector<Event> events = this->controller.getAllEvents();
	for (int index = 0; index < events.getSize(); index++) {
		Event event = events[index];
		Date dateAndTime = event.getDateAndTime();
		cout << "Title: " << event.getTitle() + " "
			<< "Description: " << event.getDescription() + " "
			<< "Date: " << to_string(dateAndTime.getDay()) + "-" << to_string(dateAndTime.getMonth()) + "-" << to_string(dateAndTime.getYear()) + " "
			<< "Hour: " << to_string(dateAndTime.getHour()) + "-" << to_string(dateAndTime.getMinutes()) + " "
			<< "Participants: " << to_string(event.getNumberOfPeople()) + " "
			<< "Link: " << event.getLink() << "\n";
	}
}

void UI::nextUI() {
	Event event = this->controller.nextEvent();
	Date dateAndTime = event.getDateAndTime();
	cout << "Title: " << event.getTitle() + " "
		<< "Description: " << event.getDescription() + " "
		<< "Date: " << to_string(dateAndTime.getDay()) + "-" << to_string(dateAndTime.getMonth()) + "-" << to_string(dateAndTime.getYear()) + " "
		<< "Hour: " << to_string(dateAndTime.getHour()) + "-" << to_string(dateAndTime.getMinutes()) + " "
		<< "Participants: " << to_string(event.getNumberOfPeople()) + " "
		<< "Link: " << event.getLink() << "\n";
}

void UI::goToEventUI() {
	this->controller.goToEvent();
}

void UI::deleteFromListUI(){
	string title;
	cout << "Enter the title: ";
	cin.ignore();
	getline(cin, title);

	this->controller.deleteEventFromList(title);
}

void UI::listEventsListsUI() {
	DynamicVector<Event> events = this->controller.seeEventsList();
	cout << "\nYou have " << events.getSize() << " events in your list.\n";
	for (int index = 0; index < events.getSize(); index++) {
		Event event = events[index];
		Date dateAndTime = event.getDateAndTime();
		cout << "Title: " << event.getTitle() + " "
			<< "Description: " << event.getDescription() + " "
			<< "Date: " << to_string(dateAndTime.getDay()) + "-" << to_string(dateAndTime.getMonth()) + "-" << to_string(dateAndTime.getYear()) + " "
			<< "Hour: " << to_string(dateAndTime.getHour()) + "-" << to_string(dateAndTime.getMinutes()) + " "
			<< "Participants: " << to_string(event.getNumberOfPeople()) + " "
			<< "Link: " << event.getLink() << "\n";
	}
}

void UI::filterEventsUI() {
	string month;
	cout << "Enter the month: ";
	cin.ignore();
	getline(cin, month);

	DynamicVector<Event> events = this->controller.filterByMonth(month);
	for (int index = 0; index < events.getSize(); index++) {
		Event event = events[index];
		Date dateAndTime = event.getDateAndTime();
		cout << "Title: " << event.getTitle() + " "
			<< "Description: " << event.getDescription() + " "
			<< "Date: " << to_string(dateAndTime.getDay()) + "-" << to_string(dateAndTime.getMonth()) + "-" << to_string(dateAndTime.getYear()) + " "
			<< "Hour: " << to_string(dateAndTime.getHour()) + "-" << to_string(dateAndTime.getMinutes()) + " "
			<< "Participants: " << to_string(event.getNumberOfPeople()) + " "
			<< "Link: " << event.getLink() << "\n";
	}
}

void UI::printMenu() {
	cout << "\n0. Exit";
	cout << "\n1. Add event";
	cout << "\n2. Update event";
	cout << "\n3. Delete event";
	cout << "\n4. List events";
	cout << "\n5. Change mode\n";
}

void UI::printUserMenu() {
	cout << "\n0. Exit";
	cout << "\n1. Filter by month";
	cout << "\n2. Next";
	cout << "\n3. Go to event";
	cout << "\n4. Delete event from list";
	cout << "\n5. List events list";
	cout << "\n6. Change mode\n";
}

void UI::run() {
	int option = 1;
	int mode = 0;
	cout << "\nChoose a mode\n1. Administrator\n2. User\n";
	cin >> mode;

	while (option != 0)
	{
		if (mode == 1) {
			printMenu();
			cin >> option;
			switch (option) {
			case 1:
				addEventUI();
				break;
			case 2:
				updateEventUI();
				break;
			case 3:
				deletEventUI();
				break;
			case 4:
				listEventsUI();
				break;
			case 5:
				mode = 2;
				break;
			case 0:
				break;
			default:
				cout << "Not a valid option\n";
				break;
			}
		}
		else {
			printUserMenu();
			cin >> option;
			switch (option) {
			case 1:
				filterEventsUI();
				break;
			case 2:
				nextUI();
				break;
			case 3:
				goToEventUI();
				break;
			case 4:
				deleteFromListUI();
				break;
			case 5:
				listEventsListsUI();
				break;
			case 6:
				mode = 1;
			case 0:
				break;
			default:
				cout << "Not a valid option\n";
				break;
			}
		}
	}
}