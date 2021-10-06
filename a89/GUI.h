#pragma once
#include <qwidget.h>
#include "Controller.h"
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qformlayout.h>
#include <qlabel.h>
#include <qmessagebox.h>

class GUI : public QWidget
{
private:
	Controller& controller;

	//graphical elements
	QListWidget* eventsList, * usersEventsList, * filteredEvents;
	QLineEdit* titleLineEdit, * descriptionLineEdit, * dateLineEdit, * participantsLineEdit, * linkLineEdit, * filterParticipantsLineEdit, * filterMonthLineEdit, * nextEventLineEdit;
	QLineEdit* dayLineEdit, * monthLineEdit, * yearLineEdit, * hourLineEdit, * minutesLineEdit;
	QPushButton* addButton, * updateButton, * removeButton, * nextButton, * goToEventButton, * filterButton, * deleteFromListButton, * openFileButton;

public:
	GUI(Controller& c);

private:
	void initGUI();
	void getAllEvents();
	void connectSignals();
	int getSelectedIndex();

	void addEvent();
	void deleteEvent();
	void updateEvent();
	void filterEvents();
	void openFile();
};

