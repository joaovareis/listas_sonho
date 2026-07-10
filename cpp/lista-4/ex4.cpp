#include <iostream>
#include <cmath>
#include <iomanip>

int main() {

    float x = 1;
    float y = 1;
    float dist;

    while (x != 0.0 and y != 0.0) {
        
        std::cout<<"Digite a posicao (x, y): ";
        std::cin>>x;
        std::cin>>y;

        dist = sqrt(pow(x, 2) + pow(y, 2));

        std::cout<<std::fixed<<std::setprecision(2);

        if (dist != 0) {

            std::cout<<"Objeto detectado em ["<<x<<", "<<y<<"]"<<std::endl;

            if (dist > 2) {
                std::cout<<"Distancia Euclidiana: "<<dist<<" m -> Caminho Livre"<<std::endl;
            } else {
                std::cout<<"Distancia Euclidiana: "<<dist<<" m -> ALERTA: Risco de colisao!"<<std::endl;
            }
        }
    }

    std::cout<<"[0, 0] recebido. Encerrando monitoramento."<<std::endl;
}