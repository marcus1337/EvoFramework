
#include <iostream>
#include "NN/NN.h"
#include "NNLayer.h"


int main(int argc, char* argv[]) {
    NNLayer layer1(3, 5);
    NNLayer layer2(5, 4);
    layer1.propagate(layer2);

    NN nn({ 2,3,3,2 });
    nn.propagate({1.f,1.f});
    std::cout << "result test: " << nn.getOutputIndex() << "\n";

    std::cout << "main function \n";
    

    return 0;
}