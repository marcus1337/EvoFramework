#include "Trainer.h"
#include <iostream>
#include "Environment.h"
#include <algorithm>

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

void Trainer::select() {
	auto elitePtr = std::max_element(elites.begin(), elites.end(),
		[](const Elite& a, const Elite& b)
		{
			return a.fitness < b.fitness;
		});
	bestElite = *elitePtr;
	bestElite.fitness = 0;
	for (std::size_t i = 0; i < elites.size(); i++) {
		elites[i] = bestElite;
	}
}

void Trainer::mutate() {
	float numElites = (float)elites.size();
	float mutateDelta = 1.0f / numElites;
	for (std::size_t i = 1; i < elites.size(); i++) {
		mutater.mutate(elites[i].nn, 1.0f - (mutateDelta*(float)i));
	}
}

void Trainer::train() {
	evaluate();
	select();
	mutate();
}

NN Trainer::getBestNN() {
	return bestElite.nn;
}