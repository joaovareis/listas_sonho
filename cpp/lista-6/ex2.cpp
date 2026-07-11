#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>


int main() {

    std::pair<float, float> coordenada;
    std::vector<std::pair<float, float>> leituras;
    float dist = 0;
    float dist_tot = 0;

    do {
        std::cout<<"Digite x: ";
        std::cin>>coordenada.first;

        std::cout<<"Digite y: ";
        std::cin>>coordenada.second;

        leituras.push_back(coordenada);

    }  while(coordenada.first =! 0 and coordenada.second != 0) ;

    for(int i = 0; i < leituras.size() -2; i++) {
    
        dist = sqrt(pow(leituras[i+1].first - leituras[i].first, 2) + pow(leituras[i+1].second - leituras[i].second, 2));
        dist_tot += dist;
        std::cout<<"Trecho "<<i+1<<" (Ponto "<<i<<" para "<<i+1<<"): Distancia = "<<std::fixed<<std::setprecision(2)<<dist<<std::endl;

    }

    std::cout<<"Distancia final total: "<<dist_tot<<std::endl;

    return 0;

}