#include "Person.h"

Person::Person(string name) {
	this->name = name;
}

void Person::addMeasurement(Measurement* m)
{
	this->measurements.push_back(m);
}

vector<Measurement*> Person::getAllMeasurements()
{
	return this->measurements;
}
