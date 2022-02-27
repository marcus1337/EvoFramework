#include "Trainer.h"
#include <iostream>
#include "Environment.h"

Trainer::Trainer(int numElites, std::string _modelScript) : modelScript(_modelScript) {

	Environment env(modelScript);
	int numIn = env.getNumObservations();
	int numOut = env.getNumActions();

	elites.reserve(numElites);
	for (int i = 0; i < numElites; i++) {
		NN nn = NN::makeDefaultNetwork(numIn, numOut);
		mutater.randomize(nn);
		elites.push_back(Elite(nn));
	}
}

void Trainer::evaluate() {
	for (Elite& elite : elites) {
		Environment env(modelScript);
		elite.fitness = env.score(elite.nn);
	}
}