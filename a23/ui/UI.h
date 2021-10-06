
#ifndef A23_OPREA00_UI_H
#define A23_OPREA00_UI_H

#include "controller/Controller.h"

typedef struct{
    Controller *countryController;
}UI;

UI* uiConstructor(Controller* controller);

void addCountryUI(UI* ui);

void updateCountryUI(UI* ui);

void deleteCountryUI(UI* ui);

void listCountriesUI(UI* ui);

void migrationUI(UI* ui);

void findByName(UI* ui);

void findByContinent(UI* ui);

void findByContinentAndPopulation(UI* ui);

int verifyContinentInput(char* continent);

void printMenu();

void run(UI* ui);

void uiDestructor(UI* ui);

#endif //A23_OPREA00_UI_H
