#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class Message
{
private:
	string text;

public:
	Message(string message) : text{ message } {};

	virtual string getMessage()
	{
		//return text;
	}

	virtual ~Message()
	{

	};
};


class ShortMessage : public Message
{
public:
	ShortMessage(string text) : Message{ text }
	{
		if (text.length() > 70)
			throw invalid_argument("Message has to be shorter");
	};

	string getMessage() override
	{
		//return text;
	}
};


class NormalMessage : public Message
{
public:
	NormalMessage(string text) : Message{ text } {};

	string getMessage() override
	{

	}
};


class MessageWithAttachment : public Message
{
private:
	string attachmentLocation;
public:
	string getMessage() override
	{

	}
};


class Contact
{
protected:
	string name;
public:
	Contact(string name) : name{ name } {};
	virtual ~Contact() {};
	virtual void addContact(Contact& c) = 0;
	virtual void sendMessage(Message& m) = 0;
};


class Person : public Contact
{
public:
	Person(string name) : Contact{ name } {};

	void sendMessage(Message& message) override
	{
		cout << "Sending message" << message.getMessage() << "to" << name << '\n';
	}
};

/*
int main()
{

	try {

	}
	catch (invalid_argument& error)
	{
		cout << error.what();
	}
}  */