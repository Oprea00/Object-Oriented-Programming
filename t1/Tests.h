#pragma once
#include "Gene.h"
#include "DynamicVector.h"
#include "Repository.h"
#include "Controller.h"
#include <assert.h>

using namespace std;

class Tests {

private:
	static void testAddToRepository();
	static void testAddExistingElementToRepository();
	static void testAddGene();
	static void testAddExistingGene();

public:
	static void runTests();
};