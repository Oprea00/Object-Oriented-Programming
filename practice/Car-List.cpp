#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
class Car
{
private:
	int price;
	string carname;
public:
	Car(string carname, int price) : price{ price }, carname{ carname } {}
	string get_carname() { return this->carname; }
	int get_price() { return this->price; }
	friend bool operator<(const Car& c, const Car& c1) { return (c.price < c1.price); }
	friend std::ostream& operator<<(std::ostream& os, const Car& c) { return os << c.carname << " " << c.price; }
};
template <typename T, typename TElem>
class List
{
private:
	std::vector<pair<T, TElem>> vect;
public:
	List() {}

	void sortByFirstComponent();

	void sortBySecondComponent();

	void add(T elem, TElem elem1);

	void printReverse();

	friend bool operator<(pair<T, TElem> s, pair<T, TElem> s1) { return s.first < s1.first; }

	friend bool operator>(pair<T, TElem> s, pair<T, TElem> s1) { return s.second < s1.second; }


};



template<typename T, typename TElem>
void List<T, TElem>::sortByFirstComponent()
{
	if (vect.size() == 0)
		throw runtime_error("List is empty!");
	else
	{
		std::sort(vect.begin(), vect.end(), [](pair<T, TElem> a, pair<T, TElem> b) {return a.first < b.first; });
	}
}

template<typename T, typename TElem>
void List<T, TElem>::sortBySecondComponent()
{
	if (vect.size() == 0)
		throw runtime_error("List is empty!");
	else
	{
		std::sort(vect.begin(), vect.end(), [](pair<T, TElem> a, pair<T, TElem> b) {return a.second < b.second; });
	}
}

template<typename T, typename TElem>
void List<T, TElem>::add(T elem, TElem elem1)
{
	pair<T, TElem> q = std::make_pair(elem, elem1);

	this->vect.push_back(q);
}
template<typename T, typename TElem>
void List<T, TElem>::printReverse()
{
	reverse(vect.begin(), vect.end());
	for (auto& elem : vect)
	{
		cout << elem.first << " -> " << elem.second << " ";
	}
	cout << "\n";
	reverse(vect.begin(), vect.end());
}

/*
int main()
{
	List<Car, int> list1;
	try {
		list1.sortByFirstComponent();
		assert(false);
	}
	catch (runtime_error& e) { assert(strcmp(e.what(), "List is empty!") == 0); }

	list1.add(Car{ "Audi", 20 }, 8);
	list1.add(Car{ "Volkswagen", 10 }, 9);
	list1.add(Car{ "Bentley", 300 }, 10);

	list1.sortByFirstComponent();
	list1.printReverse(); // prints: Bentley 300 -> 10; Audi 20 -> 8; Volkswagen 10 -> 9 
	list1.sortBySecondComponent();
	list1.printReverse(); // prints: Bentley 300 -> 10; Volkswagen 10 -> 9; Audi 20 -> 8;
}
*/