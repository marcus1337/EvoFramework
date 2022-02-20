#include "NN/NN.h"

#ifndef ELITE_H
#define ELITE_H

class Elite {
public:
    Elite(NN _nn);

    int fitness;
    int behaviorA;
    NN nn;
};

#endif // !ELITE_H
