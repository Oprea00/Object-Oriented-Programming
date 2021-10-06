#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class Beverage {
private:
	string description;

public:
	Beverage(string description) : description(description) {};
	virtual double price() = 0;
	virtual void print() {
		cout << description << "-" << price() << "RON";
	}
	virtual ~Beverage() {};
};

class Coffe : public Beverage {
public:
	Coffe() : Beverage("Coffe") {};

	double price() override {
		return 2.5;
	}
};

class Tea : public Beverage {
public:
	Tea() : Beverage("Tea") {};

	double price() override {
		return 1.5;
	}
};

class BeverageWithMilk : public Beverage {
private:
	int milkCount;
	Beverage* beverage;

public:
	BeverageWithMilk(Beverage* beverage, int milkCount) : Beverage{ "Beverage with milk" }, beverage(beverage), milkCount(milkCount) {};

	double price() {
		return beverage->price() + milkCount * 0.5;
	}

	void print() {
		beverage->print();
		cout << ", milk: " << milkCount;
		cout << " -> " << price() << " RON";
	}
};

class BeverageMachine {
public:
	void prepare(const string beverageType, int milkCount) {
		Beverage* beverage = NULL;
		if (beverageType == "Tea") {
			beverage = new Tea{};
		}
		else if (beverageType == "Coffe") {
			beverage = new Coffe{};
		}
		if (milkCount > 0) {
			if (beverage != NULL)
				beverage = new BeverageWithMilk{ beverage, milkCount };
		}
		if (beverage != NULL) {
			beverage->print();
			cout << endl;
		}
		delete beverage;
	}
};

/*
int main() {
	BeverageMachine machine{};
	machine.prepare("Tea", 0);
	machine.prepare("Coffe", 1);
	machine.prepare("Coffe", 2);
	return 0;
}
*/