#pragma once
#include <exception>
#include <string>

using namespace std;

class ValidationException : public exception {

private:
	string message;
	string error;

public:
	ValidationException(string message = "");
	const char* what() const noexcept override;
};