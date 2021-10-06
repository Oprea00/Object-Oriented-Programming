#include "Repository.h"

/* Add a gene in repository
*  Input: gene - the gene to be added
*  Output: true if gene was added, false if gene already exists
*/
bool Repository::addToRepository(const Gene& gene)
{
	int genePosition = this->findGene(gene);
	if (genePosition != -1)
		return false;
	this->genes.add(gene);
	return true;
}

DynamicVector<Gene> Repository::getAll()
{
	return this->genes;
}

int Repository::findGene(const Gene& gene)
{
	int position = -1;
	for (int index = 0; index < genes.getSize(); index++)
		if (this->genes[index].getName() == gene.getName() && this->genes[index].getOrganism() == gene.getOrganism()) {
			position = index;
			break;
		}
	return position;
}

DynamicVector<Gene> Repository::sort()
{
	Gene gene1;
	Gene gene2;
	int index1, index2;
	for (index1 = 0; index1 < this->genes.getSize() - 1; index1++)
		for (index2 = index1 + 1; index2 < this->genes.getSize(); index2++) {
			gene1 = this->genes[index1];
			gene2 = this->genes[index2];
			if (gene1.getSequence().length() < gene2.getSequence().length()) {
				Gene auxGene = this->genes[index1];
				this->genes[index1] = this->genes[index2];
				this->genes[index2] = auxGene;
			}
		}
	return this->genes;
}

DynamicVector<Gene> Repository::filter(const string& sequence)
{
	DynamicVector<Gene> filtered;
	for (int index = 0; index < genes.getSize(); index++) {
		if (genes[index].getSequence().find(sequence) != std::string::npos) {
			filtered.add(genes[index]);
		}
	}
	return sortVector(filtered);
}

DynamicVector<Gene> Repository::sortVector(DynamicVector<Gene>& filteredGenes)
{
	Gene gene1;
	Gene gene2;
	int index1, index2;
	for (index1 = 0; index1 < filteredGenes.getSize() - 1; index1++)
		for (index2 = index1 + 1; index2 < filteredGenes.getSize(); index2++) {
			gene1 = filteredGenes[index1];
			gene2 = filteredGenes[index2];
			if (gene1.getSequence().length() < gene2.getSequence().length()) {
				Gene auxGene = filteredGenes[index1];
				filteredGenes[index1] = filteredGenes[index2];
				filteredGenes[index2] = auxGene;
			}
		}
	return filteredGenes;
}
