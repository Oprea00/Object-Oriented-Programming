#include "CsvRepository.h"
#include <sstream>
#include <fstream>

CsvRepository::CsvRepository(const string& fileName, const string& csvFileName) : Repository{ fileName }, csvFileName{ csvFileName }
{}

void CsvRepository::updateFile() {
    ofstream file(this->csvFileName);
    if (!file.is_open())
        return;
    for (auto event : getEventsList())
    {
        file << event;
    }
    file.close();
}

void CsvRepository::goToEvent() {
    Repository::goToEvent();
    updateFile();
}

void CsvRepository::deleteFromList(const Event& event) {
    Repository::deleteFromList(event);
    updateFile();
}

string CsvRepository::getListLocation()
{
    return csvFileName;
}