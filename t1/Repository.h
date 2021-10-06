#pragma once
#include "Gene.h"
#include "DynamicVector.h"

class Repository {
private:
	DynamicVector<Gene> genes;

public:
	Repository() {};

	bool addToRepository(const Gene& gene);

	DynamicVector<Gene> getAll();

	int findGene(const Gene& gene);

	DynamicVector<Gene> sort();

	DynamicVector<Gene> filter(const string& sequence);

	DynamicVector<Gene> sortVector(DynamicVector<Gene>& genes);
};