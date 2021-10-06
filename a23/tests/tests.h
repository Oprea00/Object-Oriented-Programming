#ifndef A23_OPREA00_TESTS_H
#define A23_OPREA00_TESTS_H

#include "domain/Country.h"
#include "repository/Repository.h"
#include "controller/Controller.h"
#include "assert.h"
#include "string.h"
#include "stdio.h"

void runAllTests();
// tests for Country
void testCreateCountry();
void testEqualsCountries();
void testNotEqualCountries();
// tests for Dynamic Array
void testCreateDynamicArray();
void testResize();
void testAddElement();
void testUpdateElement();
void testDeleteElement();
void testGetElementAtIndex();
// tests for Repository
void testCreateRepository();
void testAdd();
void testAddDuplicate();
void testUpdate();
void testUpdateInexistent();
void testDelete();
void testDeleteInexistent();
void testMigrateRepository();
void testFindCountry();
void testGetAll();
void testGetByName();
void testGetByContinent();
void testGetByContinentAndPopulation();
// tests for Controller
void testCreateController();
void testAddCountry();
void testAddCountryThatExists();
void testUpdateCountry();
void testUpdateInexistentCountry();
void testDeleteCountry();
void testDeleteInexistentCountry();
void testMigrate();
void testGetCountries();
void testGetCountriesByName();
void testGetCountriesByContinent();
void testGetCountriesByContinentAndPopulation();

#endif //A23_OPREA00_TESTS_H
