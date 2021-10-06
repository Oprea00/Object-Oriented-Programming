#include "ui/UI.h"
#include "tests/tests.h"

int main(){

    Repository* repository = repositoryConstructor(10);
    Controller* controller = controllerConstructor(repository);
    UI* ui = uiConstructor(controller);

    addCountry(ui->countryController, "Romania", "Europe", 19);
    addCountry(ui->countryController, "Germany", "Europe", 83);
    addCountry(ui->countryController, "Italy", "Europe", 60);
    addCountry(ui->countryController, "England", "Europe", 56);
    addCountry(ui->countryController, "China", "Asia", 1350);
    addCountry(ui->countryController, "Japan", "Asia", 126);
    addCountry(ui->countryController, "Egypt", "Africa", 98);
    addCountry(ui->countryController, "Australia", "Australia", 25);
    addCountry(ui->countryController, "Brazil", "America", 209);
    addCountry(ui->countryController, "United States", "America", 328);

    runAllTests();
    run(ui);
    uiDestructor(ui);

    return 0;
}
