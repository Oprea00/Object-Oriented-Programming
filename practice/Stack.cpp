#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

template <typename T>

class Stack {
private:
	int maxCapacity;
	vector<T> elements;

public:
	Stack(int capacity) : elements{}, maxCapacity(capacity) {};

	int getMaxCapacity() {
		return maxCapacity;
	}

	Stack& operator+(T value) {
		if (this->getMaxCapacity() == elements.size())
			throw exception("Stack is full!");
		elements.push_back(value);
		return *this;
	}

	T pop() {
		T value = elements.back();
		elements.pop_back();
		return value;
	}
};

void testStack()
{
	Stack<std::string> s{ 2 }; 
	assert(s.getMaxCapacity() == 2);
	try {
		s = s + "examination";
		s = s + "oop";
		s = s + "test";
	}
	catch (std::exception& e) {
		assert(strcmp(e.what(), "Stack is full!") == 0);
	}
	assert(s.pop() == "oop");
	assert(s.pop() == "examination");
}

/*
int main() {
	testStack();
	cout << "Tests passed!" << std::endl;
	return 0;
}
*/