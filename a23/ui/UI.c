#include "ui/UI.h"
#include <stdio.h>
#include <string.h>

UI* uiConstructor(Controller* controller){
    UI* userInterface = (UI*)malloc(sizeof(UI));
    userInterface->countryController = controller;
    return userInterface;
}

void uiDestructor(UI* ui) {
    controllerDestructor(ui->countryController);
    free(ui);
}

void addCountryUI(UI* ui){
    char name[20] = {};
    char continent[20] = {};
    int population = 0;

    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the continent: ");
    scanf("%s", continent);
    printf("Enter the population: ");
    int okPopulation = scanf("%d", &population);
    if (okPopulation != 1 || population < 0){
        printf("Not a valid population\n");
        return;
    }

    if (verifyContinentInput(continent) == 0){
        printf("Not a valid continent\n");
        return;
    }

    int successfulAdd = addCountry(ui->countryController, name, continent, population);
    if (successfulAdd == 1)
        printf("Country was added\n");
    else
        printf("The country with given name already exists");
}

void updateCountryUI(UI* ui){
    char name[20] = {};
    char continent[20] = {};
    int population = 0;

    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the continent: ");
    scanf("%s", continent);
    printf("Enter the population: ");
    int okPopulation = scanf("%d", &population);
    if (okPopulation != 1 || population < 0){
        printf("Not a valid population\n");
        return;
    }

    if (verifyContinentInput(continent) == 0){
        printf("Not a valid continent\n");
        return;
    }

    int successfulUpdate = updateCountry(ui->countryController, name, continent, population);
    if (successfulUpdate == 1)
        printf("The country was updated\n");
    else
        printf("The country with given name doesn't exist");
}

void deleteCountryUI(UI* ui){
    char name[20] = {};
    printf("Enter the name: ");
    scanf("%s", name);

    int successfulDelete = deleteCountry(ui->countryController, name);
    if (successfulDelete == 1)
        printf("The country was deleted\n");
    else
        printf("The country with given name doesn't exist");
}

void listCountriesUI(UI* ui){
    Country* country;
    char name[20];
    char continent[20];
    int population;

    DynamicArray* countries = getCountries(ui->countryController);
    int listLength = countries->size;

    if (listLength == 0 )
        printf("There are no countries\n");
    else{
        for (int index = 0; index < listLength; index++){
            country = getElementAtIndex(countries, index);
            strcpy(name, country->name);
            strcpy(continent, country->continent);
            population = country->population;
            printf("%s, %s, %d\n", name, continent, population);
        }
    }
}

void migrationUI(UI* ui){
    char country1[20] = {};
    char country2[20] = {};
    int population = 0;

    printf("Enter the name for first country: ");
    scanf("%s", country1);
    printf("Enter the name for destination country: ");
    scanf("%s", country2);
    printf("Enter the number of migrators: ");
    scanf("%d", &population);

    int successfulMigration = updateMigration(ui->countryController, country1, country2, population);
    if (successfulMigration == 1)
        printf("The migration succeed\n");
    else
        printf("The country with given name doesn't exist");
}

void findByName(UI* ui){
    char name[20];
    char continent[20];
    int population;
    printf("Enter string: ");
    scanf(" %s", name);
    //scanf("%[^\n]",name);

    DynamicArray* countries = getCountriesByName(ui->countryController, name);
    int listLength = countries->size;

    if (listLength == 0 )
        printf("There are no countries with that name\n");
    else{
        for (int index = 0; index < listLength; index++){
            Country* country = getElementAtIndex(countries, index);
            strcpy(name, country->name);
            strcpy(continent, country->continent);
            population = country->population;
            printf("%s, %s, %d\n", name, continent, population);
        }
    }
}

void findByContinent(UI* ui){
    char name[20];
    char continent[20];
    int population;
    printf("Enter continent: ");
    scanf(" %s", continent);

    DynamicArray* countries = getCountriesByContinent(ui->countryController, continent);
    int listLength = countries->size;

    if (listLength == 0 )
        printf("There are no countries with that name\n");
    else{
        for (int index = 0; index < listLength; index++){
            Country* country = getElementAtIndex(countries, index);
            strcpy(name, country->name);
            strcpy(continent, country->continent);
            population = country->population;
            printf("%s, %s, %d\n", name, continent, population);
        }
    }
}

void findByContinentAndPopulation(UI* ui){
    char name[20];
    char continent[20];
    int population;
    printf("Enter continent: ");
    scanf(" %s", continent);
    printf("Enter the population: ");
    scanf("%d", &population);

    DynamicArray* countries = getCountriesByContinentAndPopulation(ui->countryController, continent, population);
    int listLength = countries->size;

    if (listLength == 0 )
        printf("There are no countries\n");
    else{
        for (int index = 0; index < listLength; index++){
            Country* country = getElementAtIndex(countries, index);
            strcpy(name, country->name);
            strcpy(continent, country->continent);
            population = country->population;
            printf("%s, %s, %d\n", name, continent, population);
        }
    }
}

int verifyContinentInput(char* continent){
    char* continents[] = {"Europe", "America", "Africa", "Australia", "Asia"};
    for (int index = 0; index < 5; index++)
        if (strcmp(continent, continents[index]) == 0) {
            return 1;
        }
    return 0;
}

void printMenu(){
    printf("\n0. Exit\n");
    printf("1. Add a country\n");
    printf("2. Update a country\n");
    printf("3. Delete a country\n");
    printf("4. List all countries\n");
    printf("5. Migration\n");
    printf("6. Find a country by name\n");
    printf("7. Find countries by continent and population, sorted ascending by population\n");
    printf("8. Find countries by continent, sorted ascending by name\n");
}

void run(UI* ui){
    char buffer[20];
    int option = 1;
    while (option != 0){
        printMenu();
        scanf("%d", &option);
        //fgets(buffer, 20, stdin);
        //option = strtol(buffer, NULL, 0);
        switch (option) {
            case 1:
                addCountryUI(ui);
                break;
            case 2:
                updateCountryUI(ui);
                break;
            case 3:
                deleteCountryUI(ui);
                break;
            case 4:
                listCountriesUI(ui);
                break;
            case 5:
                migrationUI(ui);
                break;
            case 6:
                findByName(ui);
                break;
            case 7:
                findByContinentAndPopulation(ui);
                break;
            case 8:
                findByContinent(ui);
                break;
            case 0:
                break;
            default:
                printf("Not a valid option\n");
                break;
        }
    }
}