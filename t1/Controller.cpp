#include "Controller.h"

/* Add a gene
*  Input: organism, name, sequence - strings representing the fields of a gene
*  Output: true if the gene was added, false otherwise
*/
bool Controller::addGene(const string& organism, const string& name, const string& sequence) {
	Gene gene{ organism, name, sequence };
	return this->repository.addToRepository(gene);
}


DynamicVector<Gene> Controller::getGenesSorted()
{
	return this->repository.sort();
}

DynamicVector<Gene> Controller::getFiltered(const string& sequence)
{
	return this->repository.filter(sequence);
}
