#include "../lib/odometria.hpp"
#include <iostream>

int main() {

    double x = 0;
    double y = 0;
    double theta = 0;

    std::cout<<"------- Caso 1 ----------"<<std::endl;
    
    Odometria::exibir_postura(x, y, theta, 1.0, 0.5, 0.0, 5);

    std::cout<<std::endl;

    x = 0;

    std::cout<<"------- Caso 2 ----------"<<std::endl;

    Odometria::exibir_postura(x, y, theta, 1.0, 0.5, 0.3, 8);

    return 0;
}