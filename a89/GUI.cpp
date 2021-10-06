#include "GUI.h"
#include "Exceptions.h"

GUI::GUI(Controller& c) : controller{ c }
{
	this->initGUI();
	this->getAllEvents();
	this->connectSignals();
}

void GUI::initGUI()
{
	this->eventsList = new QListWidget{};
	this->usersEventsList = new QListWidget{};
	this->filteredEvents = new QListWidget{};

	this->titleLineEdit = new QLineEdit{};
	this->descriptionLineEdit = new QLineEdit{};

	this->dateLineEdit = new QLineEdit{};
	this->dayLineEdit = new QLineEdit{};
	this->monthLineEdit = new QLineEdit{};
	this->yearLineEdit = new QLineEdit{};
	this->hourLineEdit = new QLineEdit{};
	this->minutesLineEdit = new QLineEdit{};

	this->participantsLineEdit = new QLineEdit{};
	this->linkLineEdit = new QLineEdit{};
	this->filterParticipantsLineEdit = new QLineEdit{};
	this->filterMonthLineEdit = new QLineEdit{};
	this->nextEventLineEdit = new QLineEdit{};

	this->addButton = new QPushButton{ "Add" };
	this->updateButton = new QPushButton{ "Update" };
	this->removeButton = new QPushButton{ "Delete" };
	this->nextButton = new QPushButton{ "Next" };
	this->goToEventButton = new QPushButton{ "Go to event" };
	this->filterButton = new QPushButton{ "Filter" };
	this->deleteFromListButton = new QPushButton{ "Delete from saved list" };
	this->openFileButton = new QPushButton{ "Open file" };

	QHBoxLayout* mainLayout = new QHBoxLayout{ this };
	QVBoxLayout* adminLayout = new QVBoxLayout{};
	QVBoxLayout* middleLayout = new QVBoxLayout{};
	QVBoxLayout* userLayout = new QVBoxLayout{};

	QLabel* adminLabel = new QLabel();
	adminLabel->setText("Events");
	QFont adminFont("Helvetica", 12);
	adminLabel->setFont(adminFont);
	adminLayout->addWidget(adminLabel);

	QLabel* filterLabel = new QLabel();
	filterLabel->setText("Filtered events");
	QFont filterFont("Helvetica", 12);
	filterLabel->setFont(filterFont);
	middleLayout->addWidget(filterLabel);

	QLabel* userLabel = new QLabel();
	userLabel->setText("Saved events");
	QFont userFont("Helvetica", 12);
	userLabel->setFont(userFont);
	userLayout->addWidget(userLabel);

	adminLayout->addWidget(this->eventsList);
	middleLayout->addWidget(this->filteredEvents);
	userLayout->addWidget(this->usersEventsList);
	

	QVBoxLayout* leftSide = new QVBoxLayout{};
	QVBoxLayout* rightSide = new QVBoxLayout{};

	adminLayout->addLayout(leftSide);
	userLayout->addLayout(rightSide);

	QGridLayout* adminButtonsLayout = new QGridLayout{};
	QGridLayout* userButtonsLayout = new QGridLayout{};
	QGridLayout* nextEventLayout = new QGridLayout{};

	adminButtonsLayout->addWidget(this->addButton, 0, 0);
	adminButtonsLayout->addWidget(this->updateButton, 0, 1);
	adminButtonsLayout->addWidget(this->removeButton, 0, 2);
	nextEventLayout->addWidget(this->nextEventLineEdit, 0, 0);
	nextEventLayout->addWidget(this->nextButton, 0, 1);
	userButtonsLayout->addWidget(this->goToEventButton);
	userButtonsLayout->addWidget(this->deleteFromListButton);
	userButtonsLayout->addWidget(this->openFileButton);
	
	QFormLayout* eventDetailsLayout = new QFormLayout{};
	QFormLayout* filterDetailsLayout = new QFormLayout{};

	eventDetailsLayout->addRow("Event Title", this->titleLineEdit);
	eventDetailsLayout->addRow("Description", this->descriptionLineEdit);
	eventDetailsLayout->addRow("Date", this->dateLineEdit);
	eventDetailsLayout->addRow("Day", this->dayLineEdit);
	eventDetailsLayout->addRow("Month", this->monthLineEdit);
	eventDetailsLayout->addRow("Year", this->yearLineEdit);
	eventDetailsLayout->addRow("Hour", this->hourLineEdit);
	eventDetailsLayout->addRow("Minutes", this->minutesLineEdit);
	eventDetailsLayout->addRow("Participants", this->participantsLineEdit);
	eventDetailsLayout->addRow("Link", this->linkLineEdit);

	filterDetailsLayout->addRow("Participants", this->filterParticipantsLineEdit);
	filterDetailsLayout->addRow("Month", this->filterMonthLineEdit);

	leftSide->addLayout(eventDetailsLayout);
	leftSide->addLayout(adminButtonsLayout);
	middleLayout->addLayout(filterDetailsLayout);
	middleLayout->addWidget(this->filterButton);
	rightSide->addLayout(nextEventLayout);
	rightSide->addLayout(userButtonsLayout);

	mainLayout->addLayout(adminLayout);
	mainLayout->addLayout(middleLayout);
	mainLayout->addLayout(userLayout);
}

void GUI::getAllEvents()
{
	this->eventsList->clear();
	vector<Event> allEvents = this->controller.getAllEvents();
	for (Event& event : allEvents) {
		this->eventsList->addItem(QString::fromStdString(event.toString()));
	}
}

