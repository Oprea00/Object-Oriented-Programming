#pragma once

#include "Repository.h"

class CsvRepository : public Repository {
private:
    string csvFileName;
    void updateFile();

public:
    CsvRepository(const string& fileName, const string& csvFileName = "");
    void goToEvent() override;
    void deleteFromList(const Event& event) override;
    string getListLocation() override;
};