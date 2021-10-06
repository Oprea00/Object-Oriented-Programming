#include "tests.h"

void runAllTests(){
    testCreateCountry();
    testEqualsCountries();
    testNotEqualCountries();
    // tests for DynamicArray
    testCreateDynamicArray();
    testResize();
    testAddElement();
    testUpdateElement();
    testDeleteElement();
    testGetElementAtIndex();
    // tests for Repository
    testCreateRepository();
    testAdd();
    testAddDuplicate();
    testUpdate();
    testUpdateInexistent();
    testDelete();
    testDeleteInexistent();
    testMigrateRepository();
    testFindCountry();
    testGetAll();
    testGetByName();
    testGetByContinent();
    testGetByContinentAndPopulation();
    // tests for Controller
    testCreateController();
    testAddCountry();
    testAddCountryThatExists();
    testUpdateCountry();
    testUpdateInexistentCountry();
    testDeleteCountry();
    testDeleteInexistentCountry();
    testMigrate();
    testGetCountries();
    testGetCountriesByName();
    testGetCountriesByContinent();
    testGetCountriesByContinentAndPopulation();

    printf("\nAll tests passed.\n");
}

void testCreateCountry(){
    Country* country = createCountry("test", "testing", 0);
    assert(strcmp(country->name, "test") == 0);
    assert(strcmp(country->continent, "testing") == 0);
    assert(country->population == 0);
}

void testEqualsCountries(){
    Country* country1 = createCountry("test", "testing", 0);
    Country* country2 = createCountry("test", "testing", 0);
    assert(equalsCountries(country1, country2) == 1);
}

void testNotEqualCountries(){
    Country* country1 = createCountry("test1", "testing", 0);
    Country* country2 = createCountry("test2", "testing", 0);
    assert(equalsCountries(country1, country2) == 0);
}

// --------------------- Dynamic Array Part ---------------------------

void testCreateDynamicArray(){
    DynamicArray* dynamicArray = dynamicArrayConstructor(10);
    assert(dynamicArray->capacity == 10);
}

void testResize(){
    DynamicArray* dynamicArray = dynamicArrayConstructor(10);
    resize(dynamicArray);
    assert(dynamicArray->capacity == 20);
}

void testAddElement(){
    DynamicArray* dynamicArray = dynamicArrayConstructor(10);
    int vector[] = {1, 2, 3};
    for (int index = 0; index < 3; index++) {
        addElement(dynamicArray, &vector[index]);
    }
    assert(dynamicArray->size == 3);
}

void testUpdateElement(){
    DynamicArray* dynamicArray = dynamicArrayConstructor(10);
    int vector[] = {1, 2, 3};
    int vector2[] = {11};
    for (int index = 0; index < 3; index++) {
        addElement(dynamicArray, &vector[index]);
    }
    updateElement(dynamicArray, 0, &vector2[0]);
    assert(dynamicArray->elements[0] == &vector2[0]);
}

void testDeleteElement(){
    DynamicArray* dynamicArray = dynamicArrayConstructor(10);
    int vector[] = {1, 2, 3};
    for (int index = 0; index < 3; index++) {
        addElement(dynamicArray, &vector[index]);
    }
    deleteElement(dynamicArray, 0);
    assert(dynamicArray->size == 2);
}

void testGetElementAtIndex(){
    DynamicArray* dynamicArray = dynamicArrayConstructor(10);
    int vector[] = {1, 2, 3};
    for (int index = 0; index < 3; index++) {
        addElement(dynamicArray, &vector[index]);
    }
    assert(getElementAtIndex(dynamicArray, 0) == &vector[0]);
}

// --------------------- Repository Part ---------------------------

void testCreateRepository(){
    Repository* repository = repositoryConstructor(10);
    assert(repository->countries->capacity == 10);
}

void testAdd(){
    Repository* repository = repositoryConstructor(10);
    Country* country = createCountry("Romania", "Europe", 19);
    add(repository, country);
    assert(repository->countries->size == 1);
}

void testAddDuplicate(){
    Repository* repository = repositoryConstructor(10);
    Country* country = createCountry("Romania", "Europe", 19);
    add(repository, country);
    assert(add(repository, createCountry("Romania", "Europe", 19)) == 0);
}

void testUpdate(){
    Repository* repository = repositoryConstructor(10);
    Country* country = createCountry("Romania", "Europe", 19);
    add(repository, country);
    Country* newCountry = createCountry("Romania", "-", 18);
    update(repository, newCountry);
    assert(equalsCountries(getElementAtIndex(repository->countries, 0), newCountry) == 1);
}

void testUpdateInexistent(){
    Repository* repository = repositoryConstructor(10);
    Country* country = createCountry("Romania", "Europe", 19);
    assert(update(repository, country) == 0);
}

void testDelete(){
    Repository* repository = repositoryConstructor(10);
    Country* country = createCountry("Romania", "Europe", 19);
    add(repository, country);
    delete(repository, "Romania");
    assert(repository->countries->size == 0);
}

void testDeleteInexistent(){
    Repository* repository = repositoryConstructor(10);
    assert(delete(repository, "Romania") == 0);
}

