#pragma once
#include "Repository.h"

class Controller {
private:
	Repository& repository;

public:
	Controller(Repository& repository) : repository(repository) {};

	bool addGene(const string& organism, const string& name, const string& sequence);

	DynamicVector<Gene> getGenesSorted();

	DynamicVector<Gene> getFiltered(const string& sequence);
};