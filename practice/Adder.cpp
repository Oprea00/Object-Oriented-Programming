#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Adder
{
private:
    vector<T> elements;

public:
    Adder(T value) { elements.push_back(value); };

    Adder& operator+(int value)
    {
        elements.push_back(value);
        return *this;
    }

    Adder& operator++()
    {
        int lastElement = elements[elements.size() - 1];
        elements.push_back(lastElement);
        return *this;
    }
    /*
        Returns: the sum of elements in the vector
        Input:
        Output: the sum of elements
    */
    int sum()
    {
        int sumOfNumbers = 0;
        for (auto element : elements)
            sumOfNumbers += element;
        return sumOfNumbers;
    }

    Adder& operator--()
    {
        if (elements.size() == 0)
            throw runtime_error("No more values!");
        elements.pop_back();
        return *this;
    }
};



void function2() {
    Adder<int> add{ 5 }; // build a new Adder, with initial value 5
    add = add + 5 + 2;	// add values 5 and 2
    ++add;		// adds the last added value (2) again
    add + 8;	// add value 8
    cout << add.sum() << "\n"; // print sum, so far: 22 (5+5+2+2+8)
    --add; // eliminate last added value
    cout << add.sum() << "\n"; // print modified sum: 14 (5+5+2+2)
    --(--add); // eliminate the two previously added values
    cout << add.sum() << "\n"; // print modified sum: 10
    try {
        --(--(--add));
    }
    catch (runtime_error& ex) {
        cout << ex.what(); // prints "No more values!";
    }
}

//int main()
//{
//    function2();
//    return 0;
//}