
/*
#include <iostream>
using namespace std;
class Vehicle {
protected:
	double speed;
public:
	Vehicle(double ms) { speed = ms; }
	virtual void go() { cout << "Vehicle going ..." << endl; }
	void accelerate() { cout << "Vehicle accelerating..." << endl; }
};
class Scooter :public Vehicle {
public:
	Scooter(double s) : Vehicle(s) {}
	void go() { cout << "Scooter going ..." << endl; }
	void accelerate(int s) { cout << "Accelerating with " << s << "..." << endl; }
};

int main() {
	Scooter s(1);
	Vehicle& v = s;
	v.go();
	v.accelerate();
	return 0;
}
*/


#include <iostream>
using namespace std;
class Shape {
protected:
	int width, height;
	string measureUnit;

public: 
	virtual int getArea() = 0;
	void setWidth(int w) { width = w; }
	void setHeight(int w) { height = w; }
};

class Traingle : public Shape {
public:
	int getArea() {
		return (width * height) / 2;
	}
};

class Rectangle : public Shape {
public:
	int getArea(string _measureUnit) {
		return (width * height) / 2;
	}
};

/*
int main() {
	Rectangle rect;
	Shape* tri = new Traingle;
	tri->setWidth(5);
	tri->setHeight(7);
	cout << "triunghi" << tri->getArea() << endl;

	return 0;
}
*/