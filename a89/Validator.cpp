#include "Validator.h"
#include "Exceptions.h"

void Validator::validateEvent(Event& event) {
	string error = "";
	if (event.getTitle() == "")
		error += "invalid title ";
	if (event.getDescription() == "")
		error += "invalid description ";
	if (event.getNumberOfPeople() < 0)
		error += "invalid number of people ";
	if (event.getLink() == "")
		error += "invalid link ";
	if (error != "")
		throw ValidationException(error);
}