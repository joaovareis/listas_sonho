#include <iostream>
#include <cmath>

int main() {

    int a;

    std::cout<<"Digite o numero: ";
    std::cin>>a;

    std::cout<<"Dec: "<<std::dec<<a<<" | Hex: "<<std::hex<<a<<" | Oct: "<<std::oct<<a<<std::endl;

    std::cout<<std::dec;

    int bits = std::ceil( std::log2(a + 1) );

    std::cout<<"Bits necessarios: "<<bits<<std::endl;
    std::cout<<"Bits do int: "<<sizeof(a)*8<<std::endl;
    std::cout<<"Bits desperdicados: "<<sizeof(a)*8 - bits<<std::endl;

    return 0;
}