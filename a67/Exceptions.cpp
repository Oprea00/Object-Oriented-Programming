#include "Exceptions.h"

RepositoryException::RepositoryException(string message) : message{ message }
{
	error = "Repository exception: " + message;
}

const char* RepositoryException::what() const noexcept
{
	return error.c_str();
}


ValidationException::ValidationException(string message) : message{ message }
{
	error = "Validation exception: " + message;
}

const char* ValidationException::what() const noexcept
{
	return error.c_str();
}