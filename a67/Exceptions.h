#pragma once
#include <exception>
#include <string>

using namespace std;

class RepositoryException : public exception{

private:
	string message;
	string error;

public:
	RepositoryException(string message = "");
	const char* what() const noexcept override;
};


class ValidationException : public exception{

private:
	string message;
	string error;

public:
	ValidationException(string message = "");
	const char* what() const noexcept override;
};