void testMigrateRepository(){
    Repository* repository = repositoryConstructor(10);
    Country* country1 = createCountry("Romania", "Europe", 24);
    Country* country2 = createCountry("Italy", "Europe", 60);
    add(repository, country1);
    add(repository, country2);
    migrate(repository, "Romania", "Italy", 6);
    Country* Romania = getElementAtIndex(repository->countries, 0);
    assert(Romania->population == 18);
    Country* Italy = getElementAtIndex(repository->countries, 1);
    assert(Italy->population == 66);
}

void testFindCountry(){
    Repository* repository = repositoryConstructor(10);
    Country* country1 = createCountry("Romania", "Europe", 24);
    Country* country2 = createCountry("Italy", "Europe", 60);
    add(repository, country1);
    add(repository, country2);
    assert(findCountry(repository, country2) == 1);
}

void testGetAll(){
    Repository* repository = repositoryConstructor(10);
    Country* country1 = createCountry("Romania", "Europe", 24);
    Country* country2 = createCountry("Italy", "Europe", 60);
    add(repository, country1);
    add(repository, country2);
    DynamicArray* countries = getAll(repository);
    assert(countries->size == 2);
}

void testGetByName(){
    Repository* repository = repositoryConstructor(10);
    Country* country1 = createCountry("Romania", "Europe", 24);
    Country* country2 = createCountry("Italy", "Europe", 60);
    add(repository, country1);
    add(repository, country2);
    DynamicArray* countries = getByName(repository, "Rom");
    assert(countries->size == 1);
}

void testGetByContinent(){
    Repository* repository = repositoryConstructor(10);
    Country* country1 = createCountry("Romania", "Europe", 24);
    Country* country2 = createCountry("Italy", "Europe", 60);
    Country* country3 = createCountry("China", "Asia", 1230);
    add(repository, country1);
    add(repository, country2);
    add(repository, country3);
    DynamicArray* countries = getByContinent(repository, "Europe");
    assert(countries->size == 2);
}

void testGetByContinentAndPopulation(){
    Repository* repository = repositoryConstructor(10);
    Country* country1 = createCountry("Romania", "Europe", 24);
    Country* country2 = createCountry("Italy", "Europe", 60);
    Country* country3 = createCountry("China", "Asia", 1230);
    add(repository, country1);
    add(repository, country2);
    add(repository, country3);
    DynamicArray* countries = getByContinentAndPopulation(repository, "Europe", 30);
    assert(countries->size == 1);
}

// --------------------- Controller Part ---------------------------

void testCreateController(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    assert(controller->countryRepository->countries->capacity == 10);
}

void testAddCountry(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    addCountry(controller, "test", "test", 20);
    assert(controller->countryRepository->countries->size == 1);
}

void testAddCountryThatExists(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    addCountry(controller, "test", "test", 20);
    assert(addCountry(controller, "test", "test", 20) == 0);
}

void testUpdateCountry(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    addCountry(controller, "test", "test", 20);
    updateCountry(controller, "test", "continent", 100);
    Country* newCountry = createCountry("test", "continent", 100);
    assert(equalsCountries(getElementAtIndex(controller->countryRepository->countries, 0), newCountry) == 1);
}

void testUpdateInexistentCountry(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    assert(updateCountry(controller, "test", "continent", 100) == 0);
}

void testDeleteCountry(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    addCountry(controller, "test", "test", 20);
    deleteCountry(controller, "test");
    assert(controller->countryRepository->countries->size == 0);
}

void testDeleteInexistentCountry(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    assert(deleteCountry(controller, "test") == 0);
}

void testMigrate(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    addCountry(controller, "Romania", "Europe", 24);
    addCountry(controller, "Italy", "Europe", 60);
    updateMigration(controller, "Romania", "Italy", 6);
    Country* Romania = getElementAtIndex(controller->countryRepository->countries, 0);
    assert(Romania->population == 18);
    Country* Italy = getElementAtIndex(controller->countryRepository->countries, 1);
    assert(Italy->population == 66);
}

void testGetCountries(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    addCountry(controller, "Romania", "Europe", 24);
    addCountry(controller, "Italy", "Europe", 60);
    DynamicArray* countries = getCountries(controller);
    assert(countries->size == 2);
}

void testGetCountriesByName(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    addCountry(controller, "Romania", "Europe", 24);
    addCountry(controller, "Italy", "Europe", 60);
    DynamicArray* countries = getCountriesByName(controller, "Rom");
    assert(countries->size == 1);
}

void testGetCountriesByContinent(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    addCountry(controller, "Romania", "Europe", 24);
    addCountry(controller, "Italy", "Europe", 60);
    addCountry(controller, "China", "Asia", 1230);
    DynamicArray* countries = getCountriesByContinent(controller, "Europe");
    assert(countries->size == 2);
}

void testGetCountriesByContinentAndPopulation(){
    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    addCountry(controller, "Romania", "Europe", 24);
    addCountry(controller, "Italy", "Europe", 60);
    addCountry(controller, "China", "Asia", 1230);
    DynamicArray* countries = getCountriesByContinentAndPopulation(controller, "Europe", 30);
    assert(countries->size == 1);
}