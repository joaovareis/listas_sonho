#include <iostream>

int main() {

    bool estado_robo;
    float bateria;
    float distancia;

    std::cout<<"O robo esta ligado?"<<std::endl;
    std::cout<<"1 -> Sim"<<std::endl;
    std::cout<<"0 -> Nao"<<std::endl;
    std::cout<<"Digite a opcao: ";
    std::cin>>estado_robo;

    if (not estado_robo) {
        std::cout<<"Digite o nivel da bateria (%): ";
        std::cin>>bateria;

        if (bateria < 20) {
            std::cout<<"Bateria critica. Recarregue o robo"<<std::endl;

        } else {
            std::cout<<"Falha no acionamento. Verificar sistema eletrico"<<std::endl;

        }

    } else {
        std::cout<<"Digite a distancia medida pelo sensor frontal (cm): ";
        std::cin>>distancia;

        if (distancia < 0 or distancia > 400) {
            std::cout<<"Erro de sensor. Leitura invalida"<<std::endl;

        } else if (distancia < 10) {
            std::cout<<"Parar imediatamente"<<std::endl;

        } else if (distancia > 10 and distancia < 30) {
            std::cout<<"Reduzir velocidade"<<std::endl;
        
        } else {
            std::cout<<"Seguir normalmente"<<std::endl;

        }

    }

    return 0;
}