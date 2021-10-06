#include "UI.h"
#include <iomanip>

void UI::addGeneUI()
{
	string organism, name, sequence;
	cout << "Enter the organism: ";
	cin.ignore();
	getline(cin, organism);
	cout << "Enter the name: ";
	getline(cin, name);
	cout << "Enter the sequence: ";
	getline(cin, sequence);

	bool result = this->controller.addGene(organism, name, sequence);
	if (result)
		cout << "Gene added\n";
	else
		cout << "Gene already exists\n";
}


void UI::listGenesSortedUI()
{
	const char separator = ' ';
	const int nameWidth = 12;
	const int numWidth = 8;

	DynamicVector<Gene> genes = this->controller.getGenesSorted();
	for (int index = 0; index < genes.getSize(); index++) {
		Gene gene = genes[index];
		//cout << "Organism: " << gene.getOrganism() + " "
		//	<< "Name: " << gene.getName() + " "
		//	<< "Sequence: " << gene.getSequence() + " " << "\n";
		//cout << left << setw(width) << setfill(separator) << gene.getOrganism() << setfill(separator) << gene.getName() << setfill(separator) << gene.getSequence() << endl;
		//cout << setw(13) << right << gene.getOrganism() << setfill(separator) << gene.getName() << setfill(separator) << gene.getSequence() << endl;
		//cout << right << setw(5) << gene.getOrganism() << right << setw(5) << "|" << right << setw(5) << gene.getName() << setw(5) << "|" << right << setw(5) << gene.getSequence() << endl;
		
		cout << left << setw(nameWidth) << setfill(separator) << gene.getOrganism();
		cout << right << setw(nameWidth) << setfill(separator) << "|";
		cout << right << setw(nameWidth) << setfill(separator) << gene.getName();
		cout << right << setw(nameWidth) << setfill(separator) << "|";
		cout << left << setw(nameWidth) << setfill(separator) << gene.getSequence();
		//cout << right << setw(29) << setfill(separator) << gene.getSequence();
		cout << endl;
	}
}

void UI::listFilteredUI(){
	string sequence;
	cout << "Enter the sequence: ";
	cin.ignore();
	getline(cin, sequence);

	const char separator = ' ';
	const int nameWidth = 12;

	DynamicVector<Gene> genes = this->controller.getFiltered(sequence);
	for (int index = 0; index < genes.getSize(); index++) {
		Gene gene = genes[index];
		//cout << "Organism: " << gene.getOrganism() + " "
		//	<< "Name: " << gene.getName() + " "
		//	<< "Sequence: " << gene.getSequence() + " " << "\n";
		//cout << right << setw(5) << gene.getOrganism() << right << setw(5) << "|" << right << setw(5) << gene.getName() << setw(5) << "|" << right << setw(5) << gene.getSequence() << endl;
		cout << left << setw(nameWidth) << setfill(separator) << gene.getOrganism();
		cout << right << setw(nameWidth) << setfill(separator) << "|";
		cout << right << setw(nameWidth) << setfill(separator) << gene.getName();
		cout << right << setw(nameWidth) << setfill(separator) << "|";
		cout << left << setw(nameWidth) << setfill(separator) << gene.getSequence();
		cout << endl;
	}
}

void UI::printMenu() {
	cout << "\n0. Exit";
	cout << "\n1. Add gene";
	cout << "\n2. List genes";
	cout << "\n3. List filtered by sequence\n";
	//	cout << "\n4. List events";
	//	cout << "\n5. Change mode\n";
}

void UI::run()
{
	int option = 1;
	while (option != 0)
	{
		printMenu();
		cin >> option;
		switch (option) {
		case 1:
			addGeneUI();
			break;
		case 2:
			listGenesSortedUI();
			break;
		case 3:
			listFilteredUI();
			break;
		case 0:
			break;
		default:
			cout << "Not a valid option\n";
			break;
		}
	}
}