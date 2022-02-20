#include "Trainer.h"
#include <iostream>

Trainer::Trainer(int _numElites, int _numInputNodes, int _numOutputNodes, std::string _environmentScript) :
	numElites(_numElites), numInputNodes(_numInputNodes), numOutputNodes(_numOutputNodes) {

	elites.reserve(numElites);
	for (int i = 0; i < numElites; i++) {
		int hiddenLayerSize = (numInputNodes / 3) * 2 + numOutputNodes;
		NN nn({ numInputNodes, hiddenLayerSize, hiddenLayerSize , numOutputNodes });
		mutater.randomize(nn);
		elites.push_back(Elite(nn, i));
	}
}