#include "Gene.h"

Gene::Gene(const string& organism, const string& name, const string& sequence) {
	this->organism = organism;
	this->name = name;
	this->sequence = sequence;
}