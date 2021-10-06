#include "UI.h"
#include "Tests.h"

int main() {
	Tests::runTests();

	Repository repository;
	Controller controller{ repository };

	controller.addGene("E_Coli_K12", "yqgE", "ATGACATCATCATTG");
	controller.addGene("M_tuberculosis", "ppiA", "TCTTCATCATCATCGG");
	controller.addGene("Mouse", "Col2a1", "TTAAAGCATGGCTCTGTG");
	controller.addGene("E_Coli_ETEC", "yqgE", "GTGACAGCGCCCTTCTTTCCACG");
	controller.addGene("E_Coli_K12", "hokC", "TTAATGAAGCATAAGCTTGATTTC");

	UI ui{ controller };
	ui.run();

	return 0;
}