#ifndef A23_OPREA00_REPOSITORY_H
#define A23_OPREA00_REPOSITORY_H

#include "domain/Country.h"
#include "DynamicArray.h"
#include "string.h"

typedef struct{
    DynamicArray *countries;
}Repository;

Repository* repositoryConstructor(int capacity);

int add(Repository* repository, Country* country);

int update(Repository* repository, Country* newCountry);

int delete(Repository* repository, char* countryName);

int migrate(Repository* repository, char* country1, char* country2, int population);

int findCountry(Repository* repository, Country* country);

DynamicArray* getAllCopy(DynamicArray* dynamicArray);

DynamicArray* getAll(Repository* repository);

DynamicArray* getByName(Repository* repository, char* inputName);

DynamicArray* getByContinent(Repository* repository, char* inputContinent);

DynamicArray* getByContinentAndPopulation(Repository* repository, char* continent, int population);

DynamicArray* sortAscendingByPopulation(DynamicArray* dynamicArray);

DynamicArray* sortAscendingByName(DynamicArray* dynamicArray);

void CountryRepositoryDestructor(Repository* repository);

#endif //A23_OPREA00_REPOSITORY_H
