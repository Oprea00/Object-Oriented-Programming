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

	this->controller.addEvent(title, description, day, month, year, hour, minutes, numberOfPeople, link);
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

	this->controller.updateEvent(title, description, day, month, year, hour, minutes, numberOfPeople, link);
}

void UI::deletEventUI() {
	string title;
	cout << "Enter the title: ";
	cin.ignore();
	getline(cin, title);

	this->controller.deleteEvent(title);
}

void UI::listEventsUI() {
	vector<Event> events = this->controller.getAllEvents();
	for (auto event : events) {
		cout << event;
	}
}

void UI::listByParticipants(){
	int partcicipants;
	cout << "Enter the participants: ";
	cin.ignore();
	cin >> partcicipants;
	vector<Event> events = this->controller.getByParticipants(partcicipants);
	for (auto event : events) {
		cout << event.getDescription() << "\n";
	}
}

void UI::nextUI() {
	Event event = this->controller.nextEvent();
	cout << event;
}

void UI::goToEventUI() {
	this->controller.goToEvent();
}

void UI::deleteFromListUI() {
	string title;
	cout << "Enter the title: ";
	cin.ignore();
	getline(cin, title);

	this->controller.deleteEventFromList(title);
}

void UI::listEventsListsUI() {
	vector<Event> events = this->controller.seeEventsList();
	cout << "\nYou have " << events.size() << " events in your list.\n";
	for (auto event : events) {
		cout << event;
	}
}

void UI::filterEventsUI() {
	string month;
	cout << "Enter the month: ";
	cin.ignore();
	getline(cin, month);

	vector<Event> events = this->controller.filterByMonth(month);
	for (auto event : events) {
		cout << event;
	}
}

void UI::openFileUI()
{
	this->controller.openFile();
}

void UI::printMenu() {
	cout << "\n0. Exit";
	cout << "\n1. Add event";
	cout << "\n2. Update event";
	cout << "\n3. Delete event";
	cout << "\n4. List events";
	cout << "\n5. Change mode";
	cout << "\n6. Filter by participants\n";
}

void UI::printUserMenu() {
	cout << "\n0. Exit";
	cout << "\n1. Filter by month";
	cout << "\n2. Next";
	cout << "\n3. Go to event";
	cout << "\n4. Delete event from list";
	cout << "\n5. List events list";
	cout << "\n6. Open events list file";
	cout << "\n7. Change mode\n";
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
			try {
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
				case 6:
					listByParticipants();
					break;
				case 0:
					break;
				default:
					cout << "Not a valid option\n";
					break;
				}
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << '\n';
			}
		}
		else {
			printUserMenu();
			cin >> option;
			try {
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
					openFileUI();
					break;
				case 7:
					mode = 1;
				case 0:
					break;
				default:
					cout << "Not a valid option\n";
					break;
				}
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << '\n';
			}
		}
	}
}