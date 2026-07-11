#include <iostream>

int main() {

    int n;

    std::cout<<"Digite o numero de angulos: ";
    std::cin>>n;

    float varredura[n];

    for(int i = 0; i < n; i++){
        std::cout<<"Digite o angulo "<<i<<": ";
        std::cin>>varredura[i];

    }

    std::cout<<std::endl;
    std::cout<<"Varredura Completa."<<std::endl;

    float min = varredura[0];
    int indice = 0;

    for(int i = 0; i< n; i++){

        if (varredura[i]<min){
            min = varredura[i];
            indice = i;
        }

    }

    float ang = indice*180/n;

    std::cout<<"Menor distancia detectada: "<<min<<std::endl;
    std::cout<<"Indice do obstaculo: "<<indice<<std::endl;
    std::cout<<"Angulo de saida: "<<ang<<std::endl;

}