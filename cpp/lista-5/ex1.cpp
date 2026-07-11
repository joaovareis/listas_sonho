#include <iostream>

int main(){

    bool entrada[6];
    
    for(int i = 0; i < 6; i++) {

        std::cout<<"Digite o valor para o sensor "<<i<<":";
        std::cin>>entrada[i];
    }

    std::cout<<"--- Diagnostico RollerBot ---"<<std::endl;

    for(int i = 0; i < 6; i++) {

        if (entrada[i]) {
            std::cout<<"Sensor ["<<i<<"]: ATIVO"<<std::endl;

        } else {
            std::cout<<"Sensor ["<<i<<"]: INATIVO"<<std::endl;
        }
    }

    std::cout<<"--------------------------"<<std::endl;
    return 0;
}