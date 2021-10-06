#include "Tests.h"
#include <iostream>

void Tests::runTests() {
	testAddToRepository();
	testAddExistingElementToRepository();
	testAddGene();
	testAddExistingGene();
	cout << "All tests passed\n";
}

void Tests::testAddToRepository() {
	Repository repository;
	Gene gene{ "a", "a" ,"a"};
	assert(repository.addToRepository(gene) == true);
}

void Tests::testAddExistingElementToRepository() {
	Repository repository;
	Gene gene1{ "a", "a" ,"a" };
	Gene gene2{ "a", "a" ,"a" };
	repository.addToRepository(gene1);
	assert(repository.addToRepository(gene2) == false);
}

void Tests::testAddGene() {
	Repository repository;
	Controller controller{ repository };
	assert(controller.addGene("a", "a", "a") == true);
}

void Tests::testAddExistingGene() {
	Repository repository;
	Controller controller{ repository };
	controller.addGene("a", "a", "a");
	assert(controller.addGene("a", "a", "a") == false);
}