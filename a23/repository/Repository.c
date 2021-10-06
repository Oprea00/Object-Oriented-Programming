#include "repository/Repository.h"
#include <stdlib.h>

/* This function creates a Repository
 * Input: int capacity - the given capacity
 * Output: the new created Repository
*/
Repository* repositoryConstructor(int capacity) {
    Repository* countryRepository = (Repository*)malloc(sizeof(Repository));
    countryRepository->countries = dynamicArrayConstructor(capacity);
    return countryRepository;
}

/* This function adds a country to the repository
 * Input: repository - the repository
 *        country - the country to be added
 * Output: 1 if the country already exists in the repository, 0 otherwise
 */
int add(Repository* repository, Country* country) {
    int countryIndex = findCountry(repository, country);
    if (countryIndex != -1)
        return 0;
    addElement(repository->countries, country);
    return 1;
}

/* This function updates a country
 * Input: repository - the repository
 *        country - the country which will update the existing one in the repository
 * Output: 1 if the country exists and can be updated, 0 otherwise
 */
int update(Repository *repository, Country* newCountry) {
    int countryIndex = findCountry(repository, newCountry);
    if (countryIndex == -1)
        return 0;
    updateElement(repository->countries, countryIndex, newCountry);
    return 1;
}

/* This function deals with migration, a number of people leave one country and goes into another
 * Input: repository - the Repository
 *        country1 - the name of the country from which people leave
 *        country2 - the destination country
 *        population - the number of people going from country1 into country2
 * Output: 1 if the migration succeed, 0 otherwise(if a country doesn't exist)
 */
int migrate(Repository* repository, char* country1, char* country2, int population){
    // see if the countries exists in the repository
    int country1Index = findCountry(repository, createCountry(country1, "", 0));
    int country2Index = findCountry(repository, createCountry(country2, "", 0));
    if (country1Index == -1 || country2Index == -1)
        return 0;
    else{
        // decrease and increase population depending on country
        Country* countryFrom = getElementAtIndex(repository->countries, country1Index);
        countryFrom->population -= population;
        Country* countryDestination = getElementAtIndex(repository->countries, country2Index);
        countryDestination->population += population;
        // update population in dynamic array elements
        int update1Result = updateElement(repository->countries, country1Index, countryFrom);
        int update2Result = updateElement(repository->countries, country2Index, countryDestination);
        if (update1Result == 0 || update2Result == 0)
            return 0;
        return 1;
    }
}

/* This function deletes the country which has the given name
 * Input: repository - the repository
 *        char name - the name of the country to be deleted
 * Output: 1 if the country exists and can be deleted, 0 otherwise
 */
int delete(Repository *repository, char* countryName) {
  Country* country = createCountry(countryName, "", 0);
  int countryIndex = findCountry(repository, country);
    if (countryIndex == -1)
        return 0;
  deleteElement(repository->countries, countryIndex);
    return 1;
}

/* This function searches a country in the repository
 * Input: repository - the repository
 *        country - the country that we search for
 * Output: -1 if the country doesn't exists, otherwise the position of the country in the repository
 */
int findCountry(Repository* repository, Country* country){
    int position = -1;
    Country* currentCountry;
    for (int index = 0; index < repository->countries->size; index++){
        currentCountry = getElementAtIndex(repository->countries, index);
        if (equalsCountries(currentCountry, country) == 1){
            position = index;
            break;
        }
    }
    return position;
}

/* This function returns a copy of the countries
 * Input: countries - the dynamicArray containing the countries
 * Output: a dynamicArray with the countries
 */
DynamicArray* getAllCopy(DynamicArray* countries){
    DynamicArray* dynamicArray = dynamicArrayConstructor(countries->size);
    Country* currentCountry;
    Country* country;
    for (int index = 0; index < countries->size; index++){
        currentCountry = getElementAtIndex(countries, index);
        country = createCountry(currentCountry->name, currentCountry->continent, currentCountry->population);
        addElement(dynamicArray, country);
    }
    return dynamicArray;
}

//getAllCopy-> returns a copy of the dynamicArray, getAll->cals getAllCopy, needed to can call it from controller with repository parameter

/* This function returns a copy of the countries from repository
 * Input: repository - the repository
 * Output: a dynamicArray with the countries
 */
