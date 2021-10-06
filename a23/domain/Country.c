#include "domain/Country.h"
#include "string.h"

/* Function to create a Country based on parameters
 * Input: name, continent and population of a country
 * Output: a pointer to the new Country
*/
Country* createCountry(char *name, char *continent, int population){
    Country* country = (Country*)malloc(sizeof(Country));
    country->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
    strcpy(country->name, name);
    country->continent = (char*)malloc(sizeof(char) * strlen(continent) + 1);
    strcpy(country->continent, continent);
    country->population = population;
    return country;
}

/* Function to verify if two countries have the same name
 * Input: country1, country2 : 2 Countries
 * Output: 1 if the countries have the same name, 0 otherwise
*/
int equalsCountries(Country* country1, Country* country2){
    return strcmp(country1->name, country2->name) == 0;
}