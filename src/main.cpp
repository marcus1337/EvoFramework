
#include <iostream>
#include "NN/NN.h"
#include "NNLayer.h"


int main(int argc, char* argv[]) {
    NNLayer layer1(3, 5);
    NNLayer layer2(5, 4);
    layer1.propagate(layer2);

    std::cout << "main function \n";

    //std::cout << "hello c++ " << "\n";

    return 0;
}