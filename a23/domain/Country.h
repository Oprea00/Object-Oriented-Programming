#ifndef A23_OPREA00_COUNTRY_H
#define A23_OPREA00_COUNTRY_H

#include "stdlib.h"

typedef struct {
    char *name;
    char *continent;
    int population;
}Country;

//Constructor for Country
Country* createCountry(char *name, char *continent, int population);

int equalsCountries(Country* country1, Country* country2);

#endif //A23_OPREA00_COUNTRY_H
