/*
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Icecream {
public:
	Icecream() {}
	~Icecream() {}
	virtual ~Icecream() {}
	virtual string getDescription() {}
	virtual double computePrice() {}
};
class SimpleIcecream : public Icecream {
private:
	string description;
	double price;
public:
	SimpleIcecream(string d, double p) : Icecream{}, price{ p }, description{ d }{}
	~SimpleIcecream() {}
	string getDescription() override {
		return "simple icecream with " + description;
	}
	double computePrice() override {
		return price;
	}
};
class IcecreamWithTopping : public Icecream {
public:
	IcecreamWithTopping() : Icecream{} {}
	~IcecreamWithTopping() {}
	virtual string addTopping() {}
};
class IcecreamWithChocolateTopping : public IcecreamWithTopping {
public:
	IcecreamWithChocolateTopping() : IcecreamWithTopping{} {}
	~IcecreamWithChocolateTopping() {}
	string addTopping() override {
		return this->getDescription() + " and chocolate topping";
	}
	double computePrice() override {
		double newPrice = this->computePrice() + 3;
		return newPrice;
	}
};
class IcecreamWithCaramelTopping : public IcecreamWithTopping {
public:
	IcecreamWithCaramelTopping() : IcecreamWithTopping{} {}
	~IcecreamWithCaramelTopping() {}
	string addTopping() override {
		return this->getDescription() + " and caramel topping";
	}
	double computePrice() override {
		double newPrice = this->computePrice() + 2;
		return newPrice;
	}
};
bool sortFunction(Icecream& i1, Icecream& i2) {
	return i1.computePrice() > i2.computePrice();
}
class Order {
private:
	vector<Icecream> ic;
public:
	Order() {}
	~Order() {}
	void addIcecream(Icecream& icecream) {
		ic.push_back(icecream);
	}
	void printOrder() {
		sort(ic.begin(), ic.end(), sortFunction);
		for (auto& i : ic) {
			cout << i.getDescription() << " price: " << to_string(i.computePrice());
		}
	}
};
void orderIcecream() {
	SimpleIcecream simpleVanilla{ "vanilla", 5 };
	IcecreamWithCaramelTopping topping1{ "pistachio", 5 };
	IcecreamWithChocolateTopping topping2{ topping1.getDescription(), topping1.computePrice() };
	SimpleIcecream simpleHazelnut{ "hazlenut", 5 };
	Order order{};
	order.addIcecream(simpleVanilla);
	order.addIcecream(topping1);
	order.addIcecream(simpleHazelnut);
	order.printOrder();
}

int main() {
	orderIcecream();
	return 0;
}
*/