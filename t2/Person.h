#pragma once
#include "Domain.h"
#include <vector>

class Person {
private:
	string name;
	vector<Measurement*> measurements;

public:
	Person(string name);
	void addMeasurement(Measurement* m);
	vector<Measurement*> getAllMeasurements();
	vector<Measurement*> getMeasurementsByMonth(int month);
	bool isHealthy(int month);
	vector<Measurement*> getMeasurementsNewerThan(string date);
	void writeToFile(string fileName, string date);
	string getName() { return this->name; };
};