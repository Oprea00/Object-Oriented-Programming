#pragma once
#include <string>

using namespace std;

class Measurement {
protected:
	string date;

public:
	virtual bool isNormalValue() = 0;
	virtual string toString();
};

class BMI : public Measurement {
private: 
	double value;

public:
	BMI(string date, double value);
	bool isNormalValue();
	string toString() override;
};

class BP : public Measurement {
private:
	int systolicValue;
	int diastolicValue;

public:
	BP(string date, int systolicValue, int diastolicValue);
	bool isNormalValue();
	string toString() override;
};