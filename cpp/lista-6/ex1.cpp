#include <iostream>
#include <vector>


int main() {

    float entrada;

    std::vector<float> leituras;


    std::cout<<"Digite os valores: ";

    while(entrada != 0) {
        std::cin>>entrada;
        leituras.push_back(entrada);

    }

    std::cout<<"--- Telemetria Spot ---"<<std::endl;
    std::cout<<"Amostra coletadas: "<<leituras.size() - 1<<std::endl;
    std::cout<<"Variacao amostral: "<<leituras.at(0) - leituras.at(leituras.size() - 2)<<std::endl;

    return 0;

}