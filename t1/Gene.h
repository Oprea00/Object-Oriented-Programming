#pragma once
#include <string>

using namespace std;

class Gene {
private:
	string organism;
	string name;
	string sequence;

public:
	Gene() {};
	Gene(const string& organism, const string& name, const string& sequence);
	string getOrganism() const { return organism; }
	string getName() const { return name; }
	string getSequence() const { return sequence; }
};