void GUI::connectSignals()
{
	QObject::connect(this->eventsList, &QListWidget::itemSelectionChanged, [this]() {
		int selectedElement = this->getSelectedIndex();

		if (selectedElement < 0)
			return;

		Event event = this->controller.getAllEvents()[selectedElement];
		Date date = event.getDateAndTime();
		this->titleLineEdit->setText(QString::fromStdString(event.getTitle()));
		this->descriptionLineEdit->setText(QString::fromStdString(event.getDescription()));
		this->dateLineEdit->setText(QString::fromStdString(event.getDateAndTimeString()));
		this->dayLineEdit->setText(QString::number(date.getDay()));
		this->monthLineEdit->setText(QString::number(date.getMonth()));
		this->yearLineEdit->setText(QString::number(date.getYear()));
		this->hourLineEdit->setText(QString::number(date.getHour()));
		this->minutesLineEdit->setText(QString::number(date.getMinutes()));
		this->participantsLineEdit->setText(QString::number(event.getNumberOfPeople()));
		this->linkLineEdit->setText(QString::fromStdString(event.getLink()));
		});

	QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addEvent);
	QObject::connect(this->removeButton, &QPushButton::clicked, this, &GUI::deleteEvent);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateEvent);
	QObject::connect(this->filterButton, &QPushButton::clicked, this, &GUI::filterEvents);
	QObject::connect(this->openFileButton, &QPushButton::clicked, this, &GUI::openFile);
}

int GUI::getSelectedIndex()
{
	QModelIndexList selectedIndexes = this->eventsList->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0) {
		this->titleLineEdit->clear();
		this->descriptionLineEdit->clear();
		this->dateLineEdit->clear();
		this->dayLineEdit->clear();
		this->monthLineEdit->clear();
		this->yearLineEdit->clear();
		this->hourLineEdit->clear();
		this->minutesLineEdit->clear();
		this->participantsLineEdit->clear();
		this->linkLineEdit->clear();
		return -1;
	}
	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void GUI::addEvent()
{
	string title = this->titleLineEdit->text().toStdString();
	string description = this->descriptionLineEdit->text().toStdString();
	//string date = this->dateLineEdit->text().toStdString();
	int day = this->dayLineEdit->text().toInt();
	int month = this->monthLineEdit->text().toInt();
	int year = this->yearLineEdit->text().toInt();
	int hour = this->hourLineEdit->text().toInt();
	int minutes = this->minutesLineEdit->text().toInt();
	int participants = this->participantsLineEdit->text().toInt();
	string link = this->linkLineEdit->text().toStdString();

	try {
		controller.addEvent(title, description, day, month, year, hour, minutes, participants, link);
		// repopulate the list after add
		this->getAllEvents();
		int lastElement = this->controller.getAllEvents().size() - 1;
		this->eventsList->setCurrentRow(lastElement);
	}
	catch (ValidationException& exception) {
		QMessageBox::critical(this, "Validation Error", exception.what());
	}
	catch (RepositoryException& exception) {
		QMessageBox::critical(this, "Duplicate Error", exception.what());
	}
}

void GUI::deleteEvent()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0) {
		QMessageBox::critical(this, "Error", "No item was selected");
		return;
	}
		
	Event event = this->controller.getAllEvents()[selectedIndex];
	this->controller.deleteEvent(event.getTitle());
	// repopulate the list after delete
	this->getAllEvents();
}

void GUI::updateEvent()
{
	string title = this->titleLineEdit->text().toStdString();
	string description = this->descriptionLineEdit->text().toStdString();
	//string date = this->dateLineEdit->text().toStdString();
	int day = this->dayLineEdit->text().toInt();
	int month = this->monthLineEdit->text().toInt();
	int year = this->yearLineEdit->text().toInt();
	int hour = this->hourLineEdit->text().toInt();
	int minutes = this->minutesLineEdit->text().toInt();
	int participants = this->participantsLineEdit->text().toInt();
	string link = this->linkLineEdit->text().toStdString();

	try {
		this->controller.updateEvent(title, description, day, month, year, hour, minutes, participants, link);
		// repopulate the list after update
		this->getAllEvents();
		int lastElement = this->controller.getAllEvents().size() - 1;
		this->eventsList->setCurrentRow(lastElement);
	}
	catch (ValidationException& exception) {
		QMessageBox::critical(this, "Validation Error", exception.what());
	}
	catch (RepositoryException& exception) {
		QMessageBox::critical(this, "Inexistent Event Error", exception.what());
	}
}

void GUI::filterEvents()
{
	if (this->filterParticipantsLineEdit->text().isEmpty() && this->filterMonthLineEdit->text().isEmpty()) {
		QMessageBox::critical(this, "Error", "No filter criteria entered");
		return;
	}
	// filter by month
	if (this->filterParticipantsLineEdit->text().isEmpty()) {
		string month = this->filterMonthLineEdit->text().toStdString();
		this->filteredEvents->clear();
		vector<Event> filteredEvents = this->controller.filterByMonth(month);
		for (Event& event : filteredEvents) {
			this->filteredEvents->addItem(QString::fromStdString(event.toString()));
		}
		return;
	}
	// filter by participants
	int participants = this->filterParticipantsLineEdit->text().toInt();
	this->filteredEvents->clear();
	vector<Event> filteredEvents = this->controller.getByParticipants(participants);
	for (Event& event : filteredEvents) {
		this->filteredEvents->addItem(QString::fromStdString(event.toString()));
	}
}

void GUI::openFile()
{
	this->controller.openFile();
}
