#pragma once

#include "Repository.h"

class HtmlRepository : public Repository {
private:
    string htmlFileName;
    void updateFile();

public:
    HtmlRepository(const string& fileName, const string& htmlFileName = "");
    void goToEvent() override;
    void deleteFromList(const Event& event) override;
    string getListLocation() override;
};