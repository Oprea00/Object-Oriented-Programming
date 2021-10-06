#ifndef A23_OPREA00_CONTROLLER_H
#define A23_OPREA00_CONTROLLER_H

#include "repository/Repository.h"

typedef struct {
    Repository* countryRepository;
}Controller;

Controller* controllerConstructor(Repository* repository);

int addCountry(Controller* controller, char* name, char* continent, int population);

int updateCountry(Controller* controller, char* name, char* continent, int newPopulation);

int updateMigration(Controller* controller, char*country1, char* country2, int population);

int deleteCountry(Controller* controller, char* name);

DynamicArray* getCountries(Controller* controller);

DynamicArray* getCountriesByName(Controller* controller, char* inputName);

DynamicArray* getCountriesByContinent(Controller* controller, char* inputContinent);

DynamicArray* getCountriesByContinentAndPopulation(Controller* controller, char* continent, int population);

void controllerDestructor(Controller* controller);

#endif //A23_OPREA00_CONTROLLER_H
