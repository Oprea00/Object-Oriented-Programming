/*#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

template <typename Type1, typename Type2>

class MultiDictionary {
private:
	vector<pair<Type1, Type2>> objs;
public:
	MultiDictionary() {};
	~MultiDictionary() {}

	MultiDictionary add(Type1 obj1, Type2 obj2) {
		this->objs.push_back(make_pair(obj1, obj2));
		return *this;
	}

	void erase(Type1 obj1, Type2 obj2){
		int index = 0;
		int deleted = 0;
		for (pair<Type1, Type2>& pair : objs) {
		//for (vector<pair<Type1, Type2>>::iterator it = objs.begin(); it != objs.end(); ++it) {
			if ((pair.first) == obj1 && (pair.second) == obj2) {
				objs.erase(index);
				deleted = 2;
				break;
			}
			else if ((pair.first) == obj1 && (pair.second) != obj2) {
				deleted = 1;
			}
			index++;
		}
		if (deleted == 0)
			throw runtime_error("Key does not exist!");
		else if (deleted == 1)
			throw runtime_error("Given value does not exist for given key!");

	} 

	void print(ostream& stream) {
		for (auto o : this->objs) {
			stream << o << ';';
		}

	}

	int sizeForKey(Type1 key) {
		int nr = 0;
		for (pair<Type1, Type2> &pair : objs){
		//for (vector<pair<Type1, Type2>>::iterator it = objs.begin(); it != objs.end(); ++it) {
			if ((pair.first) == key)
				nr++;
		}
		return nr;
	} 
};


class Person {
private:
	string name;
	int age;

public:
	Person(string name, int age) : name(name), age(age) {};
	~Person() {};
	string toString() {};
	bool operator==(const Person& person) const;
	friend ostream& operator<<(ostream& outputStream, const Person& person);
};

bool Person::operator==(const Person& person) const {
	return this->name == person.name && this->age == person.age;
}

ostream& operator<<(ostream& outputStream, const Person& person) {
	outputStream << person.name << "-" << person.age;
	return outputStream;
}


void function2()
{
	MultiDictionary<int, string> d1{};
	d1.add(1, "a").add(2, "b").add(1, "c").add(3, "d");
	//d1.print(std::cout); // prints 1 a; 2 b; 1 c; 3 d
	try {
		d1.erase(4, "w");
		assert(false);
	}
	catch (std::runtime_error& e) {
		try {
			assert(strcmp(e.what(), "Key does not exist!") == 0);
			d1.erase(2, "w");
			assert(false);
		}
		catch (std::runtime_error& e) {
			assert(strcmp(e.what(), "Given value does not exist for given key!") == 0);
		}
	}
	d1.erase(1, "a");
	//d1.print(std::cout); // prints 2 b; 1 c; 3 d
	MultiDictionary<string, Person> d2{};
	Person p1{ "Bianca", 20 }; Person p2{ "Andrei", 21 };
	d2.add("a", p1).add("a", p2);
	//d2.print(std::cout); // prints a Bianca is 20 years old; a Andrei is 21 years old;.
	assert(d2.sizeForKey("a") == 2);
	assert(d2.sizeForKey("b") == 0);
}

int main() {
	function2();
	return 0;
}

*/