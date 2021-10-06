#include <iostream>
#include <vector>

using namespace std;

class Activity {
private:
	string description;
	string date;

public:
	Activity(string desc, string date) : description(desc), date(date) {};

	friend ostream& operator<<(ostream& out, const Activity& activity) {
		out << "Activity " << activity.description << " will take place at " << activity.date << ".";
		return out;
	}
};

template <typename T>
class ToDo {
private:
	vector<T> elements;

public:
	ToDo() : elements{} {};

	ToDo& operator+=(T value) {
		elements.push_back(value);
		return *this;
	}

	auto begin() {
		return elements.begin();
	}

	auto end() {
		return elements.end();
	}

	void reversePrint(ostream& out) {
		for (int index = elements.size() - 1; index >= 0; index--)
			out << elements[index] << "\n";
	}

};

void ToDoList()
{
	ToDo<Activity> todo{};
	Activity tiff{ "go to TIFF movie", "20:00" };
	todo += tiff;
	Activity project{ "present project assignment", "09.20" };
	todo += project;
	// iterates through the activities and prints them as follows:
	// Activity present project assignment will take place at 09.20.
	// Activity go to TIFF movie will take place at 20.00.
	for (auto a : todo)
		std::cout << a << '\n';
	// Prints the activities as follows:
	// Activity go to TIFF movie will take place at 20.00.
	// Activity present project assignment will take place at 09.20.
	todo.reversePrint(std::cout);
}

/*
int main() {
	ToDoList();
	return 0;
}
*/