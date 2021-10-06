/*#include <iostream>
#include <cstring>

using namespace std;

class B {
public:
	B() { cout << "B() "; }
	virtual void f() { cout << "B.f "; }
	void g() { f(); }
	virtual void h() { g(); }
};

class D : public B {
public:
	D() { cout << "D() "; }
	void f() { cout << "D.f "; }
	void h() { cout << "Function h "; B::h(); }
};
int main() {
	B b{}; D d{};
	B& dd = d;
	b.g();
	dd.h();
	return 0;
}


#include <iostream>
using namespace std;

class A
{
public:
	virtual void fun() { cout << "A::fun() "; }
};

class B : public A
{
public:
	void fun() { cout << "B::fun() "; }
};

class C : public B
{
public:
	void fun() { cout << "C::fun() "; }
};

/*
int main()
{
	B* bp = new C;
	bp->fun();
	return 0;
}
*/

#include <iostream>
using namespace std;
class Base
{
public:
    int x;
    // default constructor
    Base()
    {
        cout << "Base default constructor\n";
    }
    virtual void say() {
        cout << "in base";
    }
};

class Derived : public Base
{
public:

    int y;
    // default constructor
    Derived()
    {
        cout << "Derived default constructor\n";
    }
    void say() {
        cout << "in derived";
    }
};

class Third : public Derived
{

public:
    // default constructor
    Third()
    {
        this->x = 2;
        cout << "Third default constructor\n";
    }
    void say() {
        cout << "in third";
    }
};

int main()
{
    Base* d1 = new Third();
    d1->say();
}