#include "controller/Controller.h"

/* This function creates a Controller
 * Input: repository: Repository* - the given repository
 * Output: the new created Controller
*/
Controller* controllerConstructor(Repository* repository){
    Controller* countryController = (Controller*)malloc(sizeof(Controller));
    countryController->countryRepository = repository;
    return countryController;
}

/* This function creates a country and adds it to the repository
 * Input: controller - the controller
 *        char name, continent - the name and the continent for the new country
 *        int population - the population of the country
 * Output: 1 if the operation succeed, 0 otherwise
 */
int addCountry(Controller* controller, char *name, char *continent, int population) {
    Country* country = createCountry(name, continent, population);
    return add(controller->countryRepository, country);
}

/* This function updates a country with a new one created with the given parameters
 * Input: controller - the controller
 *        char name, continent - the name and the continent for the new country
 *        int population - the population of the country
 * Output: 1 if the operation succeed, 0 otherwise
 */
int updateCountry(Controller* controller, char *name, char* continent, int newPopulation) {
    Country* country = createCountry(name, continent, newPopulation);
    return update(controller->countryRepository, country);
}

/* This function deals with migration, a number of people leave one country and goes into another
 * Input: controller - the controller
 *        country1 - the name of the country from which people leave
 *        country2 - the destination country
 *        population - the number of people going from country1 into country2
 * Output: 1 if the migration succeed, 0 otherwise
 */
int updateMigration(Controller* controller, char*country1, char* country2, int population){
    return migrate(controller->countryRepository, country1, country2, population);
}

/* This function deletes the country which has the given name
 * Input: controller - the controller
 *        char name - the name of the country to be deleted
 * Output: 1 if the operation succeed, 0 otherwise
 */
int deleteCountry(Controller* controller, char *name) {
    return delete(controller->countryRepository, name);
}
/* This function return a copy of the list of countries
 * Input: controller - the controller
 * Output: the list of countries
 */
DynamicArray* getCountries(Controller* controller){
    return getAll(controller->countryRepository);
}

/* This function return a list of countries which have the specific name
 * Input: controller - the controller, inputName - the name(string) that is given from input
 * Output: the list of countries
 */
DynamicArray* getCountriesByName(Controller* controller, char* inputName){
    return getByName(controller->countryRepository, inputName);
}

/* This function return a list of countries on a given continent sorted ascending by name
 * Input: controller - the controller, inputContinent - the given continent from input
 * Output: the list of countries
 */
DynamicArray* getCountriesByContinent(Controller* controller, char* inputContinent){
    return getByContinent(controller->countryRepository, inputContinent);
}

/* This function return a list of countries on a given continent whose populations are greater than a given value, sorted ascending by population
 * Input: controller - the controller, the given continent and the given population
 * Output: the list of countries
 */
DynamicArray* getCountriesByContinentAndPopulation(Controller* controller, char* continent, int population){
    return getByContinentAndPopulation(controller->countryRepository, continent, population);
}

/* This function destroys a Controller
 * Input: a pointer to the controller
 * Output: -
 */
void controllerDestructor(Controller* controller){
    CountryRepositoryDestructor(controller->countryRepository);
    free(controller);
}