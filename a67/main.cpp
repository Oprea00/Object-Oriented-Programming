#include "UI.h"

int main() {
	
	Repository* repository;
	cout << "Choose the type for events list\n";
	cout << "1/CSV\n";
	cout << "2/HTML\n";
	string option;
	cin >> option;

	if (option == "1" || option == "CSV") {
		repository = new CsvRepository{ "events.txt", "csvList.csv" };
		Controller controller{ *repository };
		UI ui{ controller };
		ui.run();
	}
	else if (option == "2" || option == "HTML") {
		repository = new HtmlRepository{ "events.txt", "list.html" };
		Controller controller{ *repository };
		UI ui{ controller };
		ui.run();
	}
	
	return 0;
}