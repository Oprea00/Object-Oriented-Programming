#include "UI.h"
#include <iostream>
#include "Exceptions.h"
#include <iomanip>

void UI::addUI()
{
	string type, date;
	double value;
	int sysValue, diasValue;
	cout << "Enter the date: ";
	cin.ignore();
	getline(cin, date);
	if (date.length() != 10)
		throw ValidationException("Date not valid");

	cout << "Enter the type: ";
	getline(cin, type);
	
	if (type == "BMI") {
		cout << "Enter the value: ";
		cin >> value;
		BMI* bmi = new BMI(date, value);

		this->person.addMeasurement(bmi);
		if (bmi->isNormalValue())
			cout << "Normal Values" << endl;
		else
			cout << "NOT Normal Values" << endl;
	}
	else if (type == "BP") {
		cout << "Enter the systolic: ";
		cin >> sysValue;
		cout << "Enter the diastolic: ";
		cin >> diasValue;

		BP* bp = new BP(date, sysValue, diasValue);

		this->person.addMeasurement(bp);

		if (bp->isNormalValue())
			cout << "Normal Values" << endl;
		else
			cout << "NOT Normal Values" << endl;
	}
	else throw ValidationException("Not a valid Type");

	}

	

void UI::listAllUI()
{
	cout << person.getName() << endl;

	for (auto m : person.getAllMeasurements()) {
		cout << m->toString() << endl;
	}
		
}

void UI::printMenu()
{
	cout << "\n0. Exit";
	cout << "\n1. Add";
	cout << "\n2. List\n";
}

void UI::run()
{
	//string name;
	//cout << "Enter the name: ";
	//cin.ignore();
	//getline(cin, name);

	int option = 1;
	while (option != 0)
	{
		printMenu();
		cin >> option;
		try {
			switch (option) {
			case 1:
				addUI();
				break;
			case 2:
				listAllUI();
				break;
			case 3:
				//listFilteredUI();
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
}