DynamicArray* getAll(Repository* repository){
    DynamicArray* dynamicArray = getAllCopy(repository->countries);
    return dynamicArray;
}

/* This function return a list of countries which have a specific name
 * Input: repository - the repository, inputName - the name(string) that is given from input
 * Output: the list of countries
 */
DynamicArray* getByName(Repository* repository, char* inputName){
    DynamicArray* allCountries = getAllCopy(repository->countries);
    //if (strcmp(inputName, "") == 0)
    //    return allCountries;

    Country* currentCountry;
    DynamicArray* filteredCountries = dynamicArrayConstructor(allCountries->size);
    char* contains;
    for (int index = 0; index < allCountries->size; index++){
        currentCountry = getElementAtIndex(allCountries, index);
        contains = strstr(currentCountry->name, inputName);
        if (contains != NULL){
            addElement(filteredCountries, currentCountry);
        }
    }
    return filteredCountries;
}

/* This function return a list of countries on a specific continent sorted ascending by name
 * Input: repository - the repository, inputName - te continent that is given from input
 * Output: the list of countries
 */
DynamicArray* getByContinent(Repository* repository, char* inputContinent){
    DynamicArray* allCountries = getAllCopy(repository->countries);
    Country* currentCountry;
    DynamicArray* filteredCountries = dynamicArrayConstructor(allCountries->size);
    for (int index = 0; index < allCountries->size; index++) {
        currentCountry = getElementAtIndex(allCountries, index);
        // if we found a country with the given continent
        if (strcmp(currentCountry->continent, inputContinent) == 0){
            addElement(filteredCountries, currentCountry);
        }
    }
    return sortAscendingByName(filteredCountries);
}

/* This function return a list of countries on a given continent whose populations are greater than a given value, sorted ascending by population
 * Input: repository - the repository, the given continent and the given population
 * Output: the list of countries
 */
DynamicArray* getByContinentAndPopulation(Repository* repository, char* continent, int population){
    DynamicArray* allCountries = getAllCopy(repository->countries);

    Country* currentCountry;
    DynamicArray* filteredCountries = dynamicArrayConstructor(allCountries->size);
    for (int index = 0; index < allCountries->size; index++) {
        currentCountry = getElementAtIndex(allCountries, index);
        // if we found a country with the given continent and with a greater population
        if (strcmp(currentCountry->continent, continent) == 0){
            if (currentCountry->population > population){
                addElement(filteredCountries, currentCountry);
            }
        }
    }
    return sortAscendingByPopulation(filteredCountries);
}

/* This function sorts a dynamicArray with countries by population in ascending order
 * Input: dynamicArray - a DynamicArray
 * Output: the sorted dynamicArray
 */
DynamicArray* sortAscendingByPopulation(DynamicArray* dynamicArray){
    Country* country1;
    Country* country2;
    int index1, index2;
    for (index1 = 0; index1 < dynamicArray->size-1; index1++){
        for (index2 = index1 + 1; index2 < dynamicArray->size; index2++){
            country1 = getElementAtIndex(dynamicArray, index1);
            country2 = getElementAtIndex(dynamicArray, index2);
            if (country1->population > country2->population){
                swapElements(dynamicArray, index1, index2);
            }
        }
    }
    return dynamicArray;
}

/* This function sorts a dynamicArray with countries by name in ascending order
 * Input: dynamicArray - a DynamicArray
 * Output: the sorted dynamicArray
 */
DynamicArray* sortAscendingByName(DynamicArray* dynamicArray){
    Country* country1;
    Country* country2;
    int index1, index2;
    for (index1 = 0; index1 < dynamicArray->size-1; index1++){
        for (index2 = index1 + 1; index2 < dynamicArray->size; index2++){
            country1 = getElementAtIndex(dynamicArray, index1);
            country2 = getElementAtIndex(dynamicArray, index2);
            if (strcmp(country1->name, country2->name) > 0){
                swapElements(dynamicArray, index1, index2);
            }
        }
    }
    return dynamicArray;
}

/* This function destroys a Repository
 * Input: a pointer to the repository
 * Output: -
 */
void CountryRepositoryDestructor(Repository* repository){
    if (repository != NULL){
        dynamicArrayDestructor((DynamicArray **) repository->countries);
        free(repository);
    }
}