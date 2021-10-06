#include "HtmlRepository.h"
#include <sstream>
#include <fstream>

void HtmlRepository::updateFile() {
	ofstream outputStream(this->htmlFileName);
	if (!outputStream.is_open())
		return;
	outputStream << "<!DOCTYPE html>\n";
	outputStream << "<html>\n";
	outputStream << "<head><title>Events List</title><style>body{color:white; background-color:#333; padding:auto; font-size:large;}table,td{border: 1px solid orange;}</style></head>\n";

	outputStream << "<body>\n";
	outputStream << "<table>\n";
	outputStream << "<tr>\n";
	outputStream << "<td>Title</td>\n";
	outputStream << "<td>Description</td>\n";
	outputStream << "<td>Date and time</td>\n";
	outputStream << "<td>Number of participants</td>\n";
	outputStream << "<td>Link</td>\n";
	outputStream << "</tr>\n";
	for (auto event : getEventsList())
	{
		outputStream << "<tr>\n";
		outputStream << "<td>" << event.getTitle() << "</td>\n";
		outputStream << "<td>" << event.getDescription() << "</td>\n";
		outputStream << "<td>" << event.getDateAndTime() << "</td>\n";
		outputStream << "<td>" << event.getNumberOfPeople() << "</td>\n";
		outputStream << "<td>" <<  event.getLink() << "</td>\n";
		outputStream << "</tr>\n";
	}
	outputStream << "</table>\n";
	outputStream << "</body>\n";
	outputStream << "</html>\n";
	outputStream.close();
}

HtmlRepository::HtmlRepository(const string& fileName, const string& HtmlFileName) : Repository{ fileName }, htmlFileName{ HtmlFileName }
{}

void HtmlRepository::goToEvent() {
    Repository::goToEvent();
    updateFile();
}

void HtmlRepository::deleteFromList(const Event& event) {
    Repository::deleteFromList(event);
    updateFile();
}

string HtmlRepository::getListLocation() {
	return htmlFileName;
}