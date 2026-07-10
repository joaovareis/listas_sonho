#include <iostream>
#include <iomanip>

int main(){

    float temp_atual;
    float temp_alvo;
    int minuto = 0;

    std::cout<<"Digite a temperatura atual do motor: ";
    std::cin>>temp_atual;

    std::cout<<"Digite a temperatura de seguranca: ";
    std::cin>>temp_alvo;

    std::cout<<std::fixed<<std::setprecision(2);

    while (temp_atual > temp_alvo) {

        temp_atual -= temp_atual*0.08;
        minuto += 1;
        std::cout<<"Minuto "<<minuto<<": "<<temp_atual<<" *C"<<std::endl;
    }

    std::cout<<"Temperatura segura atingida. Tempo de resfriamento: "<<minuto<<" minutos."<<std::endl;

    return 0;
}