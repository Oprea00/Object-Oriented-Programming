#include "UI.h"

int main(){

	Person person{ "Oprea" };

	BMI* bmi1 = new BMI("26.04.2021", 112);
	BMI* bmi2 = new BMI("25.04.2021", 100);
	BMI* bmi3 = new BMI("24.04.2021", 100);
	BP* bp1 = new BP("24.04.2021", 76, 89);
	BP* bp2 = new BP("26.04.2021", 56, 29);

	person.addMeasurement(bmi1);
	person.addMeasurement(bmi2);
	person.addMeasurement(bmi3);
	person.addMeasurement(bp1);
	person.addMeasurement(bp2);

	UI ui{ person };
	ui.run();
	return 0;
}