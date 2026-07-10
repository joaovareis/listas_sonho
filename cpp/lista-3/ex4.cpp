#include <iostream>

int main() {

    int a, b, c;

    std::cout<<"Digite o primeiro lado: ";
    std::cin>>a;

    std::cout<<"Digite o segundo lado: ";
    std::cin>>b;

    std::cout<<"Digite o terceiro lado: ";
    std::cin>>c;

    if ((a+b < c) or (b+c < a) or (a+c < b)) {
        std::cout<<"Nao e um triangulo"<<std::endl;

    } else if (a == b and a == c) {
        std::cout<<"Parabens, e equilatero"<<std::endl;

    } else if (a == b or a == c or b == c) {
        std::cout<<"Parabens, e isosceles"<<std::endl;

    } else { 
        std::cout<<"Parabens, e escaleno"<<std::endl;

    }

    return 0;
}