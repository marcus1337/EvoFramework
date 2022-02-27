#include "NN/NN.h"

#ifndef ELITE_H
#define ELITE_H

class Elite {
public:
    Elite(NN _nn, int _fitness = -1);

    int fitness;
    NN nn;
};

#endif // !ELITE_H
