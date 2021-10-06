#include "Domain.h"

BMI::BMI(string date, double value) {
	this->date = date;
	this->value = value;
}

BP::BP(string date, int systolicValue, int diastolicValue) {
	this->date = date;
	this->systolicValue = systolicValue;
	this->diastolicValue = diastolicValue;
}

string Measurement::toString() {
	std::string info = "";
	info += this->date;
	return info;
}

string BMI::toString() {
	std::string info = "";
	info += "Date: ";
	info += this->date;
	info += ", ";
	info += "Value: ";
	info += to_string(this->value);
	return info;
}

string BP::toString() {
	std::string info = "";
	info += "Date: ";
	info += this->date;
	info += ", ";
	info += "Values: ";
	info += to_string(this->systolicValue);
	info += ", ";
	info += to_string(this->diastolicValue);
	return info;
}

bool BMI::isNormalValue() {
	if (this->value >= 18.5 && this->value <= 25)
		return true;
	return false;
}

bool BP::isNormalValue() {
	if (this->systolicValue >= 90 && this->systolicValue <= 119 && this->diastolicValue >= 60 && this->diastolicValue <= 79)
		return true;
	return false;
}