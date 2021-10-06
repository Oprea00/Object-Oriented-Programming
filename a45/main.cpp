#include "Tests.h"
#include "UI.h"

int main() {
//	Tests::runTests();
///*
	Repository repository;
	Controller controller{ repository };

	controller.addEvent("a", "a", 11, 03, 2021, 20, 30, 500, "https://untold.com/");
	controller.addEvent("b", "a", 11, 02, 2021, 20, 30, 500, "https://www.google.ro/");
	controller.addEvent("c", "a", 11, 03, 2021, 21, 30, 500, "https://www.facebook.com/events/433549494603674");
	controller.addEvent("d", "a", 11, 03, 2021, 20, 37, 500, "https://incaceva.ro/about/");
	controller.addEvent("e", "a", 11, 05, 2021, 20, 30, 500, "https://www.google.ro/");
	controller.addEvent("f", "a", 11, 01, 2021, 20, 30, 500, "https://www.facebook.com/events/3683481851770072/?acontext=%7B%22event_action_history%22%3A[%7B%22mechanism%22%3A%22discovery_top_tab%22%2C%22surface%22%3A%22bookmark%22%7D]%7D");
	controller.addEvent("g", "a", 11, 07, 2021, 20, 30, 500, "https://www.google.ro/");
	controller.addEvent("h", "a", 11, 11, 2021, 20, 30, 500, "https://www.google.ro/");
	controller.addEvent("i", "a", 11, 12, 2021, 20, 30, 500, "https://www.google.ro/");
	controller.addEvent("j", "a", 11, 10, 2021, 20, 30, 500, "https://www.google.ro/");

	UI ui{ controller };
	ui.run();
//*/
	return 0;
}