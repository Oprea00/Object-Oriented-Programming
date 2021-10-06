#include "Exceptions.h"

ValidationException::ValidationException(string message) : message{ message }
{
	error = "Validation exception: " + message;
}

const char* ValidationException::what() const noexcept
{
	return error.c_str();
}