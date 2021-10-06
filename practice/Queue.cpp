#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

template <typename T>

class Queue {
private:
    vector<T> elements;
    

public:
    Queue(T firstElement) { elements.push_back(firstElement); }

    Queue& operator+(T value) {
        elements.push_back(value);
        return *this;
    }

    T pop() {
        if (elements.size() > 0) {
            T value = elements.front();
            elements.erase(elements.begin());
            return value;
        }
        else throw exception("Queue is empty!");
    }
};

void testQueue()
{
    Queue<std::string> q{ "today" };
    q = q + "examination";
    q = q + "oop";
    try {
        assert(q.pop() == "today");
        assert(q.pop() == "examination");
        assert(q.pop() == "oop");
        q.pop();
    }
    catch (std::exception& e) {
        assert(strcmp(e.what(), "Queue is empty!") == 0);
    }
}

/*
int main() {
    testQueue();
    cout << "Tests passed!" << std::endl;
    return 0;
}
